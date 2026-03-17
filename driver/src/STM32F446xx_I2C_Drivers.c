#include "STM32F446xx_I2C_Drivers.h"



/* @Function Name	-
 * @Brief			-
 * @Parameter[1]	-
 * @Parameter[2]	-
 * @Parameter[3]	-
 * @Return			-
 * @note			-
 */
void I2C_PeriClockControl(I2C_RegDef_t *pI2Cx, uint8_t EnorDI )
{
	if(EnorDI == ENABLE)
	{
		if(pI2Cx == I2C1)
		{
			I2C1_PCLK_EN();
		}else if(pI2Cx == I2C2)
		{
			I2C2_PCLK_EN();
		}else if(pI2Cx == I2C3)
		{
			I2C3_PCLK_EN();
		}

	}else
	{
		if(pI2Cx == I2C1)
		{
			I2C1_PCLK_DI();
		}else if(pI2Cx == I2C2)
		{
			I2C2_PCLK_DI();
		}else if(pI2Cx == I2C3)
		{
			I2C3_PCLK_DI();
		}
	}
}



/* @Function Name	-
 * @Brief			-
 * @Parameter[1]	-
 * @Parameter[2]	-
 * @Parameter[3]	-
 * @Return			-
 * @note			-
 */
void I2C_Init(I2C_Handle_t *pI2CHandle);



/* @Function Name	-
 * @Brief			-
 * @Parameter[1]	-
 * @Parameter[2]	-
 * @Parameter[3]	-
 * @Return			-
 * @note			-
 */
void I2C_DeInit(I2C_RegDef_t *pI2Cx)
{
	if(pI2Cx == I2C1)
	{
		I2C1_REG_RESET();
	}else if (pI2Cx == I2C2)
	{
		I2C2_REG_RESET();
	}else if (pI2Cx == I2C3)
	{
		I2C3_REG_RESET();
	}
}



/* @Function Name	-
 * @Brief			-
 * @Parameter[1]	-
 * @Parameter[2]	-
 * @Parameter[3]	-
 * @Return			-
 * @note			-
 */
void I2C_IRQInterruptConfig(uint8_t IRQNumber , uint8_t EnorDi )
{
	if (EnorDi == ENABLE)
		{
			if (IRQNumber <= 31)
			{
				//Program ISER0 Register
				*NVIC_ISER0 |= (1 << IRQNumber);
			}else if (IRQNumber > 31 && IRQNumber <= 63)
			{
				//Program ISER1 Register
				*NVIC_ISER1 |= (1 << IRQNumber % 31);
			}else if (IRQNumber > 63 && IRQNumber <= 95)
			{
				//Program ISER2 Register
				*NVIC_ISER2 |= (1 << IRQNumber % 64);
			}
		}else
		{
			if (IRQNumber <= 31)
			{
				//Program ICER0 Register
				*NVIC_ICER0 |= (1 << IRQNumber);
			}else if (IRQNumber > 31 && IRQNumber <= 63)
			{
				//Program ICER1 Register
				*NVIC_ICER1 |= (1 << IRQNumber % 31);
			}else if (IRQNumber > 63 && IRQNumber <= 95)
			{
				//Program ICER2 Register
				*NVIC_ICER2 |= (1 << IRQNumber % 64);
			}
		}
}



/* @Function Name	-
 * @Brief			-
 * @Parameter[1]	-
 * @Parameter[2]	-
 * @Parameter[3]	-
 * @Return			-
 * @note			-
 */
void I2C_IRQPriorityConfig (uint8_t IRQNumber ,uint32_t IRQPriority)
{
	//1. Find out IPR register
	uint8_t IPRx = IRQNumber / 4 ;
	uint8_t IPRx_Section = IRQNumber % 4 ;
	uint8_t shift_amount = (8 * IPRx_Section) + (8 - NO_PR_BITS_IMPLEMENTED);
	*(NVIC_PR_BASE_ADDR + IPRx ) |= (IRQPriority << shift_amount);
}



/* @Function Name	-
 * @Brief			-
 * @Parameter[1]	-
 * @Parameter[2]	-
 * @Parameter[3]	-
 * @Return			-
 * @note			-
 */
void I2C_PeripheralControl(I2C_RegDef_t *pI2Cx , uint8_t EnorDI )
{
	if(ENABLE)
	{
		pI2Cx->CR1 |= (1 << I2C_CR1_PE);
	}else
	{
		pI2Cx->CR1 &= ~(1 << I2C_CR1_PE);
	}
}



/* @Function Name	-
 * @Brief			-
 * @Parameter[1]	-
 * @Parameter[2]	-
 * @Parameter[3]	-
 * @Return			-
 * @note			-
 */
uint8_t I2C_GetFlagStatus(I2C_RegDef_t *pI2Cx , uint32_t FlagName);



/* @Function Name	-
 * @Brief			-
 * @Parameter[1]	-
 * @Parameter[2]	-
 * @Parameter[3]	-
 * @Return			-
 * @note			-
 */
void I2C_ApplicationEventCallback(I2C_Handle_t *pI2CHandle,uint8_t AppEv);

