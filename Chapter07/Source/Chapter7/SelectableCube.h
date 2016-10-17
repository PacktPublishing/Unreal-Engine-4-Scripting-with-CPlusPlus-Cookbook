// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PhysicsCube.h"
#include "Selectable.h"
#include "SelectableCube.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER7_API ASelectableCube : public APhysicsCube, public ISelectable
{
	GENERATED_BODY()


public:
	ASelectableCube();
	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

};
