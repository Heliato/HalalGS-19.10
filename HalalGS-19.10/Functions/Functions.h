#pragma once
#include <map>

namespace Functions
{
	bool IsPlayerBuildableClasse(UClass* BuildableClass)
	{
		AFortGameStateAthena* GameState = Cast<AFortGameStateAthena>(Globals::GetGameState());

		if (!BuildableClass || !GameState)
			return false;

		TArray<TSubclassOf<ABuildingActor>> BuildingActorClasses = GameState->BuildingActorClasses;

		if (BuildingActorClasses.IsValid())
		{
			for (int32 i = 0; i < BuildingActorClasses.Num(); i++)
			{
				TSubclassOf<ABuildingActor> BuildingActorClass = BuildingActorClasses[i];
				if (!BuildingActorClass.Get()) continue;

				if (BuildingActorClass.Get() == BuildableClass)
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

	UFortAbilitySet* LoadAbilitySet(TSoftObjectPtr<UFortAbilitySet> SoftAbilitySet)
	{
		UFortAbilitySet* AbilitySet = SoftAbilitySet.Get();

		if (!AbilitySet && SoftAbilitySet.ObjectID.AssetPathName.IsValid())
		{
			const FString& AssetPathName = UKismetStringLibrary::Conv_NameToString(SoftAbilitySet.ObjectID.AssetPathName);
			AbilitySet = StaticLoadObject<UFortAbilitySet>(AssetPathName.CStr());
		}

		return AbilitySet;
	}

	UFortGameplayAbility* LoadGameplayAbility(TSoftClassPtr<UClass> SoftGameplayAbility)
	{
		UClass* GameplayAbilityClass = SoftGameplayAbility.Get();

		if (!GameplayAbilityClass)
		{
			const FString& AssetPathName = UKismetStringLibrary::Conv_NameToString(SoftGameplayAbility.ObjectID.AssetPathName);
			GameplayAbilityClass = StaticLoadObject<UClass>(AssetPathName.CStr());
		}

		if (GameplayAbilityClass)
			return Cast<UFortGameplayAbility>(GameplayAbilityClass->CreateDefaultObject());

		return nullptr;
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

	void SpawnVehicles()
	{
		TArray<AActor*> Actors;
		UGameplayStatics::GetAllActorsOfClass(Globals::GetWorld(), AFortAthenaVehicleSpawner::StaticClass(), &Actors);

		for (int32 i = 0; i < Actors.Num(); i++)
		{
			AFortAthenaVehicleSpawner* AthenaVehicleSpawner = Cast<AFortAthenaVehicleSpawner>(Actors[i]);
			if (!AthenaVehicleSpawner) continue;

			UClass* VehicleClass = AthenaVehicleSpawner->GetVehicleClass();
			if (!VehicleClass) continue;

			FVector SpawnLocation = AthenaVehicleSpawner->K2_GetActorLocation();
			FRotator SpawnRotation = AthenaVehicleSpawner->K2_GetActorRotation();

			AFortAthenaVehicle* AthenaVehicle = Cast<AFortAthenaVehicle>(Globals::GetWorld()->SpawnActor(VehicleClass, &SpawnLocation, &SpawnRotation));
			if (!AthenaVehicle) continue;

			AthenaVehicleSpawner->OnConstructVehicle(AthenaVehicle);

			TSoftObjectPtr<UFortVehicleItemDefinition> FortVehicleItemDef = AthenaVehicleSpawner->FortVehicleItemDef;
			UFortVehicleItemDefinition* VehicleItemDefinition = FortVehicleItemDef.Get();

			if (!VehicleItemDefinition && FortVehicleItemDef.ObjectID.AssetPathName.IsValid())
			{
				const FString& AssetPathName = UKismetStringLibrary::Conv_NameToString(FortVehicleItemDef.ObjectID.AssetPathName);
				VehicleItemDefinition = StaticLoadObject<UFortVehicleItemDefinition>(AssetPathName.CStr());
			}

			if (VehicleItemDefinition)
			{
				// FN_LOG(LogInit, Log, "VehicleClass: %s, VehicleItemDefinition: %s", VehicleClass->GetFullName().c_str(), VehicleItemDefinition->GetFullName().c_str());
			}

			// FN_LOG(LogInit, Log, "AthenaVehicleSpawner: %s, VehicleClass: %s, AthenaVehicle: %s", AthenaVehicleSpawner->GetFullName().c_str(), VehicleClass->GetFullName().c_str(), AthenaVehicle->GetFullName().c_str());
		}

		if (Actors.IsValid())
			Actors.Free();
	}

	ABuildingGameplayActorConsumable* SpawnGameplayActorConsumable(ABGAConsumableSpawner* ConsumableSpawner, UBGAConsumableWrapperItemDefinition* ConsumableWrapperItemDefinition)
	{
		if (!ConsumableSpawner || !ConsumableWrapperItemDefinition)
			return nullptr;

		UClass* ConsumableClass = ConsumableWrapperItemDefinition->ConsumableClass.Get();

		if (!ConsumableClass)
		{
			const FString& AssetPathName = UKismetStringLibrary::Conv_NameToString(ConsumableWrapperItemDefinition->ConsumableClass.ObjectID.AssetPathName);
			ConsumableClass = StaticLoadObject<UClass>(AssetPathName.CStr());
		}

		if (!ConsumableClass)
			return nullptr;

		FVector SpawnLocation = ConsumableSpawner->K2_GetActorLocation();
		FVector RandomDirection = UKismetMathLibrary::RandomUnitVector();

		SpawnLocation.X += RandomDirection.X * 500.0f;
		SpawnLocation.Y += RandomDirection.Y * 500.0f;

		const FVector& End = SpawnLocation - FVector({ 0, 0, 1000 });

		FHitResult HitResult;
		bool bHit = UKismetSystemLibrary::LineTraceSingle(
			ConsumableSpawner,
			SpawnLocation,
			End,
			ETraceTypeQuery::TraceTypeQuery1,
			false,
			TArray<AActor*>(),
			EDrawDebugTrace::ForDuration,
			&HitResult,
			true,
			FLinearColor(),
			FLinearColor(),
			0.0f);

		if (bHit)
			SpawnLocation = HitResult.Location;

		FTransform SpawnTransform = UKismetMathLibrary::MakeTransform(SpawnLocation, ConsumableSpawner->K2_GetActorRotation(), FVector({ 1, 1, 1 }));

		ABuildingGameplayActorConsumable* GameplayActorConsumable = Cast<ABuildingGameplayActorConsumable>(ConsumableSpawner->GetWorld()->SpawnActor(ConsumableClass, &SpawnTransform));

		if (GameplayActorConsumable)
			UGameplayStatics::FinishSpawningActor(GameplayActorConsumable, SpawnTransform);

		return GameplayActorConsumable;
	}

	void InitializeConsumableBGAs()
	{
		AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(Globals::GetGameState());

		if (GameStateAthena)
		{
			UBlueprintGeneratedClass* GameplayActorConsumableClass = StaticLoadObject<UBlueprintGeneratedClass>(L"/Game/Athena/BuildingActors/ConsumableBGAs/Spawner/BP_BGACSpawner.BP_BGACSpawner_C");

			TArray<AActor*> Actors;
			UGameplayStatics::GetAllActorsOfClass(GameStateAthena, GameplayActorConsumableClass, &Actors);

			for (int32 i = 0; i < Actors.Num(); i++)
			{
				ABGAConsumableSpawner* ConsumableSpawner = Cast<ABGAConsumableSpawner>(Actors[i]);
				if (!ConsumableSpawner) continue;

				int32 LootLevel = UFortKismetLibrary::GetLootLevel(GameStateAthena);

				TArray<FFortItemEntry> LootToDrops;
				UFortKismetLibrary::PickLootDrops(GameStateAthena, &LootToDrops, ConsumableSpawner->SpawnLootTierGroup, LootLevel, -1);

				FVector SpawnerLocation = ConsumableSpawner->K2_GetActorLocation();

				for (int32 j = 0; j < LootToDrops.Num(); j++)
				{
					FFortItemEntry LootToDrop = LootToDrops[j];

					UBGAConsumableWrapperItemDefinition* ConsumableWrapperItemDefinition = Cast<UBGAConsumableWrapperItemDefinition>(LootToDrop.ItemDefinition);
					if (!ConsumableWrapperItemDefinition) continue;

					ABuildingGameplayActorConsumable* GameplayActorConsumable = SpawnGameplayActorConsumable(ConsumableSpawner, ConsumableWrapperItemDefinition);
					if (!ConsumableWrapperItemDefinition) continue;

					FVector ConsumableLocation = GameplayActorConsumable->K2_GetActorLocation();

					FN_LOG(LogFunctions, Debug, "[%i/%i] - GameplayActorConsumable: %s, ConsumableLocation: [X: %.2f, Y: %.2f, Z: %.2f]",
						(j + 1), LootToDrops.Num(), GameplayActorConsumable->GetFullName().c_str(), ConsumableLocation.X, ConsumableLocation.Y, ConsumableLocation.Z);

					ConsumableSpawner->ConsumablesToSpawn.Add(LootToDrop);
				}
			}
		}
	}

	void InitializeTreasureChests()
	{
		AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(Globals::GetGameState());

		if (GameStateAthena && GameStateAthena->MapInfo)
		{
			AFortAthenaMapInfo* MapInfo = GameStateAthena->MapInfo;

			TArray<FFortTreasureChestSpawnInfo> TreasureChestSpawnInfos = MapInfo->TreasureChestSpawnInfos;

			for (int32 i = 0; i < TreasureChestSpawnInfos.Num(); i++)
			{
				FFortTreasureChestSpawnInfo TreasureChestSpawnInfo = TreasureChestSpawnInfos[i];

				const float TreasureChestMinSpawnPercent = TreasureChestSpawnInfo.TreasureChestMinSpawnPercent.GetValueAtLevel(0);
				const float TreasureChestMaxSpawnPercent = TreasureChestSpawnInfo.TreasureChestMaxSpawnPercent.GetValueAtLevel(0);

				TArray<AActor*> TreasureChests;
				UGameplayStatics::GetAllActorsOfClass(MapInfo, TreasureChestSpawnInfo.TreasureChestClass, &TreasureChests);

				int32 TotalTreasureChests = TreasureChests.Num();
				int32 MinTreasureChestsToKeep = std::floor(TotalTreasureChests * (TreasureChestMinSpawnPercent / 100.0f));
				int32 MaxTreasureChestsToKeep = std::floor(TotalTreasureChests * (TreasureChestMaxSpawnPercent / 100.0f));

				int32 NumTreasureChestsToKeep = UKismetMathLibrary::RandomIntegerInRange(MinTreasureChestsToKeep, MaxTreasureChestsToKeep);

				for (int32 j = TotalTreasureChests - 1; j >= NumTreasureChestsToKeep; --j)
				{
					int32 IndexToDestroy = UKismetMathLibrary::RandomIntegerInRange(0, j);

					TreasureChests[IndexToDestroy]->K2_DestroyActor();
					TreasureChests.Remove(IndexToDestroy);
				}

				if (TreasureChests.IsValid())
					TreasureChests.Clear();
			}
		}
	}

	void InitializeAmmoBoxs()
	{
		AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(Globals::GetGameState());

		if (GameStateAthena && GameStateAthena->MapInfo)
		{
			AFortAthenaMapInfo* MapInfo = GameStateAthena->MapInfo;

			TArray<FFortAmmoBoxSpawnInfo> AmmoBoxSpawnInfos = MapInfo->AmmoBoxSpawnInfos;

			for (int32 i = 0; i < AmmoBoxSpawnInfos.Num(); i++)
			{
				FFortAmmoBoxSpawnInfo AmmoBoxSpawnInfo = AmmoBoxSpawnInfos[i];

				const float AmmoBoxMinSpawnPercent = AmmoBoxSpawnInfo.AmmoBoxMinSpawnPercent.GetValueAtLevel(0);
				const float AmmoBoxMaxSpawnPercent = AmmoBoxSpawnInfo.AmmoBoxMaxSpawnPercent.GetValueAtLevel(0);

				TArray<AActor*> AmmoBoxs;
				UGameplayStatics::GetAllActorsOfClass(MapInfo, AmmoBoxSpawnInfo.AmmoBoxClass, &AmmoBoxs);

				int32 TotalAmmoBoxs = AmmoBoxs.Num();
				int32 MinAmmoBoxsToKeep = std::floor(TotalAmmoBoxs * (AmmoBoxMinSpawnPercent / 100.0f));
				int32 MaxAmmoBoxsToKeep = std::floor(TotalAmmoBoxs * (AmmoBoxMaxSpawnPercent / 100.0f));

				int32 NumAmmoBoxsToKeep = UKismetMathLibrary::RandomIntegerInRange(MinAmmoBoxsToKeep, MaxAmmoBoxsToKeep);

				for (int32 j = TotalAmmoBoxs - 1; j >= NumAmmoBoxsToKeep; --j)
				{
					int32 IndexToDestroy = UKismetMathLibrary::RandomIntegerInRange(0, j);

					AmmoBoxs[IndexToDestroy]->K2_DestroyActor();
					AmmoBoxs.Remove(IndexToDestroy);
				}

				if (AmmoBoxs.IsValid())
					AmmoBoxs.Free();
			}
		}
	}

	void InitializeDeployTraceForGroundDistance()
	{
		AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(Globals::GetGameState());

		if (GameStateAthena)
		{
			UCurveTable* AthenaGameData = GameStateAthena->CurrentPlaylistInfo.BasePlaylist->GameData.Get();

			if (!AthenaGameData)
			{
				AthenaGameData = GameStateAthena->AthenaGameDataTable;

				if (!AthenaGameData)
					AthenaGameData = StaticLoadObject<UCurveTable>(L"/Game/Balance/AthenaGameData.AthenaGameData");
			}

			if (AthenaGameData)
			{
				FName DeployTraceForGroundDistanceName = UKismetStringLibrary::Conv_StringToName(L"Default.Parachute.DeployTraceForGroundDistance");

				float DefaultParachuteDeployTraceForGroundDistance;
				UDataTableFunctionLibrary::EvaluateCurveTableRow(AthenaGameData, DeployTraceForGroundDistanceName, 0, nullptr, &DefaultParachuteDeployTraceForGroundDistance, L"Functions::InitializeDeployTraceForGroundDistance");

				GameStateAthena->DefaultParachuteDeployTraceForGroundDistance = DefaultParachuteDeployTraceForGroundDistance;
			}
		}
	}

	bool InitializeSafeZoneDamage()
	{
		AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(Globals::GetGameState());

		if (GameStateAthena)
		{
			UCurveTable* AthenaGameData = GameStateAthena->CurrentPlaylistInfo.BasePlaylist->GameData.Get();

			if (!AthenaGameData)
			{
				AthenaGameData = GameStateAthena->AthenaGameDataTable;

				if (!AthenaGameData)
					AthenaGameData = StaticLoadObject<UCurveTable>(L"/Game/Balance/AthenaGameData.AthenaGameData");
			}

			if (AthenaGameData)
			{
				FName DefaultSafeZoneDamageName = UKismetStringLibrary::Conv_StringToName(L"Default.SafeZone.Damage");
				FSimpleCurve* SimpleCurve = (FSimpleCurve*)AthenaGameData->FindCurve(DefaultSafeZoneDamageName, L"Functions::InitializeSafeZoneDamage");

				if (SimpleCurve)
				{
					float Test = SimpleCurve->Eval(0);

					FN_LOG(LogFunctions, Log, "Functions::InitializeSafeZoneDamage - Test Result: %.2f", Test);
					
					for (int32 i = 0; i < SimpleCurve->Keys.Num(); i++)
					{
						FSimpleCurveKey* SimpleCurveKey = &SimpleCurve->Keys[i];
						if (!SimpleCurveKey) continue;

						if (SimpleCurveKey->Time == 0.0f)
						{
							SimpleCurveKey->Value = 0.0f;
						}
					}
					
					float Test2 = SimpleCurve->Eval(0);

					FN_LOG(LogFunctions, Log, "Functions::InitializeSafeZoneDamage - Test 2 Result: %.2f", Test2);

					return true;
				}
			}
		}

		return false;
	}

	void InitializeAI()
	{
		AFortGameModeAthena* GameModeAthena = Globals::GetGameMode();
		UFortPlaylistAthena* PlaylistAthena = Globals::GetPlaylist();
		UGameDataBR* GameDataBR = Globals::GetGameDataBR();
		UWorld* World = Globals::GetWorld();

		if (GameModeAthena && PlaylistAthena && GameDataBR && World)
		{
			// Setup AIDirector
			{
				UClass* AIDirectorBRClass = Functions::LoadClass(GameDataBR->AIDirectorBR);

				if (!AIDirectorBRClass)
					AIDirectorBRClass = AAthenaAIDirector::StaticClass();

				if (AIDirectorBRClass)
				{
					AFortAIDirector* AIDirector = Cast<AFortAIDirector>(World->SpawnActor(AIDirectorBRClass));

					if (AIDirector)
					{
						AIDirector->SetOwner(GameModeAthena);
						AIDirector->OnRep_Owner();

						GameModeAthena->AIDirector = AIDirector;
						GameModeAthena->AIDirector->Activate();
					}
				}
			}
			
			// Setup AIGoalManager
			{
				UClass* AIGoalManagerBRClass = Functions::LoadClass(GameDataBR->AIGoalManagerBR);

				if (!AIGoalManagerBRClass)
					AIGoalManagerBRClass = AFortAIGoalManager::StaticClass();

				AFortAIGoalManager* AIGoalManager = Cast<AFortAIGoalManager>(World->SpawnActor(AIGoalManagerBRClass));

				if (AIGoalManager)
				{
					AIGoalManager->SetOwner(GameModeAthena);
					AIGoalManager->OnRep_Owner();

					GameModeAthena->AIGoalManager = AIGoalManager;
				}
			}

			// Setup AISettings
			{
				GameModeAthena->AISettings = PlaylistAthena->AISettings;
			}

			// Unhandled Exception: EXCEPTION_ACCESS_VIOLATION reading address 0x00000000000000d4
		}
	}

	bool HasGameplayTags(TArray<FGameplayTag> GameplayTags, FName TagNameRequired)
	{
		const FString& TagNameRequiredString = UKismetStringLibrary::Conv_NameToString(TagNameRequired);
		const FString& TagNameRequiredLower = UKismetStringLibrary::ToLower(TagNameRequiredString);

		for (int32 j = 0; j < GameplayTags.Num(); j++)
		{
			FGameplayTag GameplayTag = GameplayTags[j];

			FName TagName = GameplayTag.TagName;
			if (!TagName.IsValid()) continue;

			const FString& TagNameString = UKismetStringLibrary::Conv_NameToString(TagName);
			const FString& TagNameLower = UKismetStringLibrary::ToLower(TagNameString);

			if (TagNameLower == TagNameRequiredLower)
				return true;
		}

		return false;
	}

	TArray<UFortItemDefinition*> PickOnlyAthena(TArray<UFortItemDefinition*> AllItems)
	{
		static TArray<UFortItemDefinition*> AllAthenaItems;

		if (AllAthenaItems.Num() > 0)
			return AllAthenaItems;

		for (int32 i = 0; i < AllItems.Num(); i++)
		{
			UFortItemDefinition* ItemDefinition = AllItems[i];

			if (!ItemDefinition)
				continue;

			const FString& PathName = UKismetSystemLibrary::GetPathName(ItemDefinition);

			if (!PathName.ToString().contains("/Game/Athena/Items"))
				continue;

			AllAthenaItems.Add(ItemDefinition);
		}

		return AllAthenaItems;
	}

	TArray<UFortItemDefinition*> GetAllItems(bool bOnlyAthena = false)
	{
		static TArray<UFortItemDefinition*> AllItems;

		if (AllItems.Num() > 0)
			return bOnlyAthena ? PickOnlyAthena(AllItems) : AllItems;

		for (int32 i = 0; i < UObject::GObjects->Num(); i++)
		{
			UObject* GObject = UObject::GObjects->GetByIndex(i);

			if (!GObject)
				continue;

			if (GObject->IsA(UFortItemDefinition::StaticClass()))
			{
				UFortItemDefinition* ItemDefinition = Cast<UFortItemDefinition>(GObject);
				if (!ItemDefinition) continue;

				AllItems.Add(ItemDefinition);
			}
		}

		return bOnlyAthena ? PickOnlyAthena(AllItems) : AllItems;
	}

	TArray<UFortWorldItemDefinition*> GetAllItemsWithClass(bool bOnlyAthena, UClass* Class)
	{
		TArray<UFortItemDefinition*> AllItems = GetAllItems(bOnlyAthena);
		TArray<UFortWorldItemDefinition*> AllItemsWithClass;

		for (int32 i = 0; i < AllItems.Num(); i++)
		{
			UFortItemDefinition* ItemDefinition = AllItems[i];

			if (!ItemDefinition)
				continue;

			if (ItemDefinition->IsA(Class))
			{
				UFortWorldItemDefinition* WorldItemDefinition = Cast<UFortWorldItemDefinition>(ItemDefinition);
				if (!WorldItemDefinition) continue;

				AllItemsWithClass.Add(WorldItemDefinition);
			}
		}

		return AllItemsWithClass;
	}

	TArray<UFortWeaponItemDefinition*> GetAllItemsWithTag(const FName& TagNameRequired, TArray<UFortWorldItemDefinition*> BlackListWorldItemDefinitions, TArray<EFortRarity> BlackListRaritys, TArray<EFortItemType> BlackListItemTypes)
	{
		TArray<UFortItemDefinition*> AllItems = GetAllItems(true);
		TArray<UFortWeaponItemDefinition*> AllItemsWithTag;

		if (!TagNameRequired.IsValid())
			return AllItemsWithTag;

		for (int32 i = 0; i < AllItems.Num(); i++)
		{
			UFortWeaponItemDefinition* WeaponRangedItemDefinition = Cast<UFortWeaponItemDefinition>(AllItems[i]);
			if (!WeaponRangedItemDefinition) continue;

			bool bBlacklistItem = false;
			for (int32 j = 0; j < BlackListWorldItemDefinitions.Num(); j++)
			{
				UFortWorldItemDefinition* BlackListWorldItemDefinition = BlackListWorldItemDefinitions[j];
				if (!BlackListWorldItemDefinition) continue;

				if (BlackListWorldItemDefinition == WeaponRangedItemDefinition)
				{
					bBlacklistItem = true;
					break;
				}
			}

			if (bBlacklistItem)
				continue;

			bool bBlackListRariry = false;
			for (int32 j = 0; j < BlackListRaritys.Num(); j++)
			{
				EFortRarity BlackListRarity = BlackListRaritys[j];

				if (BlackListRarity == WeaponRangedItemDefinition->Rarity)
				{
					bBlackListRariry = true;
					break;
				}
			}

			if (bBlackListRariry)
				continue;

			bool bBlackListItemType = false;
			for (int32 j = 0; j < BlackListItemTypes.Num(); j++)
			{
				EFortItemType BlackListItemType = BlackListItemTypes[j];

				if (BlackListItemType == WeaponRangedItemDefinition->ItemType)
				{
					bBlackListItemType = true;
					break;
				}
			}

			if (bBlackListItemType)
				continue;

			TArray<FGameplayTag> GameplayTags = WeaponRangedItemDefinition->GameplayTags.GameplayTags;

			const FString& TagNameRequiredString = UKismetStringLibrary::Conv_NameToString(TagNameRequired);
			const FString& TagNameRequiredLower = UKismetStringLibrary::ToLower(TagNameRequiredString);

			bool bFindTagName = false;
			for (int32 j = 0; j < GameplayTags.Num(); j++)
			{
				FGameplayTag GameplayTag = GameplayTags[j];

				FName TagName = GameplayTag.TagName;
				if (!TagName.IsValid()) continue;

				const FString& TagNameString = UKismetStringLibrary::Conv_NameToString(TagName);
				const FString& TagNameLower = UKismetStringLibrary::ToLower(TagNameString);

				if (TagNameLower == TagNameRequiredLower)
				{
					bFindTagName = true;
					break;
				}
			}

			if (!bFindTagName)
				continue;

			AllItemsWithTag.Add(WeaponRangedItemDefinition);
		}

		return AllItemsWithTag;
	}

	void ApplySiphonEffect(AFortPlayerState* PlayerState)
	{
		if (PlayerState)
		{
			UFortAbilitySystemComponent* AbilitySystemComponent = PlayerState->AbilitySystemComponent;

			if (AbilitySystemComponent)
			{
				FGameplayTag GameplayTag = FGameplayTag();
				GameplayTag.TagName = UKismetStringLibrary::Conv_StringToName(L"GameplayCue.Shield.PotionConsumed");

				AbilitySystemComponent->NetMulticast_InvokeGameplayCueAdded(GameplayTag, FPredictionKey(), FGameplayEffectContextHandle());
				AbilitySystemComponent->NetMulticast_InvokeGameplayCueExecuted(GameplayTag, FPredictionKey(), FGameplayEffectContextHandle());
			}
		}
	}

	void GiveSiphonBonus(AFortPlayerController* PlayerController, AFortPawn* Pawn, bool bGiveBuildingResource = true, bool bHealPlayer = true)
	{
		if (PlayerController)
		{
			if (bGiveBuildingResource)
			{
				UFortKismetLibrary::K2_GiveBuildingResource(PlayerController, EFortResourceType::Wood, 50);
				UFortKismetLibrary::K2_GiveBuildingResource(PlayerController, EFortResourceType::Stone, 50);
				UFortKismetLibrary::K2_GiveBuildingResource(PlayerController, EFortResourceType::Metal, 50);
			}

			if (bHealPlayer && Pawn)
			{
				float MaxHealth = Pawn->GetMaxHealth();
				float MaxShield = Pawn->GetMaxShield();

				float Health = Pawn->GetHealth();
				float Shield = Pawn->GetShield();

				float SiphonAmount = 200.0f;
				float RemainingSiphonAmount = SiphonAmount;

				if (Health < MaxHealth)
				{
					float NewHealth = std::clamp(Health + SiphonAmount, 0.0f, MaxHealth);

					Pawn->SetHealth(NewHealth);

					RemainingSiphonAmount -= (NewHealth - Health);
				}

				if (RemainingSiphonAmount > 0.0f)
				{
					float NewShield = std::clamp(Shield + RemainingSiphonAmount, 0.0f, MaxShield);

					Pawn->SetShield(NewShield);
				}
			}

			AFortPlayerState* PlayerState = Cast<AFortPlayerState>(PlayerController->PlayerState);

			if (PlayerState)
			{
				ApplySiphonEffect(PlayerState);
			}
		}
	}

	void InitFunctions()
	{
		FN_LOG(LogInit, Log, "InitFunctions Success!");
	}
}