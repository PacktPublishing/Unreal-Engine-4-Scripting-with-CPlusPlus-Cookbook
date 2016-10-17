#include "Chapter12.h"

#include "Editor/UnrealEd/Public/UnrealEd.h"
#include "Editor/UnrealEd/Classes/Editor/UnrealEdEngine.h"

#include "Runtime/Online/HTTP/Public/HttpManager.h"
#include "Runtime/Online/HTTP/Public/HttpModule.h"
#include "Runtime/Online/HTTP/Public/HttpRetrySystem.h"
#include "Runtime/Online/HTTP/Public/Interfaces/IHttpResponse.h"
using namespace FHttpRetrySystem;

#include "Runtime/Landscape/Public/LandscapeDataAccess.h"
#include "Runtime/Landscape/Classes/Landscape.h"
#include "Runtime/Landscape/Classes/LandscapeProxy.h"
#include "Runtime/Landscape/Classes/LandscapeInfo.h"
#include "Runtime/Landscape/Classes/LandscapeComponent.h"
#include "Runtime/Landscape/Public/LandscapeEdit.h"
#include "Runtime/GameplayTags/Public/GameplayTagsModule.h"
#include "Runtime/GameplayTags/Classes/GameplayTagsManager.h"

#include "Editor/UnrealEd/Public/EditorModes.h"
#include "Editor/UnrealEd/Public/Editor.h"
#include "Editor/UnrealEd/Public/EditorViewportClient.h"
#include "Editor/UnrealEd/Public/EdMode.h"
#include "Editor/LandscapeEditor/Private/LandscapeEdMode.h"
#include "Editor/LandscapeEditor/Public/LandscapeToolInterface.h"
#include "Editor/LandscapeEditor/Public/LandscapeEditorObject.h"
#include "Editor/LandscapeEditor/Public/LandscapeEditorUtils.h"
#include "Editor/LandscapeEditor/Private/LandscapeEdModeTools.h"
using namespace LandscapeEditorUtils;

#include "Runtime/Foliage/Public/ProceduralFoliageVolume.h"
#include "Runtime/Foliage/Public/InstancedFoliage.h"
#include "Runtime/Foliage/Public/InstancedFoliageActor.h"
#include "Runtime/Foliage/Public/FoliageType.h"

#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/ProgressBar.h"

#include "Chapter12GameMode.h"
#include "Functions.h"
#include "noise1234.h"
#include "Logging.h"

AChapter12GameMode::AChapter12GameMode( const FObjectInitializer& PCIP ) : Super( PCIP )
{
  // Runs VERY EARLY, even on open.. 
  IGameplayTagsModule::Get().GetGameplayTagsManager().
  LoadGameplayTagTables( GameplayTagTableNames );

  HttpDialog = 0; // Init from Blueprints (the one constructed in the blueprints construction diagram)

  // Testing the LogCh12 declaration / definition (see Logging.h / Logging.cpp)
  UE_LOG( LogCh12, Display, TEXT( "A display message, log is working" ) );
  UE_LOG( LogCh12, Warning, TEXT( "A warning message" ) );
  UE_LOG( LogCh12, Error, TEXT( "An error message " ) );
  CreateLogger( LoggerName );

  // Retrieve the Log by using the loggername.
  FMessageLog logger( LoggerName );
  logger.Warning( FTEXTS( "A warning message from gamemode ctor" ) );
}

void AChapter12GameMode::PreInitializeComponents()
{
  Super::PreInitializeComponents();
  Info( "AChapter12GameMode::PreInitializeComponents()" );
}

void AChapter12GameMode::PostInitializeComponents()
{
  Super::PostInitializeComponents();
  Info( "AChapter12GameMode::PostInitializeComponents()" );
}

void AChapter12GameMode::BeginPlay()
{
  Super::BeginPlay();
  TestHttp();
}

// Imported from FoliageEdMode.cpp
void AChapter12GameMode::SpawnFoliageInstance(UWorld* InWorld, const UFoliageType* foliageType,
  const FFoliageInstance& Instance, UActorComponent* BaseComponent)
{
	// We always spawn instances in base component level
	ULevel* TargetLevel = BaseComponent->GetComponentLevel();
	AInstancedFoliageActor* IFA = AInstancedFoliageActor::GetInstancedFoliageActorForLevel(TargetLevel, true);
	
	FFoliageMeshInfo* MeshInfo;
	UFoliageType* FoliageSettings = IFA->AddFoliageType(foliageType, &MeshInfo);

	MeshInfo->AddInstance(IFA, FoliageSettings, Instance, BaseComponent);
}

