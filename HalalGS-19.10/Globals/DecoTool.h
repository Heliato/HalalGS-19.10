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

		UFortTrapItemDefinition* TrapItemDefinition = Cast<UFortTrapItemDefinition>(DecoTool->ItemDefinition);
		AFortPlayerPawn* PlayerPawn = Cast<AFortPlayerPawn>(DecoTool->Owner);

		if (!TrapItemDefinition || !PlayerPawn) 
			return;

		AFortPlayerControllerAthena* PlayerControllerAthena = Cast<AFortPlayerControllerAthena>(PlayerPawn->Controller);
		AFortPlayerStateAthena* PlayerStateAthena = Cast<AFortPlayerStateAthena>(PlayerPawn->PlayerState);
		TSubclassOf<ABuildingActor> BlueprintClass = TrapItemDefinition->GetBlueprintClass();

		if (!PlayerControllerAthena || !PlayerStateAthena || !BlueprintClass.Get())
			return;

		UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerControllerAthena->BP_FindExistingItemForDefinition(TrapItemDefinition, FGuid(), false));

		if (!WorldItem)
			return;

		ABuildingTrap* (*SpawnDeco)(AFortDecoTool* DecoTool, UClass* Class, const FVector& Location, const FRotator& Rotation, ABuildingSMActor* AttachedActor, int a6, EBuildingAttachmentType InBuildingAttachmentType) = decltype(SpawnDeco)(0x69abec4 + uintptr_t(GetModuleHandle(0)));
		ABuildingTrap* BuildingTrap = SpawnDeco(DecoTool, BlueprintClass, Location, Rotation, AttachedActor, 0, InBuildingAttachmentType);
		
		if (BuildingTrap)
		{
			BuildingTrap->InitializeKismetSpawnedBuildingActor(BuildingTrap, PlayerControllerAthena, true, nullptr);

			BuildingTrap->SetTeam(PlayerStateAthena->TeamIndex);
			BuildingTrap->OnRep_Team();

			Abilities::GrantGameplayAbility(BuildingTrap->AbilitySet, PlayerStateAthena->AbilitySystemComponent);

			PlayerControllerAthena->ServerRemoveInventoryItem(WorldItem->ItemEntry.ItemGuid, 1, false, true, false);
		}

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