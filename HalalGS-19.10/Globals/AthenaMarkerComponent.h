#pragma once

namespace AthenaMarkerComponent
{
	void ServerAddMapMarker(UAthenaMarkerComponent* MarkerComponent, const FFortClientMarkerRequest& MarkerRequest)
	{
		AFortPlayerControllerAthena* PlayerControllerAthena = Cast<AFortPlayerControllerAthena>(MarkerComponent->GetOwner());
		if (!PlayerControllerAthena) return;

		AFortPlayerStateAthena* PlayerStateAthena = Cast<AFortPlayerStateAthena>(PlayerControllerAthena->PlayerState);
		if (!PlayerStateAthena) return;

		FFortWorldMarkerData WorldMarkerData;
		WorldMarkerData.CreateWorldMarkerData();

		WorldMarkerData.Owner = PlayerStateAthena;

		WorldMarkerData.MarkerType = MarkerRequest.MarkerType;
		WorldMarkerData.BasePosition = MarkerRequest.BasePosition;
		WorldMarkerData.BasePositionOffset = MarkerRequest.BasePositionOffset;
		WorldMarkerData.WorldNormal = MarkerRequest.WorldNormal;
		WorldMarkerData.bIncludeSquad = MarkerRequest.bIncludeSquad;
		WorldMarkerData.bUseHoveredMarkerDetail = MarkerRequest.bUseHoveredMarkerDetail;

		FMarkerID MarkerID{};
		MarkerID.PlayerId = PlayerStateAthena->PlayerId;
		MarkerID.InstanceID = MarkerRequest.InstanceID;

		WorldMarkerData.MarkerID = MarkerID;

		if (MarkerRequest.MarkedActor)
		{
			TSoftClassPtr<UClass> MarkedActorClass{};
			MarkedActorClass.WeakPtr.ObjectIndex = MarkerRequest.MarkedActor->Class->Index;
			MarkedActorClass.WeakPtr.ObjectSerialNumber = 0;

			WorldMarkerData.MarkedActorClass = MarkedActorClass;
			WorldMarkerData.MarkedActor = MarkerRequest.MarkedActor;

			char (*sub_7FF69C6136E0)(UAthenaMarkerComponent* MarkerComponent, AActor* ActorToBeMarked, FFortWorldMarkerData* WorldMarkerData) = decltype(sub_7FF69C6136E0)(0x60436e0 + uintptr_t(GetModuleHandle(0)));
			sub_7FF69C6136E0(MarkerComponent, MarkerRequest.MarkedActor, &WorldMarkerData);
		}

		if (WorldMarkerData.MarkerType == EFortWorldMarkerType::Item)
		{
			AFortPickup* Pickup = Cast<AFortPickup>(MarkerRequest.MarkedActor);

			if (Pickup)
			{
				WorldMarkerData.ItemDefinition = Pickup->PrimaryPickupItemEntry.ItemDefinition;
				WorldMarkerData.ItemCount = Pickup->PrimaryPickupItemEntry.Count;
			}
		}

		for (int32 i = 0; i < PlayerStateAthena->PlayerTeam->TeamMembers.Num(); i++)
		{
			AFortPlayerControllerAthena* TeamMember = Cast<AFortPlayerControllerAthena>(PlayerStateAthena->PlayerTeam->TeamMembers[i]);
			if (!TeamMember) continue;

			if (TeamMember == PlayerControllerAthena)
				continue;

			UAthenaMarkerComponent* TeamMemberMarkerComponent = TeamMember->MarkerComponent;
			if (!TeamMemberMarkerComponent) continue;

			FFortWorldMarkerContainer* TeamMemberMarkerStream = &TeamMemberMarkerComponent->MarkerStream;
			if (!TeamMemberMarkerStream) continue;

			bool bFoundMarker = false;
			for (int32 j = 0; j < TeamMemberMarkerStream->Markers.Num(); j++)
			{
				FFortWorldMarkerData* TeamMemberWorldMarkerData = &TeamMemberMarkerStream->Markers[j];
				if (!TeamMemberWorldMarkerData) continue;

				if (TeamMemberWorldMarkerData->Owner == PlayerStateAthena)
				{
					TeamMemberWorldMarkerData->CopyWorldMarkerData(&WorldMarkerData);
					TeamMemberMarkerStream->MarkItemDirty(TeamMemberMarkerStream->Markers[j]);
					bFoundMarker = true;
					break;
				}
			}

			if (!bFoundMarker)
			{
				TeamMemberMarkerStream->Markers.Add(WorldMarkerData);
				TeamMemberMarkerStream->MarkArrayDirty();
			}
		}

		FN_LOG(LogInit, Log, "UAthenaMarkerComponent::ServerAddMapMarker called!");
	}

    void ServerRemoveMapMarker(UAthenaMarkerComponent* MarkerComponent, const FMarkerID& MarkerID, ECancelMarkerReason CancelReason)
    {
        FN_LOG(LogInit, Log, "ServerRemoveMapMarker completed successfully.");
    }


	void InitAthenaMarkerComponent()
	{
		UAthenaMarkerComponent* AthenaMarkerComponentDefault = UAthenaMarkerComponent::GetDefaultObj();
		UClass* AthenaMarkerComponentClass = UAthenaMarkerComponent::StaticClass();

		/*MinHook::HookVTable(AthenaMarkerComponentDefault, 0x460 / 8, ServerAddMapMarker, nullptr, "UAthenaMarkerComponent::ServerAddMapMarker");
		MinHook::HookVTable(AthenaMarkerComponentDefault, 0x458 / 8, ServerRemoveMapMarker, nullptr, "UAthenaMarkerComponent::ServerRemoveMapMarker");*/

		FN_LOG(LogInit, Log, "InitAthenaMarkerComponent Success!");
	}
}