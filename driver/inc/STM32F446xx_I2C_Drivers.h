

#ifndef INC_STM32F446XX_I2C_DRIVERS_H_
#define INC_STM32F446XX_I2C_DRIVERS_H_

#include "STM32F446xx.h"

/*
 * Configuration structure for I2Cx Peripheral
 */
typedef struct
{
	uint32_t I2C_SCLSpeed;  		//@I2C_SCLSpeed
	uint8_t  I2C_DeviceAddress;
	uint8_t  I2C_ACKControl;		//@I2C_ACKControl
	uint16_t I2C_FMDutyCycle;		//@I2C_FMDutyCycle
}I2C_Config_t;

/*
 * Handle structure for I2Cx Peripheral
 */
typedef struct
{
	I2C_RegDef_t	*pI2Cx;
	I2C_Config_t	I2C_Config;
}I2C_Handle_t;

/*
 * @I2C_SCLSpeed
 */
#define I2C_SCL_SPEED_SM 		100000
#define I2C_SCL_SPEED_FM_2K 	200000
#define I2C_SCL_SPEED_FM_4K 	400000

/*
 * @I2C_ACKControl
 */
#define I2C_ACK_ENABLE		1
#define I2C_ACK_DISABLE		0

/*
 * @I2C_FMDutyCycle
 */
#define I2C_FM_DUTY_2		0
#define I2C_FM_DUTY_16_9	1


/* ************************************
 * API support by this driver
 ***************************************/


void I2C_PeriClockControl(I2C_RegDef_t *pI2Cx, uint8_t EnorDI );

void I2C_Init(I2C_Handle_t *pI2CHandle);
void I2C_DeInit(I2C_RegDef_t *pI2Cx);



void I2C_IRQInterruptConfig(uint8_t IRQNumber , uint8_t EnorDi );
void I2C_IRQPriorityConfig (uint8_t IRQNumber ,uint32_t IRQPriority);


void I2C_PeripheralControl(I2C_RegDef_t *pI2Cx , uint8_t EnorDI );
uint8_t I2C_GetFlagStatus(I2C_RegDef_t *pI2Cx , uint32_t FlagName);

void I2C_ApplicationEventCallback(I2C_Handle_t *pI2CHandle,uint8_t AppEv);


#endif /* INC_STM32F446XX_I2C_DRIVERS_H_ */
