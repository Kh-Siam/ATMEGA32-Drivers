#ifndef RTOS_H
#define RTOS_H

/* ********** Timer 2 Prescaler Options ********** */
#define RTOS_STOPPED          0
#define RTOS_NO_PRESCALER     1
#define RTOS_PRESCALER_8	  2
#define RTOS_PRESCALER_32     3
#define RTOS_PRESCALER_64	  4
#define RTOS_PRESCALER_128	  5
#define RTOS_PRESCALER_256    6
#define RTOS_PRESCALER_1024   7
/* ********** APIs ********** */
void RTOS_voidInit            (u8 copy_u8Prescaler, u8 copy_u8MatchValue, u8 copy_u8NumOfTasks);
void RTOS_voidCreateTask      (u8 copy_u8Priority, u16 copy_u16Periodicity, ptrVoidFunction copy_ptrVoidFunction);

#endif