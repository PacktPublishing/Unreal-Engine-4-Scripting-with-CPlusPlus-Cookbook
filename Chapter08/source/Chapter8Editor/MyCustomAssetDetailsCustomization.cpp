#include "UE4CookbookEditor.h"
#include "IDetailsView.h"
#include "DetailLayoutBuilder.h"
#include "DetailCategoryBuilder.h"
#include "SColorPicker.h"
#include "SBoxPanel.h"
#include "DetailWidgetRow.h"
#include "MyCustomAssetDetailsCustomization.h"
#include "IDetailChildrenBuilder.h"
#include "PropertyHandle.h"
#include "IDetailPropertyRow.h"

void FMyCustomAssetDetailsCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	const TArray< TWeakObjectPtr<UObject> >& SelectedObjects = DetailBuilder.GetDetailsView().GetSelectedObjects();

	for (int32 ObjectIndex = 0; !MyAsset.IsValid() && ObjectIndex < SelectedObjects.Num(); ++ObjectIndex)
	{
		const TWeakObjectPtr<UObject>& CurrentObject = SelectedObjects[ObjectIndex];
		if (CurrentObject.IsValid())
		{
			MyAsset = Cast<UMyCustomAsset>(CurrentObject.Get());
		}
	}
	DetailBuilder.EditCategory("CustomCategory", FText::GetEmpty(), ECategoryPriority::Important)
.AddCustomRow(FText::GetEmpty())
	[
	SNew(SVerticalBox)
	+ SVerticalBox::Slot()
	.VAlign(VAlign_Center)
		[
			SNew(SColorPicker)
			.OnColorCommitted(this, &FMyCustomAssetDetailsCustomization::ColorPicked)
		]
	];
}

void FMyCustomAssetDetailsCustomization::ColorPicked(FLinearColor SelectedColor)
{
	if (MyAsset.IsValid())
	{
		MyAsset.Get()->ColorName = SelectedColor.ToFColor(false).ToHex();
	}
}

void FMyCustomAssetPropertyDetails::CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils)
{
/*
	MyAsset = nullptr;
		//MyAsset = Cast<UMyCustomAsset>(Test);
	if (MyAsset)
	{
		ChildBuilder.AddChildProperty(PropertyHandle).CustomWidget(true)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
			.VAlign(VAlign_Center)
			[
			]
			];
	}
	*/
}

void FMyCustomAssetPropertyDetails::CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils)
{

	
	UObject* PropertyValue = nullptr;
	auto GetValueResult = PropertyHandle->GetValue(PropertyValue);

	HeaderRow.NameContent()
		[
			PropertyHandle->CreatePropertyNameWidget()
		];
	HeaderRow.ValueContent()
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.VAlign(VAlign_Center)
			[
				SNew(SColorPicker)
				.OnColorCommitted(this, &FMyCustomAssetPropertyDetails::ColorPicked)
			]
		];
}
void FMyCustomAssetPropertyDetails::ColorPicked(FLinearColor SelectedColor)
{
	if (MyAsset)
	{
		MyAsset->ColorName = SelectedColor.ToFColor(false).ToHex();
	}
}