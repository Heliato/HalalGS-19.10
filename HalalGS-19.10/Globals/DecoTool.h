#pragma once

namespace DecoTool
{
	void ServerCreateBuildingAndSpawnDeco(AFortDecoTool* DecoTool, const FVector_NetQuantize10& BuildingLocation, const FRotator& BuildingRotation, const FVector_NetQuantize10& Location, const FRotator& Rotation, EBuildingAttachmentType InBuildingAttachmentType, bool bSpawnDecoOnExtraPiece, const FVector& BuildingExtraPieceLocation)
	{
		FN_LOG(LogInit, Log, "ServerCreateBuildingAndSpawnDeco called!");
	}

	void ServerSpawnDeco(AFortDecoTool* DecoTool, const FVector& Location, const FRotator& Rotation, ABuildingSMActor* AttachedActor, EBuildingAttachmentType InBuildingAttachmentType)
	{
		FN_LOG(LogInit, Log, "ServerSpawnDeco called!");
	}

	void InitDecoTool()
	{
		AFortAbilityDecoTool* FortAbilityDecoTool = AFortAbilityDecoTool::GetDefaultObj();

		MinHook::HookVTable(FortAbilityDecoTool, 0xB88 / 8, ServerCreateBuildingAndSpawnDeco, nullptr, "AFortDecoTool::ServerCreateBuildingAndSpawnDeco");
		MinHook::HookVTable(FortAbilityDecoTool, 0xB98 / 8, ServerSpawnDeco, nullptr, "AFortDecoTool::ServerSpawnDeco");

		FN_LOG(LogInit, Log, "InitDecoTool Success!");
	}
}