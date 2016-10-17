// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "AssetTypeActions_Base.h"
/**
 * 
 */
class CHAPTER8EDITOR_API FMyCustomAssetActions: public FAssetTypeActions_Base
{
public:
	

	virtual bool HasActions(const TArray<UObject*>& InObjects) const override;


	virtual void GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder) override;

	void MyCustomAssetContext_Clicked()
	{
		TSharedRef<SWindow> CookbookWindow = SNew(SWindow)
			.Title(FText::FromString(TEXT("Cookbook Window")))
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

	};


	virtual FText GetName() const override;


	virtual UClass* GetSupportedClass() const override;


	virtual FColor GetTypeColor() const override;

/*

	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>()) override;
*/


	virtual uint32 GetCategories() override;
};
