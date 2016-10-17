// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter4.h"
#include "OrbitingMovementComponent.h"


// Sets default values for this component's properties
UOrbitingMovementComponent::UOrbitingMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	RotationSpeed = 5;
	OrbitDistance = 100;
	CurrentValue = 0;
	RotateToFaceOutwards = true;
	// ...
}


// Called when the game starts
void UOrbitingMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOrbitingMovementComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	float CurrentValueInRadians = FMath::DegreesToRadians<float>(CurrentValue);

	SetRelativeLocation(
		FVector(OrbitDistance * FMath::Cos(CurrentValueInRadians), 
		OrbitDistance * FMath::Sin(CurrentValueInRadians), 
		RelativeLocation.Z));

	if (RotateToFaceOutwards)
	{
		FVector LookDir = (RelativeLocation).GetSafeNormal();
		FRotator LookAtRot = LookDir.Rotation();
		SetRelativeRotation(LookAtRot);
	}
	CurrentValue = FMath::Fmod(CurrentValue + (RotationSpeed* DeltaTime) ,360);
	// ...
}

