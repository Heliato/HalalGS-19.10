#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Sidebar

#include "Basic.hpp"

#include "FortniteUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass Sidebar.Sidebar_C
// 0x0078 (0x0490 - 0x0418)
class USidebar_C final : public UFortSocialPanelView_Sidebar
{
public:
	class USidebarProfile_C*                      Panel_Profile;                                     // 0x0418(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USafeZone*                              Safezone_OnboardingTooltip;                        // 0x0420(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USafeZone*                              SafeZone_SideBar;                                  // 0x0428(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class FText                                   Text_PartyUp;                                      // 0x0430(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)
	class FText                                   Text_FindFriends;                                  // 0x0448(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)
	class FText                                   Text_VoiceChat;                                    // 0x0460(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)
	class FText                                   Text_UserSettings;                                 // 0x0478(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Sidebar_C">();
	}
	static class USidebar_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<USidebar_C>();
	}
};

}

