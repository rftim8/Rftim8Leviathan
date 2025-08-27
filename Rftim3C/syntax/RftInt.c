#include "RftInt.h"

void rftInt()
{
    int s = sizeof(int);
    printf("Size of int: %d byte -> %d bits\n", s, s * 8);

    int a = 1234;
    printf("%d\n", a);
    printf("%8d\n", a);
}