#include<Windows.h>
#include <iostream>

int main()
{
	std::cout << GetCurrentProcessId() << std::endl;
	LPCWSTR str1 = L"..\\x64\\Debug\\os03_02_1.exe";
	LPCWSTR str2 = L"..\\x64\\Debug\\os03_02_1.exe";
	STARTUPINFO si1;
	STARTUPINFO si2;
	PROCESS_INFORMATION pi1;
	PROCESS_INFORMATION pi2;
	ZeroMemory(&si1, sizeof(STARTUPINFO));
	ZeroMemory(&si2, sizeof(STARTUPINFO));
	//ZeroMemory(&pi1, sizeof(PPROCESS_INFORMATION));
	si1.cb = sizeof(STARTUPINFO);
	si2.cb = sizeof(STARTUPINFO);
	//CreateProcess(str1, 0, 0, 0, FALSE, CREATE_NEW_CONSOLE, 0, 0, &si1, pi1)
	if (CreateProcess(str2, 0, 0, 0, FALSE, CREATE_NEW_CONSOLE, 0, 0, &si2, &pi2)) {
		std::cout << "Proc os03_02_2.exe successfully executed." << std::endl;
	}
	else {
		std::cout << "Process os03_02_2.exe was not created." << std::endl;
	}

	if (CreateProcess(str1, 0, 0, 0, FALSE, CREATE_NEW_CONSOLE, 0, 0, &si1, &pi1)) {
		std::cout << "Proc os03_02_1.exe successfully executed." << std::endl;
	}
	else {
		std::cout << "Process os03_02_1.exe was not created." << std::endl;
	}
	for (int i = 0; i < 100; i++) {
		std::cout << GetCurrentProcessId() << std::endl;
		Sleep(1000);
	}
}