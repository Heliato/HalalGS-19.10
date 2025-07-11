#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BPS19_BattlePassRewardPage

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "BattlePassS19UI_classes.hpp"
#include "CommonInput_structs.hpp"
#include "FortniteUI_structs.hpp"
#include "UMG_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass BPS19_BattlePassRewardPage.BPS19_BattlePassRewardPage_C
// 0x0040 (0x04F0 - 0x04B0)
class UBPS19_BattlePassRewardPage_C final : public UBattlePassRewardPageS19
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x04B0(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       Intro;                                             // 0x04B8(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Header_intro;                                      // 0x04C0(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UImage*                                 Image_85;                                          // 0x04C8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USafeZone*                              SafeZone_0;                                        // 0x04D0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       Subtitle;                                          // 0x04D8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       Title;                                             // 0x04E0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UVerticalBox*                           VerticalBox_23;                                    // 0x04E8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void BP_OnActivated();
	void ExecuteUbergraph_BPS19_BattlePassRewardPage(int32 EntryPoint);
	void OnInitForPageType(const ERewardPageType InRewardPageType);
	void OnInputMethodChanged(const ECommonInputType InputType);
	void OnPageChanged(const int32 PageNumber);
	void PageNavigator_Event_0(class UPageNavigator_C* Param_PageNavigator);
	void SequenceEvent__ENTRYPOINTBPS19_BattlePassRewardPage_0(class UPageNavigator_C* Param_PageNavigator);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BPS19_BattlePassRewardPage_C">();
	}
	static class UBPS19_BattlePassRewardPage_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UBPS19_BattlePassRewardPage_C>();
	}
};

}

