#pragma once

namespace Pawn
{
	void (*OnDeathServerOG)(AFortPawn* Pawn, float Damage, const FGameplayTagContainer& DamageTags, const FVector& Momentum, const FHitResult& HitInfo, AController* InstigatedBy, AActor* DamageCauser, const FGameplayEffectContextHandle& EffectContext);

	void ServerHandlePickupInfo(AFortPlayerPawn* PlayerPawn, AFortPickup* PickUp, const FFortPickupRequestInfo& Params_0)
	{
		if (!PickUp || PlayerPawn->bIsDBNO)
			return;

		float FlyTime = Params_0.FlyTime / PlayerPawn->PickupSpeedMultiplier;

		PickUp->PickupLocationData.PickupGuid = PlayerPawn->CurrentWeapon ? PlayerPawn->CurrentWeapon->ItemEntryGuid : FGuid();
		PickUp->SetPickupTarget(PlayerPawn, FlyTime, PickUp->PickupLocationData.StartDirection, PickUp->PickupLocationData.bPlayPickupSound);
	}

	void OnCapsuleBeginOverlap(AFortPlayerPawn* PlayerPawn, FFrame& Stack, void* Ret)
	{
		UPrimitiveComponent* OverlappedComp;
		AActor* OtherActor;
		UPrimitiveComponent* OtherComp;
		int32 OtherBodyIndex;
		bool bFromSweep;
		FHitResult SweepResult;

		Stack.StepCompiledIn(&OverlappedComp);
		Stack.StepCompiledIn(&OtherActor);
		Stack.StepCompiledIn(&OtherComp);
		Stack.StepCompiledIn(&OtherBodyIndex);
		Stack.StepCompiledIn(&bFromSweep);
		Stack.StepCompiledIn(&SweepResult);

		Stack.Code += Stack.Code != nullptr;

		AFortPlayerController* PlayerController = Cast<AFortPlayerController>(PlayerPawn->Controller);
		if (!PlayerController) return;

		AFortPickup* Pickup = Cast<AFortPickup>(OtherActor);
		if (!Pickup) return;

		if (!PlayerPawn->bIsDBNO ||
			!PlayerPawn->bIsSkydiving)
		{
			if (Pickup->bPickedUp || !Pickup->bWeaponsCanBeAutoPickups)
				return;

			if (!Pickup->bServerStoppedSimulation && (Pickup->PawnWhoDroppedPickup == PlayerPawn))
				return;

			if (Pickup->PawnWhoDroppedPickup == PlayerPawn)
			{
				bool (*CanAutoPickup)(AFortPickup* Pickup, AFortPlayerPawn* PlayerPawn) = decltype(CanAutoPickup)(0x64dc9f4 + uintptr_t(GetModuleHandle(0)));

				if (!CanAutoPickup(Pickup, PlayerPawn))
					return;
			}

			UFortWorldItemDefinition* WorldItemDefinition = Cast<UFortWorldItemDefinition>(Pickup->PrimaryPickupItemEntry.ItemDefinition);
			if (!WorldItemDefinition) return;

			if (WorldItemDefinition->IsA(UFortAmmoItemDefinition::StaticClass()) || WorldItemDefinition->IsA(UFortResourceItemDefinition::StaticClass()))
			{
				int32 ItemQuantity = UFortKismetLibrary::K2_GetItemQuantityOnPlayer(PlayerController, WorldItemDefinition, FGuid());

				for (int32 i = 0; i < PlayerPawn->QueuedAutoPickups.Num(); i++)
				{
					AFortPickup* QueuedAutoPickup = PlayerPawn->QueuedAutoPickups[i];
					if (!QueuedAutoPickup) continue;

					UFortWorldItemDefinition* QueuedWorldItemDefinition = Cast<UFortWorldItemDefinition>(QueuedAutoPickup->PrimaryPickupItemEntry.ItemDefinition);
					if (!QueuedWorldItemDefinition) continue;

					if (QueuedWorldItemDefinition != WorldItemDefinition)
						continue;

					ItemQuantity += QueuedAutoPickup->PrimaryPickupItemEntry.Count;
				}

				int32 MaxStackSize = WorldItemDefinition->MaxStackSize.GetValueAtLevel(0);

				if (ItemQuantity >= MaxStackSize && !WorldItemDefinition->bAllowMultipleStacks)
					return;

				PlayerPawn->QueuedAutoPickups.Add(Pickup);

				float InFlyTime = Pickup->GenFlyTime();
				PlayerPawn->ServerHandlePickup(Pickup, InFlyTime, FVector(), true);
			}
		}
	}

