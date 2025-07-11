#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BacchusItemShopNavigator

#include "Basic.hpp"

#include "FortniteUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass BacchusItemShopNavigator.BacchusItemShopNavigator_C
// 0x0010 (0x02B8 - 0x02A8)
class UBacchusItemShopNavigator_C final : public UAthenaItemShopSectionNavigator
{
public:
	class USafeZone*                              ForceDownSafeZone;                                 // 0x02A8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USafeZone*                              ForceUpSaveZone;                                   // 0x02B0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BacchusItemShopNavigator_C">();
	}
	static class UBacchusItemShopNavigator_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UBacchusItemShopNavigator_C>();
	}
};

}

