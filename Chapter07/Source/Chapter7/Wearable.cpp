#include "Chapter7.h"
#include "Wearable.h"

int32 IWearable::GetStrengthRequirement_Implementation()
{
	return 0;
}

bool IWearable::CanEquip_Implementation(APawn* Wearer)
{
	return true;
}

void IWearable::OnEquip_Implementation(APawn* Wearer)
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "Item being worn");
}
