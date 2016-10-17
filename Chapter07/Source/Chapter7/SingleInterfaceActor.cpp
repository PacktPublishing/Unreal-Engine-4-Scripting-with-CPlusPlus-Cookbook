// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter7.h"
#include "SingleInterfaceActor.h"


// Sets default values
ASingleInterfaceActor::ASingleInterfaceActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASingleInterfaceActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASingleInterfaceActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

FString ASingleInterfaceActor::GetTestName()
{
	return IMyInterface::GetTestName();
	//IMyInterface::Execute_GetTestName();
}
