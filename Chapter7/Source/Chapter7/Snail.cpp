// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter7.h"
#include "Snail.h"


// Sets default values
ASnail::ASnail()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASnail::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASnail::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

