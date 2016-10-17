// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter4.h"
#include "MyGameState.h"
#include "InventoryCharacter.h"
#include "MyFirstActor.h"

#include "UE4CookbookGameMode.h"




AUE4CookbookGameMode::AUE4CookbookGameMode()
{
	DefaultPawnClass = AInventoryCharacter::StaticClass();
	GameStateClass = AMyGameState::StaticClass();
}

void AUE4CookbookGameMode::BeginPlay()
{
	Super::BeginPlay();
	FTransform SpawnLocation;
	GetWorld()->SpawnActor<AMyFirstActor>(AMyFirstActor::StaticClass(), SpawnLocation);
	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this, &AUE4CookbookGameMode::DestroyActorFunction, 10);
}

void AUE4CookbookGameMode::DestroyActorFunction()
{
	if (SpawnedActor != nullptr)
	{
		SpawnedActor->Destroy();
	}
}

