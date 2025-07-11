#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Tiered_Safe_Athena_Parent

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteGame_structs.hpp"
#include "FortniteGame_classes.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass Tiered_Safe_Athena_Parent.Tiered_Safe_Athena_Parent_C
// 0x00E0 (0x0F98 - 0x0EB8)
class ATiered_Safe_Athena_Parent_C : public ABuildingContainer
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0EB8(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UParticleSystemComponent*               P_Loot_Chest_Aura_Athena;                          // 0x0EC0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   S_Chest_SmokeSheet;                                // 0x0EC8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UPointLightComponent*                   TreasureLight;                                     // 0x0ED0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UAudioComponent*                        Chest_Ambient_Sound;                               // 0x0ED8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	float                                         Timeline_0_Time_396046034CABC1528CF338A149138331;  // 0x0EE0(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            Timeline_0__Direction_396046034CABC1528CF338A149138331; // 0x0EE4(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_EE5[0x3];                                      // 0x0EE5(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     Timeline_0;                                        // 0x0EE8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         MobileSelectedTL_LerpInteactoIcon_0B00BD1F4FF6CFBAD690D4AA66867AA5; // 0x0EF0(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         MobileSelectedTL_LerpObject_0B00BD1F4FF6CFBAD690D4AA66867AA5; // 0x0EF4(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            MobileSelectedTL__Direction_0B00BD1F4FF6CFBAD690D4AA66867AA5; // 0x0EF8(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_EF9[0x7];                                      // 0x0EF9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     MobileSelectedTL;                                  // 0x0F00(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         MobileOnInteractTL_LERP_7EBF522744343C22AB6D13B401F9E612; // 0x0F08(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            MobileOnInteractTL__Direction_7EBF522744343C22AB6D13B401F9E612; // 0x0F0C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_F0D[0x3];                                      // 0x0F0D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     MobileOnInteractTL;                                // 0x0F10(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystemComponent*               Loot_Effect;                                       // 0x0F18(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             SpecialChestOpenSound;                             // 0x0F20(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<class UMaterialInstanceDynamic*>       MIDs;                                              // 0x0F28(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	float                                         MobileWiggleAmount;                                // 0x0F38(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         ChestChimeVisualUpdate;                            // 0x0F3C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMaterialInterface*                     MobileInteractionMaterial;                         // 0x0F40(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   MobileInteractIcon;                                // 0x0F48(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                MobileInteractIconLocation;                        // 0x0F50(0x000C)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                MobileInteractIconScale;                           // 0x0F5C(0x000C)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             Open_Chest_Sound;                                  // 0x0F68(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystem*                        P_Loot_Chest_Opened_FX;                            // 0x0F70(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystemComponent*               NewVar_0;                                          // 0x0F78(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystemComponent*               NewVar_1;                                          // 0x0F80(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystem*                        Galileo_Chest_Open_FX;                             // 0x0F88(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         OpenFX_Rotation;                                   // 0x0F90(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          EnableAudioIndicator;                              // 0x0F94(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void CleanupWiggleMIDs();
	void CreateMobileMIDs();
	void DetermineVFXRotation();
	void DisableBacchusHighlight();
	void EnableBacchusHighlight();
	void ExecuteUbergraph_Tiered_Safe_Athena_Parent(int32 EntryPoint);
	void GetMaxAudibleDistance(float* Max_Distance);
	void HideChestOpenableCosmetics();
	void Mobile_OnDisconnect();
	void Mobile_OnInteract();
	void Mobile_Outline_Off();
	void Mobile_Outline_On();
	void MobileOnInteractTL__FinishedFunc();
	void MobileOnInteractTL__UpdateFunc();
	void MobileSelectedTL__FinishedFunc();
	void MobileSelectedTL__UpdateFunc();
	void OnBeginSearch();
	void OnDeathPlayEffects(float Damage, const struct FGameplayTagContainer& DamageTags, const struct FVector& Momentum, const struct FHitResult& HitInfo, class AFortPawn* InstigatedBy, class AActor* DamageCauser, const struct FGameplayEffectContextHandle& EffectContext);
	void OnLoot();
	void OnSetCustomDepthStencilValue(const TArray<class UPrimitiveComponent*>& PrimComponents, bool bUseCustomDepth, int32 StencilValue, bool* bOutConsume);
	void OnSetSearched();
	void PlayChestOpeningTimeline();
	void ReceiveBeginPlay();
	void ReceiveDestroyed();
	void SetLightVisibility(bool Visible);
	void SetVisibleMobileInteractIcon(bool Visible);
	bool ShouldDie(float Damage, class AController* EventInstigator, class AActor* DamageCauser);
	void SpawnChestOpenVFX();
	void Timeline_0__FinishedFunc();
	void Timeline_0__UpdateFunc();
	void UserConstructionScript();

	bool BlueprintCanInteract(const class AFortPawn* InteractingPawn, const EInteractionBeingAttempted InteractionBeingAttempted, const ETInteractionType InteractionType) const;

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Tiered_Safe_Athena_Parent_C">();
	}
	static class ATiered_Safe_Athena_Parent_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ATiered_Safe_Athena_Parent_C>();
	}
};

}

