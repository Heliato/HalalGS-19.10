#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: B_CameraLens_Geyser

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass B_CameraLens_Geyser.B_CameraLens_Geyser_C
// 0x0020 (0x0300 - 0x02E0)
class AB_CameraLens_Geyser_C final : public AEmitterCameraLensEffectBase
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x02E0(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	float                                         Timeline_0_Alpha_3D5AA2144E9B8D6D3B409B845315B143; // 0x02E8(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            Timeline_0__Direction_3D5AA2144E9B8D6D3B409B845315B143; // 0x02EC(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2ED[0x3];                                      // 0x02ED(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     Timeline_0;                                        // 0x02F0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_B_CameraLens_Geyser(int32 EntryPoint);
	void ReceiveBeginPlay();
	void ReceiveDestroyed();
	void Timeline_0__FinishedFunc();
	void Timeline_0__UpdateFunc();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"B_CameraLens_Geyser_C">();
	}
	static class AB_CameraLens_Geyser_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AB_CameraLens_Geyser_C>();
	}
};

}

