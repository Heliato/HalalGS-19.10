#pragma once

enum ENetMode
{
	NM_Standalone,
	NM_DedicatedServer,
	NM_ListenServer,
	NM_Client,
	NM_MAX,
};

namespace Hooks
{
	void (*GetPlayerViewPointOG)(APlayerController* PlayerController, FVector& out_Location, FRotator& out_Rotation);
	void (*ProcessEventOG)(UObject* Object, UFunction* Function, void* Parms);

	uintptr_t GIsClient()
	{
		return __int64(GetModuleHandleW(0)) + 0xB30CF9F;
	}

	uintptr_t GIsServer()
	{
		return __int64(GetModuleHandleW(0)) + 0xB30CF9D;
	}

	ENetMode ReturnNetMode()
	{
		return ENetMode::NM_DedicatedServer;
	}

	bool LocalSpawnPlayActor()
	{
		return true;
	}

	void KickPlayerHook()
	{
		return;
	}

	void GetPlayerViewPoint(APlayerController* PlayerController, FVector& out_Location, FRotator& out_Rotation)
	{
		APawn* Pawn = PlayerController->Pawn;
		ASpectatorPawn* SpectatorPawn = PlayerController->SpectatorPawn;

		if (Pawn)
		{
			out_Location = Pawn->K2_GetActorLocation();
			out_Rotation = PlayerController->GetControlRotation();
			return;
		}
		else if (SpectatorPawn && PlayerController->HasAuthority())
		{
			out_Location = SpectatorPawn->K2_GetActorLocation();
			out_Rotation = ((APlayerController*)SpectatorPawn->Owner)->GetControlRotation();
			return;
		}
		else if (!SpectatorPawn && !Pawn)
		{
			out_Location = PlayerController->LastSpectatorSyncLocation;
			out_Rotation = PlayerController->LastSpectatorSyncRotation;
			return;
		}

		GetPlayerViewPointOG(PlayerController, out_Location, out_Rotation);
	}

	bool bLogs = false;

	void ProcessEvent(UObject* Object, UFunction* Function, void* Parms)
	{
		if (!Object || !Function)
		{
			ProcessEventOG(Object, Function, Parms);
			return;
		}

		const std::string& FunctionName = Function->GetName();

		if (FunctionName.contains("Tick"))
		{
			if (GetAsyncKeyState(VK_F1) & 0x1)
			{
				AFortPlayerController* PlayerController = Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));

				if (!PlayerController)
					return;
			}

