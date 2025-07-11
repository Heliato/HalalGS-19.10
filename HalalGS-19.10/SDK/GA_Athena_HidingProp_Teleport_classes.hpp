#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GA_Athena_HidingProp_Teleport

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "GameplayTags_structs.hpp"
#include "FortniteGame_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass GA_Athena_HidingProp_Teleport.GA_Athena_HidingProp_Teleport_C
// 0x0098 (0x0B40 - 0x0AA8)
class UGA_Athena_HidingProp_Teleport_C final : public UFortGameplayAbility
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0AA8(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	FMulticastInlineDelegateProperty_             NewEventDispatcher_0;                              // 0x0AB0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)
	class AB_HidingProp_C*                        HidingProp;                                        // 0x0AC0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AB_HidingProp_C*                        TargetTeleporter;                                  // 0x0AC8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FGameplayTagContainer                  T_HudElementToHide;                                // 0x0AD0(0x0020)(Edit, BlueprintVisible, DisableEditOnInstance)
	struct FGameplayTag                           TargetPropTeleportingCue;                          // 0x0AF0(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	struct FTimerHandle                           WobbleHandle;                                      // 0x0AF8(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	struct FGameplayTag                           WobbleCue;                                         // 0x0B00(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	float                                         ServerWorldTime;                                   // 0x0B08(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FGameplayTag                           EnterCue;                                          // 0x0B0C(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	struct FGameplayTag                           HidingInPropTag;                                   // 0x0B14(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_B1C[0x4];                                      // 0x0B1C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FGameplayTagContainer                  ChangeEquipmentTag;                                // 0x0B20(0x0020)(Edit, BlueprintVisible, DisableEditOnInstance)

public:
	void Added_67FE14EA4DF2D8C2DB494AA89443681B();
	void Added_CB8220A04B74338E758C11B7371D4630();
	void Added_F96D6DD549939CA425D2D1BE1AD32090();
	void Added_FD079A2341CDD832DF47CD975DFC3BB3();
	void ExecuteUbergraph_GA_Athena_HidingProp_Teleport(int32 EntryPoint);
	void GrapplerFailSafe(class AFortPawn* FortPawn);
	void K2_ActivateAbility();
	void K2_OnEndAbility(bool bWasCancelled);
	void NewEventDispatcher_0__DelegateSignature();
	void OnComplete_EE0FA6804073079396C44591432259C0();
	void OnPawnDied(class AActor* DamagedActor, float Damage, class AController* InstigatedBy, class AActor* DamageCauser, const struct FVector& HitLocation, class UPrimitiveComponent* FHitComponent, class FName BoneName, const struct FVector& Momentum);
	void QuestUpdate(class AFortPawn* Pawn);
	void Wobble();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GA_Athena_HidingProp_Teleport_C">();
	}
	static class UGA_Athena_HidingProp_Teleport_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UGA_Athena_HidingProp_Teleport_C>();
	}
};

}

