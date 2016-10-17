// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter4.h"
#include "HierarchyActor.h"


// Sets default values
AHierarchyActor::AHierarchyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	ChildSceneComponent = CreateDefaultSubobject<USceneComponent>("ChildSceneComponent");
	BoxOne = CreateDefaultSubobject<UStaticMeshComponent>("BoxOne");
	BoxTwo = CreateDefaultSubobject<UStaticMeshComponent>("BoxTwo");

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (MeshAsset.Object != nullptr)
	{
		BoxOne->SetStaticMesh(MeshAsset.Object);
		BoxOne->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
		BoxTwo->SetStaticMesh(MeshAsset.Object);
		BoxTwo->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);	
	}
	RootComponent = Root;
	BoxOne->AttachTo(Root);
	BoxTwo->AttachTo(ChildSceneComponent);
	ChildSceneComponent->AttachTo(Root);
	ChildSceneComponent->SetRelativeTransform(
		FTransform(FRotator(0, 0, 0), FVector(250, 0, 0), FVector(0.1f))
		);
}

// Called when the game starts or when spawned
void AHierarchyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHierarchyActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

