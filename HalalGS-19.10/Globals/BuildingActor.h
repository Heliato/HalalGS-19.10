#pragma once

namespace BuildingActor
{
	void (*ABuildingContainer_PostUpdateOG)(ABuildingContainer* BuildingContainer, EFortBuildingPersistentState BuildingPersistentState, __int64 a3);
	void (*ABuildingSMActor_PostUpdateOG)(ABuildingSMActor* BuildingSMActor);
	void (*OnDamageServerOG)(ABuildingActor* BuildingActor, float Damage, const FGameplayTagContainer& DamageTags, const FVector& Momentum, const FHitResult& HitInfo, AController* InstigatedBy, AActor* DamageCauser, const FGameplayEffectContextHandle& EffectContext);
	void (*SelectMeshSetLootTier)(ABuildingSMActor* BuildingSMActor, int32 LootTier);

	bool SpawnLoot(ABuildingContainer* BuildingContainer, AFortPlayerPawn* PlayerPawn)
	{
		if (!BuildingContainer->HasAuthority() || !BuildingContainer->GetWorld() || !PlayerPawn)
			return false;

		BuildingContainer->ForceNetUpdate();

		if (!BuildingContainer->bAlreadySearched)
		{
			const float LootSpawnLocationX = BuildingContainer->LootSpawnLocation_Athena.X;
			const float LootSpawnLocationY = BuildingContainer->LootSpawnLocation_Athena.Y;
			const float LootSpawnLocationZ = BuildingContainer->LootSpawnLocation_Athena.Z;

			FVector SpawnLocation = BuildingContainer->K2_GetActorLocation() +
				BuildingContainer->GetActorForwardVector() * LootSpawnLocationX +
				BuildingContainer->GetActorRightVector() * LootSpawnLocationY +
				BuildingContainer->GetActorUpVector() * LootSpawnLocationZ;

			UFortWorldItemDefinition* LootTestingData = BuildingContainer->LootTestingData;

			if (LootTestingData)
			{
				FFortItemEntry ItemEntry;
				Inventory::MakeItemEntry(&ItemEntry, LootTestingData, 1, -1, -1, 1.0f);

				UFortWorldItemDefinition* WorldItemDefinition = Cast<UFortWorldItemDefinition>(ItemEntry.ItemDefinition);

				if (WorldItemDefinition &&
					WorldItemDefinition->ItemType == EFortItemType::WeaponMelee ||
					WorldItemDefinition->ItemType == EFortItemType::WeaponRanged)
				{
					float NewDurability = 1.0f * BuildingContainer->LootedWeaponsDurabilityModifier;

					ItemEntry.SetDurability(NewDurability);
					Inventory::SetStateValue(&ItemEntry, EFortItemEntryState::DurabilityInitialized, 1);
				}

				FFortCreatePickupData* (*CreatePickupData)(FFortCreatePickupData * PickupData, UWorld * World, FFortItemEntry ItemEntry, FVector SpawnLocation, FRotator SpawnRotation, AFortPlayerController * PlayerController, UClass * OverrideClass, AActor * Investigator, int a9, int a10) = decltype(CreatePickupData)(0x64da9dc + uintptr_t(GetModuleHandle(0)));

				FFortCreatePickupData PickupData{};
				CreatePickupData(&PickupData, BuildingContainer->GetWorld(), ItemEntry, SpawnLocation, FRotator(), nullptr, nullptr, nullptr, 0, 0);
				PickupData.PickupSourceTypeFlags = EFortPickupSourceTypeFlag::Container;
				PickupData.PickupSpawnSource = EFortPickupSpawnSource::Unset;

				AFortPickup* (*CreatePickupFromData)(FFortCreatePickupData * PickupData) = decltype(CreatePickupFromData)(0x64dd1b4 + uintptr_t(GetModuleHandle(0)));
				AFortPickup* Pickup = CreatePickupFromData(&PickupData);

				if (Pickup)
				{
					UFortKismetLibrary::TossPickupFromContainer(
						BuildingContainer,
						BuildingContainer,
						Pickup,
						1,
						1,
						BuildingContainer->LootTossConeHalfAngle_Athena,
						BuildingContainer->LootTossDirection_Athena,
						BuildingContainer->LootTossSpeed_Athena,
						true
					);


					Pickup->bTossedFromContainer = true;
					Pickup->OnRep_TossedFromContainer();
				}

				ItemEntry.FreeItemEntry();
			}
			else if (BuildingContainer->ContainerLootTierKey.IsValid())
			{
				int32 LootLevel = UFortKismetLibrary::GetLootLevel(BuildingContainer);

				TArray<FFortItemEntry> LootToDrops;
				Loots::PickLootDrops(&LootToDrops, LootLevel, BuildingContainer->ContainerLootTierKey, 0, 0, BuildingContainer->StaticGameplayTags, true, false);

				BuildingContainer->HighestRarity = EFortRarity::Common;

				for (int32 i = 0; i < LootToDrops.Num(); i++)
				{
					FFortItemEntry LootToDrop = LootToDrops[i];

					UFortWorldItemDefinition* WorldItemDefinition = Cast<UFortWorldItemDefinition>(LootToDrop.ItemDefinition);

					if (!WorldItemDefinition)
					{
						UFortItemDefinition* ItemDefinition = LootToDrop.ItemDefinition;
						FN_LOG(LogBuildingContainer, Error, "Attempted to spawn non-world item %s!", ItemDefinition->GetName().c_str());
						continue;
					}

					EFortRarity Rarity = WorldItemDefinition->GetRarity();
					EFortRarity HighestRarity = BuildingContainer->HighestRarity;

					if (HighestRarity < Rarity)
						BuildingContainer->HighestRarity = Rarity;

					if (WorldItemDefinition->ItemType == EFortItemType::WeaponMelee ||
						WorldItemDefinition->ItemType == EFortItemType::WeaponRanged)
					{
						float NewDurability = 1.0f * BuildingContainer->LootedWeaponsDurabilityModifier;

						LootToDrop.SetDurability(NewDurability);
						Inventory::SetStateValue(&LootToDrop, EFortItemEntryState::DurabilityInitialized, 1);
					}

					FFortCreatePickupData* (*CreatePickupData)(FFortCreatePickupData * PickupData, UWorld * World, FFortItemEntry ItemEntry, FVector SpawnLocation, FRotator SpawnRotation, AFortPlayerController * PlayerController, UClass * OverrideClass, AActor * Investigator, int a9, int a10) = decltype(CreatePickupData)(0x64da9dc + uintptr_t(GetModuleHandle(0)));

					FFortCreatePickupData PickupData{};
					CreatePickupData(&PickupData, BuildingContainer->GetWorld(), LootToDrop, SpawnLocation, FRotator(), nullptr, nullptr, nullptr, 0, 0);
					PickupData.PickupSourceTypeFlags = EFortPickupSourceTypeFlag::Container;
					PickupData.PickupSpawnSource = EFortPickupSpawnSource::LootDrop;

					AFortPickup* (*CreatePickupFromData)(FFortCreatePickupData * PickupData) = decltype(CreatePickupFromData)(0x64dd1b4 + uintptr_t(GetModuleHandle(0)));
					AFortPickup* Pickup = CreatePickupFromData(&PickupData);

					if (Pickup)
					{
						UFortKismetLibrary::TossPickupFromContainer(
							BuildingContainer,
							BuildingContainer,
							Pickup,
							(i + 1),
							LootToDrops.Num(),
							BuildingContainer->LootTossConeHalfAngle_Athena,
							BuildingContainer->LootTossDirection_Athena,
							BuildingContainer->LootTossSpeed_Athena,
							true
						);


						Pickup->bTossedFromContainer = true;
						Pickup->OnRep_TossedFromContainer();
					}
				}

				FFortItemEntry::FreeItemEntries(&LootToDrops);
			}
			else
			{
				int32 LootLevel = UFortKismetLibrary::GetLootLevel(BuildingContainer);

				TArray<FFortItemEntry> LootToDrops;
				bool bResult = UFortKismetLibrary::PickLootDrops(BuildingContainer, &LootToDrops, BuildingContainer->SearchLootTierGroup, LootLevel, -1);

				if (bResult)
				{
					BuildingContainer->HighestRarity = EFortRarity::Common;

					for (int32 i = 0; i < LootToDrops.Num(); i++)
					{
						FFortItemEntry LootToDrop = LootToDrops[i];

						UFortWorldItemDefinition* WorldItemDefinition = Cast<UFortWorldItemDefinition>(LootToDrop.ItemDefinition);

						if (!WorldItemDefinition)
						{
							UFortItemDefinition* ItemDefinition = LootToDrop.ItemDefinition;
							FN_LOG(LogBuildingContainer, Error, "Attempted to spawn non-world item %s!", ItemDefinition->GetName().c_str());
							continue;
						}

						EFortRarity Rarity = WorldItemDefinition->GetRarity();
						EFortRarity HighestRarity = BuildingContainer->HighestRarity;

						if (HighestRarity < Rarity)
							BuildingContainer->HighestRarity = Rarity;

						if (WorldItemDefinition->ItemType == EFortItemType::WeaponMelee ||
							WorldItemDefinition->ItemType == EFortItemType::WeaponRanged)
						{
							float NewDurability = 1.0f * BuildingContainer->LootedWeaponsDurabilityModifier;

							LootToDrop.SetDurability(NewDurability);
							LootToDrop.SetStateValue(EFortItemEntryState::DurabilityInitialized, 1);
						}

						FFortCreatePickupData* (*CreatePickupData)(FFortCreatePickupData * PickupData, UWorld * World, FFortItemEntry ItemEntry, FVector SpawnLocation, FRotator SpawnRotation, AFortPlayerController * PlayerController, UClass * OverrideClass, AActor * Investigator, int a9, int a10) = decltype(CreatePickupData)(0x64da9dc + uintptr_t(GetModuleHandle(0)));

						FFortCreatePickupData PickupData{};
						CreatePickupData(&PickupData, BuildingContainer->GetWorld(), LootToDrop, SpawnLocation, FRotator(), nullptr, nullptr, nullptr, 0, 0);
						PickupData.PickupSourceTypeFlags = EFortPickupSourceTypeFlag::Container;
						PickupData.PickupSpawnSource = EFortPickupSpawnSource::LootDrop;

						AFortPickup* (*CreatePickupFromData)(FFortCreatePickupData * PickupData) = decltype(CreatePickupFromData)(0x64dd1b4 + uintptr_t(GetModuleHandle(0)));
						AFortPickup* Pickup = CreatePickupFromData(&PickupData);

						if (Pickup)
						{
							UFortKismetLibrary::TossPickupFromContainer(
								BuildingContainer,
								BuildingContainer,
								Pickup,
								(i + 1),
								LootToDrops.Num(),
								BuildingContainer->LootTossConeHalfAngle_Athena,
								BuildingContainer->LootTossDirection_Athena,
								BuildingContainer->LootTossSpeed_Athena,
								true
							);


							Pickup->bTossedFromContainer = true;
							Pickup->OnRep_TossedFromContainer();
						}
					}
				}
			}

			if (PlayerPawn)
			{
				float LootNoiseRange = BuildingContainer->LootNoiseRange;

				if (LootNoiseRange > 0.0f)
				{
					const FVector& NoiseLocation = BuildingContainer->K2_GetActorLocation();
					UFortAIFunctionLibrary::MakeNoiseEventAtLocation(PlayerPawn, LootNoiseRange, NoiseLocation, FName(0));
				}
			}

			if (!BuildingContainer->bDestroyed)
			{
				BuildingContainer->SetSearchedContainer(PlayerPawn);
			}
		}

		BuildingContainer->SearchBounceData.SearchAnimationCount++;
		BuildingContainer->BounceContainer();

		return true;
	}

