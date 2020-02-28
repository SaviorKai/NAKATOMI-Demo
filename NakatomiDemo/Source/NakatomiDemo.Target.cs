// Copyright by Ivan Engelbrecht 2020. All Rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class NakatomiDemoTarget : TargetRules
{
	public NakatomiDemoTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "NakatomiDemo" } );
	}
}
