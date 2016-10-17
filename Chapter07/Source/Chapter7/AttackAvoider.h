#pragma once

#include "AttackAvoider.generated.h"


/**  */
UINTERFACE()
class CHAPTER7_API UAttackAvoider: public UInterface
{
	GENERATED_BODY()
};

/**  */
class CHAPTER7_API IAttackAvoider
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = AttackAvoider)
	void AttackIncoming(AActor* AttackActor);
};
