#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SidebarConfirmationButton

#include "Basic.hpp"

#include "SidebarConfirmationButton_classes.hpp"
#include "SidebarConfirmationButton_parameters.hpp"


namespace SDK
{

// Function SidebarConfirmationButton.SidebarConfirmationButton_C.BP_OnHovered
// (Event, Protected, BlueprintEvent)

void USidebarConfirmationButton_C::BP_OnHovered()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SidebarConfirmationButton_C", "BP_OnHovered");

	UObject::ProcessEvent(Func, nullptr);
}


// Function SidebarConfirmationButton.SidebarConfirmationButton_C.BP_OnUnhovered
// (Event, Protected, BlueprintEvent)

void USidebarConfirmationButton_C::BP_OnUnhovered()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SidebarConfirmationButton_C", "BP_OnUnhovered");

	UObject::ProcessEvent(Func, nullptr);
}


// Function SidebarConfirmationButton.SidebarConfirmationButton_C.ExecuteUbergraph_SidebarConfirmationButton
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void USidebarConfirmationButton_C::ExecuteUbergraph_SidebarConfirmationButton(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SidebarConfirmationButton_C", "ExecuteUbergraph_SidebarConfirmationButton");

	Params::SidebarConfirmationButton_C_ExecuteUbergraph_SidebarConfirmationButton Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function SidebarConfirmationButton.SidebarConfirmationButton_C.PreConstruct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// bool                                    IsDesignTime                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void USidebarConfirmationButton_C::PreConstruct(bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SidebarConfirmationButton_C", "PreConstruct");

	Params::SidebarConfirmationButton_C_PreConstruct Parms{};

	Parms.IsDesignTime = IsDesignTime;

	UObject::ProcessEvent(Func, &Parms);
}

}

