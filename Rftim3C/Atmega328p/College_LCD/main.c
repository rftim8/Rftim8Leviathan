/**
Student: Remus Flavius TIMBULI
Profil: AC-ID
An: II
Grupa: 2
Tema: Sa se programeze un ceas de 1 secunda utilizind timerul T1
si sa se afiseze ceasul pe un afisaj cu cristale lichide
(LCD cu 2 linii si 16 caractere pe linie).
Pentru memorarea ceasului se foloseste o variabila pe un octet
(unsigned char). Ceasul numara intre 00 si 59 (la depasire se
revine la 0). Afisarea informatiilor pe LCD se realizeaza
utilizind o biblioteca de functii C descrisa in fisierul Anexa 2.
Afisarea se face astfel:
- Pe prima linie se scrie textul: Ceas 1 secunda
- Pe a doua linie se afiseaza valoarea din pozitia (2,8):
 -------XX------
Frecventa de tact este de 12MHz.


Fisierul transmis de student trebuie sa contina:
- Enuntul temei
- Resursele microcontrolerului utilizate in aplicatie
si modul lor de programare
- Descrierea functiilor utilizate in limbaj C
(prototip, parametrii, functiune)
- Codul comentat al programului

Microcontroller utilizat: Atmega328P 8-bit
IDE utilizat: Atmel Studio 7.0
Programator: Raspberry Pi3 cu ajutorul pinilor GPIO
Modalitate de flash a microcontrolerului: "bitbang" cu avrdude
Componente utilizate: LCD 2x16, potentiometru(contrast-LCD),
breadboard, cabluri(mama-tata, tata-tata)
*/

/*Librarii*/
#include "main.h"

/*Prototipuri*/
void lcd_initializare_4biti();
void lcd_activare_output(unsigned char);
void lcd_stocare_mesaj(unsigned char);
void lcd_comanda(unsigned char);
void lcd_afisare_mesaj(unsigned char[]);
void lcd_afisare_timp();
void controller();

/*Message*/
unsigned char mesaj1[] = " Ceas 1 secunda ";

/*Variabila globala pentru construirea ceasului*/
unsigned char secunde = 0;

/*Functia principala*/
int main()
{

	while (1)
	{
		/*Incrementarea secundelor*/
		secunde++;
		if (secunde > 59)
			secunde = 0;

		controller();

		/*Afisarea timpului*/
		lcd_afisare_timp();
		lcd_afisare_mesaj("------");

		/*Intervalul de 1 secunda*/
		_delay_ms(1000);
	}
}

/*Functia de control a programului*/
void controller()
{

	/*Setarea pinilor de date - stare 1 (output)*/
	lcd_D7_ddr |= (1 << lcd_D7_bit);
	lcd_D6_ddr |= (1 << lcd_D6_bit);
	lcd_D5_ddr |= (1 << lcd_D5_bit);
	lcd_D4_ddr |= (1 << lcd_D4_bit);

	/*Setarea pinilor de comanda - stare 1 (output)*/
	lcd_E_ddr |= (1 << lcd_E_bit);
	lcd_RS_ddr |= (1 << lcd_RS_bit);

	/*Initializarea LCD-ului pentru o interfata pe 4 biti*/
	lcd_initializare_4biti();

	/*Afisare mesaj 1*/
	lcd_afisare_mesaj(mesaj1);

	/*Setare cursor la inceputul randului 2*/
	lcd_comanda(lcd_pozitie_cursor | lcd_rand_2);
	lcd_afisare_mesaj("--------");

	/*Setare cursor pe randul 2 pozitia 8*/
	lcd_comanda(lcd_pozitie_cursor | lcd_rand_2_pozitie_8);
	_delay_us(80);
}

