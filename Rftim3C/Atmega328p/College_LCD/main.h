/*Frecventa CPU*/
#define F_CPU 1200000UL

/*Librarii*/
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

/*Pinul de date 7 al LCD-ului*/
#define lcd_D7_port PORTD
#define lcd_D7_bit PORTD7
#define lcd_D7_ddr DDRD

/*Pinul de date 6 al LCD-ului*/
#define lcd_D6_port PORTD
#define lcd_D6_bit PORTD6
#define lcd_D6_ddr DDRD

/*Pinul de date 5 al LCD-ului*/
#define lcd_D5_port PORTD
#define lcd_D5_bit PORTD5
#define lcd_D5_ddr DDRD

/*Pinul de date 4 al LCD-ului*/
#define lcd_D4_port PORTD
#define lcd_D4_bit PORTD4
#define lcd_D4_ddr DDRD

/*Pinul enable*/
#define lcd_E_port PORTB
#define lcd_E_bit PORTB1
#define lcd_E_ddr DDRB

/*Pinul register select*/
#define lcd_RS_port PORTB
#define lcd_RS_bit PORTB0
#define lcd_RS_ddr DDRB

/*Setarea cursorului pentru afisare*/
#define lcd_rand_2 0x40           // inceput rand 2
#define lcd_rand_2_pozitie_8 0x47 // rand 2 pozitie 8

/*Comenzi utilizand bitii porturilor D ale microprocesorului*/
#define lcd_sterge 0b00000001
#define lcd_stare 0b00000110
#define lcd_stins 0b00001000
#define lcd_aprins 0b00001100
#define lcd_reset 0b00110000
#define lcd_4_biti 0b00101000
#define lcd_pozitie_cursor 0b10000000