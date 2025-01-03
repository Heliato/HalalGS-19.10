#pragma once
#include <map>

namespace Functions
{
	bool IsPlayerBuildableClasse(UClass* BuildableClasse)
	{
		AFortGameStateAthena* GameState = Cast<AFortGameStateAthena>(Globals::GetGameState());

		if (!BuildableClasse || !GameState)
			return false;

		TArray<TSubclassOf<ABuildingActor>> BuildingActorClasses = GameState->BuildingActorClasses;

		if (BuildingActorClasses.IsValid())
		{
			for (int32 i = 0; i < BuildingActorClasses.Num(); i++)
			{
				TSubclassOf<ABuildingActor> BuildingActorClasse = BuildingActorClasses[i];
				if (!BuildingActorClasse.Get()) continue;

				if (BuildingActorClasse.Get() == BuildableClasse)
					return true;
			}
		}

		return false;
	}

	// 7FF66F3270B0
	void SetEditingPlayer(ABuildingSMActor* BuildingActor, AFortPlayerStateZone* EditingPlayer)
	{
		if (BuildingActor->HasAuthority() && (!BuildingActor->EditingPlayer || !EditingPlayer))
		{
			BuildingActor->SetNetDormancy(ENetDormancy(2 - (EditingPlayer != 0)));
			BuildingActor->ForceNetUpdate();
			BuildingActor->EditingPlayer = EditingPlayer;
		}
	}

	// 7FF66F986F80
	void SetEditingActor(AFortWeap_EditingTool* EditingTool, ABuildingSMActor* BuildingActor)
	{
		if (EditingTool->HasAuthority())
		{
			EditingTool->EditActor = BuildingActor;
			EditingTool->OnRep_EditActor();
		}
	}

	UFortAbilitySet* LoadAbilitySet(TSoftObjectPtr<UFortAbilitySet> SoftAbilitySet)
	{
		UFortAbilitySet* AbilitySet = SoftAbilitySet.Get();

		if (!AbilitySet)
		{
			const FString& AssetPathName = UKismetStringLibrary::Conv_NameToString(SoftAbilitySet.ObjectID.AssetPathName);
			AbilitySet = StaticLoadObject<UFortAbilitySet>(AssetPathName.CStr());
		}

		return AbilitySet;
	}

	UClass* LoadClass(TSoftClassPtr<UClass> SoftClass)
	{
		UClass* Class = SoftClass.Get();

		if (!Class && SoftClass.ObjectID.AssetPathName.IsValid())
		{
			const FString& AssetPathName = UKismetStringLibrary::Conv_NameToString(SoftClass.ObjectID.AssetPathName);
			Class = StaticLoadObject<UClass>(AssetPathName.CStr());
		}

		return Class;
	}

	void FillSafeZoneDurations()
	{
		AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(Globals::GetGameState());

		if (GameStateAthena && GameStateAthena->MapInfo && GameStateAthena->CurrentPlaylistInfo.BasePlaylist)
		{
			UCurveTable* AthenaGameData = GameStateAthena->CurrentPlaylistInfo.BasePlaylist->GameData.Get();
			AFortAthenaMapInfo* MapInfo = GameStateAthena->MapInfo;

			if (!AthenaGameData)
			{
				AthenaGameData = GameStateAthena->AthenaGameDataTable;

				if (!AthenaGameData)
					AthenaGameData = StaticLoadObject<UCurveTable>(L"/Game/Balance/AthenaGameData.AthenaGameData");
			}

			TArray<float> WaitTimeDurations = *(TArray<float>*)(__int64(&MapInfo->SafeZoneDefinition) + 0x238);
			TArray<float> ShrinkTimeDurations = *(TArray<float>*)(__int64(&MapInfo->SafeZoneDefinition) + 0x248);

			const FName WaitTimeName = UKismetStringLibrary::Conv_StringToName(L"Default.SafeZone.WaitTime");
			const FName ShrinkTimeName = UKismetStringLibrary::Conv_StringToName(L"Default.SafeZone.ShrinkTime");

			for (int32 i = 0; i < WaitTimeDurations.Num(); i++)
			{
				UDataTableFunctionLibrary::EvaluateCurveTableRow(AthenaGameData, WaitTimeName, i, nullptr, &WaitTimeDurations[i], L"Functions::FillSafeZoneDurations");
			}

			for (int32 i = 0; i < ShrinkTimeDurations.Num(); i++)
			{
				UDataTableFunctionLibrary::EvaluateCurveTableRow(AthenaGameData, ShrinkTimeName, i, nullptr, &ShrinkTimeDurations[i], L"Functions::FillSafeZoneDurations");
			}
		}
	}

	void InitFunctions()
	{
		FN_LOG(LogInit, Log, "InitFunctions Success!");
	}
}