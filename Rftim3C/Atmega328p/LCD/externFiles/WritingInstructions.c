// Libraries----------------------------------------------------------------
#include "../headers/Main.h"
//---------------------------------------------------------------------------

// Writing instructions------------------------------------------------------
void lcd_write_instruction_4d(unsigned char theInstruction)
{
    lcd_RS_port &= ~(1 << lcd_RS_bit); // select the Instruction Register (RS low)
    lcd_E_port &= ~(1 << lcd_E_bit);   // make sure E is initially low
    lcd_write_4(theInstruction);       // write the upper 4-bits of the data
    lcd_write_4(theInstruction << 4);  // write the lower 4-bits of the data
}
//---------------------------------------------------------------------------