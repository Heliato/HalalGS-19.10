#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TypedElementRuntime

#include "Basic.hpp"

#include "CoreUObject_classes.hpp"
#include "TypedElementRuntime_structs.hpp"


namespace SDK
{

// Class TypedElementRuntime.TypedElementAssetDataInterface
// 0x0000 (0x0028 - 0x0028)
class ITypedElementAssetDataInterface final : public IInterface
{
public:
	TArray<struct FAssetData> GetAllReferencedAssetDatas(const struct FTypedElementHandle& InElementHandle);
	struct FAssetData GetAssetData(const struct FTypedElementHandle& InElementHandle);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"TypedElementAssetDataInterface">();
	}
	static class ITypedElementAssetDataInterface* GetDefaultObj()
	{
		return GetDefaultObjImpl<ITypedElementAssetDataInterface>();
	}
};

// Class TypedElementRuntime.TypedElementHierarchyInterface
// 0x0000 (0x0028 - 0x0028)
class ITypedElementHierarchyInterface final : public IInterface
{
public:
	void GetChildElements(const struct FTypedElementHandle& InElementHandle, TArray<struct FTypedElementHandle>* OutElementHandles, const bool bAllowCreate);
	struct FTypedElementHandle GetParentElement(const struct FTypedElementHandle& InElementHandle, const bool bAllowCreate);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"TypedElementHierarchyInterface">();
	}
	static class ITypedElementHierarchyInterface* GetDefaultObj()
	{
		return GetDefaultObjImpl<ITypedElementHierarchyInterface>();
	}
};

// Class TypedElementRuntime.TypedElementObjectInterface
// 0x0000 (0x0028 - 0x0028)
class ITypedElementObjectInterface final : public IInterface
{
public:
	class UObject* GetObject(const struct FTypedElementHandle& InElementHandle);
	class UClass* GetObjectClass(const struct FTypedElementHandle& InElementHandle);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"TypedElementObjectInterface">();
	}
	static class ITypedElementObjectInterface* GetDefaultObj()
	{
		return GetDefaultObjImpl<ITypedElementObjectInterface>();
	}
};

// Class TypedElementRuntime.TypedElementSelectionInterface
// 0x0000 (0x0028 - 0x0028)
class ITypedElementSelectionInterface final : public IInterface
{
public:
	bool AllowSelectionModifiers(const struct FTypedElementHandle& InElementHandle, const struct FTypedElementListProxy& InSelectionSet);
	bool CanDeselectElement(const struct FTypedElementHandle& InElementHandle, const struct FTypedElementSelectionOptions& InSelectionOptions);
	bool CanSelectElement(const struct FTypedElementHandle& InElementHandle, const struct FTypedElementSelectionOptions& InSelectionOptions);
	bool DeselectElement(const struct FTypedElementHandle& InElementHandle, const struct FTypedElementListProxy& InSelectionSet, const struct FTypedElementSelectionOptions& InSelectionOptions);
	struct FTypedElementHandle GetSelectionElement(const struct FTypedElementHandle& InElementHandle, const struct FTypedElementListProxy& InCurrentSelection, const ETypedElementSelectionMethod InSelectionMethod);
	bool IsElementSelected(const struct FTypedElementHandle& InElementHandle, const struct FTypedElementListProxy& InSelectionSet, const struct FTypedElementIsSelectedOptions& InSelectionOptions);
	bool SelectElement(const struct FTypedElementHandle& InElementHandle, const struct FTypedElementListProxy& InSelectionSet, const struct FTypedElementSelectionOptions& InSelectionOptions);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"TypedElementSelectionInterface">();
	}
	static class ITypedElementSelectionInterface* GetDefaultObj()
	{
		return GetDefaultObjImpl<ITypedElementSelectionInterface>();
	}
};

