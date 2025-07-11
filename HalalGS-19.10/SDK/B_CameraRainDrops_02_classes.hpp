#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: B_CameraRainDrops_02

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass B_CameraRainDrops_02.B_CameraRainDrops_02_C
// 0x0020 (0x0300 - 0x02E0)
class AB_CameraRainDrops_02_C final : public AEmitterCameraLensEffectBase
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x02E0(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	float                                         Alpha_Alpha_DCEE07724A8E0C236CD3F49821233A51;      // 0x02E8(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            Alpha__Direction_DCEE07724A8E0C236CD3F49821233A51; // 0x02EC(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2ED[0x3];                                      // 0x02ED(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     Alpha;                                             // 0x02F0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void Alpha__FinishedFunc();
	void Alpha__UpdateFunc();
	void ExecuteUbergraph_B_CameraRainDrops_02(int32 EntryPoint);
	void ReceiveBeginPlay();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"B_CameraRainDrops_02_C">();
	}
	static class AB_CameraRainDrops_02_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AB_CameraRainDrops_02_C>();
	}
};

}

