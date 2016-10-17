// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Clock.generated.h"

UCLASS()
class CHAPTER5_API AClock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AClock();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY()
		USceneComponent* RootSceneComponent;

	UPROPERTY()
		UStaticMeshComponent* ClockFace;
	UPROPERTY()
		USceneComponent* HourHandle;
	UPROPERTY()
		UStaticMeshComponent* HourHand;
	UPROPERTY()
		USceneComponent* MinuteHandle;
	UPROPERTY()
		UStaticMeshComponent* MinuteHand;

	UFUNCTION()
	void TimeChanged(int32 Hours, int32 Minutes);
	
	FDelegateHandle MyDelegateHandle;

};
