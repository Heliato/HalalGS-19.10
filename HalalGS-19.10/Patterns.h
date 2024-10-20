#pragma once

namespace Patterns
{
	// Base
	constexpr const char* FMemoryFree = "48 85 C9 0F 84 ? ? ? ? 53 48 83 EC 20 48 89 7C 24 ? 48 8B D9"; // Fait
	constexpr const char* FMemoryRealloc = "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 48 8B F1 41 8B D8 48 8B 0D ? ? ? ? 48 8B FA"; // Fait

	// SupplyDrop
	constexpr const char* PickSupplyDropLocation = "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 48 81 EC ? ? ? ? 0F 29 74 24 ?";
	constexpr const char* SpawnSupplyDrop = "40 53 55 56 41 56 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 84 24 ? ? ? ? 49 8B D9";
	constexpr const char* SpawningLootOnDestruction = "48 85 D2 74 68 57 48 83 EC 20 48 89 5C 24 ? 48 8B F9 48 8B 9A ? ? ? ? 48 85 DB 74 45";

	// BuildingActor
	constexpr const char* PickLootTierGroupAthena = "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 65 48 8B 04 25 ? ? ? ? 48 8B F2 8B 0D ? ? ? ? 49 8B D8";
	constexpr const char* ABuildingSMActor_PostUpdate = "48 89 5C 24 ? 57 48 83 EC 50 49 8B F8 48 8B D9";
	constexpr const char* SelectMeshSetByLootTier = "48 8B C4 89 50 10 55 53 41 55 48 8D 68 A1 48 81 EC ? ? ? ?";
	constexpr const char* SetMeshSet = "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 48 8B FA 48 8B D9 E8 ? ? ? ? 48 8B 03 48 8B CB";
	constexpr const char* OnSearchedContainer = "40 53 56 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 84 24 ? ? ? ? 48 8B 01 B2 01 48 8B D9";
	constexpr const char* DetermineMaxResourcesToSpawn = "48 89 5C 24 ? 48 89 7C 24 ? 41 56 48 83 EC 50 65 48 8B 04 25 ? ? ? ? 4C 8B F1";

	// Pickup
	constexpr const char* PickupAddInventoryOwnerInterface = "40 53 48 83 EC 20 80 B9 ? ? ? ? ? 48 8B D9 75 29 48 85 D2 74 24 F3 0F 10 15 ? ? ? ? 0F 57 DB B2 05";
	constexpr const char* PickupCombine = "4C 8B DC 53 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 84 24 ? ? ? ? 48 83 B9 ? ? ? ? ? 48 8B D9";

	// GameMode
	constexpr const char* AddFromAlivePlayers = "48 85 D2 0F 84 ? ? ? ? 56 57 48 83 EC 78";
	constexpr const char* RemoveFromAlivePlayers = "4C 89 4C 24 ? 4C 89 44 24 ? 55 41 55 41 56 41 57 48 8D 6C 24 ?";
	constexpr const char* SpawnDefaultPawnFor = "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 30 49 8B F0 48 8B FA 48 8B D9 48 85 D2";
	constexpr const char* HandleMatchHasStarted = "4C 8B DC 53 48 83 EC 70 80 3D ? ? ? ? ? 48 8B D9 49 89 73 18 49 89 7B F0 72 3B";
	constexpr const char* HandlePostSafeZonePhaseChanged = "48 89 5C 24 ? 55 56 57 41 56 41 57 48 81 EC ? ? ? ? 48 8B B9 ? ? ? ? 33 DB";
	constexpr const char* StartAircraftPhase = "4C 8B DC 55 49 8D 6B 98 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 20 49 89 73 18 48 8D 05 ? ? ? ? 33 F6";
	// constexpr const char* SetGameMode = "48 89 6C 24 ? 56 48 81 EC ? ? ? ? 48 8B F1 48 8B EA 48 8B 49 38 48 85 C9";

	// Pawn
	constexpr const char* SetPickupTarget = "40 55 53 56 41 54 48 8D 6C 24 B8";

