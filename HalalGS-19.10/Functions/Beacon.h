#pragma once

namespace Beacon
{
	void (*TickFlushOG)(UNetDriver* NetDriver, float DeltaSeconds);

	void TickFlush(UNetDriver* NetDriver, float DeltaSeconds)
	{
		if (NetDriver)
		{
			if (NetDriver->IsA(UIpNetDriver::StaticClass()) &&
				NetDriver->ClientConnections.Num() > 0 &&
				!NetDriver->ClientConnections[0]->InternalAck)
			{
				UReplicationGraph* ReplicationDriver = Cast<UReplicationGraph>(NetDriver->ReplicationDriver);

				if (ReplicationDriver)
				{
					ReplicationDriver->ServerReplicateActors(DeltaSeconds);
				}
			}
		}

		TickFlushOG(NetDriver, DeltaSeconds);
	}

	bool ListenServer(UWorld* World, FURL& InURL)
	{
		if (!World)
			return false;

		AOnlineBeaconHost* OnlineBeaconHost = Cast<AOnlineBeaconHost>(World->SpawnActor(AOnlineBeaconHost::StaticClass()));

		if (!OnlineBeaconHost)
		{
			FN_LOG(LogBeacon, Error, "Failed to create OnlineBeaconHost!");
			return false;
		}

		OnlineBeaconHost->ListenPort = 7777;

		if (World->NetDriver)
		{
			FN_LOG(LogBeacon, Warning, "OnlineBeaconHost already created!");
			return false;
		}

		if (OnlineBeaconHost->InitHost())
		{
			World->NetDriver = OnlineBeaconHost->NetDriver;
			FN_LOG(LogBeacon, Log, "Beacon created successful!");
		}
		else
		{
			FN_LOG(LogBeacon, Error, "Failed to InitHost!");
			return false;
		}

		if (World->NetDriver)
		{
			World->NetDriver->World = World;
			World->NetDriver->NetDriverName = UKismetStringLibrary::Conv_StringToName(L"GameNetDriver");

			World->LevelCollections[0].NetDriver = World->NetDriver; // ELevelCollectionType::DynamicSourceLevels
			World->LevelCollections[1].NetDriver = World->NetDriver; // ELevelCollectionType::StaticLevels

			UIpNetDriver* IpNetDriver = Cast<UIpNetDriver>(World->NetDriver);
			if (!IpNetDriver) return false;

			FString Error;
			if (!IpNetDriver->InitListen(World, InURL, true, Error))
			{
				FN_LOG(LogBeacon, Debug, "Failed to listen: %s", Error.ToString().c_str());

				World->NetDriver->SetWorld(NULL);
				World->NetDriver = NULL;

				World->LevelCollections[0].NetDriver = nullptr; // ELevelCollectionType::DynamicSourceLevels
				World->LevelCollections[1].NetDriver = nullptr; // ELevelCollectionType::StaticLevels

				return false;
			}

			World->NetDriver->SetWorld(World);

			static bool bHookTickFlush = false;

			if (!bHookTickFlush)
			{
				uintptr_t PatternTickFlush = MinHook::FindPattern(Patterns::TickFlush);

				MH_CreateHook((LPVOID)(PatternTickFlush), TickFlush, (LPVOID*)(&TickFlushOG));
				MH_EnableHook((LPVOID)(PatternTickFlush));

				bHookTickFlush = true;
			}
		}
		else
		{
			FN_LOG(LogBeacon, Error, "Failed to listen!");
			return false;
		}

		FN_LOG(LogBeacon, Log, "Listen on port: %i", InURL.Port);
	}

	void InitBeacon()
	{
		FN_LOG(LogInit, Log, "InitBeacon Success!");
	}
}