#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: RadialMenuTestEntry

#include "Basic.hpp"

#include "CommonUILegacy_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass RadialMenuTestEntry.RadialMenuTestEntry_C
// 0x0010 (0x0F10 - 0x0F00)
class URadialMenuTestEntry_C final : public UCommonButtonLegacy
{
public:
	uint8                                         Pad_EF8[0x8];                                      // 0x0EF8(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	class UImage*                                 Image_82;                                          // 0x0F00(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"RadialMenuTestEntry_C">();
	}
	static class URadialMenuTestEntry_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<URadialMenuTestEntry_C>();
	}
};

}

