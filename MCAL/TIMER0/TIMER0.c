#include <avr/io.h>                 /* Make sure to do it yourself later */
#include <avr/interrupt.h>          /* Make sure to do it yourself later */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "TIMER0.h"

static ptrVoidFunction ISR_TIMER0_OVERFLOW_PTR = NULL;
static ptrVoidFunction ISR_TIMER0_COMPARE_PTR = NULL;

void TIMER0_voidInit(u8 copy_u8Mode)
{
    switch(copy_u8Mode)
    {
        case TIMER0_NORMAL:    CLR_BIT(TCCR0, WGM00); CLR_BIT(TCCR0, WGM01); break;
        case TIMER0_CTC:       CLR_BIT(TCCR0, WGM00); SET_BIT(TCCR0, WGM01); break;
        case TIMER0_PWM_PHASE: SET_BIT(TCCR0, WGM00); CLR_BIT(TCCR0, WGM01); break;
        case TIMER0_FAST_PWM:  SET_BIT(TCCR0, WGM00); SET_BIT(TCCR0, WGM01); break;
        default:        /* do nothing */                              break;
    }
}

void TIMER0_voidSetPreValue(u8 copy_u8Value)
{
    TCNT0 = copy_u8Value;
}

void TIMER0_voidTimerStart(u8 copy_u8Prescaler)
{
    TCCR0 &= 0b11111000;
    TCCR0 |= copy_u8Prescaler;
}

void TIMER0_voidOverflowINTControl(u8 copy_u8InterruptControl)
{
    if(copy_u8InterruptControl == TIMER0_INT_ENABLE)
        SET_BIT(TIMSK, TOIE0);
        if(!GET_BIT(SREG, SREG_I))
            SET_BIT(SREG, SREG_I); 
    else
        CLR_BIT(TIMSK, TOIE0);
}

void TIMER0_voidSetCompareMatch(u8 copy_u8MatchValue, u8 copy_u8OC0PinAction)
{
    SET_BIT(DDRB, PB3);
    switch(copy_u8OC0PinAction)
    {
        case TIMER0_OC0_IN_OUT_PIN: CLR_BIT(TCCR0, COM00); CLR_BIT(TCCR0, COM01); break;
        case TIMER0_OC0_TOGGLE_PIN: SET_BIT(TCCR0, COM00); CLR_BIT(TCCR0, COM01); break;
        case TIMER0_OC0_CLEAR_PIN:  CLR_BIT(TCCR0, COM00); SET_BIT(TCCR0, COM01); break;
        case TIMER0_OC0_SET_PIN:    SET_BIT(TCCR0, COM00); SET_BIT(TCCR0, COM01); break;
        default:                    /* do nothing */                              break;
    }
    OCR0 = copy_u8MatchValue;
}

void TIMER0_voidPWMGenerator(u8 copy_u8Mode, u8 copy_u8DutyCycle, u8 copy_u8OC0PinAction)
{
    SET_BIT(DDRB, PB3);
    if(copy_u8Mode == TIMER0_FAST_PWM)
    {
        switch(copy_u8OC0PinAction)
        {
            case TIMER0_SET_OC0_AT_TOP: 
                CLR_BIT(TCCR0, COM00); SET_BIT(TCCR0, COM01); 
                OCR0 = ((copy_u8DutyCycle/100.0)*256);         break;
            case TIMER0_CLR_OC0_AT_TOP: 
                SET_BIT(TCCR0, COM00); SET_BIT(TCCR0, COM01); 
                OCR0 = (256 - ((copy_u8DutyCycle/100.0)*256)); break;
            default:    /* do nothing */                       break;
        }
    }
    else if(copy_u8Mode == TIMER0_PWM_PHASE)
    {
        switch(copy_u8OC0PinAction)
        {
            case TIMER0_CLR_UP_SET_DOWN:
                CLR_BIT(TCCR0, COM00);  SET_BIT(TCCR0, COM01);
                OCR0 = (((copy_u8DutyCycle/100.0)*510)/2);     break;
            case TIMER0_SET_UP_CLR_DOWN:
                SET_BIT(TCCR0, COM00);  SET_BIT(TCCR0, COM01);
                OCR0 = (255-((copy_u8DutyCycle/100.0)*510)/2); break;
            default:    /* do nothing */                       break;
        }
    }
    else { /* do nothing */ }
}

void TIMER0_voidSetCompareValue(u8 copy_u8MatchValue)
{
    OCR0 = copy_u8MatchValue;
}

void TIMER0_voidCompareINTControl(u8 copy_u8InterruptControl)
{
    if(copy_u8InterruptControl == TIMER0_INT_ENABLE)
        SET_BIT(TIMSK, OCIE0);
        if(!GET_BIT(SREG, SREG_I))
            SET_BIT(SREG, SREG_I); 
    else
        CLR_BIT(TIMSK, OCIE0);
}

void TIMER0_voidTimerStop(void)
{
    TCCR0 &= 0b11111000;
}

void TIMER0_voidOverflowCallback(ptrVoidFunction copy_ptrVoidFunction)
{
    if(copy_ptrVoidFunction != NULL)
        ISR_TIMER0_OVERFLOW_PTR = copy_ptrVoidFunction;
}

void TIMER0_voidCompareCallback(ptrVoidFunction copy_ptrVoidFunction)
{
    if(copy_ptrVoidFunction != NULL)
        ISR_TIMER0_COMPARE_PTR = copy_ptrVoidFunction;
}

ISR(TIMER0_OVF_vect)
{
    if(ISR_TIMER0_OVERFLOW_PTR != NULL)
        ISR_TIMER0_OVERFLOW_PTR();
    else
        { /* do nothing */ }
}


ISR(TIMER0_COMP_vect)
{
	if(ISR_TIMER0_COMPARE_PTR != NULL)
        ISR_TIMER0_COMPARE_PTR();
    else
        { /* do nothing */ }
}