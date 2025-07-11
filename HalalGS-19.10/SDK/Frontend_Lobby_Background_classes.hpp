#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Frontend_Lobby_Background

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FrontendBackgroundData_structs.hpp"
#include "FortniteGame_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass Frontend_Lobby_Background.Frontend_Lobby_Background_C
// 0x02F8 (0x0530 - 0x0238)
class AFrontend_Lobby_Background_C final : public AFortLevelScriptActor
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0238(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	float                                         FadeIn_Fade_3606FDF647A6577B9DAC47B89146CD85;      // 0x0240(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            FadeIn__Direction_3606FDF647A6577B9DAC47B89146CD85; // 0x0244(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_245[0x3];                                      // 0x0245(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     FadeIn;                                            // 0x0248(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         FadeOut_Fade_44D3B05B49031FA3891648AB32F57584;     // 0x0250(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            FadeOut__Direction_44D3B05B49031FA3891648AB32F57584; // 0x0254(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_255[0x3];                                      // 0x0255(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     FadeOut;                                           // 0x0258(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         FadetoBlackFloor;                                  // 0x0260(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         FadeGrid;                                          // 0x0264(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         FadeGrid_Targetvalue;                              // 0x0268(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         FadetoBlackFloor_TargetValue;                      // 0x026C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FString                                 PresetEnvironment;                                 // 0x0270(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, HasGetValueTypeHash)
	class UTexture*                               Texture;                                           // 0x0280(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMaterialInstance*                      Material;                                          // 0x0288(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMaterialInstance*                      PreBlueMaterial;                                   // 0x0290(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TMap<class FString, struct FFrontendBackgroundData> Backgrounds;                                       // 0x0298(0x0050)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	class ANiagaraActor*                          NiagaraActor_6_ExecuteUbergraph_Frontend_Lobby_Background_RefProperty; // 0x02E8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ABP_FrontendBackPlate_C*                Six_ExecuteUbergraph_Frontend_Lobby_Background_RefProperty; // 0x02F0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AEmitter*                               P_Storm_Rain_01_5_ExecuteUbergraph_Frontend_Lobby_Background_RefProperty; // 0x02F8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AEmitter*                               P_Snow_Ambient_Lobby_2_ExecuteUbergraph_Frontend_Lobby_Background_RefProperty; // 0x0300(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   SM_Sideways_Smoke_FrontEnd_159_ExecuteUbergraph_Frontend_Lobby_Background_RefProperty; // 0x0308(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   SM_Mother_Crash_BlinkingLights_01_3_ExecuteUbergraph_Frontend_Lobby_Background_RefProperty; // 0x0310(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   SM_Sideways_Smoke_FrontEnd_0_ExecuteUbergraph_Frontend_Lobby_Background_RefProperty; // 0x0318(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ANiagaraActor*                          NiagaraActor_2_ExecuteUbergraph_Frontend_Lobby_Background_RefProperty; // 0x0320(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ANiagaraActor*                          NiagaraActor_4_ExecuteUbergraph_Frontend_Lobby_Background_RefProperty; // 0x0328(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ANiagaraActor*                          NiagaraActor_1_ExecuteUbergraph_Frontend_Lobby_Background_RefProperty; // 0x0330(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ANiagaraActor*                          NiagaraActor_5_ExecuteUbergraph_Frontend_Lobby_Background_RefProperty; // 0x0338(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ABP_FrontendBackPlate_C*                Six_EdGraph_2_RefProperty;                         // 0x0340(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_08_Bug_EdGraph_3_RefProperty; // 0x0348(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_08_EdGraph_3_RefProperty;  // 0x0350(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_07_Bug_EdGraph_3_RefProperty; // 0x0358(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_07_EdGraph_3_RefProperty;  // 0x0360(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_06_Bug_EdGraph_3_RefProperty; // 0x0368(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_06_EdGraph_3_RefProperty;  // 0x0370(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_05_Bug_EdGraph_3_RefProperty; // 0x0378(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_05_EdGraph_3_RefProperty;  // 0x0380(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_04_Bug_EdGraph_3_RefProperty; // 0x0388(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_04_EdGraph_3_RefProperty;  // 0x0390(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_03_Bug_EdGraph_3_RefProperty; // 0x0398(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_03_EdGraph_3_RefProperty;  // 0x03A0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_02_Bug_EdGraph_3_RefProperty; // 0x03A8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_02_EdGraph_3_RefProperty;  // 0x03B0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_01_Bug_EdGraph_3_RefProperty; // 0x03B8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_01_EdGraph_3_RefProperty;  // 0x03C0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage02_04_Bug_EdGraph_3_RefProperty; // 0x03C8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage02_04_EdGraph_3_RefProperty;  // 0x03D0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage02_03_Bug_EdGraph_3_RefProperty; // 0x03D8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage02_03_EdGraph_3_RefProperty;  // 0x03E0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage02_02_Bug_EdGraph_3_RefProperty; // 0x03E8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage02_02_EdGraph_3_RefProperty;  // 0x03F0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage02_01_Bug_EdGraph_3_RefProperty; // 0x03F8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage02_01_EdGraph_3_RefProperty;  // 0x0400(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage02_02_2_EdGraph_3_RefProperty; // 0x0408(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage01_02_Bug_EdGraph_3_RefProperty; // 0x0410(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage01_01_Bug_EdGraph_3_RefProperty; // 0x0418(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage01_01_EdGraph_3_RefProperty;  // 0x0420(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ABP_FrontendBackPlate_C*                Six_EdGraph_5_RefProperty;                         // 0x0428(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ABP_FrontendBackPlate_C*                Six_EdGraph_6_RefProperty;                         // 0x0430(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_08_Bug_EdGraph_7_RefProperty; // 0x0438(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_08_EdGraph_7_RefProperty;  // 0x0440(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_07_Bug_EdGraph_7_RefProperty; // 0x0448(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_07_EdGraph_7_RefProperty;  // 0x0450(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_06_Bug_EdGraph_7_RefProperty; // 0x0458(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_06_EdGraph_7_RefProperty;  // 0x0460(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_05_Bug_EdGraph_7_RefProperty; // 0x0468(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_05_EdGraph_7_RefProperty;  // 0x0470(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_04_Bug_EdGraph_7_RefProperty; // 0x0478(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_04_EdGraph_7_RefProperty;  // 0x0480(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_03_Bug_EdGraph_7_RefProperty; // 0x0488(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_03_EdGraph_7_RefProperty;  // 0x0490(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_02_Bug_EdGraph_7_RefProperty; // 0x0498(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_02_EdGraph_7_RefProperty;  // 0x04A0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_01_Bug_EdGraph_7_RefProperty; // 0x04A8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage03_01_EdGraph_7_RefProperty;  // 0x04B0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage02_04_Bug_EdGraph_7_RefProperty; // 0x04B8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage02_04_EdGraph_7_RefProperty;  // 0x04C0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage02_03_Bug_EdGraph_7_RefProperty; // 0x04C8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage02_03_EdGraph_7_RefProperty;  // 0x04D0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage02_02_Bug_EdGraph_7_RefProperty; // 0x04D8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage02_02_EdGraph_7_RefProperty;  // 0x04E0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage02_01_Bug_EdGraph_7_RefProperty; // 0x04E8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage02_01_EdGraph_7_RefProperty;  // 0x04F0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage02_02_2_EdGraph_7_RefProperty; // 0x04F8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage01_02_Bug_EdGraph_7_RefProperty; // 0x0500(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage01_01_Bug_EdGraph_7_RefProperty; // 0x0508(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortStaticMeshActor*                   AvocadoParasite_Stage01_01_EdGraph_7_RefProperty;  // 0x0510(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ABP_FrontendBackPlate_C*                Six_EdGraph_7_RefProperty;                         // 0x0518(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ABP_FrontendBackPlate_C*                Six_EdGraph_8_RefProperty;                         // 0x0520(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ABP_FrontendBackPlate_C*                Six_EdGraph_9_RefProperty;                         // 0x0528(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void BndEvt__CMSLobbyDirector_3_K2Node_ActorBoundEvent_0_OnEnvironmentChangedDynamic__DelegateSignature(const class FString& PresetEnvironmentName);
	void BndEvt__CMSLobbyDirector_3_K2Node_ActorBoundEvent_1_OnEnvironmentBackgroundTextureChangedDynamic__DelegateSignature(class UTexture* BackgroundImage);
	void ContinueBackgroundSetup();
	void ExecuteUbergraph_Frontend_Lobby_Background(int32 EntryPoint);
	void FadeFromBlue();
	void FadeIn__FinishedFunc();
	void FadeIn__UpdateFunc();
	void FadeOut__FinishedFunc();
	void FadeOut__UpdateFunc();
	void HideAvocadoActors();
	void LoadAssets(TSoftObjectPtr<class UTexture> InTexture, TSoftObjectPtr<class UMaterialInstance> InMaterial, TSoftObjectPtr<class UMaterialInstance> InPreBlurMaterial);
	void LoadBackgroundData();
	void OnLoaded_7B16DAE04937EECB604410A2EC352CE3(class UObject* Loaded);
	void OnLoaded_D6DC1C6545F1A19E2FFC1B9CDACD5E99(class UObject* Loaded);
	void OnLoaded_E5F1E80A4DD36718D41FF68F137C4775(class UObject* Loaded);
	void ReceiveBeginPlay();
	void SetShowPedestalSparkles(bool Show);
	void Setup_Basic_Background_Data(bool EnableRealtimeUpdate, float InFadeGridTargetValue, float InFadeToBlackFloorTargetValue);
	void SetupBasicBackgroundDataWithRenderTarget(bool EnableRealtimeUpdate, float InFadeGridTargetValue, float InFadeToBlackFloorTargetValue);
	void SetupGalileo();
	void SetupSeason17BackgroundData(bool HidePhase1, bool HidePhase2, bool HidePhase3);
	void SetupSpecialEventBackgroundData(bool EnableRealtimeUpdate, float InFadeGridTargetValue, float InFadeToBlackFloorTargetValue);
	void SetupSpecialEventBackgroundDataWithRenderTarget(bool EnableRealtimeUpdate, float InFadeGridTargetValue, float InFadeToBlackFloorTargetValue);
	void TestDynColor();
	void UpdateFade(float FadeValue, float FadeFloorToBlack, float InFadeGrid);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Frontend_Lobby_Background_C">();
	}
	static class AFrontend_Lobby_Background_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AFrontend_Lobby_Background_C>();
	}
};

}

