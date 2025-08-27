#include "RftInput.h"

static void rftGetchar();

void rftInput()
{
    // rftGetchar();
}

// Getchar
static void rftGetchar()
{
    int c;
    int d = 0;

    while ((c = getchar()) != '\n')
    {
        putchar(c);
    }
}