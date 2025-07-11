#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TabAudioOptions_New

#include "Basic.hpp"

#include "TabAudioOptions_New_classes.hpp"
#include "TabAudioOptions_New_parameters.hpp"


namespace SDK
{

// Function TabAudioOptions_New.TabAudioOptions_New_C.CenterOnTab
// (Event, Protected, BlueprintCallable, BlueprintEvent)

void UTabAudioOptions_New_C::CenterOnTab()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TabAudioOptions_New_C", "CenterOnTab");

	UObject::ProcessEvent(Func, nullptr);
}


// Function TabAudioOptions_New.TabAudioOptions_New_C.ExecuteUbergraph_TabAudioOptions_New
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UTabAudioOptions_New_C::ExecuteUbergraph_TabAudioOptions_New(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TabAudioOptions_New_C", "ExecuteUbergraph_TabAudioOptions_New");

	Params::TabAudioOptions_New_C_ExecuteUbergraph_TabAudioOptions_New Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function TabAudioOptions_New.TabAudioOptions_New_C.SettingValueChanged
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Value                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UTabAudioOptions_New_C::SettingValueChanged(float Value)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TabAudioOptions_New_C", "SettingValueChanged");

	Params::TabAudioOptions_New_C_SettingValueChanged Parms{};

	Parms.Value = Value;

	UObject::ProcessEvent(Func, &Parms);
}

}

