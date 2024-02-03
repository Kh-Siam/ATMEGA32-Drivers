#ifndef KEYPAD_H
#define KEYPAD_H

#define ROWS                    4
#define COLS                    4

#define KEYPAD_ROW_1            DIO_PIN0
#define KEYPAD_ROW_2            DIO_PIN1
#define KEYPAD_ROW_3            DIO_PIN2
#define KEYPAD_ROW_4            DIO_PIN3

#define KEYPAD_COL_1            DIO_PIN4
#define KEYPAD_COL_2            DIO_PIN5
#define KEYPAD_COL_3            DIO_PIN6
#define KEYPAD_COL_4            DIO_PIN7

#define CHECK_KEY_PRESSED       0xff

#define ITEM(KEYS, ROW, COL)    KEYS[COL + ROW * COLS]    

void KEYPAD_voidInit            (u8 copy_u8KeypadPort);
u8   KEYPAD_u8GetPressedKey     (u8 copy_u8KeypadPort, u8 *copy_u8KeypadKeys);

#endif