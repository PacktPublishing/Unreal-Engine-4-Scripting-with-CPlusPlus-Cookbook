// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter8.h"
#include "BlueprintPropertyActor.h"


// Sets default values
ABlueprintPropertyActor::ABlueprintPropertyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABlueprintPropertyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlueprintPropertyActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

