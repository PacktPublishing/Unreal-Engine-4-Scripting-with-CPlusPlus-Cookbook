#pragma once

#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/ProgressBar.h"

#include "HttpDialog.generated.h"

UCLASS()
class CHAPTER12_API UHttpDialog : public UUserWidget
{
	GENERATED_BODY()
public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
  UProgressBar* progressBar;
  
  UHttpDialog( const FObjectInitializer& PCIP );
	virtual void OnWidgetRebuilt() override;
};
