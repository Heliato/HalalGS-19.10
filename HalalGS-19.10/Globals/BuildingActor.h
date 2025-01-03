#pragma once

namespace BuildingActor
{
	bool SpawnLoot(ABuildingContainer* BuildingContainer, AFortPlayerPawn* PlayerPawn)
	{
		FN_LOG(LogBuildingActor, Log, "ABuildingContainer::SpawnLoot called - BuildingContainer: %s, PlayerPawn: %s", BuildingContainer->GetFullName().c_str(), PlayerPawn->GetFullName().c_str());
		return true;
	}

	void InitBuildingActor()
	{
		ABuildingContainer* BuildingContainerDefault = ABuildingContainer::GetDefaultObj();

		MinHook::HookVTable(BuildingContainerDefault, 0xF88 / 8, SpawnLoot, nullptr, "ABuildingContainer::SpawnLoot");

		FN_LOG(LogInit, Log, "InitBuildingActor Success!");
	}
}