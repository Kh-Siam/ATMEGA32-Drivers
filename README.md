# ATMEGA32 Drivers
These are drivers that I have implemented. This repo includes most of the drivers for the atmega32 but not all. You'll find the TIMER1 driver missing, but timer1 was used in the implementation of the servo motor driver in the HAL folder. 

I am also using the following libraries:
- avr/io.h
- util/delay.h
- avr/interrupt.h

The TIMER2 driver is used for my simple RTOS implementation and will be found in the RTOS_STACK folder.

All the drivers were tested using Proteus simulation and used in multiple applications. 
