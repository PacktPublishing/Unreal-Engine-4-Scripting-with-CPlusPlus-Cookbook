#pragma once

#include "Logging.h"
#include "GameFramework/GameMode.h"

#include "Runtime/Landscape/Classes/LandscapeProxy.h"
#include "Runtime/Landscape/Classes/Landscape.h"
#include "Runtime/Landscape/Classes/LandscapeInfo.h"
#include "Runtime/Landscape/Public/LandscapeEdit.h"
#include "Runtime/Online/HTTP/Public/Interfaces/IHttpRequest.h"
#include "Runtime/Online/HTTP/Public/HttpRetrySystem.h"
#include "Runtime/Online/HTTP/Public/Interfaces/IHttpRequest.h"
#include "Runtime/Core/Public/Containers/Array.h"
#include "Runtime/GameplayAbilities/Public/GameplayAbilitySet.h"
#include "Runtime/GameplayAbilities/Public/AttributeSet.h"

#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/ProgressBar.h"

#include "HttpDialog.h"

using namespace FHttpRetrySystem;
#include "Chapter12GameMode.generated.h"

class UFoliageType;
struct FFoliageInstance;

UCLASS()
class CHAPTER12_API AChapter12GameMode : public AGameMode
{
  GENERATED_BODY()
public:
  AChapter12GameMode( const FObjectInitializer& PCIP );

  virtual void PreInitializeComponents() override;
  virtual void PostInitializeComponents() override;
  virtual void BeginPlay() override;

  UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = Attributes )
  UHttpDialog* HttpDialog;

  UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = Attributes )
  UAttributeSet* Attribs;
  
  /// Fill this out with the tag table names
  UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = GameplayTags )
  TArray<FString> GameplayTagTableNames;

  /// To select-in the foliage used.
  UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = Foliage )
  TArray< UFoliageType* > FoliageTypes;

  /// Number of foliage trees to place
  UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = Foliage )
  int32 NumTrees;

  /// Scaling parameters
  UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = Foliage )
  float ScalingMin;
  UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = Foliage )
  float ScalingMax;

  /// Foliage correlation
  /// Trees sit within a band of values, eg 0.4 < PTV < 0.6.
  /// This would have PTV=0.5 and Range=0.1.
  UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = Foliage )
  float PerlinTreeValue;

  /// The width of the band where a tree has a chance to place.
  UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = Foliage )
  float PerlinTreeRange;

  void SpawnFoliageInstance(UWorld* InWorld, const UFoliageType* Settings,
    const FFoliageInstance& Instance, UActorComponent* BaseComponent);

  // Gets you all landscapes in the level.
  TArray<ALandscape*> GetLandscapes();
  int32 GetNumHeights( ALandscape* landscape );
  uint16 PerlinNoise2D( float x, float y, float amp, int32 octaves, int32 px, int32 py );
  UFUNCTION( BlueprintCallable, Category="MapGen" )
  void Gen();
  
  void HttpRequestComplete( FHttpRequestPtr request, FHttpResponsePtr response, bool success );
  void TestHttp();
  void SendNetworkPacket();
};

class PlainObject
{
public:
  void httpHandler( FHttpRequestPtr request, FHttpResponsePtr response, bool success )
  {
    Info( "PlainObject: Http req handled" );
  }
};

// Derive from TSharedFromThis to make THREADSAFE
class SharedObject : public TSharedFromThis<SharedObject, ESPMode::ThreadSafe>
{
public:
  void httpHandler( FHttpRequestPtr request, FHttpResponsePtr response, bool success )
  {
    Info( "SharedObject: Http req handled" );
  }
};

inline void httpHandler( FHttpRequestPtr request, FHttpResponsePtr response, bool success )
{
  Info( "static: Http req handled" );
}
