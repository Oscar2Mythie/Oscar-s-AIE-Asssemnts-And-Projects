using UnrealBuildTool;

public class Lets_open_DoorsServerTarget : TargetRules
{
	public Lets_open_DoorsServerTarget(TargetInfo Target) : base(Target)
	{
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		Type = TargetType.Server;
		ExtraModuleNames.Add("Lets_open_Doors");
	}
}
