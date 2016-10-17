#pragma once
#include "Killable.h"
#include "Undead.generated.h"


/**  */
UINTERFACE()
class CHAPTER7_API UUndead: public UKillable
{
	GENERATED_BODY()
};

/**  */
class CHAPTER7_API IUndead: public IKillable
{
	GENERATED_BODY()

public:
	virtual bool IsDead() override;
	virtual void Die() override;
	virtual void Turn();
	virtual void Banish();
};
