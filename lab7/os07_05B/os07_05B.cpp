﻿#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

int start;

int main() {
    start = clock();

    DWORD pid = GetCurrentProcessId();
    HANDLE hm = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"Event");

    hm == NULL ? cout << "OS07_05B: Open Error Event\n" : cout << "OS07_05B: Open Event\n";

    WaitForSingleObject(hm, INFINITE);
    for (int i = 1; i <= 90; i++) {
        cout << i << " OS07_05B pid = " << pid << ", time: " << clock() - start << endl;
        Sleep(100);
    }
    CloseHandle(hm);
    system("pause");
}