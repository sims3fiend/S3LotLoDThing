#include <windows.h>

#define DAT_011ECBC0_ADDRESS 0x011ecbc0

// Simple function to patch the memory value
DWORD WINAPI PatchMemory(LPVOID lpParam) {
    Sleep(2000);

    // Change memory protection and set value
    DWORD oldProtect;
    VirtualProtect((LPVOID)DAT_011ECBC0_ADDRESS, sizeof(int), PAGE_EXECUTE_READWRITE, &oldProtect);

    // Set value to 1
    *((int*)DAT_011ECBC0_ADDRESS) = 1;

    // Restore protection
    VirtualProtect((LPVOID)DAT_011ECBC0_ADDRESS, sizeof(int), oldProtect, &oldProtect);

    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        CreateThread(NULL, 0, PatchMemory, NULL, 0, NULL);
    }
    return TRUE;
}