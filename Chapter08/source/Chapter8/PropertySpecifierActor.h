// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PropertySpecifierActor.generated.h"

UCLASS()
class CHAPTER8_API APropertySpecifierActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APropertySpecifierActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditDefaultsOnly)
	bool EditDefaultsOnly;
	UPROPERTY(EditInstanceOnly)
		bool EditInstanceOnly;
	UPROPERTY(EditAnywhere)
		bool EditAnywhere;
	UPROPERTY(VisibleDefaultsOnly)
		bool VisibleDefaultsOnly;
	UPROPERTY(VisibleInstanceOnly)
		bool VisibleInstanceOnly;
	UPROPERTY(VisibleAnywhere)
		bool VisibleAnywhere;
};
