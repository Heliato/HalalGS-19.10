#pragma once

namespace Pickup
{
	bool (*PickupAddInventoryOwnerInterfaceOG)(AFortPickup* Pickup, void* InventoryOwner, bool bDestroyPickup);
	void (*TossPickupOG)(AFortPickup* Pickup, const FVector& FinalLocation, class AFortPawn* ItemOwner, int32 OverrideMaxStackCount, bool bToss);
	void (*OnServerStopCallbackOG)(AFortPickup* Pickup, const FHitResult& Hit);

	bool PickupAddInventoryOwnerInterface(AFortPickup* Pickup, void* InventoryOwner, bool bDestroyPickup)
	{
		PickupAddInventoryOwnerInterfaceOG(Pickup, InventoryOwner, bDestroyPickup);

		if (!Pickup || !InventoryOwner)
			return false;

		AFortPlayerController* PlayerController = AFortPlayerController::GetPlayerControllerFromInventoryOwner(InventoryOwner);
		if (!PlayerController) return false;

		AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;
		if (!PlayerPawn) return false;

		for (int32 i = 0; i < PlayerPawn->QueuedAutoPickups.Num(); i++)
		{
			AFortPickup* QueuedAutoPickup = PlayerPawn->QueuedAutoPickups[i];
			if (!QueuedAutoPickup) continue;

			if (QueuedAutoPickup == Pickup)
			{
				PlayerPawn->QueuedAutoPickups.Remove(i);
				break;
			}
		}

		Inventory::AddInventoryItem(PlayerController, Pickup->PrimaryPickupItemEntry, Pickup->PickupLocationData.PickupGuid);

		return true;
	}

	void TossPickup(AFortPickup* Pickup, const FVector& FinalLocation, class AFortPawn* ItemOwner, int32 OverrideMaxStackCount, bool bToss)
	{
		TossPickupOG(Pickup, FinalLocation, ItemOwner, OverrideMaxStackCount, bToss);

		if (Pickup->bActorIsBeingDestroyed || Pickup->bTossedFromContainer)
			return;

		Inventory::CombineNearestPickup(Pickup, 300.0f);
	}

	void OnServerStopCallback(AFortPickup* Pickup, const FHitResult& Hit)
	{
		OnServerStopCallbackOG(Pickup, Hit);

		if (Pickup->bActorIsBeingDestroyed || !Pickup->bCombinePickupsWhenTossCompletes)
			return;

		FN_LOG(LogPlayerController, Warning, "OnServerStopCallback - Pickup: %s", Pickup->GetName().c_str());

		//return;

		Inventory::CombineNearestPickup(Pickup, 300.0f);
	}

	void CombinePickup(AFortPickup* Pickup, FFrame& Stack, void* Ret)
	{
		Stack.Code += Stack.Code != nullptr;

		if (Pickup->bActorIsBeingDestroyed)
			return;

		AFortPickup* CombineTarget = Pickup->PickupLocationData.CombineTarget;

		if (!CombineTarget || CombineTarget->bActorIsBeingDestroyed)
			return;

		UFortWorldItemDefinition* WorldItemDefinition = Cast<UFortWorldItemDefinition>(CombineTarget->PrimaryPickupItemEntry.ItemDefinition);
		if (!WorldItemDefinition) return;

		int32 MaxStackSize = WorldItemDefinition->MaxStackSize.GetValueAtLevel(0);

		int32 NewCount = Pickup->PrimaryPickupItemEntry.Count + CombineTarget->PrimaryPickupItemEntry.Count;
		int32 CountToRemove = UKismetMathLibrary::Max(0, NewCount - MaxStackSize);
		NewCount = UKismetMathLibrary::Min(NewCount, MaxStackSize);

		CombineTarget->PrimaryPickupItemEntry.SetCount(NewCount);
		CombineTarget->FlushNetDormancy();

		if (CountToRemove > 0)
		{
			FFortItemEntry ItemEntry;
			Inventory::MakeItemEntry(&ItemEntry, WorldItemDefinition, CountToRemove, Pickup->PrimaryPickupItemEntry.Level, Pickup->PrimaryPickupItemEntry.LoadedAmmo, Pickup->PrimaryPickupItemEntry.Durability);

			const FVector& SpawnLocation = CombineTarget->K2_GetActorLocation();

			TWeakObjectPtr<AFortPlayerController> WeakPlayerController{};
			WeakPlayerController.ObjectIndex = -1;
			WeakPlayerController.ObjectSerialNumber = 0;

			TWeakObjectPtr<AActor> WeakInvestigator{};
			WeakInvestigator.ObjectIndex = -1;
			WeakInvestigator.ObjectSerialNumber = 0;

			FFortCreatePickupData PickupData{};
			PickupData.World = Pickup->GetWorld();
			PickupData.ItemEntry = ItemEntry;
			PickupData.SpawnLocation = SpawnLocation;
			PickupData.SpawnRotation = FRotator();
			PickupData.WeakPlayerController = WeakPlayerController;
			PickupData.OverrideClass = Pickup->Class;
			PickupData.WeakInvestigator = WeakInvestigator;
			PickupData.PickupSourceTypeFlags = Pickup->PickupSourceTypeFlags;
			PickupData.PickupSpawnSource = Pickup->PickupSpawnSource;
			PickupData.bRandomRotation = Pickup->bRandomRotation;
			PickupData.BitPad_1DA_1 = false;

			AFortPickup* (*CreatePickupFromData)(FFortCreatePickupData* PickupData) = decltype(CreatePickupFromData)(0x64dd1b4 + uintptr_t(GetModuleHandle(0)));
			AFortPickup* NewPickup = CreatePickupFromData(&PickupData);

			if (NewPickup)
			{
				NewPickup->PawnWhoDroppedPickup = Pickup->PawnWhoDroppedPickup;
				NewPickup->bCombinePickupsWhenTossCompletes = Pickup->bCombinePickupsWhenTossCompletes;
				NewPickup->TossPickup(SpawnLocation, Pickup->PawnWhoDroppedPickup, 0, true, true, Pickup->PickupSourceTypeFlags, Pickup->PickupSpawnSource);
			}

			ItemEntry.FreeItemEntry();
		}

		Pickup->K2_DestroyActor();
	}

	void InitPickup()
	{
		AFortPickupAthena* FortPickupAthenaDefault = AFortPickupAthena::GetDefaultObj();
		UClass* FortPickupAthenaClass = AFortPickupAthena::StaticClass();

		MinHook::HookVTable(FortPickupAthenaDefault, 0x6D0 / 8, PickupAddInventoryOwnerInterface, (LPVOID*)(&PickupAddInventoryOwnerInterfaceOG), "AFortPickup::PickupAddInventoryOwnerInterface");

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x64e8838), TossPickup, (LPVOID*)(&TossPickupOG));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x64e8838));

		// MinHook::HookVTable(FortPickupAthenaDefault, 0x710 / 8, OnServerStopCallback, (LPVOID*)(&OnServerStopCallbackOG), "AFortPickup::OnServerStopCallback");

		UFunction* OnRep_ServerImpactSoundFlashFunc = FortPickupAthenaClass->GetFunction("FortPickup", "OnRep_ServerImpactSoundFlash");
		MinHook::HookFunctionExec(OnRep_ServerImpactSoundFlashFunc, CombinePickup, nullptr);

		FN_LOG(LogInit, Log, "InitPawn Success!");
	}
}