#pragma once
#include "rft_global_cpp.hh"

// Wilhelm Ackermann - recursion function test
// ! x <= y
static long ackermannTest(long x, long y)
{
    if (!x)
        return y + 1;
        
    if (!y)
        return ackermannTest(x - 1, 1);

    return ackermannTest(x - 1, ackermannTest(x, y - 1));
}