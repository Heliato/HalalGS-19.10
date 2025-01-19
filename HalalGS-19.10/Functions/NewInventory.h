#pragma once

// 0x01E0 (0x01E0 - 0x0000)
struct FFortCreatePickupData final
{
public:
	class UWorld*								  World;					                         // 0x0000(0x0008)()
	struct FFortItemEntry						  ItemEntry;									     // 0x0008(0x01A0)()
	struct FVector								  SpawnLocation;									 // 0x01A8(0x000C)()
	struct FRotator								  SpawnRotation;                                     // 0x01B4(0x000C)()
	TWeakObjectPtr<AFortPlayerController>         WeakPlayerController;							     // 0x01C0(0x0008)()
	class UClass*								  OverrideClass;									 // 0x01C8(0x0008)()
	TWeakObjectPtr<AActor>						  WeakInvestigator;									 // 0x01D0(0x0008)()
	EFortPickupSourceTypeFlag                     PickupSourceTypeFlags;							 // 0x01D8(0x0001)()
	EFortPickupSpawnSource                        PickupSpawnSource;                                 // 0x01D9(0x0001)()
	uint8                                         bRandomRotation : 1;                               // 0x01DA(0x0001)(BitIndex: 0x00)
	uint8                                         BitPad_1DA_1 : 1;									 // 0x01DA(0x0001)(BitIndex: 0x01)
};

namespace Inventory
{
	bool (*SetStateValue)(FFortItemEntry* ItemEntry, EFortItemEntryState StateType, int32 IntValue);

	// The function is compiled in another function... We have to redo it
	int32 GetItemLevel(const FDataTableCategoryHandle& ItemLevelDataHandle)
	{
		UDataTable* DataTable = ItemLevelDataHandle.DataTable;
		AFortGameState* GameState = Globals::GetGameState();

		if (!DataTable || !GameState)
			return 0;

		if (!ItemLevelDataHandle.ColumnName.IsValid() || !ItemLevelDataHandle.RowContents.IsValid())
			return 0;

		TArray<FFortLootLevelData*> MatchingLootLevelData;

		for (auto& DataPair : DataTable->GetRowMap<FFortLootLevelData>())
		{
			if (DataPair.Second->Category != ItemLevelDataHandle.RowContents)
				continue;

			MatchingLootLevelData.Add(DataPair.Second);
		}

		if (!MatchingLootLevelData.IsValid())
		{
			int32 SelectedIndex = -1;
			int32 HighestLootLevel = 0;

			for (int32 i = 0; i < MatchingLootLevelData.Num(); ++i)
			{
				FFortLootLevelData* CurrentData = MatchingLootLevelData[i];

				if (CurrentData->LootLevel <= GameState->WorldLevel && CurrentData->LootLevel > HighestLootLevel)
				{
					HighestLootLevel = CurrentData->LootLevel;
					SelectedIndex = i;
				}
			}

			if (SelectedIndex != -1)
			{
				FFortLootLevelData* SelectedData = MatchingLootLevelData[SelectedIndex];

				const int32 MinItemLevel = SelectedData->MinItemLevel;
				const int32 MaxItemLevel = SelectedData->MaxItemLevel;

				int32 LevelRange = MaxItemLevel - MinItemLevel;

				if (LevelRange + 1 <= 0)
				{
					LevelRange = 0;
				}
				else
				{
					const int32 RandomValue = (int32)(float)((float)((float)rand() * 0.000030518509) * (float)(LevelRange + 1));

					if (RandomValue <= LevelRange)
						LevelRange = RandomValue;
				}

				return LevelRange + MinItemLevel;
			}
		}

		if (MatchingLootLevelData.Num() > 0)
			MatchingLootLevelData.Free();

		return 0;
	}

	FFortBaseWeaponStats* GetWeaponStats(UFortWeaponItemDefinition* ItemDefinition)
	{
		if (!ItemDefinition)
			return nullptr;

		if (ItemDefinition->IsA(UFortAmmoItemDefinition::StaticClass()) ||
			ItemDefinition->IsA(UFortResourceItemDefinition::StaticClass()) ||
			ItemDefinition->IsA(UFortIngredientItemDefinition::StaticClass()))
			return nullptr;

		FDataTableRowHandle* WeaponStatHandle = &ItemDefinition->WeaponStatHandle;

		if (!WeaponStatHandle)
			return nullptr;

		return Globals::GetDataTableRowFromName<FFortBaseWeaponStats>(WeaponStatHandle->DataTable, WeaponStatHandle->RowName);
	}

