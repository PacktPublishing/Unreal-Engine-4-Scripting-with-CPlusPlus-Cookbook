// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Commands.h"
#include "EditorStyleSet.h"
/**
 * 
 */
class FCookbookCommands : public TCommands<FCookbookCommands>
{
public:
	FCookbookCommands()
		: TCommands<FCookbookCommands>(FName(TEXT("UE4_Cookbook")), FText::FromString("Cookbook Commands"), NAME_None, FEditorStyle::GetStyleSetName()) 
	{
	};
	virtual void RegisterCommands() override;

	TSharedPtr<FUICommandInfo> MyButton;
	
	TSharedPtr<FUICommandInfo> MyMenuButton;
};
