#include "main.h"

/*Global Variables Declarations*/
unsigned char hours = 0;
unsigned char minutes = 0;
unsigned char seconds = 0;
char time[] = "00:00:00";

/*LCD function declarations */
void LCD_send_command(unsigned char);
void LCD_send_data(unsigned char);
void LCD_init();
void LCD_goto(unsigned char, unsigned char);
void LCD_print(char *);
void LCD_update_time();

int main()
{
	LCD_init();
	LCD_goto(1, 2);
	LCD_print("Ceas 1 secunda");
	LCD_goto(2, 4);
	LCD_print(time);

	LCD_CNTRL_PORT = (1 << SET_HOUR | 1 << SET_MINUTE);

	TCCR1B = (1 << CS12 | 1 << WGM12);
	OCR1A = 15625 - 1;
	TIMSK0 = 1 << OCIE1A;
	asm("nop");

	while (1)
	{
		if (!(LCD_CNTRL_PIN & (1 << SET_HOUR)))
		{
			hours++;
			if (hours > 23)
				hours = 0;
		}
		if (!(LCD_CNTRL_PIN & (1 << SET_MINUTE)))
		{
			minutes++;
			if (minutes > 59)
				minutes = 0;
		}
		_delay_ms(250);
	}
}

/* This function sends a command 'cmnd' to the LCD module*/
void LCD_send_command(unsigned char cmnd)
{
	LCD_DATA_PORT = cmnd;
	LCD_CNTRL_PORT &= ~(1 << LCD_RW_PIN);
	LCD_CNTRL_PORT &= ~(1 << LCD_RS_PIN);

	LCD_CNTRL_PORT |= (1 << LCD_ENABLE_PIN);
	_delay_us(2);
	LCD_CNTRL_PORT &= ~(1 << LCD_ENABLE_PIN);
	_delay_us(100);
}

/* This function sends the data 'data' to the LCD module*/
void LCD_send_data(unsigned char data)
{
	LCD_DATA_PORT = data;
	LCD_CNTRL_PORT &= ~(1 << LCD_RW_PIN);
	LCD_CNTRL_PORT |= (1 << LCD_RS_PIN);

	LCD_CNTRL_PORT |= (1 << LCD_ENABLE_PIN);
	_delay_us(2);
	LCD_CNTRL_PORT &= ~(1 << LCD_ENABLE_PIN);
	_delay_us(100);
}

void LCD_init()
{
	LCD_CNTRL_DDR = 0xFF;
	LCD_CNTRL_PORT = 0x00;
	LCD_DATA_DDR = 0xFF;
	LCD_DATA_PORT = 0x00;

	_delay_ms(10);
	LCD_send_command(0x38);
	LCD_send_command(0x0C);
	LCD_send_command(0x01);
	_delay_ms(10);
	LCD_send_command(0x06);
}

/* This function moves the cursor the line y column x on the LCD module*/
void LCD_goto(unsigned char y, unsigned char x)
{
	unsigned char firstAddress[] = {0x80, 0xC0, 0x94, 0xD4};

	LCD_send_command(firstAddress[y - 1] + x - 1);
	_delay_ms(10);
}

void LCD_print(char *string)
{
	unsigned char i = 0;

	while (string[i] != 0)
	{
		LCD_send_data(string[i]);
		i++;
	}
}
void LCD_update_time()
{
	char *temp = 0;

	LCD_goto(2, 4);

	itoa(hours / 10, temp, 10);
	LCD_print(temp);
	itoa(hours % 10, temp, 10);
	LCD_print(temp);
	LCD_print(":");

	itoa(minutes / 10, temp, 10);
	LCD_print(temp);
	itoa((minutes % 10), temp, 10);
	LCD_print(temp);
	LCD_print(":");

	itoa(seconds / 10, temp, 10);
	LCD_print(temp);
	itoa(seconds % 10, temp, 10);
	LCD_print(temp);
}
/*Timer Counter 1 Compare Match A Interrupt Service Routine/Interrupt Handler*/
ISR(TIMER1_COMPA_vect)
{
	seconds++;

	if (seconds == 60)
	{
		seconds = 0;
		minutes++;
	}
	if (minutes == 60)
	{
		minutes = 0;
		hours++;
	}
	if (hours > 23)
		hours = 0;

	LCD_update_time();
}