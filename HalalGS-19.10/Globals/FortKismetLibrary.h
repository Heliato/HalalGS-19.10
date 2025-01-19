#pragma once

/*
	- 
*/

namespace FortKismetLibrary
{
	AFortAIDirector* GetAIDirector(UFortKismetLibrary* KismetLibrary, FFrame& Stack, AFortAIDirector** Ret)
	{
		UObject* WorldContextObject;

		Stack.StepCompiledIn(&WorldContextObject);

		Stack.Code += Stack.Code != nullptr;

		UWorld* World = UEngine::GetEngine()->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);

		if (World)
		{
			AFortGameModeZone* GameModeZone = Cast<AFortGameModeZone>(World->AuthorityGameMode);

			if (GameModeZone)
			{
				*Ret = GameModeZone->AIDirector;
				return *Ret;
			}
		}

		*Ret = nullptr;
		return *Ret;
	}
	
	AFortAIGoalManager* GetAIGoalManager(UFortKismetLibrary* KismetLibrary, FFrame& Stack, AFortAIGoalManager** Ret)
	{
		UObject* WorldContextObject;

		Stack.StepCompiledIn(&WorldContextObject);

		Stack.Code += Stack.Code != nullptr;

		UWorld* World = UEngine::GetEngine()->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);

		if (World)
		{
			AFortGameModeZone* GameModeZone = Cast<AFortGameModeZone>(World->AuthorityGameMode);

			if (GameModeZone)
			{
				*Ret = GameModeZone->AIGoalManager;
				return *Ret;
			}
		}

		*Ret = nullptr;
		return *Ret;
	}

	const UFortWorldItem* GiveItemToInventoryOwner(UFortKismetLibrary* KismetLibrary, FFrame& Stack, UFortWorldItem** Ret)
	{
		TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner;
		UFortWorldItemDefinition* ItemDefinition;
		FGuid ItemVariantGuid;
		int32 NumberToGive;
		bool bNotifyPlayer;
		int32 ItemLevel;
		int32 PickupInstigatorHandle;
		bool bUseItemPickupAnalyticEvent;

		Stack.StepCompiledIn(&InventoryOwner);
		Stack.StepCompiledIn(&ItemDefinition);
		Stack.StepCompiledIn(&ItemVariantGuid);
		Stack.StepCompiledIn(&NumberToGive);
		Stack.StepCompiledIn(&bNotifyPlayer);
		Stack.StepCompiledIn(&ItemLevel);
		Stack.StepCompiledIn(&PickupInstigatorHandle);
		Stack.StepCompiledIn(&bUseItemPickupAnalyticEvent);

		Stack.Code += Stack.Code != nullptr;

		AFortPlayerController* PlayerController = AFortPlayerController::GetPlayerControllerFromInventoryOwner(InventoryOwner.GetInterface());

		if (!PlayerController || !ItemDefinition)
		{
			*Ret = nullptr;
			return *Ret;
		}

		FN_LOG(LogFortKismetLibrary, Log, __FUNCTION__);

		FFortItemEntry ItemEntry;
		Inventory::MakeItemEntry(&ItemEntry, ItemDefinition, NumberToGive, ItemLevel, -1, -1.0f);
		ItemEntry.ItemVariantGuid = ItemVariantGuid;

		Inventory::SetStateValue(&ItemEntry, EFortItemEntryState::ShouldShowItemToast, bNotifyPlayer);
		*Ret = Inventory::AddInventoryItem(PlayerController, ItemEntry);

		ItemEntry.FreeItemEntry();

		return *Ret;
	}

	void K2_GiveBuildingResource(UFortKismetLibrary* KismetLibrary, FFrame& Stack, void* Ret)
	{
		AFortPlayerController* Controller;
		EFortResourceType ResourceType;
		int32 ResourceAmount;

		Stack.StepCompiledIn(&Controller);
		Stack.StepCompiledIn(&ResourceType);
		Stack.StepCompiledIn(&ResourceAmount);

		Stack.Code += Stack.Code != nullptr;

		UFortResourceItemDefinition* ResourceItemDefinition = UFortKismetLibrary::K2_GetResourceItemDefinition(ResourceType);

		if (!Controller || !ResourceItemDefinition)
			return;

		UFortKismetLibrary::K2_GiveItemToPlayer(Controller, ResourceItemDefinition, FGuid(), ResourceAmount, false);

		FN_LOG(LogFortKismetLibrary, Log, __FUNCTION__);
	}

	void K2_GiveItemToAllPlayers(UFortKismetLibrary* KismetLibrary, FFrame& Stack, void* Ret)
	{
		UObject* WorldContextObject;
		UFortWorldItemDefinition* ItemDefinition;
		FGuid ItemVariantGuid;
		int32 NumberToGive;
		bool bNotifyPlayer;

		Stack.StepCompiledIn(&WorldContextObject);
		Stack.StepCompiledIn(&ItemDefinition);
		Stack.StepCompiledIn(&ItemVariantGuid);
		Stack.StepCompiledIn(&NumberToGive);
		Stack.StepCompiledIn(&bNotifyPlayer);

		Stack.Code += Stack.Code != nullptr;

		if (!WorldContextObject || !ItemDefinition || NumberToGive <= 0)
			return;

		TArray<AFortPlayerController*> AllFortPlayerControllers = UFortKismetLibrary::GetAllFortPlayerControllers(WorldContextObject, true, false);

		for (int32 i = 0; i < AllFortPlayerControllers.Num(); i++)
		{
			AFortPlayerController* PlayerController = AllFortPlayerControllers[i];
			if (!PlayerController) continue;

			UFortKismetLibrary::K2_GiveItemToPlayer(PlayerController, ItemDefinition, ItemVariantGuid, NumberToGive, bNotifyPlayer);
		}

		FN_LOG(LogFortKismetLibrary, Log, __FUNCTION__);
	}

	void K2_GiveItemToPlayer(UFortKismetLibrary* KismetLibrary, FFrame& Stack, void* Ret)
	{
		AFortPlayerController* PlayerController;
		UFortWorldItemDefinition* ItemDefinition;
		FGuid ItemVariantGuid;
		int32 NumberToGive;
		bool bNotifyPlayer;

		Stack.StepCompiledIn(&PlayerController);
		Stack.StepCompiledIn(&ItemDefinition);
		Stack.StepCompiledIn(&ItemVariantGuid);
		Stack.StepCompiledIn(&NumberToGive);
		Stack.StepCompiledIn(&bNotifyPlayer);

		Stack.Code += Stack.Code != nullptr;

		if (!PlayerController || !ItemDefinition || NumberToGive <= 0)
			return;

		UWorld* World = UEngine::GetEngine()->GetWorldFromContextObject(PlayerController, EGetWorldErrorMode::LogAndReturnNull);

		if (!World)
			return;

		FFortItemEntry ItemEntry;
		Inventory::MakeItemEntry(&ItemEntry, ItemDefinition, NumberToGive, -1, -1, -1.0f);
		ItemEntry.ItemVariantGuid = ItemVariantGuid;

		AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;

		if (bNotifyPlayer && PlayerPawn)
		{
			const FVector& SpawnLocation = PlayerPawn->K2_GetActorLocation();

			TWeakObjectPtr<AFortPlayerController> WeakPlayerController{};
			WeakPlayerController.ObjectIndex = -1;
			WeakPlayerController.ObjectSerialNumber = 0;

			TWeakObjectPtr<AActor> WeakInvestigator{};
			WeakInvestigator.ObjectIndex = -1;
			WeakInvestigator.ObjectSerialNumber = 0;

			FFortCreatePickupData PickupData{};
			PickupData.World = World;
			PickupData.ItemEntry = ItemEntry;
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
				const FVector& StartDirection = FVector({ 0, 0, 0 });

				float FlyTime = Pickup->GenFlyTime();
				Pickup->SetPickupTarget(PlayerPawn, FlyTime, StartDirection);
			}
		}
		else
		{
			Inventory::SetStateValue(&ItemEntry, EFortItemEntryState::ShouldShowItemToast, 1);
			Inventory::AddInventoryItem(PlayerController, ItemEntry);
		}

		FN_LOG(LogFortKismetLibrary, Log, __FUNCTION__);

		ItemEntry.FreeItemEntry();
	}

	int32 K2_RemoveFortItemFromPlayer(UFortKismetLibrary* KismetLibrary, FFrame& Stack, int32* Ret)
	{
		AFortPlayerController* PlayerController;
		UFortItem* Item;
		int32 AmountToRemove;
		bool bForceRemoval;

		Stack.StepCompiledIn(&PlayerController);
		Stack.StepCompiledIn(&Item);
		Stack.StepCompiledIn(&AmountToRemove);
		Stack.StepCompiledIn(&bForceRemoval);

		Stack.Code += Stack.Code != nullptr;

		if (!PlayerController || !Item || AmountToRemove == 0)
		{
			*Ret = 0;
			return *Ret;
		}

		FN_LOG(LogFortKismetLibrary, Log, __FUNCTION__);

		UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->BP_GetInventoryItemWithGuid(Item->GetItemGuid()));

		if (WorldItem)
		{
			int32 ItemCount = WorldItem->ItemEntry.Count;
			int32 FinalCount = ItemCount - AmountToRemove;

			if (FinalCount < 0)
				FinalCount = 0;

			PlayerController->RemoveInventoryItem(WorldItem->ItemEntry.ItemGuid, AmountToRemove, false, bForceRemoval);

			*Ret = FinalCount;
			return *Ret;
		}

		*Ret = 0;
		return *Ret;
	}

	void K2_RemoveItemFromAllPlayers(UFortKismetLibrary* KismetLibrary, FFrame& Stack, void* Ret)
	{
		UObject* WorldContextObject;
		UFortWorldItemDefinition* ItemDefinition;
		FGuid ItemVariantGuid; 
		int32 AmountToRemove;

		Stack.StepCompiledIn(&WorldContextObject);
		Stack.StepCompiledIn(&ItemDefinition);
		Stack.StepCompiledIn(&ItemVariantGuid);
		Stack.StepCompiledIn(&AmountToRemove);

		Stack.Code += Stack.Code != nullptr;

		if (!WorldContextObject || !ItemDefinition || AmountToRemove == 0)
			return;

		TArray<AFortPlayerController*> AllFortPlayerControllers = UFortKismetLibrary::GetAllFortPlayerControllers(WorldContextObject, true, false);

		for (int32 i = 0; i < AllFortPlayerControllers.Num(); i++)
		{
			AFortPlayerController* PlayerController = AllFortPlayerControllers[i];
			if (!PlayerController) continue;;

			UFortKismetLibrary::K2_RemoveItemFromPlayer(PlayerController, ItemDefinition, ItemVariantGuid, AmountToRemove, false);
		}

		FN_LOG(LogFortKismetLibrary, Log, __FUNCTION__);
	}

	int32 K2_RemoveItemFromPlayer(UFortKismetLibrary* KismetLibrary, FFrame& Stack, int32* Ret)
	{
		AFortPlayerController* PlayerController;
		UFortWorldItemDefinition* ItemDefinition;
		FGuid ItemVariantGuid;
		int32 AmountToRemove;
		bool bForceRemoval;

		Stack.StepCompiledIn(&PlayerController);
		Stack.StepCompiledIn(&ItemDefinition);
		Stack.StepCompiledIn(&ItemVariantGuid);
		Stack.StepCompiledIn(&AmountToRemove);
		Stack.StepCompiledIn(&bForceRemoval);

		Stack.Code += Stack.Code != nullptr;

		if (!PlayerController || !ItemDefinition || AmountToRemove == 0)
		{
			*Ret = 0;
			return *Ret;
		}

		FN_LOG(LogFortKismetLibrary, Log, __FUNCTION__);

		UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->BP_FindExistingItemForDefinition(ItemDefinition, ItemVariantGuid, false));

		if (WorldItem)
		{
			int32 ItemCount = WorldItem->ItemEntry.Count;
			int32 FinalCount = ItemCount - AmountToRemove;

			if (FinalCount < 0)
				FinalCount = 0;

			PlayerController->RemoveInventoryItem(WorldItem->ItemEntry.ItemGuid, AmountToRemove, false, bForceRemoval);

			*Ret = FinalCount;
			return *Ret;
		}

		*Ret = 0;
		return *Ret;
	}

	int32 K2_RemoveItemFromPlayerByGuid(UFortKismetLibrary* KismetLibrary, FFrame& Stack, int32* Ret)
	{
		AFortPlayerController* PlayerController;
		FGuid ItemGuid;
		int32 AmountToRemove;
		bool bForceRemoval;

		Stack.StepCompiledIn(&PlayerController);
		Stack.StepCompiledIn(&ItemGuid);
		Stack.StepCompiledIn(&AmountToRemove);
		Stack.StepCompiledIn(&bForceRemoval);

		Stack.Code += Stack.Code != nullptr;

		if (!PlayerController || AmountToRemove == 0)
		{
			*Ret = 0;
			return *Ret;
		}

		FN_LOG(LogFortKismetLibrary, Log, __FUNCTION__);

		UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->BP_GetInventoryItemWithGuid(ItemGuid));

		if (WorldItem)
		{
			int32 ItemCount = WorldItem->ItemEntry.Count;
			int32 FinalCount = ItemCount - AmountToRemove;

			if (FinalCount < 0)
				FinalCount = 0;

			PlayerController->RemoveInventoryItem(WorldItem->ItemEntry.ItemGuid, AmountToRemove, false, bForceRemoval);

			*Ret = FinalCount;
			return *Ret;
		}

		*Ret = 0;
		return *Ret;
	}

	int32 K2_RemoveItemsFromPlayerByIntStateValue(UFortKismetLibrary* KismetLibrary, FFrame& Stack, int32* Ret)
	{
		AFortPlayerController* PlayerController;
		EFortItemEntryState StateType;
		int32 StateValue;
		bool bForceRemoval;

		Stack.StepCompiledIn(&PlayerController);
		Stack.StepCompiledIn(&StateType);
		Stack.StepCompiledIn(&StateValue);
		Stack.StepCompiledIn(&bForceRemoval);

		Stack.Code += Stack.Code != nullptr;

		FN_LOG(LogFortKismetLibrary, Log, __FUNCTION__);

		*Ret = 0;
		return *Ret;
	}

	int32 K2_RemoveItemsFromPlayerByNameStateValue(UFortKismetLibrary* KismetLibrary, FFrame& Stack, int32* Ret)
	{
		AFortPlayerController* PlayerController;
		EFortItemEntryState StateType;
		FName StateValue;
		bool bForceRemoval;

		Stack.StepCompiledIn(&PlayerController);
		Stack.StepCompiledIn(&StateType);
		Stack.StepCompiledIn(&StateValue);
		Stack.StepCompiledIn(&bForceRemoval);

		Stack.Code += Stack.Code != nullptr;

		FN_LOG(LogFortKismetLibrary, Log, __FUNCTION__);

		*Ret = 0;
		return *Ret;
	}

	AFortPickup* K2_SpawnPickupInWorld(UFortKismetLibrary* KismetLibrary, FFrame& Stack, AFortPickup** Ret)
	{
		UObject* WorldContextObject;
		UFortWorldItemDefinition* ItemDefinition;
		int32 NumberToSpawn;
		FVector Position;
		FVector Direction;
		int32 OverrideMaxStackCount;
		bool bToss;
		bool bRandomRotation;
		bool bBlockedFromAutoPickup;
		int32 PickupInstigatorHandle;
		EFortPickupSourceTypeFlag SourceType;
		EFortPickupSpawnSource Source;
		AFortPlayerController* OptionalOwnerPC;
		bool bPickupOnlyRelevantToOwner;

		Stack.StepCompiledIn(&WorldContextObject);
		Stack.StepCompiledIn(&ItemDefinition);
		Stack.StepCompiledIn(&NumberToSpawn);
		Stack.StepCompiledIn(&Position);
		Stack.StepCompiledIn(&Direction);
		Stack.StepCompiledIn(&OverrideMaxStackCount);
		Stack.StepCompiledIn(&bToss);
		Stack.StepCompiledIn(&bRandomRotation);
		Stack.StepCompiledIn(&bBlockedFromAutoPickup);
		Stack.StepCompiledIn(&PickupInstigatorHandle);
		Stack.StepCompiledIn(&SourceType);
		Stack.StepCompiledIn(&Source);
		Stack.StepCompiledIn(&OptionalOwnerPC);
		Stack.StepCompiledIn(&bPickupOnlyRelevantToOwner);

		Stack.Code += Stack.Code != nullptr;

		if (!WorldContextObject || !ItemDefinition || NumberToSpawn <= 0)
		{
			*Ret = nullptr;
			return *Ret;
		}

		UWorld* World = UEngine::GetEngine()->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);

		if (!World)
		{
			*Ret = nullptr;
			return *Ret;
		}

		FFortItemEntry ItemEntry;
		Inventory::MakeItemEntry(&ItemEntry, ItemDefinition, NumberToSpawn, -1, -1, -1.0f);

		bool bAllowOnlyRevelant = (OptionalOwnerPC && bPickupOnlyRelevantToOwner);

		FFortCreatePickupData* (*CreatePickupData)(FFortCreatePickupData* PickupData, UWorld* World, FFortItemEntry ItemEntry, FVector SpawnLocation, FRotator SpawnRotation, AFortPlayerController* PlayerController, UClass* OverrideClass, AActor* Investigator, int a9, int a10) = decltype(CreatePickupData)(0x64da9dc + uintptr_t(GetModuleHandle(0)));

		FFortCreatePickupData PickupData{};
		CreatePickupData(&PickupData, World, ItemEntry, Position, FRotator(), bAllowOnlyRevelant ? OptionalOwnerPC : nullptr, nullptr, bAllowOnlyRevelant ? OptionalOwnerPC : nullptr, 0, 0);
		PickupData.bRandomRotation = bRandomRotation;
		PickupData.PickupSourceTypeFlags = SourceType;
		PickupData.PickupSpawnSource = Source;

		AFortPickup* (*CreatePickupFromData)(FFortCreatePickupData* PickupData) = decltype(CreatePickupFromData)(0x64dd1b4 + uintptr_t(GetModuleHandle(0)));
		AFortPickup* Pickup = CreatePickupFromData(&PickupData);

		if (Pickup)
		{
			Pickup->bWeaponsCanBeAutoPickups = !bBlockedFromAutoPickup;
			Pickup->TossPickup(
				Position,
				nullptr,
				OverrideMaxStackCount,
				bToss,
				true,
				SourceType,
				Source
			);
		}

		ItemEntry.FreeItemEntry();

		FN_LOG(LogFortKismetLibrary, Log, "WorldContextObject: %s, ItemDefinition: %s, NumberToSpawn: %i", WorldContextObject->GetFullName().c_str(), ItemDefinition->GetFullName().c_str(), NumberToSpawn);
		FN_LOG(LogFortKismetLibrary, Log, __FUNCTION__);

		*Ret = Pickup;
		return *Ret;
	}

	AFortPickup* K2_SpawnPickupInWorldWithClass(UFortKismetLibrary* KismetLibrary, FFrame& Stack, AFortPickup** Ret)
	{
		UObject* WorldContextObject;
		UFortWorldItemDefinition* ItemDefinition;
		TSubclassOf<AFortPickup> PickupClass;
		int32 NumberToSpawn;
		FVector Position;
		FVector Direction;
		int32 OverrideMaxStackCount;
		bool bToss;
		bool bRandomRotation;
		bool bBlockedFromAutoPickup;
		int32 PickupInstigatorHandle;
		EFortPickupSourceTypeFlag SourceType;
		EFortPickupSpawnSource Source;
		AFortPlayerController* OptionalOwnerPC;
		bool bPickupOnlyRelevantToOwner;

		Stack.StepCompiledIn(&WorldContextObject);
		Stack.StepCompiledIn(&ItemDefinition);
		Stack.StepCompiledIn(&PickupClass);
		Stack.StepCompiledIn(&NumberToSpawn);
		Stack.StepCompiledIn(&Position);
		Stack.StepCompiledIn(&Direction);
		Stack.StepCompiledIn(&OverrideMaxStackCount);
		Stack.StepCompiledIn(&bToss);
		Stack.StepCompiledIn(&bRandomRotation);
		Stack.StepCompiledIn(&bBlockedFromAutoPickup);
		Stack.StepCompiledIn(&PickupInstigatorHandle);
		Stack.StepCompiledIn(&SourceType);
		Stack.StepCompiledIn(&Source);
		Stack.StepCompiledIn(&OptionalOwnerPC);
		Stack.StepCompiledIn(&bPickupOnlyRelevantToOwner);

		Stack.Code += Stack.Code != nullptr;

		FN_LOG(LogFortKismetLibrary, Log, __FUNCTION__);

		if (!WorldContextObject || !ItemDefinition || NumberToSpawn <= 0)
		{
			*Ret = nullptr;
			return *Ret;
		}

		UWorld* World = UEngine::GetEngine()->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);

		if (!World)
		{
			*Ret = nullptr;
			return *Ret;
		}

		FFortItemEntry ItemEntry;
		Inventory::MakeItemEntry(&ItemEntry, ItemDefinition, NumberToSpawn, -1, -1, -1.0f);

		bool bAllowOnlyRevelant = (OptionalOwnerPC && bPickupOnlyRelevantToOwner);

		FFortCreatePickupData* (*CreatePickupData)(FFortCreatePickupData* PickupData, UWorld* World, FFortItemEntry ItemEntry, FVector SpawnLocation, FRotator SpawnRotation, AFortPlayerController* PlayerController, UClass* OverrideClass, AActor* Investigator, int a9, int a10) = decltype(CreatePickupData)(0x64da9dc + uintptr_t(GetModuleHandle(0)));

		FFortCreatePickupData PickupData{};
		CreatePickupData(&PickupData, World, ItemEntry, Position, FRotator(), bAllowOnlyRevelant ? OptionalOwnerPC : nullptr, PickupClass.Get(), bAllowOnlyRevelant ? OptionalOwnerPC : nullptr, 0, 0);
		PickupData.bRandomRotation = bRandomRotation;
		PickupData.PickupSourceTypeFlags = SourceType;
		PickupData.PickupSpawnSource = Source;

		AFortPickup* (*CreatePickupFromData)(FFortCreatePickupData* PickupData) = decltype(CreatePickupFromData)(0x64dd1b4 + uintptr_t(GetModuleHandle(0)));
		AFortPickup* Pickup = CreatePickupFromData(&PickupData);

		if (Pickup)
		{
			Pickup->bWeaponsCanBeAutoPickups = !bBlockedFromAutoPickup;
			Pickup->TossPickup(
				Position,
				nullptr,
				OverrideMaxStackCount,
				bToss,
				true,
				SourceType,
				Source
			);
		}

		ItemEntry.FreeItemEntry();

		*Ret = Pickup;
		return *Ret;
	}

	AFortPickup* K2_SpawnPickupInWorldWithClassAndItemEntry(UFortKismetLibrary* KismetLibrary, FFrame& Stack, AFortPickup** Ret)
	{
		UObject* WorldContextObject;
		FFortItemEntry ItemEntry;
		TSubclassOf<AFortPickup> PickupClass;
		FVector Position;
		FVector Direction;
		int32 OverrideMaxStackCount;
		bool bToss;
		bool bRandomRotation;
		bool bBlockedFromAutoPickup;
		EFortPickupSourceTypeFlag SourceType;
		EFortPickupSpawnSource Source;
		AFortPlayerController* OptionalOwnerPC;
		bool bPickupOnlyRelevantToOwner;

		Stack.StepCompiledIn(&WorldContextObject);
		Stack.StepCompiledIn(&ItemEntry);
		Stack.StepCompiledIn(&PickupClass);
		Stack.StepCompiledIn(&Position);
		Stack.StepCompiledIn(&Direction);
		Stack.StepCompiledIn(&OverrideMaxStackCount);
		Stack.StepCompiledIn(&bToss);
		Stack.StepCompiledIn(&bRandomRotation);
		Stack.StepCompiledIn(&bBlockedFromAutoPickup);
		Stack.StepCompiledIn(&SourceType);
		Stack.StepCompiledIn(&Source);
		Stack.StepCompiledIn(&OptionalOwnerPC);
		Stack.StepCompiledIn(&bPickupOnlyRelevantToOwner);

		Stack.Code += Stack.Code != nullptr;

		FN_LOG(LogFortKismetLibrary, Log, __FUNCTION__);

		if (!WorldContextObject)
		{
			*Ret = nullptr;
			return *Ret;
		}

		UWorld* World = UEngine::GetEngine()->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);

		if (!World)
		{
			*Ret = nullptr;
			return *Ret;
		}

		FFortItemEntry NewItemEntry;
		NewItemEntry.CopyItemEntryWithReset(&ItemEntry);

		bool bAllowOnlyRevelant = (OptionalOwnerPC && bPickupOnlyRelevantToOwner);

		FFortCreatePickupData* (*CreatePickupData)(FFortCreatePickupData* PickupData, UWorld* World, FFortItemEntry ItemEntry, FVector SpawnLocation, FRotator SpawnRotation, AFortPlayerController* PlayerController, UClass* OverrideClass, AActor* Investigator, int a9, int a10) = decltype(CreatePickupData)(0x64da9dc + uintptr_t(GetModuleHandle(0)));

		FFortCreatePickupData PickupData{};
		CreatePickupData(&PickupData, World, NewItemEntry, Position, FRotator(), bAllowOnlyRevelant ? OptionalOwnerPC : nullptr, PickupClass.Get(), bAllowOnlyRevelant ? OptionalOwnerPC : nullptr, 0, 0);
		PickupData.bRandomRotation = bRandomRotation;
		PickupData.PickupSourceTypeFlags = SourceType;
		PickupData.PickupSpawnSource = Source;

		AFortPickup* (*CreatePickupFromData)(FFortCreatePickupData* PickupData) = decltype(CreatePickupFromData)(0x64dd1b4 + uintptr_t(GetModuleHandle(0)));
		AFortPickup* Pickup = CreatePickupFromData(&PickupData);

		if (Pickup)
		{
			Pickup->bWeaponsCanBeAutoPickups = !bBlockedFromAutoPickup;
			Pickup->TossPickup(
				Position,
				nullptr,
				OverrideMaxStackCount,
				bToss,
				true,
				SourceType,
				Source
			);
		}

		NewItemEntry.FreeItemEntry();
		ItemEntry.FreeItemEntry();

		*Ret = Pickup;
		return *Ret;
	}

	AFortPickup* K2_SpawnPickupInWorldWithClassAndLevel(UFortKismetLibrary* KismetLibrary, FFrame& Stack, AFortPickup** Ret)
	{
		UObject* WorldContextObject;
		UFortWorldItemDefinition* ItemDefinition;
		int32 WorldLevel;
		TSubclassOf<AFortPickup> PickupClass;
		int32 NumberToSpawn;
		FVector Position;
		FVector Direction;
		int32 OverrideMaxStackCount;
		bool bToss;
		bool bRandomRotation;
		bool bBlockedFromAutoPickup;
		int32 PickupInstigatorHandle;
		EFortPickupSourceTypeFlag SourceType;
		EFortPickupSpawnSource Source;
		AFortPlayerController* OptionalOwnerPC;
		bool bPickupOnlyRelevantToOwner;

		Stack.StepCompiledIn(&WorldContextObject);
		Stack.StepCompiledIn(&ItemDefinition);
		Stack.StepCompiledIn(&WorldLevel);
		Stack.StepCompiledIn(&PickupClass);
		Stack.StepCompiledIn(&NumberToSpawn);
		Stack.StepCompiledIn(&Position);
		Stack.StepCompiledIn(&Direction);
		Stack.StepCompiledIn(&OverrideMaxStackCount);
		Stack.StepCompiledIn(&bToss);
		Stack.StepCompiledIn(&bRandomRotation);
		Stack.StepCompiledIn(&bBlockedFromAutoPickup);
		Stack.StepCompiledIn(&PickupInstigatorHandle);
		Stack.StepCompiledIn(&SourceType);
		Stack.StepCompiledIn(&Source);
		Stack.StepCompiledIn(&OptionalOwnerPC);
		Stack.StepCompiledIn(&bPickupOnlyRelevantToOwner);

		Stack.Code += Stack.Code != nullptr;

		FN_LOG(LogFortKismetLibrary, Log, __FUNCTION__);

		*Ret = UFortKismetLibrary::K2_SpawnPickupInWorldWithClass(
			WorldContextObject,
			ItemDefinition,
			PickupClass,
			NumberToSpawn,
			Position,
			Direction,
			OverrideMaxStackCount,
			bToss,
			bRandomRotation,
			bBlockedFromAutoPickup,
			PickupInstigatorHandle,
			SourceType,
			Source,
			OptionalOwnerPC,
			bPickupOnlyRelevantToOwner
		);

		return *Ret;
	}

	AFortPickup* K2_SpawnPickupInWorldWithLevel(UFortKismetLibrary* KismetLibrary, FFrame& Stack, AFortPickup** Ret)
	{
		UObject* WorldContextObject;
		UFortWorldItemDefinition* ItemDefinition;
		int32 WorldLevel;
		int32 NumberToSpawn;
		FVector Position;
		FVector Direction;
		int32 OverrideMaxStackCount;
		bool bToss;
		bool bRandomRotation;
		bool bBlockedFromAutoPickup;
		int32 PickupInstigatorHandle;
		EFortPickupSourceTypeFlag SourceType;
		EFortPickupSpawnSource Source;
		AFortPlayerController* OptionalOwnerPC;
		bool bPickupOnlyRelevantToOwner;

		Stack.StepCompiledIn(&WorldContextObject);
		Stack.StepCompiledIn(&ItemDefinition);
		Stack.StepCompiledIn(&WorldLevel);
		Stack.StepCompiledIn(&NumberToSpawn);
		Stack.StepCompiledIn(&Position);
		Stack.StepCompiledIn(&Direction);
		Stack.StepCompiledIn(&OverrideMaxStackCount);
		Stack.StepCompiledIn(&bToss);
		Stack.StepCompiledIn(&bRandomRotation);
		Stack.StepCompiledIn(&bBlockedFromAutoPickup);
		Stack.StepCompiledIn(&PickupInstigatorHandle);
		Stack.StepCompiledIn(&SourceType);
		Stack.StepCompiledIn(&Source);
		Stack.StepCompiledIn(&OptionalOwnerPC);
		Stack.StepCompiledIn(&bPickupOnlyRelevantToOwner);

		Stack.Code += Stack.Code != nullptr;

		FN_LOG(LogFortKismetLibrary, Log, __FUNCTION__);

		*Ret = UFortKismetLibrary::K2_SpawnPickupInWorld(
			WorldContextObject,
			ItemDefinition,
			NumberToSpawn,
			Position,
			Direction,
			OverrideMaxStackCount,
			bToss,
			bRandomRotation,
			bBlockedFromAutoPickup,
			PickupInstigatorHandle,
			SourceType,
			Source,
			OptionalOwnerPC,
			bPickupOnlyRelevantToOwner
		);

		return *Ret;
	}

	TArray<AFortPickup*> K2_SpawnPickupInWorldWithLootTier(UFortKismetLibrary* KismetLibrary, FFrame& Stack, TArray<AFortPickup*>* Ret)
	{
		UObject* WorldContextObject;
		FName LootTierName;
		FVector Position;
		int32 OverrideMaxStackCount;
		bool bToss;
		bool bTossWithVelocity;
		FVector TossVelocity;
		EFortPickupSourceTypeFlag SourceType;
		EFortPickupSpawnSource Source;

		Stack.StepCompiledIn(&WorldContextObject);
		Stack.StepCompiledIn(&LootTierName);
		Stack.StepCompiledIn(&Position);
		Stack.StepCompiledIn(&OverrideMaxStackCount);
		Stack.StepCompiledIn(&bToss);
		Stack.StepCompiledIn(&bTossWithVelocity);
		Stack.StepCompiledIn(&TossVelocity);
		Stack.StepCompiledIn(&SourceType);
		Stack.StepCompiledIn(&Source);

		Stack.Code += Stack.Code != nullptr;

		FN_LOG(LogFortKismetLibrary, Log, __FUNCTION__);

		Ret->Clear();

		int32 WorldLevel = UFortKismetLibrary::GetLootLevel(WorldContextObject);

		TArray<FFortItemEntry> LootToDrops;
		UFortKismetLibrary::PickLootDrops(WorldContextObject, &LootToDrops, LootTierName, WorldLevel, -1);

		for (int32 i = 0; i < LootToDrops.Num(); i++)
		{
			AFortPickup* Pickup = UFortKismetLibrary::K2_SpawnPickupInWorldWithClassAndItemEntry(
				WorldContextObject,
				LootToDrops[i],
				AFortPickupAthena::StaticClass(),
				Position,
				Position,
				OverrideMaxStackCount,
				bToss,
				true,
				false,
				SourceType,
				Source,
				nullptr,
				false
			);

			if (!Pickup)
				continue;

			Ret->Add(Pickup);
		}

		*Ret;
	}

	bool PickLootDrops(UFortKismetLibrary* KismetLibrary, FFrame& Stack, bool* Ret)
	{
		UObject* WorldContextObject;
		TArray<FFortItemEntry> OutLootToDrop{};
		FName TierGroupName;
		int32 WorldLevel;
		int32 ForcedLootTier;

		Stack.StepCompiledIn(&WorldContextObject);
		TArray<FFortItemEntry>& LootToDrops = Stack.StepCompiledInRef<TArray<FFortItemEntry>>(&OutLootToDrop);
		Stack.StepCompiledIn(&TierGroupName);
		Stack.StepCompiledIn(&WorldLevel);
		Stack.StepCompiledIn(&ForcedLootTier);

		Stack.Code += Stack.Code != nullptr;

		FN_LOG(LogFortKismetLibrary, Log, "WorldContextObject: %s, TierGroupName: %s, WorldLevel: %i, ForcedLootTier: %i", WorldContextObject->GetFullName().c_str(), TierGroupName.ToString().c_str(), WorldLevel, ForcedLootTier);
		FN_LOG(LogFortKismetLibrary, Log, __FUNCTION__);

		FFortItemEntry::FreeItemEntries(&OutLootToDrop);

		FName LootTierKey = FName(0);
		int32 LootTier = -1;

		bool bResult = Loots::PickLootTierKeyAndLootTierFromTierGroup(&LootTierKey, &LootTier, TierGroupName, WorldLevel, 0, ForcedLootTier, FGameplayTagContainer());

		if (bResult)
		{
			*Ret = Loots::PickLootDrops(&LootToDrops, WorldLevel, LootTierKey, 0, 0, FGameplayTagContainer(), false, false);
			return *Ret;
		}

		*Ret = false;
		return *Ret;
	}

	bool PickLootDropsWithNamedWeights(UFortKismetLibrary* KismetLibrary, FFrame& Stack, bool* Ret)
	{
		UObject* WorldContextObject;
		TArray<FFortItemEntry> OutLootToDrop{};
		FName TierGroupName;
		int32 WorldLevel;
		TMap<FName, float> NamedWeightsMap;
		int32 ForcedLootTier;

		Stack.StepCompiledIn(&WorldContextObject);
		TArray<FFortItemEntry>& LootToDrops = Stack.StepCompiledInRef<TArray<FFortItemEntry>>(&OutLootToDrop);
		Stack.StepCompiledIn(&TierGroupName);
		Stack.StepCompiledIn(&WorldLevel);
		Stack.StepCompiledIn(&NamedWeightsMap);
		Stack.StepCompiledIn(&ForcedLootTier);

		Stack.Code += Stack.Code != nullptr;

		FN_LOG(LogFortKismetLibrary, Log, __FUNCTION__);

		FFortItemEntry::FreeItemEntries(&OutLootToDrop);



		*Ret = false;
		return *Ret;
	}

	bool SpawnInstancedPickupInWorld(UFortKismetLibrary* KismetLibrary, FFrame& Stack, bool* Ret)
	{
		UObject* WorldContextObject;
		UFortWorldItemDefinition* ItemDefinition;
		int32 NumberToSpawn;
		FVector Position;
		FVector Direction;
		int32 OverrideMaxStackCount;
		bool bToss;
		bool bRandomRotation;
		bool bBlockedFromAutoPickup;

		Stack.StepCompiledIn(&WorldContextObject);
		Stack.StepCompiledIn(&ItemDefinition);
		Stack.StepCompiledIn(&NumberToSpawn);
		Stack.StepCompiledIn(&Position);
		Stack.StepCompiledIn(&Direction);
		Stack.StepCompiledIn(&OverrideMaxStackCount);
		Stack.StepCompiledIn(&bToss);
		Stack.StepCompiledIn(&bRandomRotation);
		Stack.StepCompiledIn(&bBlockedFromAutoPickup);

		Stack.Code += Stack.Code != nullptr;

		FN_LOG(LogFortKismetLibrary, Log, __FUNCTION__);

		AFortPickup* Pickup = UFortKismetLibrary::K2_SpawnPickupInWorld(
			WorldContextObject,
			ItemDefinition,
			NumberToSpawn,
			Position,
			Direction,
			OverrideMaxStackCount,
			bToss,
			bRandomRotation,
			bBlockedFromAutoPickup,
			0,
			EFortPickupSourceTypeFlag::Other,
			EFortPickupSpawnSource::Unset,
			nullptr,
			false
		);
		
		*Ret = (Pickup != nullptr);
		return *Ret;
	}

	AFortPickup* SpawnItemVariantPickupInWorld(UFortKismetLibrary* KismetLibrary, FFrame& Stack, AFortPickup** Ret)
	{
		UObject* WorldContextObject;
		FSpawnItemVariantParams Params_0;

		Stack.StepCompiledIn(&WorldContextObject);
		Stack.StepCompiledIn(&Params_0);

		Stack.Code += Stack.Code != nullptr;

		FN_LOG(LogFortKismetLibrary, Log, __FUNCTION__);

		*Ret = UFortKismetLibrary::K2_SpawnPickupInWorld(
			WorldContextObject, 
			Params_0.WorldItemDefinition, 
			Params_0.NumberToSpawn, 
			Params_0.Position, 
			Params_0.Direction, 
			Params_0.OverrideMaxStackCount, 
			Params_0.bToss, 
			Params_0.bRandomRotation, 
			Params_0.bBlockedFromAutoPickup,
			Params_0.PickupInstigatorHandle,
			Params_0.SourceType,
			Params_0.Source,
			Params_0.OptionalOwnerPC,
			Params_0.bPickupOnlyRelevantToOwner
		);

		return *Ret;
	}

	void InitFortKismetLibrary()
	{
		UFortKismetLibrary* FortKismetLibraryDefault = UFortKismetLibrary::GetDefaultObj();
		UClass* FortKismetLibraryClass = UFortKismetLibrary::StaticClass();

		UFunction* GetAIDirectorFunc = FortKismetLibraryClass->GetFunction("FortKismetLibrary", "GetAIDirector");
		MinHook::HookFunctionExec(GetAIDirectorFunc, GetAIDirector, nullptr);

		UFunction* GetAIGoalManagerFunc = FortKismetLibraryClass->GetFunction("FortKismetLibrary", "GetAIGoalManager");
		MinHook::HookFunctionExec(GetAIGoalManagerFunc, GetAIGoalManager, nullptr);

		UFunction* GiveItemToInventoryOwnerFunc = FortKismetLibraryClass->GetFunction("FortKismetLibrary", "GiveItemToInventoryOwner");
		MinHook::HookFunctionExec(GiveItemToInventoryOwnerFunc, GiveItemToInventoryOwner, nullptr);

		UFunction* K2_GiveBuildingResourceFunc = FortKismetLibraryClass->GetFunction("FortKismetLibrary", "K2_GiveBuildingResource");
		MinHook::HookFunctionExec(K2_GiveBuildingResourceFunc, K2_GiveBuildingResource, nullptr);

		UFunction* K2_GiveItemToAllPlayersFunc = FortKismetLibraryClass->GetFunction("FortKismetLibrary", "K2_GiveItemToAllPlayers");
		MinHook::HookFunctionExec(K2_GiveItemToAllPlayersFunc, K2_GiveItemToAllPlayers, nullptr);

		UFunction* K2_GiveItemToPlayerFunc = FortKismetLibraryClass->GetFunction("FortKismetLibrary", "K2_GiveItemToPlayer");
		MinHook::HookFunctionExec(K2_GiveItemToPlayerFunc, K2_GiveItemToPlayer, nullptr);

		UFunction* K2_RemoveFortItemFromPlayerFunc = FortKismetLibraryClass->GetFunction("FortKismetLibrary", "K2_RemoveFortItemFromPlayer");
		MinHook::HookFunctionExec(K2_RemoveFortItemFromPlayerFunc, K2_RemoveFortItemFromPlayer, nullptr);

		UFunction* K2_RemoveItemFromAllPlayersFunc = FortKismetLibraryClass->GetFunction("FortKismetLibrary", "K2_RemoveItemFromAllPlayers");
		MinHook::HookFunctionExec(K2_RemoveItemFromAllPlayersFunc, K2_RemoveItemFromAllPlayers, nullptr);

		UFunction* K2_RemoveItemFromPlayerFunc = FortKismetLibraryClass->GetFunction("FortKismetLibrary", "K2_RemoveItemFromPlayer");
		MinHook::HookFunctionExec(K2_RemoveItemFromPlayerFunc, K2_RemoveItemFromPlayer, nullptr);

		UFunction* K2_RemoveItemFromPlayerByGuidFunc = FortKismetLibraryClass->GetFunction("FortKismetLibrary", "K2_RemoveItemFromPlayerByGuid");
		MinHook::HookFunctionExec(K2_RemoveItemFromPlayerByGuidFunc, K2_RemoveItemFromPlayerByGuid, nullptr);

		UFunction* K2_RemoveItemsFromPlayerByIntStateValueFunc = FortKismetLibraryClass->GetFunction("FortKismetLibrary", "K2_RemoveItemsFromPlayerByIntStateValue");
		MinHook::HookFunctionExec(K2_RemoveItemsFromPlayerByIntStateValueFunc, K2_RemoveItemsFromPlayerByIntStateValue, nullptr);

		UFunction* K2_RemoveItemsFromPlayerByNameStateValueFunc = FortKismetLibraryClass->GetFunction("FortKismetLibrary", "K2_RemoveItemsFromPlayerByNameStateValue");
		MinHook::HookFunctionExec(K2_RemoveItemsFromPlayerByNameStateValueFunc, K2_RemoveItemsFromPlayerByNameStateValue, nullptr);

		UFunction* K2_SpawnPickupInWorldFunc = FortKismetLibraryClass->GetFunction("FortKismetLibrary", "K2_SpawnPickupInWorld");
		MinHook::HookFunctionExec(K2_SpawnPickupInWorldFunc, K2_SpawnPickupInWorld, nullptr);

		UFunction* K2_SpawnPickupInWorldWithClassFunc = FortKismetLibraryClass->GetFunction("FortKismetLibrary", "K2_SpawnPickupInWorldWithClass");
		MinHook::HookFunctionExec(K2_SpawnPickupInWorldWithClassFunc, K2_SpawnPickupInWorldWithClass, nullptr);

		UFunction* K2_SpawnPickupInWorldWithClassAndItemEntryFunc = FortKismetLibraryClass->GetFunction("FortKismetLibrary", "K2_SpawnPickupInWorldWithClassAndItemEntry");
		MinHook::HookFunctionExec(K2_SpawnPickupInWorldWithClassAndItemEntryFunc, K2_SpawnPickupInWorldWithClassAndItemEntry, nullptr);

		UFunction* K2_SpawnPickupInWorldWithClassAndLevelFunc = FortKismetLibraryClass->GetFunction("FortKismetLibrary", "K2_SpawnPickupInWorldWithClassAndLevel");
		MinHook::HookFunctionExec(K2_SpawnPickupInWorldWithClassAndLevelFunc, K2_SpawnPickupInWorldWithClassAndLevel, nullptr);

		UFunction* PickLootDropsFunc = FortKismetLibraryClass->GetFunction("FortKismetLibrary", "PickLootDrops");
		MinHook::HookFunctionExec(PickLootDropsFunc, PickLootDrops, nullptr);

		UFunction* PickLootDropsWithNamedWeightsFunc = FortKismetLibraryClass->GetFunction("FortKismetLibrary", "PickLootDropsWithNamedWeights");
		MinHook::HookFunctionExec(PickLootDropsWithNamedWeightsFunc, PickLootDropsWithNamedWeights, nullptr);

		UFunction* SpawnInstancedPickupInWorldFunc = FortKismetLibraryClass->GetFunction("FortKismetLibrary", "SpawnInstancedPickupInWorld");
		MinHook::HookFunctionExec(SpawnInstancedPickupInWorldFunc, SpawnInstancedPickupInWorld, nullptr);

		UFunction* SpawnItemVariantPickupInWorldFunc = FortKismetLibraryClass->GetFunction("FortKismetLibrary", "SpawnItemVariantPickupInWorld");
		MinHook::HookFunctionExec(SpawnItemVariantPickupInWorldFunc, SpawnItemVariantPickupInWorld, nullptr);

		FN_LOG(LogInit, Log, "InitFortKismetLibrary Success!");
	}
}