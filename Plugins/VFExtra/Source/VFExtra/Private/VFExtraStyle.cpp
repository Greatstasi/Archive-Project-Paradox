// Copyright Epic Games, Inc. All Rights Reserved.

#include "VFExtraStyle.h"
#include "VFExtra.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FVFExtraStyle::StyleInstance = nullptr;

void FVFExtraStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FVFExtraStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FVFExtraStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("VFExtraStyle"));
	return StyleSetName;
}


const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FVFExtraStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("VFExtraStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("VFExtra")->GetBaseDir() / TEXT("Resources"));

	Style->Set("VFExtra.PluginAction", new IMAGE_BRUSH_SVG(TEXT("VFExtraLogoSVG"), Icon20x20));
	return Style;
}

void FVFExtraStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FVFExtraStyle::Get()
{
	return *StyleInstance;
}
