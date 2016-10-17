// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Factories/Factory.h"
#include "CustomAssetFactory.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER8EDITOR_API UCustomAssetFactory : public UFactory
{
	GENERATED_BODY()

public:
		UCustomAssetFactory();

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext) override;

};
