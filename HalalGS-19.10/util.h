#pragma once

inline bool bDebugLog = true;

enum LogLevel {
    Log,
    Debug,
    Warning,
    Error
};

void WriteLog(const char* category, LogLevel level, const char* format, ...)
{
    const char* levelStr;

    if (!bDebugLog && level == LogLevel::Debug)
        return;

    switch (level) {
        case LogLevel::Log: levelStr = "Info"; break;
        case LogLevel::Debug: levelStr = "Debug"; break;
        case LogLevel::Warning: levelStr = "Warning"; break;
        case LogLevel::Error: levelStr = "Error"; break;
        default: levelStr = "Unknown"; break;
    }

    printf("HalalGS-19.10: %s: %s: ", category, levelStr);

    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    printf("\n");
}

#define FN_LOG(Category, Level, ...) WriteLog(#Category, Level, __VA_ARGS__)

enum ELoadFlags
{
    LOAD_None = 0x00000000,	///< No flags.
    LOAD_Async = 0x00000001,	///< Loads the package using async loading path/ reader
    LOAD_NoWarn = 0x00000002,	///< Don't display warning if load fails.
    LOAD_EditorOnly = 0x00000004,	///< Load for editor-only purposes and by editor-only code
    LOAD_ResolvingDeferredExports = 0x00000008,	///< Denotes that we should not defer export loading (as we're resolving them)
    LOAD_Verify = 0x00000010,	///< Only verify existance; don't actually load.
    //	LOAD_Unused						= 0x00000020,	///< Allow plain DLLs.
    //	LOAD_Unused						= 0x00000040
    LOAD_NoVerify = 0x00000080,   ///< Don't verify imports yet.
    LOAD_IsVerifying = 0x00000100,	///< Is verifying imports
    LOAD_SkipLoadImportedPackages = 0x00000200,	///< Assume that all import packages are already loaded and don't call LoadPackage when creating imports 
    //	LOAD_Unused						= 0x00000400,
    //	LOAD_Unused						= 0x00000800,
    LOAD_DisableDependencyPreloading = 0x00001000,	///< Bypass dependency preloading system
    LOAD_Quiet = 0x00002000,   ///< No log warnings.
    LOAD_FindIfFail = 0x00004000,	///< Tries FindObject if a linker cannot be obtained (e.g. package is currently being compiled)
    LOAD_MemoryReader = 0x00008000,	///< Loads the file into memory and serializes from there.
    LOAD_NoRedirects = 0x00010000,	///< Never follow redirects when loading objects; redirected loads will fail
    LOAD_ForDiff = 0x00020000,	///< Loading for diffing in the editor
    LOAD_PackageForPIE = 0x00080000,   ///< This package is being loaded for PIE, it must be flagged as such immediately
    LOAD_DeferDependencyLoads = 0x00100000,   ///< Do not load external (blueprint) dependencies (instead, track them for deferred loading)
    LOAD_ForFileDiff = 0x00200000,	///< Load the package (not for diffing in the editor), instead verify at the two packages serialized output are the same, if they are not then debug break so that you can get the callstack and object information
    LOAD_DisableCompileOnLoad = 0x00400000,	///< Prevent this load call from running compile on load for the loaded blueprint (intentionally not recursive, dependencies will still compile on load)
    LOAD_DisableEngineVersionChecks = 0x00800000,   ///< Prevent this load call from running engine version checks
};

template <typename T>
static T* StaticFindObject(const TCHAR* Name, bool ExactClass = false)
{
    // 7FF697199B40
    UObject* (*StaticFindObject)(UClass* Class, UObject* InOuter, const TCHAR* Name, bool ExactClass) = decltype(StaticFindObject)(0xBC9B40 + uintptr_t(GetModuleHandle(0)));
    return (T*)StaticFindObject(UObject::StaticClass(), nullptr, Name, ExactClass);
}

template <typename T>
static T* StaticLoadObject(const TCHAR* Name, const TCHAR* Filename = nullptr, uint32 LoadFlags = LOAD_None, UPackageMap* Sandbox = nullptr, bool bAllowObjectReconciliation = true)
{
    // 7FF697676B08
    UObject* (*StaticLoadObject)(UClass* Class, UObject* InOuter, const TCHAR* Name, const TCHAR* Filename, uint32 LoadFlags, UPackageMap* Sandbox, bool bAllowObjectReconciliation, __int64 a6) = decltype(StaticLoadObject)(0x10A6B08 + uintptr_t(GetModuleHandle(0)));
    return (T*)StaticLoadObject(T::StaticClass(), nullptr, Name, Filename, LoadFlags, Sandbox, bAllowObjectReconciliation, 0);
}

