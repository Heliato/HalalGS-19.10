#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SidebarOnboardingTooltip

#include "Basic.hpp"

#include "SidebarOnboardingTooltip_classes.hpp"
#include "SidebarOnboardingTooltip_parameters.hpp"


namespace SDK
{

// Function SidebarOnboardingTooltip.SidebarOnboardingTooltip_C.ExecuteUbergraph_SidebarOnboardingTooltip
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void USidebarOnboardingTooltip_C::ExecuteUbergraph_SidebarOnboardingTooltip(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SidebarOnboardingTooltip_C", "ExecuteUbergraph_SidebarOnboardingTooltip");

	Params::SidebarOnboardingTooltip_C_ExecuteUbergraph_SidebarOnboardingTooltip Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function SidebarOnboardingTooltip.SidebarOnboardingTooltip_C.Finished_17A538A941F98B1090CABB99882ED7AC
// (BlueprintCallable, BlueprintEvent)

void USidebarOnboardingTooltip_C::Finished_17A538A941F98B1090CABB99882ED7AC()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SidebarOnboardingTooltip_C", "Finished_17A538A941F98B1090CABB99882ED7AC");

	UObject::ProcessEvent(Func, nullptr);
}


// Function SidebarOnboardingTooltip.SidebarOnboardingTooltip_C.Finished_99BF07C64B870ED66F1A1E832D2626F0
// (BlueprintCallable, BlueprintEvent)

void USidebarOnboardingTooltip_C::Finished_99BF07C64B870ED66F1A1E832D2626F0()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SidebarOnboardingTooltip_C", "Finished_99BF07C64B870ED66F1A1E832D2626F0");

	UObject::ProcessEvent(Func, nullptr);
}


// Function SidebarOnboardingTooltip.SidebarOnboardingTooltip_C.OnEndTooltip
// (Event, Protected, BlueprintEvent)

void USidebarOnboardingTooltip_C::OnEndTooltip()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SidebarOnboardingTooltip_C", "OnEndTooltip");

	UObject::ProcessEvent(Func, nullptr);
}


// Function SidebarOnboardingTooltip.SidebarOnboardingTooltip_C.OnShowTooltip
// (Event, Protected, BlueprintEvent)

void USidebarOnboardingTooltip_C::OnShowTooltip()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SidebarOnboardingTooltip_C", "OnShowTooltip");

	UObject::ProcessEvent(Func, nullptr);
}

}

