// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter8.h"
#include "King.h"


// Sets default values
AKing::AKing()
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
	
}

// Called when the game starts or when spawned
void AKing::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKing::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AKing::Die()
{
	OnKingDeath.Broadcast(this);
}

