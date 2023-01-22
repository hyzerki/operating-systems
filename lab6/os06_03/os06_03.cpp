#include <Windows.h>
#include <iostream>

#define KB (1024)
#define PG (4 * KB)

int main()
{
    int pg = 256;
    int arraySize = pg * PG / 4;

    //М CC
    //е E5
    //л EB
    //cc = 204 e5e = 3678
    //204 * PG +3678 = 0x000CCE5E

    LPVOID xmemaddr = NULL;
    if (xmemaddr = VirtualAlloc(NULL, pg * PG, MEM_COMMIT, PAGE_READWRITE)) {
        //start address, size(bytes), protection
        std::cout << "--" << pg << "pages, VirtualAlloc = " << std::hex << xmemaddr << std::dec << "\n\n";

        int* m1 = new (xmemaddr) int[arraySize];
        for (int i = 0; i < arraySize; i++) {
            m1[i] = i;
        }
        system("pause");
    }
}