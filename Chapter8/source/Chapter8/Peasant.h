// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "King.h"
#include "Peasant.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER8_API APeasant : public AStaticMeshActor
{
	GENERATED_BODY()
public:
		APeasant();
		UFUNCTION(BlueprintCallable, category = Peasant)
			void Flee(AKing* DeadKing);
};
