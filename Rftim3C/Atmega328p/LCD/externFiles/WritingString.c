// Libraries-------------------------------------------------------------------
#include "../headers/Main.h"
//-----------------------------------------------------------------------------

// Writing string to LCD-------------------------------------------------------
void lcd_write_string_4d(unsigned char theString[])
{
    volatile int i = 0;
    while (theString[i] != 0)
    {
        lcd_write_character_4d(theString[i]);
        i++;
        _delay_us(80);
    }
}
//-----------------------------------------------------------------------------