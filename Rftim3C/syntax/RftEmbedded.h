/*
 * Library for embedded programming
 */

#ifndef Embedded_H_
#define Embedded_H_

 // Includes--------------------------------------------------------------------
#include "RftUI.h"
#include <limits.h>
//-----------------------------------------------------------------------------

// Macro's---------------------------------------------------------------------
#define LESS(x, y) ((x) < (y) ? (y) : (x))
#define INFINITE_LOOP for(;;)
#define INTERCHANGE(type, x, y){type t; t = x; x = y; y = t;}
#define DISPLAY(expr) printf(#expr " = %d\n", expr)
#define SHIFT_RIGHT(x, y) ((x) >> (y))
#define SHIFT_LEFT(x, y) ((x) << (y))
#define AND_FUNC(x, y) ((x) & (y))
#define OR_FUNC(x, y) ((x) | (y))
#define OR_EXCLUSIVE_FUNC(x, y) ((x) ^ (y))

#define NIBBLE 4            // signed -64...+63
							// unsigned 128
#define BYTE 8              // signed -128...+127
							// unsigned 256
#define WORD 16             // signed -32.768...+32.767
							// unsigned 65.536
#define DOUBLE_WORD 32      // signed 4.294.967.295
							// unsigned -2.147.483.648...+2.147.483.647
#define QUADWORD 64

#define DOUBLE_QUADWORD 128

//-----------------------------------------------------------------------------

#endif /* Embedded_H_ */