	void SpawnFloorLoot(ABuildingContainer* BuildingContainer)
	{
		if (!BuildingContainer->HasAuthority() || !BuildingContainer->GetWorld())
			return;

		BuildingContainer->ForceNetUpdate();

		if (!BuildingContainer->bAlreadySearched)
		{
			if (BuildingContainer->ContainerLootTierKey.IsValid())
			{
				const float LootSpawnLocationX = BuildingContainer->LootSpawnLocation_Athena.X;
				const float LootSpawnLocationY = BuildingContainer->LootSpawnLocation_Athena.Y;
				const float LootSpawnLocationZ = BuildingContainer->LootSpawnLocation_Athena.Z;

				FVector SpawnLocation = BuildingContainer->K2_GetActorLocation() +
					BuildingContainer->GetActorForwardVector() * LootSpawnLocationX +
					BuildingContainer->GetActorRightVector() * LootSpawnLocationY +
					BuildingContainer->GetActorUpVector() * LootSpawnLocationZ;

				int32 LootLevel = UFortKismetLibrary::GetLootLevel(BuildingContainer);

				TArray<FFortItemEntry> LootToDrops;
				Loots::PickLootDrops(&LootToDrops, LootLevel, BuildingContainer->ContainerLootTierKey, 0, 0, BuildingContainer->StaticGameplayTags, true, false);

				BuildingContainer->HighestRarity = EFortRarity::Common;

				for (int32 i = 0; i < LootToDrops.Num(); i++)
				{
					FFortItemEntry LootToDrop = LootToDrops[i];

					UFortWorldItemDefinition* WorldItemDefinition = Cast<UFortWorldItemDefinition>(LootToDrop.ItemDefinition);

					if (!WorldItemDefinition)
					{
						UFortItemDefinition* ItemDefinition = LootToDrop.ItemDefinition;
						FN_LOG(LogBuildingContainer, Error, "Attempted to spawn non-world item %s!", ItemDefinition->GetName().c_str());
						continue;
					}

					EFortRarity Rarity = WorldItemDefinition->GetRarity();
					EFortRarity HighestRarity = BuildingContainer->HighestRarity;

					if (HighestRarity < Rarity)
						BuildingContainer->HighestRarity = Rarity;

					if (WorldItemDefinition->ItemType == EFortItemType::WeaponMelee ||
						WorldItemDefinition->ItemType == EFortItemType::WeaponRanged)
					{
						float NewDurability = 1.0f * BuildingContainer->LootedWeaponsDurabilityModifier;

						LootToDrop.SetDurability(NewDurability);
						LootToDrop.SetStateValue(EFortItemEntryState::DurabilityInitialized, 1);
					}

					FFortCreatePickupData* (*CreatePickupData)(FFortCreatePickupData * PickupData, UWorld * World, FFortItemEntry ItemEntry, FVector SpawnLocation, FRotator SpawnRotation, AFortPlayerController * PlayerController, UClass * OverrideClass, AActor * Investigator, int a9, int a10) = decltype(CreatePickupData)(0x64da9dc + uintptr_t(GetModuleHandle(0)));

					FFortCreatePickupData PickupData{};
					CreatePickupData(&PickupData, BuildingContainer->GetWorld(), LootToDrop, SpawnLocation, FRotator(), nullptr, nullptr, nullptr, 0, 0);
					PickupData.PickupSourceTypeFlags = EFortPickupSourceTypeFlag::FloorLoot;
					PickupData.PickupSpawnSource = EFortPickupSpawnSource::Unset;

					AFortPickup* (*CreatePickupFromData)(FFortCreatePickupData * PickupData) = decltype(CreatePickupFromData)(0x64dd1b4 + uintptr_t(GetModuleHandle(0)));
					AFortPickup* Pickup = CreatePickupFromData(&PickupData);

					if (Pickup)
					{
						UFortKismetLibrary::TossPickupFromContainer(
							BuildingContainer,
							BuildingContainer,
							Pickup,
							(i + 1),
							LootToDrops.Num(),
							BuildingContainer->LootTossConeHalfAngle_Athena,
							BuildingContainer->LootTossDirection_Athena,
							BuildingContainer->LootTossSpeed_Athena,
							true
						);


						Pickup->bTossedFromContainer = true;
						Pickup->OnRep_TossedFromContainer();
					}
				}

				FFortItemEntry::FreeItemEntries(&LootToDrops);
			}

			if (!BuildingContainer->bDestroyed)
			{
				BuildingContainer->SetSearchedContainer(nullptr);
			}
		}
	}

