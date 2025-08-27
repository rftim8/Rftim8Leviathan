#pragma once
#include "rft_global_c.h"

#pragma region coinCombinations
static int s = 150;
static int n = 6;
static int mod[6];
static int m[6] = {500, 100, 50, 10, 5, 1};
static int sol = 0;

static void show_0()
{
    int i;
    sol++;

    printf("Coins:   ");

    for (i = 0; i < n; i++)
        printf("%03d  ", m[i]);

    printf("\n");

    printf("Solution %d:  ", sol);

    for (i = 0; i < n; i++)
        printf("%03d ", mod[i]);

    printf("\n");
    printf("\n");
}

static int valid_0()
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum = sum + mod[i] * m[i];

    return sum == s;
}

static void back(int k)
{
    int j;

    if (k < n)
    {
        for (j = 0; j < s; j++)
        {
            mod[k] = j;
            back(k + 1);
        }
    }
    else
    {
        if (valid_0())
            show_0();
    }
}

static void coinCombinations()
{
    back(0);
}
#pragma endregion

#pragma region Combinations
static int p = 0;
static int tab[256];

static void print()
{
    int i, j;
    p++;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (tab[i] == j)
                printf("D");
            else
                printf("*");
        }

        printf("\n");
    }

    printf("\n");
}

static int absolute(int x)
{
    return x > 0 ? x : -x;
}

static int valid(int k, int i)
{
    int j;

    for (j = 0; j < k; j++)
    {
        if (tab[j] == i)
            return 0;

        if (abs(j - k) == abs(tab[j] - i))
            return 0;
    }

    return 1;
}

static void numbers(int k)
{
    int i;

    if (k < n)
    {
        for (i = 0; i < n; i++)
        {
            if (valid(k, i))
            {
                tab[k] = i;
                numbers(k + 1);
            }
        }
    }
    else
        print();
}

static void combinations()
{
    printf("Enter number: ");
    scanf_s("%d", &n);
    numbers(0);
    printf("There are %d posibilities.\n", p);
}

#pragma endregion

#pragma region Factorial
// 0!=1
// n!=n*(n-1)!

static int factorial(int n)
{
    int i = 1;

    if (n == 0)
        return i;
    else
        return n * factorial(n - 1);
}

static void mainFactorial()
{
    int n = 0;

    printf("Enter N=");
    scanf_s("%d", &n);
    printf("%d\n", factorial(n));
}

#pragma endregion

#pragma region NCombinations
static int m0, n0;
static int tab[256];

static void print0()
{
    for (int i = 0; i < n0; i++)
        printf("%d ", tab[i]);

    printf("\n");
}

static int valid_1(int p)
{
    if (p > 0)
    {
        for (int i = 0; i < p; i++)
        {
            if (tab[i] == tab[p])
            {
                // retrun 0;
            }
        }
    }

    return 1;
}

static void combinations0(int k)
{
    int i;

    if (k < n0)
    {
        for (i = 1; i <= m0; i++)
        {
            tab[k] = i;

            if (valid_1(k))
                combinations0(k + 1);
        }
    }
    else
        print0();
}

static void nCombinations()
{
    printf("M Combinations of N numbers...\n");
    printf("Enter M=");
    scanf_s("%d", &m0);
    printf("Enter N=");
    scanf_s("%d", &n0);
    combinations0(0);
}

#pragma endregion
