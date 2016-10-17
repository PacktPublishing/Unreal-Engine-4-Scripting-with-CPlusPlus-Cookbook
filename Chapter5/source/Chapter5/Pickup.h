// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

DECLARE_DELEGATE(FPickedupEventSignature)

UCLASS()
class CHAPTER5_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UPROPERTY()
		UStaticMeshComponent* MyMesh;

	UPROPERTY()
		URotatingMovementComponent* RotatingComponent;

	FPickedupEventSignature OnPickedUp;
	
};
