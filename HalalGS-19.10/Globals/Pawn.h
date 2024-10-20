#pragma once

namespace Pawn
{
	void InitPawn()
	{
		AFortPlayerPawnAthena* FortPlayerPawnAthenaDefault = AFortPlayerPawnAthena::GetDefaultObj();

		FN_LOG(LogInit, Log, "InitPawn Success!");
	}
}