#pragma once
#include <random>
#include <map>

struct FFortLootTierDataCheck
{
public:
    FName                                         TierGroup;                                         // 0x0000(0x0008)(100% c'est ça)
    int32                                         LootTier;                                          // 0x0008(0x0004)(100% c'est ça)
    uint8                                         Pad_1[0x4];                                        // 0x000C(0x0004)(jsp ça commence à me faire peur)
    ELootQuotaLevel                               QuotaLevel;                                        // 0x0010(0x0001)(inshallah)
    FGameplayTagContainer                         GameplayTags;                                      // 0x0018(0x0008)(inshallah)
    int32                                         WorldLevel;                                        // 0x0020(0x0004)(inshallah)

};

struct FFortLootPackageDataCheck
{
public:
    FName                                         LootPackageName;                                   // 0x0000(0x0008)(100% c'est ça)
    int32                                         LootPackageCategory;                               // 0x0008(0x0004)(100% c'est ça)
    uint8                                         Pad_1[0x4];                                        // 0x000C(0x0004)(jsp ça commence à me faire peur)
    FGameplayTagContainer                         GameplayTags;                                      // 0x0010(0x0001)(inshallah)
    int32                                         WorldLevel;                                        // 0x0018(0x0008)(inshallah)

};

namespace Loots
{
    UDataTable* LoadDataTable(TSoftObjectPtr<UDataTable> DataTableToLoad)
    {
        UDataTable* DataTable = DataTableToLoad.Get();

        if (!DataTable)
        {
            const std::string& AssetPathName = UKismetStringLibrary::Conv_NameToString(DataTableToLoad.ObjectID.AssetPathName).ToString(); // ToString doesn't work idk
            DataTable = StaticLoadObject<UDataTable>(std::wstring(AssetPathName.begin(), AssetPathName.end()).c_str());
        }

        return DataTable;

        // 7FF66F229810
        /*UDataTable* (*LoadDataTable)(TSoftObjectPtr<UDataTable> DataTableToLoad, char a2) = decltype(LoadDataTable)(0xBD9810 + uintptr_t(GetModuleHandle(0)));

        return LoadDataTable(DataTableToLoad, 1);

        UDataTable* DataTable = DataTableToLoad.Get();

        if (!DataTable)
        {
            std::string AssetPathName = DataTableToLoad.ObjectID.AssetPathName.ToString();
            DataTable = StaticLoadObject<UDataTable>(std::wstring(AssetPathName.begin(), AssetPathName.end()).c_str());
        }

        return DataTable;*/
    }

    UFortItemDefinition* LoadItemDefinition(TSoftObjectPtr<UFortItemDefinition> SoftItemDefinition)
    {
        UFortItemDefinition* ItemDefinition = SoftItemDefinition.Get();

        if (!ItemDefinition)
        {
            const std::string& AssetPathName = UKismetStringLibrary::Conv_NameToString(SoftItemDefinition.ObjectID.AssetPathName).ToString();
            ItemDefinition = StaticLoadObject<UFortItemDefinition>(std::wstring(AssetPathName.begin(), AssetPathName.end()).c_str());
        }

        return ItemDefinition;
    }

    FFortLootTierData* FindLootTierDataRow(UGameDataBR* GameDataBR, FName LootTierKey, FString ContextString)
    {
        AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(Globals::GetGameState());
        TArray<UDataTable*> LootTierDataTables;

        if (GameStateAthena)
        {
            UFortPlaylistAthena* PlaylistAthena = GameStateAthena->CurrentPlaylistInfo.BasePlaylist;

            if (PlaylistAthena && PlaylistAthena->LootTierData.ObjectID.AssetPathName.IsValid())
            {
                UDataTable* DataTable = LoadDataTable(PlaylistAthena->LootTierData);
                UCompositeDataTable* CompositeDataTable = Cast<UCompositeDataTable>(DataTable);

                if (CompositeDataTable)
                {
                    for (int32 i = 0; i < CompositeDataTable->ParentTables.Num(); i++)
                    {
                        UDataTable* ParentTable = CompositeDataTable->ParentTables[i];

                        if (ParentTable)
                            LootTierDataTables.Add(ParentTable);
                    }

                    LootTierDataTables.Add(CompositeDataTable);
                }
                else if (DataTable)
                {
                    LootTierDataTables.Add(DataTable);
                }
                else
                {
                    UDataTable* DataTable = LoadDataTable(PlaylistAthena->LootTierData);

                    if (DataTable)
                        LootTierDataTables.Add(DataTable);
                }
            }
            /*else
            {
                UDataTable* DataTable = StaticFindObject<UDataTable>(L"/Game/Items/Datatables/AthenaLootTierData_Client.AthenaLootTierData_Client");

                if (!DataTable)
                    DataTable = StaticLoadObject<UDataTable>(L"/Game/Items/Datatables/AthenaLootTierData_Client.AthenaLootTierData_Client");

                if (DataTable)
                    LootTierDataTables.Add(DataTable);
            }*/
        }

        if (LootTierDataTables.Num() <= 0)
        {
            for (int32 i = 0; i < GameDataBR->LootTierDataTablesBR.Num(); i++)
            {
                TSoftObjectPtr<UDataTable> LootTierDataTable = GameDataBR->LootTierDataTablesBR[i];

                UDataTable* DataTable = LoadDataTable(LootTierDataTable);

                if (DataTable)
                    LootTierDataTables.Add(DataTable);
            }
        }

        FFortLootTierData* SelectLootTierData = nullptr;

        for (int32 i = 0; i < LootTierDataTables.Num(); i++)
        {
            UDataTable* LootTierDataTable = LootTierDataTables[i];
            if (!LootTierDataTable) continue;

            FFortLootTierData* LootTierData = Globals::GetDataTableRowFromName<FFortLootTierData>(LootTierDataTable, LootTierKey);

            if (LootTierData)
            {
                SelectLootTierData = LootTierData;
                break;
            }
        }

        if (!SelectLootTierData)
            FN_LOG(LogLoot, Warning, "UFortGameData::FindLootTierDataRow : TierGroupName %s with context %s not found!", LootTierKey.ToString().c_str(), ContextString.ToString().c_str());

        return SelectLootTierData;
    }

