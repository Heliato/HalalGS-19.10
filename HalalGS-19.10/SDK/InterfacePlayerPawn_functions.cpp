#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: InterfacePlayerPawn

#include "Basic.hpp"

#include "InterfacePlayerPawn_classes.hpp"
#include "InterfacePlayerPawn_parameters.hpp"


namespace SDK
{

// Function InterfacePlayerPawn.InterfacePlayerPawn_C.FootStepLeft
// (Public, BlueprintCallable, BlueprintEvent)

void IInterfacePlayerPawn_C::FootStepLeft()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("InterfacePlayerPawn_C", "FootStepLeft");

	UObject::ProcessEvent(Func, nullptr);
}


// Function InterfacePlayerPawn.InterfacePlayerPawn_C.FootStepRight
// (Public, BlueprintCallable, BlueprintEvent)

void IInterfacePlayerPawn_C::FootStepRight()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("InterfacePlayerPawn_C", "FootStepRight");

	UObject::ProcessEvent(Func, nullptr);
}


// Function InterfacePlayerPawn.InterfacePlayerPawn_C.Melee_Effect_Color
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FVector                          Melee_Color_Set                                        (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void IInterfacePlayerPawn_C::Melee_Effect_Color(struct FVector* Melee_Color_Set)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("InterfacePlayerPawn_C", "Melee_Effect_Color");

	Params::InterfacePlayerPawn_C_Melee_Effect_Color Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Melee_Color_Set != nullptr)
		*Melee_Color_Set = std::move(Parms.Melee_Color_Set);
}


// Function InterfacePlayerPawn.InterfacePlayerPawn_C.MeleeSwingLeft
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    First_Left                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void IInterfacePlayerPawn_C::MeleeSwingLeft(bool First_Left)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("InterfacePlayerPawn_C", "MeleeSwingLeft");

	Params::InterfacePlayerPawn_C_MeleeSwingLeft Parms{};

	Parms.First_Left = First_Left;

	UObject::ProcessEvent(Func, &Parms);
}


// Function InterfacePlayerPawn.InterfacePlayerPawn_C.MeleeSwingLeft_End
// (Public, BlueprintCallable, BlueprintEvent)

void IInterfacePlayerPawn_C::MeleeSwingLeft_End()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("InterfacePlayerPawn_C", "MeleeSwingLeft_End");

	UObject::ProcessEvent(Func, nullptr);
}


// Function InterfacePlayerPawn.InterfacePlayerPawn_C.MeleeSwingRight
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    First_Right                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void IInterfacePlayerPawn_C::MeleeSwingRight(bool First_Right)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("InterfacePlayerPawn_C", "MeleeSwingRight");

	Params::InterfacePlayerPawn_C_MeleeSwingRight Parms{};

	Parms.First_Right = First_Right;

	UObject::ProcessEvent(Func, &Parms);
}


// Function InterfacePlayerPawn.InterfacePlayerPawn_C.MeleeSwingRight_End
// (Public, BlueprintCallable, BlueprintEvent)

void IInterfacePlayerPawn_C::MeleeSwingRight_End()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("InterfacePlayerPawn_C", "MeleeSwingRight_End");

	UObject::ProcessEvent(Func, nullptr);
}

}

