#ifndef ICU_H 
#define ICU_H

#define ICU_FALLING_EDGE        0
#define ICU_RISING_EDGE         1

#define ICU_STOPPED             0
#define ICU_NO_PRESCALER        1
#define ICU_PRESCALER_8	        2
#define ICU_PRESCALER_64		3
#define ICU_PRESCALER_256	    4
#define ICU_PRESCALER_1024	    5
#define ICU_EXT_FALLING         6
#define ICU_EXT_RISING          7

void ICU_voidInit               (u8 copy_u8Prescaler, u8 copy_u8Trigger);
void ICU_voidChangeTrigger      (u8 copy_u8Trigger);
void ICU_voidSetCallback        (ptrVoidFunction copy_ptrVoidFunction);
u16  ICU_u16ReadValue           (void);
void ICU_voidDisableInterrupt   (void);

#endif