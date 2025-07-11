#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CosmeticLoadoutScreen

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteUI_structs.hpp"
#include "FortniteUI_classes.hpp"
#include "UMG_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass CosmeticLoadoutScreen.CosmeticLoadoutScreen_C
// 0x00B8 (0x0668 - 0x05B0)
class UCosmeticLoadoutScreen_C final : public UFortCosmeticLoadoutScreen
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x05B0(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       Intro;                                             // 0x05B8(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UVerticalBox*                           LeftSideButtons;                                   // 0x05C0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       NewPresetDisclaimerText;                           // 0x05C8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Panel;                                             // 0x05D0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       PresetHeader;                                      // 0x05D8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       RandomDisclaimertext;                              // 0x05E0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       SaveSubHeader;                                     // 0x05E8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USoloButton_C*                          XButton_DeleteLoadout;                             // 0x05F0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USoloButton_C*                          XButton_RenameLoadout;                             // 0x05F8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USimpleFeatured_YellowButton_C*         XSimpleFeatured_YellowButton;                      // 0x0600(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class FText                                   BrowseHeaderText;                                  // 0x0608(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)
	class FText                                   SaveHeaderText;                                    // 0x0620(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)
	class FText                                   ApplyButtonText;                                   // 0x0638(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)
	class FText                                   SaveButtonText;                                    // 0x0650(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)

public:
	void BP_OnActivated();
	void ExecuteUbergraph_CosmeticLoadoutScreen(int32 EntryPoint);
	void OnFlavorForScreenMode(EFortCosmeticLoadoutScreenMode NewMode);
	void OnPreviewTile(EFortLoadoutCardType CardType);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"CosmeticLoadoutScreen_C">();
	}
	static class UCosmeticLoadoutScreen_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCosmeticLoadoutScreen_C>();
	}
};

}

