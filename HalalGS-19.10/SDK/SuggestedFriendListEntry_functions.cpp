#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SuggestedFriendListEntry

#include "Basic.hpp"

#include "SuggestedFriendListEntry_classes.hpp"
#include "SuggestedFriendListEntry_parameters.hpp"


namespace SDK
{

// Function SuggestedFriendListEntry.SuggestedFriendListEntry_C.BndEvt__MenuAnchor_Actions_K2Node_ComponentBoundEvent_0_OnMenuOpenChangedEvent__DelegateSignature
// (BlueprintEvent)
// Parameters:
// bool                                    bIsOpen                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void USuggestedFriendListEntry_C::BndEvt__MenuAnchor_Actions_K2Node_ComponentBoundEvent_0_OnMenuOpenChangedEvent__DelegateSignature(bool bIsOpen)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SuggestedFriendListEntry_C", "BndEvt__MenuAnchor_Actions_K2Node_ComponentBoundEvent_0_OnMenuOpenChangedEvent__DelegateSignature");

	Params::SuggestedFriendListEntry_C_BndEvt__MenuAnchor_Actions_K2Node_ComponentBoundEvent_0_OnMenuOpenChangedEvent__DelegateSignature Parms{};

	Parms.bIsOpen = bIsOpen;

	UObject::ProcessEvent(Func, &Parms);
}


// Function SuggestedFriendListEntry.SuggestedFriendListEntry_C.BP_OnHovered
// (Event, Protected, BlueprintEvent)

void USuggestedFriendListEntry_C::BP_OnHovered()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SuggestedFriendListEntry_C", "BP_OnHovered");

	UObject::ProcessEvent(Func, nullptr);
}


// Function SuggestedFriendListEntry.SuggestedFriendListEntry_C.BP_OnUnhovered
// (Event, Protected, BlueprintEvent)

void USuggestedFriendListEntry_C::BP_OnUnhovered()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SuggestedFriendListEntry_C", "BP_OnUnhovered");

	UObject::ProcessEvent(Func, nullptr);
}


// Function SuggestedFriendListEntry.SuggestedFriendListEntry_C.ExecuteUbergraph_SuggestedFriendListEntry
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void USuggestedFriendListEntry_C::ExecuteUbergraph_SuggestedFriendListEntry(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SuggestedFriendListEntry_C", "ExecuteUbergraph_SuggestedFriendListEntry");

	Params::SuggestedFriendListEntry_C_ExecuteUbergraph_SuggestedFriendListEntry Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}

}

