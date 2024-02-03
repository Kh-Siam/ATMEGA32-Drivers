#ifndef EEPROM_H
#define EEPROM_H

#define FIXED_ADDRESS       0b01010000
#define EEPROM_NUM_0        0
#define EEPROM_NUM_1        1

void EEPROM_voidWriteData   (u8 copy_u8RomNum, u16 copy_u16Address, u8 copy_u8Data);
u8   EEPROM_u8ReadData      (u8 copy_u8RomNum, u16 copy_u16Address);

#endif