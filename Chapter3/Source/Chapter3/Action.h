#pragma once

#include "Object.h"
#include "Action.generated.h"

UCLASS(BlueprintType, Blueprintable, meta=(ShortTooltip="Base class for any Action type") )
class CHAPTER3_API UAction : public UObject
{
  GENERATED_BODY()
public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Properties)
  FString Text;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Properties)
  FKey ShortcutKey;
};