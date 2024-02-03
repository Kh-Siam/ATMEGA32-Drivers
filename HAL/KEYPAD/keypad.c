#include <avr/io.h>                 /* Make sure to do it yourself later */
#include <util/delay.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/DIO/DIO.h"
#include "keypad.h"

static u8 KEYPAD_ROW_PINS[ROWS] = {KEYPAD_ROW_1, KEYPAD_ROW_2, KEYPAD_ROW_3, KEYPAD_ROW_4};
static u8 KEYPAD_COL_PINS[COLS] = {KEYPAD_COL_1, KEYPAD_COL_2, KEYPAD_COL_3, KEYPAD_COL_4};

void KEYPAD_voidInit(u8 copy_u8KeypadPort)
{
    for(u8 i = 0; i < 8; i++)
    {
        if(i < 4)
            DIO_voidSetPinDirection(copy_u8KeypadPort, KEYPAD_ROW_PINS[i], DIO_OUTPUT);
        else
            DIO_voidSetPinDirection(copy_u8KeypadPort, KEYPAD_COL_PINS[i-4], DIO_INPUT);
    }
    DIO_voidSetPortValue(copy_u8KeypadPort, DIO_PORT_HIGH);
}

u8   KEYPAD_u8GetPressedKey(u8 copy_u8KeypadPort, u8 *copy_u8KeypadKeys)
{
    u8 local_u8Pressed, local_u8Flag = 0;
    u8 local_u8ReturnedValue = CHECK_KEY_PRESSED;

    for(u8 row = 0; row < ROWS; row++)
    {
        DIO_voidSetPinValue(copy_u8KeypadPort, KEYPAD_ROW_PINS[row], DIO_LOW);
        for(u8 col = 0; col < COLS; col++)
        {
            local_u8Pressed = DIO_u8GetPinValue(copy_u8KeypadPort, KEYPAD_COL_PINS[col]);
            if(!local_u8Pressed)
            {
                _delay_ms(25);                                                                /* debouncing */
                local_u8Pressed = DIO_u8GetPinValue(copy_u8KeypadPort, KEYPAD_COL_PINS[col]);           /* checking for noise */
                if(!local_u8Pressed)
                {
                    local_u8ReturnedValue = ITEM(copy_u8KeypadKeys, row, col);

                    while(!local_u8Pressed)                                                           /* handling long press */
                        local_u8Pressed = DIO_u8GetPinValue(copy_u8KeypadPort, KEYPAD_COL_PINS[col]);

                    local_u8Flag = 1;                                                           
                    break;
                }
            }
        }
        DIO_voidSetPinValue(copy_u8KeypadPort, KEYPAD_ROW_PINS[row], DIO_HIGH);
        if(local_u8Flag)
            break;
    }
    return local_u8ReturnedValue;
}