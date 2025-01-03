#pragma once

namespace Pawn
{
	void ServerHandlePickupInfo(AFortPlayerPawn* PlayerPawn, AFortPickup* PickUp, const FFortPickupRequestInfo& Params_0)
	{
		if (!PickUp || PlayerPawn->bIsDBNO)
			return;

		float FlyTime = Params_0.FlyTime / PlayerPawn->PickupSpeedMultiplier;

		PickUp->PickupLocationData.PickupGuid = PlayerPawn->CurrentWeapon ? PlayerPawn->CurrentWeapon->ItemEntryGuid : FGuid();
		PickUp->SetPickupTarget(PlayerPawn, FlyTime, PickUp->PickupLocationData.StartDirection, PickUp->PickupLocationData.bPlayPickupSound);
	}

	void InitPawn()
	{
		AFortPlayerPawnAthena* FortPlayerPawnAthenaDefault = AFortPlayerPawnAthena::GetDefaultObj();

		MinHook::HookVTable(FortPlayerPawnAthenaDefault, 0x1100 / 8, ServerHandlePickupInfo, nullptr, "AFortPlayerPawn::ServerHandlePickupInfo");

		FN_LOG(LogInit, Log, "InitPawn Success!");
	}
}