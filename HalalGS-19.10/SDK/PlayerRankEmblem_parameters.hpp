#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PlayerRankEmblem

#include "Basic.hpp"

#include "FortniteGame_structs.hpp"
#include "Engine_structs.hpp"


namespace SDK::Params
{

// Function PlayerRankEmblem.PlayerRankEmblem_C.ExecuteUbergraph_PlayerRankEmblem
// 0x0050 (0x0050 - 0x0000)
struct PlayerRankEmblem_C_ExecuteUbergraph_PlayerRankEmblem final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class APlayerController*                      CallFunc_GetOwningPlayer_ReturnValue;              // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortPlayerController*                  K2Node_DynamicCast_AsFort_Player_Controller;       // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_19[0x7];                                       // 0x0019(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FUniqueNetIdRepl                       CallFunc_GetGameAccountId_ReturnValue;             // 0x0020(0x0028)(HasGetValueTypeHash)
	bool                                          K2Node_Event_IsDesignTime;                         // 0x0048(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function PlayerRankEmblem.PlayerRankEmblem_C.PreConstruct
// 0x0001 (0x0001 - 0x0000)
struct PlayerRankEmblem_C_PreConstruct final
{
public:
	bool                                          IsDesignTime;                                      // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function PlayerRankEmblem.PlayerRankEmblem_C.SetBannerInfo
// 0x0160 (0x0160 - 0x0000)
struct PlayerRankEmblem_C_SetBannerInfo final
{
public:
	struct FPlayerBannerInfo                      Banner;                                            // 0x0000(0x0028)(BlueprintVisible, BlueprintReadOnly, Parm)
	class FName                                   CallFunc_Conv_StringToName_ReturnValue;            // 0x0028(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   CallFunc_Conv_StringToName_ReturnValue_1;          // 0x0030(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData;              // 0x0038(0x0040)(HasGetValueTypeHash)
	class FText                                   CallFunc_Conv_StringToText_ReturnValue;            // 0x0078(0x0018)()
	class FText                                   CallFunc_Conv_StringToText_ReturnValue_1;          // 0x0090(0x0018)()
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData_1;            // 0x00A8(0x0040)(HasGetValueTypeHash)
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData_2;            // 0x00E8(0x0040)(HasGetValueTypeHash)
	TArray<struct FFormatArgumentData>            K2Node_MakeArray_Array;                            // 0x0128(0x0010)(ReferenceParm)
	class FText                                   CallFunc_Format_ReturnValue;                       // 0x0138(0x0018)()
	class FString                                 CallFunc_Conv_TextToString_ReturnValue;            // 0x0150(0x0010)(ZeroConstructor, HasGetValueTypeHash)
};

// Function PlayerRankEmblem.PlayerRankEmblem_C.SetBannerOwner
// 0x0030 (0x0030 - 0x0000)
struct PlayerRankEmblem_C_SetBannerOwner final
{
public:
	class AFortPlayerController*                  Target;                                            // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FUniqueNetIdRepl                       CallFunc_GetGameAccountId_ReturnValue;             // 0x0008(0x0028)(HasGetValueTypeHash)
};

// Function PlayerRankEmblem.PlayerRankEmblem_C.SetBannerSurroundLevel
// 0x0010 (0x0010 - 0x0000)
struct PlayerRankEmblem_C_SetBannerSurroundLevel final
{
public:
	int32                                         Level;                                             // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Animate;                                           // 0x0004(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_5[0x3];                                        // 0x0005(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UUMGSequencePlayer*                     CallFunc_PlayAnimation_ReturnValue;                // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

}