TArray<ALandscape*> AChapter12GameMode::GetLandscapes()
{
  TArray<ALandscape*> landscapes;
  ULevel *level = GetLevel();
  for( int i = 0; i < level->Actors.Num(); i++ )
    if( ALandscape* land = Cast<ALandscape>( level->Actors[ i ] ) )
      landscapes.Push( land );
  return landscapes;
}

int32 AChapter12GameMode::GetNumHeights( ALandscape* landscape )
{
  TArray<ULandscapeComponent*> landscapeComponents = GetActorsComponentsByClass<ULandscapeComponent>( landscape );
  if( landscapeComponents.Num() )
    // #components * the component size.
    return landscapeComponents.Num()*landscapeComponents[0]->ComponentSizeQuads;
  else
    return 0;
}

uint16 AChapter12GameMode::PerlinNoise2D( float x, float y, float amp, int32 octaves, int32 px, int32 py )
{
  float noise = 0.f;
  for( int octave = 1; octave < octaves; octave *= 2 )
  {
    // Add in fractions of faster varying noise at lower amplitudes 
    // for higher octaves. Assuming x is normalized, WHEN octave==px
    // you get full period. Higher frequencies will go out and also meet period.
    noise += Noise1234::pnoise( x*px*octave, y*py*octave, px, py ) / octave;
  }
  return USHRT_MAX/2.f + amp*noise;
}

void AChapter12GameMode::Gen()
{
  // MUST CALL.
  ULandscapeInfo::RecreateLandscapeInfo( GetWorld(), 1 );
  
  // Get all the landscapes in the level.
  TArray<ALandscape*> landscapes = GetLandscapes();

  // Go thru all landscape objects..
  for( ALandscape* landscape : landscapes )
  {
    FIntRect rect = landscape->GetBoundingRect();
    // LandscapeEditorUtils::SetHeightmapData adds one to each dimension
    // because the boundary edges may be used.
    int32 cols = rect.Width()+1, rows = rect.Height()+1;
    int32 numHeights = cols * rows;
    Info( FS( "LANDSCAPE `%s` measures %dx%d has %d elts",
      *landscape->GetName(), rows, cols, numHeights ) );
    
    TArray<uint16> Data;
    Data.Init( 0, numHeights );

    // #octaves to sum, period in x, period in y.
    // The larger the period, the more variation we get
    // in the lowest frequency.
    int32 octaves=16, px=4, py=4;
    float amplitude = 1000.f;
    for( int i = 0; i < Data.Num(); i++ )
    {
      float nx = (i % cols)/(float)cols; //normalized col
      float ny = (i / cols)/(float)rows; //normalized row
      Data[i] = PerlinNoise2D( nx, ny, amplitude, octaves, px, py );
    }

    LandscapeEditorUtils::SetHeightmapData( landscape, Data );
    ULandscapeInfo::RecreateLandscapeInfo( GetWorld(), 1 );
    
    // resample to ensure it works
    //LandscapeEditorUtils::ResampleData<uint16>( Data, cols, rows, cols, rows );
    
    // Generate some foliage inside the box of the landscape
    FBox box = landscape->GetComponentsBoundingBox();
    Info( FS( "The landscape is bounded by (%f %f %f), (%f %f %f)",
      box.Min.X,box.Min.Y,box.Min.Z, box.Max.X,box.Max.Y,box.Max.Z ) );
    FVector boxHeight( 0.f, 0.f, box.Max.Z - box.Min.Z );

    if( FoliageTypes.Num() )
    {
      for( int i = 0; i < NumTrees; i++ )
      {
        FVector pos = FMath::RandPointInBox( box );
        pos.Z = box.Max.Z; // put the position @ top of box, then ground.

        // Trace downward to ground the position
        FHitResult hit;
        FCollisionQueryParams fcqp( true );
        FVector rayEnd = pos - boxHeight;
        if( !landscape->ActorLineTraceSingle( hit, pos, rayEnd, ECollisionChannel::ECC_EngineTraceChannel1, fcqp ) )
        {
          Warning( FS( "ActorLineTraceSingle (%s) failed %f %f %f => %f %f %f",
            *landscape->GetName(), pos.X,pos.Y,pos.Z, rayEnd.X,rayEnd.Y,rayEnd.Z ) );
        }

        if( hit.GetActor() )
        {
          //Info( FS( "ActorLineTraceSingle (%s) hit `[%s/%s]` @ (%f %f %f)",
          //  *actor->GetName(), *hit.GetActor()->GetName(), *hit.GetComponent()->GetName(), hit.ImpactPoint.X, hit.ImpactPoint.Y, hit.ImpactPoint.Z ) );
          pos = hit.ImpactPoint;
        }
        else
        {
          Error( "ray could not hit terrain" );
        }

        FFoliageInstance instance;
        instance.Location = pos;
	      float angle = randFloat( 0.f, 2.f*PI );
        FVector dir( randFloat( -0.05f, 0.05f ), randFloat( -0.05f, 0.05f ), 1.f );
        dir.Normalize();
	      instance.Rotation = FQuat( dir, angle ).Rotator();
	      //instance.PreAlignRotation;
        float s = randFloat( ScalingMin, ScalingMax );
	      instance.DrawScale3D = FVector( s,s,s*randFloat(1.f,1.2f) );
	      instance.ZOffset = 0.f;
	      //instance.Flags;
        // Normalize the position for perlin sampling
        FVector normalizedPos = pos;
        normalizedPos.Z = 0;
        normalizedPos.Normalize();
        int px=16,py=16;
        float pn = Noise1234::pnoise( px*normalizedPos.X, py*normalizedPos.Y, px, py );
        if( fabsf( pn - PerlinTreeValue ) < PerlinTreeRange )
        {
          SpawnFoliageInstance( GetWorld(), FoliageTypes[ randInt(0, FoliageTypes.Num()) ], 
            instance, landscape->GetRootComponent() );
        }
      }
    }
  } // each landscape
}

