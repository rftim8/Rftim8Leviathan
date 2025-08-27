#pragma once
#include "rft_global_c.h"

static void rftChar()
{
    int s = sizeof(char);
    printf("Size of char: %d byte -> %d bits\n", s, s * 8);
}
