using UnrealBuildTool;

public class Lets_open_DoorsClientTarget : TargetRules
{
	public Lets_open_DoorsClientTarget(TargetInfo Target) : base(Target)
	{
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		Type = TargetType.Client;
		ExtraModuleNames.Add("Lets_open_Doors");
	}
}
