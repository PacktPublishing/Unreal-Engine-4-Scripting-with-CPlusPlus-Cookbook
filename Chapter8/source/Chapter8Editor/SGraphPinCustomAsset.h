#pragma once
#include "SGraphPin.h"


class CHAPTER8EDITOR_API SGraphPinCustomAsset : public SGraphPin
{
	SLATE_BEGIN_ARGS(SGraphPinCustomAsset) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, UEdGraphPin* InPin);
protected:
	virtual FSlateColor GetPinColor() const override { return FSlateColor(FColor::Black); };

	virtual TSharedRef<SWidget> GetDefaultValueWidget() override;
	
	void ColorPicked(FLinearColor SelectedColor);
};

