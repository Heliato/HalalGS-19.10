#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_TimeSynthTrackComponent

#include "Basic.hpp"

#include "BP_TimeSynthTrackComponent_classes.hpp"
#include "BP_TimeSynthTrackComponent_parameters.hpp"


namespace SDK
{

// Function BP_TimeSynthTrackComponent.BP_TimeSynthTrackComponent_C.CalculateMaxClipDuration
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// TArray<struct FTimeSynth_TrackStemData> Param_Clips                                            (BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// int32                                   Duration                                               (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBP_TimeSynthTrackComponent_C::CalculateMaxClipDuration(TArray<struct FTimeSynth_TrackStemData>& Param_Clips, int32* Duration)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_TimeSynthTrackComponent_C", "CalculateMaxClipDuration");

	Params::BP_TimeSynthTrackComponent_C_CalculateMaxClipDuration Parms{};

	Parms.Param_Clips = std::move(Param_Clips);

	UObject::ProcessEvent(Func, &Parms);

	Param_Clips = std::move(Parms.Param_Clips);

	if (Duration != nullptr)
		*Duration = Parms.Duration;
}


// Function BP_TimeSynthTrackComponent.BP_TimeSynthTrackComponent_C.CheckPlaystate
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// ETimeSynth_TrackPlayStates              Is_In_Play_State                                       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBP_TimeSynthTrackComponent_C::CheckPlaystate(ETimeSynth_TrackPlayStates Is_In_Play_State, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_TimeSynthTrackComponent_C", "CheckPlaystate");

	Params::BP_TimeSynthTrackComponent_C_CheckPlaystate Parms{};

	Parms.Is_In_Play_State = Is_In_Play_State;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function BP_TimeSynthTrackComponent.BP_TimeSynthTrackComponent_C.ExecuteUbergraph_BP_TimeSynthTrackComponent
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBP_TimeSynthTrackComponent_C::ExecuteUbergraph_BP_TimeSynthTrackComponent(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_TimeSynthTrackComponent_C", "ExecuteUbergraph_BP_TimeSynthTrackComponent");

	Params::BP_TimeSynthTrackComponent_C_ExecuteUbergraph_BP_TimeSynthTrackComponent Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_TimeSynthTrackComponent.BP_TimeSynthTrackComponent_C.FindMixState
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class FName                             Param_Name                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   Array_Index                                            (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBP_TimeSynthTrackComponent_C::FindMixState(class FName Param_Name, int32* Array_Index)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_TimeSynthTrackComponent_C", "FindMixState");

	Params::BP_TimeSynthTrackComponent_C_FindMixState Parms{};

	Parms.Param_Name = Param_Name;

	UObject::ProcessEvent(Func, &Parms);

	if (Array_Index != nullptr)
		*Array_Index = Parms.Array_Index;
}


// Function BP_TimeSynthTrackComponent.BP_TimeSynthTrackComponent_C.GetMaxClipDuration
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// int32                                   MaxClipDuration                                        (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBP_TimeSynthTrackComponent_C::GetMaxClipDuration(int32* MaxClipDuration)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_TimeSynthTrackComponent_C", "GetMaxClipDuration");

	Params::BP_TimeSynthTrackComponent_C_GetMaxClipDuration Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (MaxClipDuration != nullptr)
		*MaxClipDuration = Parms.MaxClipDuration;
}


// Function BP_TimeSynthTrackComponent.BP_TimeSynthTrackComponent_C.GetMixStateIndexFromName
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class FName                             Param_Name                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   Array_Index                                            (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBP_TimeSynthTrackComponent_C::GetMixStateIndexFromName(class FName Param_Name, int32* Array_Index)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_TimeSynthTrackComponent_C", "GetMixStateIndexFromName");

	Params::BP_TimeSynthTrackComponent_C_GetMixStateIndexFromName Parms{};

	Parms.Param_Name = Param_Name;

	UObject::ProcessEvent(Func, &Parms);

	if (Array_Index != nullptr)
		*Array_Index = Parms.Array_Index;
}


// Function BP_TimeSynthTrackComponent.BP_TimeSynthTrackComponent_C.GetPriority
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// float                                   Priority                                               (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBP_TimeSynthTrackComponent_C::GetPriority(float* Priority)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_TimeSynthTrackComponent_C", "GetPriority");

	Params::BP_TimeSynthTrackComponent_C_GetPriority Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Priority != nullptr)
		*Priority = Parms.Priority;
}