	// PlayerController
	constexpr const char* RemoveInventoryItem = "48 83 EC 48 80 B9 ? ? ? ? ? 74 22 0F 10 02 0F B6 44 24 ?";
	constexpr const char* ModifyLoadedAmmo = "40 53 48 83 EC 30 80 B9 ? ? ? ? ? 41 8B D8 75 3F"; // (1.7.2 - 12.10)
	constexpr const char* GetRepairResourceAmount = "40 55 53 57 41 56 48 8D 6C 24 ? 48 81 EC ? ? ? ? 48 8B 01 4C 8B F2 48 8B F9";
	constexpr const char* GetCreateResourceAmount = "41 54 41 56 48 83 EC 38 48 83 3A 00 4C 8B F2 4C 8B E1 74 1E E8 ? ? ? ? 49 8B 16";
	constexpr const char* PayRepairCosts = "40 57 41 54 41 55 41 57 48 83 EC 78";
	constexpr const char* PayBuildingCosts = "48 89 5C 24 18 56 57 41 56 48 83 EC 50 48 83 3A 00";
	constexpr const char* CanAddBuildingActorToGrid = "48 89 5C 24 ? 48 89 6C 24 ? 48 89 7C 24 ? 41 54 41 56 41 57 48 83 EC 50 33 FF";
	constexpr const char* CheckBeginEditBuildingActor = "48 89 5C 24 ? 55 56 57 48 8B EC 48 83 EC 60 48 8B F2 48 8B F9 48 85 D2";
	constexpr const char* ReplaceBuildingActor = "48 8B C4 44 89 48 20 55 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 48 89 70 E8 33 FF 40 38 3D ? ? ? ? 48 8B F1";
	constexpr const char* OnEnterAircraft = "40 55 56 57 41 56 48 8D 6C 24 ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 E0 80 B9 ? ? ? ? ? 48 8D 3D ? ? ? ?";
	constexpr const char* ToDeathCause = "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 0F B6 FA 48 8B D9 E8 ? ? ? ? 33 F6";

	constexpr const char* EquipWeaponDefinition = "48 89 6C 24 ? 56 57 41 56 48 83 EC 40 49 8B E8 48 8B F2 4C 8B F1";
	constexpr const char* EquipDecoDefinition = "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC 20 49 8B D8 48 8B F2";
	constexpr const char* EquipContextTrapDefinition = "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 48 83 EC 20 49 8B D8 4C 8B F2";

	// Beacon
	constexpr const char* InitHost = "48 8B C4 48 81 EC B8 00 00 00 48 89 58 18";
	constexpr const char* InitListen = "48 89 5C 24 10 48 89 74 24 18 57 48 83 EC 50 48 8B BC 24 80 00 00 00";
	constexpr const char* Listen = "E8 ? ? ? ? 84 C0 75 73 80 3D ? ? ? ? ? 72 6A 45 33 C0 48 8D 95 ? ? ? ? 48 8B CF E8 ? ? ? ? 83 78 08 00 74 05 48 8B 08 EB 07";
	constexpr const char* SetWorld = "48 89 5C 24 ? 57 48 83 EC 20 48 8B FA 48 8B D9 48 8B 91 ? ? ? ? 48 85 D2 74 28";
	constexpr const char* TickFlush = "4C 8B DC 55 49 8D AB 98 FE FF FF 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 00 01 00 00 49 89 5B 18 48 8D 05 ? ? ? ?";
	constexpr const char* ServerReplicateActors = "4C 8B DC 55 49 8D AB ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 48 8B 41 30 45 33 C0";

	// Abilities
	constexpr const char* InternalTryActivateAbility = "4C 89 4C 24 20 4C 89 44 24 18 89 54 24 10 55 53 56";
	constexpr const char* GiveAbility = "48 89 5C 24 ? 48 89 6C 24 ? 48 89 7C 24 ? 41 56 48 83 EC 20 83 B9 ? ? ? ? ? 49 8B E8 4C 8B F2 48 8B F9 7E 56";
	constexpr const char* CreateDefaultObject = "4C 8B DC 57 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 84 24 ? ? ? ? 48 83 B9 ? ? ? ? ? 48 8B F9";
	constexpr const char* GiveAbilityAndActivateOnce = "48 89 5C 24 ? 55 56 57 48 8B EC 48 83 EC 70 49 8B 40 10 49 8B D8";
	constexpr const char* CreateDefaultAbilitySpec = "80 61 29 F8 48 8B 44 24 ? 48 89 41 20 33 C0";
	constexpr const char* CopyAbilitySpec = "48 89 5C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC 20 48 8B F2 48 8B F9 48 3B D1";

