#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Hotfix

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "CoreUObject_classes.hpp"
#include "Hotfix_structs.hpp"


namespace SDK
{

// Class Hotfix.OnlineHotfixManager
// 0x0210 (0x0238 - 0x0028)
class UOnlineHotfixManager : public UObject
{
public:
	uint8                                         Pad_28[0x1D0];                                     // 0x0028(0x01D0)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 OSSName;                                           // 0x01F8(0x0010)(ZeroConstructor, Config, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 HotfixManagerClassName;                            // 0x0208(0x0010)(ZeroConstructor, Config, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 DebugPrefix;                                       // 0x0218(0x0010)(ZeroConstructor, Config, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TArray<class UObject*>                        AssetsHotfixedFromIniFiles;                        // 0x0228(0x0010)(ZeroConstructor, Transient, NativeAccessSpecifierPublic)

public:
	void StartHotfixProcess();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"OnlineHotfixManager">();
	}
	static class UOnlineHotfixManager* GetDefaultObj()
	{
		return GetDefaultObjImpl<UOnlineHotfixManager>();
	}
};

// Class Hotfix.UpdateManager
// 0x00F0 (0x0118 - 0x0028)
class UUpdateManager : public UObject
{
public:
	uint8                                         Pad_28[0x60];                                      // 0x0028(0x0060)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         HotfixCheckCompleteDelay;                          // 0x0088(0x0004)(ZeroConstructor, Config, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	float                                         UpdateCheckCompleteDelay;                          // 0x008C(0x0004)(ZeroConstructor, Config, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	float                                         HotfixAvailabilityCheckCompleteDelay;              // 0x0090(0x0004)(ZeroConstructor, Config, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	float                                         UpdateCheckAvailabilityCompleteDelay;              // 0x0094(0x0004)(ZeroConstructor, Config, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	uint8                                         Pad_98[0x4];                                       // 0x0098(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         AppSuspendedUpdateCheckTimeSeconds;                // 0x009C(0x0004)(ZeroConstructor, Config, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	uint8                                         Pad_A0[0x8];                                       // 0x00A0(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	bool                                          bPlatformEnvironmentDetected;                      // 0x00A8(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	bool                                          bInitialUpdateFinished;                            // 0x00A9(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	bool                                          bCheckHotfixAvailabilityOnly;                      // 0x00AA(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	EUpdateState                                  CurrentUpdateState;                                // 0x00AB(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	int32                                         WorstNumFilesPendingLoadViewed;                    // 0x00AC(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	uint8                                         Pad_B0[0x4];                                       // 0x00B0(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	EHotfixResult                                 LastHotfixResult;                                  // 0x00B4(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	uint8                                         Pad_B5[0x23];                                      // 0x00B5(0x0023)(Fixing Size After Last Property [ Dumper-7 ])
	struct FDateTime                              LastUpdateCheck[0x2];                              // 0x00D8(0x0008)(ZeroConstructor, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	EUpdateCompletionStatus                       LastCompletionResult[0x2];                         // 0x00E8(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	uint8                                         Pad_EA[0x1E];                                      // 0x00EA(0x001E)(Fixing Size After Last Property [ Dumper-7 ])
	class UEnum*                                  UpdateStateEnum;                                   // 0x0108(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	class UEnum*                                  UpdateCompletionEnum;                              // 0x0110(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"UpdateManager">();
	}
	static class UUpdateManager* GetDefaultObj()
	{
		return GetDefaultObjImpl<UUpdateManager>();
	}
};

}

