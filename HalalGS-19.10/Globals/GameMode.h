#pragma once

namespace GameMode
{
	bool (*ReadyToStartMatchOG)(AGameMode* GameMode);

	bool ReadyToStartMatch(AGameMode* GameMode)
	{
		ReadyToStartMatchOG(GameMode);

		if (!GameMode)
			return false;

		AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(GameMode->GameState);

		if (GameStateAthena && !GameStateAthena->CurrentPlaylistInfo.BasePlaylist)
		{
			StaticFindObject(UFortPlaylistAthena::StaticClass(), nullptr, L"/Game/Athena/Playlists/Playlist_DefaultSolo.Playlist_DefaultSolo");
		}

		AFortGameMode* FortGameMode = Cast<AFortGameMode>(GameMode);

		if (FortGameMode && FortGameMode->bWorldIsReady)
		{
			const FName& MatchState = FortGameMode->MatchState;
			if (!MatchState.IsValid()) return false;

			if (GameMode->NumPlayers + GameMode->NumBots > 0 &&
				MatchState.ToString() == "WaitingToStart")
			{
				const FName& InProgress = UKismetStringLibrary::Conv_StringToName(L"InProgress");
				if (!InProgress.IsValid()) return false;

				GameMode->MatchState = InProgress;
				GameMode->K2_OnSetMatchState(InProgress);

				AFortGameModeAthena* GameModeAthena = Cast<AFortGameModeAthena>(FortGameMode);

				if (GameModeAthena)
				{
					/*Functions::InitializeTreasureChests();
					Functions::InitializeAmmoBoxs();
					Functions::InitializeLlamas();
					Functions::FillVendingMachines();*/

					GameModeAthena->HandleMatchHasStarted(); // Set GamePhase to Warmup and others
				}
			}
		}
	}

	void InitGameMode()
	{
		AFortGameModeAthena* FortGameModeAthenaDefault = AFortGameModeAthena::GetDefaultObj();

		MinHook::HookVTable(FortGameModeAthenaDefault, 0x898 / 8, ReadyToStartMatch, (LPVOID*)(&ReadyToStartMatchOG), "AGameMode::ReadyToStartMatch");

		FN_LOG(LogInit, Log, "InitGameMode Success!");
	}
}