// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter5.h"
#include "UE4CookbookGameMode.h"
#include "MulticastDelegateListener.h"


// Sets default values
AMulticastDelegateListener::AMulticastDelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	RootComponent = PointLight;

}

// Called when the game starts or when spawned
void AMulticastDelegateListener::BeginPlay()
{
	Super::BeginPlay();
	UWorld* TheWorld = GetWorld();
	if (TheWorld != nullptr)
	{
		AGameMode* GameMode = UGameplayStatics::GetGameMode(TheWorld);
		AUE4CookbookGameMode * MyGameMode = Cast<AUE4CookbookGameMode>(GameMode);
		if (MyGameMode != nullptr)
		{
			MyDelegateHandle = MyGameMode->MyMulticastDelegate.AddUObject(this, &AMulticastDelegateListener::ToggleLight);
		}
	}

}

// Called every frame
void AMulticastDelegateListener::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AMulticastDelegateListener::ToggleLight()
{
	PointLight->ToggleVisibility();
}

void AMulticastDelegateListener::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	UWorld* TheWorld = GetWorld();
	if (TheWorld != nullptr)
	{
		AGameMode* GameMode = UGameplayStatics::GetGameMode(TheWorld);
		AUE4CookbookGameMode * MyGameMode = Cast<AUE4CookbookGameMode>(GameMode);
		if (MyGameMode != nullptr)
		{
			MyGameMode->MyMulticastDelegate.Remove(MyDelegateHandle);
		}
	}
}

