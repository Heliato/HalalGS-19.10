#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AthenaFunctionLibrary

#include "Basic.hpp"

#include "AthenaFunctionLibrary_classes.hpp"
#include "AthenaFunctionLibrary_parameters.hpp"


namespace SDK
{

// Function AthenaFunctionLibrary.AthenaFunctionLibrary_C.AllOnSameTeam
// (Static, Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor*                           Actor                                                  (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// TArray<class AActor*>                   ActorArray                                             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UAthenaFunctionLibrary_C::AllOnSameTeam(const class AActor* Actor, const TArray<class AActor*>& ActorArray, class UObject* __WorldContext, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("AthenaFunctionLibrary_C", "AllOnSameTeam");

	Params::AthenaFunctionLibrary_C_AllOnSameTeam Parms{};

	Parms.Actor = Actor;
	Parms.ActorArray = std::move(ActorArray);
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function AthenaFunctionLibrary.AthenaFunctionLibrary_C.CreateEnvironmentalKnockbackExplosion
// (Static, Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FVector                          ExplosionSourcePoint                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   ExplosionRadius                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   Intensity                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   MinKnockbackAngle                                      (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Reverse                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class AActor*                           SpecificActor                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UAthenaFunctionLibrary_C::CreateEnvironmentalKnockbackExplosion(const struct FVector& ExplosionSourcePoint, float ExplosionRadius, float Intensity, float MinKnockbackAngle, bool Reverse, class AActor* SpecificActor, class UObject* __WorldContext)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("AthenaFunctionLibrary_C", "CreateEnvironmentalKnockbackExplosion");

	Params::AthenaFunctionLibrary_C_CreateEnvironmentalKnockbackExplosion Parms{};

	Parms.ExplosionSourcePoint = std::move(ExplosionSourcePoint);
	Parms.ExplosionRadius = ExplosionRadius;
	Parms.Intensity = Intensity;
	Parms.MinKnockbackAngle = MinKnockbackAngle;
	Parms.Reverse = Reverse;
	Parms.SpecificActor = SpecificActor;
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);
}


// Function AthenaFunctionLibrary.AthenaFunctionLibrary_C.GetActorMeshExtents
// (Static, Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor*                           Actor                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector                          BoundingBoxExtents                                     (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UAthenaFunctionLibrary_C::GetActorMeshExtents(class AActor* Actor, class UObject* __WorldContext, struct FVector* BoundingBoxExtents)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("AthenaFunctionLibrary_C", "GetActorMeshExtents");

	Params::AthenaFunctionLibrary_C_GetActorMeshExtents Parms{};

	Parms.Actor = Actor;
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	if (BoundingBoxExtents != nullptr)
		*BoundingBoxExtents = std::move(Parms.BoundingBoxExtents);
}


// Function AthenaFunctionLibrary.AthenaFunctionLibrary_C.MakeSimpleFortEffectContext
// (Static, Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class AActor*                           Instigator                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class AActor*                           Damage_Source                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FGameplayEffectContextHandle     ReturnValue                                            (Parm, OutParm, ReturnParm)

struct FGameplayEffectContextHandle UAthenaFunctionLibrary_C::MakeSimpleFortEffectContext(class AActor* Instigator, class AActor* Damage_Source, class UObject* __WorldContext)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("AthenaFunctionLibrary_C", "MakeSimpleFortEffectContext");

	Params::AthenaFunctionLibrary_C_MakeSimpleFortEffectContext Parms{};

	Parms.Instigator = Instigator;
	Parms.Damage_Source = Damage_Source;
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function AthenaFunctionLibrary.AthenaFunctionLibrary_C.RowToBool
// (Static, Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FScalableFloat                   Input                                                  (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// float                                   Level                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

