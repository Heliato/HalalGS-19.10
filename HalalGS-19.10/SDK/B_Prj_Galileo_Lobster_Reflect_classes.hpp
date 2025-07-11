#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: B_Prj_Galileo_Lobster_Reflect

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteGame_classes.hpp"
#include "CoreUObject_structs.hpp"
#include "GameplayAbilities_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass B_Prj_Galileo_Lobster_Reflect.B_Prj_Galileo_Lobster_Reflect_C
// 0x0078 (0x0A78 - 0x0A00)
class AB_Prj_Galileo_Lobster_Reflect_C final : public AFortProjectileAthena
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0A00(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UParticleSystemComponent*               P_Galileo_Bun_Projectile_Glow;                     // 0x0A08(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   TracerMesh;                                        // 0x0A10(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             Sniper_Rifle_SurfaceImpactSound;                   // 0x0A18(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             Sniper_Rifle_PlayerImpactSound;                    // 0x0A20(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                DecalSize;                                         // 0x0A28(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_A34[0x4];                                      // 0x0A34(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FScalableFloat                         ProjectileGravityScale;                            // 0x0A38(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance)
	bool                                          UseGalileoBunTracer;                               // 0x0A60(0x0001)(Edit, BlueprintVisible, Net, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)
	uint8                                         Pad_A61[0x7];                                      // 0x0A61(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UParticleSystem*                        GenericTracer;                                     // 0x0A68(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UStaticMesh*                            GenericMesh;                                       // 0x0A70(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_B_Prj_Galileo_Lobster_Reflect(int32 EntryPoint);
	void OnStop(const struct FHitResult& Hit);
	void ReceiveBeginPlay();
	void UserConstructionScript();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"B_Prj_Galileo_Lobster_Reflect_C">();
	}
	static class AB_Prj_Galileo_Lobster_Reflect_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AB_Prj_Galileo_Lobster_Reflect_C>();
	}
};

}