// Function BP_TimeSynthTrackComponent.BP_TimeSynthTrackComponent_C.GetQuantizationSettings
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FTimeSynthQuantizationSettings   Param_QuantizationSettings                             (Parm, OutParm, NoDestructor)

void UBP_TimeSynthTrackComponent_C::GetQuantizationSettings(struct FTimeSynthQuantizationSettings* Param_QuantizationSettings)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_TimeSynthTrackComponent_C", "GetQuantizationSettings");

	Params::BP_TimeSynthTrackComponent_C_GetQuantizationSettings Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Param_QuantizationSettings != nullptr)
		*Param_QuantizationSettings = std::move(Parms.Param_QuantizationSettings);
}


// Function BP_TimeSynthTrackComponent.BP_TimeSynthTrackComponent_C.GetTimeSynthController
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class ABP_TimeSynthController_Base_C*   Param_TimeSynthController                              (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBP_TimeSynthTrackComponent_C::GetTimeSynthController(class ABP_TimeSynthController_Base_C** Param_TimeSynthController)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_TimeSynthTrackComponent_C", "GetTimeSynthController");

	Params::BP_TimeSynthTrackComponent_C_GetTimeSynthController Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Param_TimeSynthController != nullptr)
		*Param_TimeSynthController = Parms.Param_TimeSynthController;
}


// Function BP_TimeSynthTrackComponent.BP_TimeSynthTrackComponent_C.GetTrackID
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class FName                             Param_TrackID                                          (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBP_TimeSynthTrackComponent_C::GetTrackID(class FName* Param_TrackID)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_TimeSynthTrackComponent_C", "GetTrackID");

	Params::BP_TimeSynthTrackComponent_C_GetTrackID Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Param_TrackID != nullptr)
		*Param_TrackID = Parms.Param_TrackID;
}


// Function BP_TimeSynthTrackComponent.BP_TimeSynthTrackComponent_C.HasTransitionForTrack
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class FName                             Param_TrackID                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Transition_Found                                       (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FTimeSynth_TransitionData        Transition_Data                                        (Parm, OutParm, HasGetValueTypeHash)

void UBP_TimeSynthTrackComponent_C::HasTransitionForTrack(class FName Param_TrackID, bool* Transition_Found, struct FTimeSynth_TransitionData* Transition_Data)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_TimeSynthTrackComponent_C", "HasTransitionForTrack");

	Params::BP_TimeSynthTrackComponent_C_HasTransitionForTrack Parms{};

	Parms.Param_TrackID = Param_TrackID;

	UObject::ProcessEvent(Func, &Parms);

	if (Transition_Found != nullptr)
		*Transition_Found = Parms.Transition_Found;

	if (Transition_Data != nullptr)
		*Transition_Data = std::move(Parms.Transition_Data);
}