	void MakeItemEntry(FFortItemEntry* ItemEntry, UFortItemDefinition* ItemDefinition, int32 Count, int32 Level, int32 LoadedAmmo, float Durability)
	{
		if (!ItemEntry || !ItemDefinition)
			return;
		
		ItemEntry->CreateDefaultItemEntry(ItemDefinition, Count, Level);

		UFortWorldItemDefinition* WorldItemDefinition = Cast<UFortWorldItemDefinition>(ItemDefinition);

		if (WorldItemDefinition)
		{
			int32 ItemLevel = GetItemLevel(WorldItemDefinition->LootLevelData);

			ItemEntry->Level = (Level == -1) ? ItemLevel : Level;
			ItemEntry->Durability = (Durability == -1.0f) ? WorldItemDefinition->GetMaxDurability(ItemLevel) : Durability;

			UFortWeaponItemDefinition* WeaponItemDefinition = Cast<UFortWeaponItemDefinition>(WorldItemDefinition);

			if (WeaponItemDefinition)
			{
				FFortBaseWeaponStats* BaseWeaponStats = GetWeaponStats(WeaponItemDefinition);

				int32 (*GetWeaponClipSize)(UFortWeaponItemDefinition* WeaponItemDefinition, int32 WeaponLevel) = decltype(GetWeaponClipSize)(0x21da37c + uintptr_t(GetModuleHandle(0)));
				int32 WeaponClipSize = GetWeaponClipSize(WeaponItemDefinition, ItemLevel);
					
				if (WeaponItemDefinition->bUsesPhantomReserveAmmo)
				{
					ItemEntry->PhantomReserveAmmo = (WeaponClipSize - BaseWeaponStats->ClipSize);
					ItemEntry->LoadedAmmo = BaseWeaponStats ? BaseWeaponStats->ClipSize : 0;
				}
				else
					ItemEntry->LoadedAmmo = WeaponClipSize;
			}
		}
	}

	void ModifyCountItem(AFortInventory* Inventory, const FGuid& ItemGuid, int32 NewCount)
	{
		if (!Inventory)
			return;

		for (int32 i = 0; i < Inventory->Inventory.ItemInstances.Num(); i++)
		{
			UFortWorldItem* ItemInstance = Inventory->Inventory.ItemInstances[i];
			if (!ItemInstance) continue;

			FFortItemEntry* ItemEntry = &Inventory->Inventory.ItemInstances[i]->ItemEntry;

			if (ItemEntry->ItemGuid == ItemGuid)
			{
				ItemEntry->SetCount(NewCount);
				break;
			}
		}

		// I think that normally you don't need to modify the value here but for me it doesn't work idk
		for (int32 i = 0; i < Inventory->Inventory.ReplicatedEntries.Num(); i++)
		{
			FFortItemEntry* ReplicatedItemEntry = &Inventory->Inventory.ReplicatedEntries[i];

			if (ReplicatedItemEntry->ItemGuid == ItemGuid)
			{
				ReplicatedItemEntry->Count = NewCount;
				Inventory->Inventory.MarkItemDirty(*ReplicatedItemEntry);
				break;
			}
		}
	}

	void ModifyLoadedAmmoItem(AFortInventory* Inventory, const FGuid& ItemGuid, int32 NewLoadedAmmo)
	{
		if (!Inventory)
			return;

		for (int32 i = 0; i < Inventory->Inventory.ItemInstances.Num(); i++)
		{
			UFortWorldItem* ItemInstance = Inventory->Inventory.ItemInstances[i];
			if (!ItemInstance) continue;

			FFortItemEntry* ItemEntry = &Inventory->Inventory.ItemInstances[i]->ItemEntry;

			if (ItemEntry->ItemGuid == ItemGuid)
			{
				ItemEntry->SetLoadedAmmo(NewLoadedAmmo);
				break;
			}
		}

		// I think that normally you don't need to modify the value here but for me it doesn't work idk
		for (int32 i = 0; i < Inventory->Inventory.ReplicatedEntries.Num(); i++)
		{
			FFortItemEntry* ReplicatedItemEntry = &Inventory->Inventory.ReplicatedEntries[i];

			if (ReplicatedItemEntry->ItemGuid == ItemGuid)
			{
				ReplicatedItemEntry->LoadedAmmo = NewLoadedAmmo;
				Inventory->Inventory.MarkItemDirty(*ReplicatedItemEntry);
				break;
			}
		}
	}

