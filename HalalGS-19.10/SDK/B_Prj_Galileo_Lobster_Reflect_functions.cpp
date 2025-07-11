#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: B_Prj_Galileo_Lobster_Reflect

#include "Basic.hpp"

#include "B_Prj_Galileo_Lobster_Reflect_classes.hpp"
#include "B_Prj_Galileo_Lobster_Reflect_parameters.hpp"


namespace SDK
{

// Function B_Prj_Galileo_Lobster_Reflect.B_Prj_Galileo_Lobster_Reflect_C.ExecuteUbergraph_B_Prj_Galileo_Lobster_Reflect
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AB_Prj_Galileo_Lobster_Reflect_C::ExecuteUbergraph_B_Prj_Galileo_Lobster_Reflect(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Prj_Galileo_Lobster_Reflect_C", "ExecuteUbergraph_B_Prj_Galileo_Lobster_Reflect");

	Params::B_Prj_Galileo_Lobster_Reflect_C_ExecuteUbergraph_B_Prj_Galileo_Lobster_Reflect Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function B_Prj_Galileo_Lobster_Reflect.B_Prj_Galileo_Lobster_Reflect_C.OnStop
// (Event, Public, HasOutParams, BlueprintEvent)
// Parameters:
// struct FHitResult                       Hit                                                    (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, IsPlainOldData, NoDestructor, ContainsInstancedReference)

void AB_Prj_Galileo_Lobster_Reflect_C::OnStop(const struct FHitResult& Hit)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Prj_Galileo_Lobster_Reflect_C", "OnStop");

	Params::B_Prj_Galileo_Lobster_Reflect_C_OnStop Parms{};

	Parms.Hit = std::move(Hit);

	UObject::ProcessEvent(Func, &Parms);
}


// Function B_Prj_Galileo_Lobster_Reflect.B_Prj_Galileo_Lobster_Reflect_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void AB_Prj_Galileo_Lobster_Reflect_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Prj_Galileo_Lobster_Reflect_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_Prj_Galileo_Lobster_Reflect.B_Prj_Galileo_Lobster_Reflect_C.UserConstructionScript
// (Event, Public, BlueprintCallable, BlueprintEvent)

void AB_Prj_Galileo_Lobster_Reflect_C::UserConstructionScript()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Prj_Galileo_Lobster_Reflect_C", "UserConstructionScript");

	UObject::ProcessEvent(Func, nullptr);
}

}

