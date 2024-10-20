#pragma once

namespace Pickup
{
	void InitPickup()
	{
		AFortPickupAthena* FortPickupAthenaDefault = AFortPickupAthena::GetDefaultObj();

		FN_LOG(LogInit, Log, "InitPawn Success!");
	}
}