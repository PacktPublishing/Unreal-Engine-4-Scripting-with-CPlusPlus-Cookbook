#pragma once

#include "Selectable.generated.h"


/**  */
UINTERFACE()
class CHAPTER7_API USelectable: public UInterface
{
	GENERATED_BODY()
};

/**  */
class CHAPTER7_API ISelectable
{
	GENERATED_BODY()

public:
	virtual bool IsSelectable();

	virtual bool TrySelect();
	
	virtual void Deselect();
	/*
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category=Test)
	FString GetTestName2();*/
};
