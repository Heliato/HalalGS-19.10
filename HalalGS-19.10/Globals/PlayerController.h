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

		AFortPlayerStateAthena* KillerPlayerState = Cast<AFortPlayerStateAthena>(DeathReport.KillerPlayerState);
		AFortPlayerPawnAthena* KillerPawn = Cast<AFortPlayerPawnAthena>(DeathReport.KillerPawn);
		AFortPlayerControllerAthena* KillerPlayerControllerAthena = (KillerPawn ? Cast<AFortPlayerControllerAthena>(KillerPawn->Controller) : nullptr);

		AActor* DamageCauser = DeathReport.DamageCauser;

		FGameplayTagContainer TagContainer = PlayerPawnAthena ? *(FGameplayTagContainer*)(__int64(PlayerPawnAthena) + 0x19E0) : FGameplayTagContainer();

		float Distance = KillerPawn ? KillerPawn->GetDistanceTo(PlayerPawnAthena) : 0;

		EDeathCause DeathCause = AFortPlayerStateAthena::ToDeathCause(TagContainer, PlayerPawnAthena->bIsDBNO);

		FDeathInfo DeathInfo = FDeathInfo();
		DeathInfo.FinisherOrDowner = KillerPlayerState ? KillerPlayerState : PlayerStateAthena;
		DeathInfo.bDBNO = PlayerPawnAthena->bIsDBNO;
		DeathInfo.DeathCause = DeathCause;
		DeathInfo.Distance = (DeathCause == EDeathCause::FallDamage) ? PlayerPawnAthena->LastFallDistance : Distance;
		DeathInfo.DeathLocation = PlayerPawnAthena->K2_GetActorLocation();
		DeathInfo.bInitialized = true;

		PlayerStateAthena->PawnDeathLocation = DeathInfo.DeathLocation;

		PlayerStateAthena->DeathInfo = DeathInfo;
		PlayerStateAthena->OnRep_DeathInfo();

		if (KillerPlayerState && PlayerStateAthena != KillerPlayerState)
		{
			KillerPlayerState->KillScore++;
			KillerPlayerState->OnRep_Kills();

			KillerPlayerState->ClientReportKill(PlayerStateAthena);

#ifdef SIPHON
			AFortPlayerControllerAthena* KillerPlayerController = Cast<AFortPlayerControllerAthena>(KillerPlayerState->Owner);

			if (KillerPlayerController)
				Functions::GiveSiphonBonus(KillerPlayerController, KillerPawn);
#endif // SIPHON
		}

		AFortPlayerControllerAthena* PlayerControllerAthena = Cast<AFortPlayerControllerAthena>(PlayerControllerZone);
		AFortGameModeAthena* GameModeAthena = Cast<AFortGameModeAthena>(Globals::GetGameMode());
		AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(GameModeAthena->GameState);

		if (PlayerControllerAthena && GameModeAthena && GameStateAthena)
		{
			if (!GameStateAthena->IsRespawningAllowed(PlayerStateAthena) && !PlayerPawnAthena->bIsDBNO)
			{
				FAthenaMatchTeamStats TeamStats = FAthenaMatchTeamStats();
				TeamStats.Place = GameStateAthena->PlayersLeft;
				TeamStats.TotalPlayers = GameStateAthena->TotalPlayers;

				PlayerControllerAthena->ClientSendTeamStatsForPlayer(TeamStats);

				UAthenaPlayerMatchReport* MatchReport = PlayerControllerAthena->MatchReport;

				if (MatchReport)
				{
					MatchReport->bHasMatchStats = true;
					MatchReport->bHasTeamStats = true;
					MatchReport->TeamStats = TeamStats;
					MatchReport->bHasRewards = true;
					MatchReport->EndOfMatchResults = FAthenaRewardResult();
				}

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

				PlayerStateAthena->Place = GameStateAthena->TeamsLeft;
				PlayerStateAthena->OnRep_Place();

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
						}
						break;
					}
				}
			}
		}

		ClientOnPawnDiedOG(PlayerControllerZone, DeathReport);
	}

	void ServerReadyToStartMatch(AFortPlayerController* PlayerController)
	{
#ifdef CHEATS
		if (!PlayerController->CheatManager)
		{
			UCheatManager* CheatManager = (UCheatManager*)UGameplayStatics::SpawnObject(UCheatManager::StaticClass(), PlayerController);

			if (CheatManager)
			{
				PlayerController->CheatManager = CheatManager;
				PlayerController->CheatManager->ReceiveInitCheatManager();
			}
		}
#endif // CHEATS

		UFortVehicleAimingWeaponComp;
		AFortMountedTurret;

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
		if (!PlayerControllerAthena) return;

		ABuildingActor* BuildingActor = Cast<ABuildingActor>(ReceivingActor);

		if (BuildingActor)
		{
			// HalalGS-19.10: LogInit: Info: ServerAttemptInteract called - ReceivingActor: Apollo_GasPump_Valet_C Artemis_PPR_5x5_GasStation_a_1bbbf69b.Artemis_PPR_5x5_GasStation_a.PersistentLevel.Apollo_GasPump_Valet_C_3

			static auto BP_StationProp_ParentClass = StaticFindObject<UBlueprintGeneratedClass>(L"/Game/Building/ActorBlueprints/Stations/BP_StationProp_Parent.BP_StationProp_Parent_C");

			if (BuildingActor->IsA(BP_StationProp_ParentClass))
			{
				UFortNonPlayerConversationParticipantComponent* NonPlayerConversationComponent = *(UFortNonPlayerConversationParticipantComponent**)(__int64(BuildingActor) + 0xDA8);

				if (NonPlayerConversationComponent)
				{
					NonPlayerConversationComponent->ClientStartConversation(NonPlayerConversationComponent->ConversationEntryTag);

					UCampsiteConversationComponent;

					//NonPlayerConversationComponent->StartConversation(NonPlayerConversationComponent->ConversationEntryTag, PlayerControllerAthena, BuildingActor);
				}

				/*for (UStruct* TempStruct = BuildingActor->Class; TempStruct; TempStruct = TempStruct->Super)
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
		}

		/*
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: UberGraphFrame, Offset: 0xdb8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: P_TableLightIdle, Offset: 0xdc0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: P_UpgradeFX, Offset: 0xdc8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: TopCollision, Offset: 0xdd0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: TableCollision, Offset: 0xdd8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: PostCollision, Offset: 0xde0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BaseCollision, Offset: 0xde8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: WobbleTimeline_WobbleOverTime_6C787AA044BAB89E1FDAF5A5520714F2, Offset: 0xdf0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: WobbleTimeline__Direction_6C787AA044BAB89E1FDAF5A5520714F2, Offset: 0xdf4
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: WobbleTimeline, Offset: 0xdf8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: ServiceSuccessSound, Offset: 0xe00
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: InitialRelativeRotation, Offset: 0xe08
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: UberGraphFrame, Offset: 0xd90
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: Station_Ambient, Offset: 0xd98
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BuildingActorLootDropOnDeathComponent, Offset: 0xda0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: NonPlayerConversationComponent, Offset: 0xda8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: InteractionSpeedOverride, Offset: 0xdb0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: StartAmbientOnBeginPlay, Offset: 0xdb4
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: UseSpecialActorComponent, Offset: 0xd48
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: SpecialActorComponentClass, Offset: 0xd70
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: CustomInteractionWidget, Offset: 0xd78
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: AnalyticsTags, Offset: 0xc78
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bSuppressSimpleInteractionWidgetForTouch, Offset: 0xc98
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bCanBeMarked, Offset: 0xc98
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bBlockMarking, Offset: 0xc98
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bUseDamageSet, Offset: 0xc98
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: MarkerDisplay, Offset: 0xca0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: MarkerPositionOffset, Offset: 0xd38
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bIsBuildingVolume, Offset: 0xd44
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bDoNotBlockMarkerTraceWhenOverlappingPlayer, Offset: 0xd44
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: TimeOfDayControlledLightDataArray, Offset: 0xc60
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bAutoAssignNavProperties, Offset: 0xc58
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: TextureData, Offset: 0x688
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: StaticMesh, Offset: 0x6a8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: AlternateMeshes, Offset: 0x6b0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bForceReplicateSubObjects, Offset: 0x6c0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bNoPhysicsCollision, Offset: 0x6c0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bNoCameraCollision, Offset: 0x6c0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bNoPawnCollision, Offset: 0x6c0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bNoAIPawnCollision, Offset: 0x6c0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bBlocksCeilingPlacement, Offset: 0x6c0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bBlocksAttachmentPlacement, Offset: 0x6c0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bUsePhysicalSurfaceForFootstep, Offset: 0x6c0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bRandomYawOnPlacement, Offset: 0x6c1
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bRandomScaleOnPlacement, Offset: 0x6c1
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bClearMIDWhenReturningToUndamagedState, Offset: 0x6c1
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: NumFrameSubObjects, Offset: 0x6c2
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: ResourceType, Offset: 0x6c3
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: RandomScaleRange, Offset: 0x6c4
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: DestructionLootTierGroup, Offset: 0x6cc
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: WindSpeedCurve, Offset: 0x6d8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: WindPannerSpeedCurve, Offset: 0x700
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: WindAudio, Offset: 0x728
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: ShieldBuffMaterialParamValue1, Offset: 0x750
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: ShieldBuffMaterialParamValue2, Offset: 0x754
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: AnimatingDistanceFieldSelfShadowBias, Offset: 0x758
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: AnimatingSubObjects, Offset: 0x75c
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: PlayerGridSnapSize, Offset: 0x760
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: AltMeshIdx, Offset: 0x764
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bAllowBuildingCheat, Offset: 0x7b8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bMirrored, Offset: 0x7b8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bNoCollision, Offset: 0x7b8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bSupportsRepairing, Offset: 0x7b8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bHiddenDueToTrapPlacement, Offset: 0x7b8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bAttachmentPlacementBlockedFront, Offset: 0x7b8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bAttachmentPlacementBlockedBack, Offset: 0x7b8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bIsForPreviewing, Offset: 0x7b8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bUnderConstruction, Offset: 0x7b9
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bUnderRepair, Offset: 0x7b9
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bIsInitiallyBuilding, Offset: 0x7b9
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bCameraOnlyCollision, Offset: 0x7b9
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bNoWeaponCollision, Offset: 0x7b9
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bNoRangedWeaponCollision, Offset: 0x7b9
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bNoProjectileCollision, Offset: 0x7b9
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bDoNotBlockInteract, Offset: 0x7b9
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bNeedsMIDsForCreative, Offset: 0x7ba
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bAllowResourceDrop, Offset: 0x7ba
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bHideOnDeath, Offset: 0x7ba
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bPlayDestructionEffects, Offset: 0x7ba
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bSkipConstructionSounds, Offset: 0x7ba
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bSupportedDirectly, Offset: 0x7ba
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bForciblyStructurallySupported, Offset: 0x7bb
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bRegisterWithStructuralGrid, Offset: 0x7bb
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bCurrentlyBeingEdited, Offset: 0x7bb
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bAllowWeakSpots, Offset: 0x7bb
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bUseComplexForWeakSpots, Offset: 0x7bb
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bCanSpawnAtLowerQuotaLevels, Offset: 0x7bb
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bNeedsWindMaterialParameters, Offset: 0x7bc
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bPlayBounce, Offset: 0x7bc
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bPropagateBounce, Offset: 0x7bc
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bPropagatesBounceEffects, Offset: 0x7bc
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bNeedsDamageOverlay, Offset: 0x7bc
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bDeriveCurieIdentifierFromResourceType, Offset: 0x7bc
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bAllowCustomMaterial, Offset: 0x7bc
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bUseSingleMeshCullDistance, Offset: 0x7bd
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: SavedDirectlySupportedStatus, Offset: 0x7be
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: MaximumQuotaLevelBound, Offset: 0x7bf
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BuildingAnimation, Offset: 0x7c0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: CurAnimSubObjectNum, Offset: 0x7c1
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: CurAnimSubObjectTargetNum, Offset: 0x7c2
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: ActorIndexInFoundation, Offset: 0x7c4
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BounceData, Offset: 0x7c8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: DestroyedTime, Offset: 0x7f8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: InfluenceMapWeight, Offset: 0x7fc
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BASEEffectMeshComponent, Offset: 0x808
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: NavObstacles, Offset: 0x810
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BuildingPlacementDistance, Offset: 0x830
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: ReplicatedDrawScale3D, Offset: 0x83c
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: EditorOnlyInstanceMaterialParameters, Offset: 0x848
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: StaticMeshComponent, Offset: 0x888
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: WeakPointComponent, Offset: 0x890
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BaseMaterial, Offset: 0x898
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnConstructionComplete, Offset: 0x8a0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: MinimalReplicationProxy, Offset: 0x8b0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: DestructionLootTierChosenQuotaInfo, Offset: 0x8b4
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: DestructionLootTierKey, Offset: 0x8c0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BuildingResourceAmountOverride, Offset: 0x8c8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: MaxResourcesToSpawn, Offset: 0x8d8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: IntenseWindMaterials, Offset: 0x8f0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: ColorOverrides, Offset: 0x900
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: RVTHeightOverride, Offset: 0x940
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: RVTColorOverride, Offset: 0x948
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BreakEffect, Offset: 0x950
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: DeathParticles, Offset: 0x958
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: DeathParticlesInst, Offset: 0x980
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: DeathParticleSocketName, Offset: 0x988
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: DeathSound, Offset: 0x990
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: ConstructedEffect, Offset: 0x998
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: RandomDayphaseFXList, Offset: 0x9a0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: ConstructionAudioComponent, Offset: 0x9b0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: CachedDestructionInstigator, Offset: 0x9b8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: DamageOverlayComponent, Offset: 0x9c0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: DamageAmountStart, Offset: 0x9c8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: LastDamageAmount, Offset: 0x9cc
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: LastDamageHitImpulseDir, Offset: 0x9d0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: CachedAnimatingStaticMeshes, Offset: 0x9e0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnRepairBuildingStarted, Offset: 0xa50
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnRepairBuildingFinished, Offset: 0xa60
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: EditModePatternData, Offset: 0xa70
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: UndermineGroup, Offset: 0xa78
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: LogicalBuildingIdx, Offset: 0xa7c
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: AnimatingMaterialMappings, Offset: 0xa80
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: DamagedButNotAnimatingMaterialMappings, Offset: 0xa90
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: EditModeSupportClass, Offset: 0xaa0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: EditModeSupport, Offset: 0xaa8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: HealthToAutoBuild, Offset: 0xab0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: AccumulatedAutoBuildTime, Offset: 0xab4
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BuildingReplacementType, Offset: 0xab8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: ReplacementDestructionReason, Offset: 0xab9
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: CurBuildingAnimType, Offset: 0xaba
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: DamageVisualsState, Offset: 0xabb
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: CurBuildProgress, Offset: 0xabc
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OutwardMotionMagnitude, Offset: 0xac0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: CurBuildingAnimStartTime, Offset: 0xac4
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BlueprintMICs, Offset: 0xac8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BlueprintMIDs, Offset: 0xad8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BlueprintMeshComp, Offset: 0xae8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: EditingPlayer, Offset: 0xaf0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BuildingAttachmentPointOffset, Offset: 0xb18
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BuildingAttachmentRadius, Offset: 0xb24
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BuildingAttachmentSlot, Offset: 0xb28
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BuildingAttachmentType, Offset: 0xb29
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BuildingPlacementType, Offset: 0xb2a
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: LastStructuralCheck, Offset: 0xb2b
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: ParentActorToAttachTo, Offset: 0xb30
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: AttachedBuildingActors, Offset: 0xb38
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BuildingActorsAttachedTo, Offset: 0xb48
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: InvalidTrapTagQuery, Offset: 0xb58
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnTrapPlacementChanged, Offset: 0xba0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnReplacementDestruction, Offset: 0xbb0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: AttachmentPlacementBlockingActors, Offset: 0xbc0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: Foundation, Offset: 0xbd0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: DamagerOwner, Offset: 0xbf0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: RelevantBASE, Offset: 0xbf8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: LastRelevantBASE, Offset: 0xc08
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: ProxyGameplayCueDamage, Offset: 0xc28
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: MyGuid, Offset: 0x2f8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: SavedHealthPct, Offset: 0x308
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OwnerPersistentID, Offset: 0x30c
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bUseMinLifeSpan, Offset: 0x30e
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: AreaClass, Offset: 0x310
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: NavigationLinksClass, Offset: 0x338
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: InitialOverlappingVehicles, Offset: 0x350
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: CurrentBuildingLevel, Offset: 0x360
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: MaximumBuildingLevel, Offset: 0x364
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BuildingAttributeSetClass, Offset: 0x368
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BuildingAttributeSet, Offset: 0x370
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: DamageAttributeSet, Offset: 0x378
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: ReplicatedBuildingAttributeSet, Offset: 0x380
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: MaxHealthInitializationValue, Offset: 0x388
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: AttributeInitKeys, Offset: 0x38c
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: AttributeInitLevelSource, Offset: 0x3ac
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: AbilitySystemComponentCreationPolicy, Offset: 0x3ad
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: PrimarySurfaceType, Offset: 0x3ae
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: WeaponResponseType, Offset: 0x3af
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: AbilitySystemComponent, Offset: 0x3c8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: ReplicatedAbilitySystemComponent, Offset: 0x3d0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: PendingDamageImpactCues, Offset: 0x3d8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: HealthBarIndicatorWidth, Offset: 0x3e8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: HealthBarIndicatorVerticalOffset, Offset: 0x3ec
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: HealthBarIndicatorSocketName, Offset: 0x3f0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: HealthBarIndicator, Offset: 0x3f8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: HealthBarIndicatorDifficultyRating, Offset: 0x400
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: ForceMetadataRelevant, Offset: 0x404
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: LastMetadataRelevant, Offset: 0x405
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: DynamicBuildingPlacementType, Offset: 0x406
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: NavigationObstacleOverride, Offset: 0x407
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: IncomingDamageFilterQuery, Offset: 0x408
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bIsInvulnerable, Offset: 0x450
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bPreviewBuildingActor, Offset: 0x450
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bPlayedDying, Offset: 0x450
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bHasRegisteredActorStateAtLeastOnce, Offset: 0x450
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bDirtyForLevelRecordSave, Offset: 0x450
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bSavedMetaPropertiesProcessed, Offset: 0x450
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bUpgradeUsesSameClass, Offset: 0x450
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bDisplayLevelInInfoWidget, Offset: 0x451
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bAllowUpgradeRegardlessOfPlayerBuildLevel, Offset: 0x451
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bAlwaysExportNavRelevantComponent, Offset: 0x451
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bDisplayDamageNumbersInAthena, Offset: 0x451
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bUseFortHealthBarIndicator, Offset: 0x451
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bSurpressHealthBar, Offset: 0x451
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bCreateVerboseHealthLogs, Offset: 0x451
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bIsIndestructibleForTargetSelection, Offset: 0x451
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bPropagateDrawDistanceOnAdditionalComponent, Offset: 0x452
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bCreatePhysicsObjectComponent, Offset: 0x452
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bIsGameFrameworkComponentReceiver, Offset: 0x452
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bDestroyed, Offset: 0x452
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bPersistToWorld, Offset: 0x452
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bRefreshFullSaveDataBeforeZoneSave, Offset: 0x452
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bBeingDragged, Offset: 0x452
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bRotateInPlaceGame, Offset: 0x452
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bBeingOneHitDisassembled, Offset: 0x453
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bBoundsAreInvalidForMelee, Offset: 0x453
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bIsNavigationModifier, Offset: 0x453
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bBlockNavigationLinks, Offset: 0x453
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bCanExportNavigationCollisions, Offset: 0x453
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bCanExportNavigationObstacle, Offset: 0x453
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bMirrorNavLinksX, Offset: 0x453
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bMirrorNavLinksY, Offset: 0x454
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bIgnoreMoveGoalCollisionRadius, Offset: 0x454
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bForceDisableRootNavigationRelevance, Offset: 0x454
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bForceAutomationPass, Offset: 0x454
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bForceAutomationPass_NavmeshOnTop, Offset: 0x454
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bForceAutomationPass_SmashableFlat, Offset: 0x454
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bCanBeSavedInCreativeVolume, Offset: 0x454
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bIsNavigationRelevant, Offset: 0x454
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bIsNavigationIndestructible, Offset: 0x455
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bBlockNavLinksInCell, Offset: 0x455
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bUseHotSpotAsMoveGoalReplacement, Offset: 0x455
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bHasCustomAttackLocation, Offset: 0x455
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bWorldReadyCalled, Offset: 0x455
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bBeingRotatedOrScaled, Offset: 0x455
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bBeingTranslated, Offset: 0x455
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bRotateInPlaceEditor, Offset: 0x455
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bEditorPlaced, Offset: 0x456
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bPlayerPlaced, Offset: 0x456
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bShouldTick, Offset: 0x456
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bUsesDayPhaseChange, Offset: 0x456
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bIsDynamic, Offset: 0x456
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bIsDynamicOnDedicatedServer, Offset: 0x456
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bIsDedicatedServer, Offset: 0x456
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bUseTickManager, Offset: 0x456
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bIsMovable, Offset: 0x457
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bRegisteredForDayPhaseChange, Offset: 0x457
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bForceDamagePing, Offset: 0x457
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bDestroyFoliageWhenPlaced, Offset: 0x457
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bObstructTrapTargeting, Offset: 0x457
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bInstantDeath, Offset: 0x457
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bDoNotBlockBuildings, Offset: 0x457
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bForceBlockBuildings, Offset: 0x458
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bDestroyOnPlayerBuildingPlacement, Offset: 0x458
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bUseCentroidForBlockBuildingsCheck, Offset: 0x458
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bPredictedBuildingActor, Offset: 0x458
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bIgnoreCollisionWithCriticalActors, Offset: 0x458
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bIsPlayerBuildable, Offset: 0x458
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bFireBuiltAndDestroyedEvents, Offset: 0x458
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bStructurallySupportOverlappingActors, Offset: 0x458
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bAllowInteract, Offset: 0x459
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bShowFirstInteractPrompt, Offset: 0x459
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bShowSecondInteractPrompt, Offset: 0x459
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bAllowHostileBlueprintInteraction, Offset: 0x459
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bEndAbilitiesOnDeath, Offset: 0x459
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bAlwaysUseNetCullDistanceSquaredForRelevancy, Offset: 0x459
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bHighlightDirty, Offset: 0x459
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bCollisionBlockedByPawns, Offset: 0x459
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bAllowTeamDamage, Offset: 0x45a
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bShouldClearMarkerOnInteract, Offset: 0x45a
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bIgnoreAffiliationInteractHighlight, Offset: 0x45a
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bSuppressInteractionWidget, Offset: 0x45a
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bAutoReleaseCurieContainerOnDestroyed, Offset: 0x45a
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BuildingType, Offset: 0x45b
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: Team, Offset: 0x45c
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: TeamIndex, Offset: 0x45d
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: ConstTags, Offset: 0x460
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: StaticGameplayTags, Offset: 0x480
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: InteractionText, Offset: 0x4a0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: CanInteractPerformNativeActionTag, Offset: 0x4b8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnDied, Offset: 0x4c0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnDamaged, Offset: 0x4d0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: AssociatedMissionParam, Offset: 0x4e0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OriginatingPlacementActor, Offset: 0x4e8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BRMinDrawDistance, Offset: 0x4f0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BRMaxDrawDistance, Offset: 0x4f4
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: StWMinDrawDistance, Offset: 0x4f8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: StWMaxDrawDistance, Offset: 0x4fc
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnInteract, Offset: 0x500
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: InteractionSpeed, Offset: 0x510
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: DataVersion, Offset: 0x568
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: LastTakeHitTimeTimeout, Offset: 0x56c
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: PlayHitSound, Offset: 0x570
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: CullDistance, Offset: 0x578
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: SnapGridSize, Offset: 0x57c
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: VertSnapGridSize, Offset: 0x580
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: SnapOffset, Offset: 0x584
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: CentroidOffset, Offset: 0x590
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BaseLocToPivotOffset, Offset: 0x59c
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: CustomState, Offset: 0x5a8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: ComponentTypesWhitelistedForReplication, Offset: 0x5b8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OverridePrimitivesToExcludeFoliage, Offset: 0x5c8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: HotSpotConfig, Offset: 0x5d8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnBuildingHealthChanged, Offset: 0x5e0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnActorHealthChanged, Offset: 0x5f0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: SavedActorGuid, Offset: 0x600
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BaselineScale, Offset: 0x610
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: AccumulatedDeltaSinceLastVisualsTick, Offset: 0x614
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: ProjectileMovementComponent, Offset: 0x618
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnTeamIndexChangedDelegate, Offset: 0x620
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: LifespanAfterDeath, Offset: 0x630
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: PhysicsObjectPresetTag, Offset: 0x634
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: PhysicsObjectPhysicalDataTag, Offset: 0x63c
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: PhysicsObjectBuoyancyDataTag, Offset: 0x644
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: PhysicsObjectImpactDamageDataTag, Offset: 0x64c
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bIgnoreDeterminePhysicsObjectImpactDataAutomatically, Offset: 0x654
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: PhysicsObjectComponent, Offset: 0x658
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: ActorTemplateID, Offset: 0x660
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: PlaysetPackagePathName, Offset: 0x664
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: PrimaryActorTick, Offset: 0x28
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bNetTemporary, Offset: 0x58
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bNetStartup, Offset: 0x58
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bOnlyRelevantToOwner, Offset: 0x58
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bAlwaysRelevant, Offset: 0x58
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bReplicateMovement, Offset: 0x58
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bCallPreReplication, Offset: 0x58
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bCallPreReplicationForReplay, Offset: 0x58
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bHidden, Offset: 0x58
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bTearOff, Offset: 0x59
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bForceNetAddressable, Offset: 0x59
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bExchangedRoles, Offset: 0x59
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bNetLoadOnClient, Offset: 0x59
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bNetUseOwnerRelevancy, Offset: 0x59
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bRelevantForNetworkReplays, Offset: 0x59
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bRelevantForLevelBounds, Offset: 0x59
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bReplayRewindable, Offset: 0x59
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bAllowTickBeforeBeginPlay, Offset: 0x5a
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bAutoDestroyWhenFinished, Offset: 0x5a
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bCanBeDamaged, Offset: 0x5a
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bBlockInput, Offset: 0x5a
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bCollideWhenPlacing, Offset: 0x5a
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bFindCameraComponentWhenViewTarget, Offset: 0x5a
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bGenerateOverlapEventsDuringLevelStreaming, Offset: 0x5a
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bIgnoresOriginShifting, Offset: 0x5a
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bEnableAutoLODGeneration, Offset: 0x5b
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bIsEditorOnlyActor, Offset: 0x5b
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bActorSeamlessTraveled, Offset: 0x5b
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bReplicates, Offset: 0x5b
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bCanBeInCluster, Offset: 0x5b
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bAllowReceiveTickEventOnDedicatedServer, Offset: 0x5b
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bActorEnableCollision, Offset: 0x5c
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: bActorIsBeingDestroyed, Offset: 0x5c
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: UpdateOverlapsMethodDuringLevelStreaming, Offset: 0x5e
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: DefaultUpdateOverlapsMethodDuringLevelStreaming, Offset: 0x5f
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: RemoteRole, Offset: 0x60
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: ReplicatedMovement, Offset: 0x64
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: InitialLifeSpan, Offset: 0x98
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: CustomTimeDilation, Offset: 0x9c
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: AttachmentReplication, Offset: 0xa8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: Owner, Offset: 0xe8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: NetDriverName, Offset: 0xf0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: Role, Offset: 0xf8
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: NetDormancy, Offset: 0xf9
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: SpawnCollisionHandlingMethod, Offset: 0xfa
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: AutoReceiveInput, Offset: 0xfb
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: InputPriority, Offset: 0xfc
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: InputComponent, Offset: 0x100
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: NetCullDistanceSquared, Offset: 0x108
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: NetTag, Offset: 0x10c
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: NetUpdateFrequency, Offset: 0x110
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: MinNetUpdateFrequency, Offset: 0x114
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: NetPriority, Offset: 0x118
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: Instigator, Offset: 0x120
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: Children, Offset: 0x128
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: RootComponent, Offset: 0x138
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: RayTracingGroupId, Offset: 0x148
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: Layers, Offset: 0x150
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: ParentComponent, Offset: 0x160
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: Tags, Offset: 0x170
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnTakeAnyDamage, Offset: 0x180
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnTakePointDamage, Offset: 0x181
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnTakeRadialDamage, Offset: 0x182
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnActorBeginOverlap, Offset: 0x183
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnActorEndOverlap, Offset: 0x184
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnBeginCursorOver, Offset: 0x185
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnEndCursorOver, Offset: 0x186
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnClicked, Offset: 0x187
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnReleased, Offset: 0x188
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnInputTouchBegin, Offset: 0x189
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnInputTouchEnd, Offset: 0x18a
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnInputTouchEnter, Offset: 0x18b
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnInputTouchLeave, Offset: 0x18c
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnActorHit, Offset: 0x18d
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnDestroyed, Offset: 0x18e
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: OnEndPlay, Offset: 0x18f
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: InstanceComponents, Offset: 0x1f0
			HalalGS-19.10: LogInit: Info: ChildProperties->Name: BlueprintCreatedComponents, Offset: 0x200
		*/

		ABuildingProp_ConversationCompatible;

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