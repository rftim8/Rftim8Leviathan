#include "RftShort.h"

void rftShort()
{
    int s = sizeof(short);
    
    printf("Size of short: %d byte -> %d bits\n", s, s * 8);
}