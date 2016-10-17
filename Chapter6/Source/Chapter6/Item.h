// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class CHAPTER6_API AItem : public AActor
{
	GENERATED_BODY()
	
public:
  UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = Collisions )
  USphereComponent* sphere;

	// Sets default values for this actor's properties
	AItem( const FObjectInitializer& PCIP );

  virtual void PostInitializeComponents() override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintNativeEvent, Category = Collision)
  void OnOverlapsBegin(
    UPrimitiveComponent* Comp,
    AActor* OtherActor, UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult&SweepResult );


	
};
