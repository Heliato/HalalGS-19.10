#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: UACCommon

#include "Basic.hpp"

#include "Engine_classes.hpp"


namespace SDK
{

// Class UACCommon.UACNetworkComponent
// 0x0170 (0x0220 - 0x00B0)
class UUACNetworkComponent final : public UActorComponent
{
public:
	int32                                         PlayerId;                                          // 0x00B0(0x0004)(Net, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_B4[0x16C];                                     // 0x00B4(0x016C)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	void SendClientHello(uint32 SessionKey);
	void SendPacketToClient(uint8 Type, const TArray<uint8>& Packet);
	void SendPacketToServer(uint8 Type, const TArray<uint8>& Packet);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"UACNetworkComponent">();
	}
	static class UUACNetworkComponent* GetDefaultObj()
	{
		return GetDefaultObjImpl<UUACNetworkComponent>();
	}
};

}

