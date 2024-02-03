#include <avr/io.h>                 /* Make sure to do it yourself later */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "UART.h"

void UART_voidInit(u8 copy_u8SpeedMode, u16 copy_u16BaudRate)
{
    u8 local_u8UCSRC = 0b10000000;
    /* set TXD and RXD as input */
    CLR_BIT(DDRD, PD0); CLR_BIT(DDRD, PD1);
    /* set baud rate */
    UBRRH = (copy_u16BaudRate >> 8);
    UBRRL = copy_u16BaudRate;
    /* select speed mode */
    switch(copy_u8SpeedMode)
    {
        case UART_NORMAL_MODE:  CLR_BIT(UCSRA, U2X);    break;
        case UART_DOUBLE_SPEED: SET_BIT(UCSRA, U2X);    break;
        default:                /* do nothing */        break;
    }
    CLR_BIT(UCSRA, MPCM);               /* disable multi-processor mode */
     /* work on 8-bits data */
    SET_BIT(local_u8UCSRC, UCSZ0);  SET_BIT(local_u8UCSRC, UCSZ1);  CLR_BIT(UCSRB, UCSZ2);
    CLR_BIT(local_u8UCSRC, UMSEL);      /* select asynchronous */
    /* disable parity */
    CLR_BIT(local_u8UCSRC, UPM0);   CLR_BIT(local_u8UCSRC, UPM1);
    SET_BIT(local_u8UCSRC, USBS);       /* make two bits as stop bits */
    CLR_BIT(local_u8UCSRC, UCPOL);      /* disable clock polarity */
    UCSRC = local_u8UCSRC;              /* assign local variable to UCSRC register */
    /* enable receiver and transmitter */
    SET_BIT(UCSRB, RXEN);   SET_BIT(UCSRB, TXEN);
}

void UART_voidTransmitData(u8 copy_u8Data)
{
    while(!GET_BIT(UCSRA, UDRE));   /* wait for empty transmit buffer */
    UDR = copy_u8Data;              /* put data into buffer */
}

u8   UART_u8ReceiveData(void)
{
    while(!GET_BIT(UCSRA, RXC));    /* wait for data to be received */
    return UDR;                     /* return data in buffer */
}
