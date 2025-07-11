#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: EmergencyNoticeWidgetBR

#include "Basic.hpp"

#include "SlateCore_structs.hpp"
#include "Engine_structs.hpp"
#include "FortniteUI_classes.hpp"
#include "Slate_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass EmergencyNoticeWidgetBR.EmergencyNoticeWidgetBR_C
// 0x0030 (0x02A8 - 0x0278)
class UEmergencyNoticeWidgetBR_C final : public UEmergencyNoticeBase
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0278(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       Entrance;                                          // 0x0280(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UCommonTextBlock*                       BodyText;                                          // 0x0288(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UHorizontalBox*                         HB_Content;                                        // 0x0290(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       TitleText;                                         // 0x0298(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USizeBox*                               VisibilitySB;                                      // 0x02A0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void Construct();
	void ExecuteUbergraph_EmergencyNoticeWidgetBR(int32 EntryPoint);
	void HideNotice();
	void Show_Notice();
	void ShowNotice(const class FText& Title, const class FText& Body);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"EmergencyNoticeWidgetBR_C">();
	}
	static class UEmergencyNoticeWidgetBR_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UEmergencyNoticeWidgetBR_C>();
	}
};

}

