#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BPS19_GetAllButton

#include "Basic.hpp"

#include "BPS19_GetAllButton_classes.hpp"
#include "BPS19_GetAllButton_parameters.hpp"


namespace SDK
{

// Function BPS19_GetAllButton.BPS19_GetAllButton_C.BP_OnHovered
// (Event, Protected, BlueprintEvent)

void UBPS19_GetAllButton_C::BP_OnHovered()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BPS19_GetAllButton_C", "BP_OnHovered");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BPS19_GetAllButton.BPS19_GetAllButton_C.BP_OnUnhovered
// (Event, Protected, BlueprintEvent)

void UBPS19_GetAllButton_C::BP_OnUnhovered()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BPS19_GetAllButton_C", "BP_OnUnhovered");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BPS19_GetAllButton.BPS19_GetAllButton_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UBPS19_GetAllButton_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BPS19_GetAllButton_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BPS19_GetAllButton.BPS19_GetAllButton_C.Destruct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UBPS19_GetAllButton_C::Destruct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BPS19_GetAllButton_C", "Destruct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BPS19_GetAllButton.BPS19_GetAllButton_C.ExecuteUbergraph_BPS19_GetAllButton
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBPS19_GetAllButton_C::ExecuteUbergraph_BPS19_GetAllButton(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BPS19_GetAllButton_C", "ExecuteUbergraph_BPS19_GetAllButton");

	Params::BPS19_GetAllButton_C_ExecuteUbergraph_BPS19_GetAllButton Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BPS19_GetAllButton.BPS19_GetAllButton_C.Set Text Data
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Param_Page_Complete                                    (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   Starting_Page                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   Ending_Page                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   Cost                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBPS19_GetAllButton_C::Set_Text_Data(bool Param_Page_Complete, int32 Starting_Page, int32 Ending_Page, int32 Cost)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BPS19_GetAllButton_C", "Set Text Data");

	Params::BPS19_GetAllButton_C_Set_Text_Data Parms{};

	Parms.Param_Page_Complete = Param_Page_Complete;
	Parms.Starting_Page = Starting_Page;
	Parms.Ending_Page = Ending_Page;
	Parms.Cost = Cost;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BPS19_GetAllButton.BPS19_GetAllButton_C.UpdateTextAndStyle
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// ECommonInputType                        Input_Type                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBPS19_GetAllButton_C::UpdateTextAndStyle(ECommonInputType Input_Type)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BPS19_GetAllButton_C", "UpdateTextAndStyle");

	Params::BPS19_GetAllButton_C_UpdateTextAndStyle Parms{};

	Parms.Input_Type = Input_Type;

	UObject::ProcessEvent(Func, &Parms);
}

}

