#pragma once

namespace DecoTool
{
	void ServerCreateBuildingAndSpawnDeco(AFortDecoTool* DecoTool, FFrame& Stack, void* Ret)
	{
		FVector_NetQuantize10 BuildingLocation;
		FRotator BuildingRotation;
		FVector_NetQuantize10 Location;
		FRotator Rotation;
		EBuildingAttachmentType InBuildingAttachmentType;
		bool bSpawnDecoOnExtraPiece;
		FVector BuildingExtraPieceLocation;

		Stack.StepCompiledIn(&BuildingLocation);
		Stack.StepCompiledIn(&BuildingRotation);
		Stack.StepCompiledIn(&Location);
		Stack.StepCompiledIn(&Rotation);
		Stack.StepCompiledIn(&InBuildingAttachmentType);
		Stack.StepCompiledIn(&bSpawnDecoOnExtraPiece);
		Stack.StepCompiledIn(&BuildingExtraPieceLocation);

		Stack.Code += Stack.Code != nullptr;

		FN_LOG(LogInit, Log, "ServerCreateBuildingAndSpawnDeco called - DecoTool: %s", DecoTool->GetFullName().c_str());
	}

	void FinalServerSpawnDeco(AFortDecoTool* DecoTool, const FVector& Location, const FRotator& Rotation, ABuildingSMActor* AttachedActor, EBuildingAttachmentType InBuildingAttachmentType)
	{
		AFortPlayerController* (*GetPlayerControllerFromInstigator)(AFortDecoTool* DecoTool) = decltype(GetPlayerControllerFromInstigator)(0x1c16140 + uintptr_t(GetModuleHandle(0)));
		AFortPlayerController* PlayerController = GetPlayerControllerFromInstigator(DecoTool);

		UFortDecoItemDefinition* DecoItemDefinition = Cast<UFortDecoItemDefinition>(DecoTool->ItemDefinition);
		UClass* BlueprintClass = nullptr;

		if (DecoItemDefinition)
			BlueprintClass = DecoItemDefinition->GetBlueprintClass().Get();

		if (PlayerController && DecoItemDefinition && BlueprintClass)
		{
			AFortPlayerPawn* PlayerPawn = Cast<AFortPlayerPawn>(DecoTool->Instigator);

			EFortDecoPlacementQueryResults (*CanPlaceDecoInStructuralGrid)(UFortDecoItemDefinition* DecoItemDefinition, ABuildingSMActor* AttachedActor, AFortPlayerPawn* PlayerPawn, AFortDecoTool* DecoTool, const FVector& Location, const FRotator& Rotation, FText a7) = decltype(CanPlaceDecoInStructuralGrid)(0x699313c + uintptr_t(GetModuleHandle(0)));

			FText* (*FTextConstruct)(FText* Text) = decltype(FTextConstruct)(0xc8d36c + uintptr_t(GetModuleHandle(0)));

			FText Text;
			FTextConstruct(&Text);

			EFortDecoPlacementQueryResults DecoPlacementQueryResults = CanPlaceDecoInStructuralGrid(
				DecoItemDefinition,
				AttachedActor,
				PlayerPawn,
				DecoTool,
				Location,
				Rotation,
				Text);

			if (DecoPlacementQueryResults == EFortDecoPlacementQueryResults::CanAdd)
			{
				bool (*ShouldAllowServerSpawnDeco)(AFortDecoTool* DecoTool, const FVector& Location, const FRotator & Rotation, ABuildingSMActor * AttachedActor, EBuildingAttachmentType InBuildingAttachmentType) = decltype(ShouldAllowServerSpawnDeco)(0x69ab17c + uintptr_t(GetModuleHandle(0)));

				if (ShouldAllowServerSpawnDeco(DecoTool, Location, Rotation, AttachedActor, InBuildingAttachmentType))
				{
					ABuildingTrap* (*SpawnDeco)(AFortDecoTool* DecoTool, UClass* Class, const FVector& Location, const FRotator& Rotation, ABuildingSMActor* AttachedActor, int a6, EBuildingAttachmentType InBuildingAttachmentType) = decltype(SpawnDeco)(0x69abec4 + uintptr_t(GetModuleHandle(0)));
					ABuildingTrap* BuildingTrap = SpawnDeco(DecoTool, BlueprintClass, Location, Rotation, AttachedActor, 0, InBuildingAttachmentType);

					if (BuildingTrap)
					{
						AFortPlayerStateAthena* PlayerStateAthena = Cast<AFortPlayerStateAthena>(PlayerPawn->PlayerState);

						if (PlayerStateAthena)
						{
							BuildingTrap->SetTeam(PlayerStateAthena->TeamIndex);
							BuildingTrap->OnRep_Team();
						}

						void (*ConsumePlacedDeco)(AFortDecoTool* DecoTool) = decltype(ConsumePlacedDeco)(0x6998960 + uintptr_t(GetModuleHandle(0)));
						ConsumePlacedDeco(DecoTool);
					}
				}
			}
		}
	}

