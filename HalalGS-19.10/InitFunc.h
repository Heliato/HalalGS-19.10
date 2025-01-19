#pragma once

namespace InitFunc
{
	bool InitializeAll()
	{
		uintptr_t AddressFMemoryRealloc = MinHook::FindPattern(Patterns::FMemoryRealloc);
		uintptr_t AddressFMemoryFree = MinHook::FindPattern(Patterns::FMemoryFree);

		UC::FMemory_Realloc = decltype(UC::FMemory_Realloc)(AddressFMemoryRealloc);
		UC::FMemory_Free = decltype(UC::FMemory_Free)(AddressFMemoryFree);

		// Globals
		GameMode::InitGameMode();
		PlayerController::InitPlayerController();
		Pawn::InitPawn();
		BuildingActor::InitBuildingActor();
		FortKismetLibrary::InitFortKismetLibrary();
		FortAthenaSupplyDrop::InitFortAthenaSupplyDrop();
		Pickup::InitPickup();
		DecoTool::InitDecoTool();

		// Functions
		Beacon::InitBeacon();
		Abilities::InitAbilities();
		Inventory::InitInventory();
		Functions::InitFunctions();
		Cheats::InitCheats();
		Navigation::InitNavigation();

		return true;
	}
}
