#pragma once

enum ENetMode
{
	NM_Standalone,
	NM_DedicatedServer,
	NM_ListenServer,
	NM_Client,
	NM_MAX,
};

namespace Hooks
{
	void (*ProcessEventOG)(UObject* Object, UFunction* Function, void* Parms);
	void (*DispatchRequestOG)(__int64 a1, __int64 a2, int a3);

	uintptr_t GIsClient()
	{
		return __int64(GetModuleHandleW(0)) + 0xB30CF9F;
	}

	uintptr_t GIsServer()
	{
		return __int64(GetModuleHandleW(0)) + 0xB30CF9D;
	}

	ENetMode ReturnNetMode()
	{
		return ENetMode::NM_DedicatedServer;
	}

	void Ret()
	{
		return;
	}

	bool RetFalse()
	{
		return false;
	}

	bool RetTrue()
	{
		return true;
	}

	void DispatchRequest(__int64 a1, __int64 a2, int a3)
	{
		DispatchRequestOG(a1, a2, 3);
	}

	void ApplyAbilities(AFortWeapon* Weapon)
	{
		APawn* Instigator = Weapon->Instigator;
		if (!Instigator) return;

		AFortPlayerController* PlayerController = Cast<AFortPlayerController>(Instigator->Controller);
		AFortPlayerState* PlayerState = Cast<AFortPlayerState>(Instigator->PlayerState);

		if (!PlayerController || !PlayerState)
			return;

		UFortAbilitySystemComponent* AbilitySystemComponent = PlayerState->AbilitySystemComponent;
		if (!AbilitySystemComponent) return;

		if (Weapon->WeaponData)
		{
			if (Weapon->PrimaryAbilitySpecHandle.Handle == -1)
			{
				TSoftClassPtr<UClass> PrimaryFireAbility = Weapon->WeaponData->PrimaryFireAbility;
				UClass* PrimaryFireAbilityClass = Functions::LoadClass(PrimaryFireAbility);

				if (PrimaryFireAbilityClass)
				{
					UGameplayAbility* GameplayAbility = Cast<UGameplayAbility>(PrimaryFireAbilityClass->CreateDefaultObject());

					if (GameplayAbility)
					{
						FGameplayAbilitySpec GameplayAbilitySpec;
						GameplayAbilitySpec.CreateDefaultAbilitySpec(GameplayAbility, 1, -1, Weapon);

						FGameplayAbilitySpecHandle Handle;
						AbilitySystemComponent->GiveAbility(&Handle, GameplayAbilitySpec);

						Weapon->PrimaryAbilitySpecHandle.Handle = Handle.Handle;
					}
				}
			}

			if (Weapon->SecondaryAbilitySpecHandle.Handle == -1)
			{
				TSoftClassPtr<UClass> SecondaryFireAbility = Weapon->WeaponData->SecondaryFireAbility;
				UClass* SecondaryFireAbilityClass = Functions::LoadClass(SecondaryFireAbility);

				if (SecondaryFireAbilityClass)
				{
					UGameplayAbility* GameplayAbility = Cast<UGameplayAbility>(SecondaryFireAbilityClass->CreateDefaultObject());

					if (GameplayAbility)
					{
						FGameplayAbilitySpec GameplayAbilitySpec;
						GameplayAbilitySpec.CreateDefaultAbilitySpec(GameplayAbility, 1, -1, Weapon);

						FGameplayAbilitySpecHandle Handle;
						AbilitySystemComponent->GiveAbility(&Handle, GameplayAbilitySpec);

						Weapon->SecondaryAbilitySpecHandle.Handle = Handle.Handle;
					}
				}
			}

			if (Weapon->ReloadAbilitySpecHandle.Handle == -1)
			{
				TSoftClassPtr<UClass> ReloadAbility = Weapon->WeaponData->ReloadAbility;
				UClass* ReloadAbilityClass = Functions::LoadClass(ReloadAbility);

				if (ReloadAbilityClass)
				{
					UGameplayAbility* GameplayAbility = Cast<UGameplayAbility>(ReloadAbilityClass->CreateDefaultObject());

					if (GameplayAbility)
					{
						FGameplayAbilitySpec GameplayAbilitySpec;
						GameplayAbilitySpec.CreateDefaultAbilitySpec(GameplayAbility, 1, -1, Weapon);

						FGameplayAbilitySpecHandle Handle;
						AbilitySystemComponent->GiveAbility(&Handle, GameplayAbilitySpec);

						Weapon->ReloadAbilitySpecHandle.Handle = Handle.Handle;
					}
				}
			}
			
			if (!Weapon->EquippedAbilityHandles.Num())
			{
				TArray<TSoftClassPtr<UClass>> EquippedAbilities = Weapon->WeaponData->EquippedAbilities;

				for (int32 i = 0; i < EquippedAbilities.Num(); i++)
				{
					if (!EquippedAbilities[i].Get()) continue;

					UGameplayAbility* GameplayAbility = Cast<UGameplayAbility>(EquippedAbilities[i].Get()->CreateDefaultObject());
					if (!GameplayAbility) continue;

					FGameplayAbilitySpec GameplayAbilitySpec;
					GameplayAbilitySpec.CreateDefaultAbilitySpec(GameplayAbility, 1, -1, Weapon);

					FGameplayAbilitySpecHandle Handle;
					AbilitySystemComponent->GiveAbility(&Handle, GameplayAbilitySpec);
				
					Weapon->EquippedAbilityHandles.Add(Handle);
				}
			}

			UFortAbilitySet* AbilitySet = Functions::LoadAbilitySet(Weapon->WeaponData->EquippedAbilitySet);

			if (AbilitySet)
			{
				UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->BP_GetInventoryItemWithGuid(Weapon->ItemEntryGuid));

				if (WorldItem)
				{
					bool (*ApplyItemAbilitySet)(void* InventoryOwner, UFortAbilitySet * AbilitySet, UFortWorldItem * WorldItem) = decltype(ApplyItemAbilitySet)(0x6798430 + uintptr_t(GetModuleHandle(0)));
					ApplyItemAbilitySet(PlayerController->GetInventoryOwner(), AbilitySet, WorldItem);
				}
			}

			if (!Weapon->EquippedAbilitySetHandles.Num())
			{
				UFortAbilitySet* AbilitySet = Functions::LoadAbilitySet(Weapon->WeaponData->EquippedAbilitySet);

				if (AbilitySet)
				{
					FFortAbilitySetHandle AbilitySetHandle{};

					AbilitySetHandle.TargetAbilitySystemComponent.ObjectIndex = AbilitySystemComponent->Index;
					AbilitySetHandle.TargetAbilitySystemComponent.ObjectSerialNumber = 0;

					AbilitySetHandle.GrantedAbilityHandles = {};
					AbilitySetHandle.AppliedEffectHandles = {};
					AbilitySetHandle.ItemGuidsForAdditionalItems = {};

					for (int32 i = 0; i < AbilitySet->GameplayAbilities.Num(); i++)
					{
						if (!AbilitySet->GameplayAbilities[i]) continue;

						UGameplayAbility* GameplayAbility = Cast<UGameplayAbility>(AbilitySet->GameplayAbilities[i]->CreateDefaultObject());
						if (!GameplayAbility) continue;

						FGameplayAbilitySpec GameplayAbilitySpec;
						GameplayAbilitySpec.CreateDefaultAbilitySpec(GameplayAbility, 1, -1, Weapon);

						FGameplayAbilitySpecHandle Handle;
						AbilitySystemComponent->GiveAbility(&Handle, GameplayAbilitySpec);

						AbilitySetHandle.GrantedAbilityHandles.Add(Handle);
					}

					for (int32 i = 0; i < AbilitySet->GrantedGameplayEffects.Num(); i++)
					{
						FGameplayEffectApplicationInfoHard* GrantedGameplayEffect = &AbilitySet->GrantedGameplayEffects[i];
						if (!GrantedGameplayEffect) continue;

						FGameplayEffectContextHandle EffectContext{};
						FActiveGameplayEffectHandle GameplayEffectHandle = AbilitySystemComponent->BP_ApplyGameplayEffectToSelf(GrantedGameplayEffect->GameplayEffect, GrantedGameplayEffect->Level, EffectContext);

						AbilitySetHandle.AppliedEffectHandles.Add(GameplayEffectHandle);
					}

					Weapon->EquippedAbilitySetHandles.Add(AbilitySetHandle);
				}
			}

			/*if (!Weapon->EquippedAbilityHandles.Num() && !Weapon->EquippedAbilitySetHandles.Num())
			{
				TArray<TSoftClassPtr<UClass>> EquippedAbilities = Weapon->WeaponData->EquippedAbilities;

				for (int32 i = 0; i < EquippedAbilities.Num(); i++)
				{
					TSoftClassPtr<UClass> EquippedAbility = EquippedAbilities[i];
					UClass* EquippedAbilityClass = Functions::LoadClass(EquippedAbility);

					if (!EquippedAbilityClass)
						continue;

					UGameplayAbility* GameplayAbility = Cast<UGameplayAbility>(EquippedAbilityClass->CreateDefaultObject());

					if (GameplayAbility)
					{
						FGameplayAbilitySpec GameplayAbilitySpec;
						GameplayAbilitySpec.CreateDefaultAbilitySpec(GameplayAbility, 1, -1, Weapon);

						FGameplayAbilitySpecHandle Handle;
						AbilitySystemComponent->GiveAbility(&Handle, GameplayAbilitySpec);

						Weapon->EquippedAbilityHandles.Add(Handle);
					}
				}

				FN_LOG(LogHooks, Log, "Weapon->AppliedAlterations.Num(): %i", Weapon->AppliedAlterations.Num());

				if (Weapon->AppliedAlterations.Num() > 0)
				{
					for (int32 i = 0; i < Weapon->AppliedAlterations.Num(); i++)
					{
						UFortAlterationItemDefinition* AlterationItemDefinition = Weapon->AppliedAlterations[i];
						if (!AlterationItemDefinition) continue;

						TSoftObjectPtr<UFortAbilitySet> AlterationAbilitySet = AlterationItemDefinition->AlterationAbilitySet;
						UFortAbilitySet* AbilitySet = AlterationAbilitySet.Get();

						if (!AbilitySet && AlterationAbilitySet.ObjectID.AssetPathName.IsValid())
						{
							const FString& AssetPathName = UKismetStringLibrary::Conv_NameToString(AlterationAbilitySet.ObjectID.AssetPathName);
							AbilitySet = StaticLoadObject<UFortAbilitySet>(AssetPathName.CStr());
						}

						if (!AbilitySet)
							continue;

						FN_LOG(LogHooks, Log, "%i - AbilitySet: %s", i, AbilitySet->GetFullName().c_str());

						for (int32 j = 0; j < AbilitySet->GameplayAbilities.Num(); j++)
						{
							TSubclassOf<UFortGameplayAbility> GameplayAbility = AbilitySet->GameplayAbilities[j];
							UClass* GameplayAbilityClass = GameplayAbility.Get();

							if (!GameplayAbilityClass)
								continue;

							FN_LOG(LogHooks, Log, "%i - GameplayAbilityClass: %s", j, GameplayAbilityClass->GetFullName().c_str());

							UGameplayAbility* DefaultGameplayAbility = Cast<UGameplayAbility>(GameplayAbilityClass->CreateDefaultObject());
						}
					}
				}
			}*/

			/*
				TSoftClassPtr<class UClass>                   OnHitAbility;                                      // 0x0A30(0x0028)(Edit, Protected, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierProtected)
				TArray<TSoftClassPtr<class UClass>>           EquippedAbilities;                                 // 0x0A58(0x0010)(Edit, ZeroConstructor, Protected, UObjectWrapper, NativeAccessSpecifierProtected)
				TSoftObjectPtr<class UFortAbilitySet>         EquippedAbilitySet;
			*/
		}
	}

	void RemoveAbilities(AFortWeapon* Weapon)
	{
		APawn* Instigator = Weapon->Instigator;
		if (!Instigator) return;

		AFortPlayerController* PlayerController = Cast<AFortPlayerController>(Instigator->Controller);
		AFortPlayerState* PlayerState = Cast<AFortPlayerState>(Instigator->PlayerState);

		if (!PlayerController || !PlayerState)
			return;

		UFortAbilitySystemComponent* AbilitySystemComponent = PlayerState->AbilitySystemComponent;
		if (!AbilitySystemComponent) return;

		if (Weapon->WeaponData)
		{
			if (Weapon->PrimaryAbilitySpecHandle.Handle != -1)
			{
				AbilitySystemComponent->ClearAbility(Weapon->PrimaryAbilitySpecHandle);
				Weapon->PrimaryAbilitySpecHandle.Handle = -1;
			}

			if (Weapon->SecondaryAbilitySpecHandle.Handle != -1)
			{
				AbilitySystemComponent->ClearAbility(Weapon->SecondaryAbilitySpecHandle);
				Weapon->SecondaryAbilitySpecHandle.Handle = -1;
			}

			if (Weapon->ReloadAbilitySpecHandle.Handle != -1)
			{
				AbilitySystemComponent->ClearAbility(Weapon->ReloadAbilitySpecHandle);
				Weapon->ReloadAbilitySpecHandle.Handle = -1;
			}

			if (Weapon->ImpactAbilitySpecHandle.Handle != -1)
			{
				AbilitySystemComponent->ClearAbility(Weapon->ImpactAbilitySpecHandle);
				Weapon->ImpactAbilitySpecHandle.Handle = -1;
			}

			if (Weapon->ReticleTraceOverrideSpecHandle.Handle != -1)
			{
				AbilitySystemComponent->ClearAbility(Weapon->ReticleTraceOverrideSpecHandle);
				Weapon->ReticleTraceOverrideSpecHandle.Handle = -1;
			}

			for (int32 i = 0; i < Weapon->EquippedAbilityHandles.Num(); i++)
			{
				FGameplayAbilitySpecHandle& EquippedAbilityHandle = Weapon->EquippedAbilityHandles[i];
				AbilitySystemComponent->ClearAbility(EquippedAbilityHandle);
				EquippedAbilityHandle.Handle = -1;
			}

			Weapon->EquippedAbilityHandles.Free();

			UFortAbilitySet* AbilitySet = Functions::LoadAbilitySet(Weapon->WeaponData->EquippedAbilitySet);

			if (AbilitySet)
			{
				UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->BP_GetInventoryItemWithGuid(Weapon->ItemEntryGuid));

				if (WorldItem)
				{
					bool (*RemoveItemAbilitySet)(void* InventoryOwner, UFortAbilitySet* AbilitySet, UFortWorldItem* WorldItem) = decltype(RemoveItemAbilitySet)(0x67a9968 + uintptr_t(GetModuleHandle(0)));
					RemoveItemAbilitySet(PlayerController->GetInventoryOwner(), AbilitySet, WorldItem);
				}
			}

			for (int32 i = 0; i < Weapon->EquippedAbilitySetHandles.Num(); i++)
			{
				FFortAbilitySetHandle& EquippedAbilitySetHandle = Weapon->EquippedAbilitySetHandles[i];
				UFortKismetLibrary::UnequipFortAbilitySet(EquippedAbilitySetHandle);
			}

			Weapon->EquippedAbilitySetHandles.Free();
		}
	}

	bool bLogs = false;

	void ProcessEvent(UObject* Object, UFunction* Function, void* Parms)
	{
		if (!Object || !Function)
		{
			ProcessEventOG(Object, Function, Parms);
			return;
		}

		const std::string& FunctionName = Function->GetName();

		if (FunctionName.contains("Tick"))
		{
			if (GetAsyncKeyState(VK_F1) & 0x1)
			{
				AFortPlayerController* PlayerController = Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));

				if (!PlayerController)
					return;
			}

			if (GetAsyncKeyState(VK_F2) & 0x1)
			{
				AFortPlayerController* PlayerController = Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));

				if (!PlayerController)
					return;
			}

			if (GetAsyncKeyState(VK_F3) & 0x1)
			{
				AFortPlayerController* PlayerController = Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));

				if (!PlayerController)
					return;
			}

			/*if (GetAsyncKeyState(VK_F4) & 0x1)
			{
				AFortPlayerController* PlayerController = Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));

				if (!PlayerController || !PlayerController->Pawn)
					return;

				auto WoodItemData = StaticFindObject<UFortResourceItemDefinition>(L"/Game/Athena/Items/Weapons/Boss/WID_Boss_Adventure_GH.WID_Boss_Adventure_GH");

				FFortItemEntry ItemEntry;
				ItemEntry.CreateDefaultItemEntry(WoodItemData, 1, 0);

				UFortWeaponItemDefinition* WeaponItemDefinition = Cast<UFortWeaponItemDefinition>(WoodItemData);

				if (WeaponItemDefinition)
				{
					int32(*GetWeaponClipSize)(UFortWeaponItemDefinition * WeaponItemDefinition, int32 WeaponLevel) = decltype(GetWeaponClipSize)(0x21da37c + uintptr_t(GetModuleHandle(0)));
					ItemEntry.LoadedAmmo = GetWeaponClipSize(WeaponItemDefinition, ItemEntry.Level);

					FN_LOG(LogHooks, Log, "WeaponClipSize: %i", ItemEntry.LoadedAmmo);
				}

				TWeakObjectPtr<AFortPlayerController> WeakPlayerController{};
				WeakPlayerController.ObjectIndex = -1;
				WeakPlayerController.ObjectSerialNumber = 0;

				TWeakObjectPtr<AActor> WeakInvestigator{};
				WeakInvestigator.ObjectIndex = -1;
				WeakInvestigator.ObjectSerialNumber = 0;

				FFortCreatePickupData PickupData = FFortCreatePickupData();
				PickupData.World = Globals::GetWorld();
				PickupData.ItemEntry = ItemEntry;
				PickupData.SpawnLocation = PlayerController->Pawn->K2_GetActorLocation();
				PickupData.SpawnRotation = FRotator();
				PickupData.WeakPlayerController = WeakPlayerController;
				PickupData.OverrideClass = nullptr;
				PickupData.WeakInvestigator = WeakInvestigator;
				PickupData.PickupSourceTypeFlags = EFortPickupSourceTypeFlag::Other;
				PickupData.PickupSpawnSource = EFortPickupSpawnSource::Unset;
				PickupData.bRandomRotation = 1;
				PickupData.BitPad_1DA_1 = 0;

				FFortCreatePickupData* (*CreatePickupData)(
					FFortCreatePickupData* PickupData,
					UWorld* World,
					FFortItemEntry ItemEntry,
					FVector SpawnLocation,
					FRotator SpawnRotation,
					AFortPlayerController* PlayerController,
					UClass* OverrideClass,
					AActor* Investigator,
					int a9,
					int a10) = decltype(CreatePickupData)(0x64da9dc + uintptr_t(GetModuleHandle(0)));

				CreatePickupData(
					&PickupData,
					Globals::GetWorld(),
					ItemEntry,
					PlayerController->Pawn->K2_GetActorLocation(),
					FRotator(),
					nullptr,
					nullptr,
					nullptr,
					0,
					0);

				AFortPickup* (*CreatePickupFromData)(FFortCreatePickupData* PickupData) = decltype(CreatePickupFromData)(0x64dd1b4 + uintptr_t(GetModuleHandle(0)));
				AFortPickup* Pickup = CreatePickupFromData(&PickupData);

				Pickup->TossPickup(
					PlayerController->Pawn->K2_GetActorLocation(),
					nullptr,
					0,
					true,
					true,
					EFortPickupSourceTypeFlag::Tossed,
					EFortPickupSpawnSource::TossedByPlayer
				);
			}*/

			if (GetAsyncKeyState(VK_F4) & 0x1)
			{
				AFortPlayerController* PlayerController = Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));

				if (!PlayerController || !PlayerController->Pawn)
					return;

				auto Spiderman = StaticFindObject<UFortResourceItemDefinition>(L"/ParallelGameplay/Items/WestSausage/WID_WestSausage_Parallel.WID_WestSausage_Parallel");
				auto AssaultRifle = StaticFindObject<UFortResourceItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Assault_Auto_Athena_R_Ore_T03.WID_Assault_Auto_Athena_R_Ore_T03");
				auto PumpShotgun = StaticFindObject<UFortResourceItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Shotgun_Standard_Athena_SR_Ore_T03.WID_Shotgun_Standard_Athena_SR_Ore_T03");
				auto SMG = StaticFindObject<UFortResourceItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Pistol_AutoHeavyPDW_Athena_R_Ore_T03.WID_Pistol_AutoHeavyPDW_Athena_R_Ore_T03");
				auto Minis = StaticFindObject<UFortResourceItemDefinition>(L"/Game/Athena/Items/Consumables/ShieldSmall/Athena_ShieldSmall.Athena_ShieldSmall");

				UFortKismetLibrary::K2_GiveItemToAllPlayers(PlayerController, Spiderman, FGuid(), 1, false);
				UFortKismetLibrary::K2_GiveItemToAllPlayers(PlayerController, AssaultRifle, FGuid(), 1, false);
				UFortKismetLibrary::K2_GiveItemToAllPlayers(PlayerController, PumpShotgun, FGuid(), 1, false);
				UFortKismetLibrary::K2_GiveItemToAllPlayers(PlayerController, SMG, FGuid(), 1, false);
				UFortKismetLibrary::K2_GiveItemToAllPlayers(PlayerController, Minis, FGuid(), 6, false);
			}

			if (GetAsyncKeyState(VK_F5) & 0x1)
			{
				AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(Globals::GetGameState());

				if (GameStateAthena)
				{
					UCurveTable* AthenaGameData = GameStateAthena->CurrentPlaylistInfo.BasePlaylist->GameData.Get();

					if (!AthenaGameData)
					{
						AthenaGameData = GameStateAthena->AthenaGameDataTable;

						if (!AthenaGameData)
							AthenaGameData = StaticLoadObject<UCurveTable>(L"/Game/Balance/AthenaGameData.AthenaGameData");
					}

					if (AthenaGameData)
					{
						FName DefaultSafeZoneDamageName = UKismetStringLibrary::Conv_StringToName(L"Default.SafeZone.Damage");
						FSimpleCurve* SimpleCurve = (FSimpleCurve*)AthenaGameData->FindCurve(DefaultSafeZoneDamageName, FString());

						if (SimpleCurve)
						{
							FN_LOG(LogFunctions, Log, "DefaultSafeZoneDamage Value at 0 : %.2f", SimpleCurve->Eval(0));
						}
					}
				}

				/*AFortPlayerController* PlayerController = Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));

				if (!PlayerController || !PlayerController->Pawn)
					return;

				auto ItemDefinition = StaticFindObject<UFortWeaponItemDefinition>(L"/Game/Athena/Items/Consumables/FrenchYedoc/WID_Athena_FrenchYedoc_JWUnfriendly.WID_Athena_FrenchYedoc_JWUnfriendly");

				UFortKismetLibrary::K2_GiveItemToPlayer(PlayerController, ItemDefinition, FGuid(), 1, false);*/

				// auto TID_ContextTrap_Athena = StaticFindObject<UFortWeaponRangedItemDefinition>(L"/Game/Athena/Items/Consumables/WitchBroom/WID_Athena_WitchBroom.WID_Athena_WitchBroom");
				// auto TID_ContextTrap_Athena = StaticFindObject<UFortContextTrapItemDefinition>(L"/ParallelGameplay/Items/WestSausage/WID_WestSausage_Parallel_L_M.WID_WestSausage_Parallel_L_M");
				// auto TID_ContextTrap_Athena = StaticFindObject<UFortContextTrapItemDefinition>(L"/Game/Athena/Items/Traps/TID_ContextTrap_Athena.TID_ContextTrap_Athena");
				// auto TID_ContextTrap_Athena = StaticFindObject<UFortWeaponRangedItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Hook_Gun_VR_Ore_T03.WID_Hook_Gun_VR_Ore_T03");
				// auto TID_ContextTrap_Athena = StaticFindObject<UFortWeaponRangedItemDefinition>(L"/Game/Athena/Items/Weapons/WID_AshtonPack_Indigo.WID_AshtonPack_Indigo");

				/*FFortItemEntry ItemEntry;
				ItemEntry.CreateDefaultItemEntry(TID_ContextTrap_Athena, 1, 0);

				UFortWeaponItemDefinition* WeaponItemDefinition = Cast<UFortWeaponItemDefinition>(TID_ContextTrap_Athena);

				if (WeaponItemDefinition)
				{
					FFortBaseWeaponStats* BaseWeaponStats = Inventory::GetWeaponStats(WeaponItemDefinition);

					int32(*GetWeaponClipSize)(UFortWeaponItemDefinition* WeaponItemDefinition, int32 WeaponLevel) = decltype(GetWeaponClipSize)(0x21da37c + uintptr_t(GetModuleHandle(0)));
					int32 WeaponClipSize = GetWeaponClipSize(WeaponItemDefinition, ItemEntry.Level);

					if (WeaponItemDefinition->bUsesPhantomReserveAmmo)
					{
						ItemEntry.PhantomReserveAmmo = (WeaponClipSize - BaseWeaponStats->ClipSize);
						ItemEntry.LoadedAmmo = BaseWeaponStats ? BaseWeaponStats->ClipSize : 0;
					}
					else
						ItemEntry.LoadedAmmo = WeaponClipSize;

					FN_LOG(LogHooks, Log, "WeaponClipSize: %i", WeaponClipSize);
				}

				TWeakObjectPtr<AFortPlayerController> WeakPlayerController{};
				WeakPlayerController.ObjectIndex = -1;
				WeakPlayerController.ObjectSerialNumber = 0;

				TWeakObjectPtr<AActor> WeakInvestigator{};
				WeakInvestigator.ObjectIndex = -1;
				WeakInvestigator.ObjectSerialNumber = 0;

				FFortCreatePickupData PickupData = FFortCreatePickupData();
				PickupData.World = Globals::GetWorld();
				PickupData.ItemEntry = ItemEntry;
				PickupData.SpawnLocation = PlayerController->Pawn->K2_GetActorLocation();
				PickupData.SpawnRotation = FRotator();
				PickupData.WeakPlayerController = WeakPlayerController;
				PickupData.OverrideClass = nullptr;
				PickupData.WeakInvestigator = WeakInvestigator;
				PickupData.PickupSourceTypeFlags = EFortPickupSourceTypeFlag::Other;
				PickupData.PickupSpawnSource = EFortPickupSpawnSource::Unset;
				PickupData.bRandomRotation = 1;
				PickupData.BitPad_1DA_1 = 0;

				FFortCreatePickupData* (*CreatePickupData)(
					FFortCreatePickupData* PickupData,
					UWorld* World,
					FFortItemEntry ItemEntry,
					FVector SpawnLocation,
					FRotator SpawnRotation,
					AFortPlayerController* PlayerController,
					UClass* OverrideClass,
					AActor* Investigator,
					int a9,
					int a10) = decltype(CreatePickupData)(0x64da9dc + uintptr_t(GetModuleHandle(0)));

				CreatePickupData(
					&PickupData,
					Globals::GetWorld(),
					ItemEntry,
					PlayerController->Pawn->K2_GetActorLocation(),
					FRotator(),
					nullptr,
					nullptr,
					nullptr,
					0,
					0);

				AFortPickup* (*CreatePickupFromData)(FFortCreatePickupData* PickupData) = decltype(CreatePickupFromData)(0x64dd1b4 + uintptr_t(GetModuleHandle(0)));
				AFortPickup* Pickup = CreatePickupFromData(&PickupData);

				Pickup->TossPickup(
					PlayerController->Pawn->K2_GetActorLocation(),
					nullptr,
					0,
					true,
					true,
					EFortPickupSourceTypeFlag::Other,
					EFortPickupSpawnSource::Unset
				);*/
			}

			if (GetAsyncKeyState(VK_F6) & 0x1)
			{
				/*AFortPlayerController* PlayerController = Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));

				if (!PlayerController)
					return;

				AFortPlayerPawn* PlayerPawn = PlayerController->GetPlayerPawn();

				if (!PlayerPawn)
					return;

				UWorld* World = PlayerController->GetWorld();

				if (!World)
					return;

				UBlueprintGeneratedClass* BlueprintGeneratedClass = StaticLoadObject<UBlueprintGeneratedClass>(L"/Game/Athena/AI/Phoebe/BP_PlayerPawn_Athena_Phoebe.BP_PlayerPawn_Athena_Phoebe_C");
				FVector SpawnLocation = PlayerPawn->K2_GetActorLocation();

				AFortPlayerPawnAthena* PlayerPawnPhoebe = Cast<AFortPlayerPawnAthena>(World->SpawnActor(BlueprintGeneratedClass, &SpawnLocation));

				if (PlayerPawnPhoebe)
				{
					FN_LOG(LogHooks, Log, "PlayerPawnPhoebe: %s", PlayerPawnPhoebe->GetFullName().c_str());
					FN_LOG(LogHooks, Log, "Controller: %s", PlayerPawnPhoebe->Controller->GetFullName().c_str());
				}

				UAthenaAIServicePlayerBots;*/

				UAthenaAIServicePlayerBots* ServicePlayerBots = UAthenaAIBlueprintLibrary::GetAIServicePlayerBots(Globals::GetWorld());

				FN_LOG(LogHooks, Log, "ServicePlayerBots: %s", ServicePlayerBots->GetFullName().c_str());

				/*
				HalalGS-19.10: LogHooks: Info: PlayerPawnPhoebe: BP_PlayerPawn_Athena_Phoebe_C Artemis_Terrain.Artemis_Terrain.PersistentLevel.BP_PlayerPawn_Athena_Phoebe_C_2147442657
HalalGS-19.10: LogHooks: Info: Controller: BP_PhoebePlayerController_C Artemis_Terrain.Artemis_Terrain.PersistentLevel.BP_PhoebePlayerController_C_2147442647
				*/

				/*AFortPlayerController* PlayerController = Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));

				if (!PlayerController)
					return;

				for (int32 i = 0; i < PlayerController->WorldInventory->Inventory.ItemInstances.Num(); i++)
				{
					UFortWorldItem* WorldItem = PlayerController->WorldInventory->Inventory.ItemInstances[i];
					if (!WorldItem) continue;

					UFortItemDefinition* ItemDefinition = WorldItem->ItemEntry.ItemDefinition;
					if (!ItemDefinition) continue;

					FN_LOG(LogHooks, Log, "%i - ItemDefinition: %s, Count: %i, LoadedAmmo: %i", 
						i, ItemDefinition->GetName().c_str(), WorldItem->ItemEntry.Count, WorldItem->ItemEntry.LoadedAmmo);
				}

				AFortPlayerStateAthena* PlayerStateAthena = Cast<AFortPlayerStateAthena>(PlayerController->PlayerState);

				if (!PlayerStateAthena)
					return;

				UFortAbilitySystemComponent* AbilitySystemComponent = PlayerStateAthena->AbilitySystemComponent;

				if (!AbilitySystemComponent)
					return;

				for (int32 i = 0; i < AbilitySystemComponent->ActiveGameplayEffects.GameplayEffects_Internal.Num(); i++)
				{
					FActiveGameplayEffect ActiveGameplayEffect = AbilitySystemComponent->ActiveGameplayEffects.GameplayEffects_Internal[i];
					if (!ActiveGameplayEffect.Spec.Def) continue;

					FN_LOG(LogHooks, Log, "%i - ActiveGameplayEffect.Spec.Def: %s", i, ActiveGameplayEffect.Spec.Def->GetFullName().c_str());
				}

				for (int32 i = 0; i < AbilitySystemComponent->ActivatableAbilities.Items.Num(); i++)
				{
					FGameplayAbilitySpec ActivatableAbility = AbilitySystemComponent->ActivatableAbilities.Items[i];
					if (!ActivatableAbility.Ability) continue;

					FN_LOG(LogHooks, Log, "%i - ActivatableAbility.Ability: %s", i, ActivatableAbility.Ability->GetFullName().c_str());
				}*/
			}

			if (GetAsyncKeyState(VK_F7) & 0x1)
			{
				bLogs = bLogs ? false : true;
				FN_LOG(LogHooks, Log, "bLogs set to %i", bLogs);

				/*AFortPlayerController* PlayerController = Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));

				if (!PlayerController || !PlayerController->Pawn)
					return;

				UBlueprintGeneratedClass* FloorLootClass = StaticFindObject<UBlueprintGeneratedClass>(L"/Game/Athena/Environments/Blueprints/Tiered_Athena_FloorLoot_01.Tiered_Athena_FloorLoot_01_C");
				UBlueprintGeneratedClass* FloorLootWarmupClass = StaticFindObject<UBlueprintGeneratedClass>(L"/Game/Athena/Environments/Blueprints/Tiered_Athena_FloorLoot_Warmup.Tiered_Athena_FloorLoot_Warmup_C");

				if (FloorLootClass && FloorLootWarmupClass)
				{
					TArray<AActor*> FloorLootsResult;
					UGameplayStatics::GetAllActorsOfClass(PlayerController, FloorLootClass, &FloorLootsResult);

					TArray<AActor*> FloorLootWarmupResult;
					UGameplayStatics::GetAllActorsOfClass(PlayerController, FloorLootWarmupClass, &FloorLootWarmupResult);

					TArray<AActor*> FloorLoots;

					for (int i = 0; i < FloorLootsResult.Num(); i++)
					{
						FloorLoots.Add(FloorLootsResult[i]);
					}

					for (int i = 0; i < FloorLootWarmupResult.Num(); i++)
					{
						FloorLoots.Add(FloorLootWarmupResult[i]);
					}

					for (int i = 0; i < FloorLoots.Num(); i++)
					{
						ABuildingContainer* FloorLoot = (ABuildingContainer*)FloorLoots[i];
						if (!FloorLoot) continue;

						int32 WorldLevel = UFortKismetLibrary::GetLootLevel(PlayerController);

						FName LootTierKey = FName(0);
						int32 LootTier = -1;
						bool bResult = Loots::PickLootTierKeyAndLootTierFromTierGroup(&LootTierKey, &LootTier, FloorLoot->SearchLootTierGroup, WorldLevel, 0, -1, FloorLoot->StaticGameplayTags);

						if (bResult)
						{
							TArray<FFortItemEntry> LootToDrops;
							Loots::PickLootDrops(&LootToDrops, WorldLevel, LootTierKey, 0, 0, FloorLoot->StaticGameplayTags, false, false);

							for (int32 i = 0; i < LootToDrops.Num(); i++)
							{
								FFortItemEntry LootToDrop = LootToDrops[i];

								FFortItemEntry ItemEntry;
								Inventory::MakeItemEntry(&ItemEntry, LootToDrop.ItemDefinition, LootToDrop.Count, LootToDrop.Level, LootToDrop.LoadedAmmo, LootToDrop.Durability);

								Inventory::SpawnPickup(nullptr, ItemEntry, PlayerController->Pawn->K2_GetActorLocation(), PlayerController->Pawn->K2_GetActorLocation());
							}
						}

						FloorLoot->bAlreadySearched = true;
						FloorLoot->OnRep_bAlreadySearched();
					}
				}*/
			}

			if (GetAsyncKeyState(VK_F9) & 0x1)
			{
				AFortPlayerController* PlayerController = Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));

				if (!PlayerController)
					return;

				AFortPlayerPawn* PlayerPawnFFFF = PlayerController->GetPlayerPawn();

				if (!PlayerPawnFFFF)
					return;

				UWorld* World = PlayerController->GetWorld();

				AAthena_PlayerController_C* PlayerControllerAthena = Cast<AAthena_PlayerController_C>(World->SpawnActor(AAthena_PlayerController_C::StaticClass()));
				AFortGameModeAthena* GameModeAthena = Cast<AFortGameModeAthena>(Globals::GetGameMode());

				if (PlayerControllerAthena && GameModeAthena)
				{
					void (*ChoosePlayerTeam)(AFortGameModeAthena * GameModeAthena, AFortPlayerControllerAthena * PlayerController) = decltype(ChoosePlayerTeam)(0x5f9c110 + uintptr_t(GetModuleHandle(0)));
					ChoosePlayerTeam(GameModeAthena, PlayerControllerAthena);

					GameModeAthena->AddFromAlivePlayers(PlayerControllerAthena);

					AFortInventory* WorldInventory = PlayerControllerAthena->WorldInventory;

					if (!WorldInventory)
					{
						WorldInventory = Cast<AFortInventory>(World->SpawnActor(AFortInventory::StaticClass()));

						if (WorldInventory)
						{
							WorldInventory->SetOwner(PlayerControllerAthena);
							WorldInventory->OnRep_Owner();

							PlayerControllerAthena->WorldInventory = WorldInventory;
							PlayerControllerAthena->bHasInitializedWorldInventory = true;
							PlayerControllerAthena->WorldInventory->HandleInventoryLocalUpdate();
						}
					}

					AFortPlayerPawn* PlayerPawn = Util::SpawnPlayer(PlayerControllerAthena, PlayerPawnFFFF->K2_GetActorLocation(), FRotator(), true);
					AFortPlayerStateAthena* PlayerState = Cast<AFortPlayerStateAthena>(PlayerControllerAthena->PlayerState);
					UFortAbilitySystemComponent* AbilitySystemComponent = PlayerState->AbilitySystemComponent;

					if (!AbilitySystemComponent)
						AbilitySystemComponent = Cast<UFortAbilitySystemComponent>(UGameplayStatics::SpawnObject(UFortAbilitySystemComponent::StaticClass(), PlayerState));

					if (PlayerPawn && PlayerState && AbilitySystemComponent)
					{
						PlayerPawn->bCanBeDamaged = true;

						AbilitySystemComponent->ClearAllAbilities();

						UGameDataBR* GameDataBR = Globals::GetGameDataBR();
						UFortAbilitySet* DefaultAbilities = Functions::LoadAbilitySet(GameDataBR->PlayerAbilitySetBR);

						Abilities::GrantGameplayAbility(DefaultAbilities, AbilitySystemComponent);
						Abilities::GrantGameplayEffect(DefaultAbilities, AbilitySystemComponent);
						Abilities::GrantModifierAbilityFromPlaylist(AbilitySystemComponent);

						PlayerState->ApplyCharacterCustomization(PlayerPawn);

						static int32 PlayerBotId = 1;

						std::string PlayerName = "HalalBot" + std::to_string(PlayerBotId);
						PlayerControllerAthena->ServerChangeName(std::wstring(PlayerName.begin(), PlayerName.end()).c_str());

						PlayerBotId++;
					}
				}

				/*static auto FortPlayerControllerAthenaDefault = (AFortPlayerControllerAthena*)(AFortPlayerControllerAthena::StaticClass())->DefaultObject;

				static auto IdkDefault = (void*)(__int64(FortPlayerControllerAthenaDefault) + 0x710);*/

				/*
					OdysseyLog: LogHook: Debug: Index not found: 0x0, Offset: 0xc17a88, IdaAddress [00007FF66F267A88] - Pleins de Free Memory
					OdysseyLog: LogHook: Debug: Index not found: 0x1, Offset: 0xc3b978, IdaAddress [00007FF66F28B978] - Baka
					OdysseyLog: LogHook: Debug: Index not found: 0x2, Offset: 0x2ccbb0, IdaAddress [00007FF66E91CBB0] - WITH_SERVER_CODE (return 1)
					OdysseyLog: LogHook: Debug: Index not found: 0x3, Offset: 0xc26310, IdaAddress [00007FF66F276310] - Return un truc zebi jsp quoi
					OdysseyLog: LogHook: Debug: Index not found: 0x4, Offset: 0x2ccbb0, IdaAddress [00007FF66E91CBB0] - WITH_SERVER_CODE (return 1)
					OdysseyLog: LogHook: Debug: Index not found: 0x5, Offset: 0x3992a0, IdaAddress [00007FF66E9E92A0] - Return un truc zebi jsp quoi
					OdysseyLog: LogHook: Debug: Index not found: 0x6, Offset: 0x3992a0, IdaAddress [00007FF66E9E92A0] - Return un truc zebi jsp quoi
					OdysseyLog: LogHook: Debug: Index not found: 0x7, Offset: 0x11b3850, IdaAddress [00007FF66F803850] - Return un truc zebi jsp quoi
					OdysseyLog: LogHook: Debug: Index not found: 0x8, Offset: 0xc24970, IdaAddress [00007FF66F274970] - GetCurrentWeapon
					OdysseyLog: LogHook: Debug: Index not found: 0x9, Offset: 0xc24970, IdaAddress [00007FF66F274970] - GetCurrentWeapon
					OdysseyLog: LogHook: Debug: Index not found: 0xa, Offset: 0xc269f0, IdaAddress [00007FF66F2769F0] - Return un truc zebi jsp quoi
					OdysseyLog: LogHook: Debug: Index not found: 0xb, Offset: 0xc28ad0, IdaAddress [00007FF66F278AD0] - Return un truc zebi jsp quoi
					OdysseyLog: LogHook: Debug: Index not found: 0xc, Offset: 0x11beef0, IdaAddress [00007FF66F80EEF0] - Peut être intéressent ressemble à RemoveInventoryItem
					OdysseyLog: LogHook: Debug: Index not found: 0xd, Offset: 0x11d8640, IdaAddress [00007FF66F828640] - ModifyLoadedAmmo
					OdysseyLog: LogHook: Debug: Index not found: 0xe, Offset: 0x11c60b0, IdaAddress [00007FF66F8160B0] - Un truc stw je crois
					OdysseyLog: LogHook: Debug: Index not found: 0xf, Offset: 0x11c6010, IdaAddress [00007FF66F816010] - Un truc stw je crois
					OdysseyLog: LogHook: Debug: Index not found: 0x10, Offset: 0xc28550, IdaAddress [00007FF66F278550] - La fonction est énorme
					OdysseyLog: LogHook: Debug: Index not found: 0x11, Offset: 0x11a9910, IdaAddress [00007FF66F7F9910] - Prends 3 paramètres et fait un truc avec l'ItemDefinition et le FortItem
					OdysseyLog: LogHook: Debug: Index not found: 0x12, Offset: 0x11a9c40, IdaAddress [00007FF66F7F9C40] - GetItemInstances
					OdysseyLog: LogHook: Debug: Index not found: 0x13, Offset: 0x11ae410, IdaAddress [00007FF66F7FE410] - GetItemInstance
					OdysseyLog: LogHook: Debug: Index not found: 0x14, Offset: 0x11d1cc0, IdaAddress [00007FF66F821CC0] - RemoveInventoryItem
					OdysseyLog: LogHook: Debug: Index not found: 0x15, Offset: 0xc17ba0, IdaAddress [00007FF66F267BA0] - Pleins de Free Memory
					OdysseyLog: LogHook: Debug: Index not found: 0x16, Offset: 0x2ccb70, IdaAddress [00007FF66E91CB70] - WITH_SERVER_CODE (nullsub)
					OdysseyLog: LogHook: Debug: Index not found: 0x17, Offset: 0x1841460, IdaAddress [00007FF66FE91460] - jsp wallah
					OdysseyLog: LogHook: Debug: Index not found: 0x18, Offset: 0x2cccd0, IdaAddress [00007FF66E91CCD0] - WITH_SERVER_CODE (return 0)
					OdysseyLog: LogHook: Debug: Index not found: 0x19, Offset: 0x22cfbd0, IdaAddress [00007FF67091FBD0] - Return un truc zebi jsp quoi
					OdysseyLog: LogHook: Debug: Index not found: 0x1a, Offset: 0x18403d0, IdaAddress [00007FF66FE903D0] - jsp wallah
					OdysseyLog: LogHook: Debug: Index not found: 0x1b, Offset: 0x2ccb70, IdaAddress [00007FF66E91CB70] - WITH_SERVER_CODE (nullsub)
					OdysseyLog: LogHook: Debug: Index not found: 0x1c, Offset: 0x2e1a30, IdaAddress [00007FF66E931A30] - jsp wallah
					OdysseyLog: LogHook: Debug: Index not found: 0x1d, Offset: 0x22e46e0, IdaAddress [00007FF6709346E0] - Peut être intéressent à tester
					OdysseyLog: LogHook: Debug: Index not found: 0x1e, Offset: 0x2ccb70, IdaAddress [00007FF66E91CB70] - WITH_SERVER_CODE (nullsub)
					OdysseyLog: LogHook: Debug: Index not found: 0x1f, Offset: 0x2cccd0, IdaAddress [00007FF66E91CCD0] - WITH_SERVER_CODE (return 0)
					OdysseyLog: LogHook: Debug: Index not found: 0x20, Offset: 0x2ccb70, IdaAddress [00007FF66E91CB70] - WITH_SERVER_CODE (nullsub)
					OdysseyLog: LogHook: Debug: Index not found: 0x21, Offset: 0x3530d0, IdaAddress [00007FF66E9A30D0] - WITH_SERVER_CODE (nullsub)






					HalalGS-19.10: LogHook: Info: Index not found: 0x0, Offset: 0x44d6728, IdaAddress [00007FF69AAA6728]
					HalalGS-19.10: LogHook: Info: Index not found: 0x1, Offset: 0x44d6770, IdaAddress [00007FF69AAA6770]
					HalalGS-19.10: LogHook: Info: Index not found: 0x2, Offset: 0x1409430, IdaAddress [00007FF6979D9430]
					HalalGS-19.10: LogHook: Info: Index not found: 0x3, Offset: 0xb31660, IdaAddress [00007FF697101660]
					HalalGS-19.10: LogHook: Info: Index not found: 0x4, Offset: 0xbe8550, IdaAddress [00007FF6971B8550]
					HalalGS-19.10: LogHook: Info: Index not found: 0x5, Offset: 0x1b7dcf0, IdaAddress [00007FF69814DCF0]
					HalalGS-19.10: LogHook: Info: Index not found: 0x6, Offset: 0x1409430, IdaAddress [00007FF6979D9430]
					HalalGS-19.10: LogHook: Info: Index not found: 0x7, Offset: 0x3f1e700, IdaAddress [00007FF69A4EE700]
					HalalGS-19.10: LogHook: Info: Index not found: 0x8, Offset: 0x3f1e6f0, IdaAddress [00007FF69A4EE6F0]
					HalalGS-19.10: LogHook: Info: Index not found: 0x9, Offset: 0x3f1e6f0, IdaAddress [00007FF69A4EE6F0]
					HalalGS-19.10: LogHook: Info: Index not found: 0xa, Offset: 0x5ff7550, IdaAddress [00007FF69C5C7550]
					HalalGS-19.10: LogHook: Info: Index not found: 0xb, Offset: 0x14d2a50, IdaAddress [00007FF697AA2A50]
					HalalGS-19.10: LogHook: Info: Index not found: 0xc, Offset: 0x5ff6c60, IdaAddress [00007FF69C5C6C60]
					HalalGS-19.10: LogHook: Info: Index not found: 0xd, Offset: 0x1d8f4cc, IdaAddress [00007FF69835F4CC]
					HalalGS-19.10: LogHook: Info: Index not found: 0xe, Offset: 0x1297800, IdaAddress [00007FF697867800]
					HalalGS-19.10: LogHook: Info: Index not found: 0xf, Offset: 0x5ffd830, IdaAddress [00007FF69C5CD830]
					HalalGS-19.10: LogHook: Info: Index not found: 0x10, Offset: 0x5ffd5ac, IdaAddress [00007FF69C5CD5AC]
					HalalGS-19.10: LogHook: Info: Index not found: 0x11, Offset: 0x5ffd654, IdaAddress [00007FF69C5CD654]
					HalalGS-19.10: LogHook: Info: Index not found: 0x12, Offset: 0x5ffd768, IdaAddress [00007FF69C5CD768]
					HalalGS-19.10: LogHook: Info: Index not found: 0x13, Offset: 0xbe8550, IdaAddress [00007FF6971B8550]
					HalalGS-19.10: LogHook: Info: Index not found: 0x14, Offset: 0xb31660, IdaAddress [00007FF697101660]
					HalalGS-19.10: LogHook: Info: Index not found: 0x15, Offset: 0x7622a11a0, IdaAddress [00007FFDF88711A0]
					HalalGS-19.10: LogHook: Info: Index not found: 0x16, Offset: 0x6784050, IdaAddress [00007FF69CD54050]
					HalalGS-19.10: LogHook: Info: Index not found: 0x17, Offset: 0xbe8550, IdaAddress [00007FF6971B8550]
					HalalGS-19.10: LogHook: Info: Index not found: 0x18, Offset: 0x5c27f04, IdaAddress [00007FF69C1F7F04]
					HalalGS-19.10: LogHook: Info: Index not found: 0x19, Offset: 0x6775f6c, IdaAddress [00007FF69CD45F6C]
					HalalGS-19.10: LogHook: Info: Index not found: 0x1a, Offset: 0x5fe92ec, IdaAddress [00007FF69C5B92EC]
					HalalGS-19.10: LogHook: Info: Index not found: 0x1b, Offset: 0x600a4d8, IdaAddress [00007FF69C5DA4D8]
					HalalGS-19.10: LogHook: Info: Index not found: 0x1c, Offset: 0x5ff07f8, IdaAddress [00007FF69C5C07F8]
					HalalGS-19.10: LogHook: Info: Index not found: 0x1d, Offset: 0x5ffd598, IdaAddress [00007FF69C5CD598]
					HalalGS-19.10: LogHook: Info: Index not found: 0x1e, Offset: 0x5ff7284, IdaAddress [00007FF69C5C7284]
					HalalGS-19.10: LogHook: Info: Index not found: 0x1f, Offset: 0x5fe930c, IdaAddress [00007FF69C5B930C]
					HalalGS-19.10: LogHook: Info: Index not found: 0x20, Offset: 0x600a4e4, IdaAddress [00007FF69C5DA4E4]
					HalalGS-19.10: LogHook: Info: Index not found: 0x21, Offset: 0x5ff55f8, IdaAddress [00007FF69C5C55F8]
					HalalGS-19.10: LogHook: Info: Index not found: 0x22, Offset: 0x5ff753c, IdaAddress [00007FF69C5C753C]
					HalalGS-19.10: LogHook: Info: Index not found: 0x23, Offset: 0x5fe8bf0, IdaAddress [00007FF69C5B8BF0]
					HalalGS-19.10: LogHook: Info: Index not found: 0x24, Offset: 0x600a3b8, IdaAddress [00007FF69C5DA3B8]
					HalalGS-19.10: LogHook: Info: Index not found: 0x25, Offset: 0x5ffd8b4, IdaAddress [00007FF69C5CD8B4]
					HalalGS-19.10: LogHook: Info: Index not found: 0x26, Offset: 0x6755c40, IdaAddress [00007FF69CD25C40]
					HalalGS-19.10: LogHook: Info: Index not found: 0x27, Offset: 0x64df0f8, IdaAddress [00007FF69CAAF0F8]
					HalalGS-19.10: LogHook: Info: Index not found: 0x28, Offset: 0x6798430, IdaAddress [00007FF69CD68430]
					HalalGS-19.10: LogHook: Info: Index not found: 0x29, Offset: 0x67a9968, IdaAddress [00007FF69CD79968]
					HalalGS-19.10: LogHook: Info: Index not found: 0x2a, Offset: 0x5ffcc98, IdaAddress [00007FF69C5CCC98]
					HalalGS-19.10: LogHook: Info: Index not found: 0x2b, Offset: 0x3f1cdf0, IdaAddress [00007FF69A4ECDF0]
					HalalGS-19.10: LogHook: Info: Index not found: 0x2c, Offset: 0x129a8d8, IdaAddress [00007FF69786A8D8]
					HalalGS-19.10: LogHook: Info: Index not found: 0x2d, Offset: 0x5ff56dc, IdaAddress [00007FF69C5C56DC]
					HalalGS-19.10: LogHook: Info: Index not found: 0x2e, Offset: 0x1f248ac, IdaAddress [00007FF6984F48AC]
					HalalGS-19.10: LogHook: Info: Index not found: 0x2f, Offset: 0x677da2c, IdaAddress [00007FF69CD4DA2C]
					HalalGS-19.10: LogHook: Info: Index not found: 0x30, Offset: 0x14d3994, IdaAddress [00007FF697AA3994]
					HalalGS-19.10: LogHook: Info: Index not found: 0x31, Offset: 0x5ffe708, IdaAddress [00007FF69C5CE708]
					HalalGS-19.10: LogHook: Info: Index not found: 0x32, Offset: 0x676173c, IdaAddress [00007FF69CD3173C]
				*/

				// MinHook::FindIndexVTable((UObject*)IdkDefault, 0x0, 0x40);
			}

			if (GetAsyncKeyState(VK_F10) & 0x1)
			{
				AFortPlayerController* PlayerController = Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));

				if (!PlayerController)
					return;

				AFortPlayerPawn* PlayerPawn = PlayerController->GetPlayerPawn();

				if (!PlayerPawn)
					return;

				UWorld* World = PlayerController->GetWorld();

				if (!World)
					return;

				UBlueprintGeneratedClass* BlueprintGeneratedClass = StaticFindObject<UBlueprintGeneratedClass>(L"/Game/Athena/Items/Weapons/Prototype/PetrolPump/BGA_Petrol_Pickup.BGA_Petrol_Pickup_C");
				FVector SpawnLocation = PlayerPawn->K2_GetActorLocation();

				World->SpawnActor(BlueprintGeneratedClass, &SpawnLocation);
			}

			if (GetAsyncKeyState(VK_F12) & 0x1)
			{
				AFortPlayerController* PlayerController = Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));

				if (!PlayerController || !PlayerController->Pawn)
					return;

				/*UBlueprintGeneratedClass* BP_Tornado = StaticLoadObject<UBlueprintGeneratedClass>(L"/Superstorm/Tornado/BP_Tornado.BP_Tornado_C");

				FN_LOG(LogHooks, Log, "BP_Tornado: %s", BP_Tornado->GetFullName().c_str());
				FVector SpawnLocation = PlayerController->Pawn->K2_GetActorLocation();

				AActor* Actor = PlayerController->GetWorld()->SpawnActor(BP_Tornado, &SpawnLocation);

				FN_LOG(LogHooks, Log, "Actor: %s", Actor->GetFullName().c_str());*/

				// /Game/Athena/DrivableVehicles/Mech/TestMechVehicle.TestMechVehicle_C

				//UBlueprintGeneratedClass* NPC_Pawn_ButterCake_Base = StaticLoadObject<UBlueprintGeneratedClass>(L"/ButterCake/Pawns/NPC_Pawn_ButterCake_Base.NPC_Pawn_ButterCake_Base_C");
				UBlueprintGeneratedClass* NPC_Pawn_ButterCake_Base = StaticLoadObject<UBlueprintGeneratedClass>(L"/Game/Athena/DrivableVehicles/Mech/TestMechVehicle.TestMechVehicle_C");

				FN_LOG(LogHooks, Log, "NPC_Pawn_ButterCake_Base: %s", NPC_Pawn_ButterCake_Base->GetFullName().c_str());
				FVector SpawnLocation = PlayerController->Pawn->K2_GetActorLocation();

				AActor* Actor = PlayerController->GetWorld()->SpawnActor(NPC_Pawn_ButterCake_Base, &SpawnLocation);

				FN_LOG(LogHooks, Log, "Actor: %s", Actor->GetFullName().c_str());

				UFortGameplayDataTrackerComponentManager;
				UButterCakeUnstuckComponent;
				AAIController;
			}
		}
		else if (FunctionName.contains("OnWorldReady"))
		{
			AFortGameModeAthena* GameModeAthena = Cast<AFortGameModeAthena>(Globals::GetGameMode());

			if (!GameModeAthena)
				return;

			AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(GameModeAthena->GameState);

			if (!GameStateAthena)
				return;

			if (!GameModeAthena->bWorldIsReady)
			{
				UFortPlaylistAthena* PlaylistAthena = Globals::GetPlaylist();

				if (PlaylistAthena && GameStateAthena)
				{
					float ServerWorldTimeSeconds = UGameplayStatics::GetTimeSeconds(GameModeAthena) + GameStateAthena->ServerWorldTimeSecondsDelta;
					float Duration = 900.0f; // Seconds

					/*GameStateAthena->WarmupCountdownStartTime = Duration;
					GameStateAthena->WarmupCountdownEndTime = ServerWorldTimeSeconds + Duration;

					GameModeAthena->WarmupEarlyCountdownDuration = ServerWorldTimeSeconds;
					GameModeAthena->WarmupCountdownDuration = Duration;*/

					for (int32 i = 0; i < PlaylistAthena->AdditionalLevels.Num(); i++)
					{
						TSoftObjectPtr<UWorld> AdditionalLevel = PlaylistAthena->AdditionalLevels[i];

						FName FoundationName = AdditionalLevel.ObjectID.AssetPathName;
						if (!FoundationName.IsValid()) continue;

						bool bSuccess = false;
						ULevelStreamingDynamic::LoadLevelInstanceBySoftObjectPtr(GameStateAthena, AdditionalLevel, FVector(), FRotator(), &bSuccess, FString(), {});

						if (bSuccess)
						{
							FName LevelName = AdditionalLevel.ObjectID.AssetPathName;
							if (!LevelName.IsValid()) continue;

							FAdditionalLevelStreamed AdditionalLevelStreamed = FAdditionalLevelStreamed();
							AdditionalLevelStreamed.bIsServerOnly = false;
							AdditionalLevelStreamed.LevelName = LevelName;

							GameStateAthena->AdditionalPlaylistLevelsStreamed.Add(AdditionalLevelStreamed);
						}
					}

					for (int32 i = 0; i < PlaylistAthena->AdditionalLevelsServerOnly.Num(); i++)
					{
						TSoftObjectPtr<UWorld> AdditionalLevelsServerOnly = PlaylistAthena->AdditionalLevelsServerOnly[i];

						FName FoundationName = AdditionalLevelsServerOnly.ObjectID.AssetPathName;
						if (!FoundationName.IsValid()) continue;

						bool bSuccess = false;
						ULevelStreamingDynamic::LoadLevelInstanceBySoftObjectPtr(GameStateAthena, AdditionalLevelsServerOnly, FVector(), FRotator(), &bSuccess, FString(), {});

						if (bSuccess)
						{
							FName LevelName = AdditionalLevelsServerOnly.ObjectID.AssetPathName;
							if (!LevelName.IsValid()) continue;

							FAdditionalLevelStreamed AdditionalLevelStreamed = FAdditionalLevelStreamed();
							AdditionalLevelStreamed.bIsServerOnly = true;
							AdditionalLevelStreamed.LevelName = LevelName;

							GameStateAthena->AdditionalPlaylistLevelsStreamed.Add(AdditionalLevelStreamed);
						}
					}

					GameStateAthena->OnRep_AdditionalPlaylistLevelsStreamed();
				}

				Functions::InitializeDeployTraceForGroundDistance();
				Functions::InitializeConsumableBGAs();
				Functions::InitializeTreasureChests();
				Functions::InitializeAmmoBoxs();
				

				Functions::InitializeAI();
				// Navigation::InitializeNavigation(Globals::GetWorld());

				Functions::SpawnVehicles();

				FN_LOG(LogHooks, Log, "OnWorldReady called!");
				GameModeAthena->bWorldIsReady = true;
			}
		}

		/*if (FunctionName.contains("OnEquip"))
		{
			FN_LOG(Logs, Log, "Object: %s", Object->GetFullName().c_str());
			FN_LOG(Logs, Log, "OnEquip: %s", Function->GetFullName().c_str());
		}

		if (FunctionName.contains("OnUnEquip"))
		{
			UFortWeaponComponent;

			FN_LOG(Logs, Log, "Object: %s", Object->GetFullName().c_str());
			FN_LOG(Logs, Log, "OnUnEquip: %s", Function->GetFullName().c_str());
		}*/

		if (bLogs)
		{
			if (!FunctionName.contains("Tick") &&
				!FunctionName.contains("Visual") &&
				!FunctionName.contains("Clown Spinner") &&
				!FunctionName.contains("CustomStateChanged") &&
				!FunctionName.contains("ReceiveBeginPlay") &&
				!FunctionName.contains("OnAttachToBuilding") &&
				!FunctionName.contains("OnWorldReady") &&
				!FunctionName.contains("K2_GetActorLocation") &&
				!FunctionName.contains("ReceiveDrawHUD") &&
				!FunctionName.contains("ServerUpdateCamera") &&
				!FunctionName.contains("ServerMove") &&
				!FunctionName.contains("ContrailCheck") &&
				!FunctionName.contains("GetViewTarget") &&
				!FunctionName.contains("GetAllActorsOfClass") &&
				!FunctionName.contains("ClientAckGoodMove") &&
				!FunctionName.contains("ReadyToEndMatch") &&
				!FunctionName.contains("Check Closest Point") &&
				!FunctionName.contains("ServerTriggerCombatEvent") &&
				!FunctionName.contains("UpdateTime") &&
				!FunctionName.contains("OnUpdateMusic") &&
				!FunctionName.contains("UpdateStateEvent") &&
				!FunctionName.contains("ServerTouchActiveTime") &&
				!FunctionName.contains("OnCheckIfSurrounded") &&
				!FunctionName.contains("ServerFireAIDirectorEventBatch") &&
				!FunctionName.contains("ServerTriggerCombatEventBatch") &&
				!FunctionName.contains("UserConstructionScript") &&
				!FunctionName.contains("K2_OnReset") &&
				!FunctionName.contains("K2_OnEndViewTarget") &&
				!FunctionName.contains("K2_OnBecomeViewTarget") &&
				!FunctionName.contains("ReceiveUnpossessed") &&
				!FunctionName.contains("ClientGotoState") &&
				!FunctionName.contains("K2_OnEndViewTarget") &&
				!FunctionName.contains("K2_OnBecomeViewTarget") &&
				!FunctionName.contains("ClientSetViewTarget") &&
				!FunctionName.contains("ServerClientPawnLoaded") &&
				!FunctionName.contains("ReceiveEndPlay") &&
				!FunctionName.contains("OnPerceptionStimuliSourceEndPlay") &&
				!FunctionName.contains("HandleOnHUDElementVisibilityChanged") &&
				!FunctionName.contains("OnHUDElementVisibilityChanged") &&
				!FunctionName.contains("HandleInteractionChanged") &&
				!FunctionName.contains("BlueprintModifyCamera") &&
				!FunctionName.contains("BlueprintModifyPostProcess") &&
				!FunctionName.contains("ServerSetSpectatorLocation") &&
				!FunctionName.contains("ServerFireAIDirectorEvent") &&
				!FunctionName.contains("ServerTryActivateAbility") &&
				!FunctionName.contains("ClientActivateAbilitySucceed") &&
				!FunctionName.contains("ServerSetSpectatorLocation") &&
				!FunctionName.contains("CanJumpInternal") &&
				!FunctionName.contains("K2_OnMovementModeChanged") &&
				!FunctionName.contains("OnJumped") &&
				!FunctionName.contains("ServerModifyStat") &&
				!FunctionName.contains("OnLanded") &&
				!FunctionName.contains("ReceiveHit") &&
				!FunctionName.contains("OnWalkingOffLedge") &&
				!FunctionName.contains("Execute") &&
				!FunctionName.contains("OnDamagePlayEffects") &&
				!FunctionName.contains("OnMontageStarted") &&
				!FunctionName.contains("OnNewDamageNumber") &&
				!FunctionName.contains("BP_GetTokenizedDescriptionText") &&
				!FunctionName.contains("GameplayCue_InstantDeath") &&
				!FunctionName.contains("K2_GetActorRotation") &&
				!FunctionName.contains("K2_DestroyActor") &&
				!FunctionName.contains("OnDetachFromBuilding") &&
				!FunctionName.contains("OnRep_bAlreadySearched") &&
				!FunctionName.contains("OnSetSearched") &&
				!FunctionName.contains("GetAircraft") &&
				!FunctionName.contains("BeginSpawningActorFromClass") &&
				!FunctionName.contains("BlueprintInitializeAnimation") &&
				!FunctionName.contains("BlueprintUpdateAnimation") &&
				!FunctionName.contains("BlueprintPostEvaluateAnimation") &&
				!FunctionName.contains("FinishSpawningActor") &&
				!FunctionName.contains("PawnUniqueIDSet") &&
				!FunctionName.contains("OnRep_Owner") &&
				!FunctionName.contains("OnRep_Pawn") &&
				!FunctionName.contains("Possess") &&
				!FunctionName.contains("ReceivePossessed") &&
				!FunctionName.contains("ClientRestart") &&
				!FunctionName.contains("SetControlRotation") &&
				!FunctionName.contains("ClientRetryClientRestart") &&
				!FunctionName.contains("ExecuteUbergraph_PlayerPawn_Athena_Generic") &&
				!FunctionName.contains("ExecuteUbergraph_PlayerPawn_Athena") &&
				!FunctionName.contains("ServerAcknowledgePossession") &&
				!FunctionName.contains("IsInAircraft") &&
				!FunctionName.contains("FindPlayerStart") &&
				!FunctionName.contains("SpawnDefaultPawnFor") &&
				!FunctionName.contains("MustSpectate") &&
				!FunctionName.contains("GetDefaultPawnClassForController") &&
				!FunctionName.contains("On Game Phase Change") &&
				!FunctionName.contains("ClientAdjustPosition") &&
				!FunctionName.contains("Movement Audio Crossfader__UpdateFunc") &&
				!FunctionName.contains("Holding Audio Crossfader__UpdateFunc") &&
				!FunctionName.contains("OnUpdateDirectionalLightForTimeOfDay") &&
				!FunctionName.contains("OnMontageEnded") &&
				!FunctionName.contains("ServerCancelAbility") &&
				!FunctionName.contains("K2_ActivateAbility") &&
				!FunctionName.contains("ServerHandleMissionEvent_ToggledCursorMode") &&
				!FunctionName.contains("OnBlendOut_") &&
				!FunctionName.contains("ClientEndAbility") &&
				!FunctionName.contains("OnSafeZoneStateChange") &&
				!FunctionName.contains("ClientVeryShortAdjustPosition") &&
				!FunctionName.contains("OnDayPhaseChange") &&
				!FunctionName.contains("On Day Phase Change") &&
				!FunctionName.contains("K2_OnStartCrouch") &&
				!FunctionName.contains("K2_OnEndCrouch") &&
				!FunctionName.contains("On Player Won") &&
				!FunctionName.contains("ClientFinishedInteractionInZone") &&
				!FunctionName.contains("ClientReceiveKillNotification") &&
				!FunctionName.contains("ReceiveCopyProperties") &&
				!FunctionName.contains("K2_OnLogout") &&
				!FunctionName.contains("ClientReceiveLocalizedMessage") &&
				!FunctionName.contains("ClientCancelAbility") &&
				!FunctionName.contains("ServerFinishedInteractionInZoneReport") &&
				!FunctionName.contains("FallingTimeline__UpdateFunc") &&
				!FunctionName.contains("BndEvt__InterceptCollision_K2Node_ComponentBoundEvent_5_ComponentBeginOverlapSignature__DelegateSignature") &&
				!FunctionName.contains("ReceiveActorBeginOverlap") &&
				!FunctionName.contains("Conv_StringToName") &&
				!FunctionName.contains("OnRep_GamePhase") &&
				!FunctionName.contains("K2_OnSetMatchState") &&
				!FunctionName.contains("StartPlay") &&
				!FunctionName.contains("StartMatch") &&
				!FunctionName.contains("OnAircraftEnteredDropZone") &&
				!FunctionName.contains("ServerShortTimeout") &&
				!FunctionName.contains("UpdateStateWidgetContent") &&
				!FunctionName.contains("PreConstruct") &&
				!FunctionName.contains("Construct") &&
				!FunctionName.contains("OnCurrentTextStyleChanged") &&
				!FunctionName.contains("UpdateButtonState") &&
				!FunctionName.contains("OnBangStateChanged") &&
				!FunctionName.contains("OnPlayerInfoChanged") &&
				!FunctionName.contains("Update") &&
				!FunctionName.contains("OnBeginIntro") &&
				!FunctionName.contains("HandleQuickBarChangedBP") &&
				!FunctionName.contains("HandleInventoryUpdatedEvent") &&
				!FunctionName.contains("OnActivated") &&
				!FunctionName.contains("OnBeginOutro") &&
				!FunctionName.contains("HandleActiveWidgetDeactivated") &&
				!FunctionName.contains("OnDeactivated") &&
				!FunctionName.contains("OnStateStarted") &&
				!FunctionName.contains("SetRenderTransform") &&
				!FunctionName.contains("OnAnimationFinished") &&
				!FunctionName.contains("ReadyToStartMatch") &&
				!FunctionName.contains("SetWidthOverride") &&
				!FunctionName.contains("SetHeightOverride") &&
				!FunctionName.contains("HandleMinimizeFinished") &&
				!FunctionName.contains("ServerUpdateLevelVisibility") &&
				!FunctionName.contains("OnDayPhaseChanged") &&
				!FunctionName.contains("ServerLoadingScreenDropped") &&
				!FunctionName.contains("On Game Phase Step Changed") &&
				!FunctionName.contains("HandleGamePhaseStepChanged") &&
				!FunctionName.contains("GamePhaseStepChanged") &&
				!FunctionName.contains("SetColorAndOpacity") &&
				!FunctionName.contains("OnAnimationStarted") &&
				!FunctionName.contains("UpdateMessaging") &&
				!FunctionName.contains("ServerSendLoadoutConfig") &&
				!FunctionName.contains("CalculateBaseMagnitude") &&
				!FunctionName.contains("ClientRegisterWithParty") &&
				!FunctionName.contains("InitializeHUDForPlayer") &&
				!FunctionName.contains("ClientSetHUD") &&
				!FunctionName.contains("ClientEnableNetworkVoice") &&
				!FunctionName.contains("ClientUpdateMultipleLevelsStreamingStatus") &&
				!FunctionName.contains("ClientFlushLevelStreaming") &&
				!FunctionName.contains("ClientOnGenericPlayerInitialization") &&
				!FunctionName.contains("ClientCapBandwidth") &&
				!FunctionName.contains("K2_PostLogin") &&
				!FunctionName.contains("OnRep_bHasStartedPlaying") &&
				!FunctionName.contains("ServerChoosePart") &&
				!FunctionName.contains("SetOwner") &&
				!FunctionName.contains("OnRep_QuickBar") &&
				!FunctionName.contains("HandleStartingNewPlayer") &&
				!FunctionName.contains("ServerUpdateMultipleLevelsVisibility") &&
				!FunctionName.contains("ServerSetPartyOwner") &&
				!FunctionName.contains("PlayerCanRestart") &&
				!FunctionName.contains("ServerCreateCombatManager") &&
				!FunctionName.contains("ServerCreateAIDirectorDataManager") &&
				!FunctionName.contains("EnableSlot") &&
				!FunctionName.contains("DisableSlot") &&
				!FunctionName.contains("ServerSetShowHeroBackpack") &&
				!FunctionName.contains("ServerSetShowHeroHeadAccessories") &&
				!FunctionName.contains("ServerSetClientHasFinishedLoading") &&
				!FunctionName.contains("ServerReadyToStartMatch") &&
				!FunctionName.contains("Received_Notify") &&
				!FunctionName.contains("Received_NotifyBegin") &&
				!FunctionName.contains("AnimNotify_LeftFootStep") &&
				!FunctionName.contains("AnimNotify_RightFootStep") &&
				!FunctionName.contains("Completed_") &&
				!FunctionName.contains("InputActionHoldStopped") &&
				!FunctionName.contains("ServerCurrentMontageSetPlayRate") &&
				!FunctionName.contains("ServerSetReplicatedTargetData") &&
				!FunctionName.contains("Triggered_") &&
				!FunctionName.contains("ActorHasTag") &&
				!FunctionName.contains("RandomIntegerInRange") &&
				!FunctionName.contains("GetItemDefinitionBP") &&
				!FunctionName.contains("CreateTemporaryItemInstanceBP") &&
				!FunctionName.contains("SetOwningControllerForTemporaryItem") &&
				!FunctionName.contains("OnRep_PrimaryQuickBar") &&
				!FunctionName.contains("OnRep_SecondaryQuickBar") &&
				!FunctionName.contains("ServerSetupWeakSpotsOnBuildingActor") &&
				!FunctionName.contains("OnStartDirectionEffect") &&
				!FunctionName.contains("SetReplicates") &&
				!FunctionName.contains("ServerCurrentMontageSetNextSectionName") &&
				!FunctionName.contains("NetFadeOut") &&
				!FunctionName.contains("OnFadeOut") &&
				!FunctionName.contains("NetOnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("GameplayCue") &&
				!FunctionName.contains("ReceiveActorEndOverlap") &&
				!FunctionName.contains("PhysicsVolumeChanged") &&
				!FunctionName.contains("ServerAddItemInternal") &&
				!FunctionName.contains("FortClientPlaySound") &&
				!FunctionName.contains("OnCapsuleBeginOverlap") &&
				!FunctionName.contains("GetPlayerController") &&
				!FunctionName.contains("TossPickup") &&
				!FunctionName.contains("OnRep_PrimaryPickupItemEntry") &&
				!FunctionName.contains("ServerActivateSlotInternal") &&
				!FunctionName.contains("EquipWeaponDefinition") &&
				!FunctionName.contains("OnInitAlteration") &&
				!FunctionName.contains("OnInitCosmeticAlterations") &&
				!FunctionName.contains("K2_OnUnEquip") &&
				!FunctionName.contains("GetItemGuid") &&
				!FunctionName.contains("InternalServerSetTargeting") &&
				!FunctionName.contains("ServerReleaseInventoryItemKey") &&
				!FunctionName.contains("OnPawnMontageBlendingOut") &&
				!FunctionName.contains("OnSetTargeting") &&
				!FunctionName.contains("OnRep_DefaultMetadata") &&
				!FunctionName.contains("GetDataTableRowNames") &&
				!FunctionName.contains("GetMaxDurability") &&
				!FunctionName.contains("BeginDeferredActorSpawnFromClass") &&
				!FunctionName.contains("OnRep_PickupLocationData") &&
				!FunctionName.contains("GetControlRotation") &&
				!FunctionName.contains("OnVisibilitySetEvent") &&
				!FunctionName.contains("ShouldShowSoundIndicator") &&
				!FunctionName.contains("WaitForPawn") &&
				!FunctionName.contains("OnProjectileStopDelegate") &&
				!FunctionName.contains("Handle Parachute Audio State") &&
				!FunctionName.contains("IsCachedIsProjectileWeapon") &&
				!FunctionName.contains("ClientMoveResponsePacked") &&
				!FunctionName.contains("GetAbilityTargetingLevel") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("EvaluateGraphExposedInputs_ExecuteUbergraph_Fortnite_M_Avg_Player_AnimBlueprint_AnimGraphNode_"))
			{
				FN_LOG(Logs, Log, "Function: [%s], Object: [%s]", Function->GetFullName().c_str(), Object->GetName().c_str());
			}
		}

		ProcessEventOG(Object, Function, Parms);
	}

	struct FortWeaponComponent_EquipTest final
	{
	public:
		class AFortWeapon* Weapon;                                            // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	};

	void (*OnEquipOG)(UFortWeaponComponent* WeaponComponent, FFrame& Stack, void* Ret);
	void OnEquip(UFortWeaponComponent* WeaponComponent, FFrame& Stack, void* Ret)
	{
		auto Params = (FortWeaponComponent_EquipTest*)Stack.Locals;

		// FN_LOG(Logs, Log, "OnEquip - Params->Weapon: %s", Params->Weapon->GetName().c_str());

		ApplyAbilities(Params->Weapon);

		OnEquipOG(WeaponComponent, Stack, Ret);
	}

	void (*OnUnEquipOG)(UFortWeaponComponent* WeaponComponent, FFrame& Stack, void* Ret);
	void OnUnEquip(UFortWeaponComponent* WeaponComponent, FFrame& Stack, void* Ret)
	{
		auto Params = (FortWeaponComponent_EquipTest*)Stack.Locals;

		// FN_LOG(Logs, Log, "OnUnEquip - Params->Weapon: %s", Params->Weapon->GetName().c_str());

		RemoveAbilities(Params->Weapon);

		OnUnEquipOG(WeaponComponent, Stack, Ret);
	}

	float UnwindDegrees(float Angle)
	{
		float Remainder = 0.0f;
		UKismetMathLibrary::FMod(Angle, 360.0f, &Remainder);

		if (Remainder < 0.0f)
		{
			Remainder += 360.0f;
		}

		if (Remainder > 180.0f)
		{
			Remainder -= 360.0f;
		}

		return Remainder;
	}

	void ServerMove(AFortPhysicsPawn* PhysicsPawn, FFrame& Stack, void* Ret)
	{
		FReplicatedPhysicsPawnState InState;

		Stack.StepCompiledIn(&InState);

		Stack.Code += Stack.Code != nullptr;

		UPrimitiveComponent* RootComponent = Cast<UPrimitiveComponent>(PhysicsPawn->RootComponent);

		if (RootComponent)
		{
			FRotator* (*Rotator)(FQuat* Quat, FRotator* Rotator) = decltype(Rotator)(0xdb3a68 + uintptr_t(GetModuleHandle(0)));

			FRotator RealRotation;
			Rotator(&InState.Rotation, &RealRotation);

			RealRotation.Yaw = UnwindDegrees(RealRotation.Yaw);

			RealRotation.Pitch = 0.0f;
			RealRotation.Roll = 0.0f;

			RootComponent->K2_SetWorldLocationAndRotation(InState.Translation, RealRotation, false, nullptr, true);
			RootComponent->SetPhysicsLinearVelocity(InState.LinearVelocity, 0, FName(0));
			RootComponent->SetPhysicsAngularVelocityInDegrees(InState.AngularVelocity, 0, FName(0));
		}

		// FN_LOG(Logs, Log, "ServerMove - PhysicsPawn: %s", PhysicsPawn->GetFullName().c_str());
	}

	bool (*AddItemToInventoryOwnerOG)(UFortItemEntryComponent* ItemEntryComponent, TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, bool bUseItemPickupAnalyticEvent);
	bool AddItemToInventoryOwner(UFortItemEntryComponent* ItemEntryComponent, TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, bool bUseItemPickupAnalyticEvent)
	{
		bool bResult = AddItemToInventoryOwnerOG(ItemEntryComponent, InventoryOwner, bUseItemPickupAnalyticEvent);

		if (InventoryOwner.GetInterface())
		{
			AFortPlayerController* PlayerController = AFortPlayerController::GetPlayerControllerFromInventoryOwner(InventoryOwner.GetInterfaceRef());
			if (!PlayerController) return bResult;

			return (Inventory::AddInventoryItem(PlayerController, ItemEntryComponent->OwnedItemEntry) != nullptr);
		}

		return bResult;
	}

	void PickupHeldObject(UFortHeldObjectComponent* HeldObjectComponent, FFrame& Stack, void* Ret)
	{
		AFortPlayerPawn* PlayerPawn;

		Stack.StepCompiledIn(&PlayerPawn);

		Stack.Code += Stack.Code != nullptr;

		if (!PlayerPawn)
			return;

		AFortPlayerController* PlayerController = Cast<AFortPlayerController>(PlayerPawn->Controller);
		if (!PlayerController) return;

		TSoftObjectPtr<UFortWeaponItemDefinition> EquippedWeaponItemDefinition = HeldObjectComponent->EquippedWeaponItemDefinition;
		UFortWeaponItemDefinition* WeaponItemDefinition = EquippedWeaponItemDefinition.Get();

		if (!WeaponItemDefinition)
		{
			const FString& AssetPathName = UKismetStringLibrary::Conv_NameToString(EquippedWeaponItemDefinition.ObjectID.AssetPathName);
			WeaponItemDefinition = StaticLoadObject<UFortWeaponItemDefinition>(AssetPathName.CStr());
		}

		if (!WeaponItemDefinition)
			return;

		FFortItemEntry ItemEntry;
		Inventory::MakeItemEntry(&ItemEntry, WeaponItemDefinition, 1, -1, -1, -1.0f);

		UFortWorldItem* WorldItem = Inventory::AddItem(PlayerController->WorldInventory, ItemEntry);

		if (WorldItem)
		{
			bool bEquipWeapon = WeaponItemDefinition->EquipWeaponDefinition(WorldItem, PlayerController);

			if (bEquipWeapon && PlayerPawn->CurrentWeapon)
			{
				TWeakObjectPtr<UFortWorldItem> WeakGrantedWeaponItem{};
				WeakGrantedWeaponItem.ObjectIndex = WorldItem->Index;
				WeakGrantedWeaponItem.ObjectSerialNumber = 0;

				HeldObjectComponent->GrantedWeaponItem = WeakGrantedWeaponItem;

				TWeakObjectPtr<AFortWeapon> WeakGrantedWeapon{};
				WeakGrantedWeapon.ObjectIndex = PlayerPawn->CurrentWeapon->Index;
				WeakGrantedWeapon.ObjectSerialNumber = 0;

				HeldObjectComponent->GrantedWeapon = WeakGrantedWeapon;
			}
		}

		HeldObjectComponent->HeldObjectState = EHeldObjectState::Held;

		HeldObjectComponent->OwningPawn = PlayerPawn;
		HeldObjectComponent->OnRep_OwningPawn(PlayerPawn);

		FN_LOG(Logs, Log, "PickupHeldObject called - HeldObjectComponent: %s", HeldObjectComponent->GetFullName().c_str());
	}

	void DropHeldObject(UFortHeldObjectComponent* HeldObjectComponent, FFrame& Stack, void* Ret)
	{
		Stack.Code += Stack.Code != nullptr;

		AFortPlayerPawn* PlayerPawn = HeldObjectComponent->OwningPawn;
		if (!PlayerPawn) return;

		AFortPlayerController* PlayerController = Cast<AFortPlayerController>(PlayerPawn->Controller);
		if (!PlayerController) return;

		UFortWorldItem* WorldItem = HeldObjectComponent->GrantedWeaponItem.Get();

		if (WorldItem)
		{
			bool bRemoveItem = PlayerController->RemoveInventoryItem(WorldItem->ItemEntry.ItemGuid, -1, true, true);

			if (bRemoveItem)
			{
				TWeakObjectPtr<UFortWorldItem> WeakGrantedWeaponItem{};
				WeakGrantedWeaponItem.ObjectIndex = -1;
				WeakGrantedWeaponItem.ObjectSerialNumber = 0;

				HeldObjectComponent->GrantedWeaponItem = WeakGrantedWeaponItem;

				TWeakObjectPtr<AFortWeapon> WeakGrantedWeapon{};
				WeakGrantedWeapon.ObjectIndex = -1;
				WeakGrantedWeapon.ObjectSerialNumber = 0;

				HeldObjectComponent->GrantedWeapon = WeakGrantedWeapon;
			}
		}

		HeldObjectComponent->HeldObjectState = EHeldObjectState::Dropped;

		HeldObjectComponent->OwningPawn = nullptr;
		HeldObjectComponent->OnRep_OwningPawn(nullptr);

		FN_LOG(Logs, Log, "DropHeldObject called - HeldObjectComponent: %s", HeldObjectComponent->GetFullName().c_str());
	}
	
	void (*OnSpawnedOG)(UFortAthenaAISpawnerDataComponent_InventoryBase* AISpawnerDataComponent, AFortAIPawn* AIPawn);
	void OnSpawned(UFortAthenaAISpawnerDataComponent_InventoryBase* AISpawnerDataComponent, AFortAIPawn* AIPawn)
	{
		FN_LOG(LogMinHook, Log, "UFortAthenaAISpawnerDataComponent_InventoryBase::OnSpawned - AISpawnerDataComponent: %s, AIPawn: %s", AISpawnerDataComponent->GetName().c_str(), AIPawn->GetFullName().c_str());

		UWorld;
		AFortAthenaAIBotController;

		if (AIPawn)
		{
			void* InventoryOwner = AIPawn->GetInventoryOwner();

			uintptr_t Offset = uintptr_t(((UObject*)InventoryOwner)->VTable[0x2]) - InSDKUtils::GetImageBase();
			uintptr_t IdaAddress = Offset + 0x7FF6965D0000ULL;

			FN_LOG(LogMinHook, Log, "AFortAIPawn::0x2 - called in Offset [0x%llx], IdaAddress [%p]", (unsigned long long)Offset, IdaAddress);

			uintptr_t Offset2 = uintptr_t(((UObject*)InventoryOwner)->VTable[0x3]) - InSDKUtils::GetImageBase();
			uintptr_t IdaAddress2 = Offset2 + 0x7FF6965D0000ULL;

			FN_LOG(LogMinHook, Log, "AFortAIPawn::0x3 - called in Offset [0x%llx], IdaAddress [%p]", (unsigned long long)Offset2, IdaAddress2);

		}

		/*
			HalalGS-19.10: LogMinHook: Info: UFortAthenaAISpawnerDataComponent_InventoryBase::OnSpawned - AISpawnerDataComponent: Default__BP_AISC_Inv_FrenchYedoc_C, AIPawn: BP_Pawn_FrenchYedoc_C Artemis_Terrain.Artemis_Terrain.PersistentLevel.BP_Pawn_FrenchYedoc_C_2147442775
			HalalGS-19.10: LogMinHook: Info: AFortAIPawn::0x2 - called in Offset [0x3f1e4b0], IdaAddress [00007FF69A4EE4B0]
			HalalGS-19.10: LogMinHook: Info: AFortAIPawn::0x3 - called in Offset [0x672f014], IdaAddress [00007FF69CCFF014]
			HalalGS-19.10: LogMinHook: Info: UFortAthenaAISpawnerDataComponent_InventoryBase::OnSpawned - called in Offset [0x5ec3ecd], IdaAddress [00007FF69C493ECD]
		*/

		uintptr_t Offset = uintptr_t(_ReturnAddress()) - InSDKUtils::GetImageBase();
		uintptr_t IdaAddress = Offset + 0x7FF6965D0000ULL;

		FN_LOG(LogMinHook, Log, "UFortAthenaAISpawnerDataComponent_InventoryBase::OnSpawned - called in Offset [0x%llx], IdaAddress [%p]", (unsigned long long)Offset, IdaAddress);

		OnSpawnedOG(AISpawnerDataComponent, AIPawn);
	}

	float GetMaxTickRate()
	{
		return 30.0f;
	}

	void OnStart(UAthenaAIServicePlayerBots* AIServicePlayerBots)
	{
		uintptr_t Offset = uintptr_t(_ReturnAddress()) - InSDKUtils::GetImageBase();
		uintptr_t IdaAddress = Offset + 0x7FF66E650000ULL;

		FN_LOG(LogMinHook, Log, "----------------------------------------------------------------------------------------------------------------");
		FN_LOG(LogMinHook, Log, "----------------------------------------------------------------------------------------------------------------");
		FN_LOG(LogMinHook, Log, "----------------------------------------------------------------------------------------------------------------");
		FN_LOG(LogMinHook, Log, "----------------------------------------------------------------------------------------------------------------");
		FN_LOG(LogMinHook, Log, "----------------------------------------------------------------------------------------------------------------");
		FN_LOG(LogMinHook, Log, "----------------------------------------------------------------------------------------------------------------");
		FN_LOG(LogMinHook, Log, "----------------------------------------------------------------------------------------------------------------");
		FN_LOG(LogMinHook, Log, "----------------------------------------------------------------------------------------------------------------");
		FN_LOG(LogMinHook, Log, "----------------------------------------------------------------------------------------------------------------");
		FN_LOG(LogMinHook, Log, "Function [UAthenaAIServicePlayerBots::OnStart] successfully hooked with Offset [0x%llx], IdaAddress [%p], GameMode: [%s]", (unsigned long long)Offset, IdaAddress, AIServicePlayerBots->GetFullName().c_str());
		FN_LOG(LogMinHook, Log, "----------------------------------------------------------------------------------------------------------------");
		FN_LOG(LogMinHook, Log, "----------------------------------------------------------------------------------------------------------------");
		FN_LOG(LogMinHook, Log, "----------------------------------------------------------------------------------------------------------------");
		FN_LOG(LogMinHook, Log, "----------------------------------------------------------------------------------------------------------------");
		FN_LOG(LogMinHook, Log, "----------------------------------------------------------------------------------------------------------------");
		FN_LOG(LogMinHook, Log, "----------------------------------------------------------------------------------------------------------------");
		FN_LOG(LogMinHook, Log, "----------------------------------------------------------------------------------------------------------------");
		FN_LOG(LogMinHook, Log, "----------------------------------------------------------------------------------------------------------------");
		FN_LOG(LogMinHook, Log, "----------------------------------------------------------------------------------------------------------------");
	}

	AActor* (*SpawnActorOG)(UWorld* World, UClass* Class, FTransform const* Transform, const FActorSpawnParameters& SpawnParameters);
	AActor* SpawnActor(UWorld* World, UClass* Class, FTransform const* Transform, const FActorSpawnParameters& SpawnParameters)
	{
		UObject* DefaultObject = Class->CreateDefaultObject();

		if (DefaultObject->IsA(AAthenaAIDirector::StaticClass()))
		{
			/*uintptr_t Offset = uintptr_t(DefaultObject->VTable[0x20]) - InSDKUtils::GetImageBase();
			uintptr_t IdaAddress = Offset + 0x7FF6965D0000ULL;

			bool (*CanCreateInCurrentContext)() = decltype(CanCreateInCurrentContext)(DefaultObject->VTable[0x20]);

			FN_LOG(LogMinHook, Log, "SpawnActor - Offset [0x%llx], IdaAddress [%p], CanCreateInCurrentContext: %i", (unsigned long long)Offset, IdaAddress, CanCreateInCurrentContext);*/
		}

		return SpawnActorOG(World, Class, Transform, SpawnParameters);
	}


	void InitHook()
	{
		uintptr_t AddressChangingGameSessionId = MinHook::FindPattern(Patterns::ChangingGameSessionId);
		uintptr_t AddressInternalGetNetMode = MinHook::FindPattern(Patterns::InternalGetNetMode);
		uintptr_t AddressActorInternalGetNetMode = MinHook::FindPattern(Patterns::ActorInternalGetNetMode);
		uintptr_t AddressLocalSpawnPlayActor = MinHook::FindPattern(Patterns::LocalSpawnPlayActor);
		uintptr_t AddressKickPlayer = MinHook::FindPattern(Patterns::KickPlayer);
		uintptr_t AddressDispatchRequest = MinHook::FindPattern(Patterns::DispatchRequest);

		MH_CreateHook((LPVOID)(AddressChangingGameSessionId), Ret, nullptr);
		MH_EnableHook((LPVOID)(AddressChangingGameSessionId));
		MH_CreateHook((LPVOID)(AddressInternalGetNetMode), ReturnNetMode, nullptr);
		MH_EnableHook((LPVOID)(AddressInternalGetNetMode));
		MH_CreateHook((LPVOID)(AddressActorInternalGetNetMode), ReturnNetMode, nullptr);
		MH_EnableHook((LPVOID)(AddressActorInternalGetNetMode));
		MH_CreateHook((LPVOID)(AddressLocalSpawnPlayActor), RetTrue, nullptr);
		MH_EnableHook((LPVOID)(AddressLocalSpawnPlayActor));
		MH_CreateHook((LPVOID)(AddressKickPlayer), Ret, nullptr);
		MH_EnableHook((LPVOID)(AddressKickPlayer));
		MH_CreateHook((LPVOID)(AddressDispatchRequest), DispatchRequest, (LPVOID*)(&DispatchRequestOG));
		MH_EnableHook((LPVOID)(AddressDispatchRequest));

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x11BE904), RetFalse, nullptr);
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x11BE904));
		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x1F901AC), Ret, nullptr);
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x1F901AC));
		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x44A9B00), RetFalse, nullptr);
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x44A9B00));
		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x4dd8528), RetTrue, nullptr);
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x4dd8528)); 
		//MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0xd708e0), RetTrue, nullptr); // NeedsLoadForClient
		//MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0xd708e0));
		//MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x1af4a64), RetTrue, nullptr); // NeedsLoadForServer
		//MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x1af4a64));
		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0xd6bae4), Ret, nullptr);
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0xd6bae4));

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x18b3df0), Ret, nullptr); // RequestExitWithStatus
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x18b3df0));

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x63c7898), Ret, nullptr); // RequestExit
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x63c7898));

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x5edfc74), OnStart, nullptr);
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x5edfc74));

		//MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0xf951e8), Ret, nullptr); // Showing LoadingScreen
		//MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0xf951e8));

		/*MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0xD70E2C), SpawnActor, (LPVOID*)(&SpawnActorOG));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0xD70E2C));*/

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + Offsets::ProcessEvent), ProcessEvent, (LPVOID*)(&ProcessEventOG));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + Offsets::ProcessEvent));

		UClass* FortWeaponComponentClass = UFortWeaponComponent::StaticClass();

		UFunction* OnEquipFunc = FortWeaponComponentClass->GetFunction("FortWeaponComponent", "OnEquip");
		MinHook::HookFunctionExec(OnEquipFunc, OnEquip, (LPVOID*)(&OnEquipOG));
		UFunction* OnUnEquipFunc = FortWeaponComponentClass->GetFunction("FortWeaponComponent", "OnUnEquip");
		MinHook::HookFunctionExec(OnUnEquipFunc, OnUnEquip, (LPVOID*)(&OnUnEquipOG));

		UClass* FortAthenaVehicleClass = AFortPhysicsPawn::StaticClass();

		UFunction* ServerMoveFunc = FortAthenaVehicleClass->GetFunction("FortPhysicsPawn", "ServerMove");
		MinHook::HookFunctionExec(ServerMoveFunc, ServerMove, nullptr);

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x625f128), AddItemToInventoryOwner, (LPVOID*)(&AddItemToInventoryOwnerOG));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x625f128));

		UClass* FortHeldObjectComponentClass = UFortHeldObjectComponent::StaticClass();

		UFunction* PickupHeldObjectFunc = FortHeldObjectComponentClass->GetFunction("FortHeldObjectComponent", "PickupHeldObject");
		MinHook::HookFunctionExec(PickupHeldObjectFunc, PickupHeldObject, nullptr);
		UFunction* DropHeldObjectFunc = FortHeldObjectComponentClass->GetFunction("FortHeldObjectComponent", "DropHeldObject");
		MinHook::HookFunctionExec(DropHeldObjectFunc, DropHeldObject, nullptr);

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x5ec8548), OnSpawned, (LPVOID*)(&OnSpawnedOG));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x5ec8548));

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0xaed938), GetMaxTickRate, nullptr);
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0xaed938));

		/*MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x1ccfbbc), EquipMountedWeapon, nullptr);
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x1ccfbbc));*/

		FN_LOG(LogInit, Log, "InitHook Success!");
	}
}