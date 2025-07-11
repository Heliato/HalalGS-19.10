#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_FortniteLobbyLightSwitcher

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "Engine_structs.hpp"
#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_FortniteLobbyLightSwitcher.BP_FortniteLobbyLightSwitcher_C
// 0x0090 (0x02B0 - 0x0220)
class ABP_FortniteLobbyLightSwitcher_C final : public AActor
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0220(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class USceneComponent*                        DefaultSceneRoot;                                  // 0x0228(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class ADirectionalLight*                      DirectionLight;                                    // 0x0230(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ASkyLight*                              SkyLight;                                          // 0x0238(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<class APointLight*>                    Pointlights;                                       // 0x0240(0x0010)(Edit, BlueprintVisible, DisableEditOnTemplate)
	class AExponentialHeightFog*                  ExponentialHeightFog;                              // 0x0250(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ADirectionalLight*                      DirectionalLight_LowDetailMode;                    // 0x0258(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<class AEmitter*>                       ParticleSystems;                                   // 0x0260(0x0010)(Edit, BlueprintVisible, DisableEditOnTemplate)
	bool                                          IsActive;                                          // 0x0270(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          DebugLOWQualityLighting;                           // 0x0271(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_272[0x6];                                      // 0x0272(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	class ASkyLight*                              SkyLight_LowDetailMode;                            // 0x0278(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AExponentialHeightFog*                  ExponentialHeightfog_LowDetailMode;                // 0x0280(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          LOW_FX_Setting_Use_MobileLighting;                 // 0x0288(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          IsLightalreadyActive;                              // 0x0289(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_28A[0x2];                                      // 0x028A(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	struct FLinearColor                           MPCMinusManualSunlightVector;                      // 0x028C(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           MPCMinusManualSunlightColor;                       // 0x029C(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void UserConstructionScript();
	void UpdateSettings();
	void ExecuteUbergraph_BP_FortniteLobbyLightSwitcher(int32 EntryPoint);
	void EnableLobbySetLighting();
	void SetVisiblityofSceneLighting(bool Activate);
	void SetVisiblityofDetailSpecificMeshes();
	void ReceiveBeginPlay();
	void DisableLobbySetLighting();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_FortniteLobbyLightSwitcher_C">();
	}
	static class ABP_FortniteLobbyLightSwitcher_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABP_FortniteLobbyLightSwitcher_C>();
	}
};

}

