// CopyRight Nolla NLA

using UnrealBuildTool;
using System.Collections.Generic;

public class NLAEditorTarget : TargetRules
{
	public NLAEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "NLA" } );
	}
}
