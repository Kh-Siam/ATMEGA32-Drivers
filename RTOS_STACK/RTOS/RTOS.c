#include <avr/io.h>                 /* Make sure to do it yourself later */
#include <avr/interrupt.h>          /* Make sure to do it yourself later */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../TIMER2/TIMER2.h"
#include "RTOS.h"

typedef struct
{
    u16 periodicity;
    ptrVoidFunction ptr;
} RTOS_TASK;
static u8 NUMBER_OF_TASKS;
static RTOS_TASK *RTOS_TASKS = NULL;
static void RTOS_scheduler(void);     /* private function */

void RTOS_voidInit(u8 copy_u8Prescaler, u8 copy_u8MatchValue, u8 copy_u8NumOfTasks)
{
    RTOS_TASKS = malloc(copy_u8NumOfTasks * sizeof(RTOS_TASK));
    NUMBER_OF_TASKS = copy_u8NumOfTasks;
    TIMER2_voidInit(TIMER2_CTC);
    TIMER2_voidCompareINTControl(TIMER2_INT_ENABLE);
    TIMER2_voidSetCompareValue(copy_u8MatchValue);
    TIMER2_voidCompareCallback(&RTOS_scheduler);
    TIMER2_voidTimerStart(copy_u8Prescaler);
}

void RTOS_voidCreateTask(u8 copy_u8Priority, u16 copy_u16Periodicity, ptrVoidFunction copy_ptrVoidFunction)
{
	RTOS_TASKS[copy_u8Priority].periodicity = copy_u16Periodicity;
	RTOS_TASKS[copy_u8Priority].ptr = copy_ptrVoidFunction;
}

static void RTOS_scheduler(void)
{
    static u16 local_u16TickCount = 0;
    local_u16TickCount++;
    for(u8 local_u8Count = 0; local_u8Count < NUMBER_OF_TASKS; local_u8Count++)
    {
        if(!(local_u16TickCount % RTOS_TASKS[local_u8Count].periodicity))
        {
            RTOS_TASKS[local_u8Count].ptr();
        }
        else    { /* do nothing */ }
    }
}
