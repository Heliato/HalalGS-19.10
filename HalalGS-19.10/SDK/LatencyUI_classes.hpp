#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: LatencyUI

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "UMG_classes.hpp"


namespace SDK
{

// Class LatencyUI.LatencyGraph
// 0x0040 (0x0288 - 0x0248)
class ULatencyGraph final : public UUserWidget
{
public:
	struct FColor                                 TotalLatencyLineColor;                             // 0x0248(0x0004)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	struct FColor                                 GameLatencyLineColor;                              // 0x024C(0x0004)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	struct FColor                                 RenderLatencyLineColor;                            // 0x0250(0x0004)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	struct FColor                                 DriverLatencyLineColor;                            // 0x0254(0x0004)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	struct FColor                                 OSWorkQueueLatencyLineColor;                       // 0x0258(0x0004)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	struct FColor                                 GPURenderLatencyLineColor;                         // 0x025C(0x0004)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	struct FColor                                 BackgroundColor;                                   // 0x0260(0x0004)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	float                                         MaxLatencyToGraph;                                 // 0x0264(0x0004)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	struct FVector2D                              DesiredSize;                                       // 0x0268(0x0008)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	uint8                                         Pad_270[0x18];                                     // 0x0270(0x0018)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"LatencyGraph">();
	}
	static class ULatencyGraph* GetDefaultObj()
	{
		return GetDefaultObjImpl<ULatencyGraph>();
	}
};

// Class LatencyUI.LatencyWidget
// 0x00F8 (0x0340 - 0x0248)
class ULatencyWidget final : public UUserWidget
{
public:
	uint8                                         Pad_248[0x8];                                      // 0x0248(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	class UCommonTextBlock*                       TotalLatencyUI;                                    // 0x0250(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	class UCommonTextBlock*                       GameLatencyUI;                                     // 0x0258(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	class UCommonTextBlock*                       RenderLatencyUI;                                   // 0x0260(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	class UCommonTextBlock*                       OSWorkLatencyUI;                                   // 0x0268(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	class UCommonTextBlock*                       DriverLatencyUI;                                   // 0x0270(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	class UCommonTextBlock*                       GPURenderLatencyUI;                                // 0x0278(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	class UCommonTextBlock*                       TweakLatencyUI;                                    // 0x0280(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	uint8                                         Pad_288[0xB8];                                     // 0x0288(0x00B8)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	void StartTimer();
	void StopTimer();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"LatencyWidget">();
	}
	static class ULatencyWidget* GetDefaultObj()
	{
		return GetDefaultObjImpl<ULatencyWidget>();
	}
};

}

