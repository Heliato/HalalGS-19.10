#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: F_MED_Lollipop_AnimBP

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "AnimGraphRuntime_structs.hpp"
#include "FortniteGame_classes.hpp"


namespace SDK
{

// AnimBlueprintGeneratedClass F_MED_Lollipop_AnimBP.F_MED_Lollipop_AnimBP_C
// 0x2A20 (0x2FA0 - 0x0580)
class UF_MED_Lollipop_AnimBP_C final : public UCustomCharacterPartAnimInstance
{
public:
	uint8                                         Pad_578[0x8];                                      // 0x0578(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0580(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	struct FAnimSubsystemInstance                 AnimBlueprintExtension_PropertyAccess;             // 0x0588(0x0008)()
	struct FAnimSubsystemInstance                 AnimBlueprintExtension_Base;                       // 0x0590(0x0008)()
	struct FAnimNode_Root                         AnimGraphNode_Root;                                // 0x0598(0x0020)()
	struct FAnimNode_CopyPoseFromMesh             AnimGraphNode_CopyPoseFromMesh;                    // 0x05B8(0x0188)(ContainsInstancedReference)
	struct FAnimNode_RigidBody                    AnimGraphNode_RigidBody_3;                         // 0x0740(0x07F0)()
	struct FAnimNode_ConvertLocalToComponentSpace AnimGraphNode_LocalToComponentSpace;               // 0x0F30(0x0020)()
	struct FAnimNode_ConvertComponentToLocalSpace AnimGraphNode_ComponentToLocalSpace;               // 0x0F50(0x0020)()
	struct FAnimNode_RigidBody                    AnimGraphNode_RigidBody_2;                         // 0x0F70(0x07F0)()
	struct FAnimNode_RigidBody                    AnimGraphNode_RigidBody_1;                         // 0x1760(0x07F0)()
	struct FAnimNode_Constraint                   AnimGraphNode_Constraint_1;                        // 0x1F50(0x0108)()
	struct FAnimNode_ModifyBone                   AnimGraphNode_ModifyBone_5;                        // 0x2058(0x0108)()
	struct FAnimNode_ModifyBone                   AnimGraphNode_ModifyBone_4;                        // 0x2160(0x0108)()
	uint8                                         Pad_2268[0x8];                                     // 0x2268(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FAnimNode_RigidBody                    AnimGraphNode_RigidBody;                           // 0x2270(0x07F0)()
	struct FAnimNode_ModifyBone                   AnimGraphNode_ModifyBone_3;                        // 0x2A60(0x0108)()
	struct FAnimNode_ModifyBone                   AnimGraphNode_ModifyBone_2;                        // 0x2B68(0x0108)()
	struct FAnimNode_ModifyBone                   AnimGraphNode_ModifyBone_1;                        // 0x2C70(0x0108)()
	struct FAnimNode_ModifyBone                   AnimGraphNode_ModifyBone;                          // 0x2D78(0x0108)()
	struct FAnimNode_Constraint                   AnimGraphNode_Constraint;                          // 0x2E80(0x0108)()
	class USkeletalMeshComponent*                 Skel_mesh;                                         // 0x2F88(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Thigh_rot_r;                                       // 0x2F90(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Thigh_rot_l;                                       // 0x2F94(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Head_rot_up;                                       // 0x2F98(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Head_rot_down;                                     // 0x2F9C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void AnimGraph(struct FPoseLink* Param_AnimGraph);
	void BlueprintInitializeAnimation();
	void BlueprintUpdateAnimation(float DeltaTimeX);
	void ExecuteUbergraph_F_MED_Lollipop_AnimBP(int32 EntryPoint);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"F_MED_Lollipop_AnimBP_C">();
	}
	static class UF_MED_Lollipop_AnimBP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UF_MED_Lollipop_AnimBP_C>();
	}
};

}

