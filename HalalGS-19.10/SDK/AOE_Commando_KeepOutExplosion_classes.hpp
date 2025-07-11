#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AOE_Commando_KeepOutExplosion

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteGame_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass AOE_Commando_KeepOutExplosion.AOE_Commando_KeepOutExplosion_C
// 0x03D8 (0x0990 - 0x05B8)
class AAOE_Commando_KeepOutExplosion_C final : public AFortAreaOfEffectCloud
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x05B8(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UAudioComponent*                        AOE_Audio_Effect;                                  // 0x05C0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UParticleSystemComponent*               P_Grenade_Linger;                                  // 0x05C8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USphereComponent*                       DamageArea;                                        // 0x05D0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USceneComponent*                        DefaultSceneRoot;                                  // 0x05D8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	float                                         Radius;                                            // 0x05E0(0x0004)(Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, RepNotify, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_5E4[0x4];                                      // 0x05E4(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSoundAttenuationSettings              AOE_Sound_Attenuation_Based_On_Radius;             // 0x05E8(0x03A8)(Edit, BlueprintVisible, DisableEditOnInstance)

public:
	void ExecuteUbergraph_AOE_Commando_KeepOutExplosion(int32 EntryPoint);
	void OnRep_Radius();
	void ReceiveBeginPlay();
	void ReceiveDestroyed();
	void Send_Info(float Param_Radius);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"AOE_Commando_KeepOutExplosion_C">();
	}
	static class AAOE_Commando_KeepOutExplosion_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AAOE_Commando_KeepOutExplosion_C>();
	}
};

}

