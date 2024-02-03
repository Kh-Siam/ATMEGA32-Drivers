#ifndef LCD_H
#define LCD_H

#define FUNCTION_SET            0b00111000
#define DISPLAY_ON_OFF          0b00001111
#define CLEAR                   0b00000001
#define ENTRY_MODE_INCREMENT    0b00000110
#define SET_DDRAM_ADDRESS       0b10000000
#define SET_CGRAM_ADDRESS       0b01000000

#define LCD_LINE_1              1
#define LCD_LINE_2              2

#define LCD_COLUMN_1            0
#define LCD_COLUMN_2            1
#define LCD_COLUMN_3            2
#define LCD_COLUMN_4            3
#define LCD_COLUMN_5            4
#define LCD_COLUMN_6            5
#define LCD_COLUMN_7            6
#define LCD_COLUMN_8            7
#define LCD_COLUMN_9            8
#define LCD_COLUMN_10           9
#define LCD_COLUMN_11           10
#define LCD_COLUMN_12           11
#define LCD_COLUMN_13           12
#define LCD_COLUMN_14           13
#define LCD_COLUMN_15           14
#define LCD_COLUMN_16           15

#define LCD_GCRAM_1             0
#define LCD_GCRAM_2             1
#define LCD_GCRAM_3             2
#define LCD_GCRAM_4             3
#define LCD_GCRAM_5             4
#define LCD_GCRAM_6             5
#define LCD_GCRAM_7             6
#define LCD_GCRAM_8             7

void LCD_voidInit               (u8 copy_u8DataPort, u8 copy_u8ControlPort, u8 copy_u8RSPin, u8 copy_u8RWPin, u8 copy_u8ENPin);
void LCD_voidSendCommand        (u8 copy_u8Command);
void LCD_voidSendChar           (u8 copy_u8Char);
void LCD_voidSendString         (u8 *copy_u8String);
void LCD_voidSetLocation        (u8 copy_u8LineNum, u8 copy_u8ColNum);
void LCD_voidSendNumber         (u32 copy_u32Number);
void LCD_voidDrawSpecialChar    (u8 copy_u8CharIndex, u8 *copy_u8SpecialChar);
void LCD_voidSendSpecialChar    (u8 copy_u8CharIndex);

#endif