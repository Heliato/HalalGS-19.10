#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ArgonRuntime

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "FortniteGame_structs.hpp"
#include "FortniteGame_classes.hpp"
#include "ArgonRuntime_structs.hpp"
#include "GameplayTags_structs.hpp"
#include "SlateCore_structs.hpp"
#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "GameplayAbilities_structs.hpp"


namespace SDK
{

// Class ArgonRuntime.ArgonPlayerComponent
// 0x0018 (0x00C8 - 0x00B0)
class UArgonPlayerComponent final : public UFortControllerComponent
{
public:
	float                                         EntireSquadDiedServerTimeForRespawn;               // 0x00B0(0x0004)(Net, ZeroConstructor, IsPlainOldData, RepNotify, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bRotatePawnToCamera;                               // 0x00B4(0x0001)(Net, ZeroConstructor, IsPlainOldData, RepNotify, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	uint8                                         Pad_B5[0x3];                                       // 0x00B5(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UFortMontageItemDefinitionBase*         CachedFinishedRaceEmote;                           // 0x00B8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	class AFortAthenaMutator_Argon*               ArgonMutator;                                      // 0x00C0(0x0008)(Net, ZeroConstructor, IsPlainOldData, RepNotify, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)

public:
	void OnRacePhaseChanged(EArgonRacePhase NewRacePhase);
	void OnRep_ArgonMutator();
	void OnRep_EntireSquadDiedServerTimeForRespawn();
	void OnRep_RotatePawnToCamera();
	void PlayFinishedRaceEmote();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"ArgonPlayerComponent">();
	}
	static class UArgonPlayerComponent* GetDefaultObj()
	{
		return GetDefaultObjImpl<UArgonPlayerComponent>();
	}
};

// Class ArgonRuntime.FortCheatManager_Argon
// 0x0000 (0x0038 - 0x0038)
class UFortCheatManager_Argon final : public UFortCheatManager_Coupled
{
public:
	void ArgonTeleportToEndPoint();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"FortCheatManager_Argon">();
	}
	static class UFortCheatManager_Argon* GetDefaultObj()
	{
		return GetDefaultObjImpl<UFortCheatManager_Argon>();
	}
};

// Class ArgonRuntime.ArgonStartingPlatform
// 0x0028 (0x0248 - 0x0220)
class AArgonStartingPlatform final : public AActor
{
public:
	struct FGameplayTagContainer                  GameplayTags;                                      // 0x0220(0x0020)(Edit, Protected, NativeAccessSpecifierProtected)
	bool                                          bIsEnabled;                                        // 0x0240(0x0001)(Edit, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, RepNotify, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	uint8                                         Pad_241[0x7];                                      // 0x0241(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	void OnRep_IsEnabled();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"ArgonStartingPlatform">();
	}
	static class AArgonStartingPlatform* GetDefaultObj()
	{
		return GetDefaultObjImpl<AArgonStartingPlatform>();
	}
};

// Class ArgonRuntime.ArgonTicketComponent
// 0x0020 (0x00D0 - 0x00B0)
class UArgonTicketComponent final : public UActorComponent
{
public:
	class AFortAthenaMutator_Argon*               ArgonMutator;                                      // 0x00B0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	FMulticastInlineDelegateProperty_             OnIsNearToPlayerChanged;                           // 0x00B8(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic)
	uint8                                         Pad_C8[0x8];                                       // 0x00C8(0x0008)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	class AFortAthenaMutator_Argon* GetArgonMutator() const;
	bool IsNearToPlayer() const;

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"ArgonTicketComponent">();
	}
	static class UArgonTicketComponent* GetDefaultObj()
	{
		return GetDefaultObjImpl<UArgonTicketComponent>();
	}
};

// Class ArgonRuntime.ArgonTraversePoint
// 0x0010 (0x0A80 - 0x0A70)
class AArgonTraversePoint final : public AAthenaLTMTraversePoint
{
public:
	class AFortPlayerMarkerBase*                  MarkerActor;                                       // 0x0A70(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	TSubclassOf<class AFortPlayerMarkerBase>      MarkerClass;                                       // 0x0A78(0x0008)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, Protected, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierProtected)

public:
	void ClientSpawnMarkerActor(const struct FTransform& Transform);
	void OnNewState_Active_Server_BP();
	void OnNewState_Hidden_Server_BP();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"ArgonTraversePoint">();
	}
	static class AArgonTraversePoint* GetDefaultObj()
	{
		return GetDefaultObjImpl<AArgonTraversePoint>();
	}
};

