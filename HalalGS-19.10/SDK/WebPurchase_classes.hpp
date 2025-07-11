#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WebPurchase

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WebPurchase.WebPurchase_C
// 0x0020 (0x04A0 - 0x0480)
class UWebPurchase_C final : public UFortWebPurchaseScreen
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0480(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UCircularThrobber*                      Throbber;                                          // 0x0488(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	struct FDataTableRowHandle                    BackAction;                                        // 0x0490(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor)

public:
	void HandleBack(bool* bPassThrough);
	void ExecuteUbergraph_WebPurchase(int32 EntryPoint);
	void BindDelegates();
	void BP_OnActivated();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WebPurchase_C">();
	}
	static class UWebPurchase_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWebPurchase_C>();
	}
};

}