	void ServerSpawnDeco(AFortDecoTool* DecoTool, FFrame& Stack, void* Ret)
	{
		FVector Location;
		FRotator Rotation;
		ABuildingSMActor* AttachedActor;
		EBuildingAttachmentType InBuildingAttachmentType;

		Stack.StepCompiledIn(&Location);
		Stack.StepCompiledIn(&Rotation);
		Stack.StepCompiledIn(&AttachedActor);
		Stack.StepCompiledIn(&InBuildingAttachmentType);

		Stack.Code += Stack.Code != nullptr;

		AFortDecoTool_ContextTrap* DecoTool_ContextTrap = Cast<AFortDecoTool_ContextTrap>(DecoTool);

		if (DecoTool_ContextTrap)
		{
			FText* (*FTextConstruct)(FText* Text) = decltype(FTextConstruct)(0xc8d36c + uintptr_t(GetModuleHandle(0)));

			FText Text;
			FTextConstruct(&Text);

			EFortDecoPlacementQueryResults (*CanPlaceDecoInStructuralGrid)(UFortDecoItemDefinition * DecoItemDefinition, ABuildingSMActor * AttachedActor, AFortPlayerPawn * PlayerPawn, AFortDecoTool * DecoTool, const FVector & Location, const FRotator & Rotation, FText a7) = decltype(CanPlaceDecoInStructuralGrid)(0x699313c + uintptr_t(GetModuleHandle(0)));
			UFortDecoItemDefinition* DecoItemDefinition = nullptr;

			UFortContextTrapItemDefinition* ContextTrapItemDefinition = DecoTool_ContextTrap->ContextTrapItemDefinition;

			if (ContextTrapItemDefinition)
			{
				if (InBuildingAttachmentType == EBuildingAttachmentType::ATTACH_WallThenFloor || InBuildingAttachmentType == EBuildingAttachmentType::ATTACH_Wall) // 5 || 1
				{
					UFortTrapItemDefinition* TrapItemDefinition = ContextTrapItemDefinition->FloorTrap;

					if (!TrapItemDefinition || InBuildingAttachmentType == EBuildingAttachmentType::ATTACH_Wall)
						TrapItemDefinition = ContextTrapItemDefinition->WallTrap;

					AFortPlayerPawn* PlayerPawn = Cast<AFortPlayerPawn>(DecoTool_ContextTrap->Instigator);

					EFortDecoPlacementQueryResults DecoPlacementQueryResults = CanPlaceDecoInStructuralGrid(
						TrapItemDefinition,
						AttachedActor,
						PlayerPawn,
						DecoTool_ContextTrap,
						Location,
						Rotation,
						Text);

					if (DecoPlacementQueryResults == EFortDecoPlacementQueryResults::CanAdd)
						DecoItemDefinition = TrapItemDefinition;
				}
				else if (InBuildingAttachmentType == EBuildingAttachmentType::ATTACH_FloorAndStairs || InBuildingAttachmentType == EBuildingAttachmentType::ATTACH_Floor) // 6 || 0
				{
					UFortTrapItemDefinition* TrapItemDefinition = ContextTrapItemDefinition->StairTrap;

					if (!TrapItemDefinition || InBuildingAttachmentType == EBuildingAttachmentType::ATTACH_Floor)
						TrapItemDefinition = ContextTrapItemDefinition->FloorTrap;

					AFortPlayerPawn* PlayerPawn = Cast<AFortPlayerPawn>(DecoTool_ContextTrap->Instigator);

					EFortDecoPlacementQueryResults DecoPlacementQueryResults = CanPlaceDecoInStructuralGrid(
						TrapItemDefinition,
						AttachedActor,
						PlayerPawn,
						DecoTool_ContextTrap,
						Location,
						Rotation,
						Text);

					if (DecoPlacementQueryResults == EFortDecoPlacementQueryResults::CanAdd)
						DecoItemDefinition = TrapItemDefinition;
				}
				else if (InBuildingAttachmentType == EBuildingAttachmentType::ATTACH_CeilingAndStairs || InBuildingAttachmentType == EBuildingAttachmentType::ATTACH_Ceiling) // 7 || 2
				{
					UFortTrapItemDefinition* TrapItemDefinition = ContextTrapItemDefinition->StairTrap;

					if (!TrapItemDefinition || InBuildingAttachmentType == EBuildingAttachmentType::ATTACH_Ceiling)
						TrapItemDefinition = ContextTrapItemDefinition->CeilingTrap;

					AFortPlayerPawn* PlayerPawn = Cast<AFortPlayerPawn>(DecoTool_ContextTrap->Instigator);

					EFortDecoPlacementQueryResults DecoPlacementQueryResults = CanPlaceDecoInStructuralGrid(
						TrapItemDefinition,
						AttachedActor,
						PlayerPawn,
						DecoTool_ContextTrap,
						Location,
						Rotation,
						Text);

					if (DecoPlacementQueryResults == EFortDecoPlacementQueryResults::CanAdd)
						DecoItemDefinition = TrapItemDefinition;
				}
			}

			if (DecoItemDefinition)
			{
				DecoTool_ContextTrap->ItemDefinition = DecoItemDefinition;
				DecoTool_ContextTrap->OnRep_ItemDefinition();
			}
		}

		FinalServerSpawnDeco(DecoTool, Location, Rotation, AttachedActor, InBuildingAttachmentType);

		FN_LOG(LogInit, Log, "ServerSpawnDeco called - DecoTool: %s", DecoTool->GetFullName().c_str());
	}