	void SelectMeshSetLootTierKey(ABuildingSMActor* BuildingSMActor, FName LootTierKey)
	{
		int32 LootTier = Loots::FindLootTierFromKey(LootTierKey);
		FTierMeshSets* MeshSets = nullptr;

		if (BuildingSMActor->AlternateMeshes.Num() > 0)
		{
			for (int32 i = 0; i < BuildingSMActor->AlternateMeshes.Num(); i++)
			{
				FTierMeshSets* AlternateMeshe = &BuildingSMActor->AlternateMeshes[i];
				int32 Tier = AlternateMeshe->Tier;

				if (Tier <= LootTier && (!MeshSets || MeshSets->Tier < Tier))
				{
					if (AlternateMeshe->MeshSets.Num() <= 0)
					{
						FN_LOG(LogBuildingSMActor, Warning, "No Alternative Mesh available for Building: %s at LootTier: %d", BuildingSMActor->GetName().c_str(), Tier);
					}
					else
					{
						MeshSets = AlternateMeshe;
					}
				}
			}

			if (MeshSets)
			{
				int32 AltMeshIdx = BuildingSMActor->AltMeshIdx;

				if (AltMeshIdx != -1)
				{
					BuildingSMActor->SetMeshSet(MeshSets->MeshSets[AltMeshIdx]);
				}
			}
		}

		FN_LOG(LogBuildingSMActor, Debug, "ABuildingSMActor::SelectMeshSet(FName LootTierKey) Building: %s, AltMeshIdx: %d", BuildingSMActor->GetName().c_str(), BuildingSMActor->AltMeshIdx);
	}

