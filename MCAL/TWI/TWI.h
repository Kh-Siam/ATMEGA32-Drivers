#ifndef TWI_H
#define TWI_H

#define CPU_FREQ                        8000000
/* ********** Status Code ********** */
#define TWI_START_CONDITION             0x08
#define TWI_REPEATED_START              0x10
/* ********** Master Transmitter Status Code ********** */
#define TWI_MASTER_SLA_W_ACK            0x18
#define TWI_MASTER_SLA_W_NACK           0x20
#define TWI_MASTER_DATA_W_ACK           0x28
#define TWI_MASTER_DATA_W_NACK          0x30
/* ********** Master Receiver Status Code ********** */
#define TWI_MASTER_SLA_R_ACK            0x40
#define TWI_MASTER_SLA_R_NACK           0x48
#define TWI_MASTER_DATA_R_ACK           0x50
#define TWI_MASTER_DATA_R_NACK          0x58 
/* ********** Slave Transmitter Status Code ********** */
#define TWI_SLAVE_SLA_R_ACK             0xA8
#define TWI_SLAVE_DATA_W_ACK            0xB8
#define TWI_SLAVE_DATA_W_NACK           0xC0
#define TWI_SLAVE_LAST_BYTE_ACK         0xC8
/* ********** Slave Receiver Status Code ********** */
#define TWI_SLAVE_SLA_W_ACK             0x60
#define TWI_SLAVE_DATA_R_ACK            0x80
#define TWI_SLAVE_DATA_NACK             0x88
#define TWI_SLAVE_REPEATED_START_STOP   0xA0
/* ********** Prescaler ********** */
#define TWI_PRESCALER_1                 0
#define TWI_PRESCALER_4                 1
#define TWI_PRESCALER_16                2
#define TWI_PRESCALER_64                3
/* ********** APIs ********** */
void TWI_voidMasterInit                 (u8 copy_u8Prescaler, u32 copy_u32Frequency);
void TWI_voidSlaveInit                  (u8 copy_u8Address);
void TWI_voidEnable                     (void);
void TWI_voidDisable                    (void);
void TWI_voidEnableInterrupt            (void);
void TWI_voidSetCallBack                (ptrVoidFunction copy_ptrVoidFunction);
void TWI_voidDisableInterrupt           (void);
void TWI_voidStartCondition             (void);
void TWI_voidStopCondition              (void);
void TWI_voidSlaveAddressWrite	        (u8 copy_u8SlaveAddress);
void TWI_voidSlaveAddressRead	        (u8 copy_u8SlaveAddress);
void TWI_voidMasterSendData 	        (u8 copy_u8Data);
u8	 TWI_u8MasterReceiveData	        (void);
u8	 TWI_u8SlaveReceiveData		        (void);
void TWI_voidSlaveSendData              (u8 copy_u8Data);
u8   TWI_u8GetStatus                    (void);

#endif