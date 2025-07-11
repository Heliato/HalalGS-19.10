#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: MinigameStat_Time

#include "Basic.hpp"

#include "MinigameStat_Time_classes.hpp"
#include "MinigameStat_Time_parameters.hpp"


namespace SDK
{

// Function MinigameStat_Time.MinigameStat_Time_C.Accumulate
// (Event, Public, HasOutParams, BlueprintCallable, BlueprintEvent, Const)
// Parameters:
// int32                                   A                                                      (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   B                                                      (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

int32 UMinigameStat_Time_C::Accumulate(int32 A, int32 B) const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("MinigameStat_Time_C", "Accumulate");

	Params::MinigameStat_Time_C_Accumulate Parms{};

	Parms.A = A;
	Parms.B = B;

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function MinigameStat_Time.MinigameStat_Time_C.Compare
// (Event, Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure, Const)
// Parameters:
// int32                                   FirstScore                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   SecondScore                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

int32 UMinigameStat_Time_C::Compare(int32 FirstScore, int32 SecondScore) const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("MinigameStat_Time_C", "Compare");

	Params::MinigameStat_Time_C_Compare Parms{};

	Parms.FirstScore = FirstScore;
	Parms.SecondScore = SecondScore;

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function MinigameStat_Time.MinigameStat_Time_C.FormatStat
// (Event, Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, Const)
// Parameters:
// int32                                   InCount                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class FText                             ReturnValue                                            (Parm, OutParm, ReturnParm)

class FText UMinigameStat_Time_C::FormatStat(int32 InCount) const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("MinigameStat_Time_C", "FormatStat");

	Params::MinigameStat_Time_C_FormatStat Parms{};

	Parms.InCount = InCount;

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}

}

