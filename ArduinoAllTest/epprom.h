/*
 * epprom.h
 *
 * Created: 22.12.2017 6:15:35
 *  Author: asian
 */ 


#ifndef EPPROM_H_
#define EPPROM_H_

#include "main.h"
void EEPROM_write(unsigned int uiAddress, unsigned char ucData);
unsigned char EEPROM_read(unsigned int uiAddress);


#endif /* EPPROM_H_ */