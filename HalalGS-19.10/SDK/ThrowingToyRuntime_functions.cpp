#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ThrowingToyRuntime

#include "Basic.hpp"

#include "ThrowingToyRuntime_classes.hpp"
#include "ThrowingToyRuntime_parameters.hpp"


namespace SDK
{

// Function ThrowingToyRuntime.ThrowingToyTrackerComponent.AddThrowingToy
// (Final, BlueprintAuthorityOnly, Native, Public, HasOutParams, HasDefaults, BlueprintCallable)
// Parameters:
// class AActor*                           ThrowingToyActor                                       (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// struct FGuid                            WorldItemGuid                                          (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UThrowingToyTrackerComponent::AddThrowingToy(class AActor* ThrowingToyActor, const struct FGuid& WorldItemGuid)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ThrowingToyTrackerComponent", "AddThrowingToy");

	Params::ThrowingToyTrackerComponent_AddThrowingToy Parms{};

	Parms.ThrowingToyActor = ThrowingToyActor;
	Parms.WorldItemGuid = std::move(WorldItemGuid);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function ThrowingToyRuntime.ThrowingToyTrackerComponent.GetAndReleaseThrowingToy
// (Final, BlueprintAuthorityOnly, Native, Public, HasOutParams, HasDefaults, BlueprintCallable)
// Parameters:
// struct FGuid                            WorldItemGuid                                          (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// class AActor*                           ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

class AActor* UThrowingToyTrackerComponent::GetAndReleaseThrowingToy(const struct FGuid& WorldItemGuid)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ThrowingToyTrackerComponent", "GetAndReleaseThrowingToy");

	Params::ThrowingToyTrackerComponent_GetAndReleaseThrowingToy Parms{};

	Parms.WorldItemGuid = std::move(WorldItemGuid);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function ThrowingToyRuntime.ThrowingToyTrackerComponent.GetThrowingToy
// (Final, Native, Public, HasOutParams, HasDefaults, BlueprintCallable)
// Parameters:
// struct FGuid                            WorldItemGuid                                          (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// class AActor*                           ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

class AActor* UThrowingToyTrackerComponent::GetThrowingToy(const struct FGuid& WorldItemGuid)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ThrowingToyTrackerComponent", "GetThrowingToy");

	Params::ThrowingToyTrackerComponent_GetThrowingToy Parms{};

	Parms.WorldItemGuid = std::move(WorldItemGuid);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}

}

