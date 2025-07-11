#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ValetRuntime

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "CoreUObject_structs.hpp"
#include "FortniteGame_structs.hpp"
#include "GameplayTags_structs.hpp"


namespace SDK
{

// Enum ValetRuntime.ETireStates
// NumValues: 0x0003
enum class ETireStates : uint8
{
	Default                                  = 0,
	Popped                                   = 1,
	ETireStates_MAX                          = 2,
};

// Enum ValetRuntime.ETireSurfaces
// NumValues: 0x0006
enum class ETireSurfaces : uint8
{
	Road                                     = 0,
	Dirt                                     = 1,
	Grass                                    = 2,
	Air                                      = 3,
	Water                                    = 4,
	ETireSurfaces_MAX                        = 5,
};

// Enum ValetRuntime.EFortDagwoodSimEvent
// NumValues: 0x0009
enum class EFortDagwoodSimEvent : uint8
{
	EnterLandscape                           = 0,
	ExitLandscape                            = 1,
	EnterRoad                                = 2,
	ExitRoad                                 = 3,
	Explode                                  = 4,
	FlipImpact                               = 5,
	StartBoost                               = 6,
	FinishBoost                              = 7,
	EFortDagwoodSimEvent_MAX                 = 8,
};

// Enum ValetRuntime.EControlsPrototypes
// NumValues: 0x0005
enum class EControlsPrototypes : uint8
{
	CameraSteering                           = 0,
	NonCameraSteering                        = 1,
	HybridCameraSteering                     = 2,
	MaxCount                                 = 3,
	EControlsPrototypes_MAX                  = 4,
};

// Enum ValetRuntime.EPoppedTireReactionStates
// NumValues: 0x0008
enum class EPoppedTireReactionStates : uint8
{
	None                                     = 0,
	VeerLeft                                 = 1,
	VeerRight                                = 2,
	Wiggle                                   = 3,
	Yaw90                                    = 4,
	FlipPitch                                = 5,
	FlipRoll                                 = 6,
	EPoppedTireReactionStates_MAX            = 7,
};

// Enum ValetRuntime.ETireLocations
// NumValues: 0x0005
enum class ETireLocations : uint8
{
	FrontRight                               = 0,
	FrontLeft                                = 1,
	BackRight                                = 2,
	BackLeft                                 = 3,
	ETireLocations_MAX                       = 4,
};

// Enum ValetRuntime.EVehicleClass
// NumValues: 0x0005
enum class EVehicleClass : uint8
{
	Sedan                                    = 0,
	Sport                                    = 1,
	PickupTruck                              = 2,
	SemiTruck                                = 3,
	EVehicleClass_MAX                        = 4,
};

// ScriptStruct ValetRuntime.FortDagwoodCmd
// 0x001C (0x001C - 0x0000)
struct FFortDagwoodCmd final
{
public:
	float                                         ForwardAlpha;                                      // 0x0000(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         RightAlpha;                                        // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         AccelerationAlpha;                                 // 0x0008(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVector_NetQuantize100                 MovementDir;                                       // 0x000C(0x000C)(NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         bBoost : 1;                                        // 0x0018(0x0001)(BitIndex: 0x00, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         bHandbrake : 1;                                    // 0x0018(0x0001)(BitIndex: 0x01, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         Pad_19[0x3];                                       // 0x0019(0x0003)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct ValetRuntime.DagwoodInternal
// 0x0098 (0x00F0 - 0x0058)
struct FDagwoodInternal final : public FFortVehicleInternalPersistent
{
public:
	uint8                                         Pad_58[0x98];                                      // 0x0058(0x0098)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct ValetRuntime.DagwoodOutPersistent
// 0x0018 (0x0028 - 0x0010)
struct FDagwoodOutPersistent final : public FFortVehicleOutPersistent
{
public:
	bool                                          bOnRoad;                                           // 0x0010(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bOnLandscape;                                      // 0x0011(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bOnDirt;                                           // 0x0012(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bOnVehicle;                                        // 0x0013(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bBoosting;                                         // 0x0014(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_15[0x3];                                       // 0x0015(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<ETireSurfaces>                         TireSurfaces;                                      // 0x0018(0x0010)(ZeroConstructor, NativeAccessSpecifierPublic)
};

// ScriptStruct ValetRuntime.DagwoodOutContinuous
// 0x0010 (0x0038 - 0x0028)
struct FDagwoodOutContinuous final : public FFortVehicleOutContinuous
{
public:
	uint8                                         Pad_28[0x10];                                      // 0x0028(0x0010)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct ValetRuntime.DagwoodState_PT
// 0x0158 (0x0158 - 0x0000)
struct FDagwoodState_PT final
{
public:
	struct FDagwoodInternal                       Internal;                                          // 0x0000(0x00F0)(NativeAccessSpecifierPublic)
	struct FDagwoodOutPersistent                  OutPersistent;                                     // 0x00F0(0x0028)(NativeAccessSpecifierPublic)
	struct FDagwoodOutContinuous                  OutContinuous;                                     // 0x0118(0x0038)(NativeAccessSpecifierPublic)
	bool                                          bOutValid;                                         // 0x0150(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_151[0x7];                                      // 0x0151(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct ValetRuntime.RuntimeBoostInfo
// 0x0018 (0x0018 - 0x0000)
struct FRuntimeBoostInfo final
{
public:
	uint8                                         bCanBoost : 1;                                     // 0x0000(0x0001)(BitIndex: 0x00, PropSize: 0x0001 (Edit, BlueprintVisible, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         bUsesRechargeableBoost : 1;                        // 0x0000(0x0001)(BitIndex: 0x01, PropSize: 0x0001 (Edit, BlueprintVisible, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         Pad_1[0x3];                                        // 0x0001(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         BoostPushForce;                                    // 0x0004(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         BoostTopSpeedForceMultiplier;                      // 0x0008(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         BoostTopSpeedMultiplier;                           // 0x000C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         RechargeableBoostRateOfRegen;                      // 0x0010(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         RechargeableBoostRateOfUse;                        // 0x0014(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct ValetRuntime.RuntimeFuelInfo
// 0x000C (0x000C - 0x0000)
struct FRuntimeFuelInfo final
{
public:
	float                                         MaxFuel;                                           // 0x0000(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         FuelPerSecondDriving;                              // 0x0004(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         FuelPerSecondBoosting;                             // 0x0008(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct ValetRuntime.RuntimeGearInfo
// 0x0010 (0x0010 - 0x0000)
struct FRuntimeGearInfo final
{
public:
	int32                                         GearIndex;                                         // 0x0000(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         TopSpeed;                                          // 0x0004(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         MinSpeed;                                          // 0x0008(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         PushForce;                                         // 0x000C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct ValetRuntime.DagwoodRuntimeModifiers
// 0x0088 (0x0088 - 0x0000)
struct FDagwoodRuntimeModifiers final
{
public:
	struct FRuntimeBoostInfo                      BoostInfo;                                         // 0x0000(0x0018)(BlueprintVisible, Transient, NoDestructor, NativeAccessSpecifierPublic)
	struct FRuntimeFuelInfo                       FuelInfo;                                          // 0x0018(0x000C)(BlueprintVisible, Transient, NoDestructor, NativeAccessSpecifierPublic)
	struct FRuntimeSpringsInfo                    SpringsInfo;                                       // 0x0024(0x0020)(BlueprintVisible, Transient, NoDestructor, NativeAccessSpecifierPublic)
	bool                                          bDamageFriendlyVehicles;                           // 0x0044(0x0001)(BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bDamageOtherVehicles;                              // 0x0045(0x0001)(BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bDamageOwnVehicle;                                 // 0x0046(0x0001)(BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bDamageAllowedFromOtherVehicle;                    // 0x0047(0x0001)(BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         GravityMultiplier;                                 // 0x0048(0x0004)(BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         MaxInclineAngle;                                   // 0x004C(0x0004)(BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         MaxTiltAngle;                                      // 0x0050(0x0004)(BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_54[0x4];                                       // 0x0054(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FRuntimeGearInfo>               GearInfos;                                         // 0x0058(0x0010)(BlueprintVisible, ZeroConstructor, Transient, NativeAccessSpecifierPublic)
	struct FGameplayTag                           TireModTag;                                        // 0x0068(0x0008)(BlueprintVisible, Transient, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         TireModVersion;                                    // 0x0070(0x0001)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bTireModAdjustsPosition;                           // 0x0071(0x0001)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_72[0x2];                                       // 0x0072(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         SelfDestructTime;                                  // 0x0074(0x0004)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         MaxTimeExplosion;                                  // 0x0078(0x0004)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         MaxTimeZeroHealth;                                 // 0x007C(0x0004)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         MaxTimeSelfDestructCleanup;                        // 0x0080(0x0004)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         DataVersion;                                       // 0x0084(0x0001)(ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_85[0x3];                                       // 0x0085(0x0003)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct ValetRuntime.DagwoodInPersistent
// 0x00E8 (0x0230 - 0x0148)
struct FDagwoodInPersistent final : public FFortVehicleInPersistent
{
public:
	class UFortDagwoodVehicleConfigs*             FortDagwoodVehicleConfigs;                         // 0x0148(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FDagwoodRuntimeModifiers               DagwoodRuntimeModifiedProperties;                  // 0x0150(0x0088)(NativeAccessSpecifierPublic)
	TArray<ETireStates>                           TireStates;                                        // 0x01D8(0x0010)(ZeroConstructor, NativeAccessSpecifierPublic)
	uint8                                         Pad_1E8[0x48];                                     // 0x01E8(0x0048)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct ValetRuntime.ValetUpdateContext
// 0x0014 (0x0014 - 0x0000)
struct alignas(0x04) FValetUpdateContext final
{
public:
	uint8                                         Pad_0[0x14];                                       // 0x0000(0x0014)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct ValetRuntime.DagwoodFutureClientInput
// 0x0020 (0x0020 - 0x0000)
struct FDagwoodFutureClientInput final
{
public:
	int32                                         Frame;                                             // 0x0000(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FFortDagwoodCmd                        InputCmd;                                          // 0x0004(0x001C)(NoDestructor, NativeAccessSpecifierPublic)
};

// ScriptStruct ValetRuntime.DagwoodManagedState
// 0x03C8 (0x03C8 - 0x0000)
struct FDagwoodManagedState final
{
public:
	int32                                         Frame;                                             // 0x0000(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FFortDagwoodCmd                        InputCmd;                                          // 0x0004(0x001C)(NoDestructor, NativeAccessSpecifierPublic)
	struct FDagwoodInPersistent                   GT_State;                                          // 0x0020(0x0230)(NativeAccessSpecifierPublic)
	struct FDagwoodState_PT                       PT_State;                                          // 0x0250(0x0158)(NativeAccessSpecifierPublic)
	class APlayerController*                      PC;                                                // 0x03A8(0x0008)(ZeroConstructor, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_3B0[0x8];                                      // 0x03B0(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FDagwoodFutureClientInput>      FutureInputs;                                      // 0x03B8(0x0010)(ZeroConstructor, NativeAccessSpecifierPublic)
};

// ScriptStruct ValetRuntime.VehicleAttachment
// 0x0018 (0x0018 - 0x0000)
struct FVehicleAttachment final
{
public:
	class FName                                   ModName;                                           // 0x0000(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FName                                   SocketName;                                        // 0x0008(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class USkeletalMesh*                          SkeletalMesh;                                      // 0x0010(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct ValetRuntime.DagwoodActionDefForUI
// 0x0010 (0x0010 - 0x0000)
struct FDagwoodActionDefForUI final
{
public:
	TArray<struct FActionDefForUI>                ActionDefForUI;                                    // 0x0000(0x0010)(Edit, ZeroConstructor, NativeAccessSpecifierPublic)
};

// ScriptStruct ValetRuntime.TireSimulationRuntimeData
// 0x001C (0x001C - 0x0000)
struct FTireSimulationRuntimeData final
{
public:
	struct FRuntimeTerrainHandlingInfo            HandlingInfo;                                      // 0x0000(0x0010)(Transient, NoDestructor, NativeAccessSpecifierPublic)
	float                                         PoppedTireSpringLength;                            // 0x0010(0x0004)(BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         PoppedTireSpringStiff;                             // 0x0014(0x0004)(BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         PoppedTireSpringDamp;                              // 0x0018(0x0004)(BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct ValetRuntime.VehiclePropReplacementData
// 0x0040 (0x0040 - 0x0000)
struct FVehiclePropReplacementData final
{
public:
	TSoftObjectPtr<class UFortVehicleItemDefinition> FortVehicleItemDefinition;                         // 0x0000(0x0028)(Edit, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVector                                TransOffset;                                       // 0x0028(0x000C)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FRotator                               RotOffset;                                         // 0x0034(0x000C)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic)
};

}

