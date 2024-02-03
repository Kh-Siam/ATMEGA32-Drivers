#include <avr/io.h>                 /* Make sure to do it yourself later */
#include <util/delay.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/DIO/DIO.h"
#include "LCD.h"

static u8 LCD_DATA_PORT;
static u8 LCD_CONTROL_PORT;
static u8 RS, RW, EN;

void LCD_voidInit(u8 copy_u8DataPort, u8 copy_u8ControlPort, u8 copy_u8RSPin, u8 copy_u8RWPin, u8 copy_u8ENPin)
{
    LCD_DATA_PORT = copy_u8DataPort; LCD_CONTROL_PORT = copy_u8ControlPort;
    RS = copy_u8RSPin; RW = copy_u8RWPin; EN = copy_u8ENPin;

    DIO_voidSetPortDirection(LCD_DATA_PORT, DIO_PORT_OUTPUT);
    DIO_voidSetPinDirection(LCD_CONTROL_PORT, RS, DIO_OUTPUT);
    DIO_voidSetPinDirection(LCD_CONTROL_PORT, RW, DIO_OUTPUT);
    DIO_voidSetPinDirection(LCD_CONTROL_PORT, EN, DIO_OUTPUT);

    _delay_ms(35);
    LCD_voidSendCommand(FUNCTION_SET);
    _delay_us(50);
    LCD_voidSendCommand(DISPLAY_ON_OFF);
    _delay_us(50);
    LCD_voidSendCommand(CLEAR);
    _delay_ms(2);
    LCD_voidSendCommand(ENTRY_MODE_INCREMENT);
}

void LCD_voidSendCommand(u8 copy_u8Command)
{
    DIO_voidSetPinValue(LCD_CONTROL_PORT, RS, DIO_LOW);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, RW, DIO_LOW);
    DIO_voidSetPortValue(LCD_DATA_PORT, copy_u8Command);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, EN, DIO_HIGH);
    _delay_us(1);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, EN, DIO_LOW);
}

void LCD_voidSendChar(u8 copy_u8Char)
{
    DIO_voidSetPinValue(LCD_CONTROL_PORT, RS, DIO_HIGH);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, RW, DIO_LOW);
    DIO_voidSetPortValue(LCD_DATA_PORT, copy_u8Char);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, EN, DIO_HIGH);
    _delay_us(1);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, EN, DIO_LOW);
}

void LCD_voidSendString(u8 *copy_u8String)
{
    u8 local_u8Index = 0;
    while(copy_u8String[local_u8Index] != '\0')
        LCD_voidSendChar(copy_u8String[local_u8Index++]);
}

void LCD_voidSetLocation(u8 copy_u8LineNum, u8 copy_u8ColNum)
{
    switch(copy_u8LineNum)
    {
        case LCD_LINE_1:    LCD_voidSendCommand(SET_DDRAM_ADDRESS + copy_u8ColNum);        break;
        case LCD_LINE_2:    LCD_voidSendCommand(SET_DDRAM_ADDRESS + 0x40 + copy_u8ColNum); break;
    }
}

void LCD_voidSendNumber(u32 copy_u32Number)
{
    u8 local_u8Buffer[10], local_u8Digits = 0;
    do {
        local_u8Buffer[local_u8Digits++] = '0' + (copy_u32Number % 10);
        copy_u32Number /= 10;
    } while (copy_u32Number > 0);
    for (u8 i = 0, j = local_u8Digits - 1; i < j; i++, j--) {
        u8 temp = local_u8Buffer[i];
        local_u8Buffer[i] = local_u8Buffer[j];
        local_u8Buffer[j] = temp;
    }
    for(u8 i = 0; i < local_u8Digits; i++)
        LCD_voidSendChar(local_u8Buffer[i]);
}

void LCD_voidDrawSpecialChar(u8 copy_u8CharIndex, u8 *copy_u8SpecialChar)
{
    copy_u8CharIndex &= 0x07;          /* only 8 locations in CGRAM */
    LCD_voidSendCommand(SET_CGRAM_ADDRESS + (copy_u8CharIndex*8));
    _delay_us(40);
    for(u8 i = 0; i < 8; i++)
        LCD_voidSendChar(copy_u8SpecialChar[i]);
    LCD_voidSendCommand(SET_DDRAM_ADDRESS);
}

void LCD_voidSendSpecialChar(u8 copy_u8CharIndex)
{
    copy_u8CharIndex &= 0x07;          /* only 8 locations in CGRAM */
    LCD_voidSendChar(copy_u8CharIndex);
}