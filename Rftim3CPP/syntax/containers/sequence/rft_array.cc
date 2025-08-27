#include "rft_array.hh"

void printArray()
{
    int a0[5];
    initializeInt1DArray(std::size(a0), a0);
    printInt1DArrayByPointer(std::size(a0), a0);
    RFT_SEPARATOR

    int a1[] = {123, 12, 34, 32, 4, 23, 2412, 3, 314, 8};
    printInt1DArrayByPointer(std::size(a1), a1);
    RFT_SEPARATOR

    printInt1DArrayByRef(std::size(a1), a1);
    RFT_SEPARATOR

    int a2[][5] = {
        {123, 12, 34, 32, 4},
        {23, 2412, 3, 314, 8},
        {},
        {},
        {}};
    printInt2DArrayByPointer(std::size(a2), std::size(a2[0]), a2);
    RFT_SEPARATOR

    printInt2DArrayByRef(std::size(a2), std::size(a2[0]), a2);
    RFT_SEPARATOR

    print1DArrayByPointer(std::size(a1), a1);
    RFT_SEPARATOR
}

static void initializeInt1DArray(int n, int *p)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Value at " << i << ": ";
        std::cin >> p[i];
    }
}

static void printInt1DArrayByPointer(int n, int *p)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << p[i] << " ";
    }
}

static void printInt1DArrayByRef(int n, int (&arr)[])
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
}

static void printInt2DArrayByPointer(int rows, int columns, int (*p)[5])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << p[i][j] << " ";
        }
        std::cout << "\n";
    }
}

static void printInt2DArrayByRef(int rows, int columns, int (&arr)[][5])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void print1DArrayByPointer(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        std::cout << *(a + i) << " ";
    }
    std::cout << "\n";
}
