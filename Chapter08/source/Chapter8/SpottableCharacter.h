// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/DefaultPawn.h"
#include "SpottableCharacter.generated.h"

UCLASS()
class CHAPTER8_API ASpottableCharacter : public ADefaultPawn
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASpottableCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	

	
	
};
