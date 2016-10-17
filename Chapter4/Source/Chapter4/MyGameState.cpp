// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter4.h"
#include "UE4CookbookGameMode.h"
#include "MyGameState.h"

AMyGameState::AMyGameState()
{
	CurrentScore = 0;
}


int32 AMyGameState::GetScore()
{
	return CurrentScore;
}

void AMyGameState::SetScore(uint32 NewScore)
{
	CurrentScore = NewScore;
}

void AMyGameState::BeginPlay()
{
	UWorld* TheWorld = GetWorld();
	if (TheWorld != nullptr)
	{
		AGameMode* GameMode = UGameplayStatics::GetGameMode(TheWorld);
		AUE4CookbookGameMode * MyGameMode = Cast<AUE4CookbookGameMode>(GameMode);
		
	}
	
}

