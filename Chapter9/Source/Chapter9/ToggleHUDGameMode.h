// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "ToggleHUDGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER9_API AToggleHUDGameMode : public AGameMode
{
	GENERATED_BODY()
	
	
	
	
public:
	virtual void BeginPlay() override;
	UPROPERTY()
		FTimerHandle HUDToggleTimer;
	
	TSharedPtr<SVerticalBox> widget;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

};
