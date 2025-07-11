#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ShowdownTournamentTile

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass ShowdownTournamentTile.ShowdownTournamentTile_C
// 0x0030 (0x0F60 - 0x0F30)
class UShowdownTournamentTile_C final : public UFortShowdownTournamentTile
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0F30(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       SizeUp;                                            // 0x0F38(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       ChangeFocus;                                       // 0x0F40(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UImage*                                 Image_TileFade;                                    // 0x0F48(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USizeBox*                               PosterSizeBox;                                     // 0x0F50(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	bool                                          IsFaded;                                           // 0x0F58(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void BP_OnDeselected();
	void BP_OnSelected();
	void EventFade(bool FadeOut);
	void ExecuteUbergraph_ShowdownTournamentTile(int32 EntryPoint);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"ShowdownTournamentTile_C">();
	}
	static class UShowdownTournamentTile_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UShowdownTournamentTile_C>();
	}
};

}

