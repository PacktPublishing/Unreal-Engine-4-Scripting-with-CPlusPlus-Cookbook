#pragma once

#include "Wearable.generated.h"


/**  */
UINTERFACE()
class CHAPTER7_API UWearable: public UInterface
{
	GENERATED_BODY()
};

/**  */
class CHAPTER7_API IWearable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Wearable)
		int32 GetStrengthRequirement();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Wearable)
		bool CanEquip(APawn* Wearer);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Wearable)
		void OnEquip(APawn* Wearer);
};