			if (GetAsyncKeyState(VK_F2) & 0x1)
			{
				AFortPlayerController* PlayerController = Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));

				if (!PlayerController)
					return;
			}

			if (GetAsyncKeyState(VK_F3) & 0x1)
			{
				AFortPlayerController* PlayerController = Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));

				if (!PlayerController)
					return;
			}

			if (GetAsyncKeyState(VK_F4) & 0x1)
			{
				AFortPlayerController* PlayerController = Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));

				if (!PlayerController)
					return;
			}

			if (GetAsyncKeyState(VK_F5) & 0x1)
			{
				AFortPlayerController* PlayerController = Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));

				if (!PlayerController)
					return;

				PlayerController->GetWorld()->SpawnActor(AFortAIDirector::StaticClass());
			}

			if (GetAsyncKeyState(VK_F6) & 0x1)
			{
				AFortPlayerController* PlayerController = Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));

				if (!PlayerController)
					return;
			}

			if (GetAsyncKeyState(VK_F7) & 0x1)
			{
				AFortPlayerController* PlayerController = Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));

				if (!PlayerController)
					return;
			}

			if (GetAsyncKeyState(VK_F9) & 0x1)
			{
				AFortPlayerController* PlayerController = Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));

				if (!PlayerController)
					return;
			}

			if (GetAsyncKeyState(VK_F10) & 0x1)
			{
				AFortPlayerController* PlayerController = Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));

				if (!PlayerController)
					return;
			}
		}
		else if (FunctionName.contains("OnWorldReady"))
		{
			AFortGameModeAthena* GameModeAthena = Cast<AFortGameModeAthena>(Globals::GetGameMode());

			if (!GameModeAthena)
				return;

			AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(GameModeAthena->GameState);

			if (!GameStateAthena)
				return;

			if (!GameModeAthena->bWorldIsReady)
			{
				UFortPlaylistAthena* PlaylistAthena = Globals::GetPlaylist();

				if (PlaylistAthena && GameStateAthena)
				{
					for (int32 i = 0; i < PlaylistAthena->AdditionalLevels.Num(); i++)
					{
						TSoftObjectPtr<UWorld> AdditionalLevel = PlaylistAthena->AdditionalLevels[i];

						FName FoundationName = AdditionalLevel.ObjectID.AssetPathName;
						if (!FoundationName.IsValid()) continue;

						bool bSuccess = false;
						ULevelStreamingDynamic::LoadLevelInstanceBySoftObjectPtr(GameStateAthena, AdditionalLevel, FVector(), FRotator(), &bSuccess, FString(), {});

						if (bSuccess)
						{
							FName LevelName = AdditionalLevel.ObjectID.AssetPathName;
							if (!LevelName.IsValid()) continue;

							FAdditionalLevelStreamed AdditionalLevelStreamed = FAdditionalLevelStreamed();
							AdditionalLevelStreamed.bIsServerOnly = false;
							AdditionalLevelStreamed.LevelName = LevelName;

							GameStateAthena->AdditionalPlaylistLevelsStreamed.Add(AdditionalLevelStreamed);
						}
					}

					for (int32 i = 0; i < PlaylistAthena->AdditionalLevelsServerOnly.Num(); i++)
					{
						TSoftObjectPtr<UWorld> AdditionalLevelsServerOnly = PlaylistAthena->AdditionalLevelsServerOnly[i];

						FName FoundationName = AdditionalLevelsServerOnly.ObjectID.AssetPathName;
						if (!FoundationName.IsValid()) continue;

						bool bSuccess = false;
						ULevelStreamingDynamic::LoadLevelInstanceBySoftObjectPtr(GameStateAthena, AdditionalLevelsServerOnly, FVector(), FRotator(), &bSuccess, FString(), {});

						if (bSuccess)
						{
							FName LevelName = AdditionalLevelsServerOnly.ObjectID.AssetPathName;
							if (!LevelName.IsValid()) continue;

							FAdditionalLevelStreamed AdditionalLevelStreamed = FAdditionalLevelStreamed();
							AdditionalLevelStreamed.bIsServerOnly = true;
							AdditionalLevelStreamed.LevelName = LevelName;

							GameStateAthena->AdditionalPlaylistLevelsStreamed.Add(AdditionalLevelStreamed);
						}
					}

					GameStateAthena->OnRep_AdditionalPlaylistLevelsStreamed();
				}

				FN_LOG(LogHooks, Log, "OnWorldReady called!");
				GameModeAthena->bWorldIsReady = true;
			}
		}

		if (bLogs)
		{
			if (!FunctionName.contains("Tick") &&
				!FunctionName.contains("Visual") &&
				!FunctionName.contains("Clown Spinner") &&
				!FunctionName.contains("CustomStateChanged") &&
				!FunctionName.contains("ReceiveBeginPlay") &&
				!FunctionName.contains("OnAttachToBuilding") &&
				!FunctionName.contains("OnWorldReady") &&
				!FunctionName.contains("K2_GetActorLocation") &&
				!FunctionName.contains("ReceiveDrawHUD") &&
				!FunctionName.contains("ServerUpdateCamera") &&
				!FunctionName.contains("ServerMove") &&
				!FunctionName.contains("ContrailCheck") &&
				!FunctionName.contains("GetViewTarget") &&
				!FunctionName.contains("GetAllActorsOfClass") &&
				!FunctionName.contains("ClientAckGoodMove") &&
				!FunctionName.contains("ReadyToEndMatch") &&
				!FunctionName.contains("Check Closest Point") &&
				!FunctionName.contains("ServerTriggerCombatEvent") &&
				!FunctionName.contains("UpdateTime") &&
				!FunctionName.contains("OnUpdateMusic") &&
				!FunctionName.contains("UpdateStateEvent") &&
				!FunctionName.contains("ServerTouchActiveTime") &&
				!FunctionName.contains("OnCheckIfSurrounded") &&
				!FunctionName.contains("ServerFireAIDirectorEventBatch") &&
				!FunctionName.contains("ServerTriggerCombatEventBatch") &&
				!FunctionName.contains("UserConstructionScript") &&
				!FunctionName.contains("K2_OnReset") &&
				!FunctionName.contains("K2_OnEndViewTarget") &&
				!FunctionName.contains("K2_OnBecomeViewTarget") &&
				!FunctionName.contains("ReceiveUnpossessed") &&
				!FunctionName.contains("ClientGotoState") &&
				!FunctionName.contains("K2_OnEndViewTarget") &&
				!FunctionName.contains("K2_OnBecomeViewTarget") &&
				!FunctionName.contains("ClientSetViewTarget") &&
				!FunctionName.contains("ServerClientPawnLoaded") &&
				!FunctionName.contains("ReceiveEndPlay") &&
				!FunctionName.contains("OnPerceptionStimuliSourceEndPlay") &&
				!FunctionName.contains("HandleOnHUDElementVisibilityChanged") &&
				!FunctionName.contains("OnHUDElementVisibilityChanged") &&
				!FunctionName.contains("HandleInteractionChanged") &&
				!FunctionName.contains("BlueprintModifyCamera") &&
				!FunctionName.contains("BlueprintModifyPostProcess") &&
				!FunctionName.contains("ServerSetSpectatorLocation") &&
				!FunctionName.contains("ServerFireAIDirectorEvent") &&
				!FunctionName.contains("ServerTryActivateAbility") &&
				!FunctionName.contains("ClientActivateAbilitySucceed") &&
				!FunctionName.contains("ServerSetSpectatorLocation") &&
				!FunctionName.contains("CanJumpInternal") &&
				!FunctionName.contains("K2_OnMovementModeChanged") &&
				!FunctionName.contains("OnJumped") &&
				!FunctionName.contains("ServerModifyStat") &&
				!FunctionName.contains("OnLanded") &&
				!FunctionName.contains("ReceiveHit") &&
				!FunctionName.contains("OnWalkingOffLedge") &&
				!FunctionName.contains("ServerEndAbility") &&
				!FunctionName.contains("Execute") &&
				!FunctionName.contains("OnDamagePlayEffects") &&
				!FunctionName.contains("OnMontageStarted") &&
				!FunctionName.contains("OnNewDamageNumber") &&
				!FunctionName.contains("BP_GetTokenizedDescriptionText") &&
				!FunctionName.contains("GameplayCue_InstantDeath") &&
				!FunctionName.contains("K2_GetActorRotation") &&
				!FunctionName.contains("K2_DestroyActor") &&
				!FunctionName.contains("OnDetachFromBuilding") &&
				!FunctionName.contains("OnRep_bAlreadySearched") &&
				!FunctionName.contains("OnSetSearched") &&
				!FunctionName.contains("GetAircraft") &&
				!FunctionName.contains("BeginSpawningActorFromClass") &&
				!FunctionName.contains("BlueprintInitializeAnimation") &&
				!FunctionName.contains("BlueprintUpdateAnimation") &&
				!FunctionName.contains("BlueprintPostEvaluateAnimation") &&
				!FunctionName.contains("FinishSpawningActor") &&
				!FunctionName.contains("PawnUniqueIDSet") &&
				!FunctionName.contains("OnRep_Owner") &&
				!FunctionName.contains("OnRep_Pawn") &&
				!FunctionName.contains("Possess") &&
				!FunctionName.contains("ReceivePossessed") &&
				!FunctionName.contains("ClientRestart") &&
				!FunctionName.contains("SetControlRotation") &&
				!FunctionName.contains("ClientRetryClientRestart") &&
				!FunctionName.contains("ExecuteUbergraph_PlayerPawn_Athena_Generic") &&
				!FunctionName.contains("ExecuteUbergraph_PlayerPawn_Athena") &&
				!FunctionName.contains("ServerAcknowledgePossession") &&
				!FunctionName.contains("IsInAircraft") &&
				!FunctionName.contains("FindPlayerStart") &&
				!FunctionName.contains("SpawnDefaultPawnFor") &&
				!FunctionName.contains("MustSpectate") &&
				!FunctionName.contains("GetDefaultPawnClassForController") &&
				!FunctionName.contains("On Game Phase Change") &&
				!FunctionName.contains("ClientAdjustPosition") &&
				!FunctionName.contains("Movement Audio Crossfader__UpdateFunc") &&
				!FunctionName.contains("Holding Audio Crossfader__UpdateFunc") &&
				!FunctionName.contains("OnUpdateDirectionalLightForTimeOfDay") &&
				!FunctionName.contains("OnMontageEnded") &&
				!FunctionName.contains("ServerCancelAbility") &&
				!FunctionName.contains("K2_ActivateAbility") &&
				!FunctionName.contains("ServerHandleMissionEvent_ToggledCursorMode") &&
				!FunctionName.contains("OnBlendOut_") &&
				!FunctionName.contains("ClientEndAbility") &&
				!FunctionName.contains("OnSafeZoneStateChange") &&
				!FunctionName.contains("ClientVeryShortAdjustPosition") &&
				!FunctionName.contains("OnDayPhaseChange") &&
				!FunctionName.contains("On Day Phase Change") &&
				!FunctionName.contains("K2_OnStartCrouch") &&
				!FunctionName.contains("K2_OnEndCrouch") &&
				!FunctionName.contains("On Player Won") &&
				!FunctionName.contains("ClientFinishedInteractionInZone") &&
				!FunctionName.contains("ClientReceiveKillNotification") &&
				!FunctionName.contains("ReceiveCopyProperties") &&
				!FunctionName.contains("K2_OnLogout") &&
				!FunctionName.contains("ClientReceiveLocalizedMessage") &&
				!FunctionName.contains("ClientCancelAbility") &&
				!FunctionName.contains("ServerFinishedInteractionInZoneReport") &&
				!FunctionName.contains("FallingTimeline__UpdateFunc") &&
				!FunctionName.contains("BndEvt__InterceptCollision_K2Node_ComponentBoundEvent_5_ComponentBeginOverlapSignature__DelegateSignature") &&
				!FunctionName.contains("ReceiveActorBeginOverlap") &&
				!FunctionName.contains("Conv_StringToName") &&
				!FunctionName.contains("OnRep_GamePhase") &&
				!FunctionName.contains("K2_OnSetMatchState") &&
				!FunctionName.contains("StartPlay") &&
				!FunctionName.contains("StartMatch") &&
				!FunctionName.contains("OnAircraftEnteredDropZone") &&
				!FunctionName.contains("ServerShortTimeout") &&
				!FunctionName.contains("UpdateStateWidgetContent") &&
				!FunctionName.contains("PreConstruct") &&
				!FunctionName.contains("Construct") &&
				!FunctionName.contains("OnCurrentTextStyleChanged") &&
				!FunctionName.contains("UpdateButtonState") &&
				!FunctionName.contains("OnBangStateChanged") &&
				!FunctionName.contains("OnPlayerInfoChanged") &&
				!FunctionName.contains("Update") &&
				!FunctionName.contains("OnBeginIntro") &&
				!FunctionName.contains("HandleQuickBarChangedBP") &&
				!FunctionName.contains("HandleInventoryUpdatedEvent") &&
				!FunctionName.contains("OnActivated") &&
				!FunctionName.contains("OnBeginOutro") &&
				!FunctionName.contains("HandleActiveWidgetDeactivated") &&
				!FunctionName.contains("OnDeactivated") &&
				!FunctionName.contains("OnStateStarted") &&
				!FunctionName.contains("SetRenderTransform") &&
				!FunctionName.contains("OnAnimationFinished") &&
				!FunctionName.contains("ReadyToStartMatch") &&
				!FunctionName.contains("SetWidthOverride") &&
				!FunctionName.contains("SetHeightOverride") &&
				!FunctionName.contains("HandleMinimizeFinished") &&
				!FunctionName.contains("ServerUpdateLevelVisibility") &&
				!FunctionName.contains("OnDayPhaseChanged") &&
				!FunctionName.contains("ServerLoadingScreenDropped") &&
				!FunctionName.contains("On Game Phase Step Changed") &&
				!FunctionName.contains("HandleGamePhaseStepChanged") &&
				!FunctionName.contains("GamePhaseStepChanged") &&
				!FunctionName.contains("SetColorAndOpacity") &&
				!FunctionName.contains("OnAnimationStarted") &&
				!FunctionName.contains("UpdateMessaging") &&
				!FunctionName.contains("ServerSendLoadoutConfig") &&
				!FunctionName.contains("CalculateBaseMagnitude") &&
				!FunctionName.contains("ClientRegisterWithParty") &&
				!FunctionName.contains("InitializeHUDForPlayer") &&
				!FunctionName.contains("ClientSetHUD") &&
				!FunctionName.contains("ClientEnableNetworkVoice") &&
				!FunctionName.contains("ClientUpdateMultipleLevelsStreamingStatus") &&
				!FunctionName.contains("ClientFlushLevelStreaming") &&
				!FunctionName.contains("ClientOnGenericPlayerInitialization") &&
				!FunctionName.contains("ClientCapBandwidth") &&
				!FunctionName.contains("K2_PostLogin") &&
				!FunctionName.contains("OnRep_bHasStartedPlaying") &&
				!FunctionName.contains("ServerChoosePart") &&
				!FunctionName.contains("SetOwner") &&
				!FunctionName.contains("OnRep_QuickBar") &&
				!FunctionName.contains("HandleStartingNewPlayer") &&
				!FunctionName.contains("ServerUpdateMultipleLevelsVisibility") &&
				!FunctionName.contains("ServerSetPartyOwner") &&
				!FunctionName.contains("PlayerCanRestart") &&
				!FunctionName.contains("ServerCreateCombatManager") &&
				!FunctionName.contains("ServerCreateAIDirectorDataManager") &&
				!FunctionName.contains("EnableSlot") &&
				!FunctionName.contains("DisableSlot") &&
				!FunctionName.contains("ServerSetShowHeroBackpack") &&
				!FunctionName.contains("ServerSetShowHeroHeadAccessories") &&
				!FunctionName.contains("ServerSetClientHasFinishedLoading") &&
				!FunctionName.contains("ServerReadyToStartMatch") &&
				!FunctionName.contains("Received_Notify") &&
				!FunctionName.contains("Received_NotifyBegin") &&
				!FunctionName.contains("AnimNotify_LeftFootStep") &&
				!FunctionName.contains("AnimNotify_RightFootStep") &&
				!FunctionName.contains("Completed_") &&
				!FunctionName.contains("InputActionHoldStopped") &&
				!FunctionName.contains("ServerCurrentMontageSetPlayRate") &&
				!FunctionName.contains("ServerSetReplicatedTargetData") &&
				!FunctionName.contains("Triggered_") &&
				!FunctionName.contains("ActorHasTag") &&
				!FunctionName.contains("RandomIntegerInRange") &&
				!FunctionName.contains("GetItemDefinitionBP") &&
				!FunctionName.contains("CreateTemporaryItemInstanceBP") &&
				!FunctionName.contains("SetOwningControllerForTemporaryItem") &&
				!FunctionName.contains("OnRep_PrimaryQuickBar") &&
				!FunctionName.contains("OnRep_SecondaryQuickBar") &&
				!FunctionName.contains("ServerSetupWeakSpotsOnBuildingActor") &&
				!FunctionName.contains("OnStartDirectionEffect") &&
				!FunctionName.contains("SetReplicates") &&
				!FunctionName.contains("ServerCurrentMontageSetNextSectionName") &&
				!FunctionName.contains("NetFadeOut") &&
				!FunctionName.contains("OnFadeOut") &&
				!FunctionName.contains("NetOnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("GameplayCue") &&
				!FunctionName.contains("ReceiveActorEndOverlap") &&
				!FunctionName.contains("PhysicsVolumeChanged") &&
				!FunctionName.contains("ServerAddItemInternal") &&
				!FunctionName.contains("FortClientPlaySound") &&
				!FunctionName.contains("OnCapsuleBeginOverlap") &&
				!FunctionName.contains("GetPlayerController") &&
				!FunctionName.contains("TossPickup") &&
				!FunctionName.contains("OnRep_PrimaryPickupItemEntry") &&
				!FunctionName.contains("ServerActivateSlotInternal") &&
				!FunctionName.contains("EquipWeaponDefinition") &&
				!FunctionName.contains("OnInitAlteration") &&
				!FunctionName.contains("OnInitCosmeticAlterations") &&
				!FunctionName.contains("K2_OnUnEquip") &&
				!FunctionName.contains("GetItemGuid") &&
				!FunctionName.contains("InternalServerSetTargeting") &&
				!FunctionName.contains("ServerReleaseInventoryItemKey") &&
				!FunctionName.contains("OnPawnMontageBlendingOut") &&
				!FunctionName.contains("OnSetTargeting") &&
				!FunctionName.contains("OnRep_DefaultMetadata") &&
				!FunctionName.contains("GetDataTableRowNames") &&
				!FunctionName.contains("GetMaxDurability") &&
				!FunctionName.contains("BeginDeferredActorSpawnFromClass") &&
				!FunctionName.contains("OnRep_PickupLocationData") &&
				!FunctionName.contains("GetControlRotation") &&
				!FunctionName.contains("OnVisibilitySetEvent") &&
				!FunctionName.contains("ShouldShowSoundIndicator") &&
				!FunctionName.contains("WaitForPawn") &&
				!FunctionName.contains("OnProjectileStopDelegate") &&
				!FunctionName.contains("Handle Parachute Audio State") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("EvaluateGraphExposedInputs_ExecuteUbergraph_Fortnite_M_Avg_Player_AnimBlueprint_AnimGraphNode_"))
			{
				FN_LOG(Logs, Log, "FunctionName: [%s]", FunctionName.c_str());
			}
		}

		ProcessEventOG(Object, Function, Parms);
	}

	void InitHook()
	{
		uintptr_t AddressInternalGetNetMode = MinHook::FindPattern(Patterns::InternalGetNetMode);
		uintptr_t AddressActorInternalGetNetMode = MinHook::FindPattern(Patterns::ActorInternalGetNetMode);
		uintptr_t AddressLocalSpawnPlayActor = MinHook::FindPattern(Patterns::LocalSpawnPlayActor);

		MH_CreateHook((LPVOID)(AddressInternalGetNetMode), ReturnNetMode, nullptr);
		MH_EnableHook((LPVOID)(AddressInternalGetNetMode));
		MH_CreateHook((LPVOID)(AddressActorInternalGetNetMode), ReturnNetMode, nullptr);
		MH_EnableHook((LPVOID)(AddressActorInternalGetNetMode));
		MH_CreateHook((LPVOID)(AddressLocalSpawnPlayActor), LocalSpawnPlayActor, nullptr);
		MH_EnableHook((LPVOID)(AddressLocalSpawnPlayActor));

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + Offsets::ProcessEvent), ProcessEvent, (LPVOID*)(&ProcessEventOG));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + Offsets::ProcessEvent));

		FN_LOG(LogInit, Log, "InitHook Success!");
	}
}