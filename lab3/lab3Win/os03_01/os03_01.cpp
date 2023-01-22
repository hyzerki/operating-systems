#include<Windows.h>
#include <iostream>

int main()
{
    for (int i = 0; i < 1000; i++) {
        std::cout << GetCurrentProcessId() << std::endl;
        Sleep(2000);
    }
}