	// Inventory
	constexpr const char* CreatePickupFromData = "48 89 5C 24 ? 55 48 8D 6C 24 ? 48 81 EC ? ? ? ? 48 8B 41 08 48 8B D9";
	constexpr const char* CreateSimplePickup = "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 60 48 8B 01 49 8B D9";
	constexpr const char* CreateItemEntry = "48 89 5C 24 ? 57 48 83 EC 20 33 FF 48 C7 01 ? ? ? ? 48 89 79 18 48 8B D9 89 79 28";
	constexpr const char* CreateDefaultItemEntry = "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 33 F6 48 C7 01 ? ? ? ? C7 41 ? ? ? ? ? 45 85 C0";
	constexpr const char* SetStateValue = "48 89 5C 24 ? 48 89 6C 24 ? 56 41 56 41 57 48 83 EC 20 48 63 81 ? ? ? ? 45 33 F6";
	constexpr const char* PickupInitialize = "48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC 20 80 B9 ? ? ? ? ? 41 0F B6 E9 49 8B F8";
	constexpr const char* CopyItemEntry = "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 54 41 56 41 57 48 83 EC 30 8B 42 0C";
	constexpr const char* MarkItemEntryDirty = "48 89 74 24 ? 57 48 83 EC 40 80 B9 ? ? ? ? ? 48 8B F2 48 8B F9 0F 85 ? ? ? ? 80 7A 61 00";
	constexpr const char* AddWorldItem = "48 89 5C 24 ? 57 48 83 EC 40 80 B9 ? ? ? ? ? 48 8B FA 48 8B D9 0F 84 ? ? ? ? 48 8B 02";
	constexpr const char* FreeItemEntry = "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 48 8B F1 48 8B 89 ? ? ? ? 48 85 C9 74 05 E8 ? ? ? ? 48 8B 8E ? ? ? ? 48 85 C9 74 05 E8 ? ? ? ? 48 8B 8E ? ? ? ? 48 85 C9 74 05";
	constexpr const char* FindItemInstancesFromDefinition = "48 89 5C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 48 83 EC 30 45 33 F6 49 8B D8 48 8B FA";

	// Others
	constexpr const char* GetWorldFromContextObject = "48 89 5C 24 18 56 48 83 EC 40 41 8B D8";
	constexpr const char* InternalGetNetMode = "48 83 79 ? ? 75 19 48 8B 81 ? ? ? ? 48 85 C0 74 08 48 8B C8 E9 ? ? ? ?"; // Fait
	constexpr const char* ActorInternalGetNetMode = "48 89 5C 24 ? 57 48 83 EC 20 F6 41 08 10 48 8B D9 0F 85 ? ? ? ? 48 8B 41 20 48 85 C0 0F 84 ? ? ? ? F7 40 ? ? ? ? ? 0F 85 ? ? ? ? 8B 40 0C"; // Fait
	constexpr const char* GetPlayerViewPoint = "48 89 5C 24 ? 48 89 74 24 ? 55 41 56 41 57 48 8B EC 48 83 EC 40 48 8B F2 48 C7 45 ? ? ? ? ? 48 8B 55 38";
	constexpr const char* DispatchRequest = "48 89 5C 24 20 55 56 57 41 56 41 57 48 8B EC 48 83 EC 70 48 8B F1";
	constexpr const char* ServerSpawnDeco = "40 53 55 41 56 48 83 EC 60 41 8B 41 08 49 8B E8 F2 41 0F 10 01 4C 8B F1";
	constexpr const char* ApplyCustomizationToCharacter = "40 53 55 56 57 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 84 24 ? ? ? ? 80 B9 ? ? ? ? ? 48 8B F9";
	constexpr const char* KickPlayer = "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 49 8B F0 48 8B DA 48 85 D2 0F 84 ? ? ? ? 48 8B BA ? ? ? ? 48 85 FF";
	constexpr const char* ChangingGameSessionId = "40 55 56 41 56 48 8D 6C 24 ? 48 81 EC ? ? ? ? 48 8B 01 4C 8B F2 48 8B F1 FF 90 ? ? ? ? 48 8B 0D ? ? ? ? 48 8B D0";
	constexpr const char* LocalSpawnPlayActor = "48 8B C4 48 89 58 10 48 89 70 18 48 89 78 20 55 41 56 41 57 48 8D 68 C8 48 81 EC ? ? ? ? 48 8B D9 4D 8B F1"; // Fait
}