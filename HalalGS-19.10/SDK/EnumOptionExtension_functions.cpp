#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: EnumOptionExtension

#include "Basic.hpp"

#include "EnumOptionExtension_classes.hpp"
#include "EnumOptionExtension_parameters.hpp"


namespace SDK
{

// Function EnumOptionExtension.EnumOptionExtension_C.ExecuteUbergraph_EnumOptionExtension
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UEnumOptionExtension_C::ExecuteUbergraph_EnumOptionExtension(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EnumOptionExtension_C", "ExecuteUbergraph_EnumOptionExtension");

	Params::EnumOptionExtension_C_ExecuteUbergraph_EnumOptionExtension Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function EnumOptionExtension.EnumOptionExtension_C.OnSettingAssigned
// (Event, Protected, BlueprintEvent)
// Parameters:
// class UFortSetting*                     InSetting                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UEnumOptionExtension_C::OnSettingAssigned(class UFortSetting* InSetting)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EnumOptionExtension_C", "OnSettingAssigned");

	Params::EnumOptionExtension_C_OnSettingAssigned Parms{};

	Parms.InSetting = InSetting;

	UObject::ProcessEvent(Func, &Parms);
}


// Function EnumOptionExtension.EnumOptionExtension_C.OnSettingValueChanged
// (Event, Protected, BlueprintEvent)
// Parameters:
// class UFortSetting*                     InSetting                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UEnumOptionExtension_C::OnSettingValueChanged(class UFortSetting* InSetting)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EnumOptionExtension_C", "OnSettingValueChanged");

	Params::EnumOptionExtension_C_OnSettingValueChanged Parms{};

	Parms.InSetting = InSetting;

	UObject::ProcessEvent(Func, &Parms);
}


// Function EnumOptionExtension.EnumOptionExtension_C.RebuildOptions
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UObject*                          Param_Setting                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UEnumOptionExtension_C::RebuildOptions(class UObject* Param_Setting)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EnumOptionExtension_C", "RebuildOptions");

	Params::EnumOptionExtension_C_RebuildOptions Parms{};

	Parms.Param_Setting = Param_Setting;

	UObject::ProcessEvent(Func, &Parms);
}

}

