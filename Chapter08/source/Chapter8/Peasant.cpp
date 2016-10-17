// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter8.h"

#include "Peasant.h"




APeasant::APeasant()
{
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (MeshAsset.Object != nullptr)
	{
		GetStaticMeshComponent()->SetStaticMesh(MeshAsset.Object);
		GetStaticMeshComponent()->bGenerateOverlapEvents = true;
	}
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);

}

void APeasant::Flee(AKing* DeadKing)
{
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("Waily Waily!"));
	FVector FleeVector = GetActorLocation() - DeadKing->GetActorLocation();
	FleeVector.Normalize();
	FleeVector *= 500;
	SetActorLocation(GetActorLocation() + FleeVector);
}

