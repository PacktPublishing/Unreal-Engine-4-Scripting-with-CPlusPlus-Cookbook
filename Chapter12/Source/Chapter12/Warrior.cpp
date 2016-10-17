#include "Chapter12.h"

#include "Warrior.h"
#include "Logging.h"
#include "Runtime/GameplayAbilities/Public/Abilities/GameplayAbility.h"
#include "Runtime/GameplayAbilities/Public/GameplayAbilitySet.h"
#include "Runtime/GameplayAbilities/Public/GameplayAbilitySpec.h"
#include "GameplayTask_CreateParticles.h"
#include "Runtime/GameplayAbilities/Public/GameplayEffect.h"
#include "Runtime/GameplayAbilities/Public/AbilitySystemGlobals.h"
#include "Runtime/GameplayAbilities/Public/AbilitySystemInterface.h"

// Sets default values
AWarrior::AWarrior( const FObjectInitializer& PCIP ) : Super( PCIP )
{
  PrimaryActorTick.bCanEverTick = true;
  gameplayAbilitySet = 0;
  AbilitySystemComponent = PCIP.CreateDefaultSubobject<UAbilitySystemComponent>
    ( this, TEXT("UAbilitySystemComponent") );
  GameplayTasksComponent = PCIP.CreateDefaultSubobject<UGameplayTasksComponent>
    ( this, TEXT("UGameplayTasksComponent") );
  lastInput = FVector2D(0.f,0.f);
}

void AWarrior::PostInitializeComponents()
{	
	Super::PostInitializeComponents();
  UE_LOG( LogTemp, Warning, TEXT( "AWarrior::PostInitializeComponents()" ) );

  // Would be good if InitStats accepted a Blueprint of the GameUnitAttributeSet.
  AbilitySystemComponent->InitStats( 
    UGameUnitAttributeSet::StaticClass(), NULL );
  
  TestGameplayEffect();
  UGameplayTask_CreateParticles* task = 
    UGameplayTask_CreateParticles::ConstructTask( this,
    particleSystem, FVector( 0.f, 0.f, 200.f ) );
  if( GameplayTasksComponent )
  {
    GameplayTasksComponent->AddTaskReadyForActivation( *task );
  }
}

void AWarrior::SetupPlayerInputComponent( UInputComponent* Input )
{
  check( Input );
  Super::SetupPlayerInputComponent( Input );

  Input->BindAxis( "Forward", this, &AWarrior::Forward );
  Input->BindAxis( "Back", this, &AWarrior::Back );
  Input->BindAxis( "Right", this, &AWarrior::Right );
  Input->BindAxis( "Left", this, &AWarrior::Left );

  Info( "AWarrior::SetupPlayerInputComponent()" );
  Info( "AbilitySystemComponent::BindToInputComponent()" );
  // Connect the class's AbilitySystemComponent
  // to the actor's input component
  AbilitySystemComponent->BindToInputComponent( Input );
  
  // Go thru each BindInfo in the gameplayAbilitySet.
  // Give & try and activate each on the AbilitySystemComponent.
  for( const FGameplayAbilityBindInfo& BindInfo : 
    gameplayAbilitySet->Abilities )
  {
    // BindInfo has 2 members:
    //   .Command (enum value)
    //   .GameplayAbilityClass (UClass of a UGameplayAbility)
    if( !BindInfo.GameplayAbilityClass )
    {
      Error( FS( "GameplayAbilityClass %d not set",
        (int32)BindInfo.Command ) );
      continue;
    }
  
    FGameplayAbilitySpec spec(
      // Gets you an instance of the UClass
      BindInfo.GameplayAbilityClass->
        GetDefaultObject<UGameplayAbility>(),
      1, (int32)BindInfo.Command ) ;
    
    // STORE THE ABILITY HANDLE FOR LATER INVOKATION
    // OF THE ABILITY
    FGameplayAbilitySpecHandle abilityHandle = 
      AbilitySystemComponent->GiveAbility( spec );
    
    // The integer id that invokes the ability 
    // (ith value in enum listing)
    int32 AbilityID = (int32)BindInfo.Command;
    
    // CONSTRUCT the inputBinds object, which will
    // allow us to wire-up an input event to the
    // InputPressed() / InputReleased() events of
    // the GameplayAbility.
    FGameplayAbiliyInputBinds inputBinds(
      // These are supposed to be unique strings that define
      // what kicks off the ability for the actor instance.
      // Using strings of the format 
      // "ConfirmTargetting_Player0_AbilityClass"
      FS( "ConfirmTargetting_%s_%s", *GetName(), 
        *BindInfo.GameplayAbilityClass->GetName() ),
      FS( "CancelTargetting_%s_%s", *GetName(), 
        *BindInfo.GameplayAbilityClass->GetName() ),
      "EGameplayAbilityInputBinds", // The name of the ENUM that 
      // has the abilities listing.
      AbilityID, AbilityID 
    );
    // MUST BIND EACH ABILITY TO THE INPUTCOMPONENT, OTHERWISE
    // THE ABILITY CANNOT "HEAR" INPUT EVENTS. This enables 
    // triggering of InputPressed() / InputReleased() events,
    // which you can in-turn use to call TryActivateAbility()
    // if you so choose.
    AbilitySystemComponent->BindAbilityActivationToInputComponent(
      Input, inputBinds
    );

    // Test-kicks the ability to active state.
    // You can try invoking this manually via your
    // own hookups to keypresses in this warrior class
    // This auto-checks if the ability is invokable
    // according to its own internal rules.
    AbilitySystemComponent->TryActivateAbility( 
      abilityHandle, 1 );
  }
}

