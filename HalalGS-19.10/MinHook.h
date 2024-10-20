#pragma once
#include "util.h"

namespace MinHook
{
    static uintptr_t FindIndexVTable(UObject* Class, uintptr_t FuncOffset, int32 MaxIndex = 1000)
    {
        if (!Class)
        {
            FN_LOG(LogMinHook, Log, "Class not found!");
            return -1;
        }

        uintptr_t Index = 0x0;

        for (int32 i = 0; i < MaxIndex; i++)
        {
            uintptr_t FuncCallAddress = uintptr_t(Class->VTable[Index]);
            uintptr_t Offset = FuncCallAddress - InSDKUtils::GetImageBase();
            
            // Index Found!
            if (Offset == FuncOffset)
            {
                FN_LOG(LogHook, Debug, "Index Found: 0x%llx", (unsigned long long)Index);

                return Index;
            }

            uintptr_t IdaAddress = Offset + 0x7FF6965D0000ULL;

            FN_LOG(LogHook, Debug, "Index not found: 0x%llx, Offset: 0x%llx, IdaAddress [%p]", (unsigned long long)Index, (unsigned long long)Offset, IdaAddress);

            Index++;
        }

        return -1;
    }

    static void HookVTable(UObject* Class, int Index, void* FuncHook, void** FuncOG, const std::string& FuncName)
    {
        if (!Class)
        {
            FN_LOG(LogMinHook, Log, "Class not found!");
            return;
        }

        uintptr_t Address = uintptr_t(Class->VTable[Index]);

        if (FuncOG)
            *FuncOG = Class->VTable[Index];

        DWORD dwProtection;
        VirtualProtect(&Class->VTable[Index], 8, PAGE_EXECUTE_READWRITE, &dwProtection);

        Class->VTable[Index] = FuncHook;

        DWORD dwTemp;
        VirtualProtect(&Class->VTable[Index], 8, dwProtection, &dwTemp);

        uintptr_t Offset = Address - InSDKUtils::GetImageBase();
        uintptr_t IdaAddress = Offset + 0x7FF6965D0000ULL;

        FN_LOG(LogMinHook, Log, "Function VTable [%s] successfully hooked with Offset [0x%llx], IdaAddress [%p]", FuncName.c_str(), (unsigned long long)Offset, IdaAddress);
    }

    static void HookFunctionExec(UFunction* Function, void* FuncHook, void** FuncOG)
    {
        if (!Function)
        {
            FN_LOG(LogMinHook, Log, "Function not found!");
            return;
        }

        auto& ExecFunction = Function->ExecFunction;

        uintptr_t Offset = uintptr_t(ExecFunction) - InSDKUtils::GetImageBase();
        uintptr_t IdaAddress = Offset + 0x7FF6965D0000ULL;

        FN_LOG(LogMinHook, Log, "Function Exec [%s] successfully hooked with Offset [0x%llx], IdaAddress [%p]", Function->GetName().c_str(), (unsigned long long)Offset, IdaAddress);

        if (FuncOG)
            *FuncOG = ExecFunction;

        ExecFunction = (UFunction::FNativeFuncPtr)FuncHook;
    }

    static uintptr_t FindPattern(const char* signature, bool bRelative = false, uint32_t offset = 0)
    {
        uintptr_t base_address = reinterpret_cast<uintptr_t>(GetModuleHandle(NULL));
        static auto patternToByte = [](const char* pattern)
            {
                auto bytes = std::vector<int>{};
                const auto start = const_cast<char*>(pattern);
                const auto end = const_cast<char*>(pattern) + strlen(pattern);

                for (auto current = start; current < end; ++current)
                {
                    if (*current == '?')
                    {
                        ++current;
                        if (*current == '?')
                            ++current;
                        bytes.push_back(-1);
                    }
                    else
                    {
                        bytes.push_back(strtoul(current, &current, 16));
                    }
                }
                return bytes;
            };

        const auto dosHeader = (PIMAGE_DOS_HEADER)base_address;
        const auto ntHeaders = (PIMAGE_NT_HEADERS)((std::uint8_t*)base_address + dosHeader->e_lfanew);

        const auto sizeOfImage = ntHeaders->OptionalHeader.SizeOfImage;
        auto patternBytes = patternToByte(signature);
        const auto scanBytes = reinterpret_cast<std::uint8_t*>(base_address);

        const auto s = patternBytes.size();
        const auto d = patternBytes.data();

        for (auto i = 0ul; i < sizeOfImage - s; ++i)
        {
            bool found = true;
            for (auto j = 0ul; j < s; ++j)
            {
                if (scanBytes[i + j] != d[j] && d[j] != -1)
                {
                    found = false;
                    break;
                }
            }
            if (found)
            {
                uintptr_t address = reinterpret_cast<uintptr_t>(&scanBytes[i]);
                if (bRelative)
                {
                    address = ((address + offset + 4) + *(int32_t*)(address + offset));
                    return address;
                }

                return address;
            }
        }

        return NULL;
    }
}