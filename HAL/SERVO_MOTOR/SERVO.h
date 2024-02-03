#ifndef SERVO_H
#define SERVO_H

/*
    Note that this driver has direct access on 
    Timer 1 registers of the atmega32, meaning
    that it doesn't need a driver for timer 1
    and the Servo motor should be connected to
    either Pin 4 or 5 of Port D 
*/

#define SERVO_OC1A_PIN  1
#define SERVO_OC1B_PIN  2

void SERVO_voidInit     (u8 copy_u8OC1Pin);
u8   SERVO_u8MapADC     (u16 copy_u16DigitalValue);
void SERVO_voidSetAngle (u8 copy_u8Angle, u8 copy_u8OC1Pin);

#endif