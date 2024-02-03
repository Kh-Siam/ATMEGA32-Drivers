#ifndef INT_H
#define INT_H

#define INT_INT0            0
#define INT_INT1            1
#define INT_INT2            2

#define INT_FALLING_EDGE    0
#define INT_RISING_EDGE     1
#define INT_ANY_CHANGE      2
#define INT_LOW_LEVEL       3

void INT_voidEnable         (u8 copy_u8INTIndex, u8 copy_u8INTSense);
void INT_voidDisable        (u8 copy_u8INTIndex);
void INT_voidSetCallback    (u8 copy_u8INTIndex, ptrVoidFunction copy_ptrVoidFunction);

#endif