// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/DefaultPawn.h"
#include "TalkingCharacter.generated.h"

UCLASS()
class CHAPTER7_API ATalkingPawn : public ADefaultPawn
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATalkingPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY()
		UBoxComponent* TalkCollider;
	UFUNCTION()
		void OnTalkOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
};
