#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: EnumOptionExtension

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass EnumOptionExtension.EnumOptionExtension_C
// 0x0010 (0x0260 - 0x0250)
class UEnumOptionExtension_C final : public UFortSettingDetailExtension
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0250(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UDynamicEntryBox*                       EnumOptions;                                       // 0x0258(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_EnumOptionExtension(int32 EntryPoint);
	void OnSettingAssigned(class UFortSetting* InSetting);
	void OnSettingValueChanged(class UFortSetting* InSetting);
	void RebuildOptions(class UObject* Param_Setting);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"EnumOptionExtension_C">();
	}
	static class UEnumOptionExtension_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UEnumOptionExtension_C>();
	}
};

}

