// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameState.h"
#include "MyGameState.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER4_API AMyGameState : public AGameState
{
	GENERATED_BODY()
public:
	AMyGameState();

	UPROPERTY()
	int32 CurrentScore;
	
	UFUNCTION()
	int32 GetScore();
	
	UFUNCTION()
	void SetScore(uint32 NewScore);

	UFUNCTION()
	virtual void BeginPlay() override;

};
