/*
 * slave.c
 *
 * Created: 6/17/2023 3:07:28 AM
 * Author : kamar
 */ 

#include <avr/io.h>
#include "SPI driver.h"
#include "LCD driver.h"
#define DUMMY_DATA 0XFF

int main(void)
{
    SPI_SlaveInit();
	LCD_vinit ();
	unsigned char x;
	
    while (1) 
    {
		x=SPI_SlaveRecivechar(DUMMY_DATA);
		LCD_vsend_char (x);
    }
}

