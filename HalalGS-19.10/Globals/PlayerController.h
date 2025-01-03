#pragma once

namespace PlayerController
{
	void (*ServerAttemptInteractOG)(UFortControllerComponent_Interaction* ControllerComponent_Interaction, AActor* ReceivingActor, UPrimitiveComponent* InteractComponent, ETInteractionType InteractType, UObject* OptionalObjectData, EInteractionBeingAttempted InteractionBeingAttempted, int32 RequestID);
	void (*ModLoadedAmmoOG)(void* InventoryOwner, const FGuid& ItemGuid, int32 NewLoadedAmmo);
	void (*ServerReadyToStartMatchOG)(AFortPlayerController* PlayerController);
	void (*ServerReturnToMainMenuOG)(AFortPlayerController* PlayerController);
	void (*GetPlayerViewPointOG)(APlayerController* PlayerController, FVector& out_Location, FRotator& out_Rotation);

	void ServerReadyToStartMatch(AFortPlayerController* PlayerController)
	{
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
				//NewItemEntry.ItemGuid = WorldItem->ItemEntry.ItemGuid;
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

			FFortCreatePickupData* (*CreatePickupData)(FFortCreatePickupData* PickupData, UWorld* World, FFortItemEntry ItemEntry, FVector SpawnLocation, FRotator SpawnRotation, AFortPlayerController* PlayerController, UClass* OverrideClass, AActor* Investigator, int a9, int a10) = decltype(CreatePickupData)(0x64da9dc + uintptr_t(GetModuleHandle(0)));

			FFortCreatePickupData PickupData;
			CreatePickupData(&PickupData, Globals::GetWorld(), NewItemEntry, SpawnLocation, FRotator(), nullptr, AFortPickupAthena::StaticClass(), nullptr, 0, 0);

			PickupData.PickupSourceTypeFlags = EFortPickupSourceTypeFlag::Player;
			PickupData.PickupSpawnSource = EFortPickupSpawnSource::TossedByPlayer;

			AFortPickup* (*CreatePickupFromData)(FFortCreatePickupData* PickupData) = decltype(CreatePickupFromData)(0x64dd1b4 + uintptr_t(GetModuleHandle(0)));
			AFortPickup* Pickup = CreatePickupFromData(&PickupData);

			NewItemEntry.FreeItemEntry();

			if (Pickup)
			{
				FRotator PlayerRotation = PlayerPawn->K2_GetActorRotation();
				PlayerRotation.Yaw += UKismetMathLibrary::RandomFloatInRange(-60.0f, 60.0f);

				float RandomDistance = UKismetMathLibrary::RandomFloatInRange(500.0f, 600.0f);
				FVector FinalDirection = UKismetMathLibrary::GetForwardVector(PlayerRotation);

				FVector FinalLocation = SpawnLocation + FinalDirection * RandomDistance;

				Pickup->PawnWhoDroppedPickup = PlayerPawn;
				Pickup->bCombinePickupsWhenTossCompletes = true;
				Pickup->TossPickup(FinalLocation, PlayerPawn, 0, true, true, EFortPickupSourceTypeFlag::Player, EFortPickupSpawnSource::Unset);
			}

			EWorldItemDropBehavior DropBehavior = WorldItemDefinition->DropBehavior;

			switch (DropBehavior)
			{
			case EWorldItemDropBehavior::DropAsPickup:

				break;
			case EWorldItemDropBehavior::DestroyOnDrop:
				if (Pickup)
				{
					Pickup->ForceNetUpdate();
					Pickup->K2_DestroyActor();
				}
				break;
			case EWorldItemDropBehavior::DropAsPickupDestroyOnEmpty:

				break;
			default:
				break;
			}
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

		int32 MaxStackSize = UFortScalableFloatUtils::GetValueAtLevel(TargetItemDefinition->MaxStackSize, 0);

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
				BuildingClass = PlayerControllerAthena->BroadcastRemoteClientInfo->RemoteBuildableClass;
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

	void ServerCreateBuildingActor(AFortPlayerController* PlayerController, FCreateBuildingActorData CreateBuildingData)
	{
		UWorld* World = PlayerController->GetWorld();

		if (!CheckCreateBuildingActor(PlayerController, CreateBuildingData.BuildingClassData) || !World)
			return;

		UClass* BuildingClass = CreateBuildingData.BuildingClassData.BuildingClass.Get();

		if (!BuildingClass)
		{
			AFortPlayerControllerAthena* PlayerControllerAthena = Cast<AFortPlayerControllerAthena>(PlayerController);

			if (PlayerControllerAthena)
				BuildingClass = PlayerControllerAthena->BroadcastRemoteClientInfo->RemoteBuildableClass;
		}

		TArray<ABuildingActor*> ExistingBuildings;
		EFortBuildPreviewMarkerOptionalAdjustment MarkerOptionalAdjustment;
		EFortStructuralGridQueryResults GridQueryResults = PlayerController->CanPlaceBuilableClassInStructuralGrid(BuildingClass, CreateBuildingData.BuildLoc, CreateBuildingData.BuildRot, CreateBuildingData.bMirrored, &ExistingBuildings, &MarkerOptionalAdjustment);

		if (GridQueryResults == EFortStructuralGridQueryResults::CanAdd)
		{
			for (int32 i = 0; i < ExistingBuildings.Num(); i++)
			{
				ABuildingActor* ExistingBuilding = ExistingBuildings[i];
				if (!ExistingBuilding) continue;

				ExistingBuilding->K2_DestroyActor();
			}

			ABuildingSMActor* BuildingSMActor = Cast<ABuildingSMActor>(World->SpawnActor(BuildingClass, &CreateBuildingData.BuildLoc, &CreateBuildingData.BuildRot));
			if (!BuildingSMActor) return;

			BuildingSMActor->CurrentBuildingLevel = CreateBuildingData.BuildingClassData.UpgradeLevel;

			// PlayerController->PayBuildingCosts(CreateBuildingData.BuildingClassData);

			BuildingSMActor->InitializeKismetSpawnedBuildingActor(BuildingSMActor, PlayerController, true, nullptr);
			BuildingSMActor->bPlayerPlaced = true;

			AFortPlayerStateAthena* PlayerStateAthena = Cast<AFortPlayerStateAthena>(PlayerController->PlayerState);

			if (PlayerStateAthena)
			{
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

	void ServerPlayEmoteItem(AFortPlayerController* PlayerController, const UFortMontageItemDefinitionBase* EmoteAsset, float EmoteRandomNumber)
	{

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

				PlayerControllerAthena->SetControlRotation(ClientRotation);

				UFortAbilitySystemComponent* AbilitySystemComponent = PlayerStateAthena->AbilitySystemComponent;

				if (AbilitySystemComponent)
				{
					for (int32 i = 0; i < AbilitySystemComponent->ActiveGameplayEffects.GameplayEffects_Internal.Num(); i++)
					{
						FActiveGameplayEffect ActiveGameplayEffect = AbilitySystemComponent->ActiveGameplayEffects.GameplayEffects_Internal[i];
						if (!ActiveGameplayEffect.Spec.Def) continue;

						if (ActiveGameplayEffect.Spec.Def->IsA(UGE_OutsideSafeZoneDamage_C::StaticClass()))
							AbilitySystemComponent->RemoveActiveGameplayEffect(ActiveGameplayEffect.Handle, 1);
					}
				}
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

		FN_LOG(LogInit, Log, "ServerAttemptInteract called!");
		
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

			if (WeaponRangedItemDefinition && WeaponRangedItemDefinition->bPersistInInventoryWhenFinalStackEmpty)
			{
				int32 ItemQuantity = UFortKismetLibrary::K2_GetItemQuantityOnPlayer(PlayerController, WeaponRangedItemDefinition, FGuid());

				if (ItemQuantity == 1)
				{
					Inventory::ModifyCountItem(PlayerController->WorldInventory, ItemGuid, 0);
					return true;
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

	void InitPlayerController()
	{
		AFortPlayerControllerAthena* FortPlayerControllerAthenaDefault = AFortPlayerControllerAthena::GetDefaultObj();
		UFortControllerComponent_Aircraft* FortControllerComponent_AircraftDefault = UFortControllerComponent_Aircraft::GetDefaultObj();
		UFortControllerComponent_Interaction* FortControllerComponent_InteractionDefault = UFortControllerComponent_Interaction::GetDefaultObj();
		UObject* InventoryOwnerDefault = (UObject*)FortPlayerControllerAthenaDefault->GetInventoryOwner();

		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1460 / 8, ServerReadyToStartMatch, (LPVOID*)(&ServerReadyToStartMatchOG), "AFortPlayerController::ServerReadyToStartMatch");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x11D0 / 8, ServerAttemptInventoryDrop, nullptr, "AFortPlayerController::ServerAttemptInventoryDrop");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x11E0 / 8, ServerCombineInventoryItems, nullptr, "AFortPlayerController::ServerCombineInventoryItems");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1268 / 8, ServerCreateBuildingActor, nullptr, "AFortPlayerController::ServerCreateBuildingActor");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1248 / 8, ServerRepairBuildingActor, nullptr, "AFortPlayerController::ServerRepairBuildingActor");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x12A0 / 8, ServerBeginEditingBuildingActor, nullptr, "AFortPlayerController::ServerBeginEditingBuildingActor");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1278 / 8, ServerEditBuildingActor, nullptr, "AFortPlayerController::ServerEditBuildingActor");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1290 / 8, ServerEndEditingBuildingActor, nullptr, "AFortPlayerController::ServerEndEditingBuildingActor");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1160 / 8, ServerExecuteInventoryItem, nullptr, "AFortPlayerController::ServerExecuteInventoryItem");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0xF40 / 8, ServerPlayEmoteItem, nullptr, "AFortPlayerController::ServerPlayEmoteItem");
		MinHook::HookVTable(FortControllerComponent_AircraftDefault, 0x4F0 / 8, ServerAttemptAircraftJump, nullptr, "UFortControllerComponent_Aircraft::ServerAttemptAircraftJump");
		MinHook::HookVTable(FortControllerComponent_InteractionDefault, 0x500 / 8, ServerAttemptInteract, (LPVOID*)(&ServerAttemptInteractOG), "UFortControllerComponent_Interaction::ServerAttemptInteract");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1440 / 8, ServerReturnToMainMenu, (LPVOID*)(&ServerReturnToMainMenuOG), "AFortPlayerController::ServerReturnToMainMenu");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x14C0 / 8, ServerSuicide, nullptr, "AFortPlayerController::ServerSuicide");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x910 / 8, ServerAcknowledgePossession, nullptr, "APlayerController::ServerAcknowledgePossession");

		MinHook::HookVTable(InventoryOwnerDefault, 0xA8 / 8, ModLoadedAmmo, (LPVOID*)(&ModLoadedAmmoOG), "ModLoadedAmmo");

		uintptr_t AddressRemoveInventoryItem = MinHook::FindPattern(Patterns::RemoveInventoryItem);
		uintptr_t AddressGetPlayerViewPoint = MinHook::FindPattern(Patterns::GetPlayerViewPoint);

		MH_CreateHook((LPVOID)(AddressRemoveInventoryItem), RemoveInventoryItem, nullptr);
		MH_EnableHook((LPVOID)(AddressRemoveInventoryItem));
		MH_CreateHook((LPVOID)(AddressGetPlayerViewPoint), GetPlayerViewPoint, (LPVOID*)(&GetPlayerViewPointOG));
		MH_EnableHook((LPVOID)(AddressGetPlayerViewPoint));

		FN_LOG(LogInit, Log, "InitPlayerController Success!");
	}
}