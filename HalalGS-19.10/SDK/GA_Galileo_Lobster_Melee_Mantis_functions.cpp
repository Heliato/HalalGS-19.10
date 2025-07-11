#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GA_Galileo_Lobster_Melee_Mantis

#include "Basic.hpp"

#include "GA_Galileo_Lobster_Melee_Mantis_classes.hpp"
#include "GA_Galileo_Lobster_Melee_Mantis_parameters.hpp"


namespace SDK
{

// Function GA_Galileo_Lobster_Melee_Mantis.GA_Galileo_Lobster_Melee_Mantis_C.Added_257119E44AAC9BD082F95A9F3201447E
// (BlueprintCallable, BlueprintEvent)

void UGA_Galileo_Lobster_Melee_Mantis_C::Added_257119E44AAC9BD082F95A9F3201447E()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_Galileo_Lobster_Melee_Mantis_C", "Added_257119E44AAC9BD082F95A9F3201447E");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_Galileo_Lobster_Melee_Mantis.GA_Galileo_Lobster_Melee_Mantis_C.BP_OnMantisTechniqueHit
// (Event, Protected, HasOutParams, BlueprintEvent)
// Parameters:
// struct FGameplayAbilityTargetDataHandle TargetDataHandle                                       (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// struct FGameplayTag                     ApplicationTag                                         (BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor, HasGetValueTypeHash)

void UGA_Galileo_Lobster_Melee_Mantis_C::BP_OnMantisTechniqueHit(const struct FGameplayAbilityTargetDataHandle& TargetDataHandle, const struct FGameplayTag& ApplicationTag)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_Galileo_Lobster_Melee_Mantis_C", "BP_OnMantisTechniqueHit");

	Params::GA_Galileo_Lobster_Melee_Mantis_C_BP_OnMantisTechniqueHit Parms{};

	Parms.TargetDataHandle = std::move(TargetDataHandle);
	Parms.ApplicationTag = std::move(ApplicationTag);

	UObject::ProcessEvent(Func, &Parms);
}


// Function GA_Galileo_Lobster_Melee_Mantis.GA_Galileo_Lobster_Melee_Mantis_C.EventReceived_3D9CCD6F49D4ABCB0E35DB855ADE0B29
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FGameplayEventData               Payload                                                (BlueprintVisible, BlueprintReadOnly, Parm)

void UGA_Galileo_Lobster_Melee_Mantis_C::EventReceived_3D9CCD6F49D4ABCB0E35DB855ADE0B29(const struct FGameplayEventData& Payload)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_Galileo_Lobster_Melee_Mantis_C", "EventReceived_3D9CCD6F49D4ABCB0E35DB855ADE0B29");

	Params::GA_Galileo_Lobster_Melee_Mantis_C_EventReceived_3D9CCD6F49D4ABCB0E35DB855ADE0B29 Parms{};

	Parms.Payload = std::move(Payload);

	UObject::ProcessEvent(Func, &Parms);
}


// Function GA_Galileo_Lobster_Melee_Mantis.GA_Galileo_Lobster_Melee_Mantis_C.ExecuteUbergraph_GA_Galileo_Lobster_Melee_Mantis
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UGA_Galileo_Lobster_Melee_Mantis_C::ExecuteUbergraph_GA_Galileo_Lobster_Melee_Mantis(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_Galileo_Lobster_Melee_Mantis_C", "ExecuteUbergraph_GA_Galileo_Lobster_Melee_Mantis");

	Params::GA_Galileo_Lobster_Melee_Mantis_C_ExecuteUbergraph_GA_Galileo_Lobster_Melee_Mantis Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function GA_Galileo_Lobster_Melee_Mantis.GA_Galileo_Lobster_Melee_Mantis_C.K2_ActivateAbility
// (Event, Protected, BlueprintEvent)

void UGA_Galileo_Lobster_Melee_Mantis_C::K2_ActivateAbility()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_Galileo_Lobster_Melee_Mantis_C", "K2_ActivateAbility");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_Galileo_Lobster_Melee_Mantis.GA_Galileo_Lobster_Melee_Mantis_C.K2_OnEndAbility
// (Event, Protected, BlueprintEvent)
// Parameters:
// bool                                    bWasCancelled                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UGA_Galileo_Lobster_Melee_Mantis_C::K2_OnEndAbility(bool bWasCancelled)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_Galileo_Lobster_Melee_Mantis_C", "K2_OnEndAbility");

	Params::GA_Galileo_Lobster_Melee_Mantis_C_K2_OnEndAbility Parms{};

	Parms.bWasCancelled = bWasCancelled;

	UObject::ProcessEvent(Func, &Parms);
}

}

