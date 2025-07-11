#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_SkewedTabButton

#include "Basic.hpp"

#include "FortniteUI_classes.hpp"
#include "CoreUObject_structs.hpp"
#include "Engine_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass BP_SkewedTabButton.BP_SkewedTabButton_C
// 0x0040 (0x0F60 - 0x0F20)
class UBP_SkewedTabButton_C final : public UAthenaSkewedTabButton
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0F20(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       Unhovered;                                         // 0x0F28(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Hovered;                                           // 0x0F30(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Selected;                                          // 0x0F38(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UImage*                                 NoMinusCountMinus1;                                // 0x0F40(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	struct FLinearColor                           RGB1_Text_Color;                                   // 0x0F48(0x0010)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)

public:
	void PreConstruct(bool IsDesignTime);
	void ExecuteUbergraph_BP_SkewedTabButton(int32 EntryPoint);
	void BP_OnUnhovered();
	void BP_OnSelected();
	void BP_OnHovered();
	void BP_OnDeselected();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_SkewedTabButton_C">();
	}
	static class UBP_SkewedTabButton_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UBP_SkewedTabButton_C>();
	}
};

}

