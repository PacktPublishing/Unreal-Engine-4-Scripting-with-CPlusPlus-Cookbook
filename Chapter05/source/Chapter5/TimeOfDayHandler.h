// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TimeOfDayHandler.generated.h"

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnTimeChangedSignature, int32, int32)

UCLASS()
class CHAPTER5_API ATimeOfDayHandler : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimeOfDayHandler();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	FOnTimeChangedSignature OnTimeChanged;
	
	UPROPERTY()
	int32 TimeScale;

	UPROPERTY()
	int32 Hours;
	UPROPERTY()
	int32 Minutes;

	UPROPERTY()
	float ElapsedSeconds;
};
