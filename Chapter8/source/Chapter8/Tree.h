// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Tree.generated.h"

UENUM(BlueprintType)
enum TreeType
{
	Tree_Poplar,
	Tree_Spruce,
	Tree_Eucalyptus,
	Tree_Redwood
};


UCLASS()
class CHAPTER8_API ATree : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATree();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(BlueprintReadWrite)
		TEnumAsByte<TreeType> Type;
	
};
