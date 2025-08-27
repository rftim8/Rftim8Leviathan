/**
 * PORTS.c
 */

#include "main.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{

	unsigned char i; /* Define pull-ups and set outputs high */
	/* Define directions for port pins */
	PORTB = (1 << PORTB7) | (1 << PORTB6) | (1 << PORTB1) | (1 << PORTB0);
	DDRB = (1 << DDB3) | (1 << DDB2) | (1 << DDB1) | (1 << DDB0); /* Insert nop for synchronization*/
	asm("nop");													  /* Read port pins */

	i = PINB;

	while (1)
	{
	}
}
