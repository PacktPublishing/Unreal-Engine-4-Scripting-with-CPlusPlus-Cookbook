// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PickupSpawner.generated.h"

UCLASS()
class CHAPTER5_API APickupSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupSpawner();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY()
		USceneComponent* SpawnLocation;

	UFUNCTION()
		void PickupCollected();
	
	UFUNCTION()
	void SpawnPickup();

	UPROPERTY()
	APickup* CurrentPickup;
	
	FTimerHandle MyTimer;

};
