#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SocialPanelWeGameFriendButton

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "CommonUILegacy_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass SocialPanelWeGameFriendButton.SocialPanelWeGameFriendButton_C
// 0x0020 (0x0F20 - 0x0F00)
class USocialPanelWeGameFriendButton_C final : public UCommonButtonLegacy
{
public:
	uint8                                         Pad_EF8[0x8];                                      // 0x0EF8(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0F00(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       OnHovered;                                         // 0x0F08(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UCommonTextBlock*                       Text_LinkPrompt;                                   // 0x0F10(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void BP_OnHovered();
	void BP_OnUnhovered();
	void ExecuteUbergraph_SocialPanelWeGameFriendButton(int32 EntryPoint);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"SocialPanelWeGameFriendButton_C">();
	}
	static class USocialPanelWeGameFriendButton_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<USocialPanelWeGameFriendButton_C>();
	}
};

}

