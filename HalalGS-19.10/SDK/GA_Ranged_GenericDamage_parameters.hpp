#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GA_Ranged_GenericDamage

#include "Basic.hpp"

#include "GameplayTags_structs.hpp"
#include "GameplayAbilities_structs.hpp"


namespace SDK::Params
{

// Function GA_Ranged_GenericDamage.GA_Ranged_GenericDamage_C.GetEventData
// 0x0208 (0x0208 - 0x0000)
struct GA_Ranged_GenericDamage_C_GetEventData final
{
public:
	struct FGameplayTag                           EventTag;                                          // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor, HasGetValueTypeHash)
	struct FGameplayEventData                     GameplayEventData;                                 // 0x0008(0x00B0)(Parm, OutParm)
	struct FGameplayTagContainer                  GT_TargetTags;                                     // 0x00B8(0x0020)(Edit, BlueprintVisible)
	struct FGameplayTagContainer                  GT_InstigatorTags;                                 // 0x00D8(0x0020)(Edit, BlueprintVisible)
	class AActor*                                 CallFunc_GetOwningActorFromActorInfo_ReturnValue;  // 0x00F8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortPlayerState*                       K2Node_DynamicCast_AsFort_Player_State;            // 0x0100(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0108(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_109[0x7];                                      // 0x0109(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class AFortPlayerPawn*                        CallFunc_GetCurrentPawn_ReturnValue;               // 0x0110(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0118(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_119[0x7];                                      // 0x0119(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class AFortWeapon*                            CallFunc_GetCurrentSourceWeapon_ReturnValue;       // 0x0120(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue_1;                    // 0x0128(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_129[0x7];                                      // 0x0129(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FGameplayEventData                     K2Node_MakeStruct_GameplayEventData;               // 0x0130(0x00B0)()
	struct FGameplayTagContainer                  CallFunc_GetWeaponDataGameplayTags_GameplayTags;   // 0x01E0(0x0020)()
	bool                                          CallFunc_WeaponDataIsValid_ReturnValue;            // 0x0200(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_BooleanAND_ReturnValue;                   // 0x0201(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function GA_Ranged_GenericDamage.GA_Ranged_GenericDamage_C.K2_CommitExecute
// 0x00B0 (0x00B0 - 0x0000)
struct GA_Ranged_GenericDamage_C_K2_CommitExecute final
{
public:
	struct FGameplayEventData                     CallFunc_GetEventData_GameplayEventData;           // 0x0000(0x00B0)()
};

}

