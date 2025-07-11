#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PlayerSurveyVerticalIndicator

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "UMG_structs.hpp"
#include "UMG_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass PlayerSurveyVerticalIndicator.PlayerSurveyVerticalIndicator_C
// 0x0010 (0x0258 - 0x0248)
class UPlayerSurveyVerticalIndicator_C final : public UUserWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0248(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UCommonActionWidget*                    InputActionWidget_Move;                            // 0x0250(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void BndEvt__InputActionWidget_Move_K2Node_ComponentBoundEvent_0_OnInputMethodChanged__DelegateSignature(bool bUsingGamepad);
	void ExecuteUbergraph_PlayerSurveyVerticalIndicator(int32 EntryPoint);
	void UpdateGamepadControlsVisibility();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PlayerSurveyVerticalIndicator_C">();
	}
	static class UPlayerSurveyVerticalIndicator_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPlayerSurveyVerticalIndicator_C>();
	}
};

}

