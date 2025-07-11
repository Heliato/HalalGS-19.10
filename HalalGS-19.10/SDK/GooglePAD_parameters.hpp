#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GooglePAD

#include "Basic.hpp"

#include "GooglePAD_structs.hpp"


namespace SDK::Params
{

// Function GooglePAD.GooglePADFunctionLibrary.CancelDownload
// 0x0018 (0x0018 - 0x0000)
struct GooglePADFunctionLibrary_CancelDownload final
{
public:
	TArray<class FString>                         AssetPacks;                                        // 0x0000(0x0010)(ConstParm, Parm, ZeroConstructor, NativeAccessSpecifierPublic)
	EGooglePADErrorCode                           ReturnValue;                                       // 0x0010(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_11[0x7];                                       // 0x0011(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function GooglePAD.GooglePADFunctionLibrary.GetAssetPackLocation
// 0x0018 (0x0018 - 0x0000)
struct GooglePADFunctionLibrary_GetAssetPackLocation final
{
public:
	class FString                                 Param_Name;                                        // 0x0000(0x0010)(Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         Location;                                          // 0x0010(0x0004)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	EGooglePADErrorCode                           ReturnValue;                                       // 0x0014(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_15[0x3];                                       // 0x0015(0x0003)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function GooglePAD.GooglePADFunctionLibrary.GetAssetsPath
// 0x0018 (0x0018 - 0x0000)
struct GooglePADFunctionLibrary_GetAssetsPath final
{
public:
	int32                                         Location;                                          // 0x0000(0x0004)(ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 ReturnValue;                                       // 0x0008(0x0010)(Parm, OutParm, ZeroConstructor, ReturnParm, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function GooglePAD.GooglePADFunctionLibrary.GetBytesDownloaded
// 0x0008 (0x0008 - 0x0000)
struct GooglePADFunctionLibrary_GetBytesDownloaded final
{
public:
	int32                                         State;                                             // 0x0000(0x0004)(ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         ReturnValue;                                       // 0x0004(0x0004)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function GooglePAD.GooglePADFunctionLibrary.GetDownloadState
// 0x0018 (0x0018 - 0x0000)
struct GooglePADFunctionLibrary_GetDownloadState final
{
public:
	class FString                                 Param_Name;                                        // 0x0000(0x0010)(Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         State;                                             // 0x0010(0x0004)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	EGooglePADErrorCode                           ReturnValue;                                       // 0x0014(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_15[0x3];                                       // 0x0015(0x0003)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function GooglePAD.GooglePADFunctionLibrary.GetDownloadStatus
// 0x0008 (0x0008 - 0x0000)
struct GooglePADFunctionLibrary_GetDownloadStatus final
{
public:
	int32                                         State;                                             // 0x0000(0x0004)(ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	EGooglePADDownloadStatus                      ReturnValue;                                       // 0x0004(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_5[0x3];                                        // 0x0005(0x0003)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function GooglePAD.GooglePADFunctionLibrary.GetShowCellularDataConfirmationStatus
// 0x0002 (0x0002 - 0x0000)
struct GooglePADFunctionLibrary_GetShowCellularDataConfirmationStatus final
{
public:
	EGooglePADCellularDataConfirmStatus           Status;                                            // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	EGooglePADErrorCode                           ReturnValue;                                       // 0x0001(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function GooglePAD.GooglePADFunctionLibrary.GetStorageMethod
// 0x0008 (0x0008 - 0x0000)
struct GooglePADFunctionLibrary_GetStorageMethod final
{
public:
	int32                                         Location;                                          // 0x0000(0x0004)(ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	EGooglePADStorageMethod                       ReturnValue;                                       // 0x0004(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_5[0x3];                                        // 0x0005(0x0003)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function GooglePAD.GooglePADFunctionLibrary.GetTotalBytesToDownload
// 0x0008 (0x0008 - 0x0000)
struct GooglePADFunctionLibrary_GetTotalBytesToDownload final
{
public:
	int32                                         State;                                             // 0x0000(0x0004)(ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         ReturnValue;                                       // 0x0004(0x0004)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function GooglePAD.GooglePADFunctionLibrary.ReleaseAssetPackLocation
// 0x0004 (0x0004 - 0x0000)
struct GooglePADFunctionLibrary_ReleaseAssetPackLocation final
{
public:
	int32                                         Location;                                          // 0x0000(0x0004)(ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function GooglePAD.GooglePADFunctionLibrary.ReleaseDownloadState
// 0x0004 (0x0004 - 0x0000)
struct GooglePADFunctionLibrary_ReleaseDownloadState final
{
public:
	int32                                         State;                                             // 0x0000(0x0004)(ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function GooglePAD.GooglePADFunctionLibrary.RequestDownload
// 0x0018 (0x0018 - 0x0000)
struct GooglePADFunctionLibrary_RequestDownload final
{
public:
	TArray<class FString>                         AssetPacks;                                        // 0x0000(0x0010)(ConstParm, Parm, ZeroConstructor, NativeAccessSpecifierPublic)
	EGooglePADErrorCode                           ReturnValue;                                       // 0x0010(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_11[0x7];                                       // 0x0011(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function GooglePAD.GooglePADFunctionLibrary.RequestInfo
// 0x0018 (0x0018 - 0x0000)
struct GooglePADFunctionLibrary_RequestInfo final
{
public:
	TArray<class FString>                         AssetPacks;                                        // 0x0000(0x0010)(ConstParm, Parm, ZeroConstructor, NativeAccessSpecifierPublic)
	EGooglePADErrorCode                           ReturnValue;                                       // 0x0010(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_11[0x7];                                       // 0x0011(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function GooglePAD.GooglePADFunctionLibrary.RequestRemoval
// 0x0018 (0x0018 - 0x0000)
struct GooglePADFunctionLibrary_RequestRemoval final
{
public:
	class FString                                 Param_Name;                                        // 0x0000(0x0010)(Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	EGooglePADErrorCode                           ReturnValue;                                       // 0x0010(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_11[0x7];                                       // 0x0011(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function GooglePAD.GooglePADFunctionLibrary.ShowCellularDataConfirmation
// 0x0001 (0x0001 - 0x0000)
struct GooglePADFunctionLibrary_ShowCellularDataConfirmation final
{
public:
	EGooglePADErrorCode                           ReturnValue;                                       // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

}

