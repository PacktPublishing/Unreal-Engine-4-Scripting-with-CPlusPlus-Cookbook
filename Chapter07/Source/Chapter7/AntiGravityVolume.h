// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "AntiGravityVolume.generated.h"

UCLASS()
class CHAPTER7_API AAntiGravityVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAntiGravityVolume();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY()
	UBoxComponent* CollisionComponent;
	

public:
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;


	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

};
