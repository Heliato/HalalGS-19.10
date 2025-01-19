#pragma once

namespace FortAthenaSupplyDrop
{
	AFortGameModePickup* SpawnGameModePickup(AFortAthenaSupplyDrop* SupplyDrop, FFrame& Stack, AFortGameModePickup** Ret)
	{
		UFortWorldItemDefinition* ItemDefinition;
		TSubclassOf<AFortGameModePickup> PickupClass;
		int32 NumberToSpawn;
		AFortPawn* TriggeringPawn;
		FVector Position;
		FVector Direction;

		Stack.StepCompiledIn(&ItemDefinition);
		Stack.StepCompiledIn(&PickupClass);
		Stack.StepCompiledIn(&NumberToSpawn);
		Stack.StepCompiledIn(&TriggeringPawn);
		Stack.StepCompiledIn(&Position);
		Stack.StepCompiledIn(&Direction);

		Stack.Code += Stack.Code != nullptr;

		if (!ItemDefinition || !PickupClass.Get() || NumberToSpawn <= 0)
		{
			*Ret = nullptr;
			return *Ret;
		}

		UWorld* World = UEngine::GetEngine()->GetWorldFromContextObject(SupplyDrop, EGetWorldErrorMode::LogAndReturnNull);

		if (!World)
		{
			*Ret = nullptr;
			return *Ret;
		}

		FFortItemEntry ItemEntry;
		Inventory::MakeItemEntry(&ItemEntry, ItemDefinition, NumberToSpawn, -1, -1, -1.0f);

		FFortCreatePickupData* (*CreatePickupData)(FFortCreatePickupData* PickupData, UWorld* World, FFortItemEntry ItemEntry, FVector SpawnLocation, FRotator SpawnRotation, AFortPlayerController* PlayerController, UClass* OverrideClass, AActor* Investigator, int a9, int a10) = decltype(CreatePickupData)(0x64da9dc + uintptr_t(GetModuleHandle(0)));

		FFortCreatePickupData PickupData{};
		CreatePickupData(&PickupData, World, ItemEntry, Position, FRotator(), nullptr, nullptr, nullptr, 0, 0);
		PickupData.PickupSourceTypeFlags = EFortPickupSourceTypeFlag::Container;
		PickupData.PickupSpawnSource = EFortPickupSpawnSource::SupplyDrop;

		AFortPickup* (*CreatePickupFromData)(FFortCreatePickupData* PickupData) = decltype(CreatePickupFromData)(0x64dd1b4 + uintptr_t(GetModuleHandle(0)));
		AFortGameModePickup* GameModePickup = Cast<AFortGameModePickup>(CreatePickupFromData(&PickupData));

		if (GameModePickup)
		{
			GameModePickup->TossPickup(
				Position,
				nullptr,
				0,
				true,
				true,
				EFortPickupSourceTypeFlag::Container,
				EFortPickupSpawnSource::SupplyDrop
			);
		}

		ItemEntry.FreeItemEntry();

		FN_LOG(LogFortKismetLibrary, Log, __FUNCTION__);

		*Ret = GameModePickup;
		return *Ret;
	}

	AFortPickup* SpawnPickup(AFortAthenaSupplyDrop* SupplyDrop, FFrame& Stack, AFortPickup** Ret)
	{
		UFortWorldItemDefinition* ItemDefinition; 
		int32 NumberToSpawn; 
		AFortPawn* TriggeringPawn;
		FVector Position; 
		FVector Direction;

		Stack.StepCompiledIn(&ItemDefinition);
		Stack.StepCompiledIn(&NumberToSpawn);
		Stack.StepCompiledIn(&TriggeringPawn);
		Stack.StepCompiledIn(&Position);
		Stack.StepCompiledIn(&Direction);

		Stack.Code += Stack.Code != nullptr;

		if (!ItemDefinition || NumberToSpawn <= 0)
		{
			*Ret = nullptr;
			return *Ret;
		}

		UWorld* World = UEngine::GetEngine()->GetWorldFromContextObject(SupplyDrop, EGetWorldErrorMode::LogAndReturnNull);

		if (!World)
		{
			*Ret = nullptr;
			return *Ret;
		}

		FFortItemEntry ItemEntry;
		Inventory::MakeItemEntry(&ItemEntry, ItemDefinition, NumberToSpawn, -1, -1, -1.0f);

		FFortCreatePickupData* (*CreatePickupData)(FFortCreatePickupData* PickupData, UWorld* World, FFortItemEntry ItemEntry, FVector SpawnLocation, FRotator SpawnRotation, AFortPlayerController* PlayerController, UClass* OverrideClass, AActor* Investigator, int a9, int a10) = decltype(CreatePickupData)(0x64da9dc + uintptr_t(GetModuleHandle(0)));

		FFortCreatePickupData PickupData{};
		CreatePickupData(&PickupData, World, ItemEntry, Position, FRotator(), nullptr, nullptr, nullptr, 0, 0);
		PickupData.PickupSourceTypeFlags = EFortPickupSourceTypeFlag::Container;
		PickupData.PickupSpawnSource = EFortPickupSpawnSource::SupplyDrop;

		AFortPickup* (*CreatePickupFromData)(FFortCreatePickupData* PickupData) = decltype(CreatePickupFromData)(0x64dd1b4 + uintptr_t(GetModuleHandle(0)));
		AFortPickup* Pickup = CreatePickupFromData(&PickupData);

		if (Pickup)
		{
			Pickup->TossPickup(
				Position,
				nullptr,
				0,
				true,
				true,
				EFortPickupSourceTypeFlag::Container,
				EFortPickupSpawnSource::SupplyDrop
			);
		}

		ItemEntry.FreeItemEntry();

		FN_LOG(LogFortKismetLibrary, Log, __FUNCTION__);

		*Ret = Pickup;
		return *Ret;
	}

