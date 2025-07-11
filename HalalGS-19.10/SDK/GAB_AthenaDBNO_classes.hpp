#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GAB_AthenaDBNO

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteGame_structs.hpp"
#include "FortniteGame_classes.hpp"
#include "CoreUObject_structs.hpp"
#include "GameplayAbilities_structs.hpp"
#include "GameplayTags_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass GAB_AthenaDBNO.GAB_AthenaDBNO_C
// 0x0160 (0x0C08 - 0x0AA8)
class UGAB_AthenaDBNO_C final : public UFortGameplayAbility
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0AA8(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UAnimMontage*                           DeathMontage;                                      // 0x0AB0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                DeathHitDirection;                                 // 0x0AB8(0x000C)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FHitResult                             DeathHitResult;                                    // 0x0AC4(0x009C)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, ContainsInstancedReference)
	struct FGameplayTagContainer                  DamageTags;                                        // 0x0B60(0x0020)(Edit, BlueprintVisible, DisableEditOnInstance)
	struct FGameplayTagContainer                  GameplayStatusAfflicted;                           // 0x0B80(0x0020)(Edit, BlueprintVisible, DisableEditOnInstance)
	class UAnimMontage*                           DeathMontageSkydive;                               // 0x0BA0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FActiveGameplayEffectHandle            DBNOBleedGEHandle;                                 // 0x0BA8(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	class FName                                   HolsterId;                                         // 0x0BB0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAnimMontage*                           DeathMontageSwimming;                              // 0x0BB8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortPlayerPawnAthena*                  FortPlayerPawn;                                    // 0x0BC0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UClass*                                 DBNOStart_GE_Class;                                // 0x0BC8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          ImprovedDBNO;                                      // 0x0BD0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_BD1[0x7];                                      // 0x0BD1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FGameplayTagContainer                  Old_DBNO_Block_Tags;                               // 0x0BD8(0x0020)(Edit, BlueprintVisible, DisableEditOnInstance)
	struct FActiveGameplayEffectHandle            GE_Handle__Health_Bonus;                           // 0x0BF8(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	float                                         TenacityAmount;                                    // 0x0C00(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETenacityType                                 TenacityType;                                      // 0x0C04(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void Apply_Health_Bonus(struct FActiveGameplayEffectHandle* EffectHandle);
	void ApplyBleeding(struct FActiveGameplayEffectHandle* EffectHandle);
	void DropHeldObjects();
	void ExecuteUbergraph_GAB_AthenaDBNO(int32 EntryPoint);
	void Get_Custom_Tenacity(float* Tenacity);
	class UAnimMontage* Get_DBNO_Montage();
	void Get_Default_Tenacity_Amount(float* Tenacity);
	void Get_Initial_Heal_Amount(float* Health);
	void Get_Max_Health_Tenacity(float* Tenacity);
	void InitializeDeathHitDirection(const struct FGameplayEventData& EventHitData);
	void K2_ActivateAbilityFromEvent(const struct FGameplayEventData& EventData);
	void K2_OnEndAbility(bool bWasCancelled);
	void OnBlendOut_F0F6785443BD2E74F5591884CB19F35F();
	void OnCancelled_F0F6785443BD2E74F5591884CB19F35F();
	void OnCompleted_F0F6785443BD2E74F5591884CB19F35F();
	void OnFinish_4C169D40441E45B462D83CBBA67F6E45();
	void OnInterrupted_F0F6785443BD2E74F5591884CB19F35F();
	void OnStateEnded_C85094F843D5075FE4872C95AFC5D6B6();
	void OnStateInterrupted_C85094F843D5075FE4872C95AFC5D6B6();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GAB_AthenaDBNO_C">();
	}
	static class UGAB_AthenaDBNO_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UGAB_AthenaDBNO_C>();
	}
};

}

