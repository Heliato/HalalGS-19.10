#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SidebarBackButton

#include "Basic.hpp"

#include "SidebarBackButton_classes.hpp"
#include "SidebarBackButton_parameters.hpp"


namespace SDK
{

// Function SidebarBackButton.SidebarBackButton_C.OnInitialized
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void USidebarBackButton_C::OnInitialized()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SidebarBackButton_C", "OnInitialized");

	UObject::ProcessEvent(Func, nullptr);
}


// Function SidebarBackButton.SidebarBackButton_C.ExecuteUbergraph_SidebarBackButton
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void USidebarBackButton_C::ExecuteUbergraph_SidebarBackButton(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SidebarBackButton_C", "ExecuteUbergraph_SidebarBackButton");

	Params::SidebarBackButton_C_ExecuteUbergraph_SidebarBackButton Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}

}

