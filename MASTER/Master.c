/*
 * Master.c
 *
 * Created: 6/17/2023 2:41:12 AM
 * Author : kamar
 */ 

#include <avr/io.h>
#include "SPI driver.h"
#include "Keybad driver.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	unsigned char x=0xff;
	SPI_MasterInit();
	Keybad_vinit ();
	
    while (1) 
    {
		x=Keybad_u8check_press ();
		if (x!=0xff)
		{
			SPI_MasterTransmitchar(x);
		}
		_delay_ms(250);
		
    }
}