// Class TypedElementRuntime.TypedElementSelectionSet
// 0x0870 (0x0898 - 0x0028)
class UTypedElementSelectionSet final : public UObject
{
public:
	uint8                                         Pad_28[0x800];                                     // 0x0028(0x0800)(Fixing Size After Last Property [ Dumper-7 ])
	FMulticastInlineDelegateProperty_             OnPreSelectionChange;                              // 0x0828(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic)
	FMulticastInlineDelegateProperty_             OnSelectionChange;                                 // 0x0838(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic)
	uint8                                         Pad_848[0x50];                                     // 0x0848(0x0050)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	bool ClearSelection(const struct FTypedElementSelectionOptions& InSelectionOptions);
	bool DeselectElement(const struct FTypedElementHandle& InElementHandle, const struct FTypedElementSelectionOptions& InSelectionOptions);
	bool DeselectElements(const TArray<struct FTypedElementHandle>& InElementHandles, const struct FTypedElementSelectionOptions& InSelectionOptions);
	void OnChangeDynamic__DelegateSignature(const class UTypedElementSelectionSet* SelectionSet);
	void OnPreChangeDynamic__DelegateSignature(const class UTypedElementSelectionSet* SelectionSet);
	void RestoreSelectionState(const struct FTypedElementSelectionSetState& InSelectionState);
	bool SelectElement(const struct FTypedElementHandle& InElementHandle, const struct FTypedElementSelectionOptions& InSelectionOptions);
	bool SelectElements(const TArray<struct FTypedElementHandle>& InElementHandles, const struct FTypedElementSelectionOptions& InSelectionOptions);
	bool SetSelection(const TArray<struct FTypedElementHandle>& InElementHandles, const struct FTypedElementSelectionOptions& InSelectionOptions);

	bool AllowSelectionModifiers(const struct FTypedElementHandle& InElementHandle) const;
	bool CanDeselectElement(const struct FTypedElementHandle& InElementHandle, const struct FTypedElementSelectionOptions& InSelectionOptions) const;
	bool CanSelectElement(const struct FTypedElementHandle& InElementHandle, const struct FTypedElementSelectionOptions& InSelectionOptions) const;
	int32 CountSelectedElements(const TSubclassOf<class IInterface> InBaseInterfaceType) const;
	int32 CountSelectedObjects(const class UClass* InRequiredClass) const;
	class UObject* GetBottomSelectedObject(const class UClass* InRequiredClass) const;
	struct FTypedElementSelectionSetState GetCurrentSelectionState() const;
	int32 GetNumSelectedElements() const;
	TArray<struct FTypedElementHandle> GetSelectedElementHandles(const TSubclassOf<class IInterface> InBaseInterfaceType) const;
	TArray<class UObject*> GetSelectedObjects(const class UClass* InRequiredClass) const;
	struct FTypedElementHandle GetSelectionElement(const struct FTypedElementHandle& InElementHandle, const ETypedElementSelectionMethod InSelectionMethod) const;
	class UObject* GetTopSelectedObject(const class UClass* InRequiredClass) const;
	bool HasSelectedElements(const TSubclassOf<class IInterface> InBaseInterfaceType) const;
	bool HasSelectedObjects(const class UClass* InRequiredClass) const;
	bool IsElementSelected(const struct FTypedElementHandle& InElementHandle, const struct FTypedElementIsSelectedOptions& InSelectionOptions) const;

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"TypedElementSelectionSet">();
	}
	static class UTypedElementSelectionSet* GetDefaultObj()
	{
		return GetDefaultObjImpl<UTypedElementSelectionSet>();
	}
};

// Class TypedElementRuntime.TypedElementSelectionSetLibrary
// 0x0000 (0x0028 - 0x0028)
class UTypedElementSelectionSetLibrary final : public UObject
{
public:
	static bool DeselectElementsFromList(class UTypedElementSelectionSet* SelectionSet, const struct FTypedElementListProxy& ElementList, const struct FTypedElementSelectionOptions& SelectionOptions);
	static struct FTypedElementListProxy GetNormalizedElementList(class UTypedElementSelectionSet* SelectionSet, const struct FTypedElementListProxy& ElementList, const struct FTypedElementSelectionNormalizationOptions& NormalizationOptions);
	static struct FTypedElementListProxy GetNormalizedSelection(class UTypedElementSelectionSet* SelectionSet, const struct FTypedElementSelectionNormalizationOptions& NormalizationOptions);
	static bool SelectElementsFromList(class UTypedElementSelectionSet* SelectionSet, const struct FTypedElementListProxy& ElementList, const struct FTypedElementSelectionOptions& SelectionOptions);
	static bool SetSelectionFromList(class UTypedElementSelectionSet* SelectionSet, const struct FTypedElementListProxy& ElementList, const struct FTypedElementSelectionOptions& SelectionOptions);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"TypedElementSelectionSetLibrary">();
	}
	static class UTypedElementSelectionSetLibrary* GetDefaultObj()
	{
		return GetDefaultObjImpl<UTypedElementSelectionSetLibrary>();
	}
};

}

