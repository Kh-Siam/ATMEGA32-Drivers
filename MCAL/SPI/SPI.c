#include <avr/io.h>                 /* Make sure to do it yourself later */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "SPI.h"

void SPI_voidMasterInit(u8 copy_u8DataOrder, u8 copy_u8ClockSetting, u8 copy_u8Speed, u8 copy_u8Frequency)
{
    /* set both MOSI, SCK and SS as output pins */
    SET_BIT(DDRB, PB4); SET_BIT(DDRB, PB5); SET_BIT(DDRB, PB7);
    CLR_BIT(DDRB, PB6);   /* set MISO as input pin */ 
    SET_BIT(SPCR, MSTR);  /* config as master */

    switch(copy_u8DataOrder)
    {
        case SPI_DATA_ORDER_MSB:    CLR_BIT(SPCR, DORD); break;
        case SPI_DATA_ORDER_LSB:    SET_BIT(SPCR, DORD); break;
        default:                    /* do nothing */     break;
    }

    switch(copy_u8ClockSetting)
    {
        case SPI_RISING_SAMPLE:     CLR_BIT(SPCR, CPOL);  CLR_BIT(SPCR, CPHA);  break;
        case SPI_RISING_SETUP:      CLR_BIT(SPCR, CPOL);  SET_BIT(SPCR, CPHA);  break;
        case SPI_FALLING_SAMPLE:    SET_BIT(SPCR, CPOL);  CLR_BIT(SPCR, CPHA);  break;
        case SPI_FALLING_SETUP:     SET_BIT(SPCR, CPOL);  SET_BIT(SPCR, CPHA);  break;
        default:                    /* do nothing */                            break;
    }

    switch(copy_u8Speed)
    {
        case SPI_NORMAL_SPEED:      SET_BIT(SPSR, SPI2X); break;
        case SPI_DOUBLE_SPEED:      CLR_BIT(SPSR, SPI2X); break;
        default:                    /* do nothing */      break;
    }

    SPCR &= 0b11111100;
    SPCR |= copy_u8Frequency;
}

void SPI_voidSlaveInit(u8 copy_u8DataOrder, u8 copy_u8ClockSetting)
{
    SET_BIT(DDRB, PB6);     /* set MISO as output pin */
    /* set MOSI, SCK and SS as input pins */
    CLR_BIT(DDRB, PB4); CLR_BIT(DDRB, PB5); CLR_BIT(DDRB, PB7);
    CLR_BIT(SPCR, MSTR);  /* config as slave */

    switch(copy_u8DataOrder)
    {
        case SPI_DATA_ORDER_MSB:    CLR_BIT(SPCR, DORD); break;
        case SPI_DATA_ORDER_LSB:    SET_BIT(SPCR, DORD); break;
        default:                    /* do nothing */     break;
    }

    switch(copy_u8ClockSetting)
    {
        case SPI_RISING_SAMPLE:     CLR_BIT(SPCR, CPOL);  CLR_BIT(SPCR, CPHA);  break;
        case SPI_RISING_SETUP:      CLR_BIT(SPCR, CPOL);  SET_BIT(SPCR, CPHA);  break;
        case SPI_FALLING_SAMPLE:    SET_BIT(SPCR, CPOL);  CLR_BIT(SPCR, CPHA);  break;
        case SPI_FALLING_SETUP:     SET_BIT(SPCR, CPOL);  SET_BIT(SPCR, CPHA);  break;
        default:                    /* do nothing */                            break;
    }
}

void SPI_voidEnable(void)
{
    SET_BIT(SPCR, SPE);
}

void SPI_voidDisable(void)
{
    CLR_BIT(SPCR, SPE);
}

void SPI_voidMasterTransmitData(u8 copy_u8Data)
{
    SPDR = copy_u8Data;
    while(!GET_BIT(SPSR, SPIF));    /* Wait for transmission complete */
}

void SPI_voidSlaveTransmitData(u8 copy_u8Data)
{
    SPDR = copy_u8Data;
}

u8   SPI_u8ReceiveData(void)
{
    while(!GET_BIT(SPSR, SPIF));  /* Wait for reception complete */
    return SPDR;
}

u8   SPI_u8ReceiveTransmission(u8 copy_u8Data)
{
    SPDR = copy_u8Data;
    while(!GET_BIT(SPSR, SPIF));    /* Wait for transmission complete */
    return SPDR;
}