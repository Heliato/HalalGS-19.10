#pragma once

namespace BuildingActor
{
	void InitBuildingActor()
	{
		ABuildingContainer* BuildingContainerDefault = ABuildingContainer::GetDefaultObj();

		FN_LOG(LogInit, Log, "InitBuildingActor Success!");
	}
}