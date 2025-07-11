#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PropManipulation

#include "Basic.hpp"

#include "PropManipulation_classes.hpp"
#include "PropManipulation_parameters.hpp"


namespace SDK
{

// Function PropManipulation.PropManipulationNativeComponent.RefreshTrackedActors
// (Final, Native, Protected, BlueprintCallable)
// Parameters:
// class UPlayspaceComponent_SpatialActorTracker*InPlaySpaceComponent_SpatialActorTracker               (Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UPropManipulationNativeComponent::RefreshTrackedActors(class UPlayspaceComponent_SpatialActorTracker* InPlaySpaceComponent_SpatialActorTracker)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PropManipulationNativeComponent", "RefreshTrackedActors");

	Params::PropManipulationNativeComponent_RefreshTrackedActors Parms{};

	Parms.InPlaySpaceComponent_SpatialActorTracker = InPlaySpaceComponent_SpatialActorTracker;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function PropManipulation.PropManipulationNativeComponent.SetControlledObjectsVisibilityAndCollision
// (Final, Native, Protected, BlueprintCallable)
// Parameters:
// TArray<class ABuildingSMActor*>         InObjectsOfControl                                     (Parm, ZeroConstructor, NativeAccessSpecifierPublic)
// bool                                    InNewVisibility                                        (ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UPropManipulationNativeComponent::SetControlledObjectsVisibilityAndCollision(const TArray<class ABuildingSMActor*>& InObjectsOfControl, const bool InNewVisibility)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PropManipulationNativeComponent", "SetControlledObjectsVisibilityAndCollision");

	Params::PropManipulationNativeComponent_SetControlledObjectsVisibilityAndCollision Parms{};

	Parms.InObjectsOfControl = std::move(InObjectsOfControl);
	Parms.InNewVisibility = InNewVisibility;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}

}