	FName RedirectAthenaLootTierGroups(FName LootTierGroup)
	{
		AFortGameModeAthena* GameModeAthena = Globals::GetGameMode();

		if (GameModeAthena)
		{
			for (int32 i = 0; i < GameModeAthena->RedirectAthenaLootTierGroups.Elements.Elements.Num(); ++i)
			{
				auto& Pair = GameModeAthena->RedirectAthenaLootTierGroups.Elements.Elements.Data[i].ElementData.Value;

				if (Pair.Key() == LootTierGroup)
					return Pair.Value();
			}
		}

		return LootTierGroup;
	}

	void ABuildingContainer_PostUpdate(ABuildingContainer* BuildingContainer, EFortBuildingPersistentState BuildingPersistentState, __int64 a3)
	{
		ABuildingContainer_PostUpdateOG(BuildingContainer, BuildingPersistentState, a3);

		if (BuildingPersistentState == EFortBuildingPersistentState::New)
		{
			float LootSpawnThreshold = 0.0f;

			bool bSpawnAllLoot = false;

			if (bSpawnAllLoot)
				LootSpawnThreshold = 1.0f;

			if (BuildingContainer->SearchLootTierGroup.IsValid())
			{
				BuildingContainer->SearchLootTierGroup = RedirectAthenaLootTierGroups(BuildingContainer->SearchLootTierGroup);

				FName* LootTierKey = nullptr;
				int32 ChooseLootTier = -1;
				int32 LootTier = -1;

				LootSpawnThreshold = 1.0f;

				if (BuildingContainer->SearchLootTierChosenQuotaInfo.LootTierKey.ComparisonIndex > 0 ||
					BuildingContainer->SearchLootTierChosenQuotaInfo.LootTierKey.Number > 0)
				{
					LootTierKey = &BuildingContainer->ContainerLootTierKey;
					ChooseLootTier = BuildingContainer->SearchLootTierChosenQuotaInfo.LootTier;

					BuildingContainer->ContainerLootTierKey = BuildingContainer->SearchLootTierChosenQuotaInfo.LootTierKey;

					LootTier = ChooseLootTier;
				}
				else
				{
					int32 LootLevel = UFortKismetLibrary::GetLootLevel(BuildingContainer);

					LootTierKey = &BuildingContainer->ContainerLootTierKey;

					Loots::PickLootTierKeyAndLootTierFromTierGroup(
						&BuildingContainer->ContainerLootTierKey,
						&LootTier,
						BuildingContainer->SearchLootTierGroup,
						LootLevel,
						0,
						-1,
						BuildingContainer->StaticGameplayTags
					);

					ChooseLootTier = LootTier;
				}

				SelectMeshSetLootTier(BuildingContainer, ChooseLootTier);

				EFortBuildingPersistentState PersistentState = EFortBuildingPersistentState::Default;

				if (!bSpawnAllLoot &&
					!BuildingContainer->bAlwaysMaintainLoot &&
					!Loots::IsLootDropPossible(*LootTierKey, L"ABuildingContainer::PostUpdate", 0))
				{
					LootTierKey = nullptr;
					PersistentState = EFortBuildingPersistentState::Searched;

					BuildingContainer->SetSearchedContainer(nullptr);

					if (!BuildingContainer->bAlwaysShowContainer)
						LootSpawnThreshold = 0.0f;
				}

#ifdef FLOORLOOT
				UBlueprintGeneratedClass* FloorLootClass = StaticFindObject<UBlueprintGeneratedClass>(L"/Game/Athena/Environments/Blueprints/Tiered_Athena_FloorLoot_01.Tiered_Athena_FloorLoot_01_C");
				UBlueprintGeneratedClass* FloorLootWarmupClass = StaticFindObject<UBlueprintGeneratedClass>(L"/Game/Athena/Environments/Blueprints/Tiered_Athena_FloorLoot_Warmup.Tiered_Athena_FloorLoot_Warmup_C");

				if (BuildingContainer->IsA(FloorLootClass) || BuildingContainer->IsA(FloorLootWarmupClass))
					SpawnFloorLoot(BuildingContainer);
#endif // FLOORLOOT
			}

			/*float v6 = 0.0f;

			int v19 = *(int*)(a3 + 0x14);
			if (v19 > 0)
			{
				if (*(int*)(a3 + 0x10) >= v19)
					*(int*)(a3 + 0x10) = 0;

				int v20 = *(int*)(a3 + 0x10);

				*(int*)(a3 + 0x10) = v20 + 1;

				v6 = *(float*)(a3 + 4i64 * v20);
			}*/

			float v6 = (float)rand() * 0.000030518509f;

			if ((float)((float)(v6 * 1.0f) + 0.0000000099999999f) > LootSpawnThreshold)
			{
				if (BuildingContainer->bBuriedTreasure)
					BuildingContainer->SetSearchedContainer(nullptr);

				BuildingContainer->ContainerLootTierKey = FName(0);
			}
		}
		else
		{
			if (BuildingContainer->ContainerLootTierKey.IsValid())
			{
				SelectMeshSetLootTierKey(BuildingContainer, BuildingContainer->ContainerLootTierKey);
			}
			else
			{
				int32 LootLevel = UFortKismetLibrary::GetLootLevel(BuildingContainer);
				int32 LootTier = -1;

				Loots::PickLootTierKeyAndLootTierFromTierGroup(
					&BuildingContainer->ContainerLootTierKey,
					&LootTier,
					BuildingContainer->SearchLootTierGroup,
					LootLevel,
					0,
					-1,
					BuildingContainer->StaticGameplayTags
				);

				SelectMeshSetLootTier(BuildingContainer,  LootTier);
			}

			if (BuildingPersistentState == EFortBuildingPersistentState::Searched)
				BuildingContainer->SetSearchedContainer(nullptr);
		}

		FN_LOG(LogBuildingActor, Debug, "ABuildingContainer::PostUpdate() on existing container Container : % s, ContainerLootTierKey : % s, AltMeshIdx : % d",
			BuildingContainer->GetName().c_str(), BuildingContainer->ContainerLootTierKey.ToString().c_str(), BuildingContainer->AltMeshIdx);
	}