    bool IsLootDropPossible(FName LootTierKey, FString ContextString, __int64 a3)
    {
        if (!LootTierKey.IsValid())
            return false;

        UGameDataBR* GameDataBR = Globals::GetGameDataBR();
        FFortLootTierData* LootTierData = FindLootTierDataRow(GameDataBR, LootTierKey, ContextString);

        if (!LootTierData)
            return false;

        float v9 = (float)rand() * 0.000030518509f;

        float NumLootPackageDrops = LootTierData->NumLootPackageDrops;
        return NumLootPackageDrops > 0.0f && v9 <= NumLootPackageDrops;
    }

    // 7FF71A062160
    int32 FindLootTierFromKey(FName LootTierKey)
    {
        UGameDataBR* GameDataBR = Globals::GetGameDataBR();
        FFortLootTierData* LootTierData = FindLootTierDataRow(GameDataBR, LootTierKey, L"UFortLootTier::FindLootTierFromKey");

        if (LootTierData)
            return LootTierData->LootTier;

        return -1;
    }

    // 7FF71A05C230
    bool IsValidLootTier(FFortLootTierDataCheck LootTierDataCheck, FFortLootTierData LootTierData)
    {
        if (LootTierDataCheck.TierGroup != LootTierData.TierGroup)
            return false;

        int32 LootTier = LootTierDataCheck.LootTier;

        if (LootTier != -1 && LootTier != LootTierData.LootTier)
            return false;

        ELootQuotaLevel QuotaLevel = LootTierDataCheck.QuotaLevel;

        if (QuotaLevel < ELootQuotaLevel::NumLevels && QuotaLevel != LootTierData.QuotaLevel)
            return false;

        if (LootTierData.RequiredGameplayTags.GameplayTags.IsValid() ||
            LootTierData.RequiredGameplayTags.ParentTags.IsValid() ||
            LootTierData.GameplayTags.GameplayTags.IsValid() ||
            LootTierData.GameplayTags.ParentTags.IsValid())
        {
            /*bool bFindTagName = false;

            for (int32 i = 0; i < LootTierDataCheck.GameplayTags.GameplayTags.Num(); i++)
            {
                FGameplayTag GameplayTag = LootTierDataCheck.GameplayTags.GameplayTags[i];

                for (int32 j = 0; j < LootTierData.RequiredGameplayTags.GameplayTags.Num(); j++)
                {
                    FGameplayTag GameplayTagTierData = LootTierData.RequiredGameplayTags.GameplayTags[j];

                    if (GameplayTag.TagName == GameplayTagTierData.TagName)
                    {
                        bFindTagName = true;
                        break;
                    }
                }

                for (int32 j = 0; j < LootTierData.RequiredGameplayTags.ParentTags.Num(); j++)
                {
                    FGameplayTag GameplayTagTierData = LootTierData.RequiredGameplayTags.ParentTags[j];

                    if (GameplayTag.TagName == GameplayTagTierData.TagName)
                    {
                        bFindTagName = true;
                        break;
                    }
                }

                for (int32 j = 0; j < LootTierData.GameplayTags.GameplayTags.Num(); j++)
                {
                    FGameplayTag GameplayTagTierData = LootTierData.GameplayTags.GameplayTags[j];

                    if (GameplayTag.TagName == GameplayTagTierData.TagName)
                    {
                        bFindTagName = true;
                        break;
                    }
                }

                for (int32 j = 0; j < LootTierData.GameplayTags.ParentTags.Num(); j++)
                {
                    FGameplayTag GameplayTagTierData = LootTierData.GameplayTags.ParentTags[j];

                    if (GameplayTag.TagName == GameplayTagTierData.TagName)
                    {
                        bFindTagName = true;
                        break;
                    }
                }
            }

            for (int32 i = 0; i < LootTierDataCheck.GameplayTags.ParentTags.Num(); i++)
            {
                FGameplayTag ParentTags = LootTierDataCheck.GameplayTags.ParentTags[i];

                for (int32 j = 0; j < LootTierData.RequiredGameplayTags.GameplayTags.Num(); j++)
                {
                    FGameplayTag GameplayTagTierData = LootTierData.RequiredGameplayTags.GameplayTags[j];

                    if (ParentTags.TagName == GameplayTagTierData.TagName)
                    {
                        bFindTagName = true;
                        break;
                    }
                }

                for (int32 j = 0; j < LootTierData.RequiredGameplayTags.ParentTags.Num(); j++)
                {
                    FGameplayTag GameplayTagTierData = LootTierData.RequiredGameplayTags.ParentTags[j];

                    if (ParentTags.TagName == GameplayTagTierData.TagName)
                    {
                        bFindTagName = true;
                        break;
                    }
                }

                for (int32 j = 0; j < LootTierData.GameplayTags.GameplayTags.Num(); j++)
                {
                    FGameplayTag GameplayTagTierData = LootTierData.GameplayTags.GameplayTags[j];

                    if (ParentTags.TagName == GameplayTagTierData.TagName)
                    {
                        bFindTagName = true;
                        break;
                    }
                }

                for (int32 j = 0; j < LootTierData.GameplayTags.ParentTags.Num(); j++)
                {
                    FGameplayTag GameplayTagTierData = LootTierData.GameplayTags.ParentTags[j];

                    if (ParentTags.TagName == GameplayTagTierData.TagName)
                    {
                        bFindTagName = true;
                        break;
                    }
                }
            }

            if (!bFindTagName)
                return false;*/
        }

        int32 WorldLevel = LootTierDataCheck.WorldLevel;

        if (WorldLevel >= 0)
        {
            int32 MaxWorldLevel = LootTierData.MaxWorldLevel;

            if (MaxWorldLevel >= 0 && WorldLevel > MaxWorldLevel)
                return false;

            int32 MinWorldLevel = LootTierData.MinWorldLevel;

            if (MinWorldLevel >= 0 && WorldLevel < MinWorldLevel)
                return false;
        }

        return true;
    }

