// Libraries------------------------------------------------------------------
#include "../headers/Main.h"
//----------------------------------------------------------------------------

// Initialize LCD-------------------------------------------------------------
void lcd_init_4d(void)
{
    // Power-up delay
    _delay_ms(100);

    // Set up the RS and E lines for the 'lcd_write_4' subroutine.
    lcd_RS_port &= ~(1 << lcd_RS_bit); // select the Instruction Register (RS low)
    lcd_E_port &= ~(1 << lcd_E_bit);   // make sure E is initially low

    // Reset the LCD controller
    lcd_write_4(lcd_Reset);
    _delay_ms(10);

    lcd_write_4(lcd_Reset);
    _delay_us(200);

    lcd_write_4(lcd_Reset);
    _delay_us(200);

    lcd_write_4(lcd_Set_4_bit); // set 4-bit mode
    _delay_us(80);

    // Function Set instruction
    lcd_write_instruction_4d(lcd_Set_4_bit); // set mode, lines, and font
    _delay_us(80);

    // Display On/Off Control instruction
    lcd_write_instruction_4d(lcd_Display_OFF); // turn display OFF
    _delay_us(80);

    // Clear Display instruction
    lcd_write_instruction_4d(lcd_Clear); // clear display RAM
    _delay_ms(4);

    // Entry Mode Set instruction
    lcd_write_instruction_4d(lcd_Entry_Mode); // set desired shift characteristics
    _delay_us(80);

    // Display On/Off Control instruction
    lcd_write_instruction_4d(lcd_Display_ON); // turn the display ON
    _delay_us(80);
}
//-----------------------------------------------------------------------------------------