// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Undead.h"
#include "Zombie.generated.h"

UCLASS()
class CHAPTER7_API AZombie : public AActor, public IUndead
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AZombie();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
