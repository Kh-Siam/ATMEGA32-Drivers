#ifndef STPMR_H_
#define STPMR_H_

#define STPMR_COIL_BLUE     			DIO_PIN0
#define STPMR_COIL_PINK     			DIO_PIN1
#define STPMR_COIL_YELLOW   			DIO_PIN2
#define STPMR_COIL_ORANGE   			DIO_PIN3

void STPMR_voidInit         (u8 copy_u8Port);
void STPMR_voidRotateCW     (u8 copy_u8Port);
void STPMR_voidRotateACW    (u8 copy_u8Port);
void STPMR_voidStop         (u8 copy_u8Port);

#endif