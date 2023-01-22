#include<Windows.h>
#include <iostream>

int main()
{
    for (int i = 0; i < 125; i++) {
        std::cout << GetCurrentProcessId() << std::endl;
        Sleep(1000);
    }
}