// Function BP_TimeSynthTrackComponent.BP_TimeSynthTrackComponent_C.LoopCurrentTrack
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void UBP_TimeSynthTrackComponent_C::LoopCurrentTrack()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_TimeSynthTrackComponent_C", "LoopCurrentTrack");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_TimeSynthTrackComponent.BP_TimeSynthTrackComponent_C.OnPlayStateChanged__DelegateSignature
// (Public, Delegate, BlueprintCallable, BlueprintEvent)
// Parameters:
// ETimeSynth_TrackPlayStates              Previous                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// ETimeSynth_TrackPlayStates              New                                                    (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBP_TimeSynthTrackComponent_C::OnPlayStateChanged__DelegateSignature(ETimeSynth_TrackPlayStates Previous, ETimeSynth_TrackPlayStates New)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_TimeSynthTrackComponent_C", "OnPlayStateChanged__DelegateSignature");

	Params::BP_TimeSynthTrackComponent_C_OnPlayStateChanged__DelegateSignature Parms{};

	Parms.Previous = Previous;
	Parms.New = New;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_TimeSynthTrackComponent.BP_TimeSynthTrackComponent_C.OnQuantizationBar
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// ETimeSynthEventQuantization             QuantizationType                                       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   NumBars                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   Beat                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBP_TimeSynthTrackComponent_C::OnQuantizationBar(ETimeSynthEventQuantization QuantizationType, int32 NumBars, float Beat)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_TimeSynthTrackComponent_C", "OnQuantizationBar");

	Params::BP_TimeSynthTrackComponent_C_OnQuantizationBar Parms{};

	Parms.QuantizationType = QuantizationType;
	Parms.NumBars = NumBars;
	Parms.Beat = Beat;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_TimeSynthTrackComponent.BP_TimeSynthTrackComponent_C.OnQuantizationBeat
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// ETimeSynthEventQuantization             QuantizationType                                       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   NumBars                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   Beat                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBP_TimeSynthTrackComponent_C::OnQuantizationBeat(ETimeSynthEventQuantization QuantizationType, int32 NumBars, float Beat)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_TimeSynthTrackComponent_C", "OnQuantizationBeat");

	Params::BP_TimeSynthTrackComponent_C_OnQuantizationBeat Parms{};

	Parms.QuantizationType = QuantizationType;
	Parms.NumBars = NumBars;
	Parms.Beat = Beat;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_TimeSynthTrackComponent.BP_TimeSynthTrackComponent_C.QueueTrackStart
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Is_First_Track                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBP_TimeSynthTrackComponent_C::QueueTrackStart(bool Is_First_Track)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_TimeSynthTrackComponent_C", "QueueTrackStart");

	Params::BP_TimeSynthTrackComponent_C_QueueTrackStart Parms{};

	Parms.Is_First_Track = Is_First_Track;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_TimeSynthTrackComponent.BP_TimeSynthTrackComponent_C.QueueTrackStop
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Play_Outro                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBP_TimeSynthTrackComponent_C::QueueTrackStop(bool Play_Outro)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_TimeSynthTrackComponent_C", "QueueTrackStop");

	Params::BP_TimeSynthTrackComponent_C_QueueTrackStop Parms{};

	Parms.Play_Outro = Play_Outro;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_TimeSynthTrackComponent.BP_TimeSynthTrackComponent_C.ReceiveBeginPlay
// (Event, Public, BlueprintEvent)

void UBP_TimeSynthTrackComponent_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_TimeSynthTrackComponent_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_TimeSynthTrackComponent.BP_TimeSynthTrackComponent_C.SetMixStateVolume
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FName                             MixStateName                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   Volume                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBP_TimeSynthTrackComponent_C::SetMixStateVolume(class FName MixStateName, float Volume)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_TimeSynthTrackComponent_C", "SetMixStateVolume");

	Params::BP_TimeSynthTrackComponent_C_SetMixStateVolume Parms{};

	Parms.MixStateName = MixStateName;
	Parms.Volume = Volume;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_TimeSynthTrackComponent.BP_TimeSynthTrackComponent_C.SetMixStateVolumeByIndex
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   Param_Index                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   Volume                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBP_TimeSynthTrackComponent_C::SetMixStateVolumeByIndex(int32 Param_Index, float Volume)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_TimeSynthTrackComponent_C", "SetMixStateVolumeByIndex");

	Params::BP_TimeSynthTrackComponent_C_SetMixStateVolumeByIndex Parms{};

	Parms.Param_Index = Param_Index;
	Parms.Volume = Volume;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_TimeSynthTrackComponent.BP_TimeSynthTrackComponent_C.SetPlaystate
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// ETimeSynth_TrackPlayStates              Is_In_Play_State                                       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBP_TimeSynthTrackComponent_C::SetPlaystate(ETimeSynth_TrackPlayStates Is_In_Play_State)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_TimeSynthTrackComponent_C", "SetPlaystate");

	Params::BP_TimeSynthTrackComponent_C_SetPlaystate Parms{};

	Parms.Is_In_Play_State = Is_In_Play_State;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_TimeSynthTrackComponent.BP_TimeSynthTrackComponent_C.SetTimeSynthController
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class ABP_TimeSynthController_Base_C*   Param_TimeSynthController                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBP_TimeSynthTrackComponent_C::SetTimeSynthController(class ABP_TimeSynthController_Base_C* Param_TimeSynthController)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_TimeSynthTrackComponent_C", "SetTimeSynthController");

	Params::BP_TimeSynthTrackComponent_C_SetTimeSynthController Parms{};

	Parms.Param_TimeSynthController = Param_TimeSynthController;

	UObject::ProcessEvent(Func, &Parms);
}

}

