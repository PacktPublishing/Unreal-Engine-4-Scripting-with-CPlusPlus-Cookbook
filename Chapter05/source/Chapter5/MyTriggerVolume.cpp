// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter5.h"
#include "UE4CookbookGameMode.h"
#include "MyTriggerVolume.h"


// Sets default values
AMyTriggerVolume::AMyTriggerVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TriggerZone = CreateDefaultSubobject<UBoxComponent>("TriggerZone");
	TriggerZone->SetBoxExtent(FVector(200, 200, 100));
	//TriggerZone->OnComponentBeginOverlap.AddDynamic(this, &AMyTriggerVolume::OnTriggerOverlap);
}

// Called when the game starts or when spawned
void AMyTriggerVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTriggerVolume::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


void AMyTriggerVolume::NotifyActorBeginOverlap(AActor* OtherActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s entered me"), *(OtherActor->GetName())));
	UWorld* TheWorld = GetWorld();
	if (TheWorld != nullptr)
	{
		AGameMode* GameMode = UGameplayStatics::GetGameMode(TheWorld);
		AUE4CookbookGameMode * MyGameMode = Cast<AUE4CookbookGameMode>(GameMode);
		MyGameMode->MyStandardDelegate.ExecuteIfBound();
		MyGameMode->MyParameterDelegate.ExecuteIfBound(FLinearColor(1, 0, 0, 1));
		MyGameMode->MyMulticastDelegate.Broadcast();
		OnPlayerEntered.Broadcast();
	}



}

void AMyTriggerVolume::NotifyActorEndOverlap(AActor* OtherActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s left me"), *(OtherActor->GetName())));
}

