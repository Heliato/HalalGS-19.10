#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PhosphorusWipeoutRuntime

#include "Basic.hpp"

#include "GameplayTags_structs.hpp"
#include "GameplayAbilities_structs.hpp"


namespace SDK
{

// ScriptStruct PhosphorusWipeoutRuntime.ModifyIncomingPawnDamageDefinition
// 0x0070 (0x0070 - 0x0000)
struct FModifyIncomingPawnDamageDefinition final
{
public:
	struct FGameplayTagContainer                  IncludeDamageTags;                                 // 0x0000(0x0020)(Edit, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FGameplayTagContainer                  ExcludeDamageTags;                                 // 0x0020(0x0020)(Edit, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FGameplayTag                           Event;                                             // 0x0040(0x0008)(Edit, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FScalableFloat                         DamageMultiplier;                                  // 0x0048(0x0028)(Edit, DisableEditOnInstance, NativeAccessSpecifierPublic)
};

}

