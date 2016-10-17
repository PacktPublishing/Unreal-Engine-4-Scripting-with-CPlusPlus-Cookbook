// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter5.h"
#include "UE4CookbookGameMode.h"
#include "ParamDelegateListener.h"


// Sets default values
AParamDelegateListener::AParamDelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	RootComponent = PointLight;

}

// Called when the game starts or when spawned
void AParamDelegateListener::BeginPlay()
{
	Super::BeginPlay();
	UWorld* TheWorld = GetWorld();
	if (TheWorld != nullptr)
	{
		AGameMode* GameMode = UGameplayStatics::GetGameMode(TheWorld);
		AUE4CookbookGameMode * MyGameMode = Cast<AUE4CookbookGameMode>(GameMode);
		if (MyGameMode != nullptr)
		{
			MyGameMode->MyParameterDelegate.BindUObject(this, &AParamDelegateListener::SetLightColor, true);
		}
	}

}

// Called every frame
void AParamDelegateListener::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AParamDelegateListener::SetLightColor(FLinearColor LightColor, bool EnableLight)
{
	PointLight->SetLightColor(LightColor);
	PointLight->SetVisibility(EnableLight);
}
