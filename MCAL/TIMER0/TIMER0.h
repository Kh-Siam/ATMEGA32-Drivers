#ifndef TIMER0_H
#define TIMER0_H

/* ********** Timer Modes ********** */
#define TIMER0_NORMAL	        0
#define TIMER0_CTC	            1
#define TIMER0_PWM_PHASE		2
#define TIMER0_FAST_PWM		    3
/* ********** Prescaler ********** */
#define TIMER0_STOPPED          0
#define TIMER0_NO_PRESCALER     1
#define TIMER0_PRESCALER_8	    2
#define TIMER0_PRESCALER_64		3
#define TIMER0_PRESCALER_256	4
#define TIMER0_PRESCALER_1024	5
#define TIMER0_EXT_FALLING      6
#define TIMER0_EXT_RISING       7
/* ********** Interrupt Control ********** */
#define TIMER0_INT_ENABLE       1
#define TIMER0_INT_DISABLE      0
/* *********** OC0 Pin Action ********** */
#define TIMER0_OC0_IN_OUT_PIN	0
#define TIMER0_OC0_TOGGLE_PIN	1
#define TIMER0_OC0_CLEAR_PIN	2
#define TIMER0_OC0_SET_PIN		3
/* *********** OC0 Pin Action Fast PWM ********** */
#define TIMER0_SET_OC0_AT_TOP   1
#define TIMER0_CLR_OC0_AT_TOP   2
/* *********** OC0 Pin Action Phase PWM ********** */
#define TIMER0_CLR_UP_SET_DOWN  1
#define TIMER0_SET_UP_CLR_DOWN  2
/* ********** APIs ********** */
void TIMER0_voidInit                (u8 copy_u8Mode);
void TIMER0_voidSetPreValue         (u8 copy_u8Value);
void TIMER0_voidTimerStart          (u8 copy_u8Prescaler);
void TIMER0_voidOverflowINTControl  (u8 copy_u8InterruptControl);
void TIMER0_voidSetCompareMatch     (u8 copy_u8MatchValue, u8 copy_u8OC0PinAction);
void TIMER0_voidPWMGenerator        (u8 copy_u8Mode, u8 copy_u8DutyCycle, u8 copy_u8OC0PinAction);
void TIMER0_voidSetCompareValue     (u8 copy_u8MatchValue);
void TIMER0_voidCompareINTControl   (u8 copy_u8InterruptControl);
void TIMER0_voidTimerStop           (void);
void TIMER0_voidOverflowCallback    (ptrVoidFunction copy_ptrVoidFunction);
void TIMER0_voidCompareCallback     (ptrVoidFunction copy_ptrVoidFunction);

#endif