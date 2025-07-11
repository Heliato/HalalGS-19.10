#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: QuartzMusicTrackComponent

#include "Basic.hpp"

#include "QuartzMusicTrackComponent_classes.hpp"
#include "QuartzMusicTrackComponent_parameters.hpp"


namespace SDK
{

// Function QuartzMusicTrackComponent.QuartzMusicTrackComponent_C.ExecuteUbergraph_QuartzMusicTrackComponent
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UQuartzMusicTrackComponent_C::ExecuteUbergraph_QuartzMusicTrackComponent(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuartzMusicTrackComponent_C", "ExecuteUbergraph_QuartzMusicTrackComponent");

	Params::QuartzMusicTrackComponent_C_ExecuteUbergraph_QuartzMusicTrackComponent Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function QuartzMusicTrackComponent.QuartzMusicTrackComponent_C.GetAudioComponent
// (Protected, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class UAudioComponent*                  Param_AudioComponent                                   (Parm, OutParm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UQuartzMusicTrackComponent_C::GetAudioComponent(class UAudioComponent** Param_AudioComponent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuartzMusicTrackComponent_C", "GetAudioComponent");

	Params::QuartzMusicTrackComponent_C_GetAudioComponent Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Param_AudioComponent != nullptr)
		*Param_AudioComponent = Parms.Param_AudioComponent;
}


// Function QuartzMusicTrackComponent.QuartzMusicTrackComponent_C.GetClockHandle
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class UQuartzClockHandle*               Clock_Handle                                           (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UQuartzMusicTrackComponent_C::GetClockHandle(class UQuartzClockHandle** Clock_Handle)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuartzMusicTrackComponent_C", "GetClockHandle");

	Params::QuartzMusicTrackComponent_C_GetClockHandle Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Clock_Handle != nullptr)
		*Clock_Handle = Parms.Clock_Handle;
}


// Function QuartzMusicTrackComponent.QuartzMusicTrackComponent_C.GetIsPlaying
// (Protected, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    Is_Playing                                             (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UQuartzMusicTrackComponent_C::GetIsPlaying(bool* Is_Playing)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuartzMusicTrackComponent_C", "GetIsPlaying");

	Params::QuartzMusicTrackComponent_C_GetIsPlaying Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Is_Playing != nullptr)
		*Is_Playing = Parms.Is_Playing;
}


// Function QuartzMusicTrackComponent.QuartzMusicTrackComponent_C.GetPlayState
// (Protected, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// EAudioComponentPlayState                ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

EAudioComponentPlayState UQuartzMusicTrackComponent_C::GetPlayState()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuartzMusicTrackComponent_C", "GetPlayState");

	Params::QuartzMusicTrackComponent_C_GetPlayState Parms{};

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function QuartzMusicTrackComponent.QuartzMusicTrackComponent_C.GetTrackPriority
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// float                                   Priority                                               (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UQuartzMusicTrackComponent_C::GetTrackPriority(float* Priority)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuartzMusicTrackComponent_C", "GetTrackPriority");

	Params::QuartzMusicTrackComponent_C_GetTrackPriority Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Priority != nullptr)
		*Priority = Parms.Priority;
}


// Function QuartzMusicTrackComponent.QuartzMusicTrackComponent_C.OnQuartzClockDelegate
// (Private, BlueprintCallable, BlueprintEvent)
// Parameters:
// EQuartzCommandDelegateSubType           EventType                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class FName                             Param_Name                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UQuartzMusicTrackComponent_C::OnQuartzClockDelegate(EQuartzCommandDelegateSubType EventType, class FName Param_Name)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuartzMusicTrackComponent_C", "OnQuartzClockDelegate");

	Params::QuartzMusicTrackComponent_C_OnQuartzClockDelegate Parms{};

	Parms.EventType = EventType;
	Parms.Param_Name = Param_Name;

	UObject::ProcessEvent(Func, &Parms);
}