#define RESULT_PARAM Z_Param__Result
#define RESULT_DECL void*const RESULT_PARAM

#pragma pack(push, 0x1)
class alignas(0x08) FOutputDevice
{
public:
    uint8 Pad_01[0x10];
};
#pragma pack(pop)

struct FFrame : public FOutputDevice
{
public:
    UFunction* Node; // 0x10
    UObject* Object; // 0x18
    uint8* Code; // 0x20
    uint8* Locals; // 0x28

    UProperty* MostRecentProperty; // 0x30
    uint8* MostRecentPropertyAddress; // 0x38

    uint8 Pad_01[0x58];

public:
    void Step(UObject* Context, RESULT_DECL)
    {
        void (*Step)(FFrame* Frame, UObject* Context, RESULT_DECL) = decltype(Step)(0xccb6b8 + uintptr_t(GetModuleHandle(0)));
        Step(this, Context, RESULT_PARAM);
    }

    void StepExplicitProperty(void* const Result, UProperty* Property)
    {
        void (*StepExplicitProperty)(FFrame* Frame, void* const Result, UProperty* Property) = decltype(StepExplicitProperty)(0xcc9c90 + uintptr_t(GetModuleHandle(0)));
        StepExplicitProperty(this, Result, Property);
    }

    void StepCompiledIn(void* const Result)
    {
        // https://imgur.com/q5efUyh

        if (Code)
        {
            Step(Object, Result);
        }
        else
        {
            // https://imgur.com/a/CvmkuCy
            UProperty* Property = (UProperty*)(*(UField**)(__int64(this) + 0x80));
            *(UField**)(__int64(this) + 0x80) = Property->Next;

            StepExplicitProperty(Result, Property);
        }
    }

    template<typename TNativeType>
    TNativeType& StepCompiledInRef(void* const TemporaryBuffer)
    {
        MostRecentPropertyAddress = NULL;

        if (Code)
        {
            Step(Object, TemporaryBuffer);
        }
        else
        {
            // https://imgur.com/a/CvmkuCy
            UProperty* Property = (UProperty*)(*(UField**)(__int64(this) + 0x80));
            *(UField**)(__int64(this) + 0x80) = Property->Next;

            StepExplicitProperty(TemporaryBuffer, Property);
        }

        return (MostRecentPropertyAddress != NULL) ? *(TNativeType*)(MostRecentPropertyAddress) : *(TNativeType*)TemporaryBuffer;
    }
};

class Util
{
public:
    static AFortPlayerPawn* SpawnPlayer(AFortPlayerController* PlayerController, FVector Location, FRotator Rotation, bool NewPlayer = true)
    {
        if (!PlayerController || !PlayerController->GetWorld())
            return nullptr;

        AFortPlayerPawn* PlayerPawn = Cast<AFortPlayerPawn>(PlayerController->GetWorld()->SpawnActor(APlayerPawn_Athena_C::StaticClass(), &Location, &Rotation));

        if (!PlayerPawn)
        {
            FN_LOG(LogPlayer, Error, "Failed to spawn PlayerPawn!");
            return nullptr;
        }

        PlayerPawn->bCanBeDamaged = NewPlayer;
        PlayerPawn->Owner = PlayerController;
        PlayerPawn->OnRep_Owner();

        PlayerController->Pawn = PlayerPawn;
        PlayerController->OnRep_Pawn();
        PlayerController->Possess(PlayerPawn);

        if (NewPlayer)
        {
            AFortPlayerState* PlayerState = Cast<AFortPlayerState>(PlayerController->PlayerState);
            PlayerState->bHasFinishedLoading = true;
            PlayerState->bHasStartedPlaying = true;
            PlayerState->OnRep_bHasStartedPlaying();

            PlayerPawn->SetMaxHealth(100);
            PlayerPawn->SetHealth(100);
            PlayerPawn->SetMaxShield(100);
            PlayerPawn->SetShield(0);

            PlayerController->bIsDisconnecting = false;
            PlayerController->bHasClientFinishedLoading = true;
            PlayerController->bHasServerFinishedLoading = true;
            PlayerController->bHasInitiallySpawned = true;
        }

        return PlayerPawn;
    }
};