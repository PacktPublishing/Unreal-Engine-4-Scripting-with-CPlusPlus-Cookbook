#pragma once

#include "Object.h"
#include "UserProfile.generated.h"

UCLASS( Blueprintable )
class CHAPTER2_API UUserProfile : public UObject
{
	GENERATED_BODY()
public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
  float Armor;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
  float HpMax;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
  FString Name;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
  FString Email;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
  TSubclassOf<UObject> UClassOfPlayer; // Displays any UClasses
  
  // Deriving from UObject in a dropdown menu in Blueprints
  // Displays string names of UCLASSes that derive from
  // the GameMode C++ base class
  UPROPERTY( EditAnywhere, meta=(MetaClass="GameMode"), Category = Unit )
  FStringClassReference UClassGameMode;
};
