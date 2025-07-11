#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AnnualRefundTokenUI

#include "Basic.hpp"

#include "FortniteGame_structs.hpp"
#include "AnnualRefundTokenUI_structs.hpp"


namespace SDK::Params
{

// Function AnnualRefundTokenUI.FortAnnualRefundTicket.OnUpdateAvailableState
// 0x0001 (0x0001 - 0x0000)
struct FortAnnualRefundTicket_OnUpdateAvailableState final
{
public:
	bool                                          bIsAvailable;                                      // 0x0000(0x0001)(ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function AnnualRefundTokenUI.FortAnnualRefundTicket.OnUpdatePendingState
// 0x0001 (0x0001 - 0x0000)
struct FortAnnualRefundTicket_OnUpdatePendingState final
{
public:
	bool                                          bIsPending;                                        // 0x0000(0x0001)(ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function AnnualRefundTokenUI.FortPurchaseHistoryEntry.OnSetHistory
// 0x0003 (0x0003 - 0x0000)
struct FortPurchaseHistoryEntry_OnSetHistory final
{
public:
	bool                                          bHasBeenRefunded;                                  // 0x0000(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bIsTokenlessRefund;                                // 0x0001(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bPlayerHasTokens;                                  // 0x0002(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function AnnualRefundTokenUI.FortPurchaseHistoryEntry.SetPurchaseText
// 0x0020 (0x0020 - 0x0000)
struct FortPurchaseHistoryEntry_SetPurchaseText final
{
public:
	class FText                                   PurchaseText;                                      // 0x0000(0x0018)(ConstParm, Parm, OutParm, ReferenceParm, NativeAccessSpecifierPublic)
	bool                                          bHasBeenRefunded;                                  // 0x0018(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_19[0x7];                                       // 0x0019(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function AnnualRefundTokenUI.FortPurchaseHistoryEntry.SetupItemCard
// 0x0010 (0x0010 - 0x0000)
struct FortPurchaseHistoryEntry_SetupItemCard final
{
public:
	const class UFortCosmeticItemCard*            ItemCard;                                          // 0x0000(0x0008)(ConstParm, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	const class UFortItem*                        Item;                                              // 0x0008(0x0008)(ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function AnnualRefundTokenUI.FortPurchaseHistoryEntry.UpdateItemList
// 0x0010 (0x0010 - 0x0000)
struct FortPurchaseHistoryEntry_UpdateItemList final
{
public:
	TArray<class UFortCosmeticItemCard*>          ItemCards;                                         // 0x0000(0x0010)(ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, ContainsInstancedReference, NativeAccessSpecifierPublic)
};

// Function AnnualRefundTokenUI.FortPurchaseHistoryScreen.HandleTabButtonClicked
// 0x0001 (0x0001 - 0x0000)
struct FortPurchaseHistoryScreen_HandleTabButtonClicked final
{
public:
	EPurchaseReturnStep                           ClickedStep;                                       // 0x0000(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function AnnualRefundTokenUI.FortPurchaseHistoryScreen.OnItemRefresh
// 0x0020 (0x0020 - 0x0000)
struct FortPurchaseHistoryScreen_OnItemRefresh final
{
public:
	struct FMtxPurchaseHistory                    PurchaseHistory;                                   // 0x0000(0x0020)(Parm, NativeAccessSpecifierPublic)
};

// Function AnnualRefundTokenUI.FortPurchaseHistoryScreen.OnOpenSubmitRequest
// 0x0001 (0x0001 - 0x0000)
struct FortPurchaseHistoryScreen_OnOpenSubmitRequest final
{
public:
	bool                                          bIsSelectionTokenlessRefundable;                   // 0x0000(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function AnnualRefundTokenUI.FortPurchaseHistoryScreen.OnPopulateView
// 0x0001 (0x0001 - 0x0000)
struct FortPurchaseHistoryScreen_OnPopulateView final
{
public:
	EPurchaseReturnStep                           CurrentStep;                                       // 0x0000(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function AnnualRefundTokenUI.FortPurchaseHistoryScreen.UpdateItemList
// 0x0010 (0x0010 - 0x0000)
struct FortPurchaseHistoryScreen_UpdateItemList final
{
public:
	TArray<class UCommonTextBlock*>               ItemsToReturn;                                     // 0x0000(0x0010)(ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, ContainsInstancedReference, NativeAccessSpecifierPublic)
};

// Function AnnualRefundTokenUI.FortPurchaseHistoryScreen.GetCurrentStep
// 0x0001 (0x0001 - 0x0000)
struct FortPurchaseHistoryScreen_GetCurrentStep final
{
public:
	EPurchaseReturnStep                           ReturnValue;                                       // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

}

