// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "CustomHUD.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER9_API ACustomHUD : public AHUD
{
	GENERATED_BODY()
	
	
	
	
public:
	virtual void DrawHUD() override;

};
