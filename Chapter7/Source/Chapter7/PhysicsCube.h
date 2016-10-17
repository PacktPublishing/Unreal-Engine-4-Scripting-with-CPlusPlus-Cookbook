// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "GravityObject.h"
#include "PhysicsCube.generated.h"

UCLASS()
class CHAPTER7_API APhysicsCube : public AActor, public IGravityObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APhysicsCube();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY()
		UStaticMeshComponent* MyMesh;
	
};
