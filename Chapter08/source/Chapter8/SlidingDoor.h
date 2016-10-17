// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "SlidingDoor.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER8_API ASlidingDoor : public AStaticMeshActor
{
	GENERATED_BODY()
public:
		ASlidingDoor();
	UFUNCTION(BlueprintCallable, Category = Door)
	void Open();
	
	UPROPERTY()
	bool IsOpen;

	UPROPERTY()
	FVector TargetLocation;


	virtual void Tick(float DeltaSeconds) override;

};
