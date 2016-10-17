#include "Chapter7.h"
#include "Undead.h"

bool IUndead::IsDead()
{
	return true;
}

void IUndead::Die()
{
	GEngine->AddOnScreenDebugMessage(-1,1, FColor::Red,"You can't kill what is already dead. Mwahaha");
}

void IUndead::Turn()
{
	GEngine->AddOnScreenDebugMessage(-1,1, FColor::Red, "I'm fleeing!");
	
}

void IUndead::Banish()
{
	AActor* Me = Cast<AActor>(this);
	if (Me)
	{
		Me->Destroy();
	}
}