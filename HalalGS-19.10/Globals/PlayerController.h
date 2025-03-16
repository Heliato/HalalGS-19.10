#pragma once

namespace PlayerController
{
	void (*ClientOnPawnDiedOG)(AFortPlayerControllerZone* PlayerControllerZone, const FFortPlayerDeathReport& DeathReport);
	void (*ServerAttemptInteractOG)(UFortControllerComponent_Interaction* ControllerComponent_Interaction, AActor* ReceivingActor, UPrimitiveComponent* InteractComponent, ETInteractionType InteractType, UObject* OptionalObjectData, EInteractionBeingAttempted InteractionBeingAttempted, int32 RequestID);
	void (*ModLoadedAmmoOG)(void* InventoryOwner, const FGuid& ItemGuid, int32 NewLoadedAmmo);
	void (*ServerReadyToStartMatchOG)(AFortPlayerController* PlayerController);
	void (*ServerReturnToMainMenuOG)(AFortPlayerController* PlayerController);
	void (*GetPlayerViewPointOG)(APlayerController* PlayerController, FVector& out_Location, FRotator& out_Rotation);

	void ServerClientIsReadyToRespawn(AFortPlayerControllerAthena* PlayerControllerAthena)
	{
		AFortPlayerStateAthena* PlayerStateAthena = Cast<AFortPlayerStateAthena>(PlayerControllerAthena->PlayerState);
		AFortGameModeAthena* GameModeAthena = Globals::GetGameMode();

		if (!PlayerStateAthena || !GameModeAthena) 
			return;

		AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(GameModeAthena->GameState);
		if (!GameStateAthena) return;

		if (GameStateAthena->IsRespawningAllowed(PlayerStateAthena))
		{
			FFortRespawnData* RespawnData = &PlayerStateAthena->RespawnData;

			if (RespawnData->bServerIsReady && RespawnData->bRespawnDataAvailable)
			{
				const FVector& RespawnLocation = RespawnData->RespawnLocation;
				const FRotator& RespawnRotation = RespawnData->RespawnRotation;

				FTransform SpawnTransform = UKismetMathLibrary::MakeTransform(RespawnLocation, RespawnRotation, FVector({ 1, 1, 1 }));

				AFortPlayerPawn* PlayerPawn = Cast<AFortPlayerPawn>(GameModeAthena->SpawnDefaultPawnAtTransform(PlayerControllerAthena, SpawnTransform));

				if (!PlayerPawn)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerControllerAthena::ServerClientIsReadyToRespawn] Failed to spawn PlayerPawn!");
					return;
				}

				PlayerPawn->Owner = PlayerControllerAthena;
				PlayerPawn->OnRep_Owner();

				PlayerControllerAthena->Pawn = PlayerPawn;
				PlayerControllerAthena->OnRep_Pawn();
				PlayerControllerAthena->Possess(PlayerPawn);

				PlayerPawn->SetMaxHealth(100);
				PlayerPawn->SetHealth(100);
				PlayerPawn->SetMaxShield(100);
				PlayerPawn->SetShield(100);

				PlayerControllerAthena->SetControlRotation(RespawnRotation);

				RespawnData->bClientIsReady = true;
			}
		}
	}

	void ClientOnPawnDied(AFortPlayerControllerZone* PlayerControllerZone, const FFortPlayerDeathReport& DeathReport)
	{
		AFortPlayerPawnAthena* PlayerPawnAthena = Cast<AFortPlayerPawnAthena>(PlayerControllerZone->MyFortPawn);
		AFortPlayerStateAthena* PlayerStateAthena = Cast<AFortPlayerStateAthena>(PlayerControllerZone->PlayerState);

		if (!PlayerPawnAthena || !PlayerStateAthena)
			return;

		AFortGameModeAthena* GameModeAthena = Cast<AFortGameModeAthena>(Globals::GetGameMode());
		AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(GameModeAthena->GameState);

		if (!GameModeAthena || !GameStateAthena)
			return;

		AFortPlayerStateAthena* KillerPlayerState = Cast<AFortPlayerStateAthena>(DeathReport.KillerPlayerState);
		AFortPlayerPawnAthena* KillerPawn = Cast<AFortPlayerPawnAthena>(DeathReport.KillerPawn);
		AFortPlayerControllerAthena* KillerPlayerControllerAthena = (KillerPawn ? Cast<AFortPlayerControllerAthena>(KillerPawn->Controller) : nullptr);

		AActor* DamageCauser = DeathReport.DamageCauser;

		FGameplayTagContainer TagContainer = PlayerPawnAthena ? *(FGameplayTagContainer*)(__int64(PlayerPawnAthena) + 0x19E0) : FGameplayTagContainer();

		float Distance = KillerPawn ? KillerPawn->GetDistanceTo(PlayerPawnAthena) : 0;

		EDeathCause DeathCause = AFortPlayerStateAthena::ToDeathCause(TagContainer, PlayerPawnAthena->bIsDBNO);

		FDeathInfo& DeathInfo = PlayerStateAthena->DeathInfo;
		DeathInfo.FinisherOrDowner = KillerPlayerState ? KillerPlayerState : PlayerStateAthena;
		DeathInfo.bDBNO = PlayerPawnAthena->bIsDBNO;
		DeathInfo.DeathCause = DeathCause;
		DeathInfo.Distance = (DeathCause == EDeathCause::FallDamage) ? PlayerPawnAthena->LastFallDistance : Distance;
		DeathInfo.DeathLocation = PlayerPawnAthena->K2_GetActorLocation();
		DeathInfo.bInitialized = true;

		PlayerStateAthena->PawnDeathLocation = DeathInfo.DeathLocation;

		PlayerStateAthena->OnRep_DeathInfo();

		FN_LOG(LogPlayerController, Warning, "[AFortPlayerControllerZone::ClientOnPawnDied] Killer PlayerName: %s, Killed PlayerName: %s - Distance: %.2f", 
			KillerPlayerState->GetPlayerName().ToString().c_str(), PlayerStateAthena->GetPlayerName().ToString().c_str(), Distance);

		AFortPlayerControllerAthena* PlayerControllerAthena = Cast<AFortPlayerControllerAthena>(PlayerControllerZone);

		if (PlayerControllerAthena)
		{
			if (KillerPlayerState && PlayerStateAthena != KillerPlayerState)
			{
				KillerPlayerState->KillScore++;
				KillerPlayerState->OnRep_Kills();

				KillerPlayerState->ClientReportKill(PlayerStateAthena);

				for (int32 i = 0; i < GameStateAthena->Teams.Num(); i++)
				{
					AFortTeamInfo* TeamInfo = GameStateAthena->Teams[i];
					if (!TeamInfo) continue;

					if (TeamInfo->Team != KillerPlayerState->TeamIndex)
						continue;

					for (int32 j = 0; j < TeamInfo->TeamMembers.Num(); j++)
					{
						AFortPlayerControllerAthena* TeamMember = Cast<AFortPlayerControllerAthena>(TeamInfo->TeamMembers[j]);
						if (!TeamMember) continue;

						AFortPlayerStateAthena* TeamMemberPlayerState = Cast<AFortPlayerStateAthena>(TeamMember->PlayerState);
						if (!TeamMemberPlayerState) continue;

						TeamMemberPlayerState->TeamKillScore++;
						TeamMemberPlayerState->OnRep_TeamKillScore();

						TeamMemberPlayerState->ClientReportTeamKill(TeamMemberPlayerState->TeamKillScore);
					}
					break;
				}

#ifdef SIPHON
				AFortPlayerControllerAthena* KillerPlayerController = Cast<AFortPlayerControllerAthena>(KillerPlayerState->Owner);

				if (KillerPlayerController)
					Functions::GiveSiphonBonus(KillerPlayerController, KillerPawn);
#endif // SIPHON
			}

			if (!GameStateAthena->IsRespawningAllowed(PlayerStateAthena) && !PlayerPawnAthena->bIsDBNO)
			{
				AFortPlayerStateAthena* CorrectKillerPlayerState = (KillerPlayerState && KillerPlayerState == PlayerStateAthena) ? nullptr : KillerPlayerState;
				UFortWeaponItemDefinition* KillerWeaponItemDefinition = nullptr;

				if (DamageCauser)
				{
					AFortProjectileBase* ProjectileBase = Cast<AFortProjectileBase>(DamageCauser);
					AFortWeapon* Weapon = Cast<AFortWeapon>(DamageCauser);

					if (ProjectileBase)
					{
						AFortWeapon* ProjectileBaseWeapon = Cast<AFortWeapon>(ProjectileBase->Owner);

						if (ProjectileBaseWeapon)
							KillerWeaponItemDefinition = ProjectileBaseWeapon->WeaponData;
					}
					else if (Weapon)
						KillerWeaponItemDefinition = Weapon->WeaponData;
				}

				bool bMatchEnded = GameModeAthena->HasMatchEnded();

				GameModeAthena->RemoveFromAlivePlayers(PlayerControllerAthena, CorrectKillerPlayerState, KillerPawn, KillerWeaponItemDefinition, DeathCause);

				if (GameStateAthena->GamePhase > EAthenaGamePhase::Warmup)
				{
					auto SendMatchReport = [&](AFortPlayerControllerAthena* MatchPlayerControllerAthena) -> void
						{
							UAthenaPlayerMatchReport* PlayerMatchReport = MatchPlayerControllerAthena->MatchReport;
							AFortPlayerStateAthena* MatchPlayerStateAthena = Cast<AFortPlayerStateAthena>(MatchPlayerControllerAthena->PlayerState);

							if (PlayerMatchReport && MatchPlayerStateAthena)
							{
								if (PlayerMatchReport->bHasTeamStats)
								{
									FAthenaMatchTeamStats& TeamStats = PlayerMatchReport->TeamStats;
									TeamStats.Place = GameStateAthena->TeamsLeft;
									TeamStats.TotalPlayers = GameStateAthena->TotalPlayers;

									MatchPlayerControllerAthena->ClientSendTeamStatsForPlayer(TeamStats);
								}

								if (PlayerMatchReport->bHasMatchStats)
								{
									FAthenaMatchStats& MatchStats = PlayerMatchReport->MatchStats;
									//MatchStats

									MatchPlayerControllerAthena->ClientSendMatchStatsForPlayer(MatchStats);
								}

								if (PlayerMatchReport->bHasRewards)
								{
									FAthenaRewardResult& EndOfMatchResults = PlayerMatchReport->EndOfMatchResults;
									EndOfMatchResults.LevelsGained = 5;
									EndOfMatchResults.BookLevelsGained = 10;
									EndOfMatchResults.TotalSeasonXpGained = 15;
									EndOfMatchResults.TotalBookXpGained = 20;
									EndOfMatchResults.PrePenaltySeasonXpGained = 25;

									MatchPlayerControllerAthena->ClientSendEndBattleRoyaleMatchForPlayer(true, EndOfMatchResults);
								}

								MatchPlayerStateAthena->Place = GameStateAthena->TeamsLeft;
								MatchPlayerStateAthena->OnRep_Place();

								FN_LOG(LogPlayerController, Log, "SendMatchReport for Player: [%s], Place: [%i]", MatchPlayerStateAthena->GetPlayerName().ToString().c_str(), MatchPlayerStateAthena->Place);
							}
						};


					for (int32 i = 0; i < GameStateAthena->Teams.Num(); i++)
					{
						AFortTeamInfo* TeamInfo = GameStateAthena->Teams[i];
						if (!TeamInfo) continue;

						if (TeamInfo->Team != PlayerStateAthena->TeamIndex)
							continue;

						bool bIsTeamAlive = false;
						for (int32 j = 0; j < TeamInfo->TeamMembers.Num(); j++)
						{
							AFortPlayerControllerAthena* TeamMember = Cast<AFortPlayerControllerAthena>(TeamInfo->TeamMembers[j]);
							if (!TeamMember || (TeamMember == PlayerControllerAthena)) continue;

							AFortPlayerPawn* TeamMemberPlayerPawn = Cast<AFortPlayerPawn>(TeamMember->MyFortPawn);
							if (!TeamMemberPlayerPawn || TeamMemberPlayerPawn->bIsDying) continue;

							bIsTeamAlive = true;
							break;
						}

						if (!bIsTeamAlive)
						{
							for (int32 j = 0; j < TeamInfo->TeamMembers.Num(); j++)
							{
								AFortPlayerControllerAthena* TeamMember = Cast<AFortPlayerControllerAthena>(TeamInfo->TeamMembers[j]);
								if (!TeamMember) continue;

								SendMatchReport(TeamMember);
							}
						}

						FN_LOG(LogPlayerController, Log, "CheckIfTeamAliveForSendMatchReport bIsTeamAlive: [%i]", bIsTeamAlive);
						break;
					}

					if (GameStateAthena->TeamsLeft == 1 && KillerPlayerState && !bMatchEnded)
					{
						for (int32 i = 0; i < GameStateAthena->Teams.Num(); i++)
						{
							AFortTeamInfo* TeamInfo = GameStateAthena->Teams[i];
							if (!TeamInfo) continue;

							if (TeamInfo->Team != KillerPlayerState->TeamIndex)
								continue;

							for (int32 j = 0; j < TeamInfo->TeamMembers.Num(); j++)
							{
								AFortPlayerControllerAthena* TeamMember = Cast<AFortPlayerControllerAthena>(TeamInfo->TeamMembers[j]);
								if (!TeamMember) continue;

								AFortPlayerStateAthena* TeamMemberPlayerState = Cast<AFortPlayerStateAthena>(TeamMember->PlayerState);
								if (!TeamMemberPlayerState) continue;

								TeamMemberPlayerState->Place = GameStateAthena->TeamsLeft;
								TeamMemberPlayerState->OnRep_Place();

								TeamMember->ClientNotifyWon(KillerPawn, KillerWeaponItemDefinition, DeathCause);
								TeamMember->ClientNotifyTeamWon(KillerPawn, KillerWeaponItemDefinition, DeathCause);

								UAthenaGadgetItemDefinition* VictoryCrown = StaticFindObject<UAthenaGadgetItemDefinition>(L"/VictoryCrownsGameplay/Items/AGID_VictoryCrown.AGID_VictoryCrown");

								if (VictoryCrown)
								{
									int32 ItemQuantity = UFortKismetLibrary::K2_GetItemQuantityOnPlayer(TeamMember, VictoryCrown, FGuid());

									if (ItemQuantity <= 0)
										UFortKismetLibrary::K2_GiveItemToPlayer(TeamMember, VictoryCrown, FGuid(), 1, false);
								}

								SendMatchReport(TeamMember);
							}
							break;
						}
					}
				}
			}
		}

		ClientOnPawnDiedOG(PlayerControllerZone, DeathReport);
	}

	void ServerReadyToStartMatch(AFortPlayerController* PlayerController)
	{
		if (!PlayerController->bReadyToStartMatch)
		{
#ifdef CHEATS
			if (!PlayerController->CheatManager)
			{
				UCheatManager* CheatManager = Cast<UCheatManager>(UGameplayStatics::SpawnObject(UCheatManager::StaticClass(), PlayerController));

				if (CheatManager)
				{
					PlayerController->CheatManager = CheatManager;
					PlayerController->CheatManager->ReceiveInitCheatManager();
				}
			}
#endif // CHEATS

			AFortPlayerControllerAthena* PlayerControllerAthena = Cast<AFortPlayerControllerAthena>(PlayerController);

			if (PlayerControllerAthena)
			{
				if (!PlayerControllerAthena->MatchReport)
				{
					UAthenaPlayerMatchReport* NewMatchReport = Cast<UAthenaPlayerMatchReport>(UGameplayStatics::SpawnObject(UAthenaPlayerMatchReport::StaticClass(), PlayerControllerAthena));

					NewMatchReport->bHasMatchStats = true;
					NewMatchReport->bHasRewards = true;
					NewMatchReport->bHasTeamStats = true;

					PlayerControllerAthena->MatchReport = NewMatchReport;
				}

				if (!PlayerControllerAthena->MatchReport)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerReadyToStartMatch] Failed to spawn MatchReport for PlayerController: %s", PlayerControllerAthena->GetName().c_str());
				}
			}
		}

		ServerReadyToStartMatchOG(PlayerController);
	}

	void ServerAttemptInventoryDrop(AFortPlayerController* PlayerController, const FGuid& ItemGuid, int32 Count, bool bTrash)
	{
		if (Count < 1)
			return;

		AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;

		if (!PlayerPawn || PlayerPawn->bIsSkydiving || PlayerPawn->bIsDBNO)
			return;

		AFortPlayerControllerAthena* PlayerControllerAthena = Cast<AFortPlayerControllerAthena>(PlayerController);

		if (PlayerControllerAthena)
		{
			if (PlayerControllerAthena->IsInAircraft())
				return;
		}

		UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->BP_GetInventoryItemWithGuid(ItemGuid));

		if (!WorldItem)
			return;

		UFortWorldItemDefinition* WorldItemDefinition = Cast<UFortWorldItemDefinition>(WorldItem->ItemEntry.ItemDefinition);

		if (!WorldItemDefinition || !WorldItemDefinition->bCanBeDropped)
			return;

		if (WorldItem->ItemEntry.Count <= 0)
		{
			UFortWeaponRangedItemDefinition* WeaponRangedItemDefinition = Cast<UFortWeaponRangedItemDefinition>(WorldItemDefinition);

			if (WeaponRangedItemDefinition && WeaponRangedItemDefinition->bPersistInInventoryWhenFinalStackEmpty)
				return;

			FN_LOG(LogPlayerController, Warning, "[AFortPlayerController::ServerAttemptInventoryDrop] The item [%s] has a count of [%i] deletion of the item.", WorldItemDefinition->GetName().c_str(), WorldItem->ItemEntry.Count);

			PlayerController->RemoveInventoryItem(ItemGuid, Count, true, true);
			return;
		}

		if (PlayerController->RemoveInventoryItem(ItemGuid, Count, false, true))
		{
			static auto WID_Launcher_Petrol = StaticFindObject<UFortWeaponRangedItemDefinition>(L"/Game/Athena/Items/Weapons/Prototype/WID_Launcher_Petrol.WID_Launcher_Petrol");

			if (WorldItemDefinition == WID_Launcher_Petrol)
			{
				const FVector& SpawnLocation = PlayerPawn->K2_GetActorLocation();

				static auto BGA_Petrol_PickupClass = StaticFindObject<UBlueprintGeneratedClass>(L"/Game/Athena/Items/Weapons/Prototype/PetrolPump/BGA_Petrol_Pickup.BGA_Petrol_Pickup_C");
				AActor* PetrolPickup = PlayerController->GetWorld()->SpawnActor(BGA_Petrol_PickupClass, &SpawnLocation);

				if (PetrolPickup)
				{
					UFortItemEntryComponent* FortItemEntry = *(UFortItemEntryComponent**)(__int64(PetrolPickup) + 0xAB0);
					if (!FortItemEntry) return;

					FortItemEntry->SetOwnedItem(WorldItem->ItemEntry);
				}

				return;
			}

			const float LootSpawnLocationX = 0.0f;
			const float LootSpawnLocationY = 0.0f;
			const float LootSpawnLocationZ = 60.0f;

			const FVector& SpawnLocation = PlayerPawn->K2_GetActorLocation() +
				PlayerPawn->GetActorForwardVector() * LootSpawnLocationX +
				PlayerPawn->GetActorRightVector() * LootSpawnLocationY +
				PlayerPawn->GetActorUpVector() * LootSpawnLocationZ;

			FFortItemEntry NewItemEntry;

			if (WorldItem->ItemEntry.Count == Count)
			{
				NewItemEntry.CopyItemEntryWithReset(&WorldItem->ItemEntry);
				NewItemEntry.SetParentInventory(nullptr, false);

				FGuid (*sub_7FF69CAAD2C8)(FFortItemEntry* ItemEntry) = decltype(sub_7FF69CAAD2C8)(0x64dd2c8 + uintptr_t(GetModuleHandle(0)));
				sub_7FF69CAAD2C8(&NewItemEntry);

				NewItemEntry.ItemGuid.A = WorldItem->ItemEntry.ItemGuid.A;
				NewItemEntry.ItemGuid.B = WorldItem->ItemEntry.ItemGuid.B;
				NewItemEntry.ItemGuid.C = WorldItem->ItemEntry.ItemGuid.C;
				NewItemEntry.ItemGuid.D = WorldItem->ItemEntry.ItemGuid.D;
			}
			else if (Count < WorldItem->ItemEntry.Count)
			{
				Inventory::MakeItemEntry(
					&NewItemEntry,
					WorldItem->ItemEntry.ItemDefinition,
					Count,
					WorldItem->ItemEntry.Level,
					WorldItem->ItemEntry.LoadedAmmo,
					WorldItem->ItemEntry.Durability
				);
			}

			/*Inventory::MakeItemEntry(
				&NewItemEntry,
				WorldItem->ItemEntry.ItemDefinition,
				Count,
				WorldItem->ItemEntry.Level,
				WorldItem->ItemEntry.LoadedAmmo,
				WorldItem->ItemEntry.Durability
			);

			NewItemEntry.SetParentInventory(nullptr, false);

			FGuid(*sub_7FF69CAAD2C8)(FFortItemEntry* ItemEntry) = decltype(sub_7FF69CAAD2C8)(0x64dd2c8 + uintptr_t(GetModuleHandle(0)));
			sub_7FF69CAAD2C8(&NewItemEntry);*/

			Inventory::SetStateValue(&NewItemEntry, EFortItemEntryState::DurabilityInitialized, 1);
			Inventory::SetStateValue(&NewItemEntry, EFortItemEntryState::FromDroppedPickup, 1);

			TWeakObjectPtr<AFortPlayerController> WeakPlayerController{};
			WeakPlayerController.ObjectIndex = -1;
			WeakPlayerController.ObjectSerialNumber = 0;

			TWeakObjectPtr<AActor> WeakInvestigator{};
			WeakInvestigator.ObjectIndex = -1;
			WeakInvestigator.ObjectSerialNumber = 0;

			FFortCreatePickupData PickupData{};
			PickupData.World = PlayerController->GetWorld();
			PickupData.ItemEntry = NewItemEntry;
			PickupData.SpawnLocation = SpawnLocation;
			PickupData.SpawnRotation = FRotator();
			PickupData.WeakPlayerController = WeakPlayerController;
			PickupData.OverrideClass = nullptr;
			PickupData.WeakInvestigator = WeakInvestigator;
			PickupData.PickupSourceTypeFlags = EFortPickupSourceTypeFlag::Player;
			PickupData.PickupSpawnSource = EFortPickupSpawnSource::TossedByPlayer;
			PickupData.bRandomRotation = true;
			PickupData.BitPad_1DA_1 = false;

			EWorldItemDropBehavior DropBehavior = WorldItemDefinition->DropBehavior;

			if (DropBehavior != EWorldItemDropBehavior::DestroyOnDrop &&
				!WorldItemDefinition->bIgnoreRespawningForDroppingAsPickup)
			{
				AFortPickup* (*CreatePickupFromData)(FFortCreatePickupData* PickupData) = decltype(CreatePickupFromData)(0x64dd1b4 + uintptr_t(GetModuleHandle(0)));
				AFortPickup* Pickup = CreatePickupFromData(&PickupData);

				if (Pickup)
				{
					FRotator PlayerRotation = PlayerPawn->K2_GetActorRotation();
					PlayerRotation.Yaw += UKismetMathLibrary::RandomFloatInRange(-60.0f, 60.0f);

					float RandomDistance = UKismetMathLibrary::RandomFloatInRange(500.0f, 600.0f);
					FVector FinalDirection = UKismetMathLibrary::GetForwardVector(PlayerRotation);

					FVector FinalLocation = SpawnLocation + FinalDirection * RandomDistance;

					Pickup->PawnWhoDroppedPickup = PlayerPawn;
					Pickup->bCombinePickupsWhenTossCompletes = true;
					Pickup->TossPickup(FinalLocation, PlayerPawn, 0, true, true, EFortPickupSourceTypeFlag::Player, EFortPickupSpawnSource::TossedByPlayer);
				}
			}

			NewItemEntry.FreeItemEntry();
		}
	}

	void ServerCombineInventoryItems(AFortPlayerController* PlayerController, const FGuid& TargetItemGuid, const FGuid& SourceItemGuid)
	{
		UFortWorldItem* TargetWorldItem = Cast<UFortWorldItem>(PlayerController->BP_GetInventoryItemWithGuid(TargetItemGuid));
		UFortWorldItem* SourceWorldItem = Cast<UFortWorldItem>(PlayerController->BP_GetInventoryItemWithGuid(SourceItemGuid));

		if (!TargetWorldItem || !SourceWorldItem)
			return;

		UFortWorldItemDefinition* TargetItemDefinition = Cast<UFortWorldItemDefinition>(TargetWorldItem->ItemEntry.ItemDefinition);
		UFortWorldItemDefinition* SourceItemDefinition = Cast<UFortWorldItemDefinition>(SourceWorldItem->ItemEntry.ItemDefinition);

		if (!TargetItemDefinition || !SourceItemDefinition)
			return;

		int32 MaxStackSize = TargetItemDefinition->MaxStackSize.GetValueAtLevel(0);

		if (TargetItemDefinition == SourceItemDefinition && TargetWorldItem->ItemEntry.Count < MaxStackSize)
		{
			int32 NewTargetCount = TargetWorldItem->ItemEntry.Count + SourceWorldItem->ItemEntry.Count;

			if (NewTargetCount > MaxStackSize)
			{
				int32 NewSourceCount = NewTargetCount - MaxStackSize;

				Inventory::ModifyCountItem(PlayerController->WorldInventory, SourceWorldItem->ItemEntry.ItemGuid, NewSourceCount);

				NewTargetCount = MaxStackSize;
			}
			else
			{
				Inventory::RemoveItem(PlayerController->WorldInventory, SourceWorldItem->ItemEntry.ItemGuid);
			}

			Inventory::ModifyCountItem(PlayerController->WorldInventory, TargetWorldItem->ItemEntry.ItemGuid, NewTargetCount);
		}
	}

	bool CheckCreateBuildingActor(AFortPlayerController* PlayerController, FBuildingClassData& BuildingClassData)
	{
		UClass* BuildingClass = BuildingClassData.BuildingClass.Get();

		if (!BuildingClass)
		{
			AFortPlayerControllerAthena* PlayerControllerAthena = Cast<AFortPlayerControllerAthena>(PlayerController);

			if (PlayerControllerAthena)
			{
				TSubclassOf<ABuildingActor> SubBuildingClass{};
				SubBuildingClass.ClassPtr = PlayerControllerAthena->BroadcastRemoteClientInfo->RemoteBuildableClass;

				BuildingClassData.BuildingClass = SubBuildingClass;
				BuildingClass = BuildingClassData.BuildingClass;
			}
		}

		AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;

		if (!PlayerPawn || PlayerPawn->bIsDBNO)
			return false;

		UObject* BuildingClassDefault = BuildingClass->CreateDefaultObject();

		if (!BuildingClassDefault->IsA(ABuildingActor::StaticClass()))
			return false;

		if (!Functions::IsPlayerBuildableClasse(BuildingClass))
			return false;

		return true;
	}

	void ServerCreateBuildingActor(AFortPlayerController* PlayerController, FCreateBuildingActorData& CreateBuildingData)
	{
		UWorld* World = PlayerController->GetWorld();

		if (!CheckCreateBuildingActor(PlayerController, CreateBuildingData.BuildingClassData) || !World)
			return;

		TArray<ABuildingActor*> ExistingBuildings;
		EFortBuildPreviewMarkerOptionalAdjustment MarkerOptionalAdjustment;
		EFortStructuralGridQueryResults GridQueryResults = PlayerController->CanPlaceBuilableClassInStructuralGrid(CreateBuildingData.BuildingClassData.BuildingClass, CreateBuildingData.BuildLoc, CreateBuildingData.BuildRot, CreateBuildingData.bMirrored, &ExistingBuildings, &MarkerOptionalAdjustment);

		if (GridQueryResults == EFortStructuralGridQueryResults::CanAdd)
		{
			for (int32 i = 0; i < ExistingBuildings.Num(); i++)
			{
				ABuildingActor* ExistingBuilding = ExistingBuildings[i];
				if (!ExistingBuilding) continue;

				ExistingBuilding->K2_DestroyActor();
			}

			ABuildingSMActor* BuildingSMActor = Cast<ABuildingSMActor>(World->SpawnActor(CreateBuildingData.BuildingClassData.BuildingClass, &CreateBuildingData.BuildLoc, &CreateBuildingData.BuildRot));
			if (!BuildingSMActor) return;

			BuildingSMActor->CurrentBuildingLevel = CreateBuildingData.BuildingClassData.UpgradeLevel;

			PlayerController->PayBuildingCosts(CreateBuildingData.BuildingClassData);

			BuildingSMActor->InitializeKismetSpawnedBuildingActor(BuildingSMActor, PlayerController, true, nullptr);
			BuildingSMActor->bPlayerPlaced = true;

			AFortPlayerStateAthena* PlayerStateAthena = Cast<AFortPlayerStateAthena>(PlayerController->PlayerState);

			if (PlayerStateAthena)
			{
				BuildingSMActor->PlacedByPlayer(PlayerStateAthena);

				BuildingSMActor->SetTeam(PlayerStateAthena->TeamIndex);
				BuildingSMActor->OnRep_Team();
			}
		}

		if (ExistingBuildings.IsValid())
			ExistingBuildings.Free();
	}

	void ServerRepairBuildingActor(AFortPlayerController* PlayerController, ABuildingSMActor* BuildingActorToRepair)
	{
		if (!BuildingActorToRepair ||
			!BuildingActorToRepair->GetWorld())
			return;

		int32 RepairCosts = PlayerController->PayRepairCosts(BuildingActorToRepair);
		BuildingActorToRepair->RepairBuilding(PlayerController, RepairCosts);
	}

	void ServerBeginEditingBuildingActor(AFortPlayerController* PlayerController, ABuildingSMActor* BuildingActorToEdit)
	{
		if (!BuildingActorToEdit)
			return;

		AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;
		if (!PlayerPawn) return;

		if (BuildingActorToEdit->CheckBeginEditBuildingActor(PlayerController))
		{
			AFortPlayerStateZone* PlayerStateZone = Cast<AFortPlayerStateZone>(PlayerController->PlayerState);
			if (!PlayerStateZone) return;

			BuildingActorToEdit->SetEditingPlayer(PlayerStateZone);

			UFortGameData* GameData = Globals::GetGameData();
			UFortEditToolItemDefinition* EditToolItemDefinition = GameData->EditToolItem.Get();

			if (!EditToolItemDefinition)
			{
				const FString& AssetPathName = UKismetStringLibrary::Conv_NameToString(GameData->EditToolItem.ObjectID.AssetPathName);
				EditToolItemDefinition = StaticLoadObject<UFortEditToolItemDefinition>(AssetPathName.CStr());
			}

			UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->BP_FindExistingItemForDefinition(EditToolItemDefinition, FGuid(), false));

			if (WorldItem &&
				EditToolItemDefinition)
			{
				EditToolItemDefinition->EquipWeaponDefinition(WorldItem, PlayerController);
			}
		}
	}

	void ServerEditBuildingActor(AFortPlayerController* PlayerController, ABuildingSMActor* BuildingActorToEdit, TSubclassOf<ABuildingSMActor> NewBuildingClass, uint8 RotationIterations, bool bMirrored)
	{
		if (!BuildingActorToEdit ||
			!BuildingActorToEdit->GetWorld() ||
			BuildingActorToEdit->EditingPlayer != PlayerController->PlayerState ||
			BuildingActorToEdit->bDestroyed)
			return;

		if (!Functions::IsPlayerBuildableClasse(NewBuildingClass.Get()))
			return;

		BuildingActorToEdit->SetEditingPlayer(nullptr);

		int32 CurrentBuildingLevel = BuildingActorToEdit->CurrentBuildingLevel;
		BuildingActorToEdit->ReplaceBuildingActor(NewBuildingClass, CurrentBuildingLevel, RotationIterations, bMirrored, PlayerController);
	}

	void ServerEndEditingBuildingActor(AFortPlayerController* PlayerController, ABuildingSMActor* BuildingActorToStopEditing)
	{
		if (!BuildingActorToStopEditing)
			return;

		AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;
		if (!PlayerPawn) return;

		if (BuildingActorToStopEditing->EditingPlayer != PlayerController->PlayerState ||
			BuildingActorToStopEditing->bDestroyed)
			return;

		BuildingActorToStopEditing->SetEditingPlayer(nullptr);
	}

	void ServerExecuteInventoryItem(AFortPlayerController* PlayerController, const FGuid& ItemGuid)
	{
		AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;

		if (!PlayerPawn || PlayerPawn->bIsDBNO)
			return;

		UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->BP_GetInventoryItemWithGuid(ItemGuid));
		if (!WorldItem) return;

		UFortWorldItemDefinition* WorldItemDefinition = Cast<UFortWorldItemDefinition>(WorldItem->ItemEntry.ItemDefinition);
		if (!WorldItemDefinition) return;

		UFortGadgetItemDefinition* GadgetItemDefinition = Cast<UFortGadgetItemDefinition>(WorldItemDefinition);

		if (GadgetItemDefinition)
		{
			WorldItemDefinition = GadgetItemDefinition->GetWeaponItemDefinition();
		}

		UFortWeaponItemDefinition* WeaponItemDefinition = Cast<UFortWeaponItemDefinition>(WorldItemDefinition);
		if (!WeaponItemDefinition) return;

		UFortDecoItemDefinition* DecoItemDefinition = Cast<UFortDecoItemDefinition>(WorldItemDefinition);

		if (DecoItemDefinition)
		{
			DecoItemDefinition->EquipDecoDefinition(WorldItem, PlayerController);

			UFortContextTrapItemDefinition* ContextTrapItemDefinition = Cast<UFortContextTrapItemDefinition>(DecoItemDefinition);

			if (ContextTrapItemDefinition)
			{
				ContextTrapItemDefinition->EquipContextTrapDefinition(WorldItem, PlayerController);
			}

			return;
		}

		WeaponItemDefinition->EquipWeaponDefinition(WorldItem, PlayerController);
	}

	void ServerDropAllItems(AFortPlayerController* PlayerController, const UFortItemDefinition* IgnoreItemDef)
	{
		AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;
		AFortInventory* WorldInventory = PlayerController->WorldInventory;

		if (!PlayerPawn || !WorldInventory)
			return;

		TArray<UFortWorldItem*> WorldItemToDrops;

		for (int32 i = 0; i < PlayerController->WorldInventory->Inventory.ItemInstances.Num(); i++)
		{
			UFortWorldItem* WorldItem = PlayerController->WorldInventory->Inventory.ItemInstances[i];
			if (!WorldItem) continue;

			FFortItemEntry* ItemEntry = &WorldItem->ItemEntry;
			if (!ItemEntry) continue;

			UFortWorldItemDefinition* ItemDefinition = Cast<UFortWorldItemDefinition>(ItemEntry->ItemDefinition);
			if (!ItemDefinition) continue;

			if (!ItemDefinition->bCanBeDropped || ItemDefinition == IgnoreItemDef)
				continue;

			WorldItemToDrops.Add(WorldItem);
		}

		const float LootSpawnLocationX = 0.0f;
		const float LootSpawnLocationY = 0.0f;
		const float LootSpawnLocationZ = 70.0f;

		const FVector& SpawnLocation = PlayerPawn->K2_GetActorLocation() +
			PlayerPawn->GetActorForwardVector() * LootSpawnLocationX +
			PlayerPawn->GetActorRightVector() * LootSpawnLocationY +
			PlayerPawn->GetActorUpVector() * LootSpawnLocationZ;

		for (int32 i = 0; i < WorldItemToDrops.Num(); i++)
		{
			UFortWorldItem* WorldItemToDrop = WorldItemToDrops[i];
			if (!WorldItemToDrop) continue;

			FVector FinalLocation = SpawnLocation;
			FVector RandomDirection = UKismetMathLibrary::RandomUnitVector();

			FinalLocation.X += RandomDirection.X * 700.0f;
			FinalLocation.Y += RandomDirection.Y * 700.0f;

			FFortItemEntry NewItemEntry;
			NewItemEntry.CopyItemEntryWithReset(&WorldItemToDrop->ItemEntry);

			if (PlayerController->RemoveInventoryItem(WorldItemToDrop->ItemEntry.ItemGuid, WorldItemToDrop->ItemEntry.Count, true, true))
			{
				TWeakObjectPtr<AFortPlayerController> WeakPlayerController{};
				WeakPlayerController.ObjectIndex = -1;
				WeakPlayerController.ObjectSerialNumber = 0;

				TWeakObjectPtr<AActor> WeakInvestigator{};
				WeakInvestigator.ObjectIndex = -1;
				WeakInvestigator.ObjectSerialNumber = 0;

				FFortCreatePickupData PickupData{};
				PickupData.World = PlayerController->GetWorld();
				PickupData.ItemEntry = NewItemEntry;
				PickupData.SpawnLocation = SpawnLocation;
				PickupData.SpawnRotation = FRotator();
				PickupData.WeakPlayerController = WeakPlayerController;
				PickupData.OverrideClass = nullptr;
				PickupData.WeakInvestigator = WeakInvestigator;
				PickupData.PickupSourceTypeFlags = EFortPickupSourceTypeFlag::Player;
				PickupData.PickupSpawnSource = EFortPickupSpawnSource::PlayerElimination;
				PickupData.bRandomRotation = true;
				PickupData.BitPad_1DA_1 = false;

				AFortPickup* (*CreatePickupFromData)(FFortCreatePickupData* PickupData) = decltype(CreatePickupFromData)(0x64dd1b4 + uintptr_t(GetModuleHandle(0)));
				AFortPickup* Pickup = CreatePickupFromData(&PickupData);

				if (Pickup)
				{
					Pickup->PawnWhoDroppedPickup = PlayerPawn;
					Pickup->bCombinePickupsWhenTossCompletes = true;
					Pickup->TossPickup(FinalLocation, PlayerPawn, 0, true, true, EFortPickupSourceTypeFlag::Player, EFortPickupSpawnSource::PlayerElimination);
				}
			}

			NewItemEntry.FreeItemEntry();
		}

		if (WorldItemToDrops.IsValid())
			WorldItemToDrops.Free();
	}

	void ServerPlayEmoteItem(AFortPlayerController* PlayerController, UFortMontageItemDefinitionBase* EmoteAsset, float EmoteRandomNumber)
	{
		if (!EmoteAsset)
			return;

		AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;

		if (!PlayerPawn || PlayerPawn->bIsSkydiving || PlayerPawn->bIsDBNO)
			return;

		UFortAbilitySystemComponent* AbilitySystemComponent = PlayerPawn->AbilitySystemComponent;
		if (!AbilitySystemComponent) return;

		UFortGameplayAbility* GameplayAbility = nullptr;

		if (EmoteAsset->IsA(UAthenaSprayItemDefinition::StaticClass()))
		{
			UGameDataCosmetics* GameDataCosmetics = Globals::GetGameDataCosmetics();
			UFortGameplayAbility* SprayGameplayAbility = Functions::LoadGameplayAbility(GameDataCosmetics->SprayGameplayAbility);
			GameplayAbility = SprayGameplayAbility;
		}
		else if (EmoteAsset->IsA(UAthenaToyItemDefinition::StaticClass()))
		{
			UAthenaToyItemDefinition* ToyItemDefinition = Cast<UAthenaToyItemDefinition>(EmoteAsset);

			if (ToyItemDefinition)
			{
				UFortGameplayAbility* ToySpawnAbility = Functions::LoadGameplayAbility(ToyItemDefinition->ToySpawnAbility);
				GameplayAbility = ToySpawnAbility;

				UClass* ToyActorClass = Functions::LoadClass(ToyItemDefinition->ToyActorClass);

				if (ToyActorClass)
				{
					for (int32 i = 0; i < PlayerController->ActiveToyInstances.Num(); i++)
					{
						ABuildingGameplayActor* ActiveToyInstance = Cast<ABuildingGameplayActor>(PlayerController->ActiveToyInstances[i]);
						if (!ActiveToyInstance) continue;

						if (ActiveToyInstance->bActorIsBeingDestroyed)
							continue;

						if (ActiveToyInstance->IsA(ToyActorClass))
						{
							PlayerController->ActiveToyInstances.Remove(i);
							ActiveToyInstance->FlushNetDormancy();
							ActiveToyInstance->ForceNetUpdate();
							ActiveToyInstance->SilentDie(false);
							ActiveToyInstance->K2_DestroyActor();
						}
					}
				}
			}
		}

		if (!GameplayAbility && EmoteAsset->IsA(UAthenaDanceItemDefinition::StaticClass()))
		{
			UGameDataCosmetics* GameDataCosmetics = Globals::GetGameDataCosmetics();
			UFortGameplayAbility* EmoteGameplayAbility = Functions::LoadGameplayAbility(GameDataCosmetics->EmoteGameplayAbility);
			GameplayAbility = EmoteGameplayAbility;
		}

		if (GameplayAbility)
		{
			UAthenaDanceItemDefinition* DanceItemDefinition = Cast<UAthenaDanceItemDefinition>(EmoteAsset);

			if (DanceItemDefinition)
			{
				PlayerPawn->bEmoteUsesSecondaryFire = DanceItemDefinition->bUsesSecondaryFireInput;
				PlayerPawn->bMovingEmote = DanceItemDefinition->bMovingEmote;
				PlayerPawn->bMovingEmoteSkipLandingFX = DanceItemDefinition->bMovingEmoteSkipLandingFX;
				PlayerPawn->bMovingEmoteForwardOnly = DanceItemDefinition->bMoveForwardOnly;
				PlayerPawn->bMovingEmoteFollowingOnly = DanceItemDefinition->bMoveFollowingOnly;
				PlayerPawn->EmoteWalkSpeed = DanceItemDefinition->WalkForwardSpeed;

				PlayerPawn->GroupEmoteSyncValue = DanceItemDefinition->bGroupAnimationSync;
				PlayerPawn->OnRep_GroupEmoteSyncValue();

				PlayerPawn->GroupEmoteAnimOffset = DanceItemDefinition->GroupSyncAnimOffset;
				PlayerPawn->GroupEmoteLeaderRotationYawOffset = DanceItemDefinition->GroupEmoteLeaderRotationYawOffset;

				PlayerPawn->bLockGroupEmoteLeaderRotation = DanceItemDefinition->bLockGroupEmoteLeaderRotation;
				PlayerPawn->OnRep_LockGroupEmoteLeaderRotation();
			}

			FGameplayAbilitySpec AbilitySpec;
			AbilitySpec.CreateDefaultAbilitySpec(GameplayAbility, GameplayAbility->GetAbilityLevel(), -1, EmoteAsset);

			FGameplayAbilitySpecHandle Handle;
			AbilitySystemComponent->GiveAbilityAndActivateOnce(&Handle, AbilitySpec, nullptr);
		}
	}

	void ServerReturnToMainMenu(AFortPlayerController* PlayerController)
	{
		if (!PlayerController)
			return;

		if (PlayerController->Pawn)
			PlayerController->ServerSuicide();

		PlayerController->ClientTravel(L"/Game/Maps/Frontend", ETravelType::TRAVEL_Absolute, false, FGuid());

		ServerReturnToMainMenuOG(PlayerController);
	}

	void ServerSuicide(AFortPlayerController* PlayerController)
	{
		AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;
		if (!PlayerPawn) return;

		PlayerPawn->ForceKill(FGameplayTag(), PlayerController, nullptr);
	}

	void ServerAttemptAircraftJump(UFortControllerComponent_Aircraft* ControllerComponent_Aircraft, const FRotator& ClientRotation)
	{
		if (!ControllerComponent_Aircraft)
			return;

		AFortPlayerControllerAthena* PlayerControllerAthena = Cast<AFortPlayerControllerAthena>(ControllerComponent_Aircraft->GetOwner());
		if (!PlayerControllerAthena) return;

		AFortPlayerStateAthena* PlayerStateAthena = Cast<AFortPlayerStateAthena>(PlayerControllerAthena->PlayerState);
		if (!PlayerStateAthena) return;

		UWorld* World = PlayerControllerAthena->GetWorld();
		if (!World) return;

		AGameModeBase* GameModeBase = World->AuthorityGameMode;
		AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(World->GameState);

		if (!GameModeBase || !GameStateAthena)
			return;

		if (PlayerControllerAthena->IsInAircraft() && !PlayerControllerAthena->Pawn)
		{
			int32 AircraftIndex = GameStateAthena->GetAircraftIndex(PlayerControllerAthena->PlayerState);
			AFortAthenaAircraft* AthenaAircraft = GameStateAthena->GetAircraft(AircraftIndex);

			if (AthenaAircraft)
			{
				AFortPlayerPawn* PlayerPawn = Cast<AFortPlayerPawn>(GameModeBase->SpawnDefaultPawnFor(PlayerControllerAthena, AthenaAircraft));
				if (!PlayerPawn) return;

				PlayerPawn->Owner = PlayerControllerAthena;
				PlayerPawn->OnRep_Owner();

				PlayerControllerAthena->Pawn = PlayerPawn;
				PlayerControllerAthena->OnRep_Pawn();
				PlayerControllerAthena->Possess(PlayerPawn);

				PlayerPawn->SetMaxHealth(100);
				PlayerPawn->SetHealth(100);
				PlayerPawn->SetMaxShield(100);
				PlayerPawn->SetShield(0);
				
				FActiveGameplayEffect;

				/*UFortAbilitySystemComponent* AbilitySystemComponent = PlayerStateAthena->AbilitySystemComponent;

				if (AbilitySystemComponent)
				{
					for (int32 i = 0; i < AbilitySystemComponent->ActiveGameplayEffects.GameplayEffects_Internal.Num(); i++)
					{
						FActiveGameplayEffect ActiveGameplayEffect = AbilitySystemComponent->ActiveGameplayEffects.GameplayEffects_Internal[i];
						if (!ActiveGameplayEffect.Spec.Def) continue;

						if (ActiveGameplayEffect.Spec.Def->IsA(UGE_OutsideSafeZoneDamage_C::StaticClass()))
							AbilitySystemComponent->RemoveActiveGameplayEffect(ActiveGameplayEffect.Handle, 1);
					}
				}*/

				PlayerControllerAthena->SetControlRotation(ClientRotation);
			}
		}
	}

	void ServerAttemptInteract(UFortControllerComponent_Interaction* ControllerComponent_Interaction, AActor* ReceivingActor, UPrimitiveComponent* InteractComponent, ETInteractionType InteractType, UObject* OptionalObjectData, EInteractionBeingAttempted InteractionBeingAttempted, int32 RequestID)
	{
		if (!ControllerComponent_Interaction)
			return;

		ServerAttemptInteractOG(ControllerComponent_Interaction, ReceivingActor, InteractComponent, InteractType, OptionalObjectData, InteractionBeingAttempted, RequestID);

		AFortPlayerControllerAthena* PlayerControllerAthena = Cast<AFortPlayerControllerAthena>(ControllerComponent_Interaction->GetOwner());

		if (!PlayerControllerAthena) 
			return;

		if (PlayerControllerAthena->MyFortPawn && PlayerControllerAthena->MyFortPawn->IsInVehicle())
		{
			UFortVehicleSeatWeaponComponent* VehicleSeatWeaponComponent = *(UFortVehicleSeatWeaponComponent**)(__int64(ReceivingActor) + 0x1930);

			if (VehicleSeatWeaponComponent)
			{
				auto Vehicle = PlayerControllerAthena->MyFortPawn->GetVehicle();

				auto SeatIdx = PlayerControllerAthena->MyFortPawn->GetVehicleSeatIndex();
				auto WeaponComp = Vehicle->GetSeatWeaponComponent(SeatIdx);

				UFortKismetLibrary::K2_GiveItemToPlayer(PlayerControllerAthena, WeaponComp->WeaponSeatDefinitions[SeatIdx].VehicleWeapon, FGuid(), 9999, false);

				for (size_t i = 0; i < PlayerControllerAthena->WorldInventory->Inventory.ReplicatedEntries.Num(); i++)
				{
					if (PlayerControllerAthena->WorldInventory->Inventory.ReplicatedEntries[i].ItemDefinition == WeaponComp->WeaponSeatDefinitions[SeatIdx].VehicleWeapon)
					{
						PlayerControllerAthena->SwappingItemDefinition = PlayerControllerAthena->MyFortPawn->CurrentWeapon->WeaponData;
						PlayerControllerAthena->ServerExecuteInventoryItem(PlayerControllerAthena->WorldInventory->Inventory.ReplicatedEntries[i].ItemGuid);

						auto VehicleWeapon = Cast<AFortWeaponRangedForVehicle>(PlayerControllerAthena->MyFortPawn->CurrentWeapon);

						if (!Vehicle) 
							return;

						FMountedWeaponInfo MountedWeaponInfo{};
						MountedWeaponInfo.bTargetSourceFromVehicleMuzzle = true;
						MountedWeaponInfo.bNeedsVehicleAttachment = true;

						FMountedWeaponInfoRepped MountedWeaponInfoRepped{};
						MountedWeaponInfoRepped.HostVehicleCachedActor = Vehicle;
						MountedWeaponInfoRepped.HostVehicleSeatIndexCached = SeatIdx;

						VehicleWeapon->MountedWeaponInfo = MountedWeaponInfo;
						VehicleWeapon->MountedWeaponInfoRepped = MountedWeaponInfoRepped;

						VehicleWeapon->OnRep_MountedWeaponInfoRepped();
						VehicleWeapon->OnHostVehicleSetup();
						break;
					}
				}
			}

			/*for (UStruct* TempStruct = ReceivingActor->Class; TempStruct; TempStruct = TempStruct->Super)
			{
				FProperty* ChildProperties = static_cast<FProperty*>(TempStruct->ChildProperties);
				if (!ChildProperties) continue;

				while (ChildProperties)
				{
					FN_LOG(LogInit, Log, "ChildProperties->Name: %s, Offset: 0x%llx", ChildProperties->Name.ToString().c_str(), (unsigned long long)ChildProperties->Offset);

					ChildProperties = (FProperty*)ChildProperties->Next;
				}
			}*/
		}

		ABuildingActor* BuildingActor = Cast<ABuildingActor>(ReceivingActor);

		if (BuildingActor)
		{
			/*
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: UberGraphFrame, Offset: 0x1910
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: ImminentCollisionComponent, Offset: 0x1918
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: FuelComponent, Offset: 0x1920
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: Snow Landscape Interaction System, Offset: 0x1928
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: FortVehicleSeatWeapon, Offset: 0x1930
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: MeatballCollisionBody, Offset: 0x1938
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: FortCollisionAudioHitPlayer, Offset: 0x1940
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: P_Meatball_Muzzle_Flash, Offset: 0x1948
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: P_Meatball_Boost_Ready, Offset: 0x1950
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: P_Meatball_Boost_Ready1, Offset: 0x1958
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: Dirt_Cascade, Offset: 0x1960
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: AudioController, Offset: 0x1968
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: P_Boost_R, Offset: 0x1970
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: P_Boost_L, Offset: 0x1978
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: P_BoostEnd_R, Offset: 0x1980
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: P_BoostEnd_L, Offset: 0x1988
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: OverlapVolume, Offset: 0x1990
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: Timeline_0_NewTrack_0_7906805348581A63C02104AD8E4AFD45, Offset: 0x1998
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: Timeline_0__Direction_7906805348581A63C02104AD8E4AFD45, Offset: 0x199c
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: Timeline_0, Offset: 0x19a0
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: BoostTimeline_Rumble_FA04381447AE3F527025F494D33449BD, Offset: 0x19a8
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: BoostTimeline_FoV_FA04381447AE3F527025F494D33449BD, Offset: 0x19ac
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: BoostTimeline__Direction_FA04381447AE3F527025F494D33449BD, Offset: 0x19b0
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: BoostTimeline, Offset: 0x19b8
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: LocalPlayerPawn, Offset: 0x19c0
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: DriverPawn, Offset: 0x19c8
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: DrivingPlayerController_0, Offset: 0x19d0
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: LastHitPlayer, Offset: 0x19d8
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: PassengerPawn, Offset: 0x19e0
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: PassengerPlayerController, Offset: 0x19e8
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: PassengerPawns, Offset: 0x19f0
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: HitPickaxePawn, Offset: 0x1a00
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: SpecialHonk, Offset: 0x1a08
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: SpecialHonkTimer, Offset: 0x1a10
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnDeathSound, Offset: 0x1a18
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: DamagedEffect, Offset: 0x1a20
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: AudioSpark, Offset: 0x1a28
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: InWaterFX, Offset: 0x1a30
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: InWaterLoop, Offset: 0x1a38
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: WaterEnterSound, Offset: 0x1a40
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: InWaterLoopSound, Offset: 0x1a48
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: CheckWaterTimer, Offset: 0x1a50
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: WaterSplashBurstFX, Offset: 0x1a58
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: InWaterLoopingFX, Offset: 0x1a60
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: VehicleDestroyedFX, Offset: 0x1a68
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: SavedDamageForMID, Offset: 0x1a70
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: BodyMID, Offset: 0x1a78
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: RumbleIntensity, Offset: 0x1a80
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: DriverCameraShake_0, Offset: 0x1a88
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: PassengerCameraShake, Offset: 0x1a90
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: Driver_CameraShake, Offset: 0x1a98
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: Passenger_CameraShake, Offset: 0x1aa0
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: VehicleMaxSpeed_DESIGNTIME, Offset: 0x1aa8
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: MinForwardSpeedForSideWake, Offset: 0x1aac
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: Turn Bias, Offset: 0x1ab0
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnBoostEndSound, Offset: 0x1ab8
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: BoostSound, Offset: 0x1ac0
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: BoostFailedSound, Offset: 0x1ac8
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: SmallJoltCameraShake, Offset: 0x1ad0
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: WaterImpactCameraShake, Offset: 0x1ad8
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: MinImpactToShake, Offset: 0x1ae0
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: CameraShakeWaterImpact, Offset: 0x1ae8
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: InAirSmoothed, Offset: 0x1af0
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: SmoothedSpringCompression, Offset: 0x1af4
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: ScreenShakeFrequencyMin, Offset: 0x1af8
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: ScreenShakeYawFrequencyMultipier, Offset: 0x1afc
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: PassengerCameraShakeMultiplier, Offset: 0x1b00
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: Current_MaxSpringCompression, Offset: 0x1b04
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: SpringFudgeValue, Offset: 0x1b08
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: NormalizedSpeed, Offset: 0x1b0c
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: CameraShakeSpeedCurvePow, Offset: 0x1b10
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: AmplitudeMin, Offset: 0x1b14
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: AmplitudeMax, Offset: 0x1b18
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: BoostingCameraShake, Offset: 0x1b1c
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: FluidSimBP, Offset: 0x1b20
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: WaterForceSettings, Offset: 0x1b28
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: BoostCameraActive, Offset: 0x1b98
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: BoostRumbleIntensity, Offset: 0x1b9c
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: MaxBoostFOV, Offset: 0x1ba0
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: DriverGE, Offset: 0x1ba8
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: PassengerGE, Offset: 0x1bb0
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: IsLegendary, Offset: 0x1bb8
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: GC_VehicleScreenDrips, Offset: 0x1bbc
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: WaterEntryMaxMagnitude, Offset: 0x1bc4
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: Forward_Intensity, Offset: 0x1bc8
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: Right_Intensity, Offset: 0x1bcc
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: CurrentLazyUpdateVector, Offset: 0x1bd0
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: BoostSoundWrapPriority, Offset: 0x1bdc
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: NormalizedForwardSpeedKmh, Offset: 0x1be0
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: EngineOnSound, Offset: 0x1be8
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: EngineOffSound, Offset: 0x1bf0
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: IsInAirMultiplier, Offset: 0x1bf8
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: BoostGuageMIC, Offset: 0x1c00
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: IsBoosting, Offset: 0x1c08
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: Boost, Offset: 0x1c0c
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: DamageValue, Offset: 0x1c10
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: PickaxeImpulseStrength, Offset: 0x1c14
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: Row_ShouldLaunchPlayer, Offset: 0x1c18
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: GC_HitPlayer, Offset: 0x1c40
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: GC_ParamsEmpty, Offset: 0x1c48
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: GC_HitFiend, Offset: 0x1d08
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: HitBuildingActor, Offset: 0x1d10
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: DestructionAngle, Offset: 0x1d18
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: SpeedImpulsePlayerMulti, Offset: 0x1d1c
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: MinSpeedToLaunchPlayer, Offset: 0x1d20
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: ShouldLaunchPlayer, Offset: 0x1d24
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: Row_PickaxeImpulseStrength, Offset: 0x1d28
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: Row_MinSpeedLaunchPlayer, Offset: 0x1d50
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: Row_SpeedImpulseMultiplier, Offset: 0x1d78
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: MinSpeedToDamage, Offset: 0x1da0
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: Row_MinSpeedToDamage, Offset: 0x1da8
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: PickaxeForwardImpulseZ_Multiplier, Offset: 0x1dd0
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: PickaxeImpulse, Offset: 0x1dd4
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: ShouldPickaxeImpulse, Offset: 0x1de0
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: Row_ShouldPickaxeImpulse, Offset: 0x1de8
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: Row_PickaxeImpulseZ_Multiplier, Offset: 0x1e10
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnLand_CameraShake, Offset: 0x1e38
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnLandCameraShake, Offset: 0x1e40
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: DamageOnLandTimer, Offset: 0x1e48
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: ShouldDamageOnLand, Offset: 0x1e50
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: Row_ShouldDamageOnLand, Offset: 0x1e58
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: LandCameraSpeedForShakes, Offset: 0x1e80
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: LandCameraMaxFrequency, Offset: 0x1e84
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: LandCameraMinFrequency, Offset: 0x1e88
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: LandCameraRot_Amp, Offset: 0x1e8c
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: LandCameraY_Amp, Offset: 0x1e90
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: LandCameraZ_Amp, Offset: 0x1e94
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: LandCameraShakeFalloff, Offset: 0x1e98
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: LandDamageFrequency, Offset: 0x1e9c
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: LandDamageTimer, Offset: 0x1ea0
				HalalGS-19.10: LogInit: Info: ChildProperties->Name: BoatDamageOnLand, Offset: 0x1ea8
			*/
		}

		FN_LOG(LogInit, Log, "ServerAttemptInteract called - ReceivingActor: %s", ReceivingActor->GetFullName().c_str());
		
	}

	void ServerCheat(AFortPlayerController* PlayerController, const FString& Msg)
	{
		FString TempPlayerName = L"Null";

		APlayerState* TempPlayerState = PlayerController->PlayerState;

		if (TempPlayerState)
			TempPlayerName = TempPlayerState->GetPlayerName();

		FN_LOG(LogInit, Log, "ServerCheat - Msg: %s [PlayerName: %s]", Msg.ToString().c_str(), TempPlayerName.ToString().c_str());

		if (!Msg.IsValid())
			return;

		std::string Command = Msg.ToString();
		std::vector<std::string> ParsedCommand = split(Command, ' ');

		if (ParsedCommand.empty())
			return;

		std::string Action = ParsedCommand[0];
		std::transform(Action.begin(), Action.end(), Action.begin(),
			[](unsigned char c) { return std::tolower(c); });

		FString Message = L"Unknown Command";

		AFortPlayerState* PlayerState = Cast<AFortPlayerState>(PlayerController->PlayerState);
		UCheatManager* CheatManager = PlayerController->CheatManager;
		AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;

		if (Action == "listplayers")
		{
			TArray<AFortPlayerController*> AllFortPlayerControllers = UFortKismetLibrary::GetAllFortPlayerControllers(PlayerController, true, false);

			int32 NumPlayers = 0;
			for (int32 i = 0; i < AllFortPlayerControllers.Num(); i++)
			{
				AFortPlayerController* FortPlayerController = AllFortPlayerControllers[i];
				if (!FortPlayerController) continue;

				if (!FortPlayerController->PlayerState)
					continue;

				NumPlayers++;

				std::string LootMessage = "[" + std::to_string(NumPlayers) + "] - PlayerName: " + FortPlayerController->PlayerState->GetPlayerName().ToString();
				FString FLootMessage = std::wstring(LootMessage.begin(), LootMessage.end()).c_str();
				PlayerController->ClientMessage(FLootMessage, FName(), 1);

				Message = L"null";
			}
		}
		else if (Action == "startaircraft")
		{
			UKismetSystemLibrary::ExecuteConsoleCommand(PlayerController, L"startaircraft", nullptr);
			Message = L"StartAirCraft command executed successfully!";
		}

#ifdef CHEATS
		else if (Action == "pausesafezone")
		{
			UKismetSystemLibrary::ExecuteConsoleCommand(PlayerController, L"pausesafezone", nullptr);
			Message = L"PauseSafeZone command executed successfully!";
		}
		else if (Action == "skipsafezone")
		{
			UKismetSystemLibrary::ExecuteConsoleCommand(PlayerController, L"skipsafezone", nullptr);
			Message = L"SkipSafeZone command executed successfully!";
		}
		else if (Action == "startsafezone")
		{
			UKismetSystemLibrary::ExecuteConsoleCommand(PlayerController, L"startsafezone", nullptr);
			Message = L"StartSafeZone command executed successfully!";
		}
		else if (Action == "skipshrinksafezone")
		{
			UKismetSystemLibrary::ExecuteConsoleCommand(PlayerController, L"skipshrinksafezone", nullptr);
			Message = L"SkipShrinkSafeZone command executed successfully!";
		}
		else if (Action == "startshrinksafezone")
		{
			UKismetSystemLibrary::ExecuteConsoleCommand(PlayerController, L"startshrinksafezone", nullptr);
			Message = L"StartShrinkSafeZone command executed successfully!";
		}
		else if (Action == "buildfree")
		{
			PlayerController->bBuildFree = PlayerController->bBuildFree ? false : true;
			Message = PlayerController->bBuildFree ? L"BuildFree on" : L"BuildFree off";
		}
		else if (Action == "infiniteammo")
		{
			PlayerController->bInfiniteAmmo = PlayerController->bInfiniteAmmo ? false : true;
			Message = PlayerController->bInfiniteAmmo ? L"InfiniteAmmo on" : L"InfiniteAmmo off";
		}
		else if (Action == "sethealth" && ParsedCommand.size() >= 2)
		{
			if (PlayerPawn)
			{
				try
				{
					float NewHealthVal = std::stof(ParsedCommand[1]);

					PlayerPawn->SetHealth(NewHealthVal);
					Message = L"SetHealth command executed successfully!";
				}
				catch (const std::invalid_argument& e)
				{
					Message = L"Invalid NewHealthVal provided!";
				}
				catch (const std::out_of_range& e)
				{
					Message = L"NewHealthVal out of range!";
				}
			}
			else
			{
				Message = L"PlayerPawn not found!";
			}
		}
		else if (Action == "setshield" && ParsedCommand.size() >= 2)
		{
			if (PlayerPawn)
			{
				try
				{
					float NewShieldVal = std::stof(ParsedCommand[1]);

					PlayerPawn->SetShield(NewShieldVal);
					Message = L"SetShield command executed successfully!";
				}
				catch (const std::invalid_argument& e)
				{
					Message = L"Invalid NewShieldVal provided!";
				}
				catch (const std::out_of_range& e)
				{
					Message = L"NewShieldVal out of range!";
				}
			}
			else
			{
				Message = L"PlayerPawn not found!";
			}
		}
		else if (Action == "setmaxhealth" && ParsedCommand.size() >= 2)
		{
			if (PlayerPawn)
			{
				try
				{
					float NewHealthVal = std::stof(ParsedCommand[1]);

					PlayerPawn->SetMaxHealth(NewHealthVal);
					Message = L"SetMaxHealth command executed successfully!";
				}
				catch (const std::invalid_argument& e)
				{
					Message = L"Invalid NewHealthVal provided!";
				}
				catch (const std::out_of_range& e)
				{
					Message = L"NewHealthVal out of range!";
				}
			}
			else
			{
				Message = L"PlayerPawn not found!";
			}
		}
		else if (Action == "setmaxshield" && ParsedCommand.size() >= 2)
		{
			if (PlayerPawn)
			{
				try
				{
					float NewShieldVal = std::stof(ParsedCommand[1]);

					PlayerPawn->SetMaxShield(NewShieldVal);
					Message = L"SetMaxShield command executed successfully!";
				}
				catch (const std::invalid_argument& e)
				{
					Message = L"Invalid NewShieldVal provided!";
				}
				catch (const std::out_of_range& e)
				{
					Message = L"NewShieldVal out of range!";
				}
			}
			else
			{
				Message = L"PlayerPawn not found!";
			}
		}
		else if (Action == "setsprintspeed" && ParsedCommand.size() >= 2)
		{
			if (PlayerPawn)
			{
				try
				{
					float NewSprintSpeedVal = std::stof(ParsedCommand[1]);

					PlayerPawn->MovementSet->SprintSpeed.BaseValue = NewSprintSpeedVal;
					PlayerPawn->MovementSet->SprintSpeed.CurrentValue = NewSprintSpeedVal;

					PlayerPawn->MovementSet->SprintSpeed.Minimum = NewSprintSpeedVal;
					PlayerPawn->MovementSet->SprintSpeed.Maximum = NewSprintSpeedVal;

					Message = L"SetSprintSpeed command executed successfully!";
				}
				catch (const std::invalid_argument& e)
				{
					Message = L"Invalid NewSprintSpeedVal provided!";
				}
				catch (const std::out_of_range& e)
				{
					Message = L"NewSprintSpeedVal out of range!";
				}
			}
			else
			{
				Message = L"PlayerPawn not found!";
			}
		}
		else if (Action == "god")
		{
			if (CheatManager)
			{
				CheatManager->God();
				Message = L"null";
			}
			else
			{
				Message = L"CheatManager not found!";
			}
		}
		else if (Action == "destroytarget")
		{
			if (CheatManager)
			{
				CheatManager->DestroyTarget();
				Message = L"Target successfully destroyed!";
			}
			else
			{
				Message = L"CheatManager not found!";
			}
		}
		else if (Action == "tp")
		{
			if (CheatManager)
			{
				CheatManager->Teleport();
				Message = L"Teleportation successful!";
			}
			else
			{
				Message = L"CheatManager not found!";
			}
		}
		else if (Action == "resetabilities")
		{
			if (PlayerState && PlayerState->AbilitySystemComponent)
			{
				UFortAbilitySystemComponent* AbilitySystemComponent = PlayerState->AbilitySystemComponent;

				AbilitySystemComponent->ClearAllAbilities();

				for (int32 i = 0; i < AbilitySystemComponent->ActiveGameplayEffects.GameplayEffects_Internal.Num(); i++)
				{
					FActiveGameplayEffect ActiveGameplayEffect = AbilitySystemComponent->ActiveGameplayEffects.GameplayEffects_Internal[i];
					if (!ActiveGameplayEffect.Spec.Def) continue;

					AbilitySystemComponent->RemoveActiveGameplayEffect(ActiveGameplayEffect.Handle, 1);
				}

				UGameDataBR* GameDataBR = Globals::GetGameDataBR();
				UFortAbilitySet* DefaultAbilities = Functions::LoadAbilitySet(GameDataBR->PlayerAbilitySetBR);

				Abilities::GrantGameplayAbility(DefaultAbilities, AbilitySystemComponent);
				Abilities::GrantGameplayEffect(DefaultAbilities, AbilitySystemComponent);
				Abilities::GrantModifierAbilityFromPlaylist(AbilitySystemComponent);

				if (PlayerPawn)
					PlayerState->ApplyCharacterCustomization(PlayerPawn);

				Message = L"Abilities successfully reset!";
			}
			else
			{
				Message = L"PlayerState/AbilitySystemComponent not found!";
			}
		}
		else if (Action == "resetinventory")
		{
			if (PlayerController->WorldInventory)
			{
				Inventory::ResetInventory(PlayerController->WorldInventory);

				AFortPlayerControllerAthena* PlayerControllerAthena = Cast<AFortPlayerControllerAthena>(PlayerController);
				UFortWeaponMeleeItemDefinition* PickaxeItemDefinition = nullptr;

				if (PlayerControllerAthena)
				{
					UAthenaPickaxeItemDefinition* AthenaPickaxeItemDefinition = PlayerControllerAthena->CosmeticLoadoutPC.Pickaxe;

					if (AthenaPickaxeItemDefinition)
						PickaxeItemDefinition = AthenaPickaxeItemDefinition->WeaponDefinition;

					if (!PickaxeItemDefinition)
					{
						UGameDataCosmetics* GameDataCosmetics = Globals::GetGameDataCosmetics();
						UAthenaPickaxeItemDefinition* DefaultPickaxeSkin = GameDataCosmetics->FallbackPickaxe.Get();

						if (DefaultPickaxeSkin)
							PickaxeItemDefinition = DefaultPickaxeSkin->WeaponDefinition;
					}
				}

				Inventory::SetupInventory(PlayerControllerAthena, PickaxeItemDefinition);

				Message = L"Inventory successfully reset!";
			}
			else
			{
				Message = L"WorldInventory not found!";
			}
		}
		else if (Action == "bugitgo" && ParsedCommand.size() >= 4)
		{
			if (CheatManager)
			{
				try
				{
					float X = std::stof(ParsedCommand[1]);
					float Y = std::stof(ParsedCommand[2]);
					float Z = std::stof(ParsedCommand[3]);

					CheatManager->BugItGo(X, Y, Z, 0.f, 0.f, 0.f);
					Message = L"BugItGo command executed successfully!";
				}
				catch (const std::invalid_argument& e)
				{
					Message = L"Invalid coordinates provided!";
				}
				catch (const std::out_of_range& e)
				{
					Message = L"Coordinates out of range!";
				}
			}
			else
			{
				Message = L"CheatManager not found!";
			}
		}
		else if (Action == "launchpawn" && ParsedCommand.size() >= 4)
		{
			if (PlayerPawn)
			{
				try
				{
					float X = std::stof(ParsedCommand[1]);
					float Y = std::stof(ParsedCommand[2]);
					float Z = std::stof(ParsedCommand[3]);

					if (ParsedCommand.size() >= 5)
					{
						std::string PlayerName = ParsedCommand[4];

						TArray<AFortPlayerController*> AllFortPlayerControllers = UFortKismetLibrary::GetAllFortPlayerControllers(PlayerController, true, false);

						for (int32 i = 0; i < AllFortPlayerControllers.Num(); i++)
						{
							auto FortPlayerController = AllFortPlayerControllers[i];
							if (!FortPlayerController) continue;

							auto TempPlayerState = FortPlayerController->PlayerState;
							if (!TempPlayerState) continue;

							if (TempPlayerState->GetPlayerName().ToString() == PlayerName)
							{
								auto TempPlayerPawn = FortPlayerController->GetPlayerPawn();
								if (!TempPlayerPawn) break;

								TempPlayerPawn->LaunchCharacter(FVector(X, Y, Z), false, false);
								Message = L"LaunchPawn command executed successfully!";
								break;
							}
						}
					}
					else
					{
						PlayerPawn->LaunchCharacter(FVector(X, Y, Z), false, false);
						Message = L"LaunchPawn command executed successfully!";
					}
				}
				catch (const std::invalid_argument& e)
				{
					Message = L"Invalid coordinates provided!";
				}
				catch (const std::out_of_range& e)
				{
					Message = L"Coordinates out of range!";
				}
			}
			else
			{
				Message = L"PlayerPawn not found!";
			}
		}
		else if (Action == "summon" && ParsedCommand.size() >= 2)
		{
			if (PlayerPawn)
			{
				std::string& ClassName = ParsedCommand[1];

				int32 AmountToSpawn = 1;

				if (ParsedCommand.size() >= 3)
				{
					bool bIsAmountToSpawnInt = std::all_of(ParsedCommand[2].begin(), ParsedCommand[2].end(), ::isdigit);

					if (bIsAmountToSpawnInt)
						AmountToSpawn = std::stoi(ParsedCommand[2]);
				}

				UClass* Class = StaticLoadObject<UClass>(std::wstring(ClassName.begin(), ClassName.end()).c_str());

				if (Class)
				{
					const float LootSpawnLocationX = 300;
					const float LootSpawnLocationY = 0;
					const float LootSpawnLocationZ = 0;

					FVector SpawnLocation = PlayerPawn->K2_GetActorLocation() +
						PlayerPawn->GetActorForwardVector() * LootSpawnLocationX +
						PlayerPawn->GetActorRightVector() * LootSpawnLocationY +
						PlayerPawn->GetActorUpVector() * LootSpawnLocationZ;

					for (int32 j = 0; j < AmountToSpawn; j++)
					{
						AActor* Actor = PlayerPawn->GetWorld()->SpawnActor(Class, &SpawnLocation);

						/*ABuildingContainer* BuildingContainer = Cast<ABuildingContainer>(Actor);
						ABuildingSMActor* BuildingSMActor = Cast<ABuildingSMActor>(Actor);

						if (BuildingContainer)
						{
							BuildingContainer->PostUpdate(EFortBuildingPersistentState::New);
						}
						else if (BuildingSMActor)
						{
							BuildingSMActor->PostUpdate();
						}*/
					}

					Message = L"Summon successful!";
				}
				else 
				{
					Message = L"Class not found!";
				}
			}
			else
			{
				Message = L"PlayerPawn not found!";
			}
		}
		else if (Action == "spawnloot" && ParsedCommand.size() >= 2)
		{
			std::string& LootTierGroup = ParsedCommand[1];

			FName TierGroupName = UKismetStringLibrary::Conv_StringToName(std::wstring(LootTierGroup.begin(), LootTierGroup.end()).c_str());

			int32 WorldLevel = -1;

			if (ParsedCommand.size() >= 3)
			{
				bool bIsWorldLevelInt = std::all_of(ParsedCommand[2].begin(), ParsedCommand[2].end(), ::isdigit);

				if (bIsWorldLevelInt)
					WorldLevel = std::stoi(ParsedCommand[2]);
			}

			int32 ForcedLootTier = -1;

			if (ParsedCommand.size() >= 4)
			{
				bool bIsForcedLootTierInt = std::all_of(ParsedCommand[3].begin(), ParsedCommand[3].end(), ::isdigit);

				if (bIsForcedLootTierInt)
					ForcedLootTier = std::stoi(ParsedCommand[3]);
			}

			TArray<FFortItemEntry> LootToDrops;
			bool bSuccess = UFortKismetLibrary::PickLootDrops(PlayerController, &LootToDrops, TierGroupName, WorldLevel, ForcedLootTier);

			if (bSuccess && PlayerPawn)
			{
				const FVector& SpawnLocation = PlayerPawn->K2_GetActorLocation();

				for (auto& LootToDrop : LootToDrops)
				{
					TWeakObjectPtr<AFortPlayerController> WeakPlayerController{};
					WeakPlayerController.ObjectIndex = -1;
					WeakPlayerController.ObjectSerialNumber = 0;

					TWeakObjectPtr<AActor> WeakInvestigator{};
					WeakInvestigator.ObjectIndex = -1;
					WeakInvestigator.ObjectSerialNumber = 0;

					FFortCreatePickupData PickupData{};
					PickupData.World = PlayerController->GetWorld();
					PickupData.ItemEntry = LootToDrop;
					PickupData.SpawnLocation = SpawnLocation;
					PickupData.SpawnRotation = FRotator();
					PickupData.WeakPlayerController = WeakPlayerController;
					PickupData.OverrideClass = nullptr;
					PickupData.WeakInvestigator = WeakInvestigator;
					PickupData.PickupSourceTypeFlags = EFortPickupSourceTypeFlag::Other;
					PickupData.PickupSpawnSource = EFortPickupSpawnSource::Unset;
					PickupData.bRandomRotation = true;
					PickupData.BitPad_1DA_1 = false;

					AFortPickup* (*CreatePickupFromData)(FFortCreatePickupData* PickupData) = decltype(CreatePickupFromData)(0x64dd1b4 + uintptr_t(GetModuleHandle(0)));
					AFortPickup* Pickup = CreatePickupFromData(&PickupData);

					if (Pickup)
					{
						Pickup->TossPickup(
							SpawnLocation, 
							PlayerPawn, 
							0, 
							true,
							true,
							EFortPickupSourceTypeFlag::Other,
							EFortPickupSpawnSource::Unset);

						Pickup->PawnWhoDroppedPickup = PlayerPawn;
					}
				}

				Message = L"TierGroupName success spawn!";
			}
			else
			{
				if (!PlayerPawn)
				{
					Message = L"PlayerPawn not found!";
				}
				else
				{
					Message = L"Failed to find this TierGroupName!";
				}
			}

			FFortItemEntry::FreeItemEntries(&LootToDrops);
		}
		else if (Action == "spawnpickup" && ParsedCommand.size() >= 2)
		{
			std::string ItemDefinitionName = ParsedCommand[1];

			std::transform(ItemDefinitionName.begin(), ItemDefinitionName.end(), ItemDefinitionName.begin(),
				[](unsigned char c) { return std::tolower(c); });

			int32 NumberToSpawn = 1;

			if (ParsedCommand.size() >= 3)
			{
				bool bIsNumberToSpawnInt = std::all_of(ParsedCommand[2].begin(), ParsedCommand[2].end(), ::isdigit);

				if (bIsNumberToSpawnInt)
					NumberToSpawn = std::stoi(ParsedCommand[2]);
			}

			TArray<UFortItemDefinition*> AllItems = Functions::GetAllItems();

			if (PlayerPawn)
			{
				if (NumberToSpawn <= 10000 && NumberToSpawn > 0)
				{
					const FVector& SpawnLocation = PlayerPawn->K2_GetActorLocation();

					bool bItemFound = false;
					for (int32 i = 0; i < AllItems.Num(); i++)
					{
						UFortWorldItemDefinition* ItemDefinition = Cast<UFortWorldItemDefinition>(AllItems[i]);

						if (!ItemDefinition)
							continue;

						std::string ItemDefinitionName2 = ItemDefinition->GetName();

						std::transform(ItemDefinitionName2.begin(), ItemDefinitionName2.end(), ItemDefinitionName2.begin(),
							[](unsigned char c) { return std::tolower(c); });

						if (ItemDefinitionName2 != ItemDefinitionName)
							continue;

						UFortKismetLibrary::K2_SpawnPickupInWorld(
							PlayerController, 
							ItemDefinition, 
							NumberToSpawn, 
							SpawnLocation, 
							SpawnLocation,
							0, 
							true,
							true, 
							true,
							-1,
							EFortPickupSourceTypeFlag::Other,
							EFortPickupSpawnSource::Unset,
							nullptr,
							true);
						bItemFound = true;
						break;
					}

					if (bItemFound)
					{
						Message = L"Pickup successfully spawned!";
					}
					else
					{
						Message = L"Item definition not found!";
					}
				}
				else
				{
					Message = L"Invalid number to spawn (NumberToSpawn <= 10000 && NumberToSpawn > 0)";
				}
			}
			else
			{
				Message = L"PlayerPawn not found!";
			}

			if (AllItems.IsValid())
				AllItems.Free();
		}
		else if (Action == "giveitem" && ParsedCommand.size() >= 2)
		{
			std::string ItemDefinitionName = ParsedCommand[1];

			std::transform(ItemDefinitionName.begin(), ItemDefinitionName.end(), ItemDefinitionName.begin(),
				[](unsigned char c) { return std::tolower(c); });

			int32 NumberToGive = 1;
			bool bNotifyPlayer = true;

			if (ParsedCommand.size() >= 3)
			{
				bool bIsNumberToGiveInt = std::all_of(ParsedCommand[2].begin(), ParsedCommand[2].end(), ::isdigit);

				if (bIsNumberToGiveInt)
					NumberToGive = std::stoi(ParsedCommand[2]);
			}

			if (ParsedCommand.size() >= 4)
			{
				bool bIsNotifyPlayerInt = std::all_of(ParsedCommand[3].begin(), ParsedCommand[3].end(), ::isdigit);

				if (bIsNotifyPlayerInt)
					bNotifyPlayer = std::stoi(ParsedCommand[3]);
			}

			TArray<UFortItemDefinition*> AllItems = Functions::GetAllItems();

			if (NumberToGive <= 10000 && NumberToGive > 0)
			{
				bool bItemFound = false;
				for (int32 i = 0; i < AllItems.Num(); i++)
				{
					UFortWorldItemDefinition* ItemDefinition = Cast<UFortWorldItemDefinition>(AllItems[i]);

					if (!ItemDefinition)
						continue;

					std::string ItemDefinitionName2 = ItemDefinition->GetName();

					std::transform(ItemDefinitionName2.begin(), ItemDefinitionName2.end(), ItemDefinitionName2.begin(),
						[](unsigned char c) { return std::tolower(c); });

					if (ItemDefinitionName2 != ItemDefinitionName)
						continue;

					UFortKismetLibrary::K2_GiveItemToPlayer(PlayerController, ItemDefinition, FGuid(), NumberToGive, bNotifyPlayer);
					bItemFound = true;
					break;
				}

				if (bItemFound)
				{
					Message = L"Item give success!";
				}
				else
				{
					Message = L"Item definition not found!";
				}
			}
			else
			{
				Message = L"Invalid number to give (NumberToGive <= 10000 && NumberToGive > 0)";
			}

			if (AllItems.IsValid())
				AllItems.Free();
		}
		else if (Action == "removeitem" && ParsedCommand.size() >= 2)
		{
			std::string ItemDefinitionName = ParsedCommand[1];

			std::transform(ItemDefinitionName.begin(), ItemDefinitionName.end(), ItemDefinitionName.begin(),
				[](unsigned char c) { return std::tolower(c); });

			int32 AmountToRemove = 1;

			if (ParsedCommand.size() >= 3)
			{
				bool bIsAmountToRemoveInt = std::all_of(ParsedCommand[2].begin(), ParsedCommand[2].end(), ::isdigit);

				if (bIsAmountToRemoveInt)
					AmountToRemove = std::stoi(ParsedCommand[2]);
			}

			TArray<UFortItemDefinition*> AllItems = Functions::GetAllItems();

			if (AmountToRemove <= 10000 && AmountToRemove > 0)
			{
				bool bItemFound = false;

				for (int32 i = 0; i < AllItems.Num(); i++)
				{
					UFortWorldItemDefinition* ItemDefinition = Cast<UFortWorldItemDefinition>(AllItems[i]);

					if (!ItemDefinition)
						continue;

					std::string ItemDefinitionName2 = ItemDefinition->GetName();

					std::transform(ItemDefinitionName2.begin(), ItemDefinitionName2.end(), ItemDefinitionName2.begin(),
						[](unsigned char c) { return std::tolower(c); });

					if (ItemDefinitionName2 != ItemDefinitionName)
						continue;

					UFortKismetLibrary::K2_RemoveItemFromPlayer(PlayerController, ItemDefinition, FGuid(), AmountToRemove, true);
					bItemFound = true;
					break;
				}

				if (bItemFound)
				{
					Message = L"Item remove success!";
				}
				else
				{
					Message = L"Item definition not found!";
				}
			}
			else
			{
				Message = L"Invalid number to remove (AmountToRemove <= 10000 && AmountToRemove > 0)";
			}

			if (AllItems.IsValid())
				AllItems.Free();
		}
		else if (Action == "dbno" && ParsedCommand.size() >= 2)
		{
			std::string PlayerName = ParsedCommand[1];

			TArray<AFortPlayerController*> AllFortPlayerControllers = UFortKismetLibrary::GetAllFortPlayerControllers(PlayerController, true, false);

			for (int32 i = 0; i < AllFortPlayerControllers.Num(); i++)
			{
				auto FortPlayerController = AllFortPlayerControllers[i];
				if (!FortPlayerController) continue;

				auto TempPlayerState = FortPlayerController->PlayerState;
				if (!TempPlayerState) continue;

				if (TempPlayerState->GetPlayerName().ToString() == PlayerName)
				{
					auto TempPlayerPawn = FortPlayerController->GetPlayerPawn();
					if (!TempPlayerPawn) break;

					bool bOldDBNO = TempPlayerPawn->bIsDBNO;

					TempPlayerPawn->bIsDBNO = bOldDBNO ? false : true;
					break;
				}
			}

			Message = L"dbno test!";
		}
		else if (Action == "rtx" && ParsedCommand.size() >= 1)
		{
			TArray<UFortItemDefinition*> AllItems = Functions::GetAllItems(true);

			if (AllItems.Num() > 0 && PlayerPawn)
			{
				const FVector& SpawnLocation = PlayerPawn->K2_GetActorLocation();

				for (int32 i = 0; i < AllItems.Num(); i++)
				{
					UFortWorldItemDefinition* ItemDefinition = Cast<UFortWorldItemDefinition>(AllItems[i]);

					if (!ItemDefinition)
						continue;

					if (ItemDefinition->Rarity != EFortRarity::Legendary)
						continue;

					UFortKismetLibrary::K2_SpawnPickupInWorld(
						PlayerController,
						ItemDefinition,
						1,
						SpawnLocation,
						SpawnLocation,
						0,
						true,
						true,
						true,
						-1,
						EFortPickupSourceTypeFlag::Other,
						EFortPickupSpawnSource::Unset,
						nullptr,
						true);
				}

				Message = L"TEUPAIIII!";
			}
			else
			{
				if (!PlayerPawn)
				{
					Message = L"PlayerPawn not found!";
				}
				else
				{
					Message = L"No items found to spawn!";
				}
			}

			if (AllItems.IsValid())
				AllItems.Free();
		}
		else if (Action == "monfils" && ParsedCommand.size() >= 1)
		{
			TArray<UFortItemDefinition*> AllItems = Functions::GetAllItems(true);

			if (AllItems.Num() > 0 && PlayerPawn)
			{
				const FVector& SpawnLocation = PlayerPawn->K2_GetActorLocation();

				for (int32 i = 0; i < AllItems.Num(); i++)
				{
					UFortWorldItemDefinition* ItemDefinition = Cast<UFortWorldItemDefinition>(AllItems[i]);

					if (!ItemDefinition)
						continue;

					if (ItemDefinition->Rarity != EFortRarity::Mythic)
						continue;

					UFortKismetLibrary::K2_SpawnPickupInWorld(
						PlayerController,
						ItemDefinition,
						1,
						SpawnLocation,
						SpawnLocation,
						0,
						true,
						true,
						true,
						-1,
						EFortPickupSourceTypeFlag::Other,
						EFortPickupSpawnSource::Unset,
						nullptr,
						true);
				}

				Message = L"Imabloké!";
			}
			else
			{
				if (!PlayerPawn)
				{
					Message = L"PlayerPawn not found!";
				}
				else
				{
					Message = L"No items found to spawn!";
				}
			}

			if (AllItems.IsValid())
				AllItems.Free();
		}
#endif // CHEATS

		if (Message != L"null")
			PlayerController->ClientMessage(Message, FName(), 1);
	}

	void GetPlayerViewPoint(APlayerController* PlayerController, FVector& out_Location, FRotator& out_Rotation)
	{
		APawn* Pawn = PlayerController->Pawn;
		ASpectatorPawn* SpectatorPawn = PlayerController->SpectatorPawn;

		if (Pawn)
		{
			out_Location = Pawn->K2_GetActorLocation();
			out_Rotation = PlayerController->GetControlRotation();
			return;
		}
		else if (SpectatorPawn && PlayerController->HasAuthority())
		{
			out_Location = SpectatorPawn->K2_GetActorLocation();
			out_Rotation = ((APlayerController*)SpectatorPawn->Owner)->GetControlRotation();
			return;
		}
		else if (!SpectatorPawn && !Pawn)
		{
			out_Location = PlayerController->LastSpectatorSyncLocation;
			out_Rotation = PlayerController->LastSpectatorSyncRotation;
			return;
		}

		GetPlayerViewPointOG(PlayerController, out_Location, out_Rotation);
	}

	void ServerAcknowledgePossession(APlayerController* PlayerController, APawn* P)
	{
		if (!PlayerController || !P)
			return;

		if (PlayerController->AcknowledgedPawn == P)
			return;

		PlayerController->AcknowledgedPawn = P;
	}

	void ModLoadedAmmo(void* InventoryOwner, const FGuid& ItemGuid, int32 Count)
	{
		AFortPlayerController* PlayerController = AFortPlayerController::GetPlayerControllerFromInventoryOwner(InventoryOwner);
		if (!PlayerController) return;

		AFortInventory* WorldInventory = PlayerController->WorldInventory;
		if (!WorldInventory) return;

		// Function [ModLoadedAmmo] hooked with Offset [0x4bb7597], IdaAddress [00007FF69B187597]

		for (int32 i = 0; i < WorldInventory->Inventory.ItemInstances.Num(); i++)
		{
			UFortWorldItem* ItemInstance = WorldInventory->Inventory.ItemInstances[i];
			if (!ItemInstance) continue;

			FFortItemEntry* ItemEntry = &WorldInventory->Inventory.ItemInstances[i]->ItemEntry;

			if (ItemEntry->ItemGuid == ItemGuid)
			{
				ItemEntry->SetLoadedAmmo(Count);
				break;
			}
		}

		// I think that normally you don't need to modify the value here but for me it doesn't work idk
		for (int32 i = 0; i < WorldInventory->Inventory.ReplicatedEntries.Num(); i++)
		{
			FFortItemEntry* ReplicatedItemEntry = &WorldInventory->Inventory.ReplicatedEntries[i];

			if (ReplicatedItemEntry->ItemGuid == ItemGuid)
			{
				ReplicatedItemEntry->LoadedAmmo = Count;
				WorldInventory->Inventory.MarkItemDirty(*ReplicatedItemEntry);
				break;
			}
		}
	}

	void ModPhantomReserveAmmo(void* InventoryOwner, const FGuid& ItemGuid, int32 Count)
	{
		AFortPlayerController* PlayerController = AFortPlayerController::GetPlayerControllerFromInventoryOwner(InventoryOwner);
		if (!PlayerController) return;

		AFortInventory* WorldInventory = PlayerController->WorldInventory;
		if (!WorldInventory) return;

		// Function [ModPhantomReserveAmmo] hooked with Offset [0x69b26a6], IdaAddress [00007FF69CF826A6]

		for (int32 i = 0; i < WorldInventory->Inventory.ItemInstances.Num(); i++)
		{
			UFortWorldItem* ItemInstance = WorldInventory->Inventory.ItemInstances[i];
			if (!ItemInstance) continue;

			FFortItemEntry* ItemEntry = &WorldInventory->Inventory.ItemInstances[i]->ItemEntry;

			if (ItemEntry->ItemGuid == ItemGuid)
			{
				ItemEntry->SetPhantomReserveAmmo(Count);
				break;
			}
		}

		// I think that normally you don't need to modify the value here but for me it doesn't work idk
		for (int32 i = 0; i < WorldInventory->Inventory.ReplicatedEntries.Num(); i++)
		{
			FFortItemEntry* ReplicatedItemEntry = &WorldInventory->Inventory.ReplicatedEntries[i];

			if (ReplicatedItemEntry->ItemGuid == ItemGuid)
			{
				ReplicatedItemEntry->PhantomReserveAmmo = Count;
				WorldInventory->Inventory.MarkItemDirty(*ReplicatedItemEntry);
				break;
			}
		}
	}

	bool RemoveInventoryItem(void* InventoryOwner, const FGuid& ItemGuid, int32 Count, bool bForceRemoveFromQuickBars, bool bForceRemoval, bool bForcePersistWhenEmpty)
	{
		AFortPlayerController* PlayerController = AFortPlayerController::GetPlayerControllerFromInventoryOwner(InventoryOwner);
		if (!PlayerController) return false;

		if (Count == 0)
			return true;

		if (PlayerController->bInfiniteAmmo && !bForceRemoval)
			return true;

		UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->BP_GetInventoryItemWithGuid(ItemGuid));
		if (!WorldItem) return false;

		FFortItemEntry ItemEntry = WorldItem->ItemEntry;

		if (Count == -1)
		{
			Inventory::RemoveItem(PlayerController->WorldInventory, ItemGuid);
			return true;
		}

		if (Count >= ItemEntry.Count)
		{
			UFortWeaponRangedItemDefinition* WeaponRangedItemDefinition = Cast<UFortWeaponRangedItemDefinition>(ItemEntry.ItemDefinition);

			if (WeaponRangedItemDefinition && (WeaponRangedItemDefinition->bPersistInInventoryWhenFinalStackEmpty || bForcePersistWhenEmpty))
			{
				FN_LOG(LogInventory, Log, "DropBehavior: %i", WeaponRangedItemDefinition->DropBehavior);
				FN_LOG(LogInventory, Log, "LoadedAmmo: %i", ItemEntry.LoadedAmmo);

				if (WeaponRangedItemDefinition->DropBehavior != EWorldItemDropBehavior::DropAsPickupEvenWhenEmpty && false) // A Fix
				{
					int32 ItemQuantity = UFortKismetLibrary::K2_GetItemQuantityOnPlayer(PlayerController, WeaponRangedItemDefinition, FGuid());

					if (ItemQuantity == 1)
					{
						Inventory::ModifyCountItem(PlayerController->WorldInventory, ItemGuid, 0);
						return true;
					}
				}
			}

			Inventory::RemoveItem(PlayerController->WorldInventory, ItemGuid);
		}
		else if (Count < ItemEntry.Count)
		{
			int32 NewCount = ItemEntry.Count - Count;

			Inventory::ModifyCountItem(PlayerController->WorldInventory, ItemGuid, NewCount);
		}
		else
			return false;

		return true;
	}

	void MaybeAddItem(void* InventoryOwner, const FGuid& ItemGuid)
	{
		FN_LOG(LogInventory, Log, "MaybeAddItem called!");
	}

	void InitPlayerController()
	{
		AFortPlayerControllerAthena* FortPlayerControllerAthenaDefault = AFortPlayerControllerAthena::GetDefaultObj();
		UFortControllerComponent_Aircraft* FortControllerComponent_AircraftDefault = UFortControllerComponent_Aircraft::GetDefaultObj();
		UFortControllerComponent_Interaction* FortControllerComponent_InteractionDefault = UFortControllerComponent_Interaction::GetDefaultObj();
		UObject* InventoryOwnerDefault = (UObject*)FortPlayerControllerAthenaDefault->GetInventoryOwner();

		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x2A98 / 8, ServerClientIsReadyToRespawn, nullptr, "AFortPlayerControllerAthena::ServerClientIsReadyToRespawn");

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x6c26888), ClientOnPawnDied, (LPVOID*)(&ClientOnPawnDiedOG));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x6c26888));

		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1460 / 8, ServerReadyToStartMatch, (LPVOID*)(&ServerReadyToStartMatchOG), "AFortPlayerController::ServerReadyToStartMatch");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x11D0 / 8, ServerAttemptInventoryDrop, nullptr, "AFortPlayerController::ServerAttemptInventoryDrop");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x11E0 / 8, ServerCombineInventoryItems, nullptr, "AFortPlayerController::ServerCombineInventoryItems");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1268 / 8, ServerCreateBuildingActor, nullptr, "AFortPlayerController::ServerCreateBuildingActor");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1248 / 8, ServerRepairBuildingActor, nullptr, "AFortPlayerController::ServerRepairBuildingActor");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x12A0 / 8, ServerBeginEditingBuildingActor, nullptr, "AFortPlayerController::ServerBeginEditingBuildingActor");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1278 / 8, ServerEditBuildingActor, nullptr, "AFortPlayerController::ServerEditBuildingActor");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1290 / 8, ServerEndEditingBuildingActor, nullptr, "AFortPlayerController::ServerEndEditingBuildingActor");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1160 / 8, ServerExecuteInventoryItem, nullptr, "AFortPlayerController::ServerExecuteInventoryItem");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0xED8 / 8, ServerDropAllItems, nullptr, "AFortPlayerController::ServerDropAllItems");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0xF40 / 8, ServerPlayEmoteItem, nullptr, "AFortPlayerController::ServerPlayEmoteItem");
		MinHook::HookVTable(FortControllerComponent_AircraftDefault, 0x4F0 / 8, ServerAttemptAircraftJump, nullptr, "UFortControllerComponent_Aircraft::ServerAttemptAircraftJump");
		MinHook::HookVTable(FortControllerComponent_InteractionDefault, 0x500 / 8, ServerAttemptInteract, (LPVOID*)(&ServerAttemptInteractOG), "UFortControllerComponent_Interaction::ServerAttemptInteract");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1440 / 8, ServerReturnToMainMenu, (LPVOID*)(&ServerReturnToMainMenuOG), "AFortPlayerController::ServerReturnToMainMenu");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x14C0 / 8, ServerSuicide, nullptr, "AFortPlayerController::ServerSuicide");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0xF30 / 8, ServerCheat, nullptr, "AFortPlayerController::ServerCheat");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x910 / 8, ServerAcknowledgePossession, nullptr, "APlayerController::ServerAcknowledgePossession");

		MinHook::HookVTable(InventoryOwnerDefault, 0xA8 / 8, ModLoadedAmmo, nullptr, "ModLoadedAmmo");
		MinHook::HookVTable(InventoryOwnerDefault, 0x16, ModPhantomReserveAmmo, nullptr, "ModPhantomReserveAmmo");

		// MinHook::HookVTable(InventoryOwnerDefault, 0x5, MaybeAddItem, nullptr, "MaybeAddItem");

		uintptr_t AddressRemoveInventoryItem = MinHook::FindPattern(Patterns::RemoveInventoryItem);
		uintptr_t AddressGetPlayerViewPoint = MinHook::FindPattern(Patterns::GetPlayerViewPoint);

		MH_CreateHook((LPVOID)(AddressRemoveInventoryItem), RemoveInventoryItem, nullptr);
		MH_EnableHook((LPVOID)(AddressRemoveInventoryItem));
		MH_CreateHook((LPVOID)(AddressGetPlayerViewPoint), GetPlayerViewPoint, (LPVOID*)(&GetPlayerViewPointOG));
		MH_EnableHook((LPVOID)(AddressGetPlayerViewPoint));

		FN_LOG(LogInit, Log, "InitPlayerController Success!");
	}
}
