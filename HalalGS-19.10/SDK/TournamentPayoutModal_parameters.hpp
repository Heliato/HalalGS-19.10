#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TournamentPayoutModal

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "FortniteUI_structs.hpp"


namespace SDK::Params
{

// Function TournamentPayoutModal.TournamentPayoutModal_C.BndEvt__BackButton_K2Node_ComponentBoundEvent_0_CommonButtonClicked__DelegateSignature
// 0x0008 (0x0008 - 0x0000)
struct TournamentPayoutModal_C_BndEvt__BackButton_K2Node_ComponentBoundEvent_0_CommonButtonClicked__DelegateSignature final
{
public:
	class UCommonButtonLegacy*                    Button;                                            // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function TournamentPayoutModal.TournamentPayoutModal_C.BndEvt__CloseButton_K2Node_ComponentBoundEvent_2_CommonButtonClicked__DelegateSignature
// 0x0008 (0x0008 - 0x0000)
struct TournamentPayoutModal_C_BndEvt__CloseButton_K2Node_ComponentBoundEvent_2_CommonButtonClicked__DelegateSignature final
{
public:
	class UCommonButtonLegacy*                    Button;                                            // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function TournamentPayoutModal.TournamentPayoutModal_C.EmptyFunction
// 0x0001 (0x0001 - 0x0000)
struct TournamentPayoutModal_C_EmptyFunction final
{
public:
	bool                                          Handled;                                           // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function TournamentPayoutModal.TournamentPayoutModal_C.EventColorize
// 0x01D0 (0x01D0 - 0x0000)
struct TournamentPayoutModal_C_EventColorize final
{
public:
	struct FFortTournamentDisplayInfo             TournamentDisplayInfo;                             // 0x0000(0x01D0)(BlueprintVisible, BlueprintReadOnly, Parm)
};

// Function TournamentPayoutModal.TournamentPayoutModal_C.ExecuteUbergraph_TournamentPayoutModal
// 0x0218 (0x0218 - 0x0000)
struct TournamentPayoutModal_C_ExecuteUbergraph_TournamentPayoutModal final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UCommonButtonLegacy*                    K2Node_ComponentBoundEvent_Button;                 // 0x0008(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FString                                 K2Node_CustomEvent_EventWindowId;                  // 0x0010(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	class FString                                 K2Node_CustomEvent_TournamentId;                   // 0x0020(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	class UCommonButtonLegacy*                    K2Node_ComponentBoundEvent_Button_1;               // 0x0030(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FFortTournamentDisplayInfo             K2Node_CustomEvent_TournamentDisplayInfo;          // 0x0038(0x01D0)()
	struct FLinearColor                           K2Node_MakeStruct_LinearColor;                     // 0x0208(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function TournamentPayoutModal.TournamentPayoutModal_C.Init
// 0x0020 (0x0020 - 0x0000)
struct TournamentPayoutModal_C_Init final
{
public:
	class FString                                 EventWindowId;                                     // 0x0000(0x0010)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)
	class FString                                 TournamentId;                                      // 0x0010(0x0010)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)
};

}

