#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: HousepartyWelcomeToast

#include "Basic.hpp"

#include "HousepartyWelcomeToast_classes.hpp"
#include "HousepartyWelcomeToast_parameters.hpp"


namespace SDK
{

// Function HousepartyWelcomeToast.HousepartyWelcomeToast_C.OnSetToast
// (Event, Protected, BlueprintEvent)
// Parameters:
// class UFortUINotification*              ToastNotification                                      (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UHousepartyWelcomeToast_C::OnSetToast(class UFortUINotification* ToastNotification)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HousepartyWelcomeToast_C", "OnSetToast");

	Params::HousepartyWelcomeToast_C_OnSetToast Parms{};

	Parms.ToastNotification = ToastNotification;

	UObject::ProcessEvent(Func, &Parms);
}


// Function HousepartyWelcomeToast.HousepartyWelcomeToast_C.OnInitialized
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UHousepartyWelcomeToast_C::OnInitialized()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HousepartyWelcomeToast_C", "OnInitialized");

	UObject::ProcessEvent(Func, nullptr);
}


// Function HousepartyWelcomeToast.HousepartyWelcomeToast_C.ExecuteUbergraph_HousepartyWelcomeToast
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UHousepartyWelcomeToast_C::ExecuteUbergraph_HousepartyWelcomeToast(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HousepartyWelcomeToast_C", "ExecuteUbergraph_HousepartyWelcomeToast");

	Params::HousepartyWelcomeToast_C_ExecuteUbergraph_HousepartyWelcomeToast Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function HousepartyWelcomeToast.HousepartyWelcomeToast_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UHousepartyWelcomeToast_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HousepartyWelcomeToast_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}

}