	void ABuildingSMActor_PostUpdate(ABuildingSMActor* BuildingSMActor)
	{
		EFortBuildingPersistentState PersistentState = EFortBuildingPersistentState::Default;
		FName LootTierKey = BuildingSMActor->DestructionLootTierKey;

		if (BuildingSMActor->DestructionLootTierKey.IsValid())
		{
			SelectMeshSetLootTierKey(BuildingSMActor, LootTierKey);
		}
		else
		{
			int32 LootTier = 0;
			int32 ChooseLootTier = 0;

			if (BuildingSMActor->DestructionLootTierGroup.IsValid())
			{
				LootTier = -1;

				if (BuildingSMActor->DestructionLootTierChosenQuotaInfo.LootTierKey.ComparisonIndex > 0 ||
					BuildingSMActor->DestructionLootTierChosenQuotaInfo.LootTierKey.Number > 0)
				{
					ChooseLootTier = BuildingSMActor->DestructionLootTierChosenQuotaInfo.LootTier;
					LootTierKey = BuildingSMActor->DestructionLootTierChosenQuotaInfo.LootTierKey;

					LootTier = ChooseLootTier;
				}
				else
				{
					int32 LootLevel = UFortKismetLibrary::GetLootLevel(BuildingSMActor);

					Loots::PickLootTierKeyAndLootTierFromTierGroup(
						&BuildingSMActor->DestructionLootTierKey,
						&LootTier,
						BuildingSMActor->DestructionLootTierGroup,
						LootLevel,
						0,
						-1,
						BuildingSMActor->StaticGameplayTags
					);

					ChooseLootTier = LootTier;
				}

				SelectMeshSetLootTier(BuildingSMActor, ChooseLootTier);

				if (!Loots::IsLootDropPossible(LootTierKey, L"ABuildingSMActor::AttemptSpawnResources", 0))
				{
					LootTierKey = FName(0);
					PersistentState = EFortBuildingPersistentState::Searched;
				}
			}
		}

		FN_LOG(LogBuildingSMActor, Debug, "ABuildingSMActor::PostUpdate() Building: %s, AltMeshIdx: %d", BuildingSMActor->GetName().c_str(), BuildingSMActor->AltMeshIdx);

		ABuildingSMActor_PostUpdateOG(BuildingSMActor);
	}

