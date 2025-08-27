// Libraries-------------------------------------------------------------
#include "../headers/Main.h"
//-----------------------------------------------------------------------

// Writing character-----------------------------------------------------
void lcd_write_character_4d(unsigned char theData)
{
    lcd_RS_port |= (1 << lcd_RS_bit); // select the Data Register (RS high)
    lcd_E_port &= ~(1 << lcd_E_bit);  // make sure E is initially low
    lcd_write_4(theData);             // write the upper 4-bits of the data
    lcd_write_4(theData << 4);        // write the lower 4-bits of the data
}
//-----------------------------------------------------------------------