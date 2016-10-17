#include "UE4CookbookEditor.h"
#include "SColorPicker.h"
#include "SGraphPinCustomAsset.h"


void SGraphPinCustomAsset::Construct(const FArguments& InArgs, UEdGraphPin* InPin)
{
	SGraphPin::Construct(SGraphPin::FArguments(), InPin);
}

TSharedRef<SWidget> SGraphPinCustomAsset::GetDefaultValueWidget()
{
	return SNew(SColorPicker)
		.OnColorCommitted(this, &SGraphPinCustomAsset::ColorPicked);

}

void SGraphPinCustomAsset::ColorPicked(FLinearColor SelectedColor)
{
	UMyCustomAsset* NewValue = NewObject<UMyCustomAsset>();
	NewValue->ColorName = SelectedColor.ToFColor(false).ToHex();
	GraphPinObj->GetSchema()->TrySetDefaultObject(*GraphPinObj, NewValue);
}