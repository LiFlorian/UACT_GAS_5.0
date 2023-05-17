// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UACT_GAS : ModuleRules
{
	public UACT_GAS(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
