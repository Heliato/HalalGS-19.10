#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: S18_PlayerBattlePassXpAndReward

#include "Basic.hpp"

#include "Engine_structs.hpp"


namespace SDK::Params
{

// Function S18_PlayerBattlePassXpAndReward.S18_PlayerBattlePassXpAndReward_C.Update Text
// 0x0128 (0x0128 - 0x0000)
struct S18_PlayerBattlePassXpAndReward_C_Update_Text final
{
public:
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData;              // 0x0000(0x0040)(HasGetValueTypeHash)
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x0040(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_44[0x4];                                       // 0x0044(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FFormatArgumentData>            K2Node_MakeArray_Array;                            // 0x0048(0x0010)(ReferenceParm)
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData_1;            // 0x0058(0x0040)(HasGetValueTypeHash)
	class FText                                   CallFunc_Format_ReturnValue;                       // 0x0098(0x0018)()
	class UMaterialInstanceDynamic*               CallFunc_GetDynamicMaterial_ReturnValue;           // 0x00B0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Subtract_IntInt_ReturnValue;              // 0x00B8(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_BC[0x4];                                       // 0x00BC(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData_2;            // 0x00C0(0x0040)(HasGetValueTypeHash)
	TArray<struct FFormatArgumentData>            K2Node_MakeArray_Array_1;                          // 0x0100(0x0010)(ReferenceParm)
	class FText                                   CallFunc_Format_ReturnValue_1;                     // 0x0110(0x0018)()
};

// Function S18_PlayerBattlePassXpAndReward.S18_PlayerBattlePassXpAndReward_C.ExecuteUbergraph_S18_PlayerBattlePassXpAndReward
// 0x0010 (0x0010 - 0x0000)
struct S18_PlayerBattlePassXpAndReward_C_ExecuteUbergraph_S18_PlayerBattlePassXpAndReward final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UMaterialInstanceDynamic*               CallFunc_GetDynamicMaterial_ReturnValue;           // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

}

