// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "Chapter1GameMode.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER1_API AChapter1GameMode : public AGameMode
{
	GENERATED_BODY()
public:
	AChapter1GameMode( const FObjectInitializer& PCIP );
  void BeginPlay();

};
