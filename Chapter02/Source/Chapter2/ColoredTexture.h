#pragma once

#include "Chapter2.h"
#include "ColoredTexture.generated.h"

USTRUCT()
struct CHAPTER2_API FColoredTexture
{
	GENERATED_USTRUCT_BODY()
public:
  UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = HUD )
  UTexture* Texture;
  UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = HUD )    
  FLinearColor Color;
};
