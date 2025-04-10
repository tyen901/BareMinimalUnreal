// Copyright Epic Games, Inc. All Rights Reserved.

#include "SourceModule.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_MODULE(FSourceModule, SourceModule);

void FSourceModule::StartupModule()
{
	UE_LOG(LogTemp, Log, TEXT("SourceModule: Module started"));
}

void FSourceModule::ShutdownModule()
{
	UE_LOG(LogTemp, Log, TEXT("SourceModule: Module shut down"));
}