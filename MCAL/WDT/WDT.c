#include <avr/interrupt.h>          /* Make sure to do it yourself later */
#include <avr/io.h>                 /* Make sure to do it yourself later */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "WDT.h"

void WDT_voidInit(u8 copy_u8Prescaler)
{
    switch(copy_u8Prescaler)
    {
        case WDT_PRESCALER_16:   CLR_BIT(WDTCR, WDP0); CLR_BIT(WDTCR, WDP1); CLR_BIT(WDTCR, WDP2); break;
        case WDT_PRESCALER_32:   CLR_BIT(WDTCR, WDP0); CLR_BIT(WDTCR, WDP1); SET_BIT(WDTCR, WDP2); break;
        case WDT_PRESCALER_64:   CLR_BIT(WDTCR, WDP0); SET_BIT(WDTCR, WDP1); CLR_BIT(WDTCR, WDP2); break;
        case WDT_PRESCALER_128:  CLR_BIT(WDTCR, WDP0); SET_BIT(WDTCR, WDP1); SET_BIT(WDTCR, WDP2); break;
        case WDT_PRESCALER_256:  SET_BIT(WDTCR, WDP0); CLR_BIT(WDTCR, WDP1); CLR_BIT(WDTCR, WDP2); break;
        case WDT_PRESCALER_512:  SET_BIT(WDTCR, WDP0); CLR_BIT(WDTCR, WDP1); SET_BIT(WDTCR, WDP2); break;
        case WDT_PRESCALER_1024: SET_BIT(WDTCR, WDP0); SET_BIT(WDTCR, WDP1); CLR_BIT(WDTCR, WDP2); break;
        case WDT_PRESCALER_2048: SET_BIT(WDTCR, WDP0); SET_BIT(WDTCR, WDP1); SET_BIT(WDTCR, WDP2); break;
        default:                 /* do nothing */                                                  break; 
    }
}

void WDT_voidEnable(void)
{
    SET_BIT(WDTCR, WDE);
}

void WDT_voidDisable(void)
{
    WDTCR = (1 << WDTOE) | (1 << WDE);
    WDTCR = 0x00;
}