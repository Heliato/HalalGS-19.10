#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CrewPurchase_RewardTile

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "CrewUI_classes.hpp"
#include "UMG_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass CrewPurchase_RewardTile.CrewPurchase_RewardTile_C
// 0x0040 (0x0F50 - 0x0F10)
class UCrewPurchase_RewardTile_C final : public UCrewRewardTile
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0F10(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       HoverScale;                                        // 0x0F18(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Hover;                                             // 0x0F20(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UImage*                                 Image_check;                                       // 0x0F28(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Image_EdgeSlant;                                   // 0x0F30(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Image_Frame;                                       // 0x0F38(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Image_Pulse;                                       // 0x0F40(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Image_Shadow;                                      // 0x0F48(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void OnUpdateOwnedState(bool bOwned);
	void OnStartingDownloadTileImage();
	void OnDownloadTileImageComplete(class UTexture2D* Texture);
	void ExecuteUbergraph_CrewPurchase_RewardTile(int32 EntryPoint);
	void Construct();
	void BP_OnSelected();
	void BP_OnDeselected();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"CrewPurchase_RewardTile_C">();
	}
	static class UCrewPurchase_RewardTile_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCrewPurchase_RewardTile_C>();
	}
};

}

