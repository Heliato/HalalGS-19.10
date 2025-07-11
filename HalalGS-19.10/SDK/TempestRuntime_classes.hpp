#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TempestRuntime

#include "Basic.hpp"

#include "TempestRuntime_structs.hpp"
#include "FortniteGame_classes.hpp"
#include "GameplayAbilities_structs.hpp"
#include "ModularGameplay_classes.hpp"


namespace SDK
{

// Class TempestRuntime.FortAIControllerComponent_Tempest
// 0x0018 (0x00C8 - 0x00B0)
class UFortAIControllerComponent_Tempest final : public UFortControllerComponent
{
public:
	class UFortTimeOfDayWeatherComponent*         WeatherComponent;                                  // 0x00B0(0x0008)(ExportObject, ZeroConstructor, Transient, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	uint8                                         Pad_B8[0x10];                                      // 0x00B8(0x0010)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"FortAIControllerComponent_Tempest">();
	}
	static class UFortAIControllerComponent_Tempest* GetDefaultObj()
	{
		return GetDefaultObjImpl<UFortAIControllerComponent_Tempest>();
	}
};

// Class TempestRuntime.FortCheatManager_Tempest
// 0x0000 (0x0028 - 0x0028)
class UFortCheatManager_Tempest final : public UChildCheatManager
{
public:
	void EndTempestStorm(const class FString& StormName);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"FortCheatManager_Tempest">();
	}
	static class UFortCheatManager_Tempest* GetDefaultObj()
	{
		return GetDefaultObjImpl<UFortCheatManager_Tempest>();
	}
};

// Class TempestRuntime.TempestMovementComponent
// 0x00E0 (0x0190 - 0x00B0)
class UTempestMovementComponent final : public UGameFrameworkComponent
{
public:
	struct FTempestReplicatedMovementData         MovementData;                                      // 0x00B0(0x0030)(Net, RepNotify, NoDestructor, NativeAccessSpecifierPrivate)
	FMulticastInlineDelegateProperty_             OnTempestMovementStuck;                            // 0x00E0(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPrivate)
	FMulticastInlineDelegateProperty_             OnTempestSafeZoneStateChanged;                     // 0x00F0(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPrivate)
	class UEnvQuery*                              FindNextMovementLocationQuery;                     // 0x0100(0x0008)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	struct FScalableFloat                         MovementSpeed;                                     // 0x0108(0x0028)(Edit, NativeAccessSpecifierPrivate)
	struct FScalableFloat                         RotationSpeed;                                     // 0x0130(0x0028)(Edit, NativeAccessSpecifierPrivate)
	uint8                                         bShouldIgnoreZMovement : 1;                        // 0x0158(0x0001)(BitIndex: 0x00, PropSize: 0x0001 (Edit, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate))
	uint8                                         BitPad_158_1 : 1;                                  // 0x0158(0x0001)(Fixing Bit-Field Size Between Bits [ Dumper-7 ])
	uint8                                         bFloatOnWater : 1;                                 // 0x0158(0x0001)(BitIndex: 0x02, PropSize: 0x0001 (Edit, NoDestructor, AdvancedDisplay, HasGetValueTypeHash, NativeAccessSpecifierPrivate))
	uint8                                         Pad_159[0x7];                                      // 0x0159(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FScalableFloat                         WaterTraceZOffset;                                 // 0x0160(0x0028)(Edit, AdvancedDisplay, NativeAccessSpecifierPrivate)
	uint8                                         Pad_188[0x8];                                      // 0x0188(0x0008)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	void OnRep_MovementData() const;

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"TempestMovementComponent">();
	}
	static class UTempestMovementComponent* GetDefaultObj()
	{
		return GetDefaultObjImpl<UTempestMovementComponent>();
	}
};

// Class TempestRuntime.TempestStateMachineComponent
// 0x00D0 (0x0180 - 0x00B0)
class alignas(0x10) UTempestStateMachineComponent final : public UGameFrameworkComponent
{
public:
	bool                                          bDestroyOnCompletion;                              // 0x00B0(0x0001)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	uint8                                         Pad_B1[0x7];                                       // 0x00B1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FScalableFloat                         FormationDuration;                                 // 0x00B8(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         ActiveDuration;                                    // 0x00E0(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         DissipationDuration;                               // 0x0108(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FTempestStateInfo                      CurrentStateInfo;                                  // 0x0130(0x000C)(Net, RepNotify, NoDestructor, NativeAccessSpecifierPrivate)
	uint8                                         Pad_13C[0x1C];                                     // 0x013C(0x001C)(Fixing Size After Last Property [ Dumper-7 ])
	FMulticastInlineDelegateProperty_             OnTempestStateChangedDelegate;                     // 0x0158(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPrivate)
	uint8                                         Pad_168[0x18];                                     // 0x0168(0x0018)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	void ForceDissipate(const class FString& InDissipationReason);
	void OnRep_CurrentStateInfo();

	ETempestState GetCurrentState() const;
	float GetCurrentStateCompletionPercentage() const;
	struct FTempestStateInfo GetCurrentStateInfo() const;

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"TempestStateMachineComponent">();
	}
	static class UTempestStateMachineComponent* GetDefaultObj()
	{
		return GetDefaultObjImpl<UTempestStateMachineComponent>();
	}
};

}

