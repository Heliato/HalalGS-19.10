#pragma once

namespace Abilities
{
	FGameplayAbilitySpec* FindAbilitySpecFromHandle(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayAbilitySpecHandle& Ability)
	{
		FGameplayAbilitySpec* Spec = nullptr;

		for (int32 i = 0; i < AbilitySystemComponent->ActivatableAbilities.Items.Num(); i++)
		{
			if (AbilitySystemComponent->ActivatableAbilities.Items[i].Handle.Handle == Ability.Handle)
			{
				return Spec = &AbilitySystemComponent->ActivatableAbilities.Items[i];
			}
		}

		return Spec;
	}

	void ApplyGameplayAbility(UClass* AbilityClass, UFortAbilitySystemComponent* AbilitySystemComponent)
	{
		if (!AbilityClass || !AbilitySystemComponent)
			return;

		FGameplayAbilitySpec AbilitySpec;
		AbilitySpec.CreateDefaultAbilitySpec((UGameplayAbility*)AbilityClass->CreateDefaultObject(), 1, -1, nullptr);

		for (int32 i = 0; i < AbilitySystemComponent->ActivatableAbilities.Items.Num(); i++)
		{
			auto& CurrentSpec = AbilitySystemComponent->ActivatableAbilities.Items[i];

			if (CurrentSpec.Ability == AbilitySpec.Ability)
				return;
		}

		FGameplayAbilitySpecHandle Handle;
		AbilitySystemComponent->GiveAbility(&Handle, AbilitySpec);
	}

	void GrantGameplayAbility(UFortAbilitySet* AbilitySet, UFortAbilitySystemComponent* AbilitySystemComponent)
	{
		if (!AbilitySet || !AbilitySystemComponent)
			return;

		for (int32 i = 0; i < AbilitySet->GameplayAbilities.Num(); i++)
		{
			TSubclassOf<UFortGameplayAbility> GameplayAbility = AbilitySet->GameplayAbilities[i];

			if (!GameplayAbility.Get())
				continue;

			ApplyGameplayAbility(GameplayAbility, AbilitySystemComponent);
		}
	}

	void GrantGameplayEffect(UFortAbilitySet* AbilitySet, UFortAbilitySystemComponent* AbilitySystemComponent)
	{
		if (!AbilitySet || !AbilitySystemComponent)
			return;

		for (int32 i = 0; i < AbilitySet->GrantedGameplayEffects.Num(); i++)
		{
			FGameplayEffectApplicationInfoHard* GrantedGameplayEffect = &AbilitySet->GrantedGameplayEffects[i];
			if (!GrantedGameplayEffect) continue;

			FGameplayEffectContextHandle EffectContext{};
			AbilitySystemComponent->BP_ApplyGameplayEffectToSelf(GrantedGameplayEffect->GameplayEffect, GrantedGameplayEffect->Level, EffectContext);
		}
	}

	void GrantModifierAbility(UFortGameplayModifierItemDefinition* ModifierItemDefinition, UFortAbilitySystemComponent* AbilitySystemComponent)
	{
		for (int32 i = 0; i < ModifierItemDefinition->PersistentAbilitySets.Num(); i++)
		{
			FFortAbilitySetDeliveryInfo* PersistentAbilitySets = &ModifierItemDefinition->PersistentAbilitySets[i];
			if (!PersistentAbilitySets) continue;

			for (int32 j = 0; j < PersistentAbilitySets->AbilitySets.Num(); j++)
			{
				UFortAbilitySet* AbilitySet = PersistentAbilitySets->AbilitySets[j].Get();

				if (!AbilitySet)
				{
					const FString& AssetPathName = UKismetStringLibrary::Conv_NameToString(PersistentAbilitySets->AbilitySets[j].ObjectID.AssetPathName);
					AbilitySet = StaticLoadObject<UFortAbilitySet>(AssetPathName.CStr());
				}

				GrantGameplayAbility(AbilitySet, AbilitySystemComponent);
				GrantGameplayEffect(AbilitySet, AbilitySystemComponent);
			}
		}
	}

	void GrantModifierAbilityFromPlaylist(UFortAbilitySystemComponent* AbilitySystemComponent)
	{
		UFortPlaylistAthena* PlaylistAthena = Globals::GetPlaylist();

		if (PlaylistAthena)
		{
			for (int32 i = 0; i < PlaylistAthena->ModifierList.Num(); i++)
			{
				UFortGameplayModifierItemDefinition* ModifierItemDefinition = PlaylistAthena->ModifierList[i].Get();

				if (!ModifierItemDefinition)
				{
					const FString& AssetPathName = UKismetStringLibrary::Conv_NameToString(PlaylistAthena->ModifierList[i].ObjectID.AssetPathName);
					ModifierItemDefinition = StaticLoadObject<UFortGameplayModifierItemDefinition>(AssetPathName.CStr());
				}

				if (!ModifierItemDefinition)
					continue;

				GrantModifierAbility(ModifierItemDefinition, AbilitySystemComponent);
			}
		}
	}

