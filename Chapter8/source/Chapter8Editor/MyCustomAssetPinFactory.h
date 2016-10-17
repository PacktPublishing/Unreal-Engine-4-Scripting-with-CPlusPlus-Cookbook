#pragma once
#include "EdGraphUtilities.h"
#include "MyCustomAsset.h"
#include "SGraphPinCustomAsset.h"


struct CHAPTER8EDITOR_API FMyCustomAssetPinFactory : public FGraphPanelPinFactory
{
public:
	virtual TSharedPtr<class SGraphPin> CreatePin(class UEdGraphPin* Pin) const override 
	{
		if (Pin->PinType.PinSubCategoryObject == UMyCustomAsset::StaticClass())
		{
			return SNew(SGraphPinCustomAsset, Pin);
		}
		else
		{
			return nullptr;
		}
	};
};


