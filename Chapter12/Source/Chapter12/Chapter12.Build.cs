// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class Chapter12 : ModuleRules
{
	public Chapter12(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore",
      "Landscape", "LandscapeEditor", "HTTP", "Foliage", "UnrealEd",
      "GameplayAbilities", "GameplayTags", "GameplayTasks",
      "Networking", "Sockets",
      "Messaging", "MessagingRPC","UMG" });

    PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");
		// if ((Target.Platform == UnrealTargetPlatform.Win32) || (Target.Platform == UnrealTargetPlatform.Win64))
		// {
		//		if (UEBuildConfiguration.bCompileSteamOSS == true)
		//		{
		//			DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
		//		}
		// }
	}
}
