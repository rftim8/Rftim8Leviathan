#include "rft_calloc.hh"

/**
 * Contiguous allocation
 *
 * consecutive addresses: n blocks each with sizeof(m)
 *
 * Differences:
 * - it initializes each block with '0'
 * - has two params compared to malloc
 * - slower than malloc
 * - low time efficiency
 * - adds extra overhead
 */
void printRftCallocMain()
{
    int *ptr;
    int n, i;

    n = 5;
    std::cout << "Number of elements = " << n << "\n";

    ptr = (int *)calloc(n, sizeof(int));
    std::cout << ptr << "\n";
    std::cout << &ptr << "\n";

    if (ptr == NULL)
    {
        std::cout << "Memory not allocated\n";
        exit(0);
    }
    else
    {
        std::cout << "Memory successfully assigned.\n";
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                ptr[i] = 23423;
            else
                ptr[i] = i + 1;
        }

        std::cout << "The elements of the array are:\n";
        for (int i = 0; i < n; i++)
        {
            std::cout << ptr[i] << " ";
            std::cout << &ptr[i] << "\n";
        }
    }
}
