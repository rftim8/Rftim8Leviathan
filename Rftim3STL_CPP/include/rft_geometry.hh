#pragma once
#include "rft_global_cpp.hh"

static long long getDimensionOfSquareRotatedBy90Degrees(int n)
{
    return 1 + (long long)n * (n - 1) * 2;
}
