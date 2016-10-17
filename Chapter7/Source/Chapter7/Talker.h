#pragma once

#include "Talker.generated.h"


/**  */
UINTERFACE()
class CHAPTER7_API UTalker: public UInterface
{
	GENERATED_BODY()
};

/**  */
class CHAPTER7_API ITalker
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Talk)
	void StartTalking();


};
