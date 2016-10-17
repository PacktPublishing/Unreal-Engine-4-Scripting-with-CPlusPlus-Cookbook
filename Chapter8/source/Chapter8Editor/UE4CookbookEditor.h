#pragma once
#include "Engine.h"
#include "ModuleManager.h"
#include "CookbookCommands.h"
#include "MainFrame.h"
#include "AssetTypeActions_Base.h"
#include "UnrealEd.h"
#include "MyCustomAsset.h"
#include "MyCustomAssetPinFactory.h"
#include "MultiBoxExtender.h"


class FUE4CookbookEditorModule: public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
 
	TArray< TSharedPtr<IAssetTypeActions> > CreatedAssetTypeActions;
	TSharedPtr<FMyCustomAssetPinFactory> PinFactory;
	IConsoleCommand* DisplayTestCommand;
	IConsoleCommand* DisplayUserSpecifiedWindow;
	void DisplayWindow(FString WindowTitle)
	{
		TSharedRef<SWindow> CookbookWindow = SNew(SWindow)
			.Title(FText::FromString(WindowTitle))
			.ClientSize(FVector2D(800, 400))
			.SupportsMaximize(false)
			.SupportsMinimize(false);

		IMainFrameModule& MainFrameModule = FModuleManager::LoadModuleChecked<IMainFrameModule>(TEXT("MainFrame"));

		if (MainFrameModule.GetParentWindow().IsValid())
		{
			FSlateApplication::Get().AddWindowAsNativeChild(CookbookWindow, MainFrameModule.GetParentWindow().ToSharedRef());
		}
		else
		{
			FSlateApplication::Get().AddWindow(CookbookWindow);
		}

	}

	TSharedPtr<FExtender> ToolbarExtender;
	TSharedPtr<const FExtensionBase> Extension;

	
	void MyButton_Clicked()
	{
		TSharedRef<SWindow> CookbookWindow = SNew(SWindow)
			.Title(FText::FromString(TEXT("Cookbook Window")))
			.ClientSize(FVector2D(800, 400))
			.SupportsMaximize(false)
			.SupportsMinimize(false)
			[
				SNew(SVerticalBox)
				+SVerticalBox::Slot()
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(FText::FromString(TEXT("Hello from Slate")))
				]
			];

		IMainFrameModule& MainFrameModule = FModuleManager::LoadModuleChecked<IMainFrameModule>(TEXT("MainFrame"));

		if (MainFrameModule.GetParentWindow().IsValid())
		{
			FSlateApplication::Get().AddWindowAsNativeChild(CookbookWindow, MainFrameModule.GetParentWindow().ToSharedRef());
		}
		else
		{
			FSlateApplication::Get().AddWindow(CookbookWindow);
		}

	};
	void AddToolbarExtension(FToolBarBuilder &builder)
	{
		FSlateIcon IconBrush = FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.ViewOptions", "LevelEditor.ViewOptions.Small");

		builder.AddToolBarButton(FCookbookCommands::Get().MyButton, NAME_None, FText::FromString("My Button"), FText::FromString("Click me to display a message"), IconBrush, NAME_None);

	};
	void AddMenuExtension(FMenuBuilder &builder)
	{
		FSlateIcon IconBrush = FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.ViewOptions", "LevelEditor.ViewOptions.Small");

		builder.AddMenuEntry(FCookbookCommands::Get().MyButton);

	};
};