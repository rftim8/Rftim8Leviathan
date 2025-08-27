#include "rft_realloc.hh"

void printRftReallocMain()
{
    int *ptr;
    int n, i;

    n = 5;
    std::cout << "Number of elements = " << n << "\n";

    ptr = (int *)calloc(n, sizeof(int));

    if (ptr == NULL)
    {
        std::cout << "Memory not allocated\n";
        exit(0);
    }
    else
    {
        std::cout << "Memory successfully allocated using calloc.\n";
        for (int i = 0; i < n; i++)
        {
            ptr[i] = i + 1;
        }

        std::cout << "The elements of the array are: ";
        for (int i = 0; i < n; i++)
        {
            std::cout << ptr[i] << " ";
        }
        std::cout << "\n";

        n = 10;
        std::cout << "New array size = " << n << "\n";

        ptr = (int *)realloc(ptr, n * sizeof(int));
        std::cout << "Memory successfully re-allocated using realloc.\n";

        for (int i = 5; i < n; i++)
        {
            ptr[i] = i + 1;
        }

        std::cout << "Elements of the array are: ";
        for (int i = 0; i < n; i++)
        {
            std::cout << ptr[i] << " ";
        }
        std::cout << "\n";
        free(ptr);
    }
}
