#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: QuartzMusicTrackComponent_SpicySake

#include "Basic.hpp"

#include "QuartzMusicTrackComponent_SpicySake_classes.hpp"
#include "QuartzMusicTrackComponent_SpicySake_parameters.hpp"


namespace SDK
{

// Function QuartzMusicTrackComponent_SpicySake.QuartzMusicTrackComponent_SpicySake_C.HandleMixState
// (Public, BlueprintCallable, BlueprintEvent)

void UQuartzMusicTrackComponent_SpicySake_C::HandleMixState()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuartzMusicTrackComponent_SpicySake_C", "HandleMixState");

	UObject::ProcessEvent(Func, nullptr);
}


// Function QuartzMusicTrackComponent_SpicySake.QuartzMusicTrackComponent_SpicySake_C.OnDataTrackerUpdate
// (Public, BlueprintCallable, BlueprintEvent)

void UQuartzMusicTrackComponent_SpicySake_C::OnDataTrackerUpdate()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuartzMusicTrackComponent_SpicySake_C", "OnDataTrackerUpdate");

	UObject::ProcessEvent(Func, nullptr);
}


// Function QuartzMusicTrackComponent_SpicySake.QuartzMusicTrackComponent_SpicySake_C.UpdateInterpValue
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// float                                   InterpValue                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FGameplayTag                     EventTag                                               (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, NoDestructor, HasGetValueTypeHash)
// float                                   Attack_Speed                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   Release_Speed                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

float UQuartzMusicTrackComponent_SpicySake_C::UpdateInterpValue(float InterpValue, const struct FGameplayTag& EventTag, float Attack_Speed, float Release_Speed)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuartzMusicTrackComponent_SpicySake_C", "UpdateInterpValue");

	Params::QuartzMusicTrackComponent_SpicySake_C_UpdateInterpValue Parms{};

	Parms.InterpValue = InterpValue;
	Parms.EventTag = std::move(EventTag);
	Parms.Attack_Speed = Attack_Speed;
	Parms.Release_Speed = Release_Speed;

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}

}

