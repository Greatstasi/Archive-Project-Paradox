// Fill out your copyright notice in the Description page of Project Settings.


#include "VFExtraBPLibrary.h"

FName UVFExtraBPLibrary::GetMaterialGroup(UMaterialInstanceDynamic* Material, FName parameterName)
{
	FName group;
	FMaterialParameterInfo parameterInfo = Material->GetParameterInfo(EMaterialParameterAssociation::GlobalParameter, parameterName, nullptr);
	Material->GetGroupName(parameterInfo, group);
	return group;
}