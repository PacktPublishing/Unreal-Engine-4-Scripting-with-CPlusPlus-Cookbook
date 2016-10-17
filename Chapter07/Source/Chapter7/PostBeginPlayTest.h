// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PostBeginPlay.h"
#include "PostBeginPlayTest.generated.h"

UCLASS()
class CHAPTER7_API APostBeginPlayTest : public AActor, public IPostBeginPlay
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APostBeginPlayTest();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY()
		UStaticMeshComponent* MyMesh;


};
