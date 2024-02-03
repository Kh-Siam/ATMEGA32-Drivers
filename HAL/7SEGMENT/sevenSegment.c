#include <avr/io.h>                 /* Make sure to do it yourself later */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/DIO/DIO.h"
#include "sevenSegment.h"

static const u8 Digits[16] =   {
                            0b00111111,
                            0b00000110,
                            0b01011011,
                            0b01001111,
                            0b01100110,
                            0b01101101,
                            0b01111101,
                            0b00000111,
                            0b01111111,
                            0b01101111,
                            0b01110111,
                            0b01111100,
                            0b00111001,
                            0b01011110,
                            0b01111001,
                            0b01110001 
                        };

void SEVENSEGMENT_voidInit(u8 copy_u8Port)
{
    switch(copy_u8Port)
    {
        case DIO_PORTA:     DIO_voidSetPortDirection(DIO_PORTA, DIO_PORT_OUTPUT); break;
        case DIO_PORTB:     DIO_voidSetPortDirection(DIO_PORTB, DIO_PORT_OUTPUT); break;
        case DIO_PORTC:     DIO_voidSetPortDirection(DIO_PORTC, DIO_PORT_OUTPUT); break;
        case DIO_PORTD:     DIO_voidSetPortDirection(DIO_PORTD, DIO_PORT_OUTPUT); break;
        default:            /* do nothing */                                  break;
    }
}

void SEVENSEGMENT_voidDisplayDigit(u8 copy_u8Port, u8 copy_u8Digit)
{
    if(copy_u8Digit < 16)
    {
        switch(copy_u8Port)
        {
            case DIO_PORTA:     DIO_voidSetPortValue(DIO_PORTA, Digits[copy_u8Digit]); break;
            case DIO_PORTB:     DIO_voidSetPortValue(DIO_PORTB, Digits[copy_u8Digit]); break;
            case DIO_PORTC:     DIO_voidSetPortValue(DIO_PORTC, Digits[copy_u8Digit]); break;
            case DIO_PORTD:     DIO_voidSetPortValue(DIO_PORTD, Digits[copy_u8Digit]); break;
            default:            /* do nothing */                            break;
        }
    }
    else { /* do nothing */ }
}