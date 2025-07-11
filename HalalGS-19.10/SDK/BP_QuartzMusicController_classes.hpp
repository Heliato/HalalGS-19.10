#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_QuartzMusicController

#include "Basic.hpp"

#include "FortniteGame_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_QuartzMusicController.BP_QuartzMusicController_C
// 0x0020 (0x0240 - 0x0220)
class ABP_QuartzMusicController_C : public AFortTimeSynthController
{
public:
	class USceneComponent*                        DefaultSceneRoot;                                  // 0x0220(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UQuartzMusicTrackComponent_C*           CurrentTrack;                                      // 0x0228(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	FMulticastInlineDelegateProperty_             OnClockCreated;                                    // 0x0230(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)

public:
	void OnClockCreated__DelegateSignature(class FName Clock_Name, class UQuartzClockHandle* Clock_Handle);
	void PlayTrack(class UQuartzMusicTrackComponent_C* Track_Component);
	void RequestTrackPlayback(class UQuartzMusicTrackComponent_C* Requesting_Track, bool* Result);
	void StopCurrentTrack();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_QuartzMusicController_C">();
	}
	static class ABP_QuartzMusicController_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABP_QuartzMusicController_C>();
	}
};

}

