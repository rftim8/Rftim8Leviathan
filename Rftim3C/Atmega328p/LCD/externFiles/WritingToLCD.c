// Libraries-----------------------------------------------------------------
#include "../headers/Main.h"
//---------------------------------------------------------------------------

// Writing message-----------------------------------------------------------
void lcd_write_4(unsigned char theByte)
{
    lcd_D7_port &= ~(1 << lcd_D7_bit); // assume that data is '0'
    if (theByte & 1 << 7)
        lcd_D7_port |= (1 << lcd_D7_bit); // make data = '1' if necessary

    lcd_D6_port &= ~(1 << lcd_D6_bit); // repeat for each data bit
    if (theByte & 1 << 6)
        lcd_D6_port |= (1 << lcd_D6_bit);

    lcd_D5_port &= ~(1 << lcd_D5_bit);
    if (theByte & 1 << 5)
        lcd_D5_port |= (1 << lcd_D5_bit);

    lcd_D4_port &= ~(1 << lcd_D4_bit);
    if (theByte & 1 << 4)
        lcd_D4_port |= (1 << lcd_D4_bit);

    // write the data
    // 'Address set-up time' (40 nS)
    lcd_E_port |= (1 << lcd_E_bit);  // Enable pin high
    _delay_us(1);                    // implement 'Data set-up time' (80 nS) and 'Enable pulse width' (230 nS)
    lcd_E_port &= ~(1 << lcd_E_bit); // Enable pin low
    _delay_us(1);                    // implement 'Data hold time' (10 nS) and 'Enable cycle time' (500 nS)
}
//---------------------------------------------------------------------------