#include <avr/io.h>                 /* Make sure to do it yourself later */
#include <util/delay.h>             /* Make sure to do it yourself later */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/DIO/DIO.h"
#include "SERVO.h"

void SERVO_voidInit(u8 copy_u8OC1Pin)
{
    /* 
        make pin connected to the servo pin as output 
        and clear it on compare match and set at bottom
    */
    switch(copy_u8OC1Pin)
    {
        case SERVO_OC1A_PIN:
            SET_BIT(DDRD, PD5);
            CLR_BIT(TCCR1A, COM1A0); SET_BIT(TCCR1A, COM1A1); 
            break;
        case SERVO_OC1B_PIN:    
            SET_BIT(DDRD, PD4);
            CLR_BIT(TCCR1A, COM1B0); SET_BIT(TCCR1A, COM1B1); 
            break;
        default: /* do nothing */                      break;
    }

    /* select fast PWM mode for timer1 with ICR1 as TOP */
    CLR_BIT(TCCR1A, WGM10); SET_BIT(TCCR1A, WGM11);
    SET_BIT(TCCR1B, WGM12); SET_BIT(TCCR1B, WGM13);

    /* make TOP = 20000 for 50 Hz signal */
    ICR1 = 19999;

    /* setting prescaler to be divided by 8 */
    TCCR1B &= 0b11111000;
    TCCR1B |= 0b00000010;
}

u8   SERVO_u8MapADC(u16 copy_u16DigitalValue)
{
    return ((180*(u32)copy_u16DigitalValue)/1023);
}

void SERVO_voidSetAngle(u8 copy_u8Angle, u8 copy_u8OC1Pin)
{
    u16 local_u16PulseWidth = ((((u32)copy_u8Angle*1000)/180) + 1000);
    switch(copy_u8OC1Pin)
    {
        case SERVO_OC1A_PIN: OCR1A = local_u16PulseWidth; break;
        case SERVO_OC1B_PIN: OCR1B = local_u16PulseWidth; break;
        default: /* do nothing */ break;
    }
}