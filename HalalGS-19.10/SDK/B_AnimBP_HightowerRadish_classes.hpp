#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: B_AnimBP_HightowerRadish

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "B_AnimBP_HightowerRadish_structs.hpp"
#include "AnimGraphRuntime_structs.hpp"
#include "FortniteGame_classes.hpp"


namespace SDK
{

// AnimBlueprintGeneratedClass B_AnimBP_HightowerRadish.B_AnimBP_HightowerRadish_C
// 0x4220 (0x49B0 - 0x0790)
class UB_AnimBP_HightowerRadish_C final : public UFortPetAnimInstance_HighTowerRadish
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0790(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	struct B_AnimBP_HightowerRadish::FAnimBlueprintGeneratedMutableData __AnimBlueprintMutables;                           // 0x0798(0x0058)(HasGetValueTypeHash)
	struct FAnimSubsystemInstance                 AnimBlueprintExtension_PropertyAccess;             // 0x07F0(0x0008)()
	struct FAnimSubsystemInstance                 AnimBlueprintExtension_Base;                       // 0x07F8(0x0008)()
	struct FAnimNode_Root                         AnimGraphNode_Root;                                // 0x0800(0x0020)()
	struct FAnimNode_ConvertLocalToComponentSpace AnimGraphNode_LocalToComponentSpace_1;             // 0x0820(0x0020)()
	struct FAnimNode_ModifyBone                   AnimGraphNode_ModifyBone_4;                        // 0x0840(0x0108)()
	struct FAnimNode_ModifyBone                   AnimGraphNode_ModifyBone_3;                        // 0x0948(0x0108)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_52;                 // 0x0A50(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_51;                 // 0x0A78(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_50;                 // 0x0AA0(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_49;                 // 0x0AC8(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_48;                 // 0x0AF0(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_47;                 // 0x0B18(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_46;                 // 0x0B40(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_45;                 // 0x0B68(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_44;                 // 0x0B90(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_43;                 // 0x0BB8(0x0028)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_42;                   // 0x0BE0(0x0040)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_33;                      // 0x0C20(0x0020)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_7;                  // 0x0C40(0x0118)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_41;                   // 0x0D58(0x0040)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive_11;                    // 0x0D98(0x00C8)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_32;                      // 0x0E60(0x0020)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_42;                 // 0x0E80(0x0028)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_40;                   // 0x0EA8(0x0040)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_31;                      // 0x0EE8(0x0020)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_39;                   // 0x0F08(0x0040)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_30;                      // 0x0F48(0x0020)()
	struct FAnimNode_StateMachine                 AnimGraphNode_StateMachine_7;                      // 0x0F68(0x00B8)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_29;                      // 0x1020(0x0020)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_41;                 // 0x1040(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_40;                 // 0x1068(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_39;                 // 0x1090(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_38;                 // 0x10B8(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_37;                 // 0x10E0(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_36;                 // 0x1108(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_35;                 // 0x1130(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_34;                 // 0x1158(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_33;                 // 0x1180(0x0028)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_38;                   // 0x11A8(0x0040)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_28;                      // 0x11E8(0x0020)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_37;                   // 0x1208(0x0040)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_27;                      // 0x1248(0x0020)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_36;                   // 0x1268(0x0040)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_26;                      // 0x12A8(0x0020)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_35;                   // 0x12C8(0x0040)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_25;                      // 0x1308(0x0020)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_34;                   // 0x1328(0x0040)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_24;                      // 0x1368(0x0020)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_33;                   // 0x1388(0x0040)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_23;                      // 0x13C8(0x0020)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_32;                   // 0x13E8(0x0040)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive_10;                    // 0x1428(0x00C8)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_6;                  // 0x14F0(0x0118)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_22;                      // 0x1608(0x0020)()
	struct FAnimNode_StateMachine                 AnimGraphNode_StateMachine_6;                      // 0x1628(0x00B8)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_21;                      // 0x16E0(0x0020)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_31;                   // 0x1700(0x0040)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_20;                      // 0x1740(0x0020)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_30;                   // 0x1760(0x0040)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_19;                      // 0x17A0(0x0020)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_32;                 // 0x17C0(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_31;                 // 0x17E8(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_30;                 // 0x1810(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_29;                 // 0x1838(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_28;                 // 0x1860(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_27;                 // 0x1888(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_26;                 // 0x18B0(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_25;                 // 0x18D8(0x0028)()
	struct FAnimNode_TwoWayBlend                  AnimGraphNode_TwoWayBlend;                         // 0x1900(0x00C8)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_29;                   // 0x19C8(0x0040)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_28;                   // 0x1A08(0x0040)()
	struct FAnimNode_ApplyMeshSpaceAdditive       AnimGraphNode_ApplyMeshSpaceAdditive_3;            // 0x1A48(0x00D0)()
	struct FAnimNode_BlendListByBool              AnimGraphNode_BlendListByBool_6;                   // 0x1B18(0x0088)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_27;                   // 0x1BA0(0x0040)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_26;                   // 0x1BE0(0x0040)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_18;                      // 0x1C20(0x0020)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_24;                 // 0x1C40(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_23;                 // 0x1C68(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_22;                 // 0x1C90(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_21;                 // 0x1CB8(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_20;                 // 0x1CE0(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_19;                 // 0x1D08(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_18;                 // 0x1D30(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_17;                 // 0x1D58(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_16;                 // 0x1D80(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_15;                 // 0x1DA8(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_14;                 // 0x1DD0(0x0028)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_25;                   // 0x1DF8(0x0040)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive_9;                     // 0x1E38(0x00C8)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_5;                  // 0x1F00(0x0118)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive_8;                     // 0x2018(0x00C8)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_4;                  // 0x20E0(0x0118)()
	struct FAnimNode_BlendListByInt               AnimGraphNode_BlendListByInt;                      // 0x21F8(0x0088)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_24;                   // 0x2280(0x0040)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_17;                      // 0x22C0(0x0020)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive_7;                     // 0x22E0(0x00C8)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_3;                  // 0x23A8(0x0118)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_23;                   // 0x24C0(0x0040)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_16;                      // 0x2500(0x0020)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_22;                   // 0x2520(0x0040)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive_6;                     // 0x2560(0x00C8)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_21;                   // 0x2628(0x0040)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_15;                      // 0x2668(0x0020)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_20;                   // 0x2688(0x0040)()
	struct FAnimNode_BlendListByBool              AnimGraphNode_BlendListByBool_5;                   // 0x26C8(0x0088)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive_5;                     // 0x2750(0x00C8)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_2;                  // 0x2818(0x0118)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive_4;                     // 0x2930(0x00C8)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_1;                  // 0x29F8(0x0118)()
	struct FAnimNode_ApplyMeshSpaceAdditive       AnimGraphNode_ApplyMeshSpaceAdditive_2;            // 0x2B10(0x00D0)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_19;                   // 0x2BE0(0x0040)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_18;                   // 0x2C20(0x0040)()
	struct FAnimNode_RefPose                      AnimGraphNode_IdentityPose;                        // 0x2C60(0x0010)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_17;                   // 0x2C70(0x0040)()
	struct FAnimNode_BlendListByBool              AnimGraphNode_BlendListByBool_4;                   // 0x2CB0(0x0088)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive_3;                     // 0x2D38(0x00C8)()
	struct FAnimNode_BlendListByBool              AnimGraphNode_BlendListByBool_3;                   // 0x2E00(0x0088)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive_2;                     // 0x2E88(0x00C8)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer;                    // 0x2F50(0x0118)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_16;                   // 0x3068(0x0040)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_14;                      // 0x30A8(0x0020)()
	struct FAnimNode_StateMachine                 AnimGraphNode_StateMachine_5;                      // 0x30C8(0x00B8)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_13;                      // 0x3180(0x0020)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_15;                   // 0x31A0(0x0040)()
	struct FAnimNode_ApplyMeshSpaceAdditive       AnimGraphNode_ApplyMeshSpaceAdditive_1;            // 0x31E0(0x00D0)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_14;                   // 0x32B0(0x0040)()
	struct FAnimNode_BlendListByBool              AnimGraphNode_BlendListByBool_2;                   // 0x32F0(0x0088)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_13;                   // 0x3378(0x0040)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_12;                      // 0x33B8(0x0020)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_13;                 // 0x33D8(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_12;                 // 0x3400(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_11;                 // 0x3428(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_10;                 // 0x3450(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_9;                  // 0x3478(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_8;                  // 0x34A0(0x0028)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_12;                   // 0x34C8(0x0040)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_11;                      // 0x3508(0x0020)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_11;                   // 0x3528(0x0040)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive_1;                     // 0x3568(0x00C8)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_10;                   // 0x3630(0x0040)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_10;                      // 0x3670(0x0020)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_9;                    // 0x3690(0x0040)()
	struct FAnimNode_BlendListByBool              AnimGraphNode_BlendListByBool_1;                   // 0x36D0(0x0088)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_8;                    // 0x3758(0x0040)()
	struct FAnimNode_ApplyMeshSpaceAdditive       AnimGraphNode_ApplyMeshSpaceAdditive;              // 0x3798(0x00D0)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_7;                    // 0x3868(0x0040)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_9;                       // 0x38A8(0x0020)()
	struct FAnimNode_StateMachine                 AnimGraphNode_StateMachine_4;                      // 0x38C8(0x00B8)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_8;                       // 0x3980(0x0020)()
	struct FAnimNode_StateMachine                 AnimGraphNode_StateMachine_3;                      // 0x39A0(0x00B8)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_7;                       // 0x3A58(0x0020)()
	struct FAnimNode_StateMachine                 AnimGraphNode_StateMachine_2;                      // 0x3A78(0x00B8)()
	struct FAnimNode_CopyBone                     AnimGraphNode_CopyBone_1;                          // 0x3B30(0x00F0)()
	struct FAnimNode_ConvertComponentToLocalSpace AnimGraphNode_ComponentToLocalSpace_1;             // 0x3C20(0x0020)()
	struct FAnimNode_SaveCachedPose               AnimGraphNode_SaveCachedPose;                      // 0x3C40(0x0108)()
	struct FAnimNode_UseCachedPose                AnimGraphNode_UseCachedPose;                       // 0x3D48(0x0028)()
	struct FAnimNode_ConvertLocalToComponentSpace AnimGraphNode_LocalToComponentSpace;               // 0x3D70(0x0020)()
	struct FAnimNode_BlendListByBool              AnimGraphNode_BlendListByBool;                     // 0x3D90(0x0088)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_7;                  // 0x3E18(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_6;                  // 0x3E40(0x0028)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_6;                    // 0x3E68(0x0040)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_5;                    // 0x3EA8(0x0040)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive;                       // 0x3EE8(0x00C8)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_6;                       // 0x3FB0(0x0020)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_5;                  // 0x3FD0(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_4;                  // 0x3FF8(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_3;                  // 0x4020(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_2;                  // 0x4048(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_1;                  // 0x4070(0x0028)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult;                    // 0x4098(0x0028)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_4;                    // 0x40C0(0x0040)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_5;                       // 0x4100(0x0020)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_3;                    // 0x4120(0x0040)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_4;                       // 0x4160(0x0020)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_2;                    // 0x4180(0x0040)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_3;                       // 0x41C0(0x0020)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_1;                    // 0x41E0(0x0040)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_2;                       // 0x4220(0x0020)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer;                      // 0x4240(0x0040)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_1;                       // 0x4280(0x0020)()
	struct FAnimNode_StateMachine                 AnimGraphNode_StateMachine_1;                      // 0x42A0(0x00B8)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult;                         // 0x4358(0x0020)()
	struct FAnimNode_StateMachine                 AnimGraphNode_StateMachine;                        // 0x4378(0x00B8)()
	struct FAnimNode_LegIK                        AnimGraphNode_LegIK;                               // 0x4430(0x00F8)()
	struct FAnimNode_ModifyBone                   AnimGraphNode_ModifyBone_2;                        // 0x4528(0x0108)()
	struct FAnimNode_CopyBone                     AnimGraphNode_CopyBone;                            // 0x4630(0x00F0)()
	struct FAnimNode_ConvertComponentToLocalSpace AnimGraphNode_ComponentToLocalSpace;               // 0x4720(0x0020)()
	struct FAnimNode_Slot                         AnimGraphNode_Slot;                                // 0x4740(0x0048)()
	struct FAnimNode_ModifyBone                   AnimGraphNode_ModifyBone_1;                        // 0x4788(0x0108)()
	struct FAnimNode_ModifyBone                   AnimGraphNode_ModifyBone;                          // 0x4890(0x0108)()
	bool                                          bStoppedMovingOrMeleeForLongEnoughTime;            // 0x4998(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bSharpDirectionChange;                             // 0x4999(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bHighTowerRadish_LobbySkyDive_Diving;              // 0x499A(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bHighTowerRadish_LobbySkyDive_Gliding;             // 0x499B(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bFrontEndIdleTransition;                           // 0x499C(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bIsPlayingMeleeAnimLastTick;                       // 0x499D(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_499E[0x2];                                     // 0x499E(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         RandomLocomotionBreak;                             // 0x49A0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bAllowRandomLocomotionBreak;                       // 0x49A4(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bHasTargettedInLastNSeconds;                       // 0x49A5(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_49A6[0x2];                                     // 0x49A6(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         IsDBNOCarriedAlpha;                                // 0x49A8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void AnimGraph(struct FPoseLink* Param_AnimGraph);
	void AnimNotify_BwdToFwd_Entered();
	void AnimNotify_FwdToBwd_Entered();
	void AnimNotify_MoveLoopRandomEntered();
	void AnimNotify_RandomIdlePick();
	void AnimNotify_TriggerRandomizer();
	void BlueprintUpdateAnimation(float DeltaTimeX);
	void EvaluateGraphExposedInputs_ExecuteUbergraph_B_AnimBP_HightowerRadish_AnimGraphNode_TransitionResult_7063B86B4BA21930F893DBA578CF6DAD();
	void ExecuteUbergraph_B_AnimBP_HightowerRadish(int32 EntryPoint);
	void HighTowerRadish_Lobby_SkyDive_Diving();
	void HighTowerRadish_Lobby_SkyDive_Gliding();
	void OnEnteredVehicle();
	void OnExitedVehicle();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"B_AnimBP_HightowerRadish_C">();
	}
	static class UB_AnimBP_HightowerRadish_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UB_AnimBP_HightowerRadish_C>();
	}
};

}

