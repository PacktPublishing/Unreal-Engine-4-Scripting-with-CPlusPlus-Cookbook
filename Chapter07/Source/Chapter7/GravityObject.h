#pragma once

#include "GravityObject.generated.h"


/**  */
UINTERFACE()
class CHAPTER7_API UGravityObject: public UInterface
{
	GENERATED_BODY()
};

/**  */
class CHAPTER7_API IGravityObject
{
	GENERATED_BODY()

public:
	virtual void EnableGravity();

	virtual void DisableGravity();
	/*
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category=Test)
	FString GetTestName2();*/
};
