#pragma once
#include "rft_global_c.h"

static void rftLong()
{
    int s = sizeof(long);

    printf("Size of long: %d byte -> %d bits\n", s, s * 8);
}
