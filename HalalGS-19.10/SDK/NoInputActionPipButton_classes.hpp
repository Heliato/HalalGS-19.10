#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: NoInputActionPipButton

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteUI_classes.hpp"
#include "UMG_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass NoInputActionPipButton.NoInputActionPipButton_C
// 0x0030 (0x0FC0 - 0x0F90)
class UNoInputActionPipButton_C final : public UFortTextButton
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0F90(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       Hover;                                             // 0x0F98(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Selected;                                          // 0x0FA0(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UImage*                                 BacchusMobileShadow;                               // 0x0FA8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 PIP;                                               // 0x0FB0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void BP_OnDeselected();
	void BP_OnSelected();
	void Construct();
	void ExecuteUbergraph_NoInputActionPipButton(int32 EntryPoint);
	void PreConstruct(bool IsDesignTime);
	void Set_Pip_Colors(const struct FLinearColor& Base_Color, const struct FLinearColor& Hover_Color, const struct FLinearColor& Select_Color);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"NoInputActionPipButton_C">();
	}
	static class UNoInputActionPipButton_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UNoInputActionPipButton_C>();
	}
};

}

