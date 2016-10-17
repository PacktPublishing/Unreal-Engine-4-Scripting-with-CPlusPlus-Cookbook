#pragma once

#include "Openable.generated.h"


/**  */
UINTERFACE()
class CHAPTER7_API UOpenable: public UInterface
{
	GENERATED_BODY()
};

/**  */
class CHAPTER7_API IOpenable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category=Openable)
	void Open();

	
};
