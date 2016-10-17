// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "StyledHUDGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER9_API AStyledHUDGameMode : public AGameMode
{
	GENERATED_BODY()
	
	TSharedPtr<SVerticalBox> Widget;
public:
	virtual void BeginPlay() override;

	
};
