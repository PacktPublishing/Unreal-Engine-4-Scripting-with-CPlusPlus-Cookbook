// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter7.h"
#include "Talker.h"
#include "TalkingCharacter.h"


// Sets default values
ATalkingPawn::ATalkingPawn()
	:Super()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TalkCollider = CreateDefaultSubobject<UBoxComponent>("TalkCollider"); 
	TalkCollider->SetBoxExtent(FVector(200, 200, 100));
	TalkCollider->OnComponentBeginOverlap.AddDynamic(this, &ATalkingPawn::OnTalkOverlap);
	TalkCollider->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void ATalkingPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATalkingPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input

void ATalkingPawn::OnTalkOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor->GetClass()->ImplementsInterface(UTalker::StaticClass()))
	{
		ITalker::Execute_StartTalking(OtherActor);
	}
}

