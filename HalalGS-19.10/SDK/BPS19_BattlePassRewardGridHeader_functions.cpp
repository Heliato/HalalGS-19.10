#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BPS19_BattlePassRewardGridHeader

#include "Basic.hpp"

#include "BPS19_BattlePassRewardGridHeader_classes.hpp"
#include "BPS19_BattlePassRewardGridHeader_parameters.hpp"


namespace SDK
{

// Function BPS19_BattlePassRewardGridHeader.BPS19_BattlePassRewardGridHeader_C.ExecuteUbergraph_BPS19_BattlePassRewardGridHeader
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBPS19_BattlePassRewardGridHeader_C::ExecuteUbergraph_BPS19_BattlePassRewardGridHeader(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BPS19_BattlePassRewardGridHeader_C", "ExecuteUbergraph_BPS19_BattlePassRewardGridHeader");

	Params::BPS19_BattlePassRewardGridHeader_C_ExecuteUbergraph_BPS19_BattlePassRewardGridHeader Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BPS19_BattlePassRewardGridHeader.BPS19_BattlePassRewardGridHeader_C.OnPageLocked
// (Event, Public, BlueprintEvent)
// Parameters:
// int32                                   RequiredLevel                                          (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   RequiredRewards                                        (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBPS19_BattlePassRewardGridHeader_C::OnPageLocked(const int32 RequiredLevel, const int32 RequiredRewards)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BPS19_BattlePassRewardGridHeader_C", "OnPageLocked");

	Params::BPS19_BattlePassRewardGridHeader_C_OnPageLocked Parms{};

	Parms.RequiredLevel = RequiredLevel;
	Parms.RequiredRewards = RequiredRewards;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BPS19_BattlePassRewardGridHeader.BPS19_BattlePassRewardGridHeader_C.OnPageNumberSet
// (Event, Public, BlueprintEvent)
// Parameters:
// int32                                   InPageNumber                                           (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBPS19_BattlePassRewardGridHeader_C::OnPageNumberSet(const int32 InPageNumber)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BPS19_BattlePassRewardGridHeader_C", "OnPageNumberSet");

	Params::BPS19_BattlePassRewardGridHeader_C_OnPageNumberSet Parms{};

	Parms.InPageNumber = InPageNumber;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BPS19_BattlePassRewardGridHeader.BPS19_BattlePassRewardGridHeader_C.OnPageUnlocked
// (Event, Public, BlueprintEvent)
// Parameters:
// int32                                   PurchasedRewards                                       (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   TotalRewards                                           (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBPS19_BattlePassRewardGridHeader_C::OnPageUnlocked(const int32 PurchasedRewards, const int32 TotalRewards)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BPS19_BattlePassRewardGridHeader_C", "OnPageUnlocked");

	Params::BPS19_BattlePassRewardGridHeader_C_OnPageUnlocked Parms{};

	Parms.PurchasedRewards = PurchasedRewards;
	Parms.TotalRewards = TotalRewards;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BPS19_BattlePassRewardGridHeader.BPS19_BattlePassRewardGridHeader_C.OnSetPageCustomName
// (Event, Public, HasOutParams, BlueprintEvent)
// Parameters:
// class FText                             CustomName                                             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)

void UBPS19_BattlePassRewardGridHeader_C::OnSetPageCustomName(const class FText& CustomName)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BPS19_BattlePassRewardGridHeader_C", "OnSetPageCustomName");

	Params::BPS19_BattlePassRewardGridHeader_C_OnSetPageCustomName Parms{};

	Parms.CustomName = std::move(CustomName);

	UObject::ProcessEvent(Func, &Parms);
}


// Function BPS19_BattlePassRewardGridHeader.BPS19_BattlePassRewardGridHeader_C.OnSetPageType
// (Event, Public, BlueprintEvent)
// Parameters:
// ERewardPageType                         PageType                                               (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBPS19_BattlePassRewardGridHeader_C::OnSetPageType(const ERewardPageType PageType)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BPS19_BattlePassRewardGridHeader_C", "OnSetPageType");

	Params::BPS19_BattlePassRewardGridHeader_C_OnSetPageType Parms{};

	Parms.PageType = PageType;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BPS19_BattlePassRewardGridHeader.BPS19_BattlePassRewardGridHeader_C.UpdateLockedHeaderText
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   RequiredLevel                                          (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   RequiredRewards                                        (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBPS19_BattlePassRewardGridHeader_C::UpdateLockedHeaderText(const int32 RequiredLevel, const int32 RequiredRewards)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BPS19_BattlePassRewardGridHeader_C", "UpdateLockedHeaderText");

	Params::BPS19_BattlePassRewardGridHeader_C_UpdateLockedHeaderText Parms{};

	Parms.RequiredLevel = RequiredLevel;
	Parms.RequiredRewards = RequiredRewards;

	UObject::ProcessEvent(Func, &Parms);
}

}

