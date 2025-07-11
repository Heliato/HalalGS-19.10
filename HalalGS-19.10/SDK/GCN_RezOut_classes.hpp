#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GCN_RezOut

#include "Basic.hpp"

#include "FortniteGame_classes.hpp"
#include "CoreUObject_structs.hpp"
#include "Engine_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass GCN_RezOut.GCN_RezOut_C
// 0x0190 (0x0600 - 0x0470)
class AGCN_RezOut_C final : public AFortGameplayCueNotify_BurstLatent
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0470(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	float                                         TFX_ResOutCharacterMesh_LightIntensity_E9C2D3554642468472CCCFA609A39FBC; // 0x0478(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         TFX_ResOutCharacterMesh_ZHeightParam_E9C2D3554642468472CCCFA609A39FBC; // 0x047C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         TFX_ResOutCharacterMesh_TransitionParam_E9C2D3554642468472CCCFA609A39FBC; // 0x0480(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            TFX_ResOutCharacterMesh__Direction_E9C2D3554642468472CCCFA609A39FBC; // 0x0484(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_485[0x3];                                      // 0x0485(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     TFX_ResOutCharacterMesh;                           // 0x0488(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         TFX_GlowCharacterMesh_EmissiveWarp_39A37BC9407CF090A09ABDA5A488F776; // 0x0490(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            TFX_GlowCharacterMesh__Direction_39A37BC9407CF090A09ABDA5A488F776; // 0x0494(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_495[0x3];                                      // 0x0495(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     TFX_GlowCharacterMesh;                             // 0x0498(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          DEBUG_ANIMATION;                                   // 0x04A0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          SpawnDrone;                                        // 0x04A1(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)
	uint8                                         Pad_4A2[0x6];                                      // 0x04A2(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	class UClass*                                 Teleportation_Drone;                               // 0x04A8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Teleport_Bot_AnimPlayRate;                         // 0x04B0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Teleport_Bot_Lifespan;                             // 0x04B4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UPointLightComponent*                   Teleportation_Point_Light;                         // 0x04B8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                Teleportation_Light_Offset;                        // 0x04C0(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           Teleportation_Light_Color;                         // 0x04CC(0x0010)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4DC[0x4];                                      // 0x04DC(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class UMaterialInstanceDynamic*>       DissolveMIDs;                                      // 0x04E0(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, AdvancedDisplay)
	class UMaterialInterface*                     Mat_Chracter_Dissolve;                             // 0x04F0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APlayerPawn_Athena_C*                   Pawn;                                              // 0x04F8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash)
	TSet<class USkeletalMeshComponent*>           Dissolve;                                          // 0x0500(0x0050)(Edit, BlueprintVisible, DisableEditOnInstance, ContainsInstancedReference, AdvancedDisplay)
	class FName                                   Socket_Mesh_Top;                                   // 0x0550(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash)
	float                                         Max_Light_Intensity;                               // 0x0558(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   Socket_Mesh_Bottom;                                // 0x055C(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash)
	uint8                                         Pad_564[0x4];                                      // 0x0564(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class USkeletalMeshComponent*>         Meshes_to_Dissolve;                                // 0x0568(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, ContainsInstancedReference, AdvancedDisplay)
	class ABP_TeleportationDrone_C*               Drone;                                             // 0x0578(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash)
	bool                                          DEBUG_CHILDCOMPONENTS;                             // 0x0580(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_581[0x7];                                      // 0x0581(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class UFXSystemComponent*>             Particle_Components;                               // 0x0588(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, ContainsInstancedReference, AdvancedDisplay)
	class UNiagaraComponent*                      Spawned_Death_VFX;                                 // 0x0598(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash)
	class UNiagaraSystem*                         Dissolve_Visual_Effect;                            // 0x05A0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   Dissolve_VFX_Spawn_Point_Name;                     // 0x05A8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAnimMontage*                           Base_Elimination_Montage;                          // 0x05B0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAnimMontage*                           DBNO_Elimination_Montage;                          // 0x05B8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAnimMontage*                           Skydiving_Elimination_Montage;                     // 0x05C0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAnimMontage*                           Swimming_Elimination_Montage;                      // 0x05C8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAnimMontage*                           DBNO_Swimming_Elimination_Montage;                 // 0x05D0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Spawn_VFX_Attached;                                // 0x05D8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_5D9[0x3];                                      // 0x05D9(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         Dissolve_Timeline_Playrate;                        // 0x05DC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Glow_Timeline_Playrate;                            // 0x05E0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          DEBUG_REMOVESPAWNVFX;                              // 0x05E4(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash)
	bool                                          DEBUG_REMOVESPAWNEDPOINTLIGHT;                     // 0x05E5(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash)
	uint8                                         Pad_5E6[0x2];                                      // 0x05E6(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	class UNiagaraSystem*                         Drone_Visual_Effect;                               // 0x05E8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   Drone_VFX_Attach_Point;                            // 0x05F0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          DEBUG_FXSYSTEMCOMPONENTS;                          // 0x05F8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void CleanMinusUp_Teleportation_Light();
	void Dissolve_Material_Setup();
	void ExecuteUbergraph_GCN_RezOut(int32 EntryPoint);
	void Play_Elmination_AnimMontage();
	void PreMinusSequence_Change();
	void Set_Additional_Niagara_Parameters_on_Drone_FX(class UNiagaraComponent* Drone_FX);
	void Set_Additional_Niagara_Parameters_on_Spawned_FX(class UNiagaraComponent* Spawned_Death_FX);
	void Set_Timeline_Playrates();
	void Spawn_Dissolve_VFX();
	void Spawn_Drone_VFX();
	void Spawn_Teleportation_Drone();
	void Spawn_Teleportation_Light();
	void Stop_Looping_Audio();
	void TFX_GlowCharacterMesh__FinishedFunc();
	void TFX_GlowCharacterMesh__UpdateFunc();
	void TFX_ResOutCharacterMesh__FinishedFunc();
	void TFX_ResOutCharacterMesh__UpdateFunc();

	void OnBurstGeneric(class AActor* MyTarget, const struct FGameplayCueParameters& Parameters, const TArray<class UFXSystemComponent*>& ParticleComponents, const TArray<class UAudioComponent*>& AudioComponents, class UMatineeCameraShake* BurstCameraShakeInstance, class ADecalActor* BurstDecalInstance) const;

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GCN_RezOut_C">();
	}
	static class AGCN_RezOut_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AGCN_RezOut_C>();
	}
};

}

