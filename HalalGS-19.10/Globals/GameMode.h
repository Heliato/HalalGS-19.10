#pragma once

namespace GameMode
{
	void (*HandlePostSafeZonePhaseChangedOG)(AFortGameModeAthena* GameModeAthena, int a2);
	bool (*StartAircraftPhaseOG)(AFortGameModeAthena* GameModeAthena, bool a2);

	bool ReadyToStartMatch(AFortGameModeAthena* GameModeAthena)
	{
		if (!GameModeAthena)
			return false;

		UWorld* World = GameModeAthena->GetWorld();
		if (!World) return false;

		if (!World->NetDriver)
		{
			FURL URL = FURL();
			URL.Port = 7777;
			Beacon::ListenServer(World, URL);
		}

		AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(GameModeAthena->GameState);

		if (GameStateAthena && !GameStateAthena->CurrentPlaylistInfo.BasePlaylist)
		{
			UFortPlaylistAthena* PlaylistAthena = StaticFindObject<UFortPlaylistAthena>(L"/Game/Athena/Playlists/Playlist_DefaultSolo.Playlist_DefaultSolo");
			if (!PlaylistAthena) return false;

			GameStateAthena->CurrentPlaylistInfo.BasePlaylist = PlaylistAthena;
			GameStateAthena->CurrentPlaylistInfo.OverridePlaylist = PlaylistAthena;
			GameStateAthena->CurrentPlaylistInfo.PlaylistReplicationKey++;
			GameStateAthena->CurrentPlaylistInfo.MarkArrayDirty();
			GameStateAthena->OnRep_CurrentPlaylistInfo();

			GameModeAthena->CurrentPlaylistId = PlaylistAthena->PlaylistId;
			GameModeAthena->CurrentPlaylistName = PlaylistAthena->PlaylistName;

			GameModeAthena->WarmupRequiredPlayerCount = 1;

			GameStateAthena->CurrentPlaylistId = PlaylistAthena->PlaylistId;
			GameStateAthena->OnRep_CurrentPlaylistId();

			GameStateAthena->AirCraftBehavior = PlaylistAthena->AirCraftBehavior;
			GameStateAthena->bIsLargeTeamGame = PlaylistAthena->bIsLargeTeamGame;
			GameStateAthena->TeamCount = PlaylistAthena->MaxTeamCount;
			GameStateAthena->AirCraftBehavior = PlaylistAthena->AirCraftBehavior;
			
			UFortZoneTheme* ZoneTheme = GameStateAthena->ZoneTheme;

			if (ZoneTheme)
			{
				ZoneTheme->PlaylistId = PlaylistAthena->PlaylistId;
				ZoneTheme->TeamSize = PlaylistAthena->MaxTeamSize;
				ZoneTheme->TeamCount = PlaylistAthena->MaxTeamCount;
				ZoneTheme->MaxPartySize = PlaylistAthena->MaxSocialPartySize;
				ZoneTheme->MaxPlayers = PlaylistAthena->MaxPlayers;
			}

			AFortGameSession* FortGameSession = GameModeAthena->FortGameSession;

			if (FortGameSession)
			{
				FortGameSession->MaxPlayers = PlaylistAthena->MaxPlayers;
				FortGameSession->MaxPartySize = PlaylistAthena->MaxSocialPartySize;

				FortGameSession->SessionName = UKismetStringLibrary::Conv_StringToName(L"HalalSession");

				FN_LOG(LogGameMode, Log, "MaxPlayers: %i", PlaylistAthena->MaxPlayers);
				FN_LOG(LogGameMode, Log, "MaxPartySize: %i", PlaylistAthena->MaxSocialPartySize);
				FN_LOG(LogGameMode, Log, "FortGameSession: %s", FortGameSession->GetFullName().c_str());
			}

			GameStateAthena->bPlaylistDataIsLoaded = true;

			FN_LOG(LogGameMode, Log, "GameStateAthena->bPlaylistDataIsLoaded: %i", GameStateAthena->bPlaylistDataIsLoaded);

			FN_LOG(LogGameMode, Log, "GameStateAthena: %s", GameStateAthena->GetFullName().c_str());
			FN_LOG(LogGameMode, Log, "GameModeAthena: %s", GameModeAthena->GetFullName().c_str());
			FN_LOG(LogGameMode, Log, "PlaylistAthena: %s", PlaylistAthena->GetFullName().c_str());
			FN_LOG(LogGameMode, Log, "Playlist Successful Set!");
		}


		if (GameModeAthena->bWorldIsReady)
		{
			const FName& MatchState = GameModeAthena->MatchState;

			if (GameModeAthena->NumPlayers + GameModeAthena->NumBots > 0 &&
				MatchState.ToString() == "WaitingToStart")
			{
				FN_LOG(LogGameMode, Log, "bReadyToStartMatch: %i, bWorldIsReady: %i, ForceReturnTrue: 1", false, GameModeAthena->bWorldIsReady);

				return true;
			}
		}

		return false;
	}

