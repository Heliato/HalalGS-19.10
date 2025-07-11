#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SortAndFilterButton

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "CommonUILegacy_classes.hpp"
#include "UMG_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass SortAndFilterButton.SortAndFilterButton_C
// 0x0050 (0x0F50 - 0x0F00)
class USortAndFilterButton_C final : public UCommonButtonLegacy
{
public:
	uint8                                         Pad_EF8[0x8];                                      // 0x0EF8(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0F00(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       ShowPipOutline;                                    // 0x0F08(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Deselected;                                        // 0x0F10(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Selected;                                          // 0x0F18(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Hover;                                             // 0x0F20(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UCommonTextBlock*                       Text_ButtonAction;                                 // 0x0F28(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class FText                                   Button_Description;                                // 0x0F30(0x0018)(Edit, BlueprintVisible)
	bool                                          IsSelected;                                        // 0x0F48(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void SnapToEndOfAnimation(class UWidgetAnimation* Animation, EUMGSequencePlayMode PlayMode);
	void SetText(const class FText& Text);
	void ResetAnimations();
	void PreConstruct(bool IsDesignTime);
	void OnMouseLeave(const struct FPointerEvent& MouseEvent);
	void OnMouseEnter(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent);
	void ExecuteUbergraph_SortAndFilterButton(int32 EntryPoint);
	void Construct();
	void BP_OnSelected();
	void BP_OnDeselected();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"SortAndFilterButton_C">();
	}
	static class USortAndFilterButton_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<USortAndFilterButton_C>();
	}
};

}

