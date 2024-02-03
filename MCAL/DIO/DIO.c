#include <avr/io.h>                 /* Make sure to do it yourself later */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "DIO.h"

void DIO_voidSetPinDirection(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Direction)
{
    if(copy_u8Pin < 8 )
    {
        if(copy_u8Direction == DIO_OUTPUT)
        {
            switch(copy_u8Port)
            {
                case DIO_PORTA:     SET_BIT(DDRA, copy_u8Pin); break;
                case DIO_PORTB:     SET_BIT(DDRB, copy_u8Pin); break;
                case DIO_PORTC:     SET_BIT(DDRC, copy_u8Pin); break;
                case DIO_PORTD:     SET_BIT(DDRD, copy_u8Pin); break;
                default:            /* do nothing */    break;
            }
        }
        else if(copy_u8Direction == DIO_INPUT)
        {
            switch(copy_u8Port)
            {
                case DIO_PORTA:     CLR_BIT(DDRA, copy_u8Pin); break;
                case DIO_PORTB:     CLR_BIT(DDRB, copy_u8Pin); break;
                case DIO_PORTC:     CLR_BIT(DDRC, copy_u8Pin); break;
                case DIO_PORTD:     CLR_BIT(DDRD, copy_u8Pin); break;
                default:            /* do nothing */    break;
            }
        }
        else { /* do nothing */ }
    }
    else { /* do nothing */ }
}

void DIO_voidSetPinValue(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Value)
{
    if(copy_u8Pin < 8)
    {
        if(copy_u8Value == DIO_HIGH)
        {
            switch(copy_u8Port)
            {
                case DIO_PORTA:     SET_BIT(PORTA, copy_u8Pin); break;
                case DIO_PORTB:     SET_BIT(PORTB, copy_u8Pin); break;
                case DIO_PORTC:     SET_BIT(PORTC, copy_u8Pin); break;
                case DIO_PORTD:     SET_BIT(PORTD, copy_u8Pin); break;
                default:            /* do nothing */     break;
            }
        }
        else if(copy_u8Value == DIO_LOW)
        {
            switch(copy_u8Port)
            {
                case DIO_PORTA:     CLR_BIT(PORTA, copy_u8Pin); break;
                case DIO_PORTB:     CLR_BIT(PORTB, copy_u8Pin); break;
                case DIO_PORTC:     CLR_BIT(PORTC, copy_u8Pin); break;
                case DIO_PORTD:     CLR_BIT(PORTD, copy_u8Pin); break;
                default:            /* do nothing */     break;
            }
        }
        else { /* do nothing */ }
    }
    else { /* do nothing */ }
}

u8   DIO_u8GetPinValue(u8 copy_u8Port, u8 copy_u8Pin)
{
    if(copy_u8Pin < 8)
    {
        switch(copy_u8Port)
        {
            case DIO_PORTA:     return GET_BIT(PINA, copy_u8Pin);
            case DIO_PORTB:     return GET_BIT(PINB, copy_u8Pin);
            case DIO_PORTC:     return GET_BIT(PINC, copy_u8Pin);
            case DIO_PORTD:     return GET_BIT(PIND, copy_u8Pin);
            default:            return 0xff;                    /* as a wrong entry */
        }
    }
    else { /* do nothing */ }
}

void DIO_voidSetPortDirection(u8 copy_u8Port, u8 copy_u8Direction) 
{
    switch(copy_u8Port)
    {
        case DIO_PORTA:         DDRA = copy_u8Direction; break;
        case DIO_PORTB:         DDRB = copy_u8Direction; break;
        case DIO_PORTC:         DDRC = copy_u8Direction; break;
        case DIO_PORTD:         DDRD = copy_u8Direction; break;
        default:                /* do nothing */  break;
    }
}

void DIO_voidSetPortValue(u8 copy_u8Port, u8 copy_u8Value)
{
    switch(copy_u8Port)
    {
        case DIO_PORTA:         PORTA = copy_u8Value;    break;
        case DIO_PORTB:         PORTB = copy_u8Value;    break;
        case DIO_PORTC:         PORTC = copy_u8Value;    break;
        case DIO_PORTD:         PORTD = copy_u8Value;    break;
        default:                /* do nothing */  break;
    }
}

u8   DIO_u8GetPortValue(u8 copy_u8Port)
{
    switch(copy_u8Port)
    {
        case DIO_PORTA:         return PINA;
        case DIO_PORTB:         return PINB;
        case DIO_PORTC:         return PINC;
        case DIO_PORTD:         return PIND;
        default:                return 0x00;                    /* as a wrong entry */
    }
}

void DIO_voidTogglePin(u8 copy_u8Port, u8 copy_u8Pin)
{
    if(copy_u8Pin < 8)
    {
        switch(copy_u8Port)
        {
            case DIO_PORTA:     TGL_BIT(PORTA, copy_u8Pin); break;
            case DIO_PORTB:     TGL_BIT(PORTB, copy_u8Pin); break;
            case DIO_PORTC:     TGL_BIT(PORTC, copy_u8Pin); break;
            case DIO_PORTD:     TGL_BIT(PORTD, copy_u8Pin); break;
            default:            /* do nothing */     break;
        }
    }
    else { /* do nothing */ }
}   

void DIO_voidTogglePort(u8 copy_u8Port)
{
    switch(copy_u8Port)
    {
        case DIO_PORTA:         PORTA = ~PORTA;	  break;
        case DIO_PORTB:         PORTB = ~PORTB;   break;
        case DIO_PORTC:         PORTC = ~PORTC;   break;
        case DIO_PORTD:         PORTD = ~PORTD;   break;
        default:                /* do nothing */  break;
    }
}

u8   DIO_u8GetOutPortState(u8 copy_u8Port)
{
    switch(copy_u8Port)
    {
        case DIO_PORTA:         return PORTA;	  break;
        case DIO_PORTB:         return PORTB;     break;
        case DIO_PORTC:         return PORTC;     break;
        case DIO_PORTD:         return PORTD;     break;
        default:                /* do nothing */  break;
    }
}
