// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Materials/MaterialInterface.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/ExpandableArea.h"
#include "Components/Widget.h"
#include "VFExtraBPLibrary.generated.h"


/**
 * 
 */
UCLASS()
class VFEXTRA_API UVFExtraBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	

	UFUNCTION(BlueprintCallable, Category = "VFE")
	static FName GetMaterialGroup(UMaterialInstanceDynamic* Material, FName parameterName);

};
