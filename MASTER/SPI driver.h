/*
 * SPI_driver.h
 *
 * Created: 6/16/2023 12:22:39 AM
 *  Author: kamar
 */ 


#ifndef SPI DRIVER_H_
#define SPI DRIVER_H_

void SPI_MasterInit();
void SPI_SlaveInit();
unsigned char SPI_MasterTransmitchar(unsigned char data);
unsigned char SPI_SlaveRecivechar(unsigned char data);
void SPI_MasterTransmitstring(unsigned char *ptr);

#endif /* SPI DRIVER_H_ */