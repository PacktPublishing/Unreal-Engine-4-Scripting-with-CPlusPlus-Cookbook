// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4CookbookEditor.h"
#include "Commands.h"
#include "CookbookCommands.h"

void FCookbookCommands::RegisterCommands()
{
#define LOCTEXT_NAMESPACE ""
	UI_COMMAND(MyButton, "Cookbook", "Demo Cookbook Toolbar Command", EUserInterfaceActionType::Button, FInputGesture());
	UI_COMMAND(MyMenuButton, "Cookbook", "Demo Cookbook Toolbar Command", EUserInterfaceActionType::Button, FInputGesture());
#undef LOCTEXT_NAMESPACE
}
