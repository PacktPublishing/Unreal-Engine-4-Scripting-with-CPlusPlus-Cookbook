// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter7.h"
#include "Interactable.h"
#include "InteractingPawn.h"




void AInteractingPawn::TryInteract()
{
	
	
	APlayerController* MyController = Cast<APlayerController>(Controller);
	if (MyController)
	{
		APlayerCameraManager* MyCameraManager = MyController->PlayerCameraManager;
		auto StartLocation = MyCameraManager->GetCameraLocation();
		auto EndLocation = MyCameraManager->GetCameraLocation() + (MyCameraManager->GetActorForwardVector() * 100);
		FCollisionObjectQueryParams Params;
		FHitResult HitResult;
		GetWorld()->SweepSingleByObjectType(HitResult, StartLocation, EndLocation, FQuat::Identity, 
			FCollisionObjectQueryParams(FCollisionObjectQueryParams::AllObjects), FCollisionShape::MakeSphere(25),
			FCollisionQueryParams(FName("Interaction"),true,this));
		
		if (HitResult.Actor != nullptr)
		{
			if (HitResult.Actor->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
			{
				if (IInteractable::Execute_CanInteract(HitResult.Actor.Get()))
				{
					IInteractable::Execute_PerformInteract(HitResult.Actor.Get());
				}
			}
		}

	}
	

}

void AInteractingPawn::SetupPlayerInputComponent(UInputComponent* InInputComponent)
{
	Super::SetupPlayerInputComponent(InInputComponent);
	InInputComponent->BindAction("Interact", IE_Released, this, &AInteractingPawn::TryInteract);
}