// Class ArgonRuntime.ArgonVehicleSpawner
// 0x0018 (0x0238 - 0x0220)
class AArgonVehicleSpawner final : public AActor
{
public:
	TArray<struct FPrimaryAssetId>                OverrideVehicleAssetIds;                           // 0x0220(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Protected, NativeAccessSpecifierProtected)
	ESpawnActorCollisionHandlingMethod            SpawnVehicleCollisionHandlingMethod;               // 0x0230(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	uint8                                         Pad_231[0x7];                                      // 0x0231(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"ArgonVehicleSpawner">();
	}
	static class AArgonVehicleSpawner* GetDefaultObj()
	{
		return GetDefaultObjImpl<AArgonVehicleSpawner>();
	}
};

// Class ArgonRuntime.FortAthenaMutator_Argon
// 0x1170 (0x1550 - 0x03E0)
class AFortAthenaMutator_Argon final : public AFortAthenaMutator_GameModeBase
{
public:
	uint8                                         Pad_3E0[0x8];                                      // 0x03E0(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FScalableFloat                         MinInitialVehicleFuelPercent;                      // 0x03E8(0x0028)(Edit, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FScalableFloat                         MaxInitialVehicleFuelPercent;                      // 0x0410(0x0028)(Edit, DisableEditOnInstance, NativeAccessSpecifierPublic)
	FMulticastInlineDelegateProperty_             OnArgonPlayerFinished;                             // 0x0438(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic)
	FMulticastInlineDelegateProperty_             OnArgonPlayerReachedEndWithoutEnoughTickets;       // 0x0448(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic)
	FMulticastInlineDelegateProperty_             OnArgonRacePhaseChanged;                           // 0x0458(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic)
	FMulticastInlineDelegateProperty_             OnArgonEndTraversePointSet;                        // 0x0468(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic)
	FMulticastInlineDelegateProperty_             OnTeamTicketCountChanged;                          // 0x0478(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic)
	uint8                                         Pad_488[0x18];                                     // 0x0488(0x0018)(Fixing Size After Last Property [ Dumper-7 ])
	FMulticastInlineDelegateProperty_             OnSupplyDropClusterSpawned;                        // 0x04A0(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic)
	uint8                                         Pad_4B0[0x20];                                     // 0x04B0(0x0020)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FArgonRoute>                    Routes;                                            // 0x04D0(0x0010)(Edit, ZeroConstructor, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FFortSquadStartSearchParamData         StartPOISquadStartSearchParam;                     // 0x04E0(0x00C0)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         bUseOverridingSpawnTransforms;                     // 0x05A0(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	TArray<struct FTransform>                     OverridingSpawnTransforms;                         // 0x05C8(0x0010)(Edit, ZeroConstructor, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	class FText                                   TeleportingPlayersText;                            // 0x05D8(0x0018)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         PreCountdownTextDuration;                          // 0x05F0(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	TArray<struct FArgonVehicleOption>            VehicleOptionsList;                                // 0x0618(0x0010)(Edit, ZeroConstructor, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         EndRaceAfterNumFinishers;                          // 0x0628(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FSlateBrush                            EndLocationCompassBrush;                           // 0x0650(0x00B0)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FSlateBrush                            EndLocationLockedCompassBrush;                     // 0x0700(0x00B0)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	float                                         EndLocationCompassBrush_YOffset;                   // 0x07B0(0x0004)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	float                                         EndLocationCompassBrush_MinScale;                  // 0x07B4(0x0004)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	float                                         EndLocationCompassBrush_MaxScale;                  // 0x07B8(0x0004)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	float                                         EndLocationCompassBrush_DistanceForMinScale;       // 0x07BC(0x0004)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	float                                         EndLocationCompassBrush_DistanceForMaxScale;       // 0x07C0(0x0004)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	uint8                                         Pad_7C4[0xC];                                      // 0x07C4(0x000C)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSlateBrush                            EndLocationMapBrush;                               // 0x07D0(0x00B0)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FSlateBrush                            EndLocationLockedMapBrush;                         // 0x0880(0x00B0)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FVector2D                              EndLocationMapBrushScale;                          // 0x0930(0x0008)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	struct FGameplayTag                           RacePositionStatGameplayTag;                       // 0x0938(0x0008)(Edit, DisableEditOnInstance, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	class UFortWorldItemDefinition*               TicketItemDefinition;                              // 0x0940(0x0008)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	struct FScalableFloat                         NumTicketsNeededToCompleteRace;                    // 0x0948(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	int32                                         NumEnemiesTrackedOnProgressBarUI;                  // 0x0970(0x0004)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	int32                                         NumSquadmatesTrackedOnProgressBarUI;               // 0x0974(0x0004)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	struct FScalableFloat                         EntireSquadDeadRespawnViewPitch;                   // 0x0978(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         EntireSquadDeadRespawnTime;                        // 0x09A0(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	TSubclassOf<class AActor>                     EntireSquadDeadRespawnActorClass;                  // 0x09C8(0x0008)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, Protected, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	struct FScalableFloat                         RespawnOffsetDistance;                             // 0x09D0(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         MinRespawnHeightAboveGround;                       // 0x09F8(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         bShouldRespawnInSafeZone;                          // 0x0A20(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         PercentDistanceInsideOfSafeZone;                   // 0x0A48(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FArgonSupplyDropPointData              SupplyDropPointData;                               // 0x0A70(0x0298)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         bAreDropsAlwaysTriggeredByFirstPlacePlayer;        // 0x0D08(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	class UCurveFloat*                            SupplyDropPercentCurve;                            // 0x0D30(0x0008)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	struct FScalableFloat                         MaxConsecutiveDropsOnSameSideOfPath;               // 0x0D38(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         MinPathDropOffset;                                 // 0x0D60(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         MaxPathDropOffset;                                 // 0x0D88(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         MinDropTriggerSpacing;                             // 0x0DB0(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         MaxDropTriggerSpacing;                             // 0x0DD8(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         MinDropDistFromRaceEnd;                            // 0x0E00(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         FirstDropTriggerDist;                              // 0x0E28(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         NumRepopulationsPerRacePathDrop;                   // 0x0E50(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         DelayBeforeRepopulatingRacePathDrops;              // 0x0E78(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         NumDropsAroundEnd;                                 // 0x0EA0(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         DelayBetweenEndPointDrops;                         // 0x0EC8(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         MinEndDropRadius;                                  // 0x0EF0(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         MaxEndDropRadius;                                  // 0x0F18(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         NumRepopulationsPerEndPointDrop;                   // 0x0F40(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         DelayBeforeRepopulatingEndPointDrops;              // 0x0F68(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FVector                                StartingPoint;                                     // 0x0F90(0x000C)(Net, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	uint8                                         Pad_F9C[0x2C];                                     // 0x0F9C(0x002C)(Fixing Size After Last Property [ Dumper-7 ])
	class UFortMontageItemDefinitionBase*         StartingLineEmote;                                 // 0x0FC8(0x0008)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	struct FScalableFloat                         MaxStartingLineEmoteDelay;                         // 0x0FD0(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         MinStartingLineEmotePlayRate;                      // 0x0FF8(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         MaxStartingLineEmotePlayRate;                      // 0x1020(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         bPlayStartingLineEmoteBeforeCountdown;             // 0x1048(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	class UFortMontageItemDefinitionBase*         FinishedRaceEmote;                                 // 0x1070(0x0008)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	struct FScalableFloat                         FinishedRaceEmoteTime;                             // 0x1078(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	class UNiagaraSystem*                         SquadmateVictoryVFXTemplate;                       // 0x10A0(0x0008)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	class UParticleSystem*                        FinishedPlayerDespawnVFXTemplate;                  // 0x10A8(0x0008)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	struct FScalableFloat                         MaxFloorCheckDist;                                 // 0x10B0(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         NumNearbyTicketsToShowOnCompass;                   // 0x10D8(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                         NumNearbyTicketsToShowInWorld;                     // 0x1100(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	uint8                                         Pad_1128[0x8];                                     // 0x1128(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSlateBrush                            TicketCompassBrush;                                // 0x1130(0x00B0)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	float                                         TicketCompassBrush_YOffset;                        // 0x11E0(0x0004)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	float                                         TicketCompassBrush_Scale;                          // 0x11E4(0x0004)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	struct FScalableFloat                         SortClientTicketComponentsTime;                    // 0x11E8(0x0028)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FSlateBrush                            AcquiredAllTicketsMapBrush;                        // 0x1210(0x00B0)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	struct FGameplayTagContainer                  TicketSpecialActorCategories;                      // 0x12C0(0x0020)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	TMap<class FName, class FName>                AnalyticsAttributeNameToStatNameMap;               // 0x12E0(0x0050)(Edit, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	TSubclassOf<class UFortGameplayAbility_JumpBoostPack> JumpBoostPackAbilityClass;                         // 0x1330(0x0008)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, Protected, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	struct FArgonRaceStateInfo                    CurrentRaceState;                                  // 0x1338(0x0018)(Net, RepNotify, NativeAccessSpecifierPrivate)
	uint8                                         Pad_1350[0x28];                                    // 0x1350(0x0028)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class AFortSquadStart*>                SquadStarts;                                       // 0x1378(0x0010)(ZeroConstructor, NativeAccessSpecifierPrivate)
	TArray<struct FArgonPlayerInfo>               RacingPlayersByPlace;                              // 0x1388(0x0010)(Net, ZeroConstructor, RepNotify, NativeAccessSpecifierPrivate)
	TArray<struct FArgonTeamProgressBarInfo>      LeaderProgressInfos;                               // 0x1398(0x0010)(Net, ZeroConstructor, NativeAccessSpecifierPrivate)
	TArray<struct FArgonTeamTicketCount>          TeamTicketCounts;                                  // 0x13A8(0x0010)(Net, ZeroConstructor, RepNotify, NativeAccessSpecifierPrivate)
	uint8                                         Pad_13B8[0x10];                                    // 0x13B8(0x0010)(Fixing Size After Last Property [ Dumper-7 ])
	class AAthenaHoldingArea*                     SquadStartHoldingArea;                             // 0x13C8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	class AArgonTraversePoint*                    EndTraversePoint;                                  // 0x13D0(0x0008)(Net, ZeroConstructor, IsPlainOldData, RepNotify, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	class AFortAthenaMutator_SynchronizedTeleport* TeleportMutator;                                   // 0x13D8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	class AFortAthenaMutator_GameStartCountdown*  GameStartCountdownMutator;                         // 0x13E0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	class AFortAthenaMutator_RespawnAndSpectateSelect* RespawnAndSpectateSelectMutator;                   // 0x13E8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	TMap<uint8, class AActor*>                    EntireSquadDeadRespawnActors;                      // 0x13F0(0x0050)(NativeAccessSpecifierPrivate)
	uint8                                         Pad_1440[0x11];                                    // 0x1440(0x0011)(Fixing Size After Last Property [ Dumper-7 ])
	uint8                                         NumSupplyDropClustersSpawned;                      // 0x1451(0x0001)(Net, ZeroConstructor, IsPlainOldData, RepNotify, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	uint8                                         Pad_1452[0x2];                                     // 0x1452(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         RaceStartTime;                                     // 0x1454(0x0004)(Net, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	TArray<TWeakObjectPtr<class AFortPlayerPawn>> FinishedPlayerPawns;                               // 0x1458(0x0010)(Net, ZeroConstructor, UObjectWrapper, NativeAccessSpecifierPrivate)
	uint8                                         Pad_1468[0xE8];                                    // 0x1468(0x00E8)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	void GetProgressBarUIInfo(float* OutMyPercent, TArray<float>* OutSquadmatePcts, uint8* OutNumSquadTickets, TArray<struct FArgonTeamProgressBarInfo>* OutEnemyProgressInfos);
	void HandleGameStartCountdownEnd();
	void HandleGroupTeleportComplete();
	void HandlePlayerTeleportComplete(class AFortPlayerStateAthena* PlayerState);
	void OnEndTraversePointTouched(class AAthenaTraversePoint* PointActor, class AFortPlayerStateAthena* TouchingPlayer);
	void OnRep_CurrentRaceState();
	void OnRep_EndTraversePoint();
	void OnRep_NumSupplyDropClustersSpawned();
	void OnRep_RacingPlayersByPlace();
	void OnRep_TeamTicketCounts();
	void SortClientTicketComponents();

