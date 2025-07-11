#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ActivityBrowserSoloButton

#include "Basic.hpp"

#include "SlateCore_structs.hpp"
#include "Engine_structs.hpp"
#include "FortTextButton_classes.hpp"
#include "CommonInput_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass ActivityBrowserSoloButton.ActivityBrowserSoloButton_C
// 0x00C0 (0x1050 - 0x0F90)
class UActivityBrowserSoloButton_C final : public UFortTextButton_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0F90(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       Pressed;                                           // 0x0F98(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Hover;                                             // 0x0FA0(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UBorder*                                ButtonMaterialBorder;                              // 0x0FA8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UHorizontalBox*                         ContentHB;                                         // 0x0FB0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UBorder*                                DynamicPaddingBorder;                              // 0x0FB8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USizeBox*                               MinSizesSB;                                        // 0x0FC0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class FText                                   Button_Description;                                // 0x0FC8(0x0018)(Edit, BlueprintVisible)
	float                                         TextShearX;                                        // 0x0FE0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         TextShearY;                                        // 0x0FE4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FMargin                                TextPadding;                                       // 0x0FE8(0x0010)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          IsDisabled;                                        // 0x0FF8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_FF9[0x7];                                      // 0x0FF9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UMaterialInterface*                     ButtonMaterial;                                    // 0x1000(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         ButtonSharpnessX;                                  // 0x1008(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         ButtonSharpnessY;                                  // 0x100C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         UseBoxScalingX;                                    // 0x1010(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         UseBoxScalingY;                                    // 0x1014(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         ButtonBoxScaleSizeX;                               // 0x1018(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         ButtonBoxScaleSizeY;                               // 0x101C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   DisabledParamName;                                 // 0x1020(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   SharpnessVParamName;                               // 0x1028(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   SharpnessUParamName;                               // 0x1030(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   UseBoxScaleUParamName;                             // 0x1038(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   UseBoxScaleVParamName;                             // 0x1040(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          HideButtonBackingOnGamepad;                        // 0x1048(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void BP_OnClicked();
	void BP_OnDeselected();
	void BP_OnDisabled();
	void BP_OnEnabled();
	void BP_OnHovered();
	void BP_OnSelected();
	void BP_OnUnhovered();
	void Construct();
	void Destruct();
	void EventOnInputMethodChanged(ECommonInputType bNewInputType);
	void ExecuteUbergraph_ActivityBrowserSoloButton(int32 EntryPoint);
	void Finished_3B04A1D04A2128E7C8B3D5BC22792871();
	void PreConstruct(bool IsDesignTime);
	void ResetFontMaterial();
	void ResetMaterials();
	void SetButtonMaterial();
	void SetText(const class FText& Text);
	void SetTextStyle();
	void UpdateStylingOnInputType(ECommonInputType Param_Index);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"ActivityBrowserSoloButton_C">();
	}
	static class UActivityBrowserSoloButton_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UActivityBrowserSoloButton_C>();
	}
};

}

