#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: B_MasterPetAnimBP

#include "Basic.hpp"

#include "B_MasterPetAnimBP_classes.hpp"
#include "B_MasterPetAnimBP_parameters.hpp"


namespace SDK
{

// Function B_MasterPetAnimBP.B_MasterPetAnimBP_C.AnimGraph
// (HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FPoseLink                        Param_AnimGraph                                        (Parm, OutParm, NoDestructor)

void UB_MasterPetAnimBP_C::AnimGraph(struct FPoseLink* Param_AnimGraph)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_MasterPetAnimBP_C", "AnimGraph");

	Params::B_MasterPetAnimBP_C_AnimGraph Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Param_AnimGraph != nullptr)
		*Param_AnimGraph = std::move(Parms.Param_AnimGraph);
}


// Function B_MasterPetAnimBP.B_MasterPetAnimBP_C.AnimNotify_CrouchIdle1_FullyBlended
// (BlueprintCallable, BlueprintEvent)

void UB_MasterPetAnimBP_C::AnimNotify_CrouchIdle1_FullyBlended()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_MasterPetAnimBP_C", "AnimNotify_CrouchIdle1_FullyBlended");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_MasterPetAnimBP.B_MasterPetAnimBP_C.AnimNotify_CrouchIdle2_FullyBlended
// (BlueprintCallable, BlueprintEvent)

void UB_MasterPetAnimBP_C::AnimNotify_CrouchIdle2_FullyBlended()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_MasterPetAnimBP_C", "AnimNotify_CrouchIdle2_FullyBlended");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_MasterPetAnimBP.B_MasterPetAnimBP_C.AnimNotify_Entered_Crouching
// (BlueprintCallable, BlueprintEvent)

void UB_MasterPetAnimBP_C::AnimNotify_Entered_Crouching()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_MasterPetAnimBP_C", "AnimNotify_Entered_Crouching");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_MasterPetAnimBP.B_MasterPetAnimBP_C.AnimNotify_Entered_DownSightsToCrouch
// (BlueprintCallable, BlueprintEvent)

void UB_MasterPetAnimBP_C::AnimNotify_Entered_DownSightsToCrouch()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_MasterPetAnimBP_C", "AnimNotify_Entered_DownSightsToCrouch");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_MasterPetAnimBP.B_MasterPetAnimBP_C.AnimNotify_RollRandomIdle
// (BlueprintCallable, BlueprintEvent)

void UB_MasterPetAnimBP_C::AnimNotify_RollRandomIdle()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_MasterPetAnimBP_C", "AnimNotify_RollRandomIdle");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_MasterPetAnimBP.B_MasterPetAnimBP_C.AnimNotify_RollRandomIdle2
// (BlueprintCallable, BlueprintEvent)

void UB_MasterPetAnimBP_C::AnimNotify_RollRandomIdle2()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_MasterPetAnimBP_C", "AnimNotify_RollRandomIdle2");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_MasterPetAnimBP.B_MasterPetAnimBP_C.AnimNotify_StartJump_Entered
// (BlueprintCallable, BlueprintEvent)

void UB_MasterPetAnimBP_C::AnimNotify_StartJump_Entered()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_MasterPetAnimBP_C", "AnimNotify_StartJump_Entered");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_MasterPetAnimBP.B_MasterPetAnimBP_C.AnimNotify_StartJump_Entered_Test
// (BlueprintCallable, BlueprintEvent)

void UB_MasterPetAnimBP_C::AnimNotify_StartJump_Entered_Test()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_MasterPetAnimBP_C", "AnimNotify_StartJump_Entered_Test");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_MasterPetAnimBP.B_MasterPetAnimBP_C.ExecuteUbergraph_B_MasterPetAnimBP
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UB_MasterPetAnimBP_C::ExecuteUbergraph_B_MasterPetAnimBP(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_MasterPetAnimBP_C", "ExecuteUbergraph_B_MasterPetAnimBP");

	Params::B_MasterPetAnimBP_C_ExecuteUbergraph_B_MasterPetAnimBP Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function B_MasterPetAnimBP.B_MasterPetAnimBP_C.LobbySkyDive_IsDiving
// (BlueprintCallable, BlueprintEvent)

void UB_MasterPetAnimBP_C::LobbySkyDive_IsDiving()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_MasterPetAnimBP_C", "LobbySkyDive_IsDiving");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_MasterPetAnimBP.B_MasterPetAnimBP_C.LobbySkyDive_IsGliding
// (BlueprintCallable, BlueprintEvent)

void UB_MasterPetAnimBP_C::LobbySkyDive_IsGliding()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_MasterPetAnimBP_C", "LobbySkyDive_IsGliding");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_MasterPetAnimBP.B_MasterPetAnimBP_C.PetFullOverrideLayer
// (HasOutParams, BlueprintCallable)
// Parameters:
// struct FPoseLink                        InPose                                                 (BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor)
// struct FPoseLink                        Param_PetFullOverrideLayer                             (Parm, OutParm, NoDestructor)

void UB_MasterPetAnimBP_C::PetFullOverrideLayer(const struct FPoseLink& InPose, struct FPoseLink* Param_PetFullOverrideLayer)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_MasterPetAnimBP_C", "PetFullOverrideLayer");

	Params::B_MasterPetAnimBP_C_PetFullOverrideLayer Parms{};

	Parms.InPose = std::move(InPose);

	UObject::ProcessEvent(Func, &Parms);

	if (Param_PetFullOverrideLayer != nullptr)
		*Param_PetFullOverrideLayer = std::move(Parms.Param_PetFullOverrideLayer);
}


// Function B_MasterPetAnimBP.B_MasterPetAnimBP_C.PetSkeletalControlLayer
// (HasOutParams, BlueprintCallable)
// Parameters:
// struct FPoseLink                        Pose                                                   (BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor)
// float                                   Param_LookAtOverrideInput                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector                          Param_LookAtTargetLocationInput                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   Param_LegIKAlphaOverride                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   Param_HandIKAlphaOverride                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FPoseLink                        Param_PetSkeletalControlLayer                          (Parm, OutParm, NoDestructor)

void UB_MasterPetAnimBP_C::PetSkeletalControlLayer(const struct FPoseLink& Pose, float Param_LookAtOverrideInput, const struct FVector& Param_LookAtTargetLocationInput, float Param_LegIKAlphaOverride, float Param_HandIKAlphaOverride, struct FPoseLink* Param_PetSkeletalControlLayer)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_MasterPetAnimBP_C", "PetSkeletalControlLayer");

	Params::B_MasterPetAnimBP_C_PetSkeletalControlLayer Parms{};

	Parms.Pose = std::move(Pose);
	Parms.Param_LookAtOverrideInput = Param_LookAtOverrideInput;
	Parms.Param_LookAtTargetLocationInput = std::move(Param_LookAtTargetLocationInput);
	Parms.Param_LegIKAlphaOverride = Param_LegIKAlphaOverride;
	Parms.Param_HandIKAlphaOverride = Param_HandIKAlphaOverride;

	UObject::ProcessEvent(Func, &Parms);

	if (Param_PetSkeletalControlLayer != nullptr)
		*Param_PetSkeletalControlLayer = std::move(Parms.Param_PetSkeletalControlLayer);
}

}

