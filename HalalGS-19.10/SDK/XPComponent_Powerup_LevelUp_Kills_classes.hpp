#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: XPComponent_Powerup_LevelUp_Kills

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "GameplayAbilities_structs.hpp"
#include "GameplayTags_structs.hpp"
#include "FortniteGame_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass XPComponent_Powerup_LevelUp_Kills.XPComponent_Powerup_LevelUp_Kills_C
// 0x0038 (0x0100 - 0x00C8)
class UXPComponent_Powerup_LevelUp_Kills_C final : public UFortWorldMultiItemXPComponent
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x00C8(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	struct FGameplayTag                           Killed_Event_Tag;                                  // 0x00D0(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	struct FScalableFloat                         IncrementalXP;                                     // 0x00D8(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance)

public:
	void EventReceived_05AD7EE7427E2756D60D2A91EB87AA4E(const struct FGameplayEventData& Payload);
	void ExecuteUbergraph_XPComponent_Powerup_LevelUp_Kills(int32 EntryPoint);
	void ReceiveBeginPlay();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"XPComponent_Powerup_LevelUp_Kills_C">();
	}
	static class UXPComponent_Powerup_LevelUp_Kills_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UXPComponent_Powerup_LevelUp_Kills_C>();
	}
};

}

