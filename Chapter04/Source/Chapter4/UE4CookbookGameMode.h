// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "MyFirstActor.h"
#include "UE4CookbookGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER4_API AUE4CookbookGameMode : public AGameMode
{
	GENERATED_BODY()

public:
		AUE4CookbookGameMode();

		virtual void BeginPlay() override;

		UPROPERTY()
		AMyFirstActor* SpawnedActor;

		UFUNCTION()
		void DestroyActorFunction();

};
