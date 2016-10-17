// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Killable.h"
#include "Snail.generated.h"

UCLASS()
class CHAPTER7_API ASnail : public AActor, public IKillable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASnail();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
