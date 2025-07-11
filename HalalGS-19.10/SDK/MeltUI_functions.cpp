#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: MeltUI

#include "Basic.hpp"

#include "MeltUI_classes.hpp"
#include "MeltUI_parameters.hpp"


namespace SDK
{

// Function MeltUI.MeltWidgetBase.CacheAndGetSeaLevel
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// float                                   ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

float UMeltWidgetBase::CacheAndGetSeaLevel()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("MeltWidgetBase", "CacheAndGetSeaLevel");

	Params::MeltWidgetBase_CacheAndGetSeaLevel Parms{};

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function MeltUI.MeltWidgetBase.MutatorReady
// (Event, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AFortAthenaMutator_Fill*          MutatorActor                                           (ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UMeltWidgetBase::MutatorReady(const class AFortAthenaMutator_Fill* MutatorActor)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("MeltWidgetBase", "MutatorReady");

	Params::MeltWidgetBase_MutatorReady Parms{};

	Parms.MutatorActor = MutatorActor;

	UObject::ProcessEvent(Func, &Parms);
}


// Function MeltUI.MeltWidgetBase.GetFillMutator
// (Final, Native, Public, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// class AFortAthenaMutator_Fill*          ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

class AFortAthenaMutator_Fill* UMeltWidgetBase::GetFillMutator() const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("MeltWidgetBase", "GetFillMutator");

	Params::MeltWidgetBase_GetFillMutator Parms{};

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}

}

