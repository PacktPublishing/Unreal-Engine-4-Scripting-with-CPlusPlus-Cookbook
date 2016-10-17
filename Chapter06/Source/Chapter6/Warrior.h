// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Warrior.generated.h"

UCLASS()
class CHAPTER6_API AWarrior : public ACharacter
{
	GENERATED_BODY()
public:
  FVector2D lastInput;

	// Sets default values for this character's properties
	AWarrior( const FObjectInitializer& PCIP );

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent( UInputComponent* Input ) override;

	void Forward( float amount );
  void Back( float amount );
  void Right( float amount );
  void Left( float amount );
	
  // Called every frame
	virtual void Tick( float DeltaSeconds ) override;

  UFUNCTION(BlueprintNativeEvent, Category = Collision)
  void OnOverlapsBegin(
    UPrimitiveComponent* Comp,
    AActor* OtherActor, UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult&SweepResult );

  UFUNCTION(BlueprintNativeEvent, Category = Collision)
	void OnOverlapsEnd(
    UPrimitiveComponent* Comp,
    AActor* OtherActor, UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex );
	
};
