#pragma once

#include "PostBeginPlay.generated.h"


/**  */
UINTERFACE(meta=(CannotImplementInterfaceInBlueprint))
class CHAPTER7_API UPostBeginPlay: public UInterface
{
	GENERATED_BODY()
};

/**  */
class CHAPTER7_API IPostBeginPlay
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category=Test)
	virtual void OnPostBeginPlay();
};
