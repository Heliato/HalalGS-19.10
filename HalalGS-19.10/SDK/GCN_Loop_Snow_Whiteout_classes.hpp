#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GCN_Loop_Snow_Whiteout

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteGame_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass GCN_Loop_Snow_Whiteout.GCN_Loop_Snow_Whiteout_C
// 0x0038 (0x0840 - 0x0808)
class AGCN_Loop_Snow_Whiteout_C final : public AFortGameplayCueNotify_Loop
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0808(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UPostProcessComponent*                  PostProcess;                                       // 0x0810(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	float                                         FadeinOut_Post_BDCA5FC943E3CD00D42B59A9A0D1C530;   // 0x0818(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         FadeinOut_Fade_BDCA5FC943E3CD00D42B59A9A0D1C530;   // 0x081C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            FadeinOut__Direction_BDCA5FC943E3CD00D42B59A9A0D1C530; // 0x0820(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_821[0x7];                                      // 0x0821(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     FadeinOut;                                         // 0x0828(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             SoundOnFadeIn;                                     // 0x0830(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             SoundOnFadeOut;                                    // 0x0838(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_GCN_Loop_Snow_Whiteout(int32 EntryPoint);
	void FadeinOut__FinishedFunc();
	void FadeinOut__UpdateFunc();
	void OnLoopingStart(class AActor* MyTarget, const struct FGameplayCueParameters& Parameters, const TArray<class UParticleSystemComponent*>& ParticleComponents, const TArray<class UAudioComponent*>& AudioComponents);
	void OnRemoval(class AActor* MyTarget, const struct FGameplayCueParameters& Parameters, const TArray<class UParticleSystemComponent*>& ParticleComponents, const TArray<class UAudioComponent*>& AudioComponents, class UMatineeCameraShake* BurstCameraShakeInstance, class ADecalActor* BurstDecalInstance);
	void ReceiveDestroyed();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GCN_Loop_Snow_Whiteout_C">();
	}
	static class AGCN_Loop_Snow_Whiteout_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AGCN_Loop_Snow_Whiteout_C>();
	}
};

}