	bool IsInventoryFull(AFortInventory* Inventory)
	{
		if (!Inventory)
			return false;

		AFortPlayerController* PlayerController = Cast<AFortPlayerController>(Inventory->Owner);
		if (!PlayerController) return false;

		int32 (*GetInventoryCapacity)(void* InventoryOwnerInterfaceAddress, EFortInventoryType InventoryType) = decltype(GetInventoryCapacity)(0x64cbc0c + uintptr_t(GetModuleHandle(0)));
		int32 InventoryCapacity = GetInventoryCapacity(PlayerController->GetInventoryOwner(), Inventory->InventoryType);

		int32 (*GetInventorySize)(void* InventoryOwnerInterfaceAddress, EFortInventoryType InventoryType) = decltype(GetInventorySize)(0x64cc020 + uintptr_t(GetModuleHandle(0)));
		int32 InventorySize = GetInventorySize(PlayerController->GetInventoryOwner(), Inventory->InventoryType);

		return (InventorySize >= InventoryCapacity);
	}

	UFortWorldItem* AddItem(AFortInventory* Inventory, FFortItemEntry ItemEntry)
	{
		if (!Inventory || !Inventory->Owner)
			return nullptr;

		UFortWorldItem* WorldItem = Cast<UFortWorldItem>(ItemEntry.ItemDefinition->CreateTemporaryItemInstanceBP(ItemEntry.Count, ItemEntry.Level));
		FFortItemEntry* WorldItemEntry = &WorldItem->ItemEntry;

		WorldItemEntry->CopyItemEntryWithReset(&ItemEntry);

		AFortPlayerController* PlayerController = Cast<AFortPlayerController>(Inventory->Owner);

		WorldItem->SetOwningControllerForTemporaryItem(PlayerController);

		Inventory->AddWorldItem(WorldItem);

		return WorldItem;
	}

	void RemoveItem(AFortInventory* Inventory, const FGuid& ItemGuid)
	{
		if (!Inventory)
			return;

		AFortPlayerController* PlayerController = Cast<AFortPlayerController>(Inventory->Owner);

		if (!PlayerController)
			return;

		UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->BP_GetInventoryItemWithGuid(ItemGuid));

		if (!WorldItem)
			return;

		Inventory->RecentlyRemoved.Add(WorldItem);

		for (int32 i = 0; i < Inventory->Inventory.ItemInstances.Num(); i++)
		{
			UFortWorldItem* ItemInstance = Inventory->Inventory.ItemInstances[i];
			if (!ItemInstance) continue;

			FFortItemEntry* ItemEntry = &Inventory->Inventory.ItemInstances[i]->ItemEntry;
			if (!ItemEntry) continue;

			if (ItemEntry->ItemGuid == ItemGuid)
			{
				ItemEntry->FreeItemEntry();
				Inventory->Inventory.ItemInstances.Remove(i);
				break;
			}
		}

		for (int32 i = 0; i < Inventory->Inventory.ReplicatedEntries.Num(); i++)
		{
			FFortItemEntry* ReplicatedItemEntry = &Inventory->Inventory.ReplicatedEntries[i];
			if (!ReplicatedItemEntry) continue;

			if (ReplicatedItemEntry->ItemGuid == ItemGuid)
			{
				ReplicatedItemEntry->FreeItemEntry();
				Inventory->Inventory.ReplicatedEntries.Remove(i);
				break;
			}
		}

