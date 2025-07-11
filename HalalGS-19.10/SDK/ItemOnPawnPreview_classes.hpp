#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ItemOnPawnPreview

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteGame_classes.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass ItemOnPawnPreview.ItemOnPawnPreview_C
// 0x00E0 (0x0620 - 0x0540)
class AItemOnPawnPreview_C final : public AFortItemPreviewOnPawnActor
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0540(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class USkyLightComponent*                     SkyLightPC;                                        // 0x0548(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UArrowComponent*                        Arrow;                                             // 0x0550(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USkyLightComponent*                     SkyLightLowMobile;                                 // 0x0558(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UDirectionalLightComponent*             DirectionalLightMobile;                            // 0x0560(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USpotLightComponent*                    KeyLight_StandaloneForSwitch;                      // 0x0568(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USpotLightComponent*                    KeyLight5;                                         // 0x0570(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USpotLightComponent*                    KeyLight6;                                         // 0x0578(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USpotLightComponent*                    KeyLigh3;                                          // 0x0580(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USpotLightComponent*                    KeyLight2;                                         // 0x0588(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USpotLightComponent*                    BounceRear1;                                       // 0x0590(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USpotLightComponent*                    RimLowerRight1;                                    // 0x0598(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USpotLightComponent*                    RimLeft1;                                          // 0x05A0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USpotLightComponent*                    RimTopRight1;                                      // 0x05A8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USpotLightComponent*                    RimBottomLeft1;                                    // 0x05B0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USpotLightComponent*                    Bounce1;                                           // 0x05B8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USceneComponent*                        LightTransform;                                    // 0x05C0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   Plane;                                             // 0x05C8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USkeletalMeshComponent*                 Sample_Mesh;                                       // 0x05D0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	bool                                          AlwaysOn;                                          // 0x05D8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          IsActive;                                          // 0x05D9(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          DebugConstructionLighting;                         // 0x05DA(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_5DB[0x5];                                      // 0x05DB(0x0005)(Fixing Size After Last Property [ Dumper-7 ])
	class UParticleSystemComponent*               ObscuringLoopEmitter;                              // 0x05E0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FRotator                               ToonLightRotatio;                                  // 0x05E8(0x000C)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          bIsBattlePassReward;                               // 0x05F4(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_5F5[0x3];                                      // 0x05F5(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTimerHandle                           LOD_StreamingSafetyTimer;                          // 0x05F8(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	float                                         LOD_StreamingSafetyDuration;                       // 0x0600(0x0004)(Edit, BlueprintVisible, ZeroConstructor, Config, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_604[0x4];                                      // 0x0604(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UMaterialInterface*                     DefaultFloorMaterial;                              // 0x0608(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMaterialInterface*                     CustomFloorMaterial;                               // 0x0610(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void UpdateSettings();
	void SwitchPCLighting(bool Visibility);
	void SwitchMobileLighting(bool NewParam);
	void SwitchErebusLighting(bool Visibility);
	void SetFloorEnabled(bool Show_Floor);
	void ReceiveBeginPlay();
	void OnUpdateFloorMaterial(bool bEnableAutotestBackground);
	void OnPreviewVisualsSpawned(const bool bUseSecondaryTransitionEffects, const bool bShowFloor);
	void OnSetFloorMaterial(class UMaterialInterface* InMaterialInstance);
	void OnCurrentVisualsCleanedUp();
	void OnAllLODStreamingComplete();
	void LightControl(bool Active);
	void ExecuteUbergraph_ItemOnPawnPreview(int32 EntryPoint);
	void Backup_LODStreamingFailed();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"ItemOnPawnPreview_C">();
	}
	static class AItemOnPawnPreview_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AItemOnPawnPreview_C>();
	}
};

}

