// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter8.h"
#include "PostEditChangePropertyActor.h"


// Sets default values
APostEditChangePropertyActor::APostEditChangePropertyActor()
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
	ShowStaticMesh = true;

}

// Called when the game starts or when spawned
void APostEditChangePropertyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APostEditChangePropertyActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void APostEditChangePropertyActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.Property != nullptr)
	{
		const FName PropertyName(PropertyChangedEvent.Property->GetFName());
		if (PropertyName == GET_MEMBER_NAME_CHECKED(APostEditChangePropertyActor, ShowStaticMesh))
		{
			if (GetStaticMeshComponent() != nullptr)
			{
				GetStaticMeshComponent()->SetVisibility(ShowStaticMesh);
			}
		}
	}


	Super::PostEditChangeProperty(PropertyChangedEvent);
}