    // 7FF71A071B80
    bool IsValidLootPackage(FFortLootPackageData LootPackageData, FName LootPackageName, int32 LootPackageCategory, FGameplayTagContainer GameplayTags, int32 WorldLevel)
    {
        if (LootPackageName != LootPackageData.LootPackageID || LootPackageCategory != -1 && LootPackageData.LootPackageCategory != LootPackageCategory)
            return false;

        if (LootPackageData.RequiredTag.ComparisonIndex > 0)
        {
            FName RequiredTag = LootPackageData.RequiredTag;
            bool bFindTagName = false;

            for (int32 i = 0; i < GameplayTags.GameplayTags.Num(); i++)
            {
                FGameplayTag GameplayTag = GameplayTags.GameplayTags[i];

                if (GameplayTag.TagName == RequiredTag)
                {
                    bFindTagName = true;
                    break;
                }
            }

            for (int32 i = 0; i < GameplayTags.ParentTags.Num(); i++)
            {
                FGameplayTag ParentTag = GameplayTags.ParentTags[i];

                if (ParentTag.TagName == RequiredTag)
                {
                    bFindTagName = true;
                    break;
                }
            }

            if (!bFindTagName)
                return false;
        }

        if (WorldLevel >= 0)
        {
            int32 MaxWorldLevel = LootPackageData.MaxWorldLevel;

            if (MaxWorldLevel >= 0 && WorldLevel > MaxWorldLevel)
                return false;

            int32 MinWorldLevel = LootPackageData.MinWorldLevel;

            if (MinWorldLevel >= 0 && WorldLevel < MinWorldLevel)
                return false;
        }

        return true;
    }

    // 7FF71A057880
    void CollectLootTierDatas(std::map<FName, FFortLootTierData*>* OutLootTierDatas, float* OutWeight, TArray<UDataTable*> LootTierDataTables, FFortLootTierDataCheck LootTierDataCheck)
    {
        for (int32 i = 0; i < LootTierDataTables.Num(); i++)
        {
            UDataTable* LootTierDataTable = LootTierDataTables[i];
            if (!LootTierDataTable) continue;

            TArray<FName> RowNames;
            UDataTableFunctionLibrary::GetDataTableRowNames(LootTierDataTable, &RowNames);

            for (int32 j = 0; j < RowNames.Num(); j++)
            {
                FName RowName = RowNames[j];
                if (!RowName.IsValid()) continue;

                FFortLootTierData* LootTierData = Globals::GetDataTableRowFromName<FFortLootTierData>(LootTierDataTable, RowName);

                if (LootTierData && IsValidLootTier(LootTierDataCheck, *LootTierData))
                {
                    OutLootTierDatas->insert_or_assign(RowName, LootTierData);
                    *OutWeight = LootTierData->Weight + *OutWeight;
                }
            }
        }

        if (LootTierDataTables.IsValid())
            LootTierDataTables.Free();
    }

