// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MyTriggerVolume.h"
#include "TriggerVolEventListener.generated.h"

UCLASS()
class CHAPTER5_API ATriggerVolEventListener : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATriggerVolEventListener();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY()
		UPointLightComponent* PointLight;

	UPROPERTY(EditAnywhere)
		AMyTriggerVolume* TriggerEventSource;
	
	UFUNCTION()
		void OnTriggerEvent();
};
