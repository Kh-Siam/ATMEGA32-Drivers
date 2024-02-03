#include <avr/io.h>                 /* Make sure to do it yourself later */
#include <avr/interrupt.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "TWI.h"

static ptrVoidFunction ISR_TWI_HANDLE_PTR = NULL;

void TWI_voidMasterInit(u8 copy_u8Prescaler, u32 copy_u32Frequency)
{
    u8 local_u8PrescalerValue;
    switch(copy_u8Prescaler)
    {
        case TWI_PRESCALER_1:   CLR_BIT(TWSR, TWPS0); CLR_BIT(TWSR, TWPS1); 
                                local_u8PrescalerValue = 1;          break;
        case TWI_PRESCALER_4:   SET_BIT(TWSR, TWPS0); CLR_BIT(TWSR, TWPS1);
                                local_u8PrescalerValue = 16;         break;
        case TWI_PRESCALER_16:  CLR_BIT(TWSR, TWPS0); SET_BIT(TWSR, TWPS1);
                                local_u8PrescalerValue = 16;         break;
        case TWI_PRESCALER_64:  SET_BIT(TWSR, TWPS0); SET_BIT(TWSR, TWPS1);
                                local_u8PrescalerValue = 64;         break;
        default:                /* do nothing */                     break;
    }
    TWBR = (((CPU_FREQ/copy_u32Frequency) - 16) / (2*local_u8PrescalerValue));
	SET_BIT(TWCR, TWEA);        /* enable ACK */
}

void TWI_voidSlaveInit(u8 copy_u8Address)
{
    TWAR = copy_u8Address << 1;
    SET_BIT(TWCR, TWEA);        /* enable ACK */
}

void TWI_voidEnable(void)
{
    SET_BIT(TWCR, TWEN);
}

void TWI_voidDisable(void)
{
    CLR_BIT(TWCR, TWEN);
}

void TWI_voidEnableInterrupt(void)
{
    if(!GET_BIT(SREG, SREG_I))
        SET_BIT(SREG, SREG_I); 
    SET_BIT(TWCR, TWIE);
}

void TWI_voidSetCallBack(ptrVoidFunction copy_ptrVoidFunction)
{
    if(copy_ptrVoidFunction != NULL)
        ISR_TWI_HANDLE_PTR = copy_ptrVoidFunction;
    else
        { /* do nothing */ }
}

void TWI_voidDisableInterrupt(void)
{
    CLR_BIT(TWCR, TWIE);
}

void TWI_voidStartCondition(void)
{
    do
    {
        SET_BIT(TWCR, TWSTA);   
        SET_BIT(TWCR, TWINT);
        while(!GET_BIT(TWCR, TWINT));
    } while(TWI_u8GetStatus() != TWI_START_CONDITION);
}

void TWI_voidStopCondition(void)
{
    SET_BIT(TWCR, TWSTO);
	SET_BIT(TWCR, TWINT);
}

void TWI_voidSlaveAddressWrite(u8 copy_u8SlaveAddress)
{
    do
    {
        TWDR = copy_u8SlaveAddress << 1;
        CLR_BIT(TWDR, 0);       /* write operation */
        CLR_BIT(TWCR, TWSTA);   /* disable start condition */
        SET_BIT(TWCR, TWINT);
        while(!GET_BIT(TWCR, TWINT));
    } while(TWI_u8GetStatus() != TWI_MASTER_SLA_W_ACK);
}

void TWI_voidSlaveAddressRead(u8 copy_u8SlaveAddress)
{
    do
    {
        TWDR = copy_u8SlaveAddress << 1;
        SET_BIT(TWDR, 0);       /* read operation */
        CLR_BIT(TWCR, TWSTA);   /* disable start condition */
        SET_BIT(TWCR, TWINT);
        while(!GET_BIT(TWCR, TWINT));
    } while(TWI_u8GetStatus() != TWI_MASTER_SLA_R_ACK);
}

void TWI_voidMasterSendData(u8 copy_u8Data)
{
    do
    {
        TWDR = copy_u8Data;
        SET_BIT(TWCR, TWINT);
        while(!GET_BIT(TWCR, TWINT));
    } while(TWI_u8GetStatus() != TWI_MASTER_DATA_W_ACK);
}

u8 TWI_u8MasterReceiveData(void)
{
    do
    {
        SET_BIT(TWCR, TWINT);
        while(!GET_BIT(TWCR, TWINT));
    } while(TWI_u8GetStatus() != TWI_MASTER_DATA_R_ACK);
	return TWDR;
}

u8 TWI_u8SlaveReceiveData(void)
{
    /* 
        Please check for TWI_SLAVE_SLA_W_ACK 
        before calling the function
    */
	do
    {
        SET_BIT(TWCR, TWINT);
        while(!GET_BIT(TWCR, TWINT));
    } while(TWI_u8GetStatus() != TWI_SLAVE_DATA_R_ACK);
	return TWDR;
}

void TWI_voidSlaveSendData(u8 copy_u8Data)
{
    /* 
        Please check for TWI_SLAVE_SLA_R_ACK 
        before calling the function
    */
    do
    {
        TWDR = copy_u8Data;
        SET_BIT(TWCR, TWINT);
        while(!GET_BIT(TWCR, TWINT));
    } while(TWI_u8GetStatus() != TWI_SLAVE_DATA_W_ACK);
}

u8 TWI_u8GetStatus(void)
{
    return (TWSR & 0xF8);
}

ISR(TWI_vect)
{
    if(ISR_TWI_HANDLE_PTR != NULL)
        ISR_TWI_HANDLE_PTR();
    else
        { /* do nothing */ }
    SET_BIT(TWCR, TWINT);
}