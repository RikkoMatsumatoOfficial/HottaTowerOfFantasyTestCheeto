// dllmain.cpp : Defines the entry point for the DLL application.
#include "Includes.hpp"

uintptr_t GetModuleHandle_Current() {
    return (uintptr_t)GetModuleHandleA("QRSL.exe");
}
void AllocateConsole() {
    FILE* fp;
    AllocConsole();
    freopen_s(&fp, "CONOUT$", "w", stdout);
    SetConsoleTitleA("HottaTestCheat by RikkoMatsumatoOfficial");
}
DWORD WINAPI Thr() 
{
    uintptr_t qrslmod = GetModuleHandle_Current();
    AllocateConsole();
    if (MinHookInit()) 
    {
        cout << "MinHook Successfully Initializated!!!" << endl;
    }
    else {
        cout << "Failed to Initializating MinHook!!!" << endl;
        Sleep(3000);
        exit(43);
    }
    MH_STATUS st;
    uintptr_t zx = qrslmod + SDK::Offsets::ProcessEvent;
    const char* err = MH_StatusToString(st);
    if (MH_CreateHook(reinterpret_cast<LPVOID*>(zx), &hProcessEvent, (LPVOID*)(&oProcessEvent)) == MH_OK) {
        cout << "Successfully Adding ProcessEvent hook!!!" << endl;
    }
    MH_EnableHook(reinterpret_cast<LPVOID*>(zx));
    return TRUE;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Thr, 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

