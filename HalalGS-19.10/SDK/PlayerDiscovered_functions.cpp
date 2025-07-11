#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PlayerDiscovered

#include "Basic.hpp"

#include "PlayerDiscovered_classes.hpp"
#include "PlayerDiscovered_parameters.hpp"


namespace SDK
{

// Function PlayerDiscovered.PlayerDiscovered_C.Brief Show Finished
// (BlueprintCallable, BlueprintEvent)

void UPlayerDiscovered_C::Brief_Show_Finished()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PlayerDiscovered_C", "Brief Show Finished");

	UObject::ProcessEvent(Func, nullptr);
}


// Function PlayerDiscovered.PlayerDiscovered_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UPlayerDiscovered_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PlayerDiscovered_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function PlayerDiscovered.PlayerDiscovered_C.EndOfShow
// (Public, BlueprintCallable, BlueprintEvent)

void UPlayerDiscovered_C::EndOfShow()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PlayerDiscovered_C", "EndOfShow");

	UObject::ProcessEvent(Func, nullptr);
}


// Function PlayerDiscovered.PlayerDiscovered_C.ExecuteUbergraph_PlayerDiscovered
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPlayerDiscovered_C::ExecuteUbergraph_PlayerDiscovered(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PlayerDiscovered_C", "ExecuteUbergraph_PlayerDiscovered");

	Params::PlayerDiscovered_C_ExecuteUbergraph_PlayerDiscovered Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function PlayerDiscovered.PlayerDiscovered_C.K2_OnBecomeActive
// (Event, Protected, BlueprintEvent)

void UPlayerDiscovered_C::K2_OnBecomeActive()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PlayerDiscovered_C", "K2_OnBecomeActive");

	UObject::ProcessEvent(Func, nullptr);
}


// Function PlayerDiscovered.PlayerDiscovered_C.OnNewDiscovery
// (Event, Protected, HasOutParams, BlueprintEvent)
// Parameters:
// class FText                             LocalizedLocationName                                  (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// bool                                    bIsNamedLocation                                       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPlayerDiscovered_C::OnNewDiscovery(const class FText& LocalizedLocationName, bool bIsNamedLocation)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PlayerDiscovered_C", "OnNewDiscovery");

	Params::PlayerDiscovered_C_OnNewDiscovery Parms{};

	Parms.LocalizedLocationName = std::move(LocalizedLocationName);
	Parms.bIsNamedLocation = bIsNamedLocation;

	UObject::ProcessEvent(Func, &Parms);
}


// Function PlayerDiscovered.PlayerDiscovered_C.OnStompedByOtherWidget
// (Event, Protected, BlueprintEvent)

void UPlayerDiscovered_C::OnStompedByOtherWidget()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PlayerDiscovered_C", "OnStompedByOtherWidget");

	UObject::ProcessEvent(Func, nullptr);
}


// Function PlayerDiscovered.PlayerDiscovered_C.OnStompFailed
// (Event, Protected, BlueprintEvent)

void UPlayerDiscovered_C::OnStompFailed()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PlayerDiscovered_C", "OnStompFailed");

	UObject::ProcessEvent(Func, nullptr);
}


// Function PlayerDiscovered.PlayerDiscovered_C.Play Brief Show Sound
// (BlueprintCallable, BlueprintEvent)

void UPlayerDiscovered_C::Play_Brief_Show_Sound()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PlayerDiscovered_C", "Play Brief Show Sound");

	UObject::ProcessEvent(Func, nullptr);
}

}

