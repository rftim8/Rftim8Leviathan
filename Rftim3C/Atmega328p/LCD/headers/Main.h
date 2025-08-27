#ifndef MICROCONTROLLERPROJECT_MAIN_H
#define MICROCONTROLLERPROJECT_MAIN_H

// Libraries------------------------------------------------------------------
#include <avr/io.h>
#include <util/delay.h>
//----------------------------------------------------------------------------

// Globals--------------------------------------------------------------------
#define lcd_D7_port PORTD // LCD D7 connection
#define lcd_D7_bit PORTD7
#define lcd_D7_ddr DDRD

#define lcd_D6_port PORTD // LCD D6 connection
#define lcd_D6_bit PORTD6
#define lcd_D6_ddr DDRD

#define lcd_D5_port PORTD // LCD D5 connection
#define lcd_D5_bit PORTD5
#define lcd_D5_ddr DDRD

#define lcd_D4_port PORTD // LCD D4 connection
#define lcd_D4_bit PORTD4
#define lcd_D4_ddr DDRD

#define lcd_E_port PORTB // Enable pin
#define lcd_E_bit PORTB1
#define lcd_E_ddr DDRB

#define lcd_RS_port PORTB // Register Select
#define lcd_RS_bit PORTB0
#define lcd_RS_ddr DDRB

#define lcd_Line_One 0x00 // start line 1
#define lcd_Line_Two 0x40 // start line 2
//----------------------------------------------------------------------------

// Utilities------------------------------------------------------------------
#define lcd_Clear 0b00000001
#define lcd_Home 0b00000010
#define lcd_Entry_Mode 0b00000110
#define lcd_Display_OFF 0b00001000
#define lcd_Display_ON 0b00001100
#define lcd_Reset 0b00110000
#define lcd_Set_4_bit 0b00101000
#define lcd_Cursor_Pos 0b10000000
//----------------------------------------------------------------------------

// Prototypes-----------------------------------------------------------------

extern void lcd_write_4(unsigned char);

extern void lcd_write_instruction_4d(unsigned char);

extern void lcd_write_character_4d(unsigned char);

extern void lcd_write_string_4d(unsigned char message[]);

extern void lcd_init_4d(void);

extern void controller();

//----------------------------------------------------------------------------

#endif // MICROCONTROLLERPROJECT_MAIN_H
