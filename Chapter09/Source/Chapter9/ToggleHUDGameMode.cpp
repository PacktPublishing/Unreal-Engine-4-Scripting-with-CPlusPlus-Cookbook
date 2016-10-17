// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter9.h"
#include "ToggleHUDGameMode.h"




void AToggleHUDGameMode::BeginPlay()
{
	Super::BeginPlay();
	widget = SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SButton)
			.Content()
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("Test button")))
		]
		];
	GEngine->GameViewport->AddViewportWidgetForPlayer(GetWorld()->GetFirstLocalPlayerFromController(), widget.ToSharedRef(), 1);

	GetWorld()->GetTimerManager().SetTimer(HUDToggleTimer, FTimerDelegate::CreateLambda
	([this] 
	{
		if (this->widget->GetVisibility().IsVisible())
		{
			this->widget->SetVisibility(EVisibility::Hidden);

		}
		else
		{
			this->widget->SetVisibility(EVisibility::Visible);
		}
	}), 5, true);
}

void AToggleHUDGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearTimer(HUDToggleTimer);
}
