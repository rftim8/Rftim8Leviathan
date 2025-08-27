#include "rft_memory.hh"

/**
 * high address
 *
 * 0. Stack -> non-static, local variables
 *      |
 *      v
 *
 *      ^
 *      |
 * 1. Heap -> dynamically allocated
 * 2. Uninitialized data (bss -> block started by symbol) -> data initialized by the kernel with 0 before the program starts to execute the uninitialized data
 * 3. Initialized data -> global, static variables
 *  - read-only
 *  - read-write
 * 3. text -> code segment
 *
 * low address
 *
 * 2 -> initialized to zero by exec
 * 3 -> read from program file by exec
 */
void printRftMemory()
{
    printBasicNewDelete();
    printBlockMemory();
}

static void printBasicNewDelete()
{
    int *p = new int(10);
    // *p = 10;
    float *q = new float(75.25);
    cust *var = new cust(25);

    std::cout << *p << " " << *q << " " << var->p << "\n";
    std::cout << "Address: " << p << "\n";
    std::cout << "Value: " << *p << "\n";
}

static void printBlockMemory()
{
    int *p = NULL;
    p = new (std::nothrow) int;

    if (!p)
        std::cout << "Memory allocation failed.\n";
    else
    {
        *p = 29;
        std::cout << "Value of p: " << *p << "\n";
    }

    float *r = new float(75.25);
    std::cout << "Value of r: " << *r << "\n";

    int n = 5;
    int *q = new (std::nothrow) int[n];

    if (!q)
        std::cout << "Memory allocation failed: ";
    else
    {
        for (int i = 0; i < n; i++)
        {
            q[i] = i + 1;
        }

        std::cout << "Value store in block of memory: ";
        for (int i = 0; i < n; i++)
        {
            std::cout << q[i] << " ";
        }
        std::cout << "\n";
    }

    delete p;
    delete r;
    delete[] q;
}
