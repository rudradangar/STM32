#include "STM32F446xx_SPI_Drivers.h"


/* @Function Name	- SPI_PeriClockControl
 * @Brief			- This function Enable and Disable Peripheral Clock for Given SPI Port
 * @Parameter[1]	- Base Address of SPI Peripheral
 * @Parameter[2]	- Enable Or Disable Macros
 * @Parameter[3]	- none
 * @Return			- none
 * @note			- none
 */

void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDI)
{
	if(EnorDI == ENABLE)
	{
		if(pSPIx == SPI1)
		{
			SPI1_PCLK_EN();
		}else if(pSPIx == SPI2)
		{
			SPI2_PCLK_EN();
		}else if(pSPIx == SPI3)
		{
			SPI3_PCLK_EN();
		}else if(pSPIx == SPI4)
		{
			SPI4_PCLK_EN();
		}

	}else
	{
		{
				if(pSPIx == SPI1)
				{
					SPI1_PCLK_DI();
				}else if(pSPIx == SPI2)
				{
					SPI2_PCLK_DI();
				}else if(pSPIx == SPI3)
				{
					SPI3_PCLK_DI();
				}else if(pSPIx == SPI4)
				{
					SPI4_PCLK_DI();
				}
		}
	}
}


	/* @Function Name	- SPI_Init
	 * @Brief			- This is Use to Configure Mode, Bus , Speed, DFF, CPOL, CPHA
	 * @Parameter[1]	- none
	 * @Parameter[2]	- none
	 * @Parameter[3]	- none
	 * @Return			- none
	 * @note			- none
	 */
void SPI_Init(SPI_Handle_t *pSPIHandle)
{
	uint32_t temp = 0;

	//1. configure device mode
	 temp |= pSPIHandle->SPI_PinCofing.SPI_DeviceMode << 2;

	 //2. configure bus
	if(pSPIHandle->SPI_PinCofing.SPI_BusConfig == SPI_BUS_CONFIG_FD)
	{
		//BIDI clear
		temp &= ~(1 << SPI_CR1_BIDIMODE);

	}else if(pSPIHandle->SPI_PinCofing.SPI_BusConfig == SPI_BUS_CONFIG_HD)
	{
		//BIDI set
		temp |= (1 << SPI_CR1_BIDIMODE);

	}else if(pSPIHandle->SPI_PinCofing.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_RXONLY)
	{
		//BIDI should be clear
		//RXONLY bit must be set
		temp &= ~(1 << SPI_CR1_BIDIMODE);
		temp |= (1 << SPI_CR1_RXONLY);

	}

	//3. configure Speed
	temp |= pSPIHandle->SPI_PinCofing.SPI_SclkSpeed << SPI_CR1_BR;

	//4. configure DFF
	temp |= pSPIHandle->SPI_PinCofing.SPI_DFF << SPI_CR1_DFF;

	//5. configure CPOL
	temp |= pSPIHandle->SPI_PinCofing.SPI_CPOL << SPI_CR1_CPOL;

	//6. configure CPHA
	temp |= pSPIHandle->SPI_PinCofing.SPI_CPHA << SPI_CR1_CPHA;

	pSPIHandle->pSPIx->CR1 = temp;
}


	/* @Function Name	- GPIO_DeInit
	 * @Brief			- This is Use to Clear Register
	 * @Parameter[1]	- Base Address of SPI Peripheral
	 * @Parameter[2]	- none
	 * @Parameter[3]	- none
	 * @Return			- none
	 * @note			- none
	 */
void SPI_DeInit(SPI_RegDef_t *pSPIx)
{
	if(pSPIx == SPI1)
						{
							SPI1_REG_RESET();
						}else if (pSPIx == SPI2)
						{
							SPI2_REG_RESET();
						}else if (pSPIx == SPI3)
						{
							SPI3_REG_RESET();
						}else if (pSPIx == SPI4)
						{
							SPI4_REG_RESET();
						}
}


	/* @Function Name	- SPI_SendData
	 * @Brief			-
	 * @Parameter[1]	- Base Address of SPI Peripheral
	 * @Parameter[2]	- pointer to Tx Buffer which is transfer
	 * @Parameter[3]	- Length of how many data need to transfer
	 * @Return			- none
	 * @note			- This is Blocking Call Because if Length is 1000 and 1000 Bytes not transfer its continuous running
	 */
uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx , uint32_t FlagName)
{
	if (pSPIx->SR & FlagName)
	{
		return FLAG_SET;
	}
	return FLAG_RESET;
}
void SPI_SendData (SPI_RegDef_t *pSPIx ,uint8_t *pTxBuffer , uint32_t Len)
{
	while(Len > 0)
	{
		while(SPI_GetFlagStatus(pSPIx , SPI_TXE_FLAG) == FLAG_RESET);
		if(pSPIx->CR1 & (1 << SPI_CR1_DFF))
		{
			//16 Bit DFF
			pSPIx->DR = *((uint16_t*)pTxBuffer);
			Len--;
			Len--;
			(uint16_t*)pTxBuffer++;
		}else
		{
			//8 Bit DFF
			pSPIx->DR = *pTxBuffer;
			Len--;
			pTxBuffer++;
		}
	}
}


	/* @Function Name	- SPI_ReciveData
	 * @Brief			-
	 * @Parameter[1]	- Base Address of GPIO Peripheral
	 * @Parameter[2]	-
	 * @Parameter[3]	-
	 * @Return			- none
	 * @note			- none
	 */

void SPI_ReciveData(SPI_RegDef_t *pSPIx ,uint8_t *pRxBuffer , uint32_t Len)
{
	while(Len > 0)
	{
		while(SPI_GetFlagStatus(pSPIx , SPI_RXNE_FLAG) == FLAG_RESET);
		if(pSPIx->CR1 & (1 << SPI_CR1_DFF))
		{
			//16 Bit DFF
			*(uint16_t*)pRxBuffer = pSPIx->DR ;
			Len--;
			Len--;
			(uint16_t*)pRxBuffer++;
		}else
		{
			//8 Bit DFF
			*pRxBuffer = pSPIx->DR;
			Len--;
			pRxBuffer++;
		}
	}
}



	/* @Function Name	- SPI_SendDataIT
	 * @Brief			-
	 * @Parameter[1]	-
	 * @Parameter[2]	-
	 * @Parameter[3]	-
	 * @Return			- none
	 * @note			- none
	 */
uint8_t SPI_SendDataIT (SPI_Handle_t *pSPIHandle ,uint8_t *pTxBuffer , uint32_t Len)
{
	uint8_t state = pSPIHandle->TxState;

	if (state != SPI_BUSY_IN_Tx)
	{
		//1.save Tx Buffer Address and Length Information in Some Global Variable
		pSPIHandle->pTxBuffer = pTxBuffer;
		pSPIHandle->TxLen = Len;

		//2. Mark SPI sate is busy in Transmission so that
		//   no other code can take over same SPI peripheral until transmission is over
		pSPIHandle->TxState = SPI_BUSY_IN_Tx;


		//3.Enable the TXEIE control bit to get Interrupt whenever TXE flag is set in SR
		pSPIHandle->pSPIx->CR2 |= (1 << SPI_CR2_TXEIE);
	}

	//4.Data Transmission is handle by ISR code

	return state;
}



	/* @Function Name	- SPI_ReciveDataIT
	 * @Brief			-
	 * @Parameter[1]	-
	 * @Parameter[2]	-
	 * @Parameter[3]	- none
	 * @Return			- none
	 * @note			- none
	 */
uint8_t SPI_ReciveDataIT(SPI_Handle_t *pSPIHandle ,uint8_t *pRxBuffer , uint32_t Len)
{
	uint8_t state = pSPIHandle->RxState;

	if (state != SPI_BUSY_IN_Rx)
	{
		//1.save Tx Buffer Address and Length Information in Some Global Variable
		pSPIHandle->pRxBuffer = pRxBuffer;
		pSPIHandle->RxLen = Len;

		//2. Mark SPI sate is busy in Transmission so that
		//   no other code can take over same SPI peripheral until transmission is over
		pSPIHandle->RxState = SPI_BUSY_IN_Rx;


		//3.Enable the RXNEIE control bit to get Interrupt whenever TXE flag is set in SR
		pSPIHandle->pSPIx->CR2 |= (1 << SPI_CR2_RXNEIE);
	}

	//4.Data Transmission is handle by ISR code

	return state;
}





	/* @Function Name	- SPI_IRQInterruptConfig
	 * @Brief			-
	 * @Parameter[1]	-
	 * @Parameter[2]	-
	 * @Parameter[3]	- none
	 * @Return			- none
	 * @note			- none
	 */
