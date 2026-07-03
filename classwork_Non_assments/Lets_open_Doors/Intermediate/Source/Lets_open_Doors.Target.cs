using UnrealBuildTool;

public class Lets_open_DoorsTarget : TargetRules
{
	public Lets_open_DoorsTarget(TargetInfo Target) : base(Target)
	{
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		Type = TargetType.Game;
		ExtraModuleNames.Add("Lets_open_Doors");
	}
}
