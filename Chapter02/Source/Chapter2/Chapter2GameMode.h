// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "Chapter2GameMode.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER2_API AChapter2GameMode : public AGameMode
{
	GENERATED_BODY()
public:
	AChapter2GameMode( const FObjectInitializer& PCIP );
	void BeginPlay();

};
