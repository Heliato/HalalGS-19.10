#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: NiagaraShader

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"


namespace SDK
{

// Enum NiagaraShader.ENiagaraMipMapGenerationType
// NumValues: 0x0007
enum class ENiagaraMipMapGenerationType : uint8
{
	Unfiltered                               = 0,
	Linear                                   = 1,
	Blur1                                    = 2,
	Blur2                                    = 3,
	Blur3                                    = 4,
	Blur4                                    = 5,
	ENiagaraMipMapGenerationType_MAX         = 6,
};

// Enum NiagaraShader.ENiagaraSimStageExecuteBehavior
// NumValues: 0x0004
enum class ENiagaraSimStageExecuteBehavior : uint8
{
	Always                                   = 0,
	OnSimulationReset                        = 1,
	NotOnSimulationReset                     = 2,
	ENiagaraSimStageExecuteBehavior_MAX      = 3,
};

// Enum NiagaraShader.FNiagaraCompileEventSeverity
// NumValues: 0x0004
enum class EFNiagaraCompileEventSeverity : uint8
{
	Log                                      = 0,
	Warning                                  = 1,
	Error                                    = 2,
	FNiagaraCompileEventSeverity_MAX         = 3,
};

// Enum NiagaraShader.FNiagaraCompileEventSource
// NumValues: 0x0003
enum class EFNiagaraCompileEventSource : uint8
{
	Unset                                    = 0,
	ScriptDependency                         = 1,
	FNiagaraCompileEventSource_MAX           = 2,
};

// ScriptStruct NiagaraShader.SimulationStageMetaData
// 0x0040 (0x0040 - 0x0000)
struct FSimulationStageMetaData final
{
public:
	class FName                                   SimulationStageName;                               // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FName                                   EnabledBinding;                                    // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FName                                   IterationSource;                                   // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	ENiagaraSimStageExecuteBehavior               ExecuteBehavior;                                   // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_19[0x3];                                       // 0x0019(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	uint8                                         bWritesParticles : 1;                              // 0x001C(0x0001)(BitIndex: 0x00, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         bPartialParticleUpdate : 1;                        // 0x001C(0x0001)(BitIndex: 0x01, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         Pad_1D[0x3];                                       // 0x001D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class FName>                           OutputDestinations;                                // 0x0020(0x0010)(ZeroConstructor, NativeAccessSpecifierPublic)
	int32                                         NumIterations;                                     // 0x0030(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FName                                   NumIterationsBinding;                              // 0x0034(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_3C[0x4];                                       // 0x003C(0x0004)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct NiagaraShader.NiagaraDataInterfaceGeneratedFunction
// 0x0028 (0x0028 - 0x0000)
struct alignas(0x08) FNiagaraDataInterfaceGeneratedFunction final
{
public:
	uint8                                         Pad_0[0x28];                                       // 0x0000(0x0028)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct NiagaraShader.NiagaraDataInterfaceGPUParamInfo
// 0x0030 (0x0030 - 0x0000)
struct FNiagaraDataInterfaceGPUParamInfo final
{
public:
	class FString                                 DataInterfaceHLSLSymbol;                           // 0x0000(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 DIClassName;                                       // 0x0010(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TArray<struct FNiagaraDataInterfaceGeneratedFunction> GeneratedFunctions;                                // 0x0020(0x0010)(ZeroConstructor, NativeAccessSpecifierPublic)
};

// ScriptStruct NiagaraShader.NiagaraCompileEvent
// 0x0068 (0x0068 - 0x0000)
struct FNiagaraCompileEvent final
{
public:
	EFNiagaraCompileEventSeverity                 Severity;                                          // 0x0000(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_1[0x7];                                        // 0x0001(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 Message;                                           // 0x0008(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 ShortDescription;                                  // 0x0018(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bDismissable;                                      // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_29[0x3];                                       // 0x0029(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FGuid                                  NodeGUID;                                          // 0x002C(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FGuid                                  PinGuid;                                           // 0x003C(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_4C[0x4];                                       // 0x004C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FGuid>                          StackGuids;                                        // 0x0050(0x0010)(ZeroConstructor, NativeAccessSpecifierPublic)
	EFNiagaraCompileEventSource                   Source;                                            // 0x0060(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_61[0x7];                                       // 0x0061(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

}

