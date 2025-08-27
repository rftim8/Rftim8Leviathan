#pragma once
#include "rft_global_c.h"

static void rftFloat()
{
    int s = sizeof(float);
    printf("Size of float: %d byte -> %d bits\n", s, s * 8);

    float a = 12345.567890;
    printf("%f\n", a);
    printf("%6f\n", a);
    printf("%.2f\n", a);
    printf("%6.2f\n", a);
}
