#pragma once
#include "rft_global_cpp.hh"

static bool isNumberASumOfPowersOfN(int number, int n)
{
    int max_power = 0;

    while (pow(n, max_power) <= number)
    {
        max_power++;
    }

    while (number > 0)
    {
        if (number >= pow(n, max_power))
            number -= pow(n, max_power);

        if (number >= pow(n, max_power))
            return false;

            max_power--;
    }

    return true;
}