void SPI_IRQInterruptConfig(uint8_t IRQNumber , uint8_t EnorDi )
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


	/* @Function Name	- SPI_IRQPriorityConfig
	 * @Brief			-
	 * @Parameter[1]	-
	 * @Parameter[2]	-
	 * @Parameter[3]	- none
	 * @Return			- none
	 * @note			- none
	 */
void SPI_IRQPriorityConfig (uint8_t IRQNumber ,uint32_t IRQPriority)
{
	//1. Find out IPR register
	uint8_t IPRx = IRQNumber / 4 ;
	uint8_t IPRx_Section = IRQNumber % 4 ;
	uint8_t shift_amount = (8 * IPRx_Section) + (8 - NO_PR_BITS_IMPLEMENTED);
	*(NVIC_PR_BASE_ADDR + IPRx ) |= (IRQPriority << shift_amount);
}


	/* @Function Name	- SPI_IRQHandling
	 * @Brief			-
	 * @Parameter[1]	-
	 * @Parameter[2]	- none
	 * @Parameter[3]	- none
	 * @Return			- none
	 * @note			- none
	 */
static void SPI_TXE_INTERRUPT_HANDLE(SPI_Handle_t *pSPIHandle)
{
	// check the DFF bit in CR1
		if( (pSPIHandle->pSPIx->CR1 & ( 1 << SPI_CR1_DFF) ) )
		{
			//16 bit DFF
			//1. load the data in to the DR
			pSPIHandle->pSPIx->DR =   *((uint16_t*)pSPIHandle->pTxBuffer);
			pSPIHandle->TxLen--;
			pSPIHandle->TxLen--;
			(uint16_t*)pSPIHandle->pTxBuffer++;
		}else
		{
			//8 bit DFF
			pSPIHandle->pSPIx->DR =   *pSPIHandle->pTxBuffer;
			pSPIHandle->TxLen--;
			pSPIHandle->pTxBuffer++;
		}

		if(! pSPIHandle->TxLen)
		{
			//TxLen is zero , so close the spi transmission and inform the application that
			//TX is over.

			//this prevents interrupts from setting up of TXE flag
			SPI_CloseTransmisson(pSPIHandle);
			SPI_ApplicationEventCallback(pSPIHandle,SPI_EVENT_TX_CMPLT);
		}

}
static void SPI_RXNE_INTERRUPT_HANDLE(SPI_Handle_t *pSPIHandle)
{
	//do rxing as per the dff
		if(pSPIHandle->pSPIx->CR1 & ( 1 << 11))
		{
			//16 bit
			*((uint16_t*)pSPIHandle->pRxBuffer) = (uint16_t) pSPIHandle->pSPIx->DR;
			pSPIHandle->RxLen -= 2;
			pSPIHandle->pRxBuffer++;
			pSPIHandle->pRxBuffer++;

		}else
		{
			//8 bit
			*(pSPIHandle->pRxBuffer) = (uint8_t) pSPIHandle->pSPIx->DR;
			pSPIHandle->RxLen--;
			pSPIHandle->pRxBuffer++;
		}

		if(! pSPIHandle->RxLen)
		{
			//reception is complete
			SPI_CloseReception(pSPIHandle);
			SPI_ApplicationEventCallback(pSPIHandle,SPI_EVENT_RX_CMPLT);
		}
}


static void SPI_OVR_FLAG_INTERRUPT_HANDLE(SPI_Handle_t *pSPIHandle)
{
	uint8_t temp;
	//1. clear the ovr flag
	if(pSPIHandle->TxState != SPI_BUSY_IN_Tx)
	{
		temp = pSPIHandle->pSPIx->DR;
		temp = pSPIHandle->pSPIx->SR;
	}
	(void)temp;
	//2. inform the application
	SPI_ApplicationEventCallback(pSPIHandle,SPI_EVENT_OVR_FLAG_CMPLT);
}



