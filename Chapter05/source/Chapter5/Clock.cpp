// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter5.h"
#include "TimeOfDayHandler.h"
#include "Clock.h"


// Sets default values
AClock::AClock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootSceneComponent = CreateDefaultSubobject<USceneComponent>("RootSceneComponent");
	ClockFace = CreateDefaultSubobject<UStaticMeshComponent>("ClockFace");
	HourHand = CreateDefaultSubobject<UStaticMeshComponent>("HourHand");
	MinuteHand = CreateDefaultSubobject<UStaticMeshComponent>("MinuteHand");
	HourHandle = CreateDefaultSubobject<USceneComponent>("HourHandle");
	MinuteHandle = CreateDefaultSubobject<USceneComponent>("MinuteHandle");
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));
	if (MeshAsset.Object != nullptr)
	{
		ClockFace->SetStaticMesh(MeshAsset.Object);
		HourHand->SetStaticMesh(MeshAsset.Object);
		MinuteHand->SetStaticMesh(MeshAsset.Object);
	}
	RootComponent = RootSceneComponent;
	HourHand->AttachTo(HourHandle);
	MinuteHand->AttachTo(MinuteHandle);
	HourHandle->AttachTo(RootSceneComponent);
	MinuteHandle->AttachTo(RootSceneComponent);
	ClockFace->AttachTo(RootSceneComponent);


	ClockFace->SetRelativeTransform(FTransform(FRotator(90, 0, 0), FVector(10, 0, 0), FVector(2, 2, 0.1)));
	HourHand->SetRelativeTransform(FTransform(FRotator(0, 0, 0), FVector(0, 0, 25), FVector(0.1, 0.1, 0.5)));
	MinuteHand->SetRelativeTransform(FTransform(FRotator(0, 0, 0), FVector(0, 0, 50), FVector(0.1, 0.1, 1)));

}

// Called when the game starts or when spawned
void AClock::BeginPlay()
{
	Super::BeginPlay();
	TArray<AActor*> TimeOfDayHandlers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATimeOfDayHandler::StaticClass(), TimeOfDayHandlers);
	if (TimeOfDayHandlers.Num() != 0)
	{
		auto TimeOfDayHandler = Cast<ATimeOfDayHandler>(TimeOfDayHandlers[0]);
		MyDelegateHandle = TimeOfDayHandler->OnTimeChanged.AddUObject(this, &AClock::TimeChanged);
	}
	
}

// Called every frame
void AClock::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AClock::TimeChanged(int32 Hours, int32 Minutes)
{
	HourHandle->SetRelativeRotation(FRotator( 0, 0,30 * Hours));
	MinuteHandle->SetRelativeRotation(FRotator(0,0,6 * Minutes));

}

