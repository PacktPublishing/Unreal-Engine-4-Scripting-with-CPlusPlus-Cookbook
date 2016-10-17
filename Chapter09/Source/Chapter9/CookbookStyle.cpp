#include "Chapter9.h"
#include "CookbookStyle.h"


// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.


#include "SlateGameResources.h"

TSharedPtr< FSlateStyleSet > FCookbookStyle::CookbookStyleInstance = NULL;

void FCookbookStyle::Initialize()
{
	if (!CookbookStyleInstance.IsValid())
	{
		CookbookStyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*CookbookStyleInstance);
	}
}

void FCookbookStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*CookbookStyleInstance);
	ensure(CookbookStyleInstance.IsUnique());
	CookbookStyleInstance.Reset();
}

FName FCookbookStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("CookbookStyle"));
	return StyleSetName;
}

#define IMAGE_BRUSH( RelativePath, ... ) FSlateImageBrush( FPaths::GameContentDir() / "Slate"/ RelativePath + TEXT(".png"), __VA_ARGS__ )
#define BOX_BRUSH( RelativePath, ... ) FSlateBoxBrush( FPaths::GameContentDir() / "Slate"/ RelativePath + TEXT(".png"), __VA_ARGS__ )
#define BORDER_BRUSH( RelativePath, ... ) FSlateBorderBrush( FPaths::GameContentDir() / "Slate"/ RelativePath + TEXT(".png"), __VA_ARGS__ )
#define TTF_FONT( RelativePath, ... ) FSlateFontInfo( FPaths::GameContentDir() / "Slate"/ RelativePath + TEXT(".ttf"), __VA_ARGS__ )
#define OTF_FONT( RelativePath, ... ) FSlateFontInfo( FPaths::GameContentDir() / "Slate"/ RelativePath + TEXT(".otf"), __VA_ARGS__ )

TSharedRef< FSlateStyleSet > FCookbookStyle::Create()
{
	TSharedRef<FSlateStyleSet> StyleRef = FSlateGameResources::New(FCookbookStyle::GetStyleSetName(), "/Game/Slate", "/Game/Slate");
	FSlateStyleSet& Style = StyleRef.Get();

	Style.Set("NormalButtonBrush", 
		FButtonStyle().
		SetNormal(BOX_BRUSH("Button", FVector2D(54,54),FMargin(14.0f/54.0f))));
	Style.Set("NormalButtonText",
		FTextBlockStyle(FTextBlockStyle::GetDefault())
		.SetColorAndOpacity(FSlateColor(FLinearColor(1,1,1,1))));
	return StyleRef;
}

#undef IMAGE_BRUSH
#undef BOX_BRUSH
#undef BORDER_BRUSH
#undef TTF_FONT
#undef OTF_FONT

void FCookbookStyle::ReloadTextures()
{
	FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
}

const ISlateStyle& FCookbookStyle::Get()
{
	return *CookbookStyleInstance;
}