	void InitDecoTool()
	{
		AFortDecoTool* FortDecoToolDefault = AFortDecoTool::GetDefaultObj();
		UClass* FortDecoToolClass = AFortDecoTool::StaticClass();

		UFunction* ServerCreateBuildingAndSpawnDecoFunc = FortDecoToolClass->GetFunction("FortDecoTool", "ServerCreateBuildingAndSpawnDeco");
		MinHook::HookFunctionExec(ServerCreateBuildingAndSpawnDecoFunc, ServerCreateBuildingAndSpawnDeco, nullptr);

		UFunction* ServerSpawnDecoFunc = FortDecoToolClass->GetFunction("FortDecoTool", "ServerSpawnDeco");
		MinHook::HookFunctionExec(ServerSpawnDecoFunc, ServerSpawnDeco, nullptr);

		/*MinHook::HookVTable(FortDecoToolDefault, 0xB88 / 8, ServerCreateBuildingAndSpawnDeco, nullptr, "AFortDecoTool::ServerCreateBuildingAndSpawnDeco");
		MinHook::HookVTable(FortDecoToolDefault, 0xB98 / 8, ServerSpawnDeco, nullptr, "AFortDecoTool::ServerSpawnDeco");*/

		FN_LOG(LogInit, Log, "InitDecoTool Success!");
	}
}