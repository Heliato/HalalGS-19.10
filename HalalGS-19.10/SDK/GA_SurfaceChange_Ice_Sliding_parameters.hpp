#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GA_SurfaceChange_Ice_Sliding

#include "Basic.hpp"


namespace SDK::Params
{

// Function GA_SurfaceChange_Ice_Sliding.GA_SurfaceChange_Ice_Sliding_C.ExecuteUbergraph_GA_SurfaceChange_Ice_Sliding
// 0x0020 (0x0020 - 0x0000)
struct GA_SurfaceChange_Ice_Sliding_C_ExecuteUbergraph_GA_SurfaceChange_Ice_Sliding final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_Event_bWasCancelled;                        // 0x0004(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_5[0x3];                                        // 0x0005(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class AFortPlayerPawn*                        CallFunc_GetAvatarAsFortPlayerPawn_ReturnValue;    // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UFortMovementComp_CharacterAthena*      K2Node_DynamicCast_AsFort_Movement_Comp_Character_Athena; // 0x0010(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function GA_SurfaceChange_Ice_Sliding.GA_SurfaceChange_Ice_Sliding_C.K2_OnEndAbility
// 0x0001 (0x0001 - 0x0000)
struct GA_SurfaceChange_Ice_Sliding_C_K2_OnEndAbility final
{
public:
	bool                                          bWasCancelled;                                     // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

}

