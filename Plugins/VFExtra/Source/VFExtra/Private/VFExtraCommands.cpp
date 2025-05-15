// Copyright Epic Games, Inc. All Rights Reserved.

#include "VFExtraCommands.h"

#define LOCTEXT_NAMESPACE "FVFExtraModule"

void FVFExtraCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "VFExtra", "Execute VFExtra action", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