		Inventory->Inventory.MarkArrayDirty();
		Inventory->HandleInventoryLocalUpdate();
	}

	void ResetInventory(AFortInventory* Inventory, bool bRemoveAll = true)
	{
		if (!Inventory)
			return;

		if (bRemoveAll)
		{
			if (Inventory->Inventory.ItemInstances.IsValid())
				Inventory->Inventory.ItemInstances.Free();

			if (Inventory->Inventory.ReplicatedEntries.IsValid())
				Inventory->Inventory.ReplicatedEntries.Free();

			Inventory->Inventory.MarkArrayDirty();
			Inventory->HandleInventoryLocalUpdate();
		}
		else
		{
			TArray<FGuid> ItemGuidToRemoves;

			for (int32 i = 0; i < Inventory->Inventory.ItemInstances.Num(); i++)
			{
				UFortWorldItem* ItemInstance = Inventory->Inventory.ItemInstances[i];
				if (!ItemInstance) continue;

				FFortItemEntry* ItemEntry = &ItemInstance->ItemEntry;
				if (!ItemEntry) continue;

				UFortWorldItemDefinition* ItemDefinition = Cast<UFortWorldItemDefinition>(ItemEntry->ItemDefinition);
				if (!ItemDefinition) continue;

				if (!ItemDefinition->bCanBeDropped)
					continue;

				ItemGuidToRemoves.Add(ItemEntry->ItemGuid);
			}

			for (int32 i = 0; i < ItemGuidToRemoves.Num(); i++)
				Inventory::RemoveItem(Inventory, ItemGuidToRemoves[i]);
		}
	}

	AFortPickup* GetClosestPickup(AFortPickup* PickupToCombine, float MaxDistance)
	{
		if (!PickupToCombine)
			return nullptr;

		UFortWorldItemDefinition* WorldItemDefinitionCombine = Cast<UFortWorldItemDefinition>(PickupToCombine->PrimaryPickupItemEntry.ItemDefinition);

		if (WorldItemDefinitionCombine)
		{
			TArray<AActor*> Actors;
			UGameplayStatics::GetAllActorsOfClass(PickupToCombine, AFortPickup::StaticClass(), &Actors);

			AFortPickup* ClosestPickup = nullptr;

			for (int32 i = 0; i < Actors.Num(); i++)
			{
				AFortPickup* Pickup = Cast<AFortPickup>(Actors[i]);
				if (!Pickup) continue;

				if (Pickup->bActorIsBeingDestroyed || Pickup->bPickedUp)
					continue;

				if (Pickup == PickupToCombine)
					continue;

				const float Distance = PickupToCombine->GetDistanceTo(Pickup);

				if (Distance > MaxDistance)
					continue;

				if (Pickup->PickupLocationData.CombineTarget)
					continue;

				FFortItemEntry* PrimaryPickupItemEntry = &Pickup->PrimaryPickupItemEntry;
				if (!PrimaryPickupItemEntry) continue;

				UFortWorldItemDefinition* WorldItemDefinition = Cast<UFortWorldItemDefinition>(PrimaryPickupItemEntry->ItemDefinition);
				if (!WorldItemDefinition) continue;

				if (WorldItemDefinition != WorldItemDefinitionCombine)
					continue;

				if (PrimaryPickupItemEntry->Count >= WorldItemDefinition->MaxStackSize.GetValueAtLevel(0))
					continue;

				ClosestPickup = Pickup;
				break;
			}

			if (Actors.IsValid())
				Actors.Free();

			return ClosestPickup;
		}

		return nullptr;
	}

	bool CombineNearestPickup(AFortPickup* PickupToCombine, float MaxDistance)
	{
		if (!PickupToCombine)
			return false;

		AFortPickup* ClosestPickup = Inventory::GetClosestPickup(PickupToCombine, MaxDistance);

		if (ClosestPickup)
		{
			PickupToCombine->PickupLocationData.CombineTarget = ClosestPickup;
			PickupToCombine->PickupLocationData.FlyTime = 0.25f;
			PickupToCombine->PickupLocationData.LootFinalPosition = (FVector_NetQuantize10)ClosestPickup->K2_GetActorLocation();
			PickupToCombine->PickupLocationData.LootInitialPosition = (FVector_NetQuantize10)PickupToCombine->K2_GetActorLocation();
			PickupToCombine->PickupLocationData.FinalTossRestLocation = (FVector_NetQuantize10)ClosestPickup->K2_GetActorLocation();

			PickupToCombine->OnRep_PickupLocationData();
			PickupToCombine->FlushNetDormancy();

			// Use to call a CombinePickup function with delay
			UKismetSystemLibrary::K2_SetTimer(PickupToCombine, L"OnRep_ServerImpactSoundFlash", PickupToCombine->PickupLocationData.FlyTime, false, false, false);

			return true;
		}

		return false;
	}

	AFortPickup* SpawnPickup(AFortPawn* ItemOwner, FFortItemEntry ItemEntry, FVector SpawnLocation, FVector FinalLocation, int32 OverrideMaxStackCount = 0, bool bToss = true, bool bShouldCombinePickupsWhenTossCompletes = true, const EFortPickupSourceTypeFlag InPickupSourceTypeFlags = EFortPickupSourceTypeFlag::Other, const EFortPickupSpawnSource InPickupSpawnSource = EFortPickupSpawnSource::Unset)
	{
		ItemEntry.SetParentInventory(nullptr, false);

		FFortCreatePickupData* (*CreatePickupData)(FFortCreatePickupData* PickupData, UWorld* World, FFortItemEntry ItemEntry, FVector SpawnLocation, FRotator SpawnRotation, AFortPlayerController* PlayerController, UClass* OverrideClass, AActor* Investigator, int a9, int a10) = decltype(CreatePickupData)(0x64da9dc + uintptr_t(GetModuleHandle(0)));

		FFortCreatePickupData PickupData;
		CreatePickupData(&PickupData, Globals::GetWorld(), ItemEntry, SpawnLocation, FRotator(), nullptr, AFortPickupAthena::StaticClass(), nullptr, 0, 0);

		PickupData.PickupSourceTypeFlags = InPickupSourceTypeFlags;
		PickupData.PickupSpawnSource = InPickupSpawnSource;

		AFortPickup* (*CreatePickupFromData)(FFortCreatePickupData* PickupData) = decltype(CreatePickupFromData)(0x64dd1b4 + uintptr_t(GetModuleHandle(0)));
		AFortPickup* Pickup = CreatePickupFromData(&PickupData);

		if (Pickup)
		{
			if (ItemOwner)
				Pickup->PawnWhoDroppedPickup = ItemOwner;

			Pickup->TossPickup(
				FinalLocation,
				ItemOwner,
				OverrideMaxStackCount,
				bToss,
				bShouldCombinePickupsWhenTossCompletes,
				InPickupSourceTypeFlags,
				InPickupSpawnSource
			);
		}

		return Pickup;
	}

	UFortWorldItem* AddInventoryItem(AFortPlayerController* PlayerController, FFortItemEntry ItemEntry, FGuid CurrentItemGuid = FGuid(), bool bReplaceWeapon = true)
	{
		if (!PlayerController || !PlayerController->WorldInventory || !ItemEntry.ItemDefinition)
			return nullptr;

		if (ItemEntry.Count <= 0)
			return nullptr;

		TArray<UFortItem*> ItemArray;
		PlayerController->BP_FindItemInstancesFromDefinition(ItemEntry.ItemDefinition, FGuid(), ItemArray);

		if (ItemArray.Num() > 0)
		{
			int32 ItemCountToAdd = ItemEntry.Count;

			for (int32 i = 0; i < ItemArray.Num(); i++)
			{
				UFortWorldItem* WorldItem = Cast<UFortWorldItem>(ItemArray[i]);
				if (!WorldItem) continue;

				UFortItemDefinition* ItemDefinition = WorldItem->ItemEntry.ItemDefinition;
				if (!ItemDefinition) continue;

				int32 CurrentCount = WorldItem->ItemEntry.Count;
				int32 MaxStackSize = ItemDefinition->MaxStackSize.GetValueAtLevel(0);

				if (CurrentCount < MaxStackSize)
				{
					int32 NewCount = UKismetMathLibrary::Min(CurrentCount + ItemCountToAdd, MaxStackSize);

					ModifyCountItem(PlayerController->WorldInventory, WorldItem->ItemEntry.ItemGuid, NewCount);

					ItemCountToAdd -= (NewCount - CurrentCount);

					if (ItemCountToAdd <= 0)
						return WorldItem; // A tester
				}
			}

			if (ItemCountToAdd < 0)
				ItemCountToAdd = 0;

			ItemEntry.Count = ItemCountToAdd;
		}

		if (ItemEntry.Count <= 0)
			return nullptr;

		UFortWorldItemDefinition* WorldItemDefinition = Cast<UFortWorldItemDefinition>(ItemEntry.ItemDefinition);

		if (!WorldItemDefinition)
			return nullptr;

		int32 MaxStackSize = WorldItemDefinition->MaxStackSize.GetValueAtLevel(0);

		if (ItemEntry.Count > MaxStackSize)
		{
			while (ItemEntry.Count > 0)
			{
				int32 NewCount = UKismetMathLibrary::Min(ItemEntry.Count, MaxStackSize);

				FFortItemEntry NewItemEntry;
				MakeItemEntry(&NewItemEntry, WorldItemDefinition, NewCount, ItemEntry.Level, ItemEntry.LoadedAmmo, ItemEntry.Durability);

				AddInventoryItem(PlayerController, NewItemEntry, CurrentItemGuid, false);

				ItemEntry.Count -= NewCount;
			}

			return nullptr;
		}

		FVector SpawnLocation = FVector({ 0, 0, 0 });
		FVector FinalLocation = FVector({ 0, 0, 0 });

		AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;

		if (PlayerPawn)
		{
			SpawnLocation = PlayerPawn->K2_GetActorLocation();

			SpawnLocation.Z += 40.0f;

			float RandomAngle = UKismetMathLibrary::RandomFloatInRange(-60.0f, 60.0f);

			FRotator RandomRotation = PlayerPawn->K2_GetActorRotation();
			RandomRotation.Yaw += RandomAngle;

			float RandomDistance = UKismetMathLibrary::RandomFloatInRange(500.0f, 600.0f);
			FVector Direction = UKismetMathLibrary::GetForwardVector(RandomRotation);

			FinalLocation = SpawnLocation + Direction * RandomDistance;
		}

		UFortWorldItem* NewWorldItem = nullptr;

		if (WorldItemDefinition->IsA(UFortWeaponMeleeItemDefinition::StaticClass()) && !WorldItemDefinition->bCanBeDropped) // If the WorldItemDefinition is a pickaxe, replace or add
		{
			for (int32 i = 0; i < PlayerController->WorldInventory->Inventory.ItemInstances.Num(); i++)
			{
				UFortWorldItem* ItemInstance = PlayerController->WorldInventory->Inventory.ItemInstances[i];
				if (!ItemInstance) continue;

				FFortItemEntry* ItemEntry = &PlayerController->WorldInventory->Inventory.ItemInstances[i]->ItemEntry;
				if (!ItemEntry) continue;

				UFortWeaponMeleeItemDefinition* WeaponMeleeItemDefinition = Cast<UFortWeaponMeleeItemDefinition>(ItemEntry->ItemDefinition);
				if (!WeaponMeleeItemDefinition) continue;

				if (WeaponMeleeItemDefinition->bCanBeDropped)
					continue;

				RemoveItem(PlayerController->WorldInventory, ItemEntry->ItemGuid);
			}

			NewWorldItem = AddItem(PlayerController->WorldInventory, ItemEntry);
		}
		else if (IsInventoryFull(PlayerController->WorldInventory) && WorldItemDefinition->bInventorySizeLimited && PlayerPawn) // If the Inventory is full replace the current weapon and spawn pickup
		{
			if (!bReplaceWeapon)
			{
				SpawnPickup(PlayerPawn, ItemEntry, SpawnLocation, FinalLocation);
				return NewWorldItem;
			}

			UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->BP_GetInventoryItemWithGuid(CurrentItemGuid));

			if (!WorldItem)
			{
				AFortWeapon* Weapon = PlayerPawn->CurrentWeapon;

				if (Weapon)
					WorldItem = Cast<UFortWorldItem>(PlayerController->BP_GetInventoryItemWithGuid(Weapon->ItemEntryGuid));
			}

			if (!WorldItem)
			{
				SpawnPickup(PlayerPawn, ItemEntry, SpawnLocation, FinalLocation);
				return NewWorldItem;
			}

			UFortWorldItemDefinition* WorldItemDefinition = Cast<UFortWorldItemDefinition>(WorldItem->ItemEntry.ItemDefinition);

			if (!WorldItemDefinition || !WorldItemDefinition->bCanBeDropped)
			{
				SpawnPickup(PlayerPawn, ItemEntry, SpawnLocation, FinalLocation);
				return NewWorldItem;
			}

			UFortWeaponRangedItemDefinition* WeaponRangedItemDefinition = Cast<UFortWeaponRangedItemDefinition>(WorldItemDefinition);

			if (WeaponRangedItemDefinition && WeaponRangedItemDefinition->bPersistInInventoryWhenFinalStackEmpty)
			{
				int32 ItemQuantity = UFortKismetLibrary::K2_GetItemQuantityOnPlayer(PlayerController, WeaponRangedItemDefinition, FGuid());

				if (ItemQuantity == 0)
				{
					SpawnPickup(PlayerPawn, ItemEntry, SpawnLocation, FinalLocation);
					return NewWorldItem;
				}
			}

			PlayerController->ServerAttemptInventoryDrop(WorldItem->ItemEntry.ItemGuid, WorldItem->ItemEntry.Count, false);

			if (!IsInventoryFull(PlayerController->WorldInventory))
			{
				NewWorldItem = AddItem(PlayerController->WorldInventory, ItemEntry);

				if (NewWorldItem)
				{
					AFortPlayerControllerAthena* PlayerControllerAthena = Cast<AFortPlayerControllerAthena>(PlayerController);

					if (WorldItem->ItemEntry.ItemGuid == PlayerPawn->CurrentWeapon->ItemEntryGuid && PlayerControllerAthena)
						PlayerControllerAthena->ClientEquipItem(NewWorldItem->ItemEntry.ItemGuid, true);
				}
			}
		}
		else if (!IsInventoryFull(PlayerController->WorldInventory) && WorldItemDefinition->bInventorySizeLimited) // If the Inventory is not full just add
		{
			NewWorldItem = AddItem(PlayerController->WorldInventory, ItemEntry);
		}
		else if (!WorldItemDefinition->bInventorySizeLimited)
		{
			UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->BP_FindExistingItemForDefinition(WorldItemDefinition, FGuid(), false));

			if (WorldItem && !WorldItemDefinition->bAllowMultipleStacks && PlayerPawn)
			{
				SpawnPickup(PlayerPawn, ItemEntry, SpawnLocation, FinalLocation);
				return NewWorldItem;
			}
			else
			{
				NewWorldItem = AddItem(PlayerController->WorldInventory, ItemEntry);
			}
		}
		else
		{
			FN_LOG(LogInventory, Error, "Zgueg au max");
		}

		return NewWorldItem;
	}

	void SetupInventory(AFortPlayerController* PlayerController, UFortWeaponMeleeItemDefinition* PickaxeItemDefinition)
	{
		if (!PlayerController)
			return;

		TArray<FItemAndCount> StartingItems = Cast<AFortGameModeAthena>(Globals::GetGameMode())->StartingItems;

		for (int32 i = 0; i < StartingItems.Num(); i++)
		{
			FItemAndCount StartingItem = StartingItems[i];

			UFortWorldItemDefinition* WorldItemDefinition = Cast<UFortWorldItemDefinition>(StartingItem.Item);

			if (!WorldItemDefinition || StartingItem.Count <= 0)
				continue;

			if (WorldItemDefinition->IsA(UFortSmartBuildingItemDefinition::StaticClass()))
				continue;

			FFortItemEntry ItemEntry;
			MakeItemEntry(&ItemEntry, WorldItemDefinition, StartingItem.Count, -1, -1, -1.0f);

			AddInventoryItem(PlayerController, ItemEntry);
			ItemEntry.FreeItemEntry();
		}

		if (PickaxeItemDefinition)
		{
			FFortItemEntry ItemEntry;
			MakeItemEntry(&ItemEntry, PickaxeItemDefinition, 1, 0, 0, 0.f);

			AddInventoryItem(PlayerController, ItemEntry);
			ItemEntry.FreeItemEntry();
		}
	}

	void InitInventory()
	{
		SetStateValue = decltype(SetStateValue)(InSDKUtils::GetImageBase() + 0x625cfbc);

		FN_LOG(LogInit, Log, "InitInventory Success!");
	}
}