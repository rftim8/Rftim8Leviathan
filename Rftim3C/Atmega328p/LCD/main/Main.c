// Libraries------------------------------------------------------------------
#include "../headers/Main.h"
//----------------------------------------------------------------------------

// Message--------------------------------------------------------------------
unsigned char message[] = "AVR Embedded";
//----------------------------------------------------------------------------

// Main method----------------------------------------------------------------
int main()
{

	controller();

	while (1)
		;
	return 0;
}
//----------------------------------------------------------------------------

// Project controller---------------------------------------------------------
void controller()
{

	// configure the microprocessor pins for the data lines
	lcd_D7_ddr |= (1 << lcd_D7_bit); // 4 data lines - output
	lcd_D6_ddr |= (1 << lcd_D6_bit);
	lcd_D5_ddr |= (1 << lcd_D5_bit);
	lcd_D4_ddr |= (1 << lcd_D4_bit);

	// configure the microprocessor pins for the control lines
	lcd_E_ddr |= (1 << lcd_E_bit);	 // E line - output
	lcd_RS_ddr |= (1 << lcd_RS_bit); // RS line - output

	// initialize the LCD controller as determined by the defines (LCD instructions)
	lcd_init_4d(); // initialize the LCD display for a 4-bit interface

	// display the first line of information
	lcd_write_string_4d(message);

	// set cursor to start of second line
	lcd_write_instruction_4d(lcd_Cursor_Pos | lcd_Line_Two);
	_delay_us(80);

	// display the second line of information
	lcd_write_string_4d(message);
}
//----------------------------------------------------------------------------
