#include "RftLong.h"

void rftLong()
{
    int s = sizeof(long);
    
    printf("Size of long: %d byte -> %d bits\n", s, s * 8);
}