#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_TimeSynthController_Base

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "TimeSynth_structs.hpp"
#include "FortniteGame_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_TimeSynthController_Base.BP_TimeSynthController_Base_C
// 0x0070 (0x0290 - 0x0220)
class ABP_TimeSynthController_Base_C final : public AFortTimeSynthController
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0220(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UTimeSynthComponent*                    TimeSynth;                                         // 0x0228(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBP_TimeSynthTrackComponent_C*          CurrentTrack;                                      // 0x0230(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         TransitionBeats;                                   // 0x0238(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          TransitionActive;                                  // 0x023C(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_23D[0x3];                                      // 0x023D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UBP_TimeSynthTrackComponent_C*          QueuedTransitionTrack;                             // 0x0240(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<class UTimeSynthVolumeGroup*>          VolumeGroups;                                      // 0x0248(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	TArray<struct FTimeSynthClipHandle>           QueuedTransitions;                                 // 0x0258(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	TArray<class UBP_TimeSynthTrackComponent_C*>  QueuedTracks;                                      // 0x0268(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, ContainsInstancedReference)
	bool                                          IsPlaying;                                         // 0x0278(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Debug;                                             // 0x0279(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_27A[0x6];                                      // 0x027A(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	class UFortGameplayDataTrackerComponentManager* DataTrackerManager;                                // 0x0280(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          IsStoppedPermenant;                                // 0x0288(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void CalculateMaxClipDuration(class UBP_TimeSynthTrackComponent_C* Track, int32* Duration);
	void ChangeTrack(class UBP_TimeSynthTrackComponent_C* New_Track);
	void ExecuteUbergraph_BP_TimeSynthController_Base(int32 EntryPoint);
	void FlushExtraClips(bool Exclude_Current);
	void GetIsPlaying(bool* Param_IsPlaying);
	void GetTimeSynthComponent(class UTimeSynthComponent** Param_TimeSynth);
	void OnQuantizationBar(ETimeSynthEventQuantization QuantizationType, int32 NumBars, float Beat);
	void OnQuantizationBeat(ETimeSynthEventQuantization QuantizationType, int32 NumBars, float Beat);
	void OnTimeSynthTrackComponentRegistered(const class UBP_TimeSynthTrackComponent_C*& Track);
	void PlayTransition(const struct FTimeSynth_TransitionData& Transition_Data, class UBP_TimeSynthTrackComponent_C* Queued_Track);
	void QueueTrackStartInternal(class UBP_TimeSynthTrackComponent_C* NewTrack);
	void ReceiveBeginPlay();
	void RegisterTrackComponents();
	void RequestTrackChange(class UBP_TimeSynthTrackComponent_C* TrackRequesting, bool* CanChangeTrack);
	void SetVolumeGroup(int32 Param_Index, float Volume_Multiplier);
	void StopAllMusic(bool Play_Outro);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_TimeSynthController_Base_C">();
	}
	static class ABP_TimeSynthController_Base_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABP_TimeSynthController_Base_C>();
	}
};

}

