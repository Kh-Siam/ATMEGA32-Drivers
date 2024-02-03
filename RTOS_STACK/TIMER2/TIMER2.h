#ifndef TIMER2_H
#define TIMER2_H

/*
    Note that I am using this timer for 
    RTOS, so most of these definitions
    and functions aren't going to be used 
    but I just wanted to create a full 
    driver for Timer 2
*/

/* ********** Timer Modes ********** */
#define TIMER2_NORMAL   	    0
#define TIMER2_CTC		        1
#define TIMER2_PWM_PHASE        2
#define TIMER2_FAST_PWM		    3
/* ********** Prescaler ********** */
#define TIMER2_STOPPED          0
#define TIMER2_NO_PRESCALER     1
#define TIMER2_PRESCALER_8	    2
#define TIMER2_PRESCALER_32		3
#define TIMER2_PRESCALER_64	    4
#define TIMER2_PRESCALER_128	5
#define TIMER2_PRESCALER_256    6
#define TIMER2_PRESCALER_1024   7
/* ********** Interrupt Control ********** */
#define TIMER2_INT_ENABLE       1
#define TIMER2_INT_DISABLE      0
/* *********** OC2 Pin Action ********** */
#define TIMER2_OC2_IN_OUT_PIN	0
#define TIMER2_OC2_TOGGLE_PIN	1
#define TIMER2_OC2_CLEAR_PIN	2
#define TIMER2_OC2_SET_PIN		3
/* *********** OC2 Pin Action Fast PWM ********** */
#define TIMER2_SET_OC2_AT_TOP   1
#define TIMER2_CLR_OC2_AT_TOP   2
/* *********** OC2 Pin Action Phase PWM ********** */
#define TIMER2_CLR_UP_SET_DOWN  1
#define TIMER2_SET_UP_CLR_DOWN  2
/* ********** APIs ********** */
void TIMER2_voidInit                (u8 copy_u8Mode);
void TIMER2_voidSetPreValue         (u8 copy_u8Value);
void TIMER2_voidTimerStart          (u8 copy_u8Prescaler);
void TIMER2_voidOverflowINTControl  (u8 copy_u8InterruptControl);
void TIMER2_voidSetCompareMatch     (u8 copy_u8MatchValue, u8 copy_u8OC2PinAction);
void TIMER2_voidPWMGenerator        (u8 copy_u8Mode, u8 copy_u8DutyCycle, u8 copy_u8OC2PinAction);
void TIMER2_voidSetCompareValue     (u8 copy_u8MatchValue);
void TIMER2_voidCompareINTControl   (u8 copy_u8InterruptControl);
void TIMER2_voidTimerStop           (void);
void TIMER2_voidOverflowCallback    (ptrVoidFunction copy_ptrVoidFunction);
void TIMER2_voidCompareCallback     (ptrVoidFunction copy_ptrVoidFunction);

#endif