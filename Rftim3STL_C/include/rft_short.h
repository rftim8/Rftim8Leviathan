#pragma once
#include "rft_global_c.h"

static void rftShort()
{
    int s = sizeof(short);

    printf("Size of short: %d byte -> %d bits\n", s, s * 8);
}
