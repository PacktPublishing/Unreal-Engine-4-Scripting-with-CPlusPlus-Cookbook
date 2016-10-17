#pragma once

#include "Interactable.generated.h"


/**  */
UINTERFACE()
class CHAPTER7_API UInteractable: public UInterface
{
	GENERATED_BODY()
};

/**  */
class CHAPTER7_API IInteractable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category=Interactable)
	bool CanInteract();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Interactable)
	void PerformInteract();
	
};