    // 7FF71A057B40
    void CollectLootPackageDatas(TArray<FFortLootPackageData*>* OutLootPackageDatas, float* OutWeight, TArray<UDataTable*> LootTierPackageTables, FFortLootPackageDataCheck LootTierPackageCheck)
    {
        for (int32 i = 0; i < LootTierPackageTables.Num(); i++)
        {
            UDataTable* LootTierPackageTable = LootTierPackageTables[i];
            if (!LootTierPackageTable) continue;

            TArray<FName> RowNames;
            UDataTableFunctionLibrary::GetDataTableRowNames(LootTierPackageTable, &RowNames);

            for (int32 j = 0; j < RowNames.Num(); j++)
            {
                FName RowName = RowNames[j];
                if (!RowName.IsValid()) continue;

                FFortLootPackageData* LootPackageData = Globals::GetDataTableRowFromName<FFortLootPackageData>(LootTierPackageTable, RowName);

                if (LootPackageData && IsValidLootPackage(*LootPackageData, LootTierPackageCheck.LootPackageName, LootTierPackageCheck.LootPackageCategory, LootTierPackageCheck.GameplayTags, LootTierPackageCheck.WorldLevel)) // 7FF71A057D4A
                {
                    OutLootPackageDatas->Add(LootPackageData);
                    *OutWeight = LootPackageData->Weight + *OutWeight; // 7FF71A057D98
                }
            }
        }

        if (LootTierPackageTables.IsValid())
            LootTierPackageTables.Free();
    }

    // 7FF71A057F70
    void ChooseLootTierDatas(UGameDataBR* GameDataBR, std::map<FName, FFortLootTierData*>* OutLootTierDatas, float* OutWeight, FFortLootTierDataCheck LootTierDataCheck)
    {
        AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(Globals::GetGameState());
        TArray<UDataTable*> LootTierDataTables;

        if (GameStateAthena)
        {
            UFortPlaylistAthena* PlaylistAthena = GameStateAthena->CurrentPlaylistInfo.BasePlaylist;

            if (PlaylistAthena && PlaylistAthena->LootTierData.ObjectID.AssetPathName.IsValid())
            {
                UDataTable* DataTable = LoadDataTable(PlaylistAthena->LootTierData);
                UCompositeDataTable* CompositeDataTable = Cast<UCompositeDataTable>(DataTable);

                if (CompositeDataTable)
                {
                    for (int32 i = 0; i < CompositeDataTable->ParentTables.Num(); i++)
                    {
                        UDataTable* ParentTable = CompositeDataTable->ParentTables[i];

                        if (ParentTable)
                            LootTierDataTables.Add(ParentTable);
                    }

                    LootTierDataTables.Add(CompositeDataTable);
                }
                else if (DataTable)
                {
                    LootTierDataTables.Add(DataTable);
                }
                else
                {
                    UDataTable* DataTable = LoadDataTable(PlaylistAthena->LootTierData);

                    if (DataTable)
                        LootTierDataTables.Add(DataTable);
                }
            }
            /*else
            {
                UDataTable* DataTable = StaticFindObject<UDataTable>(L"/Game/Items/Datatables/AthenaLootTierData_Client.AthenaLootTierData_Client");

                if (!DataTable)
                    DataTable = StaticLoadObject<UDataTable>(L"/Game/Items/Datatables/AthenaLootTierData_Client.AthenaLootTierData_Client");

                if (DataTable)
                    LootTierDataTables.Add(DataTable);
            }*/
        }

        if (LootTierDataTables.Num() <= 0)
        {
            for (int32 i = 0; i < GameDataBR->LootTierDataTablesBR.Num(); i++)
            {
                TSoftObjectPtr<UDataTable> LootTierDataTable = GameDataBR->LootTierDataTablesBR[i];

                UDataTable* DataTable = LoadDataTable(LootTierDataTable);

                if (DataTable)
                    LootTierDataTables.Add(DataTable);
            }
        }

        CollectLootTierDatas(OutLootTierDatas, OutWeight, LootTierDataTables, LootTierDataCheck);
    }