void AChapter12GameMode::HttpRequestComplete( FHttpRequestPtr request, FHttpResponsePtr response, bool success )
{
  // print the http response
  UE_LOG( LogTemp, Warning, TEXT( "Http response %d, %s" ),
    response->GetResponseCode(), *response->GetContentAsString() );
}

void AChapter12GameMode::TestHttp()
{
  // 1. Create the IHttpRequest object from your FHttpModule singleton interface.
  TSharedRef<IHttpRequest> http = FHttpModule::Get().CreateRequest();

  // 2. To see progress of http requests, attach to the OnRequestProgress() function.
  //    You may or may not want to see this.. this can be used to display your
  //    progressbar for longer http requests.
  http->OnRequestProgress().BindLambda( 
    [this]( FHttpRequestPtr request, int32 sentBytes, int32 receivedBytes )
    -> void
  {
    int32 contentLen = request->GetResponse()->GetContentLength();
    float percentComplete = 100.f*receivedBytes / contentLen;
    
    Info( FS( "Progress sent=%d bytes / received=%d/%d bytes [%.0f%%]",
      sentBytes, receivedBytes, contentLen, percentComplete ) );
    if( HttpDialog && HttpDialog->progressBar )
      HttpDialog->progressBar->SetPercent( percentComplete );
  } );

  // 3. Attach to the OnProcessRequestComplete() function to do something
  //    when the HTTP request completes. We demonstrate 7 ways of attaching
  //    to the delegate below.
  FHttpRequestCompleteDelegate& delegate = http->OnProcessRequestComplete();
  // 1. BindLambda():
  delegate.BindLambda(
    []( FHttpRequestPtr request, FHttpResponsePtr response, bool success ) -> void {
    UE_LOG( LogTemp, Warning, TEXT( "Http response %d, %s" ),
      response->GetResponseCode(), *response->GetContentAsString() );
    if( success )
      Info( "Request success" );
    else
      Warning( "Request did not succeed" );
  } );

  // 2. .BindRaw():
  PlainObject* p = new PlainObject();
  delegate.BindRaw( p, &PlainObject::httpHandler );
  // be sure to delete p later..!
  // But CANNOT delete p until callback completes.
  
  // 3. .BindSP():
  TSharedRef< PlainObject > sr( new PlainObject() );
  delegate.BindSP( sr, &PlainObject::httpHandler );

  // 4. .BindThreadSafeSP():
  TSharedRef< SharedObject, ESPMode::ThreadSafe > tssr( new SharedObject() );
  delegate.BindThreadSafeSP( tssr, &SharedObject::httpHandler );

  // 5. .BindStatic():
  delegate.BindStatic( &httpHandler );
  // 6. .BindUFunction(): Can't use for functions that have non-UCLASS, USTRUCT or UENUM type arguments (ie
  // no tsharedrefs.
  //.BindUFunction( this, &AChapter12GameMode::ufunctionHttpHandler );
  // 7. .BindUObject():
  delegate.BindUObject( this, &AChapter12GameMode::HttpRequestComplete );
  
  // 4. Set the web address to open by setting the URL of the HttpRequest.
  http->SetURL( TEXT( "http://unrealengine.com" ) ); // Do an HTTP request to any site you'd like.
  
  http->ProcessRequest();
}

void AChapter12GameMode::SendNetworkPacket()
{

}
