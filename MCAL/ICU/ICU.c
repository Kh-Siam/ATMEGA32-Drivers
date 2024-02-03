#include <avr/interrupt.h>          /* Make sure to do it yourself later */
#include <avr/io.h>                 /* Make sure to do it yourself later */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "ICU.h"

static ptrVoidFunction ISR_TIMER1_CAPT_PTR = NULL;

void ICU_voidInit(u8 copy_u8Prescaler, u8 copy_u8Trigger)
{
    /* make ICP1 pin as input */
    CLR_BIT(DDRD, PD6);

    /* Timer 1 normal mode */
    CLR_BIT(TCCR1A, WGM10); CLR_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1B, WGM12); CLR_BIT(TCCR1B, WGM13);

    /* enable interrupt */
    SET_BIT(TIMSK, TICIE1);
    if(!GET_BIT(SREG, SREG_I))
        SET_BIT(SREG, SREG_I); 

    switch(copy_u8Trigger)
    {
        case ICU_FALLING_EDGE:  CLR_BIT(TCCR1B, ICES1); break;
        case ICU_RISING_EDGE:   SET_BIT(TCCR1B, ICES1); break;
        default:                /* do nothing */        break;
    }

    TCCR1B &= 0b11111000;
    TCCR1B |= copy_u8Prescaler;
}

void ICU_voidChangeTrigger(u8 copy_u8Trigger)
{
    switch(copy_u8Trigger)
    {
        case ICU_FALLING_EDGE:  CLR_BIT(TCCR1B, ICES1); break;
        case ICU_RISING_EDGE:   SET_BIT(TCCR1B, ICES1); break;
        default:                /* do nothing */        break;
    }
}

void ICU_voidSetCallback(ptrVoidFunction copy_ptrVoidFunction)
{
    if(copy_ptrVoidFunction != NULL)
        ISR_TIMER1_CAPT_PTR = copy_ptrVoidFunction;
    else
        { /* do nothing */ } 
}

u16  ICU_u16ReadValue(void)
{
    return ICR1;
}

void ICU_voidDisableInterrupt(void)
{
    CLR_BIT(TIMSK, TICIE1);
}

ISR(TIMER1_CAPT_vect){

	ISR_TIMER1_CAPT_PTR();

}