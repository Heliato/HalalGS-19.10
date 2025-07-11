#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_BannerEditorTile

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass BP_BannerEditorTile.BP_BannerEditorTile_C
// 0x0050 (0x0F60 - 0x0F10)
class UBP_BannerEditorTile_C final : public UFortPlayerProfileBannerEditorTile
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0F10(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UImage*                                 ColorImage;                                        // 0x0F18(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonWidgetSwitcherLegacy*            CommonWidgetSwitcher_0;                            // 0x0F20(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 IconImage;                                         // 0x0F28(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonLoadGuard*                       IconLoadGuard;                                     // 0x0F30(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Image_BannerEditBorder;                            // 0x0F38(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UNormalBangWrapper_C*                   NormalBangWrapper;                                 // 0x0F40(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMaterialInstanceDynamic*               ColorMID;                                          // 0x0F48(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	FMulticastInlineDelegateProperty_             BannerTileBangUpdated;                             // 0x0F50(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)

public:
	void BannerTileBangUpdated__DelegateSignature();
	void BP_OnHovered();
	void BP_OnSelected();
	void Construct();
	void ExecuteUbergraph_BP_BannerEditorTile(int32 EntryPoint);
	void HandleBannerIconLoadGuardFinished(class UObject* Object);
	void Mark_Item_As_Seen();
	void OnListItemObjectSet(class UObject* ListItemObject);
	void Update_Bang_State();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_BannerEditorTile_C">();
	}
	static class UBP_BannerEditorTile_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UBP_BannerEditorTile_C>();
	}
};

}

