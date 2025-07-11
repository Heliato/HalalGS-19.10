#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GAB_Emote_Generic

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "GameplayTags_structs.hpp"
#include "FortniteGame_structs.hpp"
#include "FortniteGame_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass GAB_Emote_Generic.GAB_Emote_Generic_C
// 0x0060 (0x0B08 - 0x0AA8)
class UGAB_Emote_Generic_C : public UFortGameplayAbility
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0AA8(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class AFortPlayerPawn*                        PlayerPawn;                                        // 0x0AB0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         PostTriggerCancelDelay;                            // 0x0AB8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          HideReticle;                                       // 0x0ABC(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_ABD[0x3];                                      // 0x0ABD(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FGameplayTagContainer                  ReticleHUDElementTags;                             // 0x0AC0(0x0020)(Edit, BlueprintVisible, DisableEditOnInstance)
	class FName                                   MontageOverrideSection;                            // 0x0AE0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bAbilityStopped;                                   // 0x0AE8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_AE9[0x3];                                      // 0x0AE9(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class FName                                   EmoteHolsterId;                                    // 0x0AEC(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bHolstered;                                        // 0x0AF4(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_AF5[0x3];                                      // 0x0AF5(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class FName                                   HUDElementVisibilityReasonName;                    // 0x0AF8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         WaitForLoadedCount;                                // 0x0B00(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void Cancelled_DE7019AA4E006879EDD264899869FEE2(const struct FGameplayAbilityTargetDataHandle& TargetData, const struct FGameplayTag& ApplicationTag);
	void Completed_DE7019AA4E006879EDD264899869FEE2(const struct FGameplayAbilityTargetDataHandle& TargetData, const struct FGameplayTag& ApplicationTag);
	void ExecuteUbergraph_GAB_Emote_Generic(int32 EntryPoint);
	void ForceStopMontage();
	void GetBodyTypeAndGender(EFortCustomBodyType* BodyType, EFortCustomGender* Gender);
	TSoftObjectPtr<class UAnimMontage> GetMontageToPlay(class UFortMontageItemDefinitionBase* EmoteAsset, EFortCustomBodyType BodyType, EFortCustomGender Gender);
	void IsMontagePlaying(class UAnimMontage* Montage, bool* Result);
	void K2_ActivateAbility();
	void K2_OnEndAbility(bool bWasCancelled);
	void NonMontageAsyncAssetsReady();
	void OnLoaded_D5C2B0D14DEB9277D15965B97800FD1D(class UObject* Loaded);
	void OnLoaded_DA96775D40CD998BF2FF0085FE5AB126(class UObject* Loaded);
	void OnMontageStartedPlaying();
	void PlayInitialEmoteMontage();
	void SetReticleVisibility(bool ShouldHide);
	void Triggered_DE7019AA4E006879EDD264899869FEE2(const struct FGameplayAbilityTargetDataHandle& TargetData, const struct FGameplayTag& ApplicationTag);

	bool K2_CanActivateAbility(const struct FGameplayAbilityActorInfo& ActorInfo, const struct FGameplayAbilitySpecHandle& Handle, struct FGameplayTagContainer* RelevantTags) const;
	bool ShouldPlayFailedMontage(const struct FGameplayTagContainer& FailedReason) const;

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GAB_Emote_Generic_C">();
	}
	static class UGAB_Emote_Generic_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UGAB_Emote_Generic_C>();
	}
};

}

