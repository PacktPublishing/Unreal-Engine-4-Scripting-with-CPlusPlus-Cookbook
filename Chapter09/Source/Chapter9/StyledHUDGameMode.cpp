// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter9.h"
#include "CookbookStyle.h"
#include "StyledHUDGameMode.h"


void AStyledHUDGameMode::BeginPlay()
{
	Super::BeginPlay();

	Widget = SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SButton)
			.ButtonStyle(FCookbookStyle::Get(), "NormalButtonBrush")
		.ContentPadding(FMargin(16))
		.Content()
		[
			SNew(STextBlock)
			.TextStyle(FCookbookStyle::Get(), "NormalButtonText")
		.Text(FText::FromString("Styled Button"))
		]
		];
	GEngine->GameViewport->AddViewportWidgetForPlayer(GetWorld()->GetFirstLocalPlayerFromController(), Widget.ToSharedRef(), 1);

}




