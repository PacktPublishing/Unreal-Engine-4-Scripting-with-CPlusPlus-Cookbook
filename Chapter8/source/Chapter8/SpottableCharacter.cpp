// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter8.h"
#include "SpottableCharacter.h"


// Sets default values
ASpottableCharacter::ASpottableCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpottableCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpottableCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}
