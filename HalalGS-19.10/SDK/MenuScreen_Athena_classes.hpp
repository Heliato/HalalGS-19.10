#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: MenuScreen_Athena

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "AnimGraphRuntime_structs.hpp"
#include "MenuScreen_Athena_structs.hpp"
#include "FortniteGame_classes.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK
{

// AnimBlueprintGeneratedClass MenuScreen_Athena.MenuScreen_Athena_C
// 0x8C90 (0x94D0 - 0x0840)
class UMenuScreen_Athena_C final : public UFrontendAnimInstance
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0840(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	struct MenuScreen_Athena::FAnimBlueprintGeneratedMutableData __AnimBlueprintMutables;                           // 0x0848(0x0458)(HasGetValueTypeHash)
	struct FAnimSubsystemInstance                 AnimBlueprintExtension_PropertyAccess;             // 0x0CA0(0x0008)()
	struct FAnimSubsystemInstance                 AnimBlueprintExtension_Base;                       // 0x0CA8(0x0008)()
	struct FAnimNode_LegIK                        AnimGraphNode_LegIK_2;                             // 0x0CB0(0x00F8)()
	struct FAnimNode_CopyBone                     AnimGraphNode_CopyBone_5;                          // 0x0DA8(0x00F0)()
	struct FAnimNode_CopyBone                     AnimGraphNode_CopyBone_4;                          // 0x0E98(0x00F0)()
	struct FAnimNode_CopyBone                     AnimGraphNode_CopyBone_3;                          // 0x0F88(0x00F0)()
	struct FAnimNode_Slot                         AnimGraphNode_Slot_3;                              // 0x1078(0x0048)()
	struct FAnimNode_CopyBone                     AnimGraphNode_CopyBone_2;                          // 0x10C0(0x00F0)()
	struct FAnimNode_ModifyBone                   AnimGraphNode_ModifyBone_3;                        // 0x11B0(0x0108)()
	struct FAnimNode_LegIK                        AnimGraphNode_LegIK_1;                             // 0x12B8(0x00F8)()
	struct FAnimNode_LegIK                        AnimGraphNode_LegIK;                               // 0x13B0(0x00F8)()
	struct FAnimNode_CopyBone                     AnimGraphNode_CopyBone_1;                          // 0x14A8(0x00F0)()
	struct FAnimNode_CopyBone                     AnimGraphNode_CopyBone;                            // 0x1598(0x00F0)()
	struct FAnimNode_ModifyBone                   AnimGraphNode_ModifyBone_2;                        // 0x1688(0x0108)()
	struct FAnimNode_ConvertComponentToLocalSpace AnimGraphNode_ComponentToLocalSpace;               // 0x1790(0x0020)()
	struct FAnimNode_ModifyCurve                  AnimGraphNode_ModifyCurve;                         // 0x17B0(0x0100)()
	struct FAnimNode_Root                         AnimGraphNode_Root;                                // 0x18B0(0x0020)()
	struct FAnimNode_ModifyBone                   AnimGraphNode_ModifyBone_1;                        // 0x18D0(0x0108)()
	struct FAnimNode_ModifyBone                   AnimGraphNode_ModifyBone;                          // 0x19D8(0x0108)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_16;                   // 0x1AE0(0x0040)()
	struct FAnimNode_BlendListByInt               AnimGraphNode_BlendListByInt_3;                    // 0x1B20(0x0088)()
	struct FAnimNode_BlendListByInt               AnimGraphNode_BlendListByInt_2;                    // 0x1BA8(0x0088)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_15;                   // 0x1C30(0x0040)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_14;                   // 0x1C70(0x0040)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_13;                   // 0x1CB0(0x0040)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_12;                   // 0x1CF0(0x0040)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_34;                  // 0x1D30(0x0088)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_33;                  // 0x1DB8(0x0088)()
	struct FAnimNode_BlendListByInt               AnimGraphNode_BlendListByInt_1;                    // 0x1E40(0x0088)()
	struct FAnimNode_BlendListByInt               AnimGraphNode_BlendListByInt;                      // 0x1EC8(0x0088)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_11;                   // 0x1F50(0x0040)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_10;                   // 0x1F90(0x0040)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_9;                    // 0x1FD0(0x0040)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_8;                    // 0x2010(0x0040)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_32;                  // 0x2050(0x0088)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_16;                      // 0x20D8(0x0020)()
	struct FAnimNode_StateMachine                 AnimGraphNode_StateMachine_13;                     // 0x20F8(0x00B8)()
	struct FAnimNode_BlendListByBool              AnimGraphNode_BlendListByBool_2;                   // 0x21B0(0x0088)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_7;                    // 0x2238(0x0040)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_6;                    // 0x2278(0x0040)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive_15;                    // 0x22B8(0x00C8)()
	struct FAnimNode_BlendListByBool              AnimGraphNode_BlendListByBool_1;                   // 0x2380(0x0088)()
	struct FAnimNode_SaveCachedPose               AnimGraphNode_SaveCachedPose_3;                    // 0x2408(0x0108)()
	struct FAnimNode_Inertialization              AnimGraphNode_Inertialization;                     // 0x2510(0x00D0)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_2;                  // 0x25E0(0x0028)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_56;                 // 0x2608(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_55;                 // 0x2720(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_54;                 // 0x2838(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_53;                 // 0x2950(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_52;                 // 0x2A68(0x0118)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_31;                  // 0x2B80(0x0088)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_30;                  // 0x2C08(0x0088)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_29;                  // 0x2C90(0x0088)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_15;                      // 0x2D18(0x0020)()
	struct FAnimNode_StateMachine                 AnimGraphNode_StateMachine_12;                     // 0x2D38(0x00B8)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_51;                 // 0x2DF0(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_50;                 // 0x2F08(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_49;                 // 0x3020(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_48;                 // 0x3138(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_47;                 // 0x3250(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_46;                 // 0x3368(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_45;                 // 0x3480(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_44;                 // 0x3598(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_43;                 // 0x36B0(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_42;                 // 0x37C8(0x0118)()
	struct FAnimNode_TwoWayBlend                  AnimGraphNode_TwoWayBlend;                         // 0x38E0(0x00C8)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_28;                  // 0x39A8(0x0088)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_27;                  // 0x3A30(0x0088)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_26;                  // 0x3AB8(0x0088)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_25;                  // 0x3B40(0x0088)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_24;                  // 0x3BC8(0x0088)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_23;                  // 0x3C50(0x0088)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_14;                      // 0x3CD8(0x0020)()
	struct FAnimNode_StateMachine                 AnimGraphNode_StateMachine_11;                     // 0x3CF8(0x00B8)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive_14;                    // 0x3DB0(0x00C8)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive_13;                    // 0x3E78(0x00C8)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_41;                 // 0x3F40(0x0118)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_13;                      // 0x4058(0x0020)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_40;                 // 0x4078(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_39;                 // 0x4190(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_38;                 // 0x42A8(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_37;                 // 0x43C0(0x0118)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_22;                  // 0x44D8(0x0088)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_21;                  // 0x4560(0x0088)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_20;                  // 0x45E8(0x0088)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_36;                 // 0x4670(0x0118)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_12;                      // 0x4788(0x0020)()
	struct FAnimNode_StateMachine                 AnimGraphNode_StateMachine_10;                     // 0x47A8(0x00B8)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_35;                 // 0x4860(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_34;                 // 0x4978(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_33;                 // 0x4A90(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_32;                 // 0x4BA8(0x0118)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_19;                  // 0x4CC0(0x0088)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_18;                  // 0x4D48(0x0088)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_31;                 // 0x4DD0(0x0118)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_17;                  // 0x4EE8(0x0088)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_11;                      // 0x4F70(0x0020)()
	struct FAnimNode_StateMachine                 AnimGraphNode_StateMachine_9;                      // 0x4F90(0x00B8)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive_12;                    // 0x5048(0x00C8)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_30;                 // 0x5110(0x0118)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive_11;                    // 0x5228(0x00C8)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_10;                      // 0x52F0(0x0020)()
	struct FAnimNode_StateMachine                 AnimGraphNode_StateMachine_8;                      // 0x5310(0x00B8)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive_10;                    // 0x53C8(0x00C8)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult_1;                  // 0x5490(0x0028)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_29;                 // 0x54B8(0x0118)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_9;                       // 0x55D0(0x0020)()
	struct FAnimNode_StateMachine                 AnimGraphNode_StateMachine_7;                      // 0x55F0(0x00B8)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive_9;                     // 0x56A8(0x00C8)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive_8;                     // 0x5770(0x00C8)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_5;                    // 0x5838(0x0040)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive_7;                     // 0x5878(0x00C8)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_28;                 // 0x5940(0x0118)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive_6;                     // 0x5A58(0x00C8)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_27;                 // 0x5B20(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_26;                 // 0x5C38(0x0118)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_8;                       // 0x5D50(0x0020)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive_5;                     // 0x5D70(0x00C8)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_25;                 // 0x5E38(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_24;                 // 0x5F50(0x0118)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_16;                  // 0x6068(0x0088)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive_4;                     // 0x60F0(0x00C8)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_23;                 // 0x61B8(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_22;                 // 0x62D0(0x0118)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_7;                       // 0x63E8(0x0020)()
	struct FAnimNode_StateMachine                 AnimGraphNode_StateMachine_6;                      // 0x6408(0x00B8)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_4;                    // 0x64C0(0x0040)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_3;                    // 0x6500(0x0040)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_2;                    // 0x6540(0x0040)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_1;                    // 0x6580(0x0040)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer;                      // 0x65C0(0x0040)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_15;                  // 0x6600(0x0088)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_14;                  // 0x6688(0x0088)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_13;                  // 0x6710(0x0088)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_6;                       // 0x6798(0x0020)()
	struct FAnimNode_StateMachine                 AnimGraphNode_StateMachine_5;                      // 0x67B8(0x00B8)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_12;                  // 0x6870(0x0088)()
	struct FAnimNode_TransitionResult             AnimGraphNode_TransitionResult;                    // 0x68F8(0x0028)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_21;                 // 0x6920(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_20;                 // 0x6A38(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_19;                 // 0x6B50(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_18;                 // 0x6C68(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_17;                 // 0x6D80(0x0118)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_11;                  // 0x6E98(0x0088)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_10;                  // 0x6F20(0x0088)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_9;                   // 0x6FA8(0x0088)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_5;                       // 0x7030(0x0020)()
	struct FAnimNode_StateMachine                 AnimGraphNode_StateMachine_4;                      // 0x7050(0x00B8)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_16;                 // 0x7108(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_15;                 // 0x7220(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_14;                 // 0x7338(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_13;                 // 0x7450(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_12;                 // 0x7568(0x0118)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_8;                   // 0x7680(0x0088)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_7;                   // 0x7708(0x0088)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_6;                   // 0x7790(0x0088)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_4;                       // 0x7818(0x0020)()
	struct FAnimNode_StateMachine                 AnimGraphNode_StateMachine_3;                      // 0x7838(0x00B8)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive_3;                     // 0x78F0(0x00C8)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive_2;                     // 0x79B8(0x00C8)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_11;                 // 0x7A80(0x0118)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_3;                       // 0x7B98(0x0020)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_10;                 // 0x7BB8(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_9;                  // 0x7CD0(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_8;                  // 0x7DE8(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_7;                  // 0x7F00(0x0118)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_5;                   // 0x8018(0x0088)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_4;                   // 0x80A0(0x0088)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_6;                  // 0x8128(0x0118)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_3;                   // 0x8240(0x0088)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_2;                       // 0x82C8(0x0020)()
	struct FAnimNode_StateMachine                 AnimGraphNode_StateMachine_2;                      // 0x82E8(0x00B8)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_5;                  // 0x83A0(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_4;                  // 0x84B8(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_3;                  // 0x85D0(0x0118)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_2;                  // 0x86E8(0x0118)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_2;                   // 0x8800(0x0088)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum_1;                   // 0x8888(0x0088)()
	struct FAnimNode_BlendListByEnum              AnimGraphNode_BlendListByEnum;                     // 0x8910(0x0088)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer_1;                  // 0x8998(0x0118)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult_1;                       // 0x8AB0(0x0020)()
	struct FAnimNode_StateMachine                 AnimGraphNode_StateMachine_1;                      // 0x8AD0(0x00B8)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive_1;                     // 0x8B88(0x00C8)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer;                    // 0x8C50(0x0118)()
	struct FAnimNode_ApplyAdditive                AnimGraphNode_ApplyAdditive;                       // 0x8D68(0x00C8)()
	struct FAnimNode_StateResult                  AnimGraphNode_StateResult;                         // 0x8E30(0x0020)()
	struct FAnimNode_StateMachine                 AnimGraphNode_StateMachine;                        // 0x8E50(0x00B8)()
	struct FAnimNode_SaveCachedPose               AnimGraphNode_SaveCachedPose_2;                    // 0x8F08(0x0108)()
	struct FAnimNode_SaveCachedPose               AnimGraphNode_SaveCachedPose_1;                    // 0x9010(0x0108)()
	struct FAnimNode_UseCachedPose                AnimGraphNode_UseCachedPose_4;                     // 0x9118(0x0028)()
	struct FAnimNode_UseCachedPose                AnimGraphNode_UseCachedPose_3;                     // 0x9140(0x0028)()
	struct FAnimNode_Slot                         AnimGraphNode_Slot_2;                              // 0x9168(0x0048)()
	struct FAnimNode_UseCachedPose                AnimGraphNode_UseCachedPose_2;                     // 0x91B0(0x0028)()
	struct FAnimNode_Slot                         AnimGraphNode_Slot_1;                              // 0x91D8(0x0048)()
	struct FAnimNode_UseCachedPose                AnimGraphNode_UseCachedPose_1;                     // 0x9220(0x0028)()
	struct FAnimNode_Slot                         AnimGraphNode_Slot;                                // 0x9248(0x0048)()
	struct FAnimNode_ConvertLocalToComponentSpace AnimGraphNode_LocalToComponentSpace;               // 0x9290(0x0020)()
	struct FAnimNode_BlendListByBool              AnimGraphNode_BlendListByBool;                     // 0x92B0(0x0088)()
	struct FAnimNode_UseCachedPose                AnimGraphNode_UseCachedPose;                       // 0x9338(0x0028)()
	struct FAnimNode_SaveCachedPose               AnimGraphNode_SaveCachedPose;                      // 0x9360(0x0108)()
	FMulticastInlineDelegateProperty_             MenuScreenDispatcher;                              // 0x9468(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)
	bool                                          IsSkydiveDiving;                                   // 0x9478(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          HasBeenSelected;                                   // 0x9479(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_947A[0x2];                                     // 0x947A(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         PoseInt;                                           // 0x947C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                OffsetTranslate;                                   // 0x9480(0x000C)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FRotator                               OffsetRotate;                                      // 0x948C(0x000C)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	class APlayerPawn_Athena_C*                   PawnOwner;                                         // 0x9498(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         StartTime;                                         // 0x94A0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         PlayRate;                                          // 0x94A4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         HidePropTimeRemaining;                             // 0x94A8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          HidePropBones;                                     // 0x94AC(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          HasWeaponEquipped;                                 // 0x94AD(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_94AE[0x2];                                     // 0x94AE(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	class AFortWeapon*                            Equipped_Weapon;                                   // 0x94B0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAnimMontage*                           Current_Idle_Montage;                              // 0x94B8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Skydive_Aim_Yaw;                                   // 0x94C0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Skydive_Aim_Pitch;                                 // 0x94C4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         WeaponHandPose;                                    // 0x94C8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          OneHandedWeapon;                                   // 0x94CC(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Dual;                                              // 0x94CD(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void AnimGraph(struct FPoseLink* Param_AnimGraph);
	void AnimNotify_LeftB();
	void AnimNotify_LobbySkydive_Diving();
	void AnimNotify_LobbySkydive_Gliding();
	void AnimNotify_playFacialAnim();
	void BlueprintInitializeAnimation();
	void BlueprintUpdateAnimation(float DeltaTimeX);
	void CalculateMontagePlayTiming();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_MenuScreen_Athena_AnimGraphNode_BlendListByBool_846B1F144FCC62C0860150BBCD95C2E8();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_MenuScreen_Athena_AnimGraphNode_TransitionResult_2E3328A94B338669440FEBAFF4C036E7();
	void ExecuteUbergraph_MenuScreen_Athena(int32 EntryPoint);
	void HidePropsForBlend(class UAnimMontage* NewMontage);
	void MenuScreenDispatcher__DelegateSignature();
	void OnFocusedItemChanged(const class UFortItemDefinition* FocusedItem, const class AFortWeapon* EquippedWeapon, const class AFortPlayerParachute* CurrentParachute);
	void OnMontageBlendingOut_Event_HideProps(class UAnimMontage* Montage, bool bInterrupted);
	void OnMontageStarted_Event_HideProps(class UAnimMontage* Montage);
	void UserFocus();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"MenuScreen_Athena_C">();
	}
	static class UMenuScreen_Athena_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UMenuScreen_Athena_C>();
	}
};

}