	void PlayGroupEmote(AFortPlayerPawn* PlayerPawn, FFrame& Stack, void* Ret)
	{
		UFortMontageItemDefinitionBase* EmoteAsset;

		Stack.StepCompiledIn(&EmoteAsset);

		Stack.Code += Stack.Code != nullptr;

		FN_LOG(LogInit, Log, "PlayGroupEmote called - EmoteAsset: %s", EmoteAsset->GetFullName().c_str());
	}

	void MovingEmoteStopped(AFortPawn* Pawn, FFrame& Stack, void* Ret)
	{
		Stack.Code += Stack.Code != nullptr;

		Pawn->bMovingEmote = false;
		Pawn->bMovingEmoteSkipLandingFX = false;
		Pawn->bMovingEmoteForwardOnly = false;
		Pawn->bMovingEmoteFollowingOnly = false;
	}

	void OnDeathServer(AFortPawn* Pawn, float Damage, const FGameplayTagContainer& DamageTags, const FVector& Momentum, const FHitResult& HitInfo, AController* InstigatedBy, AActor* DamageCauser, const FGameplayEffectContextHandle& EffectContext)
	{
		OnDeathServerOG(Pawn, Damage, DamageTags, Momentum, HitInfo, InstigatedBy, DamageCauser, EffectContext);

		AFortPlayerControllerAthena* PlayerControllerAthena = Cast<AFortPlayerControllerAthena>(Pawn->Controller);
		if (!PlayerControllerAthena) return;

		AFortPlayerState* PlayerState = Cast<AFortPlayerState>(PlayerControllerAthena->PlayerState);
		if (!PlayerState) return;

		AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(Globals::GetGameState());
		if (!GameStateAthena) return;

		if (PlayerControllerAthena && !GameStateAthena->IsRespawningAllowed(PlayerState))
		{
			PlayerControllerAthena->ServerDropAllItems(nullptr);
			Inventory::ResetInventory(PlayerControllerAthena->WorldInventory);
		}
	}

	void InitPawn()
	{
		AFortPlayerPawnAthena* FortPlayerPawnAthenaDefault = AFortPlayerPawnAthena::GetDefaultObj();
		UClass* FortPlayerPawnAthenaClass = AFortPlayerPawnAthena::StaticClass();

		MinHook::HookVTable(FortPlayerPawnAthenaDefault, 0x1100 / 8, ServerHandlePickupInfo, nullptr, "AFortPlayerPawn::ServerHandlePickupInfo");

		UFunction* OnCapsuleBeginOverlapFunc = FortPlayerPawnAthenaClass->GetFunction("FortPlayerPawn", "OnCapsuleBeginOverlap");
		MinHook::HookFunctionExec(OnCapsuleBeginOverlapFunc, OnCapsuleBeginOverlap, nullptr);

		UFunction* PlayGroupEmoteFunc = FortPlayerPawnAthenaClass->GetFunction("FortPlayerPawn", "PlayGroupEmote");
		MinHook::HookFunctionExec(PlayGroupEmoteFunc, PlayGroupEmote, nullptr);

		UFunction* MovingEmoteStoppedFunc = FortPlayerPawnAthenaClass->GetFunction("FortPawn", "MovingEmoteStopped");
		MinHook::HookFunctionExec(MovingEmoteStoppedFunc, MovingEmoteStopped, nullptr);

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x6bde618), OnDeathServer, (LPVOID*)(&OnDeathServerOG));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x6bde618));

		FN_LOG(LogInit, Log, "InitPawn Success!");
	}
}