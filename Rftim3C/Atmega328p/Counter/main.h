#define F_CPU 1600000UL
#include <util/delay.h>
#include <avr/io.h>
#include <string.h>
#include <avr/interrupt.h>

/*Timer Counter 1 Compare Match A Interrupt Service Routine/Interrupt Handler*/
ISR(TIMER1_COMPA_vect);

#define LCD_DATA_PORT PORTB
#define LCD_DATA_DDR DDRB
#define LCD_DATA_PIN PINB

#define LCD_CNTRL_PORT PORTD
#define LCD_CNTRL_DDR DDRD
#define LCD_CNTRL_PIN PIND

#define LCD_RS_PIN 5
#define LCD_RW_PIN 6
#define LCD_ENABLE_PIN 7
#define SET_HOUR 3
#define SET_MINUTE 4