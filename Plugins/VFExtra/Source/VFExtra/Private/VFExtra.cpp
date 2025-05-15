// Copyright Epic Games, Inc. All Rights Reserved.

#include "VFExtra.h"
#include "VFExtraStyle.h"
#include "VFExtraCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"
#include "Engine.h"


// temp for euw
#include "EditorUtilityWidgetBlueprint.h"
#include "EditorUtilitySubsystem.h"
#include "EditorAssetLibrary.h"

static const FName VFExtraTabName("VFExtra");

#define LOCTEXT_NAMESPACE "FVFExtraModule"

void FVFExtraModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FVFExtraStyle::Initialize();
	FVFExtraStyle::ReloadTextures();

	FVFExtraCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FVFExtraCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FVFExtraModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FVFExtraModule::RegisterMenus));
}

void FVFExtraModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FVFExtraStyle::Shutdown();

	FVFExtraCommands::Unregister();
}

void FVFExtraModule::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	/*FText DialogText = FText::Format(
							LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
							FText::FromString(TEXT("FVFExtraModule::PluginButtonClicked()")),
							FText::FromString(TEXT("VFExtra.cpp"))
					   );
	*/
	//FMessageDialog::Open(EAppMsgType::Ok, DialogText);

	UE_LOG(LogTemp, Warning, TEXT("Opening Toolbox"));
	UObject* Toolbox = UEditorAssetLibrary::LoadAsset(FString(TEXT("/VFExtra/00_Base/BP/VFExtra_Toolbox_C")));
	if (IsValid(Toolbox)) {
		UEditorUtilityWidgetBlueprint* EditorWidget = Cast<UEditorUtilityWidgetBlueprint>(Toolbox);
		if (IsValid(EditorWidget)) {
			UEditorUtilitySubsystem* EditorUtilitySubsystem = GEditor->GetEditorSubsystem<UEditorUtilitySubsystem>();
			EditorUtilitySubsystem->SpawnAndRegisterTab(EditorWidget);
			UE_LOG(LogTemp, Warning, TEXT("Opened Toolbox"));
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("Cannot Cast"));
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Toolbox Invalid"));
	}

}

void FVFExtraModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FVFExtraCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FVFExtraCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FVFExtraModule, VFExtra)