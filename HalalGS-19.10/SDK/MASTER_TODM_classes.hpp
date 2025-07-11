#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: MASTER_TODM

#include "Basic.hpp"

#include "FortniteGame_classes.hpp"
#include "CoreUObject_structs.hpp"
#include "Engine_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass MASTER_TODM.MASTER_TODM_C
// 0x0210 (0x1120 - 0x0F10)
class AMASTER_TODM_C : public AFortTimeOfDayManager
{
public:
	uint8                                         Pad_F08[0x8];                                      // 0x0F08(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0F10(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UPostProcessComponent*                  HeavySSAO_Postprocess;                             // 0x0F18(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UPostProcessComponent*                  EditorPostProcessMaterial_HackToWorkAroundTheOutlineShaderBeingInjectedByCodeAtRuntime_; // 0x0F20(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	float                                         New_Storm_Timeline_Wind_Strength_5E5E494B489306ED044096A143F228CF; // 0x0F28(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         New_Storm_Timeline_RainInt_5E5E494B489306ED044096A143F228CF; // 0x0F2C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         New_Storm_Timeline_Lightning_Modulator_5E5E494B489306ED044096A143F228CF; // 0x0F30(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         New_Storm_Timeline_Storm_Ramp_In_Value_5E5E494B489306ED044096A143F228CF; // 0x0F34(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            New_Storm_Timeline__Direction_5E5E494B489306ED044096A143F228CF; // 0x0F38(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_F39[0x7];                                      // 0x0F39(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     New_Storm_Timeline;                                // 0x0F40(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         FlashLightning_LightningColorLERP_FA5447C54EBAE729F521C3B243BEC285; // 0x0F48(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         FlashLightning_lightning_alpha_FA5447C54EBAE729F521C3B243BEC285; // 0x0F4C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         FlashLightning_Lightning_Intensity_FA5447C54EBAE729F521C3B243BEC285; // 0x0F50(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            FlashLightning__Direction_FA5447C54EBAE729F521C3B243BEC285; // 0x0F54(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_F55[0x3];                                      // 0x0F55(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     FlashLightning;                                    // 0x0F58(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         WindSpeed;                                         // 0x0F60(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         RandomWeatherWaitTime;                             // 0x0F64(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CurrentAmountOfRandomWeatherTimeLeft;              // 0x0F68(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         NewWeatherLerpAmount;                              // 0x0F6C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         WindStrength;                                      // 0x0F70(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         FutureWindStrength;                                // 0x0F74(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         FutureWindSpeed;                                   // 0x0F78(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bPickNewWindConditions;                            // 0x0F7C(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_F7D[0x3];                                      // 0x0F7D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         LightningStrength;                                 // 0x0F80(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         ThreatCloudStormAmount;                            // 0x0F84(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          UseRainWithStorms;                                 // 0x0F88(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Play_a_Particle_Effect_Near_the_players_Feet;      // 0x0F89(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          WindEffects_Should_be_Active;                      // 0x0F8A(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_F8B[0x5];                                      // 0x0F8B(0x0005)(Fixing Size After Last Property [ Dumper-7 ])
	class UParticleSystemComponent*               Storm_Foot_Particle_Outdoor;                       // 0x0F90(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystem*                        Storm_Foot_Particle_While_on_Terrain;              // 0x0F98(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystemComponent*               Storm_Foot_Particle_Indoor;                        // 0x0FA0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystem*                        Storm_Foot_Particle_While_NOT_on_Terrain;          // 0x0FA8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Storm_Wind_Strength;                               // 0x0FB0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Generate_Foliage_Wind_Gusts;                       // 0x0FB4(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_FB5[0x3];                                      // 0x0FB5(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTimerHandle                           LightningStrikeTimerHandle;                        // 0x0FB8(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           PreviousDirectionalLightColor;                     // 0x0FC0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           Lightning_Flash_Color;                             // 0x0FD0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)
	float                                         Lightning_Flash_Timeline_Min;                      // 0x0FE0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Lightning_Flash_Timeline_Max;                      // 0x0FE4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           SkyboxFogMorningColor;                             // 0x0FE8(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           SkyboxFogMorningLitColor;                          // 0x0FF8(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SkyboxFogMorningDistance;                          // 0x1008(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SkyboxFogMorningDiffuseAmount;                     // 0x100C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SkyboxFogMorningEmissiveAmount;                    // 0x1010(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SkyboxFogMorningLitLength;                         // 0x1014(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SkyboxFogMorningLitRotation;                       // 0x1018(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SkyboxFogMorningLitOffset;                         // 0x101C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           SkyboxFogDayColor;                                 // 0x1020(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           SkyboxFogDayLitColor;                              // 0x1030(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SkyboxFogDayDistance;                              // 0x1040(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SkyboxFogDayDiffuseAmount;                         // 0x1044(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SkyboxFogDayEmissiveAmount;                        // 0x1048(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SkyboxFogDayLitLength;                             // 0x104C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SkyboxFogDayLitRotation;                           // 0x1050(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SkyboxFogDayLitOffset;                             // 0x1054(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           SkyboxFogEveningColor;                             // 0x1058(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           SkyboxFogEveningLitColor;                          // 0x1068(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SkyboxFogEveningDistance;                          // 0x1078(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SkyboxFogEveningDiffuseAmount;                     // 0x107C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SkyboxFogEveningEmissiveAmount;                    // 0x1080(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SkyboxFogEveningLitLength;                         // 0x1084(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SkyboxFogEveningLitRotation;                       // 0x1088(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SkyboxFogEveningLitOffset;                         // 0x108C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           SkyboxFogNightColor;                               // 0x1090(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           SkyboxFogNightLitColor;                            // 0x10A0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SkyboxFogNightDistance;                            // 0x10B0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SkyboxFogNightDiffuseAmount;                       // 0x10B4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SkyboxFogNightEmissiveAmount;                      // 0x10B8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SkyboxFogNightLitLength;                           // 0x10BC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SkyboxFogNightLitRotation;                         // 0x10C0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SkyboxFogNightLitOffset;                           // 0x10C4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         World_Border_Cloud_Base_Color_Brightness;          // 0x10C8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           World_Border_Cloud_Sub_Surface_Color_and_Opacity;  // 0x10CC(0x0010)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          EnableCometDynamicPlacement;                       // 0x10DC(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_10DD[0x3];                                     // 0x10DD(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector4                               Night;                                             // 0x10E0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector4                               Evening;                                           // 0x10F0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector4                               Day;                                               // 0x1100(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector4                               Morning;                                           // 0x1110(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void UserConstructionScript();
	void UpdateSSAO();
	void StartStorm();
	void SetHeavySSAO();
	void ReceiveBeginPlay();
	void OnStormStart();
	void OnStormEnd();
	void New_Storm_Timeline__UpdateFunc();
	void New_Storm_Timeline__FireOffRain__EventFunc();
	void New_Storm_Timeline__FinishedFunc();
	void LightningStrike();
	void FlashLightning__UpdateFunc();
	void FlashLightning__FinishedFunc();
	void ExecuteUbergraph_MASTER_TODM(int32 EntryPoint);
	void EnableHDRRendering();
	void EmptyTransform(struct FTransform* Transform);
	void DisableLightAndFog(bool Enable);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"MASTER_TODM_C">();
	}
	static class AMASTER_TODM_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AMASTER_TODM_C>();
	}
};

}

