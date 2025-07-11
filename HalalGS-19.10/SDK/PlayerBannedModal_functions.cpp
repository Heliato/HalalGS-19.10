#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PlayerBannedModal

#include "Basic.hpp"

#include "PlayerBannedModal_classes.hpp"
#include "PlayerBannedModal_parameters.hpp"


namespace SDK
{

// Function PlayerBannedModal.PlayerBannedModal_C.BanEnumToText
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// EPlayerBanReasons                       Param_Index                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class FString                           ExploitProgramName                                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)
// EPlayerCompetitiveBanReasons            Competitive_Ban_Reason                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Param_bIsCompetitiveBan                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class FText                             ReturnValue                                            (Parm, OutParm, ReturnParm)

class FText UPlayerBannedModal_C::BanEnumToText(EPlayerBanReasons Param_Index, const class FString& ExploitProgramName, EPlayerCompetitiveBanReasons Competitive_Ban_Reason, bool Param_bIsCompetitiveBan)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PlayerBannedModal_C", "BanEnumToText");

	Params::PlayerBannedModal_C_BanEnumToText Parms{};

	Parms.Param_Index = Param_Index;
	Parms.ExploitProgramName = std::move(ExploitProgramName);
	Parms.Competitive_Ban_Reason = Competitive_Ban_Reason;
	Parms.Param_bIsCompetitiveBan = Param_bIsCompetitiveBan;

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function PlayerBannedModal.PlayerBannedModal_C.BndEvt__CloseButton_K2Node_ComponentBoundEvent_16_CommonButtonClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UCommonButtonLegacy*              Button                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPlayerBannedModal_C::BndEvt__CloseButton_K2Node_ComponentBoundEvent_16_CommonButtonClicked__DelegateSignature(class UCommonButtonLegacy* Button)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PlayerBannedModal_C", "BndEvt__CloseButton_K2Node_ComponentBoundEvent_16_CommonButtonClicked__DelegateSignature");

	Params::PlayerBannedModal_C_BndEvt__CloseButton_K2Node_ComponentBoundEvent_16_CommonButtonClicked__DelegateSignature Parms{};

	Parms.Button = Button;

	UObject::ProcessEvent(Func, &Parms);
}


// Function PlayerBannedModal.PlayerBannedModal_C.BP_OnActivated
// (Event, Protected, BlueprintEvent)

void UPlayerBannedModal_C::BP_OnActivated()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PlayerBannedModal_C", "BP_OnActivated");

	UObject::ProcessEvent(Func, nullptr);
}


// Function PlayerBannedModal.PlayerBannedModal_C.DisableButton
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Param_DisableButton                                    (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPlayerBannedModal_C::DisableButton(bool Param_DisableButton)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PlayerBannedModal_C", "DisableButton");

	Params::PlayerBannedModal_C_DisableButton Parms{};

	Parms.Param_DisableButton = Param_DisableButton;

	UObject::ProcessEvent(Func, &Parms);
}


// Function PlayerBannedModal.PlayerBannedModal_C.ExecuteUbergraph_PlayerBannedModal
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPlayerBannedModal_C::ExecuteUbergraph_PlayerBannedModal(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PlayerBannedModal_C", "ExecuteUbergraph_PlayerBannedModal");

	Params::PlayerBannedModal_C_ExecuteUbergraph_PlayerBannedModal Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function PlayerBannedModal.PlayerBannedModal_C.HandleCloseAttempted
// (Public, BlueprintCallable, BlueprintEvent)

void UPlayerBannedModal_C::HandleCloseAttempted()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PlayerBannedModal_C", "HandleCloseAttempted");

	UObject::ProcessEvent(Func, nullptr);
}


// Function PlayerBannedModal.PlayerBannedModal_C.OnBanAck
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Success                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPlayerBannedModal_C::OnBanAck(bool Success)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PlayerBannedModal_C", "OnBanAck");

	Params::PlayerBannedModal_C_OnBanAck Parms{};

	Parms.Success = Success;

	UObject::ProcessEvent(Func, &Parms);
}


// Function PlayerBannedModal.PlayerBannedModal_C.OnCloseSucceeded__DelegateSignature
// (Public, Delegate, BlueprintCallable, BlueprintEvent)

void UPlayerBannedModal_C::OnCloseSucceeded__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PlayerBannedModal_C", "OnCloseSucceeded__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}


// Function PlayerBannedModal.PlayerBannedModal_C.RemoveModal
// (Public, BlueprintCallable, BlueprintEvent)

void UPlayerBannedModal_C::RemoveModal()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PlayerBannedModal_C", "RemoveModal");

	UObject::ProcessEvent(Func, nullptr);
}


// Function PlayerBannedModal.PlayerBannedModal_C.UpdateText
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FText                             Param_Title                                            (BlueprintVisible, BlueprintReadOnly, Parm)
// class FText                             Content                                                (BlueprintVisible, BlueprintReadOnly, Parm)

void UPlayerBannedModal_C::UpdateText(const class FText& Param_Title, const class FText& Content)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PlayerBannedModal_C", "UpdateText");

	Params::PlayerBannedModal_C_UpdateText Parms{};

	Parms.Param_Title = std::move(Param_Title);
	Parms.Content = std::move(Content);

	UObject::ProcessEvent(Func, &Parms);
}


// Function PlayerBannedModal.PlayerBannedModal_C.UpdateTimeRemaining
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FText                             Time                                                   (BlueprintVisible, BlueprintReadOnly, Parm)

void UPlayerBannedModal_C::UpdateTimeRemaining(const class FText& Time)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PlayerBannedModal_C", "UpdateTimeRemaining");

	Params::PlayerBannedModal_C_UpdateTimeRemaining Parms{};

	Parms.Time = std::move(Time);

	UObject::ProcessEvent(Func, &Parms);
}

}