void AWarrior::Forward( float amount )
{
  lastInput.Y += amount;
}
void AWarrior::Back( float amount )
{
  lastInput.Y += -amount;
}
void AWarrior::Right( float amount )
{
  lastInput.X += amount;
}
void AWarrior::Left( float amount )
{
  lastInput.X += -amount;
}

// Called when the game starts or when spawned
void AWarrior::BeginPlay()
{
	Super::BeginPlay();
  UE_LOG( LogTemp, Warning, TEXT( "AWarrior::BeginPlay()" ) );
}

inline UGameplayEffect* ConstructGameplayEffect( FString name )
{
  return NewObject<UGameplayEffect>( GetTransientPackage(), FName( *name ) );
}

inline FGameplayModifierInfo& AddModifier(
  UGameplayEffect* Effect, UProperty* Property,
  EGameplayModOp::Type Op,
  const FGameplayEffectModifierMagnitude& Magnitude)
{
	int32 index = Effect->Modifiers.Num();
	Effect->Modifiers.SetNum( index + 1 );
	FGameplayModifierInfo& Info = Effect->Modifiers[ index ];
	Info.ModifierMagnitude = Magnitude;
	Info.ModifierOp = Op;
	Info.Attribute.SetUProperty(Property);
	return Info;
}

void AWarrior::TestGameplayEffect()
{
  // Construct & retrieve UProperty to affect
  UGameplayEffect* RecoverHP = ConstructGameplayEffect( "RecoverHP" );

  // Compile-time checked retrieval of Hp UPROPERTY()
  // from our UGameUnitAttributeSet class (listed in
  // UGameUnitAttributeSet.h)
  UProperty* hpProperty = FindFieldChecked<UProperty>( 
    UGameUnitAttributeSet::StaticClass(), 
    GET_MEMBER_NAME_CHECKED(UGameUnitAttributeSet, Hp));

  // Command the addition of +5 HP to the hpProperty
  AddModifier( RecoverHP, hpProperty, EGameplayModOp::Additive, FScalableFloat( 50.f ) );
  // .. for a fixed-duration of 10 seconds ..
  RecoverHP->DurationPolicy = EGameplayEffectDurationType::HasDuration;
  RecoverHP->DurationMagnitude = FScalableFloat( 10.f );
  // .. with 100% chance of success ..
  RecoverHP->ChanceToApplyToTarget = 1.f;
  // .. with recurrency (Period) of 0.5 seconds
  RecoverHP->Period = 0.5f;

  // Finally, begin application of the effect.
  FActiveGameplayEffectHandle recoverHpEffectHandle = 
    AbilitySystemComponent->ApplyGameplayEffectToTarget( 
    RecoverHP, AbilitySystemComponent, 1.f );

  // Retrieve the delegate. If it has no duration how can we
  // make sure the lambda runs before effect terminates?
  FOnActiveGameplayEffectRemoved* ep = AbilitySystemComponent->
    OnGameplayEffectRemovedDelegate( recoverHpEffectHandle );
  if( ep ) {
    //FDelegateHandle OnGameplayEffectRemovedDelegateHandle =
    //  ep->AddUObject( this, &AWarrior::RecoverHpEffectEnded );
    ep->AddLambda( [](){ Info( "Added lambda" ); } );
  }
}

void AWarrior::RecoverHpEffectEnded()
{
  Info( "RecoverHP effect end" );
}

// Called every frame
void AWarrior::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

  if( Controller )
  {
    float len = lastInput.Size();
    if( len > 1.f )
    {
      lastInput /= len; // Normalize when input length is greater than 1.0
    }

    AddMovementInput( GetActorForwardVector(), lastInput.Y );
    AddMovementInput( GetActorRightVector(), lastInput.X );

    lastInput = FVector2D( 0.f, 0.f );

  }
}

