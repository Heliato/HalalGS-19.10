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

		AFortPlayerState* PlayerState = Cast<AFortPlayerState>(Instigator->PlayerState);
		if (!PlayerState) return;

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
			
			if (!Weapon->EquippedAbilityHandles.Num() && !Weapon->EquippedAbilitySetHandles.Num())
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

							/*if (DefaultGameplayAbility)
							{
								FGameplayAbilitySpec GameplayAbilitySpec;
								GameplayAbilitySpec.CreateDefaultAbilitySpec(DefaultGameplayAbility, 1, -1, Weapon);

								FGameplayAbilitySpecHandle Handle;
								AbilitySystemComponent->GiveAbility(&Handle, GameplayAbilitySpec);

								Weapon->EquippedAbilitySetHandles.Add(Handle);
							}*/
						}
					}
				}
			}

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

		AFortPlayerState* PlayerState = Cast<AFortPlayerState>(Instigator->PlayerState);
		if (!PlayerState) return;

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

			/*if (Weapon->ImpactAbilitySpecHandle.Handle != -1)
			{
				AbilitySystemComponent->ClearAbility(Weapon->ImpactAbilitySpecHandle);
				Weapon->ImpactAbilitySpecHandle.Handle = -1;
			}

			if (Weapon->ReticleTraceOverrideSpecHandle.Handle != -1)
			{
				AbilitySystemComponent->ClearAbility(Weapon->ReticleTraceOverrideSpecHandle);
				Weapon->ReticleTraceOverrideSpecHandle.Handle = -1;
			}*/

			for (int32 i = 0; i < Weapon->EquippedAbilityHandles.Num(); i++)
			{
				FGameplayAbilitySpecHandle& EquippedAbilityHandle = Weapon->EquippedAbilityHandles[i];
				AbilitySystemComponent->ClearAbility(EquippedAbilityHandle);
				EquippedAbilityHandle.Handle = -1;
			}

			Weapon->EquippedAbilityHandles.Free();

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

			if (GetAsyncKeyState(VK_F4) & 0x1)
			{
				AFortPlayerController* PlayerController = Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));

				if (!PlayerController || !PlayerController->Pawn)
					return;

				auto WoodItemData = StaticFindObject<UFortResourceItemDefinition>(L"/Game/Items/ResourcePickups/WoodItemData.WoodItemData");

				FFortItemEntry ItemEntry;
				ItemEntry.CreateDefaultItemEntry(WoodItemData, 30, 0);

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
			}

			if (GetAsyncKeyState(VK_F5) & 0x1)
			{
				AFortPlayerController* PlayerController = Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));

				if (!PlayerController || !PlayerController->Pawn)
					return;

				//auto TID_ContextTrap_Athena = StaticFindObject<UFortContextTrapItemDefinition>(L"/Game/Athena/Items/Traps/TID_ContextTrap_Athena.TID_ContextTrap_Athena");
				auto TID_ContextTrap_Athena = StaticFindObject<UFortWeaponRangedItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Hook_Gun_VR_Ore_T03.WID_Hook_Gun_VR_Ore_T03");
				// FortniteGame/Content.uasset

				FFortItemEntry ItemEntry;
				ItemEntry.CreateDefaultItemEntry(TID_ContextTrap_Athena, 1, 0);
				ItemEntry.LoadedAmmo = 10;

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
				);
			}

			if (GetAsyncKeyState(VK_F6) & 0x1)
			{
				AFortPlayerController* PlayerController = Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));

				if (!PlayerController)
					return;

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
				}
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

				if (!PlayerController || !PlayerController->Pawn)
					return;

				FName TierGroupName = UKismetStringLibrary::Conv_StringToName(L"Loot_AthenaTreasure");
				int32 WorldLevel = UFortKismetLibrary::GetLootLevel(PlayerController);

				int32 LootTier = -1;
				FName LootTierKey = FName(0);
				bool bResult = Loots::PickLootTierKeyAndLootTierFromTierGroup(&LootTierKey, &LootTier, TierGroupName, WorldLevel, 0, -1, FGameplayTagContainer());

				FN_LOG(LogHooks, Log, "bResult: %i, TierGroupName: %s, LootTierKey: %s, LootTier: %i, ", bResult, TierGroupName.ToString().c_str(), LootTierKey.ToString().c_str(), LootTier);
			}

			if (GetAsyncKeyState(VK_F10) & 0x1)
			{
				UGameDataBR* GameDataBR = Globals::GetGameDataBR();

				for (int32 i = 0; i < GameDataBR->LootTierDataTablesBR.Num(); i++)
				{
					TSoftObjectPtr<UDataTable> LootTierDataTable = GameDataBR->LootTierDataTablesBR[i];
					UDataTable* DataTable = Loots::LoadDataTable(LootTierDataTable);

					FN_LOG(LogHooks, Log, "%i - LootTierDataTables: %s", i, DataTable->GetFullName().c_str());
				}

				for (int32 i = 0; i < GameDataBR->LootPackageDataTablesBR.Num(); i++)
				{
					TSoftObjectPtr<UDataTable> LootPackageDataTable = GameDataBR->LootPackageDataTablesBR[i];
					UDataTable* DataTable = Loots::LoadDataTable(LootPackageDataTable);

					FN_LOG(LogHooks, Log, "%i - LootPackageDataTable: %s", i, DataTable->GetFullName().c_str());
				}
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

				Functions::FillSafeZoneDurations();

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
				FN_LOG(Logs, Log, "Function: [%s]", Function->GetFullName().c_str());
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

		FN_LOG(Logs, Log, "OnEquip - Params->Weapon: %s", Params->Weapon->GetName().c_str());

		ApplyAbilities(Params->Weapon);

		OnEquipOG(WeaponComponent, Stack, Ret);
	}

	void (*OnUnEquipOG)(UFortWeaponComponent* WeaponComponent, FFrame& Stack, void* Ret);
	void OnUnEquip(UFortWeaponComponent* WeaponComponent, FFrame& Stack, void* Ret)
	{
		auto Params = (FortWeaponComponent_EquipTest*)Stack.Locals;

		FN_LOG(Logs, Log, "OnUnEquip - Params->Weapon: %s", Params->Weapon->GetName().c_str());

		RemoveAbilities(Params->Weapon);

		OnUnEquipOG(WeaponComponent, Stack, Ret);
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
		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0xd6bae4), Ret, nullptr);
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0xd6bae4));

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + Offsets::ProcessEvent), ProcessEvent, (LPVOID*)(&ProcessEventOG));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + Offsets::ProcessEvent));

		UClass* FortWeaponComponentClass = UFortWeaponComponent::StaticClass();

		UFunction* OnEquipFunc = FortWeaponComponentClass->GetFunction("FortWeaponComponent", "OnEquip");
		MinHook::HookFunctionExec(OnEquipFunc, OnEquip, (LPVOID*)(&OnEquipOG));
		UFunction* OnUnEquipFunc = FortWeaponComponentClass->GetFunction("FortWeaponComponent", "OnUnEquip");
		MinHook::HookFunctionExec(OnUnEquipFunc, OnUnEquip, (LPVOID*)(&OnUnEquipOG));

		FN_LOG(LogInit, Log, "InitHook Success!");
	}
}