#pragma once
#include "rft_global_c.h"

static void rftDouble()
{
    int s = sizeof(double);
    printf("Size of double: %d byte -> %d bits\n", s, s * 8);
}

