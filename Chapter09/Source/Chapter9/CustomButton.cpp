// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter9.h"
#include "CustomButton.h"

void SCustomButton::Construct(const FArguments& InArgs)
{
	Label = InArgs._Label;
	ButtonClicked = InArgs._ButtonClicked;
	ChildSlot.VAlign(VAlign_Center)
	.HAlign(HAlign_Center)
	[SNew(SButton)
	.OnClicked(ButtonClicked)
	.Content()
		[
			SNew(STextBlock)
			.Text_Lambda([this] {return FText::FromString(Label.Get()); })
		]
	];
}
