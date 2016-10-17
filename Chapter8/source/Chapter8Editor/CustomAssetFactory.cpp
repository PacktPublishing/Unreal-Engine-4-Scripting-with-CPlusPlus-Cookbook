// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4CookbookEditor.h"
#include "MyCustomAsset.h"
#include "CustomAssetFactory.h"




UCustomAssetFactory::UCustomAssetFactory()
	:Super()
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UMyCustomAsset::StaticClass();
}

UObject* UCustomAssetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	auto NewObjectAsset = NewObject<UMyCustomAsset>(InParent, InClass, InName, Flags);
	return NewObjectAsset;
}