	void OnDamageServer(
		ABuildingActor* BuildingActor,
		float Damage,
		const FGameplayTagContainer& DamageTags,
		const FVector& Momentum,
		const FHitResult& HitInfo,
		AController* InstigatedBy,
		AActor* DamageCauser,
		const FGameplayEffectContextHandle& EffectContext
	)
	{
		OnDamageServerOG(
			BuildingActor,
			Damage,
			DamageTags,
			Momentum,
			HitInfo,
			InstigatedBy,
			DamageCauser,
			EffectContext);

		ABuildingSMActor* BuildingSMActor = Cast<ABuildingSMActor>(BuildingActor);
		AFortPlayerController* PlayerController = Cast<AFortPlayerController>(InstigatedBy);
		AFortWeapon* Weapon = Cast<AFortWeapon>(DamageCauser);

		if (!BuildingSMActor || !PlayerController || !Weapon)
			return;

		AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;

		if (!Weapon->WeaponData->IsA(UFortWeaponMeleeItemDefinition::StaticClass()) ||
			!BuildingSMActor->bAllowResourceDrop ||
			!PlayerPawn)
			return;

		UFortResourceItemDefinition* ResourceItemDefinition = UFortKismetLibrary::K2_GetResourceItemDefinition(BuildingSMActor->ResourceType);

		int32 ResourceDropAmount = 0;
		float ResourceRatio = 0.0f;

		if (ResourceItemDefinition)
		{
			if (BuildingSMActor->MaxResourcesToSpawn < 0)
				BuildingSMActor->MaxResourcesToSpawn = BuildingSMActor->DetermineMaxResourcesToSpawn();

			float MaxResourcesToSpawn = BuildingSMActor->MaxResourcesToSpawn;
			float MaxHealth = BuildingSMActor->GetMaxHealth();

			ResourceRatio = MaxResourcesToSpawn / MaxHealth;
			ResourceDropAmount = (int32)(ResourceRatio * Damage);
		}

		bool bHasHealthLeft = BuildingSMActor->HasHealthLeft();
		bool bDestroyed = false;

		if (!bHasHealthLeft)
		{
			bDestroyed = true;

			int32 MinResourceCount = 0;

			if (!ResourceItemDefinition || (MinResourceCount = 1, ResourceRatio == 0.0))
				MinResourceCount = 0;

			if (ResourceDropAmount < MinResourceCount)
				ResourceDropAmount = MinResourceCount;

			if (BuildingSMActor->DestructionLootTierKey.IsValid())
			{
				int32 LootLevel = UFortKismetLibrary::GetLootLevel(BuildingSMActor);

				TArray<FFortItemEntry> LootToDrops;
				Loots::PickLootDrops(&LootToDrops, LootLevel, BuildingSMActor->DestructionLootTierKey, 0, 0, BuildingSMActor->StaticGameplayTags, true, false);

				for (int32 i = 0; i < LootToDrops.Num(); i++)
				{
					FFortItemEntry LootToDrop = LootToDrops[i];

					UFortWorldItemDefinition* WorldItemDefinition = Cast<UFortWorldItemDefinition>(LootToDrop.ItemDefinition);

					if (!WorldItemDefinition)
					{
						FN_LOG(LogBuildingSMActor, Error, "Loot tier %s dropped entry with no item data!", BuildingSMActor->DestructionLootTierGroup.ToString().c_str());
						continue;
					}

					FFortItemEntry ItemEntry;
					Inventory::MakeItemEntry(&ItemEntry, WorldItemDefinition, LootToDrop.Count, LootToDrop.Level, LootToDrop.LoadedAmmo, LootToDrop.Durability);
					Inventory::SetStateValue(&ItemEntry, EFortItemEntryState::DoNotShowSpawnParticles, 1);
					Inventory::SetStateValue(&ItemEntry, EFortItemEntryState::ShouldShowItemToast, 1);
					Inventory::AddInventoryItem(PlayerController, ItemEntry);

					ItemEntry.FreeItemEntry();
				}
			}
		}

		if (ResourceDropAmount > 0)
		{
			FFortItemEntry ItemEntry;
			Inventory::MakeItemEntry(&ItemEntry, ResourceItemDefinition, ResourceDropAmount, 0, 0, 0.f);
			Inventory::SetStateValue(&ItemEntry, EFortItemEntryState::DoNotShowSpawnParticles, 1);
			Inventory::SetStateValue(&ItemEntry, EFortItemEntryState::ShouldShowItemToast, 1);
			Inventory::AddInventoryItem(PlayerController, ItemEntry);

			PlayerController->ClientReportDamagedResourceBuilding(BuildingSMActor, BuildingSMActor->ResourceType, ResourceDropAmount, bDestroyed, (Damage == 100.0f));

			ItemEntry.FreeItemEntry();
		}
	}

