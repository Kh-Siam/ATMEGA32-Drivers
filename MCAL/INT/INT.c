#include <avr/interrupt.h>                 /* Make sure to do it yourself later */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "INT.h"

static ptrVoidFunction ISR_INT0_PTR = NULL;
static ptrVoidFunction ISR_INT1_PTR = NULL;
static ptrVoidFunction ISR_INT2_PTR = NULL;

void INT_voidEnable(u8 copy_u8INTIndex, u8 copy_u8INTSense)
{
    SET_BIT(SREG, SREG_I);                       /* enables global interrupt */

    switch(copy_u8INTIndex)
    {
        case INT_INT0:
            switch(copy_u8INTSense)
            {
                case(INT_FALLING_EDGE):
                    CLR_BIT(MCUCR, ISC00);
                    SET_BIT(MCUCR, ISC01);
                    break;
                case(INT_RISING_EDGE):
                    SET_BIT(MCUCR, ISC00);
                    SET_BIT(MCUCR, ISC01);
                    break;
                case(INT_ANY_CHANGE):
                    SET_BIT(MCUCR, ISC00);
                    CLR_BIT(MCUCR, ISC01);
                    break;
                case(INT_LOW_LEVEL):
                    CLR_BIT(MCUCR, ISC00);
                    CLR_BIT(MCUCR, ISC01);
                    break;
                default:    /* do nothing */ break;
            }
            CLR_BIT(DDRD, PD2);
            SET_BIT(GICR, INT0);
            break;
        case INT_INT1:
            switch(copy_u8INTSense)
            {
                case(INT_FALLING_EDGE):
                    CLR_BIT(MCUCR, ISC10);
                    SET_BIT(MCUCR, ISC11);
                    break;
                case(INT_RISING_EDGE):
                    SET_BIT(MCUCR, ISC10);
                    SET_BIT(MCUCR, ISC11);
                    break;
                case(INT_ANY_CHANGE):
                    SET_BIT(MCUCR, ISC10);
                    CLR_BIT(MCUCR, ISC11);
                    break;
                case(INT_LOW_LEVEL):
                    CLR_BIT(MCUCR, ISC10);
                    CLR_BIT(MCUCR, ISC11);
                    break;
                default:    /* do nothing */ break;
            }
            CLR_BIT(DDRD, PD3);
            SET_BIT(GICR, INT1);
            break;
        case INT_INT2:
            switch(copy_u8INTSense)
            {
                case(INT_FALLING_EDGE):
                    CLR_BIT(MCUCSR, ISC2);   break;
                case(INT_RISING_EDGE):
                    SET_BIT(MCUCSR, ISC2);   break;
                default:    /* do nothing */ break;
            }
            CLR_BIT(DDRB, PB2);
            SET_BIT(GICR, INT2);
            break;
        default:    /* do nothing */ break;
    }
}

void INT_voidDisable(u8 copy_u8INTIndex)
{
    switch(copy_u8INTIndex)
    {
        case INT_INT0:  CLR_BIT(GICR, INT0); break;
        case INT_INT1:  CLR_BIT(GICR, INT1); break;
        case INT_INT2:  CLR_BIT(GICR, INT2); break;
        default:        /* do nothing */     break;
    }
}

void INT_voidSetCallback(u8 copy_u8INTIndex, ptrVoidFunction copy_ptrVoidFunction)
{
    switch(copy_u8INTIndex)
    {
        case INT_INT0:  ISR_INT0_PTR = copy_ptrVoidFunction; break;
        case INT_INT1:  ISR_INT1_PTR = copy_ptrVoidFunction; break;
        case INT_INT2:  ISR_INT2_PTR = copy_ptrVoidFunction; break;
        default:        /* do nothing */    break;
    }
}

ISR(INT0_vect)
{
    if(ISR_INT0_PTR != NULL)
        ISR_INT0_PTR();
    else
        { /* do nothing */ }
}

ISR(INT1_vect)
{
    if(ISR_INT1_PTR != NULL)
        ISR_INT1_PTR();
    else
        { /* do nothing */ }
}

ISR(INT2_vect)
{
    if(ISR_INT2_PTR != NULL)
        ISR_INT2_PTR();
    else
        { /* do nothing */ }
}