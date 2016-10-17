// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ParamDelegateListener.generated.h"

UCLASS()
class CHAPTER5_API AParamDelegateListener : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AParamDelegateListener();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION()
		void SetLightColor(FLinearColor LightColor, bool EnableLight);

	UPROPERTY()
		UPointLightComponent* PointLight;

	
};