	void InternalServerTryActiveAbility(UAbilitySystemComponent* AbilitySystemComponent, FGameplayAbilitySpecHandle Handle, bool InputPressed, const FPredictionKey& PredictionKey, const FGameplayEventData* TriggerEventData)
	{
		FGameplayAbilitySpec* Spec = FindAbilitySpecFromHandle(AbilitySystemComponent, Handle);

		if (!Spec)
		{
			AbilitySystemComponent->ClientActivateAbilityFailed(Handle, PredictionKey.Current);
			return;
		}

		UGameplayAbility* InstancedAbility = nullptr;
		Spec->InputPressed = true;

		if (!AbilitySystemComponent->InternalTryActivateAbility(Handle, PredictionKey, &InstancedAbility, nullptr, TriggerEventData))
		{
			AbilitySystemComponent->ClientActivateAbilityFailed(Handle, PredictionKey.Current);
			Spec->InputPressed = false;
		}

		AbilitySystemComponent->ActivatableAbilities.MarkItemDirty(*Spec);
	}

	FGameplayAbilitySpecHandle (*GiveAbilityOG)(UAbilitySystemComponent* AbilitySystemComponent, FGameplayAbilitySpecHandle* Handle, FGameplayAbilitySpec Spec);
	FGameplayAbilitySpecHandle GiveAbility(UAbilitySystemComponent* AbilitySystemComponent, FGameplayAbilitySpecHandle* Handle, FGameplayAbilitySpec Spec)
	{
		FN_LOG(LogMinHook, Log, "AbilitySystemComponent: %s", AbilitySystemComponent->GetFullName().c_str());
		FN_LOG(LogMinHook, Log, "Spec.Ability: %s", Spec.Ability->GetFullName().c_str());
		FN_LOG(LogMinHook, Log, "Spec.Level: %i", Spec.Level);
		FN_LOG(LogMinHook, Log, "Spec.InputID: %i", Spec.InputID);

		uintptr_t Offset = uintptr_t(_ReturnAddress()) - InSDKUtils::GetImageBase();
		uintptr_t IdaAddress = Offset + 0x7FF6965D0000ULL;

		FN_LOG(LogMinHook, Log, "UAbilitySystemComponent::GiveAbility - called in Offset [0x%llx], IdaAddress [%p]", (unsigned long long)Offset, IdaAddress);

		return GiveAbilityOG(AbilitySystemComponent, Handle, Spec);
	}

	void (*ClearAbilityOG)(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayAbilitySpecHandle& Handle);
	void ClearAbility(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayAbilitySpecHandle& Handle)
	{
		FGameplayAbilitySpec* Spec = Abilities::FindAbilitySpecFromHandle(AbilitySystemComponent, Handle);

		if (Spec)
		{
			FN_LOG(LogMinHook, Log, "AbilitySystemComponent: %s", AbilitySystemComponent->GetFullName().c_str());
			FN_LOG(LogMinHook, Log, "Spec.Ability: %s", Spec->Ability->GetFullName().c_str());
			FN_LOG(LogMinHook, Log, "Spec.Level: %i", Spec->Level);
			FN_LOG(LogMinHook, Log, "Spec.InputID: %i", Spec->InputID);

			uintptr_t Offset = uintptr_t(_ReturnAddress()) - InSDKUtils::GetImageBase();
			uintptr_t IdaAddress = Offset + 0x7FF6965D0000ULL;

			FN_LOG(LogMinHook, Log, "UAbilitySystemComponent::ClearAbility - called in Offset [0x%llx], IdaAddress [%p]", (unsigned long long)Offset, IdaAddress);
		}

		ClearAbilityOG(AbilitySystemComponent, Handle);
	}

	void InitAbilities()
	{
		UFortAbilitySystemComponentAthena* AbilitySystemComponentDefault = UFortAbilitySystemComponentAthena::GetDefaultObj();

		MinHook::HookVTable(AbilitySystemComponentDefault, 0x840 / 8, InternalServerTryActiveAbility, nullptr, "UAbilitySystemComponent::InternalServerTryActiveAbility");

		/*MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x1210B88), GiveAbility, (LPVOID*)(&GiveAbilityOG));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x1210B88));
		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x4dfd34c), ClearAbility, (LPVOID*)(&ClearAbilityOG));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x4dfd34c));*/

		FN_LOG(LogInit, Log, "InitAbilities Success!");
	}
}