#pragma once

#define CHEATS
// #define DEBUGS
// #define SIPHON
// #define QUESTS
// #define LATEGAME
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

struct FFortCreatePickupData final
{
public:
	UWorld*										  World;					                         // 0x0000(0x0008)()
	
};

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

	AFortGameMode* GetGameMode()
	{
		UWorld* World = GetWorld();

		if (World)
		{
			AFortGameMode* GameMode = Cast<AFortGameMode>(World->AuthorityGameMode);

			if (GameMode)
				return GameMode;
		}

		return nullptr;
	}

	AFortGameState* GetGameState()
	{
		UWorld* World = GetWorld();

		if (World)
		{
			AFortGameState* GameState = Cast<AFortGameState>(World->GameState);

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