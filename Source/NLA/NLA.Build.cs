// CopyRight Nolla NLA

using UnrealBuildTool;

public class NLA : ModuleRules
{
	public NLA(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "GameplayAbilities" });

		PrivateDependencyModuleNames.AddRange(new string[] { "GameplayTags", "GameplayTasks" });

        PrivateIncludePaths.AddRange(new string[] {
            "NLA",
            "NLA/Character",
            "NLA/Game",
            "NLA/Interaction",
            "NLA/Player",
            "NLA/AbilitySystem"

        });


        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
