#ifndef UART_H
#define UART_H

/* ********** Speed Mode ********** */
#define UART_NORMAL_MODE          1
#define UART_DOUBLE_SPEED         2
/* ********** Normal Speed, 8MHz ********** */
#define UART_BAUD_RATE_2400       207
#define UART_BAUD_RATE_4800       103
#define UART_BAUD_RATE_9600       51
#define UART_BAUD_RATE_14_4k      34
#define UART_BAUD_RATE_19_2k      25
#define UART_BAUD_RATE_28_8k      16
#define UART_BAUD_RATE_38_4k      12
#define UART_BAUD_RATE_57_6k      8
#define UART_BAUD_RATE_76_8k      6
#define UART_BAUD_RATE_115_2k     3
#define UART_BAUD_RATE_230_4k     1
#define UART_BAUD_RATE_250k       1
#define UART_BAUD_RATE_0_5M       0
/* ********** Double Speed, 8MHz ********** */
#define UART_U2X_BAUD_RATE_2400   416
#define UART_U2X_BAUD_RATE_4800   207
#define UART_U2X_BAUD_RATE_9600   103
#define UART_U2X_BAUD_RATE_14_4k  68
#define UART_U2X_BAUD_RATE_19_2k  51
#define UART_U2X_BAUD_RATE_28_8k  34
#define UART_U2X_BAUD_RATE_38_4k  25
#define UART_U2X_BAUD_RATE_57_6k  16
#define UART_U2X_BAUD_RATE_76_8k  12
#define UART_U2X_BAUD_RATE_115_2k 8
#define UART_U2X_BAUD_RATE_230_4k 3
#define UART_U2X_BAUD_RATE_250k   3
#define UART_U2X_BAUD_RATE_0_5M   1
#define UART_U2X_BAUD_RATE_1M     0
/* ********** APIs ********** */
void UART_voidInit                (u8 copy_u8SpeedMode, u16 copy_u16BaudRate);
void UART_voidTransmitData        (u8 copy_u8Data);
u8   UART_u8ReceiveData           (void);

#endif