    // 7FF71A057E30
    void ChooseLootPackageDatas(UGameDataBR* GameDataBR, TArray<FFortLootPackageData*>* OutLootPackageDatas, float* OutWeight, FFortLootPackageDataCheck LootPackageDataCheck)
    {
        AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(Globals::GetGameState());
        TArray<UDataTable*> LootPackageDataTables;

        if (GameStateAthena)
        {
            UFortPlaylistAthena* PlaylistAthena = GameStateAthena->CurrentPlaylistInfo.BasePlaylist;

            if (PlaylistAthena && PlaylistAthena->LootPackages.ObjectID.AssetPathName.IsValid())
            {
                UDataTable* DataTable = LoadDataTable(PlaylistAthena->LootPackages);
                UCompositeDataTable* CompositeDataTable = Cast<UCompositeDataTable>(DataTable);

                if (CompositeDataTable)
                {
                    for (int32 i = 0; i < CompositeDataTable->ParentTables.Num(); i++)
                    {
                        UDataTable* ParentTable = CompositeDataTable->ParentTables[i];

                        if (ParentTable)
                            LootPackageDataTables.Add(ParentTable);
                    }

                    LootPackageDataTables.Add(CompositeDataTable);
                }
                else if (DataTable)
                {
                    LootPackageDataTables.Add(DataTable);
                }
                else
                {
                    UDataTable* DataTable = LoadDataTable(PlaylistAthena->LootPackages);

                    if (DataTable)
                        LootPackageDataTables.Add(DataTable);
                }
            }
            /*else
            {
                UDataTable* DataTable = StaticFindObject<UDataTable>(L"/Game/Items/Datatables/AthenaLootPackages_Client.AthenaLootPackages_Client");

                if (!DataTable)
                    DataTable = StaticLoadObject<UDataTable>(L"/Game/Items/Datatables/AthenaLootPackages_Client.AthenaLootPackages_Client");

                if (DataTable)
                    LootPackageDataTables.Add(DataTable);
            }*/
        }

        if (LootPackageDataTables.Num() <= 0)
        {
            for (int32 i = 0; i < GameDataBR->LootPackageDataTablesBR.Num(); i++)
            {
                TSoftObjectPtr<UDataTable> LootPackageDataTable = GameDataBR->LootPackageDataTablesBR[i];

                UDataTable* DataTable = LoadDataTable(LootPackageDataTable);

                if (DataTable)
                    LootPackageDataTables.Add(DataTable);
            }
        }

        CollectLootPackageDatas(OutLootPackageDatas, OutWeight, LootPackageDataTables, LootPackageDataCheck);
    }

    bool ChooseLootTierKeyAndLootTierByWeight(FName* OutLootTierKey, int32* OutLootTier, float TotalWeight, std::map<FName, FFortLootTierData*> LootTierDatas, __int64 a5)
    {
        if (TotalWeight <= 0.0000000099999999f)
            return false;

        float SelectWeight;

        /*if (a5)
        {
            v8 = *(_DWORD*)(a5 + 0x14);
            if (v8 > 0)
            {
                if (*(_DWORD*)(a5 + 16) >= v8)
                    *(_DWORD*)(a5 + 16) = 0;
                v10 = *(int*)(a5 + 16);
                *(_DWORD*)(a5 + 16) = v10 + 1;
                SelectWeight = *(float*)(*(_QWORD*)a5 + 4 * v10);
            }
            else
            {
                SelectWeight = 0.0;
            }
        }
        else*/
        {
            SelectWeight = (float)rand() * 0.000030518509f;
        }

        float TargetWeight = SelectWeight * TotalWeight;

        if (LootTierDatas.empty())
            return false;

        for (auto& LootTierDataMap : LootTierDatas)
        {
            FFortLootTierData* LootTierData = LootTierDataMap.second;
            FName LootTierKey = LootTierDataMap.first;

            if (!LootTierData || !LootTierKey.IsValid())
                continue;

            float CurrentWeight = LootTierData->Weight;

            if (TargetWeight <= CurrentWeight)
            {
                *OutLootTier = LootTierData->LootTier;
                *OutLootTierKey = LootTierKey;
                return true;
            }

            TargetWeight -= CurrentWeight;
        }

        return false;
    }

    // 7FF71A05F790
    bool PickLootTierKeyAndLootTierFromTierGroup(FName* OutLootTierKey, int32* OutLootTier, FName TierGroupName, int32 WorldLevel, __int64 a5, int32 ForcedLootTier, FGameplayTagContainer StaticGameplayTags)
    {
        FFortLootTierDataCheck LootTierDataCheck;
        LootTierDataCheck.TierGroup = TierGroupName;
        LootTierDataCheck.LootTier = -1;
        LootTierDataCheck.QuotaLevel = ELootQuotaLevel::Unlimited;
        LootTierDataCheck.GameplayTags = StaticGameplayTags;
        LootTierDataCheck.WorldLevel = WorldLevel;

        float TotalWeight = 0.0f;
        float FinalWeight = 0.0f;

        std::map<FName, FFortLootTierData*> LootTierDatas;

        UGameDataBR* GameDataBR = Globals::GetGameDataBR();
        ChooseLootTierDatas(GameDataBR, &LootTierDatas, &TotalWeight, LootTierDataCheck);

        if (ForcedLootTier == -1)
        {
            FinalWeight = TotalWeight;
        }
        else
        {
            std::map<FName, FFortLootTierData*> NewLootTierDatas;
            float NewWeight = 0.0f;

            for (auto& LootTierDataMap : LootTierDatas)
            {
                FFortLootTierData* LootTierData = LootTierDataMap.second;
                FName LootTierKey = LootTierDataMap.first;

                if (LootTierData && LootTierKey.IsValid())
                {
                    if (LootTierData->LootTier == ForcedLootTier && LootTierData->Weight > 0.0f)
                    {
                        NewLootTierDatas[LootTierKey] = LootTierData;
                        NewWeight = LootTierData->Weight + NewWeight;
                    }
                }
            }

            LootTierDatas = NewLootTierDatas;
            FinalWeight = NewWeight;
        }

        return ChooseLootTierKeyAndLootTierByWeight(OutLootTierKey, OutLootTier, FinalWeight, LootTierDatas, a5);
    }

