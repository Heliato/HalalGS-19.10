#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GCN_Loop_GhostMode

#include "Basic.hpp"

#include "FortniteGame_classes.hpp"
#include "CoreUObject_structs.hpp"
#include "Engine_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass GCN_Loop_GhostMode.GCN_Loop_GhostMode_C
// 0x0060 (0x0868 - 0x0808)
class AGCN_Loop_GhostMode_C : public AFortGameplayCueNotify_Loop
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0808(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	float                                         FadeMaterialsTL_Lerp_D7B0BAAD47F48403BE23B98F38D8CA3E; // 0x0810(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            FadeMaterialsTL__Direction_D7B0BAAD47F48403BE23B98F38D8CA3E; // 0x0814(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_815[0x3];                                      // 0x0815(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     FadeMaterialsTL;                                   // 0x0818(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           HitGlowColor;                                      // 0x0820(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           HotGlowOuterColor;                                 // 0x0830(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         HitGlowFresnelBrightness;                          // 0x0840(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         HitGlowFresnelExponent;                            // 0x0844(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APlayerPawn_Athena_C*                   Target_Player;                                     // 0x0848(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Glow_Priority;                                     // 0x0850(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_854[0x4];                                      // 0x0854(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class USoundBase*                             StopSoundCue;                                      // 0x0858(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             StartSoundCue;                                     // 0x0860(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_GCN_Loop_GhostMode(int32 EntryPoint);
	void FadeMaterialsIn();
	void FadeMaterialsOut();
	void FadeMaterialsTL__FinishedFunc();
	void FadeMaterialsTL__UpdateFunc();
	void Highlight_Lerp(float Alpha, struct FPawnHighlight* Highlight);
	void OnLoopingStart(class AActor* MyTarget, const struct FGameplayCueParameters& Parameters, const TArray<class UParticleSystemComponent*>& ParticleComponents, const TArray<class UAudioComponent*>& AudioComponents);
	void OnRemoval(class AActor* MyTarget, const struct FGameplayCueParameters& Parameters, const TArray<class UParticleSystemComponent*>& ParticleComponents, const TArray<class UAudioComponent*>& AudioComponents, class UMatineeCameraShake* BurstCameraShakeInstance, class ADecalActor* BurstDecalInstance);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GCN_Loop_GhostMode_C">();
	}
	static class AGCN_Loop_GhostMode_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AGCN_Loop_GhostMode_C>();
	}
};

}

