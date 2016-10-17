// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "UE4CookbookEditor.h"
#include "K2Node.h"
#include "K2Node_IsInEditor.generated.h"
/**
 * 
 */
UCLASS()
class CHAPTER8EDITOR_API UK2Node_IsInEditor: public UK2Node
{
	GENERATED_BODY()
public:
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;


	virtual void AllocateDefaultPins() override;

private:
	virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;

};
