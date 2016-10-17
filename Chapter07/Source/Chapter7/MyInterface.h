#pragma once

#include "MyInterface.generated.h"


/**  */
UINTERFACE()
class CHAPTER7_API UMyInterface: public UInterface
{
	GENERATED_BODY()
};

/**  */
class CHAPTER7_API IMyInterface
{
	GENERATED_BODY()

public:
	virtual FString GetTestName();
	/*
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category=Test)
	FString GetTestName2();*/
};
