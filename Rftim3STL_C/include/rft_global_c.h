#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define IN 1
#define OUT 0
#define MAXLINE 1000
#define COMPARE_VALUES(x, y) ((x) < (y) ? (y) : (x))

// UI -------------------------------------------------------------------------
#define SEPARATOR printf("\n\n");
#define TITLE(title) printf("----------   %s   ----------", title);
#define BREAKPOINT printf("--------------------------------------------------");
//-----------------------------------------------------------------------------

#define LESS(x, y) ((x) < (y) ? (y) : (x))
#define INFINITE_LOOP for (;;)
#define INTERCHANGE(type, x, y) \
    {                           \
        type t;                 \
        t = x;                  \
        x = y;                  \
        y = t;                  \
    }
#define DISPLAY(expr) printf(#expr " = %d\n", expr)
#define SHIFT_RIGHT(x, y) ((x) >> (y))
#define SHIFT_LEFT(x, y) ((x) << (y))
#define AND_FUNC(x, y) ((x) & (y))
#define OR_FUNC(x, y) ((x) | (y))
#define OR_EXCLUSIVE_FUNC(x, y) ((x) ^ (y))

#define NIBBLE 4       // signed -64...+63
                       // unsigned 128
#define BYTE 8         // signed -128...+127
                       // unsigned 256
#define WORD 16        // signed -32.768...+32.767
                       // unsigned 65.536
#define DOUBLE_WORD 32 // signed 4.294.967.295
                       // unsigned -2.147.483.648...+2.147.483.647
#define QUADWORD 64

#define DOUBLE_QUADWORD 128

#define FAHR_TO_CELSIUS(y) printf("Celsius: %d", 5 * (y - 32) / 9);
#define CELSIUS_TO_FAHR(y) printf("Fahrenheit: %d", y * 9 / 5 + 32);
