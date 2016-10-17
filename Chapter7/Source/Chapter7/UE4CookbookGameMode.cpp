// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter7.h"

#include "MyInterface.h"
#include "UE4CookbookGameMode.h"




AUE4CookbookGameMode::AUE4CookbookGameMode()
{
}

void AUE4CookbookGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	for (TActorIterator<AActor> It(GetWorld(), AActor::StaticClass()); It; ++It)
	{
		AActor* Actor = *It;
		IMyInterface* MyInterfaceInstance = Cast<IMyInterface>(Actor);
		if (MyInterfaceInstance)
		{
			MyInterfaceInstances.Add(MyInterfaceInstance);
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, FString::Printf(TEXT("%d actors implement the interface"), MyInterfaceInstances.Num()));
}
