#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ResonanceAudio

#include "Basic.hpp"

#include "ResonanceAudio_structs.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK::Params
{

// Function ResonanceAudio.ResonanceAudioBlueprintFunctionLibrary.GetGlobalReverbPreset
// 0x0008 (0x0008 - 0x0000)
struct ResonanceAudioBlueprintFunctionLibrary_GetGlobalReverbPreset final
{
public:
	class UResonanceAudioReverbPluginPreset*      ReturnValue;                                       // 0x0000(0x0008)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function ResonanceAudio.ResonanceAudioBlueprintFunctionLibrary.SetGlobalReverbPreset
// 0x0008 (0x0008 - 0x0000)
struct ResonanceAudioBlueprintFunctionLibrary_SetGlobalReverbPreset final
{
public:
	class UResonanceAudioReverbPluginPreset*      InPreset;                                          // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function ResonanceAudio.ResonanceAudioReverbPluginPreset.SetEnableRoomEffects
// 0x0001 (0x0001 - 0x0000)
struct ResonanceAudioReverbPluginPreset_SetEnableRoomEffects final
{
public:
	bool                                          bInEnableRoomEffects;                              // 0x0000(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function ResonanceAudio.ResonanceAudioReverbPluginPreset.SetReflectionScalar
// 0x0004 (0x0004 - 0x0000)
struct ResonanceAudioReverbPluginPreset_SetReflectionScalar final
{
public:
	float                                         InReflectionScalar;                                // 0x0000(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function ResonanceAudio.ResonanceAudioReverbPluginPreset.SetReverbBrightness
// 0x0004 (0x0004 - 0x0000)
struct ResonanceAudioReverbPluginPreset_SetReverbBrightness final
{
public:
	float                                         InReverbBrightness;                                // 0x0000(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function ResonanceAudio.ResonanceAudioReverbPluginPreset.SetReverbGain
// 0x0004 (0x0004 - 0x0000)
struct ResonanceAudioReverbPluginPreset_SetReverbGain final
{
public:
	float                                         InReverbGain;                                      // 0x0000(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function ResonanceAudio.ResonanceAudioReverbPluginPreset.SetReverbTimeModifier
// 0x0004 (0x0004 - 0x0000)
struct ResonanceAudioReverbPluginPreset_SetReverbTimeModifier final
{
public:
	float                                         InReverbTimeModifier;                              // 0x0000(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function ResonanceAudio.ResonanceAudioReverbPluginPreset.SetRoomDimensions
// 0x000C (0x000C - 0x0000)
struct ResonanceAudioReverbPluginPreset_SetRoomDimensions final
{
public:
	struct FVector                                InDimensions;                                      // 0x0000(0x000C)(ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function ResonanceAudio.ResonanceAudioReverbPluginPreset.SetRoomMaterials
// 0x0010 (0x0010 - 0x0000)
struct ResonanceAudioReverbPluginPreset_SetRoomMaterials final
{
public:
	TArray<ERaMaterialName>                       InMaterials;                                       // 0x0000(0x0010)(ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, NativeAccessSpecifierPublic)
};

// Function ResonanceAudio.ResonanceAudioReverbPluginPreset.SetRoomPosition
// 0x000C (0x000C - 0x0000)
struct ResonanceAudioReverbPluginPreset_SetRoomPosition final
{
public:
	struct FVector                                InPosition;                                        // 0x0000(0x000C)(ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function ResonanceAudio.ResonanceAudioReverbPluginPreset.SetRoomRotation
// 0x0010 (0x0010 - 0x0000)
struct ResonanceAudioReverbPluginPreset_SetRoomRotation final
{
public:
	struct FQuat                                  InRotation;                                        // 0x0000(0x0010)(ConstParm, Parm, OutParm, ReferenceParm, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic)
};

// Function ResonanceAudio.ResonanceAudioSpatializationSourceSettings.SetSoundSourceDirectivity
// 0x0008 (0x0008 - 0x0000)
struct ResonanceAudioSpatializationSourceSettings_SetSoundSourceDirectivity final
{
public:
	float                                         InPattern;                                         // 0x0000(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         InSharpness;                                       // 0x0004(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function ResonanceAudio.ResonanceAudioSpatializationSourceSettings.SetSoundSourceSpread
// 0x0004 (0x0004 - 0x0000)
struct ResonanceAudioSpatializationSourceSettings_SetSoundSourceSpread final
{
public:
	float                                         InSpread;                                          // 0x0000(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

}

