// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter6.h"
#include "Warrior.h"


// Sets default values
AWarrior::AWarrior( const FObjectInitializer& PCIP )
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
  lastInput = FVector2D::ZeroVector;
}

// Called when the game starts or when spawned
void AWarrior::BeginPlay()
{
	Super::BeginPlay();
}

void AWarrior::PostInitializeComponents()
{
  Super::PostInitializeComponents();
  if( RootComponent )
  {
    // Attach contact function to all bounding components.
    GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(
      this, &AWarrior::OnOverlapsBegin );
    GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(
      this, &AWarrior::OnOverlapsEnd );
  }
}

// Called to bind functionality to input
void AWarrior::SetupPlayerInputComponent( UInputComponent* Input )
{
	Super::SetupPlayerInputComponent( Input );
  check( Input );
  Input->BindAxis( "Forward", this, &AWarrior::Forward );
  Input->BindAxis( "Back", this, &AWarrior::Back );
  Input->BindAxis( "Right", this, &AWarrior::Right );
  Input->BindAxis( "Left", this, &AWarrior::Left );

  FInputAxisKeyMapping backKey( "Back", EKeys::S, 1.f );
  FInputActionKeyMapping jump( "Jump", EKeys::SpaceBar, 0, 0, 0, 0 );

  GetWorld()->GetFirstPlayerController()->PlayerInput->
    AddAxisMapping( backKey );
  GetWorld()->GetFirstPlayerController()->PlayerInput->
    AddActionMapping( jump );

}

void AWarrior::Forward( float amount )
{
  // Moves the player forward by an amount in forward direction
  AddMovementInput( GetActorForwardVector(), amount );
}

void AWarrior::Back( float amount )
{
  AddMovementInput( -GetActorForwardVector(), amount );
}

void AWarrior::Right( float amount )
{
  AddMovementInput( GetActorRightVector(), amount );
}

void AWarrior::Left( float amount )
{
  AddMovementInput( -GetActorRightVector(), amount );
}

void AWarrior::Tick( float DeltaSeconds )
{
  Super::Tick( DeltaSeconds );
  if( Controller )
  {
    float len = lastInput.Size();
    if( len > 1.f )
      lastInput /= len;
    AddMovementInput( GetActorForwardVector(), lastInput.Y );
    AddMovementInput( GetActorRightVector(), lastInput.X );
    // Zero off last input values
    lastInput = FVector2D( 0.f, 0.f );
  }
}

void AWarrior::OnOverlapsBegin_Implementation(
  UPrimitiveComponent* Comp,
  AActor* OtherActor, UPrimitiveComponent* OtherComp,
  int32 OtherBodyIndex,
  bool bFromSweep, const FHitResult&SweepResult )
{
  UE_LOG(LogTemp, Warning, TEXT( "Overlaps warrior began" ) );
}

void AWarrior::OnOverlapsEnd_Implementation(
  UPrimitiveComponent* Comp,
  AActor* OtherActor, UPrimitiveComponent* OtherComp,
  int32 OtherBodyIndex )
{
  UE_LOG(LogTemp, Warning, TEXT( "Overlaps warrior ended" ) );
}
