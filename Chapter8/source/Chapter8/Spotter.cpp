// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter8.h"
#include "Spotter.h"


// Sets default values
ASpotter::ASpotter()
	:Super()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cone.Cone'"));
	if (MeshAsset.Object != nullptr)
	{
		GetStaticMeshComponent()->SetStaticMesh(MeshAsset.Object);
		GetStaticMeshComponent()->bGenerateOverlapEvents = true;
	}
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	GetStaticMeshComponent()->SetRelativeRotation(FRotator(90, 0, 0));
}

// Called when the game starts or when spawned
void ASpotter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpotter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	auto EndLocation = GetActorLocation() + ActorToWorld().TransformVector(FVector(0,0,-200));
	
	FHitResult HitResult;
	GetWorld()->SweepSingleByChannel(HitResult, GetActorLocation(), EndLocation, FQuat::Identity, ECC_Camera, FCollisionShape::MakeSphere(25), FCollisionQueryParams("Spot", true, this));
	APawn* SpottedPlayer = Cast<APawn>(HitResult.Actor.Get());

	if (SpottedPlayer!= nullptr)
	{
		OnPlayerSpotted(SpottedPlayer);
	}
	DrawDebugLine(GetWorld(), GetActorLocation(), EndLocation, FColor::Red);


}