void SPI_IRQHandling(SPI_Handle_t *pSPIHandle)
{
	uint8_t temp1 , temp2;
	//let's check TXE
	temp1 = pSPIHandle->pSPIx->SR & (1 << SPI_SR_TXE);
	temp2 = pSPIHandle->pSPIx->CR2 & (1 << SPI_CR2_TXEIE);


	if (temp1 && temp2)
	{
		//Handle TXE
		SPI_TXE_INTERRUPT_HANDLE(pSPIHandle);
	}

	//let's check RXNE
	temp1 = pSPIHandle->pSPIx->SR & (1 << SPI_SR_RXNE);
	temp1 = pSPIHandle->pSPIx->CR2 & (1 << SPI_CR2_RXNEIE);
	if (temp1 && temp2)
	{
		//Handle RXNE
		SPI_RXNE_INTERRUPT_HANDLE(pSPIHandle);
	}

	//let's check OVR Flag
	temp1 = pSPIHandle->pSPIx->SR & (1 << SPI_SR_OVR);
	temp1 = pSPIHandle->pSPIx->CR2 & (1 << SPI_CR2_ERRIE);
	if (temp1 && temp2)
	{
		//Handle RXNE
		SPI_OVR_FLAG_INTERRUPT_HANDLE(pSPIHandle);
	}

}


	/* @Function Name	- SPI_PeripheralControl
	 * @Brief			-
	 * @Parameter[1]	- Base Address of GPIO Peripheral
	 * @Parameter[2]	-
	 * @Parameter[3]	- none
	 * @Return			- none
	 * @note			- none
	 */
void SPI_PeripheralControl(SPI_RegDef_t *pSPIx , uint8_t EnorDI )
{
	if(ENABLE)
	{
		pSPIx->CR1 |= (1 << SPI_CR1_SPE);
	}else
	{
		pSPIx->CR1 &= ~(1 << SPI_CR1_SPE);
	}
}


	/* @Function Name	- SPI_SSIConfig
	 * @Brief			-
	 * @Parameter[1]	- Base Address of GPIO Peripheral
	 * @Parameter[2]	-
	 * @Parameter[3]	- none
	 * @Return			- none
	 * @note			- none
	 */
void SPI_SSIConfig(SPI_RegDef_t *pSPIx , uint8_t EnorDI )
{
	if(ENABLE)
		{
			pSPIx->CR1 |= (1 << SPI_CR1_SSI);
		}else
		{
			pSPIx->CR1 &= ~(1 << SPI_CR1_SSI);
		}
}


	/* @Function Name	- SPI_SSOEConfig
	 * @Brief			-
	 * @Parameter[1]	- Base Address of GPIO Peripheral
	 * @Parameter[2]	-
	 * @Parameter[3]	- none
	 * @Return			- none
	 * @note			- none
	 */
void SPI_SSOEConfig(SPI_RegDef_t *pSPIx , uint8_t EnorDI )
{
	if(ENABLE)
		{
			pSPIx->CR2 |= (1 << SPI_CR2_SSOE);
		}else
		{
			pSPIx->CR2 &= ~(1 << SPI_CR2_SSOE);
		}
}



void SPI_ClearOVRFlag(SPI_RegDef_t *pSPIx)
{
	uint8_t temp;
	temp = pSPIx->DR;
	temp = pSPIx->SR;
	(void)temp;
}



void SPI_CloseReception(SPI_Handle_t *pSPIHandle)
{
	pSPIHandle->pSPIx->CR2 &= ~( 1 << SPI_CR2_RXNEIE);
	pSPIHandle->pRxBuffer = NULL;
	pSPIHandle->RxLen = 0;
	pSPIHandle->RxState = SPI_READY;
}



void SPI_CloseTransmisson(SPI_Handle_t *pSPIHandle)
{
pSPIHandle->pSPIx->CR2 &= ~( 1 << SPI_CR2_TXEIE);
pSPIHandle->pTxBuffer = NULL;
pSPIHandle->TxLen = 0;
pSPIHandle->TxState = SPI_READY;
}

__weak void SPI_ApplicationEventCallback(SPI_Handle_t *pSPIHandle,uint8_t AppEv)
{

	//This is a weak implementation . the user application may override this function.
}




