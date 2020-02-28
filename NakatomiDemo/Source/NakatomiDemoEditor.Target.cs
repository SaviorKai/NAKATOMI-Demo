// Copyright by Ivan Engelbrecht 2020. All Rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class NakatomiDemoEditorTarget : TargetRules
{
	public NakatomiDemoEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "NakatomiDemo" } );
	}
}
