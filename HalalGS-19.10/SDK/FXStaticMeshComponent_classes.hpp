#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: FXStaticMeshComponent

#include "Basic.hpp"

#include "FortniteGame_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass FXStaticMeshComponent.FXStaticMeshComponent_C
// 0x0000 (0x0500 - 0x0500)
class UFXStaticMeshComponent_C final : public UFortFXStaticMeshComponent
{
public:
	void ApplyAwakenEffect();
	void ApplyBuildingHitEffect();
	void ApplyEffect(class UMaterialInterface* Source_Material, float FadeInTime, float Duration, float FadeOutTimer);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"FXStaticMeshComponent_C">();
	}
	static class UFXStaticMeshComponent_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UFXStaticMeshComponent_C>();
	}
};

}

