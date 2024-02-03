#include <avr/io.h>                 /* Make sure to do it yourself later */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "ADC.h"

void ADC_voidInit(u8 copy_u8Channel, u8 copy_u8ReferenceVoltage, u8 copy_u8Prescaler)
{
    CLR_BIT(DDRA, copy_u8Channel);

    SET_BIT(ADCSRA, ADEN);          /* enables ADC */

    switch(copy_u8ReferenceVoltage)
    {
        case ADC_AVCC:      SET_BIT(ADMUX, REFS0);  CLR_BIT(ADMUX, REFS1);  break;
        case ADC_AREF:      CLR_BIT(ADMUX, REFS0);  CLR_BIT(ADMUX, REFS1);  break;
        case ADC_2_56_V:    SET_BIT(ADMUX, REFS0);  SET_BIT(ADMUX, REFS1);  break;
        default:			/* do nothing */								break;
    }

    CLR_BIT(ADMUX, ADLAR);
    ADCSRA &= 0b11111000;
    ADCSRA |= copy_u8Prescaler;
}

/* Single Conversion Mode */
u16  ADC_u16GetDigitalValue(u8 copy_u8Channel)
{
    ADMUX &= 0b11100000;
    ADMUX |= copy_u8Channel;

    SET_BIT(ADCSRA, ADSC);

    while(!GET_BIT(ADCSRA, ADIF));
    SET_BIT(ADCSRA, ADIF);

    return ADC & 0x03FF;
}

void ADC_voidDisable(void)
{
    CLR_BIT(ADCSRA, ADEN);
}
