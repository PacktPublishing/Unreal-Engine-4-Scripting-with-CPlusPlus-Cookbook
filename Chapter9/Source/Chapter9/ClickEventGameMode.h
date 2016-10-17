// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "ClickEventGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER9_API AClickEventGameMode : public AGameMode
{
	GENERATED_BODY()
private:
		TSharedPtr<SVerticalBox> Widget;

		TSharedPtr<STextBlock> ButtonLabel;
	
public:
	virtual void BeginPlay() override;
	FReply ButtonClicked();
};
