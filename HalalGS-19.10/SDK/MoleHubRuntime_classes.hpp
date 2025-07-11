#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: MoleHubRuntime

#include "Basic.hpp"

#include "GameHubRuntime_classes.hpp"


namespace SDK
{

// Class MoleHubRuntime.MoleHubBaseMutator
// 0x0000 (0x02D8 - 0x02D8)
class AMoleHubBaseMutator final : public AGameHubBaseMutator
{
public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"MoleHubBaseMutator">();
	}
	static class AMoleHubBaseMutator* GetDefaultObj()
	{
		return GetDefaultObjImpl<AMoleHubBaseMutator>();
	}
};

// Class MoleHubRuntime.MoleHubPlayerSpawningComponent
// 0x0000 (0x00E0 - 0x00E0)
class UMoleHubPlayerSpawningComponent final : public UGameHubPlayerSpawningComponent
{
public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"MoleHubPlayerSpawningComponent">();
	}
	static class UMoleHubPlayerSpawningComponent* GetDefaultObj()
	{
		return GetDefaultObjImpl<UMoleHubPlayerSpawningComponent>();
	}
};

// Class MoleHubRuntime.MoleHubPlayspace
// 0x0000 (0x0568 - 0x0568)
class AMoleHubPlayspace final : public AGameHubPlayspace
{
public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"MoleHubPlayspace">();
	}
	static class AMoleHubPlayspace* GetDefaultObj()
	{
		return GetDefaultObjImpl<AMoleHubPlayspace>();
	}
};

}

