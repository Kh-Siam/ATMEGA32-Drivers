#ifndef     SPI_H
#define     SPI_H

/* ********** Data Order ********** */
#define SPI_DATA_ORDER_MSB      1
#define SPI_DATA_ORDER_LSB      2
/* ********** Clock Settings(Polarity and Phase) ********** */
#define SPI_RISING_SAMPLE       1
#define SPI_RISING_SETUP        2
#define SPI_FALLING_SAMPLE      3
#define SPI_FALLING_SETUP       4
/* ********** Clock Speed ********** */
#define SPI_NORMAL_SPEED        1
#define SPI_DOUBLE_SPEED        2
/* ********** SCK and Oscillator Frequency ********** */
#define SPI_DIV_4               0
#define SPI_DIV_16              1
#define SPI_DIV_64              2
#define SPI_DIV_128             3
#define SPI_DIV_2               4
#define SPI_DIV_8               5
#define SPI_DIV_32              6
#define SPI_DIV_64_2            7
/* ********** APIs ********** */
void SPI_voidMasterInit         (u8 copy_u8DataOrder, u8 copy_u8ClockSetting, u8 copy_u8Speed, u8 copy_u8Frequency);
void SPI_voidSlaveInit          (u8 copy_u8DataOrder, u8 copy_u8ClockSetting);
void SPI_voidEnable             (void);
void SPI_voidDisable            (void);
void SPI_voidMasterTransmitData (u8 copy_u8Data);
void SPI_voidSlaveTransmitData  (u8 copy_u8Data);
u8   SPI_u8ReceiveData          (void);
u8   SPI_u8ReceiveTransmission  (u8 copy_u8Data);

#endif