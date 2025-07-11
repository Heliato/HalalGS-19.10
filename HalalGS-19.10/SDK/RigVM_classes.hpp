#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: RigVM

#include "Basic.hpp"

#include "RigVM_structs.hpp"
#include "CoreUObject_classes.hpp"


namespace SDK
{

// Class RigVM.RigVM
// 0x0298 (0x02C0 - 0x0028)
class URigVM final : public UObject
{
public:
	class URigVMMemoryStorage*                    WorkMemoryStorageObject;                           // 0x0028(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class URigVMMemoryStorage*                    LiteralMemoryStorageObject;                        // 0x0030(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class URigVMMemoryStorage*                    DebugMemoryStorageObject;                          // 0x0038(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_40[0x20];                                      // 0x0040(0x0020)(Fixing Size After Last Property [ Dumper-7 ])
	struct FRigVMByteCode                         ByteCodeStorage;                                   // 0x0060(0x0030)(NativeAccessSpecifierPublic)
	uint8                                         Pad_90[0x8];                                       // 0x0090(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FRigVMInstructionArray                 Instructions;                                      // 0x0098(0x0010)(Transient, NativeAccessSpecifierPrivate)
	uint8                                         Pad_A8[0x8];                                       // 0x00A8(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FRigVMExecuteContext                   Context;                                           // 0x00B0(0x00C0)(Transient, NativeAccessSpecifierPrivate)
	uint32                                        NumExecutions;                                     // 0x0170(0x0004)(ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	uint8                                         Pad_174[0x4];                                      // 0x0174(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class FName>                           FunctionNamesStorage;                              // 0x0178(0x0010)(ZeroConstructor, NativeAccessSpecifierPrivate)
	uint8                                         Pad_188[0x20];                                     // 0x0188(0x0020)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FRigVMParameter>                Parameters;                                        // 0x01A8(0x0010)(ZeroConstructor, NativeAccessSpecifierPrivate)
	TMap<class FName, int32>                      ParametersNameMap;                                 // 0x01B8(0x0050)(NativeAccessSpecifierPrivate)
	uint8                                         Pad_208[0x98];                                     // 0x0208(0x0098)(Fixing Size After Last Property [ Dumper-7 ])
	class URigVM*                                 DeferredVMToCopy;                                  // 0x02A0(0x0008)(ZeroConstructor, Transient, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	uint8                                         Pad_2A8[0x18];                                     // 0x02A8(0x0018)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	int32 AddRigVMFunction(class UScriptStruct* InRigVMStruct, const class FName& InMethodName);
	bool Execute(const class FName& InEntryName);
	bool GetParameterValueBool(const class FName& InParameterName, int32 InArrayIndex);
	double GetParameterValueDouble(const class FName& InParameterName, int32 InArrayIndex);
	float GetParameterValueFloat(const class FName& InParameterName, int32 InArrayIndex);
	int32 GetParameterValueInt(const class FName& InParameterName, int32 InArrayIndex);
	class FName GetParameterValueName(const class FName& InParameterName, int32 InArrayIndex);
	struct FQuat GetParameterValueQuat(const class FName& InParameterName, int32 InArrayIndex);
	class FString GetParameterValueString(const class FName& InParameterName, int32 InArrayIndex);
	struct FTransform GetParameterValueTransform(const class FName& InParameterName, int32 InArrayIndex);
	struct FVector GetParameterValueVector(const class FName& InParameterName, int32 InArrayIndex);
	struct FVector2D GetParameterValueVector2D(const class FName& InParameterName, int32 InArrayIndex);
	void SetParameterValueBool(const class FName& InParameterName, bool InValue, int32 InArrayIndex);
	void SetParameterValueDouble(const class FName& InParameterName, double InValue, int32 InArrayIndex);
	void SetParameterValueFloat(const class FName& InParameterName, float InValue, int32 InArrayIndex);
	void SetParameterValueInt(const class FName& InParameterName, int32 InValue, int32 InArrayIndex);
	void SetParameterValueName(const class FName& InParameterName, const class FName& InValue, int32 InArrayIndex);
	void SetParameterValueQuat(const class FName& InParameterName, const struct FQuat& InValue, int32 InArrayIndex);
	void SetParameterValueString(const class FName& InParameterName, const class FString& InValue, int32 InArrayIndex);
	void SetParameterValueTransform(const class FName& InParameterName, const struct FTransform& InValue, int32 InArrayIndex);
	void SetParameterValueVector(const class FName& InParameterName, const struct FVector& InValue, int32 InArrayIndex);
	void SetParameterValueVector2D(const class FName& InParameterName, const struct FVector2D& InValue, int32 InArrayIndex);

	class FString GetRigVMFunctionName(int32 InFunctionIndex) const;
	struct FRigVMStatistics GetStatistics() const;

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"RigVM">();
	}
	static class URigVM* GetDefaultObj()
	{
		return GetDefaultObjImpl<URigVM>();
	}
};

// Class RigVM.RigVMMemoryStorageGeneratorClass
// 0x0038 (0x0270 - 0x0238)
class URigVMMemoryStorageGeneratorClass final : public UClass
{
public:
	uint8                                         Pad_238[0x38];                                     // 0x0238(0x0038)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"RigVMMemoryStorageGeneratorClass">();
	}
	static class URigVMMemoryStorageGeneratorClass* GetDefaultObj()
	{
		return GetDefaultObjImpl<URigVMMemoryStorageGeneratorClass>();
	}
};

// Class RigVM.RigVMMemoryStorage
// 0x0000 (0x0028 - 0x0028)
class URigVMMemoryStorage final : public UObject
{
public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"RigVMMemoryStorage">();
	}
	static class URigVMMemoryStorage* GetDefaultObj()
	{
		return GetDefaultObjImpl<URigVMMemoryStorage>();
	}
};

}

