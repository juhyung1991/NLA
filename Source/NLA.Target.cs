// CopyRight Nolla NLA

using UnrealBuildTool;
using System.Collections.Generic;

public class NLATarget : TargetRules
{
	public NLATarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "NLA" } );
	}
}
