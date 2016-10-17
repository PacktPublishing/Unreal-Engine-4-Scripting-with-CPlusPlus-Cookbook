#include "UE4CookbookEditor.h"
#include "LevelEditor.h"
#include "SlateBasics.h"
#include "MultiBoxExtender.h"
#include "MyCustomAssetActions.h"
#include "AssetToolsModule.h"
#include "CookbookCommands.h"
#include "MyCustomAsset.h"
#include "MyCustomAssetDetailsCustomization.h"
IMPLEMENT_GAME_MODULE(FUE4CookbookEditorModule, UE4CookbookEditor)

void FUE4CookbookEditorModule::StartupModule()
{
	FCookbookCommands::Register();
	TSharedPtr<FUICommandList> CommandList = MakeShareable(new FUICommandList());
	CommandList->MapAction(FCookbookCommands::Get().MyButton, FExecuteAction::CreateRaw(this, &FUE4CookbookEditorModule::MyButton_Clicked), FCanExecuteAction());
	ToolbarExtender = MakeShareable(new FExtender());
	Extension = ToolbarExtender->AddToolBarExtension("Compile", EExtensionHook::Before, CommandList, FToolBarExtensionDelegate::CreateRaw(this, &FUE4CookbookEditorModule::AddToolbarExtension));
	
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	

	LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);

	ToolbarExtender->AddMenuExtension("LevelEditor", EExtensionHook::Before, CommandList, FMenuExtensionDelegate::CreateRaw(this, &FUE4CookbookEditorModule::AddMenuExtension));
	LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(ToolbarExtender);

	DisplayTestCommand = IConsoleManager::Get().RegisterConsoleCommand(TEXT("DisplayTestCommandWindow"), TEXT("test"), FConsoleCommandDelegate::CreateRaw(this, &FUE4CookbookEditorModule::DisplayWindow, FString(TEXT("Test Command Window"))), ECVF_Default);

	DisplayUserSpecifiedWindow = IConsoleManager::Get().RegisterConsoleCommand(TEXT("DisplayWindow"), TEXT("test"), FConsoleCommandWithArgsDelegate::CreateLambda(
		[&](const TArray< FString >& Args)
	{
		FString WindowTitle;
		for (FString Arg : Args)
		{
			WindowTitle +=Arg;
			WindowTitle.AppendChar(' ');
		}
		this->DisplayWindow(WindowTitle);
	}

		), ECVF_Default);



	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

	auto Actions =MakeShareable(new FMyCustomAssetActions);
	AssetTools.RegisterAssetTypeActions(Actions);
	CreatedAssetTypeActions.Add(Actions);

	PinFactory = MakeShareable(new FMyCustomAssetPinFactory());
	FEdGraphUtilities::RegisterVisualPinFactory(PinFactory);
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PropertyModule.RegisterCustomClassLayout(UMyCustomAsset::StaticClass()->GetFName(), FOnGetDetailCustomizationInstance::CreateStatic(&FMyCustomAssetDetailsCustomization::MakeInstance));
	PropertyModule.RegisterCustomPropertyTypeLayout(UMyCustomAsset::StaticClass()->GetFName(), FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FMyCustomAssetPropertyDetails::MakeInstance));

}

void FUE4CookbookEditorModule::ShutdownModule()
{
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

	for (auto Action : CreatedAssetTypeActions)
	{
		AssetTools.UnregisterAssetTypeActions(Action.ToSharedRef());
	}
	IConsoleManager::Get().UnregisterConsoleObject(DisplayTestCommand);
	DisplayTestCommand = nullptr;
	IConsoleManager::Get().UnregisterConsoleObject(DisplayUserSpecifiedWindow);
	DisplayUserSpecifiedWindow = nullptr;
	FEdGraphUtilities::UnregisterVisualPinFactory(PinFactory);
	PinFactory.Reset();
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PropertyModule.UnregisterCustomClassLayout(UMyCustomAsset::StaticClass()->GetFName());
	ToolbarExtender->RemoveExtension(Extension.ToSharedRef());
	Extension.Reset();
	ToolbarExtender.Reset();



}
