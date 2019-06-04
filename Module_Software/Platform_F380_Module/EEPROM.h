#ifndef _EEPROM_H_
#define _EEPROM_H_

#include <platform_options.h>

#ifdef PLATFORM_F380_MODULE
void eeprom_write(u16 address,u8* w_buffer,u16 len);
void eeprom_read(u16 address,u8* r_buffer,u16 len);
#endif
#endif