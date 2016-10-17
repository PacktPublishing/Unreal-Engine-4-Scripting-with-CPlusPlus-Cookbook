#pragma once

#include "Killable.generated.h"


/**  */
UINTERFACE(meta=(CannotImplementInterfaceInBlueprint))
class CHAPTER7_API UKillable: public UInterface
{
	GENERATED_BODY()
};

/**  */
class CHAPTER7_API IKillable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category=Killable)
	virtual bool IsDead();
	UFUNCTION(BlueprintCallable, Category = Killable)
	virtual void Die();
	
};
