// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "AttributeGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER9_API AAttributeGameMode : public AGameMode
{
	GENERATED_BODY()
	
	
	TSharedPtr<SVerticalBox> Widget;
	
	FText GetButtonLabel() const ;

	
public:
	virtual void BeginPlay() override;

};
