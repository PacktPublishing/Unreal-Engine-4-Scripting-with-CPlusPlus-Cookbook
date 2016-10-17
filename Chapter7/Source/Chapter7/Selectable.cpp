#include "Chapter7.h"
#include "Selectable.h"


bool ISelectable::IsSelectable()
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "Selectable");
	return true;
}

bool ISelectable::TrySelect()
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "Accepting Selection");
	return true;
}

void ISelectable::Deselect()
{
	unimplemented();
}
