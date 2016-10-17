#pragma once

#include "GameUnitAttributeStatsRow.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct FGameUnitAttributeStatsRow : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = Stats )
	float StartingHp;
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = Stats )
	float StartingMana;
};

