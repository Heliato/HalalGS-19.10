#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Hotfix_Container_Parent

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "GameplayAbilities_structs.hpp"
#include "FortniteGame_classes.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass Hotfix_Container_Parent.Hotfix_Container_Parent_C
// 0x0080 (0x0F38 - 0x0EB8)
class AHotfix_Container_Parent_C : public ABuildingContainer
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0EB8(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	struct FScalableFloat                         Row_ActorEnabled;                                  // 0x0EC0(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance)
	struct FScalableFloat                         Row_InteractEnabled;                               // 0x0EE8(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance)
	class UParticleSystem*                        FX_Open;                                           // 0x0F10(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                FX_OpenOffsetLocation;                             // 0x0F18(0x000C)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         FX_OpenPitchOffset;                                // 0x0F24(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             Sound_Open;                                        // 0x0F28(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          DisableLootOnDisableInteract;                      // 0x0F30(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_Hotfix_Container_Parent(int32 EntryPoint);
	void OnLoot();
	void OnReady_8BE6ADB6479A5EF3145F32B245E584C6(class AFortGameStateAthena* GameState, const class UFortPlaylist* Playlist, const struct FGameplayTagContainer& PlaylistContextTags);
	void ReceiveBeginPlay();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Hotfix_Container_Parent_C">();
	}
	static class AHotfix_Container_Parent_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AHotfix_Container_Parent_C>();
	}
};

}