bool UAthenaFunctionLibrary_C::RowToBool(const struct FScalableFloat& Input, float Level, class UObject* __WorldContext)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("AthenaFunctionLibrary_C", "RowToBool");

	Params::AthenaFunctionLibrary_C_RowToBool Parms{};

	Parms.Input = std::move(Input);
	Parms.Level = Level;
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function AthenaFunctionLibrary.AthenaFunctionLibrary_C.ShouldAllowDeathEffects
// (Static, Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FGameplayTagContainer            Damage_Or_Death_Tags                                   (BlueprintVisible, BlueprintReadOnly, Parm)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

bool UAthenaFunctionLibrary_C::ShouldAllowDeathEffects(const struct FGameplayTagContainer& Damage_Or_Death_Tags, class UObject* __WorldContext)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("AthenaFunctionLibrary_C", "ShouldAllowDeathEffects");

	Params::AthenaFunctionLibrary_C_ShouldAllowDeathEffects Parms{};

	Parms.Damage_Or_Death_Tags = std::move(Damage_Or_Death_Tags);
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function AthenaFunctionLibrary.AthenaFunctionLibrary_C.SpawnLootFromTable
// (Static, Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FName                             TierGroupName                                          (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   WorldLevel                                             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   ForcedLootTier                                         (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector                          Position                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector                          Direction                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   OverrideMaxStackCount                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    bToss                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    bRandomRotation                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    bBlockedFromAutoPickup                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   PickupInstigatorHandle                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// EFortPickupSourceTypeFlag               SourceType                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// EFortPickupSpawnSource                  Source                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class AFortPlayerController*            OptionalOwnerPC                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    bPickupOnlyRelevantToOwner                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// TArray<class AFortPickup*>              ItemPickupsSpawned                                     (Parm, OutParm)

void UAthenaFunctionLibrary_C::SpawnLootFromTable(const class FName TierGroupName, const int32 WorldLevel, const int32 ForcedLootTier, const struct FVector& Position, const struct FVector& Direction, int32 OverrideMaxStackCount, bool bToss, bool bRandomRotation, bool bBlockedFromAutoPickup, int32 PickupInstigatorHandle, EFortPickupSourceTypeFlag SourceType, EFortPickupSpawnSource Source, class AFortPlayerController* OptionalOwnerPC, bool bPickupOnlyRelevantToOwner, class UObject* __WorldContext, TArray<class AFortPickup*>* ItemPickupsSpawned)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("AthenaFunctionLibrary_C", "SpawnLootFromTable");

	Params::AthenaFunctionLibrary_C_SpawnLootFromTable Parms{};

	Parms.TierGroupName = TierGroupName;
	Parms.WorldLevel = WorldLevel;
	Parms.ForcedLootTier = ForcedLootTier;
	Parms.Position = std::move(Position);
	Parms.Direction = std::move(Direction);
	Parms.OverrideMaxStackCount = OverrideMaxStackCount;
	Parms.bToss = bToss;
	Parms.bRandomRotation = bRandomRotation;
	Parms.bBlockedFromAutoPickup = bBlockedFromAutoPickup;
	Parms.PickupInstigatorHandle = PickupInstigatorHandle;
	Parms.SourceType = SourceType;
	Parms.Source = Source;
	Parms.OptionalOwnerPC = OptionalOwnerPC;
	Parms.bPickupOnlyRelevantToOwner = bPickupOnlyRelevantToOwner;
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	if (ItemPickupsSpawned != nullptr)
		*ItemPickupsSpawned = std::move(Parms.ItemPickupsSpawned);
}


// Function AthenaFunctionLibrary.AthenaFunctionLibrary_C.UnclampedLerp
// (Static, Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// float                                   A                                                      (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   B                                                      (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   Alpha                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   Return_Value                                           (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UAthenaFunctionLibrary_C::UnclampedLerp(float A, float B, float Alpha, class UObject* __WorldContext, float* Return_Value)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("AthenaFunctionLibrary_C", "UnclampedLerp");

	Params::AthenaFunctionLibrary_C_UnclampedLerp Parms{};

	Parms.A = A;
	Parms.B = B;
	Parms.Alpha = Alpha;
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	if (Return_Value != nullptr)
		*Return_Value = Parms.Return_Value;
}

}