// Function QuartzMusicTrackComponent.QuartzMusicTrackComponent_C.OnQuartzQuantizationEvent
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FName                             Param_ClockName                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// EQuartzCommandQuantization              QuantizationType                                       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   NumBars                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   Beat                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   BeatFraction                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UQuartzMusicTrackComponent_C::OnQuartzQuantizationEvent(class FName Param_ClockName, EQuartzCommandQuantization QuantizationType, int32 NumBars, int32 Beat, float BeatFraction)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuartzMusicTrackComponent_C", "OnQuartzQuantizationEvent");

	Params::QuartzMusicTrackComponent_C_OnQuartzQuantizationEvent Parms{};

	Parms.Param_ClockName = Param_ClockName;
	Parms.QuantizationType = QuantizationType;
	Parms.NumBars = NumBars;
	Parms.Beat = Beat;
	Parms.BeatFraction = BeatFraction;

	UObject::ProcessEvent(Func, &Parms);
}


// Function QuartzMusicTrackComponent.QuartzMusicTrackComponent_C.QueueTrackStart
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void UQuartzMusicTrackComponent_C::QueueTrackStart()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuartzMusicTrackComponent_C", "QueueTrackStart");

	UObject::ProcessEvent(Func, nullptr);
}


// Function QuartzMusicTrackComponent.QuartzMusicTrackComponent_C.QueueTrackStop
// (Public, BlueprintCallable, BlueprintEvent)

void UQuartzMusicTrackComponent_C::QueueTrackStop()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuartzMusicTrackComponent_C", "QueueTrackStop");

	UObject::ProcessEvent(Func, nullptr);
}


// Function QuartzMusicTrackComponent.QuartzMusicTrackComponent_C.ReceiveBeginPlay
// (Event, Public, BlueprintEvent)

void UQuartzMusicTrackComponent_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuartzMusicTrackComponent_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function QuartzMusicTrackComponent.QuartzMusicTrackComponent_C.ReceiveEndPlay
// (Event, Public, BlueprintEvent)
// Parameters:
// EEndPlayReason                          EndPlayReason                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UQuartzMusicTrackComponent_C::ReceiveEndPlay(EEndPlayReason EndPlayReason)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuartzMusicTrackComponent_C", "ReceiveEndPlay");

	Params::QuartzMusicTrackComponent_C_ReceiveEndPlay Parms{};

	Parms.EndPlayReason = EndPlayReason;

	UObject::ProcessEvent(Func, &Parms);
}


// Function QuartzMusicTrackComponent.QuartzMusicTrackComponent_C.SetDebugEnabled
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Debug                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UQuartzMusicTrackComponent_C::SetDebugEnabled(bool Debug)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuartzMusicTrackComponent_C", "SetDebugEnabled");

	Params::QuartzMusicTrackComponent_C_SetDebugEnabled Parms{};

	Parms.Debug = Debug;

	UObject::ProcessEvent(Func, &Parms);
}


// Function QuartzMusicTrackComponent.QuartzMusicTrackComponent_C.SetStemVolume
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   Param_Index                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   Value                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UQuartzMusicTrackComponent_C::SetStemVolume(int32 Param_Index, float Value)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuartzMusicTrackComponent_C", "SetStemVolume");

	Params::QuartzMusicTrackComponent_C_SetStemVolume Parms{};

	Parms.Param_Index = Param_Index;
	Parms.Value = Value;

	UObject::ProcessEvent(Func, &Parms);
}


// Function QuartzMusicTrackComponent.QuartzMusicTrackComponent_C.SetTrackParameter
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   ParameterIndex                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   InFloat                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UQuartzMusicTrackComponent_C::SetTrackParameter(int32 ParameterIndex, float InFloat)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuartzMusicTrackComponent_C", "SetTrackParameter");

	Params::QuartzMusicTrackComponent_C_SetTrackParameter Parms{};

	Parms.ParameterIndex = ParameterIndex;
	Parms.InFloat = InFloat;

	UObject::ProcessEvent(Func, &Parms);
}

}

