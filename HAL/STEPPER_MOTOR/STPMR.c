#include <avr/io.h>                 /* Make sure to do it yourself later */
#include <util/delay.h>             /* Make sure to do it yourself later */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/DIO/DIO.h"
#include "STPMR.h"

void STPMR_voidInit(u8 copy_u8Port)
{
    DIO_voidSetPinDirection(copy_u8Port, STPMR_COIL_BLUE, DIO_OUTPUT);
    DIO_voidSetPinDirection(copy_u8Port, STPMR_COIL_PINK, DIO_OUTPUT);
    DIO_voidSetPinDirection(copy_u8Port, STPMR_COIL_YELLOW, DIO_OUTPUT);
    DIO_voidSetPinDirection(copy_u8Port, STPMR_COIL_ORANGE, DIO_OUTPUT);
}

void STPMR_voidRotateCW(u8 copy_u8Port)
{
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_BLUE, DIO_HIGH);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_PINK, DIO_LOW);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_YELLOW, DIO_LOW);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_ORANGE, DIO_LOW);
    _delay_ms(2);

    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_BLUE, DIO_LOW);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_PINK, DIO_HIGH);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_YELLOW, DIO_LOW);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_ORANGE, DIO_LOW);
    _delay_ms(2);

    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_BLUE, DIO_LOW);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_PINK, DIO_LOW);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_YELLOW, DIO_HIGH);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_ORANGE, DIO_LOW);
    _delay_ms(2);

    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_BLUE, DIO_LOW);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_PINK, DIO_LOW);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_YELLOW, DIO_LOW);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_ORANGE, DIO_HIGH);
    _delay_ms(2);
}

void STPMR_voidRotateACW(u8 copy_u8Port)
{
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_BLUE, DIO_LOW);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_PINK, DIO_LOW);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_YELLOW, DIO_LOW);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_ORANGE, DIO_HIGH);
    _delay_ms(2);

    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_BLUE, DIO_LOW);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_PINK, DIO_LOW);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_YELLOW, DIO_HIGH);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_ORANGE, DIO_LOW);
    _delay_ms(2);

    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_BLUE, DIO_LOW);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_PINK, DIO_HIGH);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_YELLOW, DIO_LOW);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_ORANGE, DIO_LOW);
    _delay_ms(2);

    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_BLUE, DIO_HIGH);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_PINK, DIO_LOW);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_YELLOW, DIO_LOW);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_ORANGE, DIO_LOW);
    _delay_ms(2);
}

void STPMR_voidStop(u8 copy_u8Port)
{
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_BLUE, DIO_LOW);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_PINK, DIO_LOW);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_YELLOW, DIO_LOW);
    DIO_voidSetPinValue(copy_u8Port, STPMR_COIL_ORANGE, DIO_LOW);
}