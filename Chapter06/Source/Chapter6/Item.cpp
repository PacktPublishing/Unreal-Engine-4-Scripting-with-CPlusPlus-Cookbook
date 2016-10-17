// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter6.h"
#include "Item.h"


// Sets default values
AItem::AItem( const FObjectInitializer& PCIP ) : Super( PCIP )
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
  sphere = PCIP.CreateDefaultSubobject<USphereComponent>( this, TEXT("Sphere") );
  sphere->AttachTo( GetRootComponent() );
}

void AItem::PostInitializeComponents()
{
  Super::PostInitializeComponents();
  sphere->OnComponentBeginOverlap.AddDynamic(
    this, &AItem::OnOverlapsBegin );
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AItem::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void AItem::OnOverlapsBegin_Implementation(
  UPrimitiveComponent* Comp,
  AActor* OtherActor, UPrimitiveComponent* OtherComp,
  int32 OtherBodyIndex,
  bool bFromSweep, const FHitResult&SweepResult )
{
  UE_LOG( LogTemp, Warning, TEXT( "Overlaps item began" ) );
}
