// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "VFExtraStyle.h"

class FVFExtraCommands : public TCommands<FVFExtraCommands>
{
public:

	FVFExtraCommands()
		: TCommands<FVFExtraCommands>(TEXT("VFExtra"), NSLOCTEXT("Contexts", "VFExtra", "VFExtra Plugin"), NAME_None, FVFExtraStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
