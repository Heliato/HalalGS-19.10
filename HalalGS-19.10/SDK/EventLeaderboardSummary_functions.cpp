#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: EventLeaderboardSummary

#include "Basic.hpp"

#include "EventLeaderboardSummary_classes.hpp"
#include "EventLeaderboardSummary_parameters.hpp"


namespace SDK
{

// Function EventLeaderboardSummary.EventLeaderboardSummary_C.BndEvt__Button_ViewAll_K2Node_ComponentBoundEvent_0_CommonButtonClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UCommonButtonLegacy*              Button                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UEventLeaderboardSummary_C::BndEvt__Button_ViewAll_K2Node_ComponentBoundEvent_0_CommonButtonClicked__DelegateSignature(class UCommonButtonLegacy* Button)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EventLeaderboardSummary_C", "BndEvt__Button_ViewAll_K2Node_ComponentBoundEvent_0_CommonButtonClicked__DelegateSignature");

	Params::EventLeaderboardSummary_C_BndEvt__Button_ViewAll_K2Node_ComponentBoundEvent_0_CommonButtonClicked__DelegateSignature Parms{};

	Parms.Button = Button;

	UObject::ProcessEvent(Func, &Parms);
}


// Function EventLeaderboardSummary.EventLeaderboardSummary_C.BndEvt__Button_ViewAll_K2Node_ComponentBoundEvent_1_CommonButtonClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UCommonButtonLegacy*              Button                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UEventLeaderboardSummary_C::BndEvt__Button_ViewAll_K2Node_ComponentBoundEvent_1_CommonButtonClicked__DelegateSignature(class UCommonButtonLegacy* Button)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EventLeaderboardSummary_C", "BndEvt__Button_ViewAll_K2Node_ComponentBoundEvent_1_CommonButtonClicked__DelegateSignature");

	Params::EventLeaderboardSummary_C_BndEvt__Button_ViewAll_K2Node_ComponentBoundEvent_1_CommonButtonClicked__DelegateSignature Parms{};

	Parms.Button = Button;

	UObject::ProcessEvent(Func, &Parms);
}


// Function EventLeaderboardSummary.EventLeaderboardSummary_C.BndEvt__Button_ViewAll_K2Node_ComponentBoundEvent_2_CommonButtonClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UCommonButtonLegacy*              Button                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UEventLeaderboardSummary_C::BndEvt__Button_ViewAll_K2Node_ComponentBoundEvent_2_CommonButtonClicked__DelegateSignature(class UCommonButtonLegacy* Button)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EventLeaderboardSummary_C", "BndEvt__Button_ViewAll_K2Node_ComponentBoundEvent_2_CommonButtonClicked__DelegateSignature");

	Params::EventLeaderboardSummary_C_BndEvt__Button_ViewAll_K2Node_ComponentBoundEvent_2_CommonButtonClicked__DelegateSignature Parms{};

	Parms.Button = Button;

	UObject::ProcessEvent(Func, &Parms);
}


// Function EventLeaderboardSummary.EventLeaderboardSummary_C.EventColorize
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FFortTournamentDisplayInfo       Param_TournamentDisplayInfo                            (BlueprintVisible, BlueprintReadOnly, Parm)

void UEventLeaderboardSummary_C::EventColorize(const struct FFortTournamentDisplayInfo& Param_TournamentDisplayInfo)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EventLeaderboardSummary_C", "EventColorize");

	Params::EventLeaderboardSummary_C_EventColorize Parms{};

	Parms.Param_TournamentDisplayInfo = std::move(Param_TournamentDisplayInfo);

	UObject::ProcessEvent(Func, &Parms);
}


// Function EventLeaderboardSummary.EventLeaderboardSummary_C.EventViewFullLeaderboard__DelegateSignature
// (Public, Delegate, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FString                           TournamentId                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)
// class FString                           EventId                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)

void UEventLeaderboardSummary_C::EventViewFullLeaderboard__DelegateSignature(const class FString& TournamentId, const class FString& EventId)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EventLeaderboardSummary_C", "EventViewFullLeaderboard__DelegateSignature");

	Params::EventLeaderboardSummary_C_EventViewFullLeaderboard__DelegateSignature Parms{};

	Parms.TournamentId = std::move(TournamentId);
	Parms.EventId = std::move(EventId);

	UObject::ProcessEvent(Func, &Parms);
}


// Function EventLeaderboardSummary.EventLeaderboardSummary_C.ExecuteUbergraph_EventLeaderboardSummary
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UEventLeaderboardSummary_C::ExecuteUbergraph_EventLeaderboardSummary(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EventLeaderboardSummary_C", "ExecuteUbergraph_EventLeaderboardSummary");

	Params::EventLeaderboardSummary_C_ExecuteUbergraph_EventLeaderboardSummary Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function EventLeaderboardSummary.EventLeaderboardSummary_C.RefreshDataBP
// (Event, Protected, BlueprintEvent)

void UEventLeaderboardSummary_C::RefreshDataBP()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EventLeaderboardSummary_C", "RefreshDataBP");

	UObject::ProcessEvent(Func, nullptr);
}

}

