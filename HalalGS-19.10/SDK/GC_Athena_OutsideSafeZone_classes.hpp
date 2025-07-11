#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GC_Athena_OutsideSafeZone

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteGame_classes.hpp"
#include "CoreUObject_structs.hpp"
#include "GameplayTags_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass GC_Athena_OutsideSafeZone.GC_Athena_OutsideSafeZone_C
// 0x0090 (0x0898 - 0x0808)
class AGC_Athena_OutsideSafeZone_C : public AFortGameplayCueNotify_Loop
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0808(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UPointLightComponent*                   Random_Lighting_Light;                             // 0x0810(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	float                                         LightningFlashTL_LERP_3FDEC95248645BE865DCD0840F99915A; // 0x0818(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            LightningFlashTL__Direction_3FDEC95248645BE865DCD0840F99915A; // 0x081C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_81D[0x3];                                      // 0x081D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     LightningFlashTL;                                  // 0x0820(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             Storm_Sound;                                       // 0x0828(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         LightningFlashDiameter;                            // 0x0830(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         LightningFlashHeight;                              // 0x0834(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                Lightning_Spawn_Location;                          // 0x0838(0x000C)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         _ChanceOfLightningMesh;                            // 0x0844(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Lightning_Intensity;                               // 0x0848(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         LightningIntensityMin;                             // 0x084C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         LightningIntensityMax;                             // 0x0850(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         LightningTimelinePlaySpeedMin;                     // 0x0854(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         LightningTimelinePlaySpeedMax;                     // 0x0858(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_85C[0x4];                                      // 0x085C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class APlayerPawn_Athena_Generic_C*           Player_Pawn;                                       // 0x0860(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         LightningFlashRepeatDelayMin;                      // 0x0868(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         LightningFlashRepeatDelayMax;                      // 0x086C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Storm_Stage;                                       // 0x0870(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FGameplayTag                           StormAudioTag_Low;                                 // 0x0874(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	struct FGameplayTag                           StormAudioTag_Medium;                              // 0x087C(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	struct FGameplayTag                           StormAudioTag_High;                                // 0x0884(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_88C[0x4];                                      // 0x088C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UAmbientAudioDataAsset*                 StormAudioBank;                                    // 0x0890(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_GC_Athena_OutsideSafeZone(int32 EntryPoint);
	void FlashTimeline();
	void Get_Location_in_Circle_XY(struct FVector* Location_Local_Space);
	void LightningFlashTL__FinishedFunc();
	void LightningFlashTL__UpdateFunc();
	void OnLoopingStart(class AActor* MyTarget, const struct FGameplayCueParameters& Parameters, const TArray<class UParticleSystemComponent*>& ParticleComponents, const TArray<class UAudioComponent*>& AudioComponents);
	void OnRemoval(class AActor* MyTarget, const struct FGameplayCueParameters& Parameters, const TArray<class UParticleSystemComponent*>& ParticleComponents, const TArray<class UAudioComponent*>& AudioComponents, class UMatineeCameraShake* BurstCameraShakeInstance, class ADecalActor* BurstDecalInstance);
	void Random_Lighting_Flashes();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GC_Athena_OutsideSafeZone_C">();
	}
	static class AGC_Athena_OutsideSafeZone_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AGC_Athena_OutsideSafeZone_C>();
	}
};

}

