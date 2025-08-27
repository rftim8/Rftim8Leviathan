#include "RftOutput.h"

static void rftPutchar();

void rftOutput()
{
    rftPutchar();
}

// Putchar
static void rftPutchar()
{
    int c;

    while ((c = getchar()) != '\n')
    {
        putchar(c);
    }
}