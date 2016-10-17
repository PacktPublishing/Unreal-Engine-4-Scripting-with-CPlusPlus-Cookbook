// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter8.h"
#include "PropertySpecifierActor.h"


// Sets default values
APropertySpecifierActor::APropertySpecifierActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APropertySpecifierActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APropertySpecifierActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

