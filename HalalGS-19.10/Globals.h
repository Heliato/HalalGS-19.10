#pragma once

#include <algorithm>
#include <time.h>
#include <vector>
#include <unordered_map>
#include <functional>
#include <string>
#include <sstream>

// InventoryOwner = 0x710

#define CHEATS
// #define DEBUGS
// #define SIPHON
// #define QUESTS
// #define LATEGAME
// #define FLOORLOOT
#define BOTS

template<typename T = UObject>
static T* Cast(UObject* Object)
{
	if (Object && Object->IsA(T::StaticClass()))
	{
		return (T*)Object;
	}

	return nullptr;
}

std::vector<std::string> split(const std::string& s, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);

	while (std::getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}

	return tokens;
}

namespace Globals
{
	UFortEngine* GetFortEngine()
	{
		return *(UFortEngine**)(uintptr_t(GetModuleHandleW(0)) + 0xB318468); // GEngine
	}

	UWorld* GetWorld(bool SkipCheck = false)
	{
		UEngine* Engine = GetFortEngine();

		if (Engine)
		{
			if (Engine->GameViewport)
				return Engine->GameViewport->World;
		}

		return nullptr;
	}

	TArray<ULocalPlayer*> GetLocalPlayers()
	{
		UGameEngine* Engine = GetFortEngine();

		if (Engine)
		{
			if (Engine->GameInstance)
				return Engine->GameInstance->LocalPlayers;
		}
	}

	AFortPlayerController* GetServerPlayerController()
	{
		return Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));
	}

	AFortGameModeAthena* GetGameMode()
	{
		UWorld* World = GetWorld();

		if (World)
		{
			AFortGameModeAthena* GameMode = Cast<AFortGameModeAthena>(World->AuthorityGameMode);

			if (GameMode)
				return GameMode;
		}

		return nullptr;
	}

	AFortGameStateAthena* GetGameState()
	{
		UWorld* World = GetWorld();

		if (World)
		{
			AFortGameStateAthena* GameState = Cast<AFortGameStateAthena>(World->GameState);

			if (GameState)
				return GameState;
		}

		return nullptr;
	}

	UFortPlaylistAthena* GetPlaylist()
	{
		AFortGameStateAthena* GameState = Cast<AFortGameStateAthena>(GetGameState());

		if (GameState)
		{
			UFortPlaylistAthena* PlaylistAthena = GameState->CurrentPlaylistInfo.BasePlaylist;

			if (PlaylistAthena)
				return PlaylistAthena;
		}

		return nullptr;
	}

	UFortGameData* GetGameData()
	{
		UFortAssetManager* AssetManager = Cast<UFortAssetManager>(GetFortEngine()->AssetManager);

		if (AssetManager)
		{
			UFortGameData* GameData = AssetManager->GameDataCommon;

			if (GameData)
				return GameData;
		}

		return nullptr;
	}

	UGameDataBR* GetGameDataBR()
	{
		UFortAssetManager* AssetManager = Cast<UFortAssetManager>(GetFortEngine()->AssetManager);

		if (AssetManager)
		{
			UGameDataBR* GameDataBR = AssetManager->GameDataBR;

			if (GameDataBR)
				return GameDataBR;
		}

		return nullptr;
	}

	UGameDataCosmetics* GetGameDataCosmetics()
	{
		UFortAssetManager* AssetManager = Cast<UFortAssetManager>(GetFortEngine()->AssetManager);

		if (AssetManager)
		{
			UGameDataCosmetics* GameDataCosmetics = AssetManager->GameDataCosmetics;

			if (GameDataCosmetics)
				return GameDataCosmetics;
		}

		return nullptr;
	}

	template <typename T>
	static T* GetDataTableRowFromName(UDataTable* DataTable, FName RowName)
	{
		if (!DataTable)
			return nullptr;

		auto& RowMap = DataTable->RowMap;

		for (int i = 0; i < RowMap.Elements.Elements.Num(); ++i)
		{
			auto& Pair = RowMap.Elements.Elements.Data[i].ElementData.Value;

			if (Pair.Key() != RowName)
				continue;

			return (T*)Pair.Value();
		}

		return nullptr;
	}
}