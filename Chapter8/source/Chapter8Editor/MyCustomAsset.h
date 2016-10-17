// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"

#include "MyCustomAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, EditInlineNew)
class CHAPTER8EDITOR_API UMyCustomAsset : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY( BlueprintReadWrite,EditAnywhere, Category = "Custom Asset")
	FString ColorName;

	
};




