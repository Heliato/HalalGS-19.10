#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SettingsRotator_Narrow

#include "Basic.hpp"

#include "SettingsRotator_Narrow_classes.hpp"
#include "SettingsRotator_Narrow_parameters.hpp"


namespace SDK
{

// Function SettingsRotator_Narrow.SettingsRotator_Narrow_C.BP_OnDefaultOptionSpecified
// (Event, Protected, BlueprintEvent)
// Parameters:
// int32                                   DefaultOptionIndex                                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void USettingsRotator_Narrow_C::BP_OnDefaultOptionSpecified(int32 DefaultOptionIndex)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SettingsRotator_Narrow_C", "BP_OnDefaultOptionSpecified");

	Params::SettingsRotator_Narrow_C_BP_OnDefaultOptionSpecified Parms{};

	Parms.DefaultOptionIndex = DefaultOptionIndex;

	UObject::ProcessEvent(Func, &Parms);
}


// Function SettingsRotator_Narrow.SettingsRotator_Narrow_C.BP_OnOptionSelected
// (Event, Protected, BlueprintEvent)
// Parameters:
// int32                                   Param_Index                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void USettingsRotator_Narrow_C::BP_OnOptionSelected(int32 Param_Index)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SettingsRotator_Narrow_C", "BP_OnOptionSelected");

	Params::SettingsRotator_Narrow_C_BP_OnOptionSelected Parms{};

	Parms.Param_Index = Param_Index;

	UObject::ProcessEvent(Func, &Parms);
}


// Function SettingsRotator_Narrow.SettingsRotator_Narrow_C.BP_OnOptionsPopulated
// (Event, Protected, BlueprintEvent)
// Parameters:
// int32                                   Count                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void USettingsRotator_Narrow_C::BP_OnOptionsPopulated(int32 Count)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SettingsRotator_Narrow_C", "BP_OnOptionsPopulated");

	Params::SettingsRotator_Narrow_C_BP_OnOptionsPopulated Parms{};

	Parms.Count = Count;

	UObject::ProcessEvent(Func, &Parms);
}


// Function SettingsRotator_Narrow.SettingsRotator_Narrow_C.ExecuteUbergraph_SettingsRotator_Narrow
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void USettingsRotator_Narrow_C::ExecuteUbergraph_SettingsRotator_Narrow(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SettingsRotator_Narrow_C", "ExecuteUbergraph_SettingsRotator_Narrow");

	Params::SettingsRotator_Narrow_C_ExecuteUbergraph_SettingsRotator_Narrow Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function SettingsRotator_Narrow.SettingsRotator_Narrow_C.OnHover Animation
// (BlueprintCallable, BlueprintEvent)

void USettingsRotator_Narrow_C::OnHover_Animation()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SettingsRotator_Narrow_C", "OnHover Animation");

	UObject::ProcessEvent(Func, nullptr);
}


// Function SettingsRotator_Narrow.SettingsRotator_Narrow_C.OnUnHover Animation
// (BlueprintCallable, BlueprintEvent)

void USettingsRotator_Narrow_C::OnUnHover_Animation()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SettingsRotator_Narrow_C", "OnUnHover Animation");

	UObject::ProcessEvent(Func, nullptr);
}

}