	APawn* SpawnDefaultPawnFor(AFortGameModeAthena* GameModeAthena, AController* NewPlayer, AActor* StartSpot)
	{
		if (!NewPlayer || !StartSpot)
			return nullptr;

		AFortPlayerControllerAthena* PlayerControllerAthena = Cast<AFortPlayerControllerAthena>(NewPlayer);
		AFortPlayerStateAthena* PlayerStateAthena = Cast<AFortPlayerStateAthena>(NewPlayer->PlayerState);

		if (!PlayerControllerAthena || !PlayerStateAthena)
			return nullptr;

		AFortPlayerPawn* PlayerPawn = GameModeAthena->SpawnDefaultPawnFor(PlayerControllerAthena, StartSpot);

		if (!PlayerPawn)
			return nullptr;

		UFortAbilitySystemComponent* AbilitySystemComponent = PlayerStateAthena->AbilitySystemComponent;

		if (AbilitySystemComponent)
		{
			AbilitySystemComponent->ClearAllAbilities();

			UGameDataBR* GameDataBR = Globals::GetGameDataBR();
			UFortAbilitySet* DefaultAbilities = Functions::LoadAbilitySet(GameDataBR->PlayerAbilitySetBR);

			Abilities::GrantGameplayAbility(DefaultAbilities, AbilitySystemComponent);
			Abilities::GrantGameplayEffect(DefaultAbilities, AbilitySystemComponent);
			Abilities::GrantModifierAbilityFromPlaylist(AbilitySystemComponent);
		}

		PlayerStateAthena->ApplyCharacterCustomization(PlayerPawn);

		UFortWeaponMeleeItemDefinition* PickaxeItemDefinition = nullptr;

		if (PlayerControllerAthena)
		{
			UAthenaPickaxeItemDefinition* AthenaPickaxeItemDefinition = PlayerControllerAthena->CosmeticLoadoutPC.Pickaxe;

			if (AthenaPickaxeItemDefinition)
				PickaxeItemDefinition = AthenaPickaxeItemDefinition->WeaponDefinition;

			if (!PickaxeItemDefinition)
			{
				UGameDataCosmetics* GameDataCosmetics = Globals::GetGameDataCosmetics();
				UAthenaPickaxeItemDefinition* DefaultPickaxeSkin = GameDataCosmetics->FallbackPickaxe.Get();

				if (DefaultPickaxeSkin)
					PickaxeItemDefinition = DefaultPickaxeSkin->WeaponDefinition;
			}
		}

		Inventory::SetupInventory(PlayerControllerAthena, PickaxeItemDefinition);

		return PlayerPawn;
	}

	void HandlePostSafeZonePhaseChanged(AFortGameModeAthena* GameModeAthena, int a2)
	{
		AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(GameModeAthena->GameState);
		AFortSafeZoneIndicator* SafeZoneIndicator = GameModeAthena->SafeZoneIndicator;

		if (!GameStateAthena || !SafeZoneIndicator) 
			return HandlePostSafeZonePhaseChangedOG(GameModeAthena, a2);

		AFortAthenaMapInfo* MapInfo = GameStateAthena->MapInfo;

		if (!MapInfo) 
			return HandlePostSafeZonePhaseChangedOG(GameModeAthena, a2);

		int32 NextSafeZonePhase = (GameModeAthena->SafeZonePhase + 1);

		TArray<float> WaitTimeDurations = *(TArray<float>*)(__int64(&MapInfo->SafeZoneDefinition) + 0x238);
		TArray<float> ShrinkTimeDurations = *(TArray<float>*)(__int64(&MapInfo->SafeZoneDefinition) + 0x248);

		float WaitTimeDuration = WaitTimeDurations[NextSafeZonePhase];
		float ShrinkTimeDuration = ShrinkTimeDurations[NextSafeZonePhase];

		SafeZoneIndicator->SafeZoneStartShrinkTime = UGameplayStatics::GetTimeSeconds(GameModeAthena) + WaitTimeDuration;
		SafeZoneIndicator->SafeZoneFinishShrinkTime = SafeZoneIndicator->SafeZoneStartShrinkTime + ShrinkTimeDuration;

		// FN_LOG(LogHooks, Log, "HandlePostSafeZonePhaseChanged called - GameModeAthena: %s, a2: %i", GameModeAthena->GetFullName().c_str(), a2);

		HandlePostSafeZonePhaseChangedOG(GameModeAthena, a2);
	}

	bool StartAircraftPhase(AFortGameModeAthena* GameModeAthena, bool a2)
	{
		TArray<AFortPlayerController*> AllFortPlayerController = UFortKismetLibrary::GetAllFortPlayerControllers(GameModeAthena, true, true);

		for (int32 i = 0; i < AllFortPlayerController.Num(); i++)
		{
			AFortPlayerController* PlayerController = AllFortPlayerController[i];
			if (!PlayerController) continue;

			Inventory::ResetInventory(PlayerController->WorldInventory);
		}

		return StartAircraftPhaseOG(GameModeAthena, a2);
	}

	void InitGameMode()
	{
		AFortGameModeAthena* FortGameModeAthenaDefault = AFortGameModeAthena::GetDefaultObj();

		MinHook::HookVTable(FortGameModeAthenaDefault, 0x898 / 8, ReadyToStartMatch, nullptr, "AGameMode::ReadyToStartMatch");
		MinHook::HookVTable(FortGameModeAthenaDefault, 0x6C0 / 8, SpawnDefaultPawnFor, nullptr, "AGameModeBase::SpawnDefaultPawnFor");

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x5fa67bc), HandlePostSafeZonePhaseChanged, (LPVOID*)(&HandlePostSafeZonePhaseChangedOG));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x5fa67bc));
		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x5fa4538), StartAircraftPhase, (LPVOID*)(&StartAircraftPhaseOG));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x5fa4538));

		FN_LOG(LogInit, Log, "InitGameMode Success!");
	}
}