#ifndef WDT_H
#define WDT_H

#define WDT_PRESCALER_16   0
#define WDT_PRESCALER_32   1
#define WDT_PRESCALER_64   2
#define WDT_PRESCALER_128  3
#define WDT_PRESCALER_256  4
#define WDT_PRESCALER_512  5
#define WDT_PRESCALER_1024 6
#define WDT_PRESCALER_2048 7

void WDT_voidInit       (u8 copy_u8Prescaler);
void WDT_voidEnable     (void);
void WDT_voidDisable    (void);

#endif