// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter4.h"
#include "LifeSpanActor.h"


// Sets default values
ALifeSpanActor::ALifeSpanActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALifeSpanActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALifeSpanActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

