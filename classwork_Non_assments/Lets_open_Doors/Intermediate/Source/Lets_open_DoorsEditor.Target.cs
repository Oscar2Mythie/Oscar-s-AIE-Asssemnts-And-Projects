using UnrealBuildTool;

public class Lets_open_DoorsEditorTarget : TargetRules
{
	public Lets_open_DoorsEditorTarget(TargetInfo Target) : base(Target)
	{
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		Type = TargetType.Editor;
		ExtraModuleNames.Add("Lets_open_Doors");
	}
}
