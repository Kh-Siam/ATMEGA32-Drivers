#include <avr/io.h>                 /* Make sure to do it yourself later */
#include <avr/interrupt.h>          /* Make sure to do it yourself later */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "TIMER2.h"

static ptrVoidFunction ISR_TIMER2_OVERFLOW_PTR = NULL;
static ptrVoidFunction ISR_TIMER2_COMPARE_PTR = NULL;

void TIMER2_voidInit(u8 copy_u8Mode)
{
    switch(copy_u8Mode)
    {
        case TIMER2_NORMAL:    CLR_BIT(TCCR2, WGM20); CLR_BIT(TCCR2, WGM21); break;
        case TIMER2_CTC:       CLR_BIT(TCCR2, WGM20); SET_BIT(TCCR2, WGM21); break;
        case TIMER2_PWM_PHASE: SET_BIT(TCCR2, WGM20); CLR_BIT(TCCR2, WGM21); break;
        case TIMER2_FAST_PWM:  SET_BIT(TCCR2, WGM20); SET_BIT(TCCR2, WGM21); break;
        default:        /* do nothing */                              break;
    }
}

void TIMER2_voidSetPreValue(u8 copy_u8Value)
{
    TCNT2 = copy_u8Value;
}

void TIMER2_voidTimerStart(u8 copy_u8Prescaler)
{
    TCCR2 &= 0b11111000;
    TCCR2 |= copy_u8Prescaler;
}

void TIMER2_voidOverflowINTControl(u8 copy_u8InterruptControl)
{
    if(copy_u8InterruptControl == TIMER2_INT_ENABLE)
        SET_BIT(TIMSK, TOIE2);
        if(!GET_BIT(SREG, SREG_I))
            SET_BIT(SREG, SREG_I); 
    else
        CLR_BIT(TIMSK, TOIE2);
}

void TIMER2_voidSetCompareMatch(u8 copy_u8MatchValue, u8 copy_u8OC2PinAction)
{
    SET_BIT(DDRD, PB7);
    switch(copy_u8OC2PinAction)
    {
        case TIMER2_OC2_IN_OUT_PIN: CLR_BIT(TCCR2, COM20); CLR_BIT(TCCR2, COM21); break;
        case TIMER2_OC2_TOGGLE_PIN: SET_BIT(TCCR2, COM20); CLR_BIT(TCCR2, COM21); break;
        case TIMER2_OC2_CLEAR_PIN:  CLR_BIT(TCCR2, COM20); SET_BIT(TCCR2, COM21); break;
        case TIMER2_OC2_SET_PIN:    SET_BIT(TCCR2, COM20); SET_BIT(TCCR2, COM21); break;
        default:                    /* do nothing */                              break;
    }
    OCR2 = copy_u8MatchValue;
}

void TIMER2_voidPWMGenerator(u8 copy_u8Mode, u8 copy_u8DutyCycle, u8 copy_u8OC2PinAction)
{
    SET_BIT(DDRD, PB7);
    if(copy_u8Mode == TIMER2_FAST_PWM)
    {
        switch(copy_u8OC2PinAction)
        {
            case TIMER2_SET_OC2_AT_TOP: 
                CLR_BIT(TCCR2, COM20); SET_BIT(TCCR2, COM21); 
                OCR2 = ((copy_u8DutyCycle/100.0)*256);         break;
            case TIMER2_CLR_OC2_AT_TOP: 
                SET_BIT(TCCR2, COM20); SET_BIT(TCCR2, COM21); 
                OCR2 = (256 - ((copy_u8DutyCycle/100.0)*256)); break;
            default:    /* do nothing */                       break;
        }
    }
    else if(copy_u8Mode == TIMER2_PWM_PHASE)
    {
        switch(copy_u8OC2PinAction)
        {
            case TIMER2_CLR_UP_SET_DOWN:
                CLR_BIT(TCCR2, COM20);  SET_BIT(TCCR2, COM21);
                OCR2 = (((copy_u8DutyCycle/100.0)*510)/2);     break;
            case TIMER2_SET_UP_CLR_DOWN:
                SET_BIT(TCCR2, COM20);  SET_BIT(TCCR2, COM21);
                OCR2 = (255-((copy_u8DutyCycle/100.0)*510)/2); break;
            default:    /* do nothing */                       break;
        }
    }
    else { /* do nothing */ }
}

void TIMER2_voidSetCompareValue(u8 copy_u8MatchValue)
{
    OCR2 = copy_u8MatchValue;
}

void TIMER2_voidCompareINTControl(u8 copy_u8InterruptControl)
{
    if(copy_u8InterruptControl == TIMER2_INT_ENABLE)
        SET_BIT(TIMSK, OCIE2);
        if(!GET_BIT(SREG, SREG_I))
            SET_BIT(SREG, SREG_I); 
    else
        CLR_BIT(TIMSK, OCIE2);
}

void TIMER2_voidTimerStop(void)
{
    TCCR2 &= 0b11111000;
}

void TIMER2_voidOverflowCallback(ptrVoidFunction copy_ptrVoidFunction)
{
    if(copy_ptrVoidFunction != NULL)
        ISR_TIMER2_OVERFLOW_PTR = copy_ptrVoidFunction;
}

void TIMER2_voidCompareCallback(ptrVoidFunction copy_ptrVoidFunction)
{
    if(copy_ptrVoidFunction != NULL)
        ISR_TIMER2_COMPARE_PTR = copy_ptrVoidFunction;
}

ISR(TIMER2_OVF_vect)
{
    if(ISR_TIMER2_OVERFLOW_PTR != NULL)
        ISR_TIMER2_OVERFLOW_PTR();
    else
        { /* do nothing */ }
}


ISR(TIMER2_COMP_vect)
{
	if(ISR_TIMER2_COMPARE_PTR != NULL)
        ISR_TIMER2_COMPARE_PTR();
    else
        { /* do nothing */ }
}