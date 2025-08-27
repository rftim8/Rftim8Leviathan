#pragma once
#include "rft_global_cpp.hh"

// Kadane's algorithm
static int getMaxSumOfContiguousSubarray(std::vector<int> v)
{
    int maxCrt = v[0];
    int maxEnd = v[0];

    for (int i = 1; i < v.size(); i++)
    {
        maxEnd = std::max(v[i], maxEnd + v[i]);
        maxCrt = std::max(maxCrt, maxEnd);
    }

    return maxCrt;
}
