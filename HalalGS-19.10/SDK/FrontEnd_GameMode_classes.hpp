#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: FrontEnd_GameMode

#include "Basic.hpp"

#include "FortniteGame_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass FrontEnd_GameMode.FrontEnd_GameMode_C
// 0x0008 (0x06C8 - 0x06C0)
class AFrontEnd_GameMode_C final : public AFortGameModeFrontEnd
{
public:
	class USceneComponent*                        DefaultSceneRoot;                                  // 0x06C0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"FrontEnd_GameMode_C">();
	}
	static class AFrontEnd_GameMode_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AFrontEnd_GameMode_C>();
	}
};

}

