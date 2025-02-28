#include <windows.h>

#define BIAS_CONDITION_ADDRESS 0x00c63015
#define DAT_011ECBC0_ADDRESS 0x011ecbc0


DWORD WINAPI PatchDatThread(LPVOID lpParam) {
    //idr if this like just stops the game or actually waits lololol
    Sleep(3000);

    int* datValue = (int*)DAT_011ECBC0_ADDRESS;

    // Change memory protection
    DWORD oldProtect;
    if (VirtualProtect((LPVOID)DAT_011ECBC0_ADDRESS, sizeof(int), PAGE_EXECUTE_READWRITE, &oldProtect)) {
        // Force the value to 1
        *datValue = 1;

        // Restore original protection
        VirtualProtect((LPVOID)DAT_011ECBC0_ADDRESS, sizeof(int), oldProtect, &oldProtect);
    }

    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        // Apply jump patch
        DWORD oldProtect;
        if (VirtualProtect((LPVOID)BIAS_CONDITION_ADDRESS, 1, PAGE_EXECUTE_READWRITE, &oldProtect)) {
            *((BYTE*)BIAS_CONDITION_ADDRESS) = 0xEB;  // Change JZ to JMP
            VirtualProtect((LPVOID)BIAS_CONDITION_ADDRESS, 1, oldProtect, &oldProtect);
        }

        HANDLE hThread = CreateThread(NULL, 0, PatchDatThread, NULL, 0, NULL);
        if (hThread) {
            CloseHandle(hThread);
        }
    }
    return TRUE;
}
