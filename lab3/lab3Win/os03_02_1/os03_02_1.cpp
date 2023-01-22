#include<Windows.h>
#include <iostream>

int main()
{
    for (int i = 0; i < 50; i++) {
        std::cout << GetCurrentProcessId() << std::endl;
        Sleep(1000);
    }
}