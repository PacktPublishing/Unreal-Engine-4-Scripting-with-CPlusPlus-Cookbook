// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter7.h"
#include "Zombie.h"


// Sets default values
AZombie::AZombie()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AZombie::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AZombie::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