	void (*BP_SetAlreadySearchedOG)(ABuildingContainer* BuildingContainer, bool bInAlreadySearched);
	void BP_SetAlreadySearched(ABuildingContainer* BuildingContainer, bool bInAlreadySearched)
	{
		FN_LOG(LogInit, Log, "BP_SetAlreadySearched called!");

		// [ABuildingContainer::BP_SetAlreadySearched] successfully hooked with Offset [0x17f49e8], IdaAddress [00007FF697DC49E8]

		BP_SetAlreadySearchedOG(BuildingContainer, bInAlreadySearched);
	}

	void InitBuildingActor()
	{
		ABuildingContainer* BuildingContainerDefault = ABuildingContainer::GetDefaultObj();

		MinHook::HookVTable(BuildingContainerDefault, 0x8D8 / 8, ABuildingContainer_PostUpdate, (LPVOID*)(&ABuildingContainer_PostUpdateOG), "ABuildingContainer::PostUpdate");
		MinHook::HookVTable(BuildingContainerDefault, 0xF88 / 8, SpawnLoot, nullptr, "ABuildingContainer::SpawnLoot");

		// MinHook::HookVTable(BuildingContainerDefault, 0xF60 / 8, BP_SetAlreadySearched, (LPVOID*)(&BP_SetAlreadySearchedOG), "ABuildingContainer::BP_SetAlreadySearched");

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x61b0c28), ABuildingSMActor_PostUpdate, (LPVOID*)(&ABuildingSMActor_PostUpdateOG));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x61b0c28));

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x69e3008), OnDamageServer, (LPVOID*)(&OnDamageServerOG));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x69e3008));

		SelectMeshSetLootTier = decltype(SelectMeshSetLootTier)(0x19089c4 + uintptr_t(GetModuleHandle(0)));

		FN_LOG(LogInit, Log, "InitBuildingActor Success!");
	}
}