    int32 AdjustItemLevel(UFortItemDefinition* ItemDefinition, int32 ItemLevel)
    {
        /*int32 Result = 0;
        int32 MinLevel = ItemDefinition->MinLevel;

        if (ItemLevel >= MinLevel)
            Result = ItemLevel;

        int32 MaxLevel = ItemDefinition->MaxLevel;

        if (MaxLevel >= 0)
        {
            if (Result <= MaxLevel)
                return Result;

            return MaxLevel;
        }*/

        return ItemLevel;
    }

    bool PickLootDropsFromLootPackage(TArray<FFortItemEntry>* OutLootToDrops, FName LootPackageName, int32 WorldLevel, int32 LootPackageCategory, __int64 a5, __int64 a6, FGameplayTagContainer StaticGameplayTags, bool bAllowBonusDrops)
    {
        FFortLootPackageDataCheck LootTierPackageCheck;
        LootTierPackageCheck.LootPackageName = LootPackageName;
        LootTierPackageCheck.LootPackageCategory = LootPackageCategory;
        LootTierPackageCheck.GameplayTags = StaticGameplayTags;
        LootTierPackageCheck.WorldLevel = WorldLevel;

        float TotalWeight = 0.0f;

        TArray<FFortLootPackageData*> LootPackageDatas;

        UGameDataBR* GameDataBR = Globals::GetGameDataBR();
        ChooseLootPackageDatas(GameDataBR, &LootPackageDatas, &TotalWeight, LootTierPackageCheck);

        if (TotalWeight == 0.0f)
        {
            FN_LOG(LogLoot, Warning, "Loot Package %s has no valid weights with the following data:\nLootPackageCategory: %d\nWorldLevel: %d\nTags: ",
                LootPackageName.ToString().c_str(), LootPackageCategory, WorldLevel);

            for (int32 i = 0; i < StaticGameplayTags.GameplayTags.Num(); i++)
            {
                FGameplayTag GameplayTag = StaticGameplayTags.GameplayTags[i];
                if (!GameplayTag.TagName.IsValid()) continue;

                FN_LOG(LogLoot, Warning, "%s", GameplayTag.TagName.ToString().c_str());
            }

            for (int32 i = 0; i < StaticGameplayTags.ParentTags.Num(); i++)
            {
                FGameplayTag ParentTag = StaticGameplayTags.ParentTags[i];
                if (!ParentTag.TagName.IsValid()) continue;

                FN_LOG(LogLoot, Warning, "%s", ParentTag.TagName.ToString().c_str());
            }

            return false;
        }

        float RandomWeight = ((float)rand() * 0.000030518509f) * TotalWeight;
        FFortLootPackageData* SelectLootPackageData = nullptr;

        for (int32 i = 0; i < LootPackageDatas.Num(); i++)
        {
            FFortLootPackageData* LootPackageData = LootPackageDatas[i];
            if (!LootPackageData) continue;

            if (RandomWeight <= LootPackageData->Weight)
            {
                SelectLootPackageData = LootPackageData;
                break;
            }

            RandomWeight -= LootPackageData->Weight;
        }

        if (!SelectLootPackageData)
            return false;

        FN_LOG(LogLoot, Debug, "PickLootDropsFromLootPackage selected package %s", SelectLootPackageData->LootPackageID.ToString().c_str());

        if (SelectLootPackageData->LootPackageCall.IsValid())
        {
            if (SelectLootPackageData->Count > 0)
            {
                FName LootPackageCallName = UKismetStringLibrary::Conv_StringToName(SelectLootPackageData->LootPackageCall);

                for (int32 i = 0; i < SelectLootPackageData->Count; ++i)
                {
                    PickLootDropsFromLootPackage(
                        OutLootToDrops,
                        LootPackageCallName,
                        WorldLevel,
                        -1, // -1
                        a5,
                        a6,
                        StaticGameplayTags,
                        false);
                }
            }

            return false;
        }

        if (!SelectLootPackageData->ItemDefinition.Get())
        {
            FName AssetPathName = SelectLootPackageData->ItemDefinition.ObjectID.AssetPathName;

            if (!AssetPathName.IsValid())
            {
                FN_LOG(LogLoot, Warning, "Loot Package %s does not contain a LootPackageCall or ItemDefinition.", SelectLootPackageData->LootPackageID.ToString().c_str());
                return false;
            }
        }

        UFortItemDefinition* ItemDefinition = LoadItemDefinition(SelectLootPackageData->ItemDefinition);

        if (!ItemDefinition)
        {
            FN_LOG(LogLoot, Warning, "Failed to load loot package %s.", SelectLootPackageData->LootPackageID.ToString().c_str());
            return false;
        }

        UFortWorldItemDefinition* WorldItemDefinition = Cast<UFortWorldItemDefinition>(ItemDefinition);
        int32 ItemLevel = 0;

        if (WorldItemDefinition)
        {
            ItemLevel = Inventory::GetItemLevel(WorldItemDefinition->LootLevelData);
        }

        int32 CountMultiplier = 1;

        FN_LOG(LogLoot, Debug, "Dropping %s (Count: %i, CountMultiplier: %i, ItemLevel: %i",
            ItemDefinition->DisplayName.ToString().c_str(), SelectLootPackageData->Count, CountMultiplier, ItemLevel);

        int32 TotalCount = CountMultiplier * SelectLootPackageData->Count;

        if (TotalCount > 0)
        {
            int32 Level = 0;

            if (ItemLevel >= 0)
                Level = ItemLevel;

            for (int32 i = 0; i < TotalCount; i++)
            {
                int32 MaxStackSize = UFortScalableFloatUtils::GetValueAtLevel(ItemDefinition->MaxStackSize, 0);
                int32 Count = MaxStackSize;

                if (TotalCount <= MaxStackSize)
                    Count = TotalCount;

                if (Count <= 0)
                    Count = 0;

                FFortItemEntry ItemEntry;
                Inventory::MakeItemEntry(&ItemEntry, (UFortWorldItemDefinition*)ItemDefinition, Count, AdjustItemLevel(ItemDefinition, Level), -1, 1.0f);

                ItemEntry.ItemGuid = UKismetGuidLibrary::NewGuid();
                ItemEntry.Inventory_overflow_date = 0;

                OutLootToDrops->Add(ItemEntry);
                TotalCount -= Count;
            }
        }

        if (LootPackageDatas.IsValid())
            LootPackageDatas.Free();

        return true;
    }

