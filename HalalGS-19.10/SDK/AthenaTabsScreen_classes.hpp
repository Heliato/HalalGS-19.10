#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AthenaTabsScreen

#include "Basic.hpp"

#include "FortniteUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass AthenaTabsScreen.AthenaTabsScreen_C
// 0x0010 (0x0378 - 0x0368)
class UAthenaTabsScreen_C final : public UFortAthenaTabsScreenBase
{
public:
	class UItemShopScreen_C*                      CatabaScreen;                                      // 0x0368(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USafeZone*                              SafeZoneContent;                                   // 0x0370(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"AthenaTabsScreen_C">();
	}
	static class UAthenaTabsScreen_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UAthenaTabsScreen_C>();
	}
};

}

