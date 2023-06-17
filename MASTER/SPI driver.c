/*
 * SPI_driver.c
 *
 * Created: 6/16/2023 12:22:15 AM
 *  Author: kamar
 */ 

#include <avr/io.h>
#include "macros.h"
#include "DIO drivers.h"

void SPI_MasterInit()
{
	/* set pins SS &MOSI &CLK  as output bins*/
	DIO_vset_pin_dir('B', 4, 1);
	DIO_vset_pin_dir('B', 5, 1);
	DIO_vset_pin_dir('B', 7, 1);
	
	/*set cloack as fosc/16*/
	SET_BIT(SPCR,SPR0) ;
	
	/*enable SPI */
	SET_BIT(SPCR,SPE) ;
	
	/*enable Master mode */
	SET_BIT(SPCR,MSTR) ;
	
	/*set SS to logic high*/
	DIO_vwrite_pin('B', 4, 1);
	
}

void SPI_SlaveInit()
{
     /*enable SPI */
	 SET_BIT(SPCR,SPE) ;
	
	/*set MISO as output pin*/
	DIO_vset_pin_dir('B', 6, 1);	
	
}

SPI_MasterTransmitchar(unsigned char data)
{
	/*clear SS to send data to Slave*/
	DIO_vwrite_pin('B', 4, 0);
	
	/*load data on SPDR register*/
	SPDR= data;
	
	/*wait until the transmition is complete*/
	while (READ_BIT(SPSR,SPIF)==0);
	
	/*read the data*/
	return SPDR;
		
}

SPI_SlaveResivechar(unsigned char data)
{
	/*load data on SPDR register*/
	SPDR= data;
	
	/*wait until data is recived in spi register*/
	while (READ_BIT(SPSR,SPIF)==0);
	
	/*read the recived data*/
	return SPDR;
		
}

SPI_MasterTransmitstring(unsigned char *ptr)
{
	while ((*ptr)!=0)
	{
		SPI_MasterTransmitchar(*ptr);
		_delay_ms(300);
		ptr++;
	}
}