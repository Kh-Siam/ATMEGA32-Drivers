#ifndef DIO_H
#define DIO_H

/* ********** Input and Output pin values ********** */
#define DIO_HIGH        1
#define DIO_LOW         0
/* ********** Input and Output port values ********** */
#define DIO_PORT_HIGH   0xff
#define DIO_PORT_LOW    0x00
/* ********** Input and Output pin config based on mc ********** */
#define DIO_OUTPUT      1
#define DIO_INPUT       0
/* ********** Input and Output port config based on mc ********** */
#define DIO_PORT_OUTPUT 0xff
#define DIO_PORT_INPUT  0x00
/* ********** AVR Ports ********** */
#define DIO_PORTA       0
#define DIO_PORTB       1
#define DIO_PORTC       2
#define DIO_PORTD       3
/* ********** AVR Pins ********** */
#define DIO_PIN0        0
#define DIO_PIN1        1
#define DIO_PIN2        2
#define DIO_PIN3        3
#define DIO_PIN4        4
#define DIO_PIN5        5
#define DIO_PIN6        6
#define DIO_PIN7        7
/* ********** APIs ********** */
void DIO_voidSetPinDirection    (u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Direction);   /* DDR   Register */
void DIO_voidSetPinValue        (u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Value);       /* PORT  Register */
u8   DIO_u8GetPinValue          (u8 copy_u8Port, u8 copy_u8Pin);                        /* PIN   Register */
void DIO_voidSetPortDirection   (u8 copy_u8Port, u8 copy_u8Direction);                  /* DDR   Register */
void DIO_voidSetPortValue       (u8 copy_u8Port, u8 copy_u8Value);                      /* PORT  Register */
u8   DIO_u8GetPortValue         (u8 copy_u8Port);                                       /* PIN   Register */

void DIO_voidTogglePin          (u8 copy_u8Port, u8 copy_u8Pin);                        /* PORT  Register */
void DIO_voidTogglePort         (u8 copy_u8Port);                                       /* PORT  Register */

u8   DIO_u8GetOutPortState      (u8 copy_u8Port);                                       /* used to get the current state of an output port */

#endif