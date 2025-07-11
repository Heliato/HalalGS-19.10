#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PetAnimLayerInterface

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "Engine_structs.hpp"


namespace SDK::Params
{

// Function PetAnimLayerInterface.PetAnimLayerInterface_C.PetFullOverrideLayer
// 0x0020 (0x0020 - 0x0000)
struct PetAnimLayerInterface_C_PetFullOverrideLayer final
{
public:
	struct FPoseLink                              InPose;                                            // 0x0000(0x0010)(BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor)
	struct FPoseLink                              Param_PetFullOverrideLayer;                        // 0x0010(0x0010)(Parm, OutParm, NoDestructor)
};

// Function PetAnimLayerInterface.PetAnimLayerInterface_C.PetSkeletalControlLayer
// 0x0038 (0x0038 - 0x0000)
struct PetAnimLayerInterface_C_PetSkeletalControlLayer final
{
public:
	struct FPoseLink                              Pose;                                              // 0x0000(0x0010)(BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor)
	float                                         LookAtOverrideInput;                               // 0x0010(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                LookAtTargetLocationInput;                         // 0x0014(0x000C)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         LegIKAlphaOverride;                                // 0x0020(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         HandIKAlphaOverride;                               // 0x0024(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FPoseLink                              Param_PetSkeletalControlLayer;                     // 0x0028(0x0010)(Parm, OutParm, NoDestructor)
};

}

