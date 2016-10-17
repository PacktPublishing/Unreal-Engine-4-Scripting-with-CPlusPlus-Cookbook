#pragma once

#include "Runtime/GameplayAbilities/Public/AttributeSet.h"
#include "GameUnitAttributeSet.generated.h"

UCLASS(Blueprintable, BlueprintType)
class CHAPTER12_API UGameUnitAttributeSet : public UAttributeSet
{
  GENERATED_BODY()
public:
  UGameUnitAttributeSet( const FObjectInitializer& PCIP );
  UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = GameUnitAttributes )
  float Hp;
  UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = GameUnitAttributes )
  float Mana;
  UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = GameUnitAttributes )
  float Speed;

	/**
	 *	Called just before modifying the value of an attribute. 
      AttributeSet can make additional modifications here. 
      Return true to continue, or false to throw out the modification.
	 *	Note this is only called during an 'execute'. E.g., a modification 
      to the 'base value' of an attribute. It is not called during an application 
      of a GameplayEffect, such as a 5 ssecond +10 movement speed buff.
	 */	
	virtual bool PreGameplayEffectExecute( FGameplayEffectModCallbackData &Data );
	
	
	/**
	 *	Called just before a GameplayEffect is executed to modify the base value of an attribute. 
      No more changes can be made.
	 *	Note this is only called during an 'execute'. E.g., a modification to the 'base value' 
      of an attribute. It is not called during an application of a GameplayEffect, such as a 5 ssecond +10 movement speed buff.
	 */
	virtual void PostGameplayEffectExecute( const FGameplayEffectModCallbackData &Data );

};
