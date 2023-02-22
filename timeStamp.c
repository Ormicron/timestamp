// timeStamp.c : This file contains the 'main' function. Program execution begins and ends there.
//
#include <windows.h>
#include <stdio.h>

BOOL SetFileToCurrentTime(HANDLE hsFile, HANDLE htFile) {
    FILETIME filestamp;
    BOOL f;
    FILETIME ftCreate, ftAccess, ftWrite;
    GetFileTime(hsFile, &ftCreate, &ftAccess, &ftWrite);
    f = SetFileTime(htFile,
        &ftCreate,
        &ftAccess,
        &ftWrite);


    return f;
}

HANDLE GetFileHandle(LPCSTR LfilePath) {
    HANDLE hFile = NULL;
    DWORD dwDesiredAccess = GENERIC_ALL;
    DWORD dwShareMode = 0;
    LPSECURITY_ATTRIBUTES IpSecurityAttributes = NULL;
    DWORD dwCreationDisposition = OPEN_EXISTING;
    DWORD dwFlagsAndAttributes = FILE_ATTRIBUTE_NORMAL;
    HANDLE hTemplateFile = 0;

    hFile = CreateFileA(LfilePath, dwDesiredAccess, dwShareMode, IpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);

    DWORD dw = GetLastError();
    if (dw != 0) {
        printf("ERROR Code:%d\n", dw);
        ExitProcess(dw);
    }

    return hFile;
}

int main(int argc, LPCTSTR* argv[]) {
    if (argc != 3) {
        printf("Example:\n TimeStamp.exe source.docx target.exe\n");
        ExitProcess(0);
    }



    HANDLE hSourceFile = GetFileHandle(argv[1]);
    HANDLE hTargetFile = GetFileHandle(argv[2]);
    if (SetFileToCurrentTime(hSourceFile, hTargetFile)) {
        printf("[+] Success\n");
    }
    else {
        printf("[-] Failed\n");
    }

    CloseHandle(hTargetFile);
    CloseHandle(hSourceFile);
    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