    // 7FF719F6C630
    bool CheckLootPackageDataTables(UGameDataBR* GameDataBR)
    {
        TArray<TSoftObjectPtr<UDataTable>> LootPackageDataTables = GameDataBR->LootPackageDataTablesBR;
        TArray<UDataTable*> ValidDataTables;

        for (int32 i = 0; i < LootPackageDataTables.Num(); i++)
        {
            TSoftObjectPtr<UDataTable> LootPackageDataTable = LootPackageDataTables[i];

            UDataTable* DataTable = LoadDataTable(LootPackageDataTable);

            if (DataTable)
                ValidDataTables.Add(DataTable);
        }

        return (ValidDataTables.Num() > 0);
    }

    bool ProcessLootDrops(FFortLootTierData* LootTierData, int32 NumberOfLootDrops, std::map<int32, int32>* LootMaps, __int64 a4)
    {
        if (!LootTierData)
            return false;

        LootMaps->clear();

        int32 NumberOfLootPackageCategoryMin = LootTierData->LootPackageCategoryMinArray.Num();

        if (NumberOfLootPackageCategoryMin != LootTierData->LootPackageCategoryWeightArray.Num() || NumberOfLootPackageCategoryMin != LootTierData->LootPackageCategoryMaxArray.Num())
            return false;

        int32 MinimumOfLootDrops = 0;

        for (int32 i = 0; i < NumberOfLootPackageCategoryMin; i++)
        {
            int32 LootPackageCategoryMin = LootTierData->LootPackageCategoryMinArray[i];

            if (LootPackageCategoryMin > 0)
            {
                LootMaps->emplace(i, LootPackageCategoryMin);
                MinimumOfLootDrops += LootPackageCategoryMin;
            }
        }

        if (MinimumOfLootDrops > NumberOfLootDrops)
        {
            FN_LOG(LogLoot, Warning, "Requested %i loot drops but minimum drops is %i for loot package %s", NumberOfLootDrops, MinimumOfLootDrops, LootTierData->LootPackage.ToString().c_str());
            LootMaps->clear();
            return false;
        }

        int32 TotalCategoryWeight = 0;
        std::map<int32, int32> CategoryWeightMap;

        for (int32 i = 0; i < LootTierData->LootPackageCategoryWeightArray.Num(); i++)
        {
            int32 LootPackageCategoryWeight = LootTierData->LootPackageCategoryWeightArray[i];
            int32 LootPackageCategoryMax = LootTierData->LootPackageCategoryMaxArray[i];

            if (LootPackageCategoryWeight > 0)
            {
                int32 CurrentDropsForCategory = LootMaps->contains(i) ? LootMaps->at(i) : 0;

                if (LootPackageCategoryMax < 0 || CurrentDropsForCategory < LootPackageCategoryMax)
                {
                    TotalCategoryWeight += LootPackageCategoryWeight;
                    CategoryWeightMap.emplace(i, LootPackageCategoryWeight);
                }
            }
        }

        if (MinimumOfLootDrops < NumberOfLootDrops)
        {
            while (TotalCategoryWeight > 0)
            {
                float RandomValue = (float)rand() * 0.000030518509f;

                int32 WeightedRandomSelection = (int32)((TotalCategoryWeight * RandomValue * 2) + 0.5f) >> 1;
                int32 SelectedDropCategory = 0;

                for (auto& [DropCategory, Weight] : CategoryWeightMap)
                {
                    if (WeightedRandomSelection <= Weight)
                    {
                        SelectedDropCategory = DropCategory;
                        break;
                    }

                    WeightedRandomSelection -= Weight;
                }

                int32& NumDropsForCategory = (*LootMaps)[SelectedDropCategory];
                NumDropsForCategory++;
                MinimumOfLootDrops++;

                int32 MaxDropsForCategory = LootTierData->LootPackageCategoryMaxArray[SelectedDropCategory];

                if (MaxDropsForCategory >= 0 && NumDropsForCategory >= MaxDropsForCategory)
                {
                    FN_LOG(LogLoot, Warning, "We have dropped %i items of category %i but the max is %i for tier group %s at tier %i.",
                        NumDropsForCategory, SelectedDropCategory, MaxDropsForCategory, LootTierData->TierGroup.ToString().c_str(), LootTierData->LootTier);

                    CategoryWeightMap.erase(SelectedDropCategory);
                }

                TotalCategoryWeight -= LootTierData->LootPackageCategoryWeightArray[SelectedDropCategory];

                if (MinimumOfLootDrops >= NumberOfLootDrops)
                    break;
            }

            if (MinimumOfLootDrops < NumberOfLootDrops)
            {
                FN_LOG(LogLoot, Warning, "Requested %i loot drops but maximum drops is %i for loot package %s", NumberOfLootDrops, MinimumOfLootDrops, LootTierData->LootPackage.ToString().c_str());
                LootMaps->clear();
                return false;
            }
        }

        return true;
    }

