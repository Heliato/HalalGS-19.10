#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: B_CameraRainDrops_03

#include "Basic.hpp"

#include "B_CameraRainDrops_03_classes.hpp"
#include "B_CameraRainDrops_03_parameters.hpp"


namespace SDK
{

// Function B_CameraRainDrops_03.B_CameraRainDrops_03_C.Alpha__FinishedFunc
// (BlueprintEvent)

void AB_CameraRainDrops_03_C::Alpha__FinishedFunc()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_CameraRainDrops_03_C", "Alpha__FinishedFunc");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_CameraRainDrops_03.B_CameraRainDrops_03_C.Alpha__UpdateFunc
// (BlueprintEvent)

void AB_CameraRainDrops_03_C::Alpha__UpdateFunc()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_CameraRainDrops_03_C", "Alpha__UpdateFunc");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_CameraRainDrops_03.B_CameraRainDrops_03_C.ExecuteUbergraph_B_CameraRainDrops_03
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AB_CameraRainDrops_03_C::ExecuteUbergraph_B_CameraRainDrops_03(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_CameraRainDrops_03_C", "ExecuteUbergraph_B_CameraRainDrops_03");

	Params::B_CameraRainDrops_03_C_ExecuteUbergraph_B_CameraRainDrops_03 Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function B_CameraRainDrops_03.B_CameraRainDrops_03_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void AB_CameraRainDrops_03_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_CameraRainDrops_03_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_CameraRainDrops_03.B_CameraRainDrops_03_C.ReceiveDestroyed
// (Event, Public, BlueprintEvent)

void AB_CameraRainDrops_03_C::ReceiveDestroyed()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_CameraRainDrops_03_C", "ReceiveDestroyed");

	UObject::ProcessEvent(Func, nullptr);
}

}

