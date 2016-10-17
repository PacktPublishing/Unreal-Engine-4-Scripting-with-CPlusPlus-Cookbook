#include "Chapter7.h"
#include "PostBeginPlay.h"


void IPostBeginPlay::OnPostBeginPlay()
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "PostBeginPlay called");
}