	AFortPickup* SpawnPickupFromItemEntry(AFortAthenaSupplyDrop* SupplyDrop, FFrame& Stack, AFortPickup** Ret)
	{
		UFortWorldItemDefinition* ItemDefinition; 
		FFortItemEntry InItemEntry; 
		int32 NumberToSpawn;
		AFortPawn* TriggeringPawn; 
		FVector Position; 
		FVector Direction;

		Stack.StepCompiledIn(&ItemDefinition);
		Stack.StepCompiledIn(&InItemEntry);
		Stack.StepCompiledIn(&NumberToSpawn);
		Stack.StepCompiledIn(&TriggeringPawn);
		Stack.StepCompiledIn(&Position);
		Stack.StepCompiledIn(&Direction);

		Stack.Code += Stack.Code != nullptr;

		if (!ItemDefinition || NumberToSpawn <= 0)
		{
			*Ret = nullptr;
			return *Ret;
		}

		UWorld* World = UEngine::GetEngine()->GetWorldFromContextObject(SupplyDrop, EGetWorldErrorMode::LogAndReturnNull);

		if (!World)
		{
			*Ret = nullptr;
			return *Ret;
		}

		FFortItemEntry ItemEntry;
		ItemEntry.CopyItemEntryWithReset(&InItemEntry);

		FFortCreatePickupData* (*CreatePickupData)(FFortCreatePickupData* PickupData, UWorld* World, FFortItemEntry ItemEntry, FVector SpawnLocation, FRotator SpawnRotation, AFortPlayerController* PlayerController, UClass* OverrideClass, AActor* Investigator, int a9, int a10) = decltype(CreatePickupData)(0x64da9dc + uintptr_t(GetModuleHandle(0)));

		FFortCreatePickupData PickupData{};
		CreatePickupData(&PickupData, World, ItemEntry, Position, FRotator(), nullptr, nullptr, nullptr, 0, 0);
		PickupData.PickupSourceTypeFlags = EFortPickupSourceTypeFlag::Container;
		PickupData.PickupSpawnSource = EFortPickupSpawnSource::SupplyDrop;

		AFortPickup* (*CreatePickupFromData)(FFortCreatePickupData* PickupData) = decltype(CreatePickupFromData)(0x64dd1b4 + uintptr_t(GetModuleHandle(0)));
		AFortPickup* Pickup = CreatePickupFromData(&PickupData);

		if (Pickup)
		{
			Pickup->TossPickup(
				Position,
				nullptr,
				0,
				true,
				true,
				EFortPickupSourceTypeFlag::Container,
				EFortPickupSpawnSource::SupplyDrop
			);
		}

		ItemEntry.FreeItemEntry();

		FN_LOG(LogFortKismetLibrary, Log, __FUNCTION__);

		*Ret = Pickup;
		return *Ret;
	}
	void InitFortAthenaSupplyDrop()
	{
		AFortAthenaSupplyDrop* FortAthenaSupplyDropDefault = AFortAthenaSupplyDrop::GetDefaultObj();
		UClass* FortAthenaSupplyDropClass = AFortAthenaSupplyDrop::StaticClass();

		UFunction* SpawnGameModePickupFunc = FortAthenaSupplyDropClass->GetFunction("FortAthenaSupplyDrop", "SpawnGameModePickup");
		MinHook::HookFunctionExec(SpawnGameModePickupFunc, SpawnGameModePickup, nullptr);

		UFunction* SpawnPickupFunc = FortAthenaSupplyDropClass->GetFunction("FortAthenaSupplyDrop", "SpawnPickup");
		MinHook::HookFunctionExec(SpawnPickupFunc, SpawnPickup, nullptr);

		UFunction* SpawnPickupFromItemEntryFunc = FortAthenaSupplyDropClass->GetFunction("FortAthenaSupplyDrop", "SpawnPickupFromItemEntry");
		MinHook::HookFunctionExec(SpawnPickupFromItemEntryFunc, SpawnPickupFromItemEntry, nullptr);

		FN_LOG(LogInit, Log, "FortAthenaSupplyDrop Success!");
	}
}