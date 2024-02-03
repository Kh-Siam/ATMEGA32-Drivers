#ifndef ADC_H
#define ADC_H

#define ADC_AVCC            0
#define ADC_AREF            1
#define ADC_2_56_V          2

#define ADC_DIV_2           1
#define ADC_DIV_4           2
#define ADC_DIV_8           3
#define ADC_DIV_16          4
#define ADC_DIV_32          5 
#define ADC_DIV_64          6
#define ADC_DIV_128         7

#define ADC_CHANNEL_0       0
#define ADC_CHANNEL_1       1
#define ADC_CHANNEL_2       2
#define ADC_CHANNEL_3       3
#define ADC_CHANNEL_4       4
#define ADC_CHANNEL_5       5
#define ADC_CHANNEL_6       6
#define ADC_CHANNEL_7       7

void ADC_voidInit           (u8 copy_u8Channel, u8 copy_u8ReferenceVoltage, u8 copy_u8Prescaler);
u16  ADC_u16GetDigitalValue (u8 copy_u8Channel);
void ADC_voidDisable        (void);

#endif