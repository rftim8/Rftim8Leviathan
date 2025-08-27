#pragma once
#include "rft_global_c.h"

static void getString()
{
    int c;
    int d = 0;

    while ((c = getchar()) != '\n')
    {
        putchar(c);
    }
}

static void rftTerminal()
{
    char *command = "dir";
    FILE *fpipe = _popen(command, "r");
    char line[256];
    
    while (fgets(line, sizeof(line), fpipe))
    {
        printf("%s", line);
    }
    
    _pclose(fpipe);
}