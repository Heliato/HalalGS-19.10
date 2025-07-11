#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WB_AudioAnalysis_FloatGraph

#include "Basic.hpp"

#include "WB_AudioAnalysis_FloatGraph_classes.hpp"
#include "WB_AudioAnalysis_FloatGraph_parameters.hpp"


namespace SDK
{

// Function WB_AudioAnalysis_FloatGraph.WB_AudioAnalysis_FloatGraph_C.calcWidgetSize
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FGeometry                        Geom                                                   (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)

void UWB_AudioAnalysis_FloatGraph_C::CalcWidgetSize(const struct FGeometry& Geom)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_AudioAnalysis_FloatGraph_C", "calcWidgetSize");

	Params::WB_AudioAnalysis_FloatGraph_C_CalcWidgetSize Parms{};

	Parms.Geom = std::move(Geom);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_AudioAnalysis_FloatGraph.WB_AudioAnalysis_FloatGraph_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UWB_AudioAnalysis_FloatGraph_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_AudioAnalysis_FloatGraph_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WB_AudioAnalysis_FloatGraph.WB_AudioAnalysis_FloatGraph_C.ExecuteUbergraph_WB_AudioAnalysis_FloatGraph
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_AudioAnalysis_FloatGraph_C::ExecuteUbergraph_WB_AudioAnalysis_FloatGraph(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_AudioAnalysis_FloatGraph_C", "ExecuteUbergraph_WB_AudioAnalysis_FloatGraph");

	Params::WB_AudioAnalysis_FloatGraph_C_ExecuteUbergraph_WB_AudioAnalysis_FloatGraph Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_AudioAnalysis_FloatGraph.WB_AudioAnalysis_FloatGraph_C.Initialize MPC
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// class FName                             Param_Parameter                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UMaterialParameterCollection*     Collection                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   Param_VectorIndex                                      (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_AudioAnalysis_FloatGraph_C::Initialize_MPC(class FName Param_Parameter, class UMaterialParameterCollection* Collection, int32 Param_VectorIndex)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_AudioAnalysis_FloatGraph_C", "Initialize MPC");

	Params::WB_AudioAnalysis_FloatGraph_C_Initialize_MPC Parms{};

	Parms.Param_Parameter = Param_Parameter;
	Parms.Collection = Collection;
	Parms.Param_VectorIndex = Param_VectorIndex;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_AudioAnalysis_FloatGraph.WB_AudioAnalysis_FloatGraph_C.PreConstruct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// bool                                    IsDesignTime                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_AudioAnalysis_FloatGraph_C::PreConstruct(bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_AudioAnalysis_FloatGraph_C", "PreConstruct");

	Params::WB_AudioAnalysis_FloatGraph_C_PreConstruct Parms{};

	Parms.IsDesignTime = IsDesignTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_AudioAnalysis_FloatGraph.WB_AudioAnalysis_FloatGraph_C.Set Value
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Param_Value                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_AudioAnalysis_FloatGraph_C::Set_Value(float Param_Value)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_AudioAnalysis_FloatGraph_C", "Set Value");

	Params::WB_AudioAnalysis_FloatGraph_C_Set_Value Parms{};

	Parms.Param_Value = Param_Value;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_AudioAnalysis_FloatGraph.WB_AudioAnalysis_FloatGraph_C.Tick
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// struct FGeometry                        MyGeometry                                             (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// float                                   InDeltaTime                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_AudioAnalysis_FloatGraph_C::Tick(const struct FGeometry& MyGeometry, float InDeltaTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_AudioAnalysis_FloatGraph_C", "Tick");

	Params::WB_AudioAnalysis_FloatGraph_C_Tick Parms{};

	Parms.MyGeometry = std::move(MyGeometry);
	Parms.InDeltaTime = InDeltaTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_AudioAnalysis_FloatGraph.WB_AudioAnalysis_FloatGraph_C.OnPaint
// (BlueprintCosmetic, Event, Public, HasOutParams, BlueprintCallable, BlueprintEvent, Const)
// Parameters:
// struct FPaintContext                    Context                                                (BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, NoDestructor)

void UWB_AudioAnalysis_FloatGraph_C::OnPaint(struct FPaintContext& Context) const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_AudioAnalysis_FloatGraph_C", "OnPaint");

	Params::WB_AudioAnalysis_FloatGraph_C_OnPaint Parms{};

	Parms.Context = std::move(Context);

	UObject::ProcessEvent(Func, &Parms);

	Context = std::move(Parms.Context);
}

}

