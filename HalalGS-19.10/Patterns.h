#pragma once

namespace Patterns
{
	// Base
	constexpr const char* FMemoryFree = "48 85 C9 0F 84 ? ? ? ? 53 48 83 EC 20 48 89 7C 24 ? 48 8B D9"; // Fait
	constexpr const char* FMemoryRealloc = "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 48 8B F1 41 8B D8 48 8B 0D ? ? ? ? 48 8B FA"; // Fait

	// SupplyDrop
	constexpr const char* SpawningLootOnDestruction = "48 85 D2 74 68 57 48 83 EC 20 48 89 5C 24 ? 48 8B F9 48 8B 9A ? ? ? ? 48 85 DB 74 45";

	// BuildingActor
	constexpr const char* ABuildingSMActor_PostUpdate = "48 83 EC 58 80 3D ? ? ? ? ? 72 51 8B 81 ? ? ? ? 48 8D 54 24 ? 45 33 C0 89 44 24 78 E8 ? ? ? ? 83 78 08 00 74 05"; // fait

	// GameMode
	constexpr const char* HandlePostSafeZonePhaseChanged = "48 8B C4 48 89 58 10 48 89 70 18 48 89 78 20 55 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 C8 0F 29 78 B8 44 0F 29 40 ? 44 0F 29 48 ? 44 0F 29 50 ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 44 8B F2 89 54 24 48 4C 8B F9"; // fait
	constexpr const char* StartAircraftPhase = "48 8B C4 48 89 58 10 48 89 70 18 48 89 78 20 55 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 C8 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 45 33 ED 48 89 4C 24 ? 44 38 2D ? ? ? ? 48 8D 05 ? ? ? ? 44 8A E2 44 89 6C 24 ? 49 0F 45 C5 48 8B F9 48 89 45 88 E8 ? ? ? ? 48 89 44 24 ? 4C 8B F8 48 85 C0 74 0D"; // fait

	// PlayerController
	constexpr const char* RemoveInventoryItem = "48 83 EC 48 80 B9 ? ? ? ? ? 74 22 0F 10 02 8A 44 24 70 48 8D 54 24 ? 48 81 C1 ? ? ? ? 88 44 24 20"; // fait
	constexpr const char* ModifyLoadedAmmo = "40 53 48 83 EC 30 80 B9 ? ? ? ? ? 41 8B D8 75 3F"; // (1.7.2 - 12.10)

	// Beacon
	constexpr const char* TickFlush = "48 8B C4 48 89 58 18 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 B8 0F 29 78 A8 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 44 8A A1 ? ? ? ? 48 8D 15 ? ? ? ? 48 8B F9 44 88 64 24 ? BB ? ? ? ? 0F 28 F9 88 99 ? ? ? ? 48 8D 4D 40"; // fait

	// Others
	constexpr const char* GetWorldFromContextObject = "48 89 5C 24 18 56 48 83 EC 40 41 8B D8";
	constexpr const char* InternalGetNetMode = "48 83 79 ? ? 75 19 48 8B 81 ? ? ? ? 48 85 C0 74 08 48 8B C8 E9 ? ? ? ?"; // Fait
	constexpr const char* ActorInternalGetNetMode = "48 89 5C 24 ? 57 48 83 EC 20 F6 41 08 10 48 8B D9 0F 85 ? ? ? ? 48 8B 41 20 48 85 C0 0F 84 ? ? ? ? F7 40 ? ? ? ? ? 0F 85 ? ? ? ? 8B 40 0C"; // Fait
	constexpr const char* GetPlayerViewPoint = "48 8B C4 48 89 58 10 48 89 70 18 55 57 41 54 41 56 41 57 48 8D 68 A1 48 81 EC ? ? ? ? 0F 29 70 C8 48 8B FA 48 8B 55 5F 48 8B D9 0F 29 78 B8 49 8B F0 44 0F 29 40 ? 44 0F 29 48 ? 8A 4A FB 44 0F 29 50 ? 44 0F 29 5C 24 ? 44 0F 29 64 24 ? 44 0F 29 6C 24 ? 80 F9 E8"; // Fait
	constexpr const char* DispatchRequest = "48 89 5C 24 ? 48 89 74 24 ? 55 57 41 56 48 8D 6C 24 ? 48 81 EC ? ? ? ? 80 3D ? ? ? ? ? 48 8D 3D ? ? ? ? 41 8B D8 4C 8B F2 48 8B F1 73 7D"; // Fait
	constexpr const char* KickPlayer = "48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 45 33 ED 48 8B FA 41 8B DD 4C 8B F9 89 9D ? ? ? ? E8 ? ? ? ?"; // Fait
	constexpr const char* ChangingGameSessionId = "48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8B EC 48 83 EC 50 4C 8B FA 48 8B F1"; // Fait
	constexpr const char* LocalSpawnPlayActor = "48 8B C4 48 89 58 10 48 89 70 18 48 89 78 20 55 41 56 41 57 48 8D 68 C8 48 81 EC ? ? ? ? 48 8B D9 4D 8B F1"; // Fait
}