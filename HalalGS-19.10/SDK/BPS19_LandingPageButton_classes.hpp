#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BPS19_LandingPageButton

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "CoreUObject_structs.hpp"
#include "Slate_structs.hpp"
#include "BattlePassBase_classes.hpp"
#include "UMG_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass BPS19_LandingPageButton.BPS19_LandingPageButton_C
// 0x00E0 (0x1020 - 0x0F40)
class UBPS19_LandingPageButton_C final : public UBattlePassLandingPageButton
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0F40(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       burst;                                             // 0x0F48(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Intro;                                             // 0x0F50(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Selected;                                          // 0x0F58(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class USpacer*                                ExtraSpace;                                        // 0x0F60(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Image;                                             // 0x0F68(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Image_32;                                          // 0x0F70(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Image_Background;                                  // 0x0F78(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Image_Disabled;                                    // 0x0F80(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Image_Lock_Purple;                                 // 0x0F88(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Image_selected_LR;                                 // 0x0F90(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Image_selected_TB;                                 // 0x0F98(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonRichTextBlock*                   RichText_Title;                                    // 0x0FA0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonVisibilitySwitcher*              Switcher_locked;                                   // 0x0FA8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class FText                                   Title_Text;                                        // 0x0FB0(0x0018)(Edit, BlueprintVisible)
	ETextJustify                                  Justification;                                     // 0x0FC8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)
	uint8                                         Pad_FC9[0x7];                                      // 0x0FC9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UMaterialInterface*                     Material;                                          // 0x0FD0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)
	struct FVector2D                              In_Size;                                           // 0x0FD8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Extra_Space;                                       // 0x0FE0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)
	bool                                          IsLocked;                                          // 0x0FE4(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)
	uint8                                         Pad_FE5[0x3];                                      // 0x0FE5(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   Empty_text;                                        // 0x0FE8(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)
	bool                                          TimeGated;                                         // 0x1000(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)
	uint8                                         Pad_1001[0x7];                                     // 0x1001(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   Text_SubscriptionOwned;                            // 0x1008(0x0018)(Edit, BlueprintVisible, ExposeOnSpawn)

public:
	void BP_OnHovered();
	void BP_OnUnhovered();
	void ExecuteUbergraph_BPS19_LandingPageButton(int32 EntryPoint);
	void OnInitialized();
	void OnSubscriptionOwnershipUpdated(const bool bOwnsSubsciption);
	void OnSubscriptionTextureLoaded(class UTexture2D* Texture);
	void Play_intro();
	void PreConstruct(bool IsDesignTime);
	void SetPageDelayed(bool IsDelayed);
	void SetPageLocked(bool Param_IsLocked);
	void UpdateStatusIcons();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BPS19_LandingPageButton_C">();
	}
	static class UBPS19_LandingPageButton_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UBPS19_LandingPageButton_C>();
	}
};

}

