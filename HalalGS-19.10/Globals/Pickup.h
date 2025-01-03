#pragma once

namespace Pickup
{
	bool (*PickupAddInventoryOwnerInterfaceOG)(AFortPickup* Pickup, void* InventoryOwner, bool bDestroyPickup);

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

	void InitPickup()
	{
		AFortPickupAthena* FortPickupAthenaDefault = AFortPickupAthena::GetDefaultObj();

		MinHook::HookVTable(FortPickupAthenaDefault, 0x6D0 / 8, PickupAddInventoryOwnerInterface, (LPVOID*)(&PickupAddInventoryOwnerInterfaceOG), "AFortPickup::PickupAddInventoryOwnerInterface");

		FN_LOG(LogInit, Log, "InitPawn Success!");
	}
}