/*Functie pentru initializarea LCD-ului*/
void lcd_initializare_4biti()
{
	/*Intarziere la pornirea LCD-ului pentru incarcarea si finalizarea instructiunilor curente*/
	_delay_ms(100);

	/*Setarea pinilor register select si enable pe 0 (input), pentru
	a putea efectua functia de scriere a mesajului si
	functiile de comanda*/
	lcd_RS_port &= ~(1 << lcd_RS_bit);
	lcd_E_port &= ~(1 << lcd_E_bit);

	/*Resetare LCD*/
	lcd_activare_output(lcd_reset);
	_delay_ms(10);

	lcd_activare_output(lcd_reset);
	_delay_us(200);

	lcd_activare_output(lcd_reset);
	_delay_us(200);

	/*Pregatire interfata pe 4 biti*/
	lcd_activare_output(lcd_4_biti);
	_delay_us(80);

	/*Setare interfata pe 4 biti*/
	lcd_comanda(lcd_4_biti);
	_delay_us(80);

	/*Oprire LCD*/
	lcd_comanda(lcd_stins);
	_delay_us(80);

	/*Stergere afisare LCD*/
	lcd_comanda(lcd_sterge);
	_delay_ms(4);

	/*Setare stare LCD*/
	lcd_comanda(lcd_stare);
	_delay_us(80);

	/*Aprindere LCD*/
	lcd_comanda(lcd_aprins);
	_delay_us(80);
}

/*Functia de pregatire pentru scriere a mesajului*/
void lcd_activare_output(unsigned char opt_biti)
{
	/*setare portului D7 pe 0 (input)*/
	lcd_D7_port &= ~(1 << lcd_D7_bit);
	/*daca exista date, setare port D7 pe 1 (output)*/
	if (opt_biti & 1 << 7)
		lcd_D7_port |= (1 << lcd_D7_bit);

	/*setare portului D6 pe 0 (input)*/
	lcd_D6_port &= ~(1 << lcd_D6_bit);
	/*daca exista date, setare port D6 pe 1 (output)*/
	if (opt_biti & 1 << 6)
		lcd_D6_port |= (1 << lcd_D6_bit);

	/*setare portului D5 pe 0 (input)*/
	lcd_D5_port &= ~(1 << lcd_D5_bit);
	/*daca exista date, setare port D5 pe 1 (output)*/
	if (opt_biti & 1 << 5)
		lcd_D5_port |= (1 << lcd_D5_bit);

	/*setare portului D4 pe 0 (input)*/
	lcd_D4_port &= ~(1 << lcd_D4_bit);
	/*daca exista date, setare port D4 pe 1 (output)*/
	if (opt_biti & 1 << 4)
		lcd_D4_port |= (1 << lcd_D4_bit);

	/*Afisarea datelor pe LCD*/
	/*Setare pin enable pe 1 (output)*/
	lcd_E_port |= (1 << lcd_E_bit);
	_delay_us(1);
	/*Setarea pin enable pe 0 (input)*/
	lcd_E_port &= ~(1 << lcd_E_bit);
	_delay_us(1);
}

/*Functia de introducere a datelor*/
void lcd_stocare_mesaj(unsigned char date)
{
	/*Setare pin register select pe 1 (output)*/
	lcd_RS_port |= (1 << lcd_RS_bit);
	/*Setare pin enable pe 0 (input)*/
	lcd_E_port &= ~(1 << lcd_E_bit);
	/*Scrierea datelor pe primii 4 biti*/
	lcd_activare_output(date);
	/*Scrierea datelor pe ultimii 4 biti*/
	lcd_activare_output(date << 4);
}

/*Functia pentru comenzi LCD*/
void lcd_comanda(unsigned char instructiune)
{
	/*Setare pin register select 0 (input)*/
	lcd_RS_port &= ~(1 << lcd_RS_bit);
	/*Setare pin enable 0 (output)*/
	lcd_E_port &= ~(1 << lcd_E_bit);
	/*Scrierea instructiunii pe primii 4 biti*/
	lcd_activare_output(instructiune);
	/*Scrierea instructiunii pe ultimii 4 biti*/
	lcd_activare_output(instructiune << 4);
}

/*Functia de afisare a datelor pe LCD*/
void lcd_afisare_mesaj(unsigned char mesaj[])
{
	volatile int i = 0;
	while (mesaj[i] != 0)
	{
		lcd_stocare_mesaj(mesaj[i]);
		i++;
		_delay_us(80);
	}
}

/*Functie pentru calcularea si afisarea timpului*/
void lcd_afisare_timp()
{

	unsigned char *temp = 0;

	/*Convertirea int in char si afisarea lor*/
	itoa(secunde / 10, temp, 10);
	lcd_afisare_mesaj(temp);
	itoa(secunde % 10, temp, 10);
	lcd_afisare_mesaj(temp);
}