    bool PickLootDrops(TArray<FFortItemEntry>* OutLootToDrops, int32 WorldLevel, FName LootTierKey, __int64 a4, __int64 a5, FGameplayTagContainer StaticGameplayTags, bool bAllowBonusDrops, bool a8)
    {
        if (!LootTierKey.IsValid())
            return false;

        OutLootToDrops->Clear();

        UGameDataBR* GameDataBR = Globals::GetGameDataBR();
        FFortLootTierData* LootTierData = FindLootTierDataRow(GameDataBR, LootTierKey, L"UFortLootPackage::PickLootDrops");

        int32 NumberOfLootDrops = 0;

        if (LootTierData && CheckLootPackageDataTables(GameDataBR))
        {
            FName LootPackageName = a8 ? LootTierData->LootPreviewPackage : LootTierData->LootPackage;

            float NumLootPackageDrops = LootTierData->NumLootPackageDrops;

            if (NumLootPackageDrops > 0.0f)
            {
                if (a8 || NumLootPackageDrops < 1.0f)
                {
                    NumberOfLootDrops = 1;
                }
                else
                {
                    NumberOfLootDrops = (int32)((NumLootPackageDrops * 2) - 0.5f) / 2;
                    float RemainingFraction = NumLootPackageDrops - (float)NumberOfLootDrops;

                    if (RemainingFraction > 0.0000099999997f)
                    {
                        if (a5)
                            NumberOfLootDrops += RemainingFraction >= 0.0f; // sub_7FF71A068EB0(a5);
                        else
                            NumberOfLootDrops += RemainingFraction >= (float)rand() * 0.000030518509f;
                    }
                }

                FN_LOG(LogLoot, Debug, "Actual number of loot drops is: %i", NumberOfLootDrops);

                std::map<int32, int32> LootMap;

                if (a8)
                {
                    /*int v52 = 0;
                    int v53 = 1;
                    __int128 v49 = reinterpret_cast<__int128>(&v52);
                    __int128 v50 = reinterpret_cast<__int128>(&v53);
                    sub_7FF719EA2B50(&LootMap, nullptr, reinterpret_cast<int**>(&v49), 0i64);*/
                }
                else
                {
                    ProcessLootDrops(LootTierData, NumberOfLootDrops, &LootMap, a5);
                }

                for (const auto& [LootPackageCategory, DropCount] : LootMap)
                {
                    FN_LOG(LogLoot, Debug, "Dropping %i loot packages from drop category %i", DropCount, LootPackageCategory);

                    if (DropCount > 0)
                    {
                        bool v33 = !a8 && bAllowBonusDrops && LootTierData->bAllowBonusLootDrops;

                        for (int32 i = 0; i < DropCount; ++i)
                        {
                            PickLootDropsFromLootPackage(
                                OutLootToDrops,
                                LootPackageName,
                                WorldLevel,
                                LootPackageCategory,
                                a4,
                                0,
                                StaticGameplayTags,
                                v33);
                        }
                    }
                }
            }

            int32 NumberOfLootToDrops = OutLootToDrops->Num();

            if (NumberOfLootToDrops > 0)
            {
                for (int32 i = 0; i < NumberOfLootToDrops; ++i)
                {
                    FFortItemEntry* ItemEntry = &(*OutLootToDrops)[i];
                    UFortItemDefinition* ItemDefinition = ItemEntry->ItemDefinition;

                    if (!ItemDefinition || ItemDefinition->bAllowMultipleStacks)
                        continue;

                    for (int32 j = i + 1; j < NumberOfLootToDrops; ++j)
                    {
                        FFortItemEntry* NextItemEntry = &(*OutLootToDrops)[j];

                        if (ItemEntry->ItemDefinition != NextItemEntry->ItemDefinition)
                            continue;

                        int32 NewCount = ItemEntry->Count + NextItemEntry->Count;

                        ItemEntry->SetCount(NewCount);

                        OutLootToDrops->Remove(j--);
                        NumberOfLootToDrops--;
                    }
                }
            }
        }

        return (NumberOfLootDrops > 0);
    }
}