#include "RftDouble.h"

void rftDouble()
{
    int s = sizeof(double);
    printf("Size of double: %d byte -> %d bits\n", s, s * 8);
}