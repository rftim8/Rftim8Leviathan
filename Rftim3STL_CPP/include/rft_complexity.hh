#pragma once
#include "rft_global_cpp.hh"

#pragma region Space

#pragma endregion

static void geometric(int n)
{
    if (n == 1)
        return;
    geometric(n - 1);
    geometric(n - 1);
}

#pragma region Time
static void printTimeComplexityMain()
{
    std::cout << "Time complexity\n";

#pragma region Polynomial - efficient
// n is large: constant O(1)

// n is large: logarithmic O(log n) -> two pointers

// square root algorithm O(sqrt(n))

// n <= 10^6: linear O(n)

// n <= 10^6: efficient sorting O(n * log n)

// n <= 5000: quadratic O(n^2) -> pairs
#pragma region O(n^2)
    int n = 1;

    for (int i = 0; i < n; i++)
    {
    }

    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < n; i++)
        {
        }
    }

    for (int i = 0; i < n; i++)
    {
    }

#pragma endregion

    // n <= 500: cubic O(n^3) -> pairs

#pragma region O(n*m)
    int m = 1;
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < m; i++)
        {
        }
    }

#pragma endregion
#pragma endregion

#pragma region Non-Polynomial NP-hard
// n <= 20: iteration through all subsets O(2^n)
#pragma region O(2^n)
    geometric(n);
#pragma endregion

// n <= 10: O(n!) -> permutations
#pragma endregion
}
#pragma endregion
