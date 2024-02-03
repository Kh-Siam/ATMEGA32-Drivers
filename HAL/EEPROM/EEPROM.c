#include <avr/io.h>                 /* Make sure to do it yourself later */
#include <util/delay.h>             /* Make sure to do it yourself later */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/TWI/TWI.h"
#include "EEPROM.h"

void EEPROM_voidWriteData(u8 copy_u8RomNum, u16 copy_u16Address, u8 copy_u8Data)
{
    TWI_voidStartCondition();
    TWI_voidSlaveAddressWrite(FIXED_ADDRESS | (copy_u8RomNum << 2) | (copy_u16Address >> 8));    /* block select */ 
    TWI_voidMasterSendData((u8)copy_u16Address); /* address select */
    TWI_voidMasterSendData(copy_u8Data);
    TWI_voidStopCondition();
    _delay_ms(5);
}

u8 EEPROM_u8ReadData(u8 copy_u8RomNum, u16 copy_u16Address)
{
    u8 local_u8Data;
    TWI_voidStartCondition();
    TWI_voidSlaveAddressWrite(FIXED_ADDRESS | (copy_u8RomNum << 2) | (copy_u16Address >> 8));    /* block select */ 
    TWI_voidMasterSendData((u8)copy_u16Address); /* address select */
    TWI_voidStartCondition();
    TWI_voidSlaveAddressRead(FIXED_ADDRESS | (copy_u8RomNum << 2) | (copy_u16Address >> 8));
    local_u8Data = TWI_u8MasterReceiveData();
    TWI_voidStopCondition();
    return local_u8Data;
}