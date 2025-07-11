#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: EventLeaderboardHeader

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass EventLeaderboardHeader.EventLeaderboardHeader_C
// 0x0018 (0x0700 - 0x06E8)
class UEventLeaderboardHeader_C final : public UFortShowdownDetailView
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x06E8(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UCommonBorder*                          CommonBorder_ScoringTitleBG;                       // 0x06F0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       Text_RoundTitle;                                   // 0x06F8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_EventLeaderboardHeader(int32 EntryPoint);
	void RefreshDataBP();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"EventLeaderboardHeader_C">();
	}
	static class UEventLeaderboardHeader_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UEventLeaderboardHeader_C>();
	}
};

}

