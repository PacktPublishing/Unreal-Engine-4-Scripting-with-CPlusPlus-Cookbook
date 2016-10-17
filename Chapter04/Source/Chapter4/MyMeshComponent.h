// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/MeshComponent.h"
#include "MyMeshComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = Experimental, meta = (BlueprintSpawnableComponent))
class CHAPTER4_API UMyMeshComponent : public UMeshComponent
{
	GENERATED_BODY()
	
public:
		// Begin UPrimitiveComponent interface.
		virtual FPrimitiveSceneProxy* CreateSceneProxy() override;
	TArray<int32> Indices;
	TArray<FVector> Vertices;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Materials)
		UMaterial* TheMaterial;
	
	UMyMeshComponent();

};
