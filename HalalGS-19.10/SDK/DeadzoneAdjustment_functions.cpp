#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: DeadzoneAdjustment

#include "Basic.hpp"

#include "DeadzoneAdjustment_classes.hpp"
#include "DeadzoneAdjustment_parameters.hpp"


namespace SDK
{

// Function DeadzoneAdjustment.DeadzoneAdjustment_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UDeadzoneAdjustment_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DeadzoneAdjustment_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function DeadzoneAdjustment.DeadzoneAdjustment_C.DoCustomNavigation_0
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// EUINavigation                           Param_Navigation                                       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UWidget*                          ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

class UWidget* UDeadzoneAdjustment_C::DoCustomNavigation_0(EUINavigation Param_Navigation)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DeadzoneAdjustment_C", "DoCustomNavigation_0");

	Params::DeadzoneAdjustment_C_DoCustomNavigation_0 Parms{};

	Parms.Param_Navigation = Param_Navigation;

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function DeadzoneAdjustment.DeadzoneAdjustment_C.ExecuteUbergraph_DeadzoneAdjustment
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UDeadzoneAdjustment_C::ExecuteUbergraph_DeadzoneAdjustment(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DeadzoneAdjustment_C", "ExecuteUbergraph_DeadzoneAdjustment");

	Params::DeadzoneAdjustment_C_ExecuteUbergraph_DeadzoneAdjustment Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function DeadzoneAdjustment.DeadzoneAdjustment_C.OnValueChanged_Bind
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Value                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UDeadzoneAdjustment_C::OnValueChanged_Bind(float Value)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DeadzoneAdjustment_C", "OnValueChanged_Bind");

	Params::DeadzoneAdjustment_C_OnValueChanged_Bind Parms{};

	Parms.Value = Value;

	UObject::ProcessEvent(Func, &Parms);
}

}

