#pragma once
namespace FortAthenaSupplyDrop
{
	void InitFortAthenaSupplyDrop()
	{
		AFortAthenaSupplyDrop* FortAthenaSupplyDropDefault = AFortAthenaSupplyDrop::GetDefaultObj();

		FN_LOG(LogInit, Log, "FortAthenaSupplyDrop Success!");
	}
}