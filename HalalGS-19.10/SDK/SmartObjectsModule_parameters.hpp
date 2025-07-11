#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SmartObjectsModule

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "SmartObjectsModule_structs.hpp"
#include "GameplayTags_structs.hpp"


namespace SDK::Params
{

// Function SmartObjectsModule.AITask_UseSmartObject.UseClaimedSmartObject
// 0x0020 (0x0020 - 0x0000)
struct AITask_UseSmartObject_UseClaimedSmartObject final
{
public:
	class AAIController*                          Controller;                                        // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FSmartObjectClaimHandle                ClaimHandle;                                       // 0x0008(0x000C)(Parm, NoDestructor, NativeAccessSpecifierPublic)
	bool                                          bLockAILogic;                                      // 0x0014(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_15[0x3];                                       // 0x0015(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UAITask_UseSmartObject*                 ReturnValue;                                       // 0x0018(0x0008)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function SmartObjectsModule.AITask_UseSmartObject.UseSmartObject
// 0x0028 (0x0028 - 0x0000)
struct AITask_UseSmartObject_UseSmartObject final
{
public:
	class AAIController*                          Controller;                                        // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class AActor*                                 SmartObjectActor;                                  // 0x0008(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class USmartObjectComponent*                  SmartObjectComponent;                              // 0x0010(0x0008)(Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bLockAILogic;                                      // 0x0018(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_19[0x7];                                       // 0x0019(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UAITask_UseSmartObject*                 ReturnValue;                                       // 0x0020(0x0008)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function SmartObjectsModule.SmartObjectBlueprintFunctionLibrary.GetValueAsSOClaimHandle
// 0x0020 (0x0020 - 0x0000)
struct SmartObjectBlueprintFunctionLibrary_GetValueAsSOClaimHandle final
{
public:
	class UBlackboardComponent*                   BlackboardComponent;                               // 0x0000(0x0008)(Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FName                                   KeyName;                                           // 0x0008(0x0008)(ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FSmartObjectClaimHandle                ReturnValue;                                       // 0x0010(0x000C)(Parm, OutParm, ReturnParm, NoDestructor, NativeAccessSpecifierPublic)
	uint8                                         Pad_1C[0x4];                                       // 0x001C(0x0004)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function SmartObjectsModule.SmartObjectBlueprintFunctionLibrary.IsValidSmartObjectClaimHandle
// 0x0010 (0x0010 - 0x0000)
struct SmartObjectBlueprintFunctionLibrary_IsValidSmartObjectClaimHandle final
{
public:
	struct FSmartObjectClaimHandle                Handle;                                            // 0x0000(0x000C)(ConstParm, Parm, NoDestructor, NativeAccessSpecifierPublic)
	bool                                          ReturnValue;                                       // 0x000C(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_D[0x3];                                        // 0x000D(0x0003)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function SmartObjectsModule.SmartObjectBlueprintFunctionLibrary.K2_AddLooseGameplayTags
// 0x0030 (0x0030 - 0x0000)
struct SmartObjectBlueprintFunctionLibrary_K2_AddLooseGameplayTags final
{
public:
	class AActor*                                 Actor;                                             // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FGameplayTagContainer                  GameplayTags;                                      // 0x0008(0x0020)(ConstParm, Parm, OutParm, ReferenceParm, NativeAccessSpecifierPublic)
	bool                                          ReturnValue;                                       // 0x0028(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_29[0x7];                                       // 0x0029(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function SmartObjectsModule.SmartObjectBlueprintFunctionLibrary.K2_RemoveLooseGameplayTags
// 0x0030 (0x0030 - 0x0000)
struct SmartObjectBlueprintFunctionLibrary_K2_RemoveLooseGameplayTags final
{
public:
	class AActor*                                 Actor;                                             // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FGameplayTagContainer                  GameplayTags;                                      // 0x0008(0x0020)(ConstParm, Parm, OutParm, ReferenceParm, NativeAccessSpecifierPublic)
	bool                                          ReturnValue;                                       // 0x0028(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_29[0x7];                                       // 0x0029(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function SmartObjectsModule.SmartObjectBlueprintFunctionLibrary.K2_SetSmartObjectEnabled
// 0x0010 (0x0010 - 0x0000)
struct SmartObjectBlueprintFunctionLibrary_K2_SetSmartObjectEnabled final
{
public:
	class AActor*                                 SmartObject;                                       // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bEnabled;                                          // 0x0008(0x0001)(ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          ReturnValue;                                       // 0x0009(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_A[0x6];                                        // 0x000A(0x0006)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function SmartObjectsModule.SmartObjectBlueprintFunctionLibrary.K2_UseSmartObject
// 0x0018 (0x0018 - 0x0000)
struct SmartObjectBlueprintFunctionLibrary_K2_UseSmartObject final
{
public:
	class AActor*                                 Avatar;                                            // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class AActor*                                 SmartObject;                                       // 0x0008(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          ReturnValue;                                       // 0x0010(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_11[0x7];                                       // 0x0011(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function SmartObjectsModule.SmartObjectBlueprintFunctionLibrary.SetValueAsSOClaimHandle
// 0x0020 (0x0020 - 0x0000)
struct SmartObjectBlueprintFunctionLibrary_SetValueAsSOClaimHandle final
{
public:
	class UBlackboardComponent*                   BlackboardComponent;                               // 0x0000(0x0008)(Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FName                                   KeyName;                                           // 0x0008(0x0008)(ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FSmartObjectClaimHandle                Value;                                             // 0x0010(0x000C)(Parm, NoDestructor, NativeAccessSpecifierPublic)
	uint8                                         Pad_1C[0x4];                                       // 0x001C(0x0004)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function SmartObjectsModule.SmartObjectSubsystem.Claim
// 0x0014 (0x0014 - 0x0000)
struct SmartObjectSubsystem_Claim final
{
public:
	struct FSmartObjectRequestResult              RequestResult;                                     // 0x0000(0x0008)(ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, NativeAccessSpecifierPublic)
	struct FSmartObjectClaimHandle                ReturnValue;                                       // 0x0008(0x000C)(Parm, OutParm, ReturnParm, NoDestructor, NativeAccessSpecifierPublic)
};

// Function SmartObjectsModule.SmartObjectSubsystem.FindSmartObject
// 0x00E0 (0x00E0 - 0x0000)
struct SmartObjectSubsystem_FindSmartObject final
{
public:
	struct FSmartObjectRequest                    Request;                                           // 0x0000(0x00D0)(ConstParm, Parm, OutParm, ReferenceParm, NativeAccessSpecifierPublic)
	struct FSmartObjectRequestResult              ReturnValue;                                       // 0x00D0(0x0008)(Parm, OutParm, ReturnParm, NoDestructor, NativeAccessSpecifierPublic)
	uint8                                         Pad_D8[0x8];                                       // 0x00D8(0x0008)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function SmartObjectsModule.SmartObjectSubsystem.FindSmartObjects
// 0x00F0 (0x00F0 - 0x0000)
struct SmartObjectSubsystem_FindSmartObjects final
{
public:
	struct FSmartObjectRequest                    Request;                                           // 0x0000(0x00D0)(ConstParm, Parm, OutParm, ReferenceParm, NativeAccessSpecifierPublic)
	TArray<struct FSmartObjectRequestResult>      OutResults;                                        // 0x00D0(0x0010)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
	bool                                          ReturnValue;                                       // 0x00E0(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_E1[0xF];                                       // 0x00E1(0x000F)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function SmartObjectsModule.SmartObjectSubsystem.Release
// 0x0010 (0x0010 - 0x0000)
struct SmartObjectSubsystem_Release final
{
public:
	struct FSmartObjectClaimHandle                ClaimHandle;                                       // 0x0000(0x000C)(ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, NativeAccessSpecifierPublic)
	bool                                          ReturnValue;                                       // 0x000C(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_D[0x3];                                        // 0x000D(0x0003)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function SmartObjectsModule.SmartObjectSubsystem.Use
// 0x0020 (0x0020 - 0x0000)
struct SmartObjectSubsystem_Use final
{
public:
	struct FSmartObjectClaimHandle                ClaimHandle;                                       // 0x0000(0x000C)(ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, NativeAccessSpecifierPublic)
	uint8                                         Pad_C[0x4];                                        // 0x000C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TSubclassOf<class USmartObjectBehaviorDefinition> DefinitionClass;                                   // 0x0010(0x0008)(ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	const class USmartObjectBehaviorDefinition*   ReturnValue;                                       // 0x0018(0x0008)(ConstParm, Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function SmartObjectsModule.SmartObjectSubsystem.GetSlotLocation
// 0x001C (0x001C - 0x0000)
struct SmartObjectSubsystem_GetSlotLocation final
{
public:
	struct FSmartObjectClaimHandle                ClaimHandle;                                       // 0x0000(0x000C)(ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, NativeAccessSpecifierPublic)
	struct FVector                                OutSlotLocation;                                   // 0x000C(0x000C)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          ReturnValue;                                       // 0x0018(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_19[0x3];                                       // 0x0019(0x0003)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function SmartObjectsModule.SmartObjectSubsystem.GetSlotTransform
// 0x0050 (0x0050 - 0x0000)
struct SmartObjectSubsystem_GetSlotTransform final
{
public:
	struct FSmartObjectClaimHandle                ClaimHandle;                                       // 0x0000(0x000C)(ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, NativeAccessSpecifierPublic)
	uint8                                         Pad_C[0x4];                                        // 0x000C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTransform                             OutSlotTransform;                                  // 0x0010(0x0030)(Parm, OutParm, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic)
	bool                                          ReturnValue;                                       // 0x0040(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_41[0xF];                                       // 0x0041(0x000F)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function SmartObjectsModule.SmartObjectSubsystem.GetSmartObjectComponent
// 0x0018 (0x0018 - 0x0000)
struct SmartObjectSubsystem_GetSmartObjectComponent final
{
public:
	struct FSmartObjectClaimHandle                ClaimHandle;                                       // 0x0000(0x000C)(ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, NativeAccessSpecifierPublic)
	uint8                                         Pad_C[0x4];                                        // 0x000C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class USmartObjectComponent*                  ReturnValue;                                       // 0x0010(0x0008)(ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

}

