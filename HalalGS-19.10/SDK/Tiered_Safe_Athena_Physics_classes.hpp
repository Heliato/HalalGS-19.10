#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Tiered_Safe_Athena_Physics

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "BuildingContainer_Physics_Parent_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass Tiered_Safe_Athena_Physics.Tiered_Safe_Athena_Physics_C
// 0x0018 (0x0EF8 - 0x0EE0)
class ATiered_Safe_Athena_Physics_C final : public ABuildingContainer_Physics_Parent_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_Tiered_Safe_Athena_Physics_C;       // 0x0EE0(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UMultiInteractActorComponent_C*         MultiInteractActorComponent;                       // 0x0EE8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             OpenSafeSound;                                     // 0x0EF0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_Tiered_Safe_Athena_Physics(int32 EntryPoint);
	void OnSetSearched();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Tiered_Safe_Athena_Physics_C">();
	}
	static class ATiered_Safe_Athena_Physics_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ATiered_Safe_Athena_Physics_C>();
	}
};

}