	bool DidPlayerCrossFinishLine(const class AFortPlayerStateAthena* PlayerState) const;
	void FindSpawnLocationInSafeZone(struct FVector* InOutSpawnLocation) const;
	class AArgonTraversePoint* GetEndTraversePoint() const;
	int32 GetNumberOfTicketsNeededToFinishRace() const;
	int32 GetNumberOfTicketsTeamHasAcquired(uint8 Team) const;
	int32 GetPlayerTeamPlacement(class AFortPlayerStateAthena* Player) const;
	float GetRaceTimeElapsed() const;
	float GetRandomStartingLineEmotePlayRate() const;
	class UFortWorldItemDefinition* GetTicketItemDefinition() const;
	bool HasPlayerFinishedRace(const class AFortPlayerStateAthena* PlayerState) const;
	bool HasTeamFinishedRace(uint8 Team) const;
	bool IsInSafeZone(const struct FVector& TestLocation) const;
	bool IsUsingRespawnAndSpectateSelectMutator() const;
	bool ShouldShowNearbyTicketIndicators() const;

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"FortAthenaMutator_Argon">();
	}
	static class AFortAthenaMutator_Argon* GetDefaultObj()
	{
		return GetDefaultObjImpl<AFortAthenaMutator_Argon>();
	}
};

}

