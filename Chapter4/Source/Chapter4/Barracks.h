// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Barracks.generated.h"

UCLASS()
class CHAPTER4_API ABarracks : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABarracks();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY()
	UStaticMeshComponent* BuildingMesh;
	
	UPROPERTY()
	UParticleSystemComponent* SpawnPoint;

	UPROPERTY()
	UClass* UnitToSpawn;

	UPROPERTY()
	float SpawnInterval;

	UFUNCTION()
	void SpawnUnit();

	UFUNCTION()
	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY()
	FTimerHandle SpawnTimerHandle;
};
