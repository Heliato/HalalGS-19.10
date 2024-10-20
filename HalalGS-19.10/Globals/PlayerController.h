#pragma once

namespace PlayerController
{
	void InitPlayerController()
	{
		AFortPlayerControllerAthena* FortPlayerControllerAthenaDefault = AFortPlayerControllerAthena::GetDefaultObj();

		FN_LOG(LogInit, Log, "InitPlayerController Success!");
	}
}