#include "Chapter12.h"
#include "GameUnitAttributeSet.h"

UGameUnitAttributeSet::UGameUnitAttributeSet( const FObjectInitializer& PCIP ) : Super( PCIP )
{

}

bool UGameUnitAttributeSet::PreGameplayEffectExecute( FGameplayEffectModCallbackData &Data )
{
  return Super::PreGameplayEffectExecute( Data );
}

void UGameUnitAttributeSet::PostGameplayEffectExecute( const FGameplayEffectModCallbackData &Data )
{
  Super::PostGameplayEffectExecute( Data );
}
