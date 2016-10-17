#include "Chapter7.h"
#include "GravityObject.h"


void IGravityObject::EnableGravity()
{
	AActor* ThisAsActor = Cast<AActor>(this);
	if (ThisAsActor != nullptr)
	{
		TArray<UPrimitiveComponent*> PrimitiveComponents;
		ThisAsActor->GetComponents(PrimitiveComponents);
		for (UPrimitiveComponent* Component : PrimitiveComponents)
		{
			Component->SetEnableGravity(true);
		}
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Enabling Gravity"));
	}
}

void IGravityObject::DisableGravity()
{
	AActor* ThisAsActor = Cast<AActor>(this);
	if (ThisAsActor != nullptr)
	{
		TArray<UPrimitiveComponent*> PrimitiveComponents;
		ThisAsActor->GetComponents(PrimitiveComponents);
		for (UPrimitiveComponent* Component : PrimitiveComponents)
		{
			Component->SetEnableGravity(false);
		}
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Disabling Gravity"));
	}
}
