#include "rft_malloc.hh"

/**
 * Memory allocation dynamically (during runtime)
 *
 * consecutive addresses: one large block with size n * sizeof(m)
 * - faster than calloc
 * - high time efficiency
 * - no memory overhead
 */
void printRftMallocMain()
{
    int *ptr;
    int n, i;

    n = 5;
    std::cout << "Number of elements = " << n << "\n";

    ptr = (int *)malloc(n * sizeof(int));
    std::cout << ptr << "\n";
    std::cout << &ptr << "\n";

    if (ptr == NULL)
    {
        std::cout << "Memory not allocated.\n";
        exit(0);
    }
    else
    {
        std::cout << "Memory successfully assigned.\n";
        for (int i = 0; i < n; i++)
        {
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
