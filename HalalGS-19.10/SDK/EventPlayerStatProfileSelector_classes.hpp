#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: EventPlayerStatProfileSelector

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass EventPlayerStatProfileSelector.EventPlayerStatProfileSelector_C
// 0x0040 (0x04F8 - 0x04B8)
class UEventPlayerStatProfileSelector_C final : public UFortEventPlayerStatProfileSelector
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x04B8(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       Intro;                                             // 0x04C0(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UIconTextButton_C*                      CloseMainPanel;                                    // 0x04C8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonBorder*                          CommonBorder_0;                                    // 0x04D0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Image_Background;                                  // 0x04D8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USafeZone*                              SafeZone_0;                                        // 0x04E0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWidgetSwitcher*                        Switcher_Content;                                  // 0x04E8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       Text_WindowTitle;                                  // 0x04F0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void BndEvt__CloseMainPanel_K2Node_ComponentBoundEvent_0_CommonButtonClicked__DelegateSignature(class UCommonButtonLegacy* Button);
	void BP_OnActivated();
	void ExecuteUbergraph_EventPlayerStatProfileSelector(int32 EntryPoint);
	void Set_Up_Profile_Selector_Style(const struct FFortTournamentDisplayInfo& Tournament_Display_Info);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"EventPlayerStatProfileSelector_C">();
	}
	static class UEventPlayerStatProfileSelector_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UEventPlayerStatProfileSelector_C>();
	}
};

}

