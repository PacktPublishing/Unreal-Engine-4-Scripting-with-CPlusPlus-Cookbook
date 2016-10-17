// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "HierarchyActor.generated.h"

UCLASS()
class CHAPTER4_API AHierarchyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHierarchyActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY()
		USceneComponent* Root;
	UPROPERTY()
	USceneComponent* ChildSceneComponent;
	UPROPERTY()
		UStaticMeshComponent* BoxOne;
	UPROPERTY()
		UStaticMeshComponent* BoxTwo;
};
