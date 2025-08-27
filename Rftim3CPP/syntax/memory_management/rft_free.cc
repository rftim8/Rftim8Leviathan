#include "rft_free.hh"

void printRftFreeMain()
{
    int *ptr, *ptr1;
    int n, i;

    n = 5;
    std::cout << "Number of elements = " << n << "\n";

    ptr = (int *)malloc(n * sizeof(int));
    ptr1 = (int *)calloc(n, sizeof(int));

    if (ptr == NULL || ptr1 == NULL)
    {
        std::cout << "Memory not allocated.\n";
        exit(0);
    }
    else
    {
        std::cout << "Memory successfully allocated using malloc.\n";

        free(ptr);
        std::cout << "Malloc memory successfully freed.\n";

        std::cout << "Memory successfully allocated using calloc.\n";

        free(ptr1);
        std::cout << "Calloc memory successfully freed.\n";
    }
}