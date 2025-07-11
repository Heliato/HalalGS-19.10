#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: McpProfileSys

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "CoreUObject_classes.hpp"
#include "Engine_classes.hpp"
#include "McpProfileSys_structs.hpp"


namespace SDK
{

// Class McpProfileSys.McpItemAware
// 0x0000 (0x0028 - 0x0028)
class IMcpItemAware final : public IInterface
{
public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"McpItemAware">();
	}
	static class IMcpItemAware* GetDefaultObj()
	{
		return GetDefaultObjImpl<IMcpItemAware>();
	}
};

// Class McpProfileSys.McpProfileManager
// 0x0040 (0x0068 - 0x0028)
class UMcpProfileManager final : public UObject
{
public:
	uint8                                         Pad_28[0x10];                                      // 0x0028(0x0010)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FProfileGroupEntry>             ServerProfileGroups;                               // 0x0038(0x0010)(ZeroConstructor, NativeAccessSpecifierPrivate)
	TArray<struct FProfileGroupEntry>             ClientProfileGroups;                               // 0x0048(0x0010)(ZeroConstructor, NativeAccessSpecifierPrivate)
	uint8                                         Pad_58[0x8];                                       // 0x0058(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         MaxItemsProcessedInInitialUpdatesPerTick;          // 0x0060(0x0004)(ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	uint8                                         Pad_64[0x4];                                       // 0x0064(0x0004)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"McpProfileManager">();
	}
	static class UMcpProfileManager* GetDefaultObj()
	{
		return GetDefaultObjImpl<UMcpProfileManager>();
	}
};

// Class McpProfileSys.McpItemDefinitionBase
// 0x0000 (0x0030 - 0x0030)
class UMcpItemDefinitionBase : public UPrimaryDataAsset
{
public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"McpItemDefinitionBase">();
	}
	static class UMcpItemDefinitionBase* GetDefaultObj()
	{
		return GetDefaultObjImpl<UMcpItemDefinitionBase>();
	}
};

// Class McpProfileSys.McpProfile
// 0x00E8 (0x0110 - 0x0028)
class UMcpProfile : public UObject
{
public:
	bool                                          AllowSubscriptionToNotificationsService;           // 0x0028(0x0001)(ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	uint8                                         Pad_29[0x57];                                      // 0x0029(0x0057)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 DebugName;                                         // 0x0080(0x0010)(ZeroConstructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	bool                                          bProfileLockOperationPending;                      // 0x0090(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	bool                                          bProfileUnlockOperationPending;                    // 0x0091(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	bool                                          bEnableMocks;                                      // 0x0092(0x0001)(ZeroConstructor, Config, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	uint8                                         Pad_93[0x15];                                      // 0x0093(0x0015)(Fixing Size After Last Property [ Dumper-7 ])
	class UMcpProfileGroup*                       ProfileGroup;                                      // 0x00A8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	class FString                                 ProfileId;                                         // 0x00B0(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	int64                                         ProfileRevision;                                   // 0x00C0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	int32                                         FullProfileQueryQueued;                            // 0x00C8(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	bool                                          bProfileWriteLocked;                               // 0x00CC(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	uint8                                         Pad_CD[0x3];                                       // 0x00CD(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FDateTime                              ProfileWriteLockExpireTime;                        // 0x00D0(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	uint8                                         Pad_D8[0x38];                                      // 0x00D8(0x0038)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	void DeleteAllProfiles(struct FClientUrlContext* Context);
	void DeleteProfile(struct FClientUrlContext* Context);
	void LockProfileForWrite(const class FString& Code, int32 Timeout, struct FDedicatedServerUrlContext* Context);
	void QueryProfile(struct FBaseUrlContext* Context);
	void QueryPublicProfile(struct FBaseUrlContext* Context);
	void UnlockProfileForWrite(const class FString& Code, struct FDedicatedServerUrlContext* Context);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"McpProfile">();
	}
	static class UMcpProfile* GetDefaultObj()
	{
		return GetDefaultObjImpl<UMcpProfile>();
	}
};

// Class McpProfileSys.McpProfileGroup
// 0x0248 (0x0270 - 0x0028)
class alignas(0x10) UMcpProfileGroup final : public UObject
{
public:
	uint8                                         Pad_28[0xB4];                                      // 0x0028(0x00B4)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         DelayMcpResults;                                   // 0x00DC(0x0004)(ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	int32                                         WeeklyIntervalStartDay;                            // 0x00E0(0x0004)(ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	uint8                                         Pad_E4[0x4];                                       // 0x00E4(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FProfileEntry>                  ProfileList;                                       // 0x00E8(0x0010)(ZeroConstructor, NativeAccessSpecifierPrivate)
	uint8                                         Pad_F8[0x8];                                       // 0x00F8(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 PlayerName;                                        // 0x0100(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	bool                                          bIsServer;                                         // 0x0110(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	uint8                                         Pad_111[0x7];                                      // 0x0111(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 ProfileNotificationsStompTopic;                    // 0x0118(0x0010)(ZeroConstructor, Config, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	uint8                                         Pad_128[0x40];                                     // 0x0128(0x0040)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 LastMcpVersion;                                    // 0x0168(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	class FString                                 LastContentVersion;                                // 0x0178(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	class FString                                 LastMinBuild;                                      // 0x0188(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	struct FTimespan                              LocalTimeOffset;                                   // 0x0198(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	uint8                                         Pad_1A0[0x8];                                      // 0x01A0(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 LockCode;                                          // 0x01A8(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	TArray<class UMcpProfile*>                    LockedProfiles;                                    // 0x01B8(0x0010)(ZeroConstructor, NativeAccessSpecifierPrivate)
	class FString                                 LockedProfilesString;                              // 0x01C8(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	int32                                         ProfileWriteLockTimeoutSecs;                       // 0x01D8(0x0004)(ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	bool                                          bSubscribedToNotifications;                        // 0x01DC(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	uint8                                         Pad_1DD[0x3];                                      // 0x01DD(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 ApplyStashEndPoint;                                // 0x01E0(0x0010)(ZeroConstructor, Config, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	uint8                                         Pad_1F0[0x8];                                      // 0x01F0(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	bool                                          bSendProfileCommandRevisions;                      // 0x01F8(0x0001)(ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	bool                                          bAsyncParseProfileUpdates;                         // 0x01F9(0x0001)(ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	uint8                                         Pad_1FA[0x56];                                     // 0x01FA(0x0056)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         MaxChangesToForwardInUpdate;                       // 0x0250(0x0004)(ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	int32                                         ItemLogThreshold;                                  // 0x0254(0x0004)(ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	TArray<class FString>                         ForwardToClientExclusions;                         // 0x0258(0x0010)(ZeroConstructor, Config, NativeAccessSpecifierPrivate)
	uint8                                         Pad_268[0x8];                                      // 0x0268(0x0008)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"McpProfileGroup">();
	}
	static class UMcpProfileGroup* GetDefaultObj()
	{
		return GetDefaultObjImpl<UMcpProfileGroup>();
	}
};

}

