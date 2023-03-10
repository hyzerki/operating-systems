#include <Windows.h>
#include <iostream>

using namespace std;

void main()
{
    int start = clock();
    DWORD pid = GetCurrentProcessId();
    HANDLE hm = CreateMutexW(NULL, FALSE, L"Mutex");

    LPCWSTR an1 = L"os07_03A.exe";
    LPCWSTR an2 = L"os07_03B.exe";

    STARTUPINFO si1;
    STARTUPINFO si2;
    PROCESS_INFORMATION pi1;
    PROCESS_INFORMATION pi2;
    ZeroMemory(&si1, sizeof(STARTUPINFO));
    ZeroMemory(&si2, sizeof(STARTUPINFO));
    si1.cb = sizeof(STARTUPINFO);
    si2.cb = sizeof(STARTUPINFO);

    if (CreateProcess(an1, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si1, &pi1))
        cout << "--Process OS07_03A created\n";
    else cout << "--Process OS07_03A not created\n";

    if (CreateProcess(an2, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si2, &pi2))
        cout << "--Process OS07_03B created\n";
    else cout << "--Process OS07_03B not created\n";

    for (int i = 1; i <= 90; i++) {
        if (i == 30) {
            cout << i << "------------WaitForSingleObject MAIN------------" << endl;
            WaitForSingleObject(hm, INFINITE);
        }
        if (i == 60) {
            cout << i << "------------ReleaseMutex MAIN------------" << endl;
            ReleaseMutex(hm);
        }
        cout << i << " OS07_03 pid = " << pid << ", time: " << clock() - start << endl;
        Sleep(100);
    }

    WaitForSingleObject(pi1.hProcess, INFINITE);
    WaitForSingleObject(pi2.hProcess, INFINITE);
    CloseHandle(hm);
    CloseHandle(pi1.hProcess);
    CloseHandle(pi2.hProcess);
    system("pause");
}