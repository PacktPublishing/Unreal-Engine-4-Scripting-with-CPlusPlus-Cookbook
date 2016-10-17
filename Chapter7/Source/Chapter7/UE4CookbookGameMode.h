// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "MyInterface.h"
#include "UE4CookbookGameMode.generated.h"

DECLARE_DELEGATE(FStandardDelegateSignature)

DECLARE_DELEGATE_OneParam(FParamDelegateSignature, FLinearColor)
DECLARE_MULTICAST_DELEGATE(FMulticastDelegateSignature)
/**
 * 
 */
UCLASS()
class CHAPTER7_API AUE4CookbookGameMode : public AGameMode
{
	GENERATED_BODY()

public:
		AUE4CookbookGameMode();

		virtual void BeginPlay() override;

		
		
		FStandardDelegateSignature MyStandardDelegate;

		FParamDelegateSignature MyParameterDelegate;

		FMulticastDelegateSignature MyMulticastDelegate;

		TArray<IMyInterface*> MyInterfaceInstances;
};
