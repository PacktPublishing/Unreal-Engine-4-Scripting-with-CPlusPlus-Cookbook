// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter5.h"
#include "UE4CookbookGameMode.h"
#include "DelegateListener.h"


// Sets default values
ADelegateListener::ADelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	RootComponent = PointLight;
	
	PointLight->SetVisibility(false);
}

// Called when the game starts or when spawned
void ADelegateListener::BeginPlay()
{
	Super::BeginPlay();
	UWorld* TheWorld = GetWorld();
	if (TheWorld != nullptr)
	{
		AGameMode* GameMode = UGameplayStatics::GetGameMode(TheWorld);
		AUE4CookbookGameMode * MyGameMode = Cast<AUE4CookbookGameMode>(GameMode);
		if (MyGameMode != nullptr)
		{
			MyGameMode->MyStandardDelegate.BindUObject(this, &ADelegateListener::EnableLight);
		}
	}

}

// Called every frame
void ADelegateListener::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ADelegateListener::EnableLight()
{
	PointLight->SetVisibility(true);
}

void ADelegateListener::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	UWorld* TheWorld = GetWorld();
	if (TheWorld != nullptr)
	{
		AGameMode* GameMode = UGameplayStatics::GetGameMode(TheWorld);
		AUE4CookbookGameMode * MyGameMode = Cast<AUE4CookbookGameMode>(GameMode);
		if (MyGameMode != nullptr)
		{
			MyGameMode->MyStandardDelegate.Unbind();
		}
	}
}
