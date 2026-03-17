

#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

#include <stddef.h>
#include <stdint.h>
#define __vo 					volatile
#define __weak					__attribute__((weak))

/******************************
 * Processor Specific detail
 *******************************/

/*
 * ISER Register Address
 */
#define NVIC_ISER0 				((__vo uint32_t*)0xE000E100)
#define NVIC_ISER1 				((__vo uint32_t*)0xE000E104)
#define NVIC_ISER2 				((__vo uint32_t*)0xE000E108)
#define NVIC_ISER3 				((__vo uint32_t*)0xE000E10C)


/*
 * ICER Register Address
 */
#define NVIC_ICER0 				((__vo uint32_t*)0xE000E180)
#define NVIC_ICER1 				((__vo uint32_t*)0xE000E184)
#define NVIC_ICER2 				((__vo uint32_t*)0xE000E188)
#define NVIC_ICER3 				((__vo uint32_t*)0xE000E18C)

/*
 * Priority Register Address
 */
#define NVIC_PR_BASE_ADDR 		((__vo uint32_t*)0xE000E400)

#define NO_PR_BITS_IMPLEMENTED 	4

/*
 * Base Addresses of Flash and SRAM
 */
#define FLASH_BASEADDR       	0x08000000U
#define SRAM1_BASEADDR          0x20000000U
#define ROM						0x1FFF0000U             //also called system memory
#define SRAM  					SRAM1_BASEADDR

/*
 * Base Addresses of AHBx and APBx bus
 */
#define PERIPH_BASEADDR        		0x40000000U
#define APB1PERIPH_BASEADDR			PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR			0x40010000U
#define AHB1PERIPH_BASEADDR			0x40020000U
#define AHB2PERIPH_BASEADDR			0x50000000U

/*
 * ON AHB1
 */
#define GPIOA_BASEADDR  		(AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR  		(AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR  		(AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR  		(AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR  		(AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR  		(AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR  		(AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR  		(AHB1PERIPH_BASEADDR + 0x1C00)

#define RCC_BASEADDR            (AHB1PERIPH_BASEADDR + 0x3800)

/*
 * ON APB1
 */

#define  I2C1_BASEADDR 			(APB1PERIPH_BASEADDR + 0x5400)
#define  I2C2_BASEADDR			(APB1PERIPH_BASEADDR + 0x5800)
#define  I2C3_BASEADDR 			(APB1PERIPH_BASEADDR + 0x5C00)

#define SPI2_BASEADDR 			(APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR  			(APB1PERIPH_BASEADDR + 0x3C00)

#define USART2_BASEADDR 		(APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR 		(APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR 			(APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR 			(APB1PERIPH_BASEADDR + 0x5000)

/*
 * ON APB2
 */
#define EXTI_BASEADDR 			(APB2PERIPH_BASEADDR + 0x3C00)
#define SPI1_BASEADDR 			(APB2PERIPH_BASEADDR + 0x3000)
#define SPI4_BASEADDR 			(APB2PERIPH_BASEADDR + 0x3400)
#define SYSCFG_BASEADDR 		(APB2PERIPH_BASEADDR + 0x3800)
#define USART1_BASEADDR 		(APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR 		(APB2PERIPH_BASEADDR + 0x1400)

/*
 * Peripheral Register definition Structure for GPIO
 */
typedef struct
{
	__vo uint32_t MODER; 			//GPIO port mode register (GPIOx_MODER)
	__vo uint32_t OTYPER;			//GPIO port output type register (GPIOx_OTYPER)
	__vo uint32_t OSPEEDR;			//GPIO port output speed register (GPIOx_OSPEEDR)
	__vo uint32_t PUPDR;			//GPIO port pull-up/pull-down register (GPIOx_PUPDR)
	__vo uint32_t IDR;				//GPIO port input data register (GPIOx_IDR)
	__vo uint32_t ODR;				//GPIO port output data register (GPIOx_ODR)
	__vo uint32_t BSRR; 			//GPIO port bit set/reset register (GPIOx_BSRR)
	__vo uint32_t LCKR;				//GPIO port configuration lock register (GPIOx_LCKR)
	__vo uint32_t AFR[2]; 			//GPIO alternate function low register (GPIOx_AFRL) AFR[0] FOR LOW & AFR[1] FOR HIGH

}GPIO_RegDef_t;

/*
 * Peripheral Register definition Structure for RCC
 */
typedef struct
{
	__vo uint32_t CR;
	__vo uint32_t PLLCFGR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	__vo uint32_t AHB3RSTR;
	uint32_t	  Reserved0;
	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	uint32_t  	  Reserved1[2];
	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	__vo uint32_t AHB3ENR;
	uint32_t      Reserved2;
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	uint32_t      Reserved3[2];
	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	__vo uint32_t AHB3LPENR;
	uint32_t      Reserved4;
	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;
	uint32_t      Reserved5[2];
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	uint32_t      Reserved6[2];
	__vo uint32_t SSCGR;
	__vo uint32_t PLLI2SCFGR;
	__vo uint32_t PLLSAICFGR;
	__vo uint32_t DCKCFGR;
	__vo uint32_t CKGATENR;
	__vo uint32_t DCKCFGR2;
}RCC_RegDef_t;


/*
 * Peripheral Register definition Structure for EXTI
 */
typedef struct
{
	__vo uint32_t IMR;										//OFFSET :- 0x00
	__vo uint32_t EMR;										//OFFSET :- 0x04
	__vo uint32_t RTSR;                                     //OFFSET :- 0x08
	__vo uint32_t FTSR;										//OFFSET :- 0x0C
	__vo uint32_t SWIER;									//OFFSET :- 0x10
	__vo uint32_t PR;										//OFFSET :- 0x14
}EXTI_RegDef_t;


/*
 * Peripheral Register definition Structure for EXTI
 */
typedef struct
{
	__vo uint32_t MEMRMP;			//OFFSET :- 0x00
	__vo uint32_t PMC;				//OFFSET :- 0x04
	__vo uint32_t EXTICR[4];		//OFFSET :- 0x08 - 0x14
	__vo uint32_t RESERVED0[2];		//OFFSET :- 0x18 - 0x1C
	__vo uint32_t CMPCR;			//OFFSET :- 0x20
	__vo uint32_t RESERVED1[2];		//OFFSET :- 0x24 - 0x28
	__vo uint32_t CFGR;				//OFFSET :- 0x2C
}SYSCFG_RegDef_t;

/*
 * Peripheral Register definition Structure for SPI
 */
typedef struct
{
	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t SR;
	__vo uint32_t DR;
	__vo uint32_t CRCPR;
	__vo uint32_t RXCRCR;
	__vo uint32_t TXCRCR;
	__vo uint32_t I2SCFGR;
	__vo uint32_t I2SPR;

}SPI_RegDef_t;


/*
 * Peripheral Register definition Structure for I2C
 */
typedef struct
{
	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t OAR1;
	__vo uint32_t OAR2;
	__vo uint32_t DR;
	__vo uint32_t SR1;
	__vo uint32_t SR2;
	__vo uint32_t CCR;
	__vo uint32_t TRISE;
	__vo uint32_t FLTR;
}I2C_RegDef_t;


/*
 * peripheral base addresses type casting
 */
#define GPIOA 					((GPIO_RegDef_t*) GPIOA_BASEADDR )
#define GPIOB 					((GPIO_RegDef_t*) GPIOB_BASEADDR )
#define GPIOC 					((GPIO_RegDef_t*) GPIOC_BASEADDR )
#define GPIOD 					((GPIO_RegDef_t*) GPIOD_BASEADDR )
#define GPIOE 					((GPIO_RegDef_t*) GPIOE_BASEADDR )
#define GPIOF 					((GPIO_RegDef_t*) GPIOF_BASEADDR )
#define GPIOG 					((GPIO_RegDef_t*) GPIOG_BASEADDR )
#define GPIOH 					((GPIO_RegDef_t*) GPIOH_BASEADDR )


#define RCC 					((RCC_RegDef_t*)  RCC_BASEADDR )

#define EXTI					((EXTI_RegDef_t*)  EXTI_BASEADDR )

#define SYSCFG					((SYSCFG_RegDef_t*)  SYSCFG_BASEADDR )


#define SPI1 					((SPI_RegDef_t*) SPI1_BASEADDR )
#define SPI2 					((SPI_RegDef_t*) SPI2_BASEADDR )
#define SPI3 					((SPI_RegDef_t*) SPI3_BASEADDR )
#define SPI4 					((SPI_RegDef_t*) SPI4_BASEADDR )

#define I2C1					((I2C_RegDef_t*) I2C1_BASEADDR )
#define I2C2 					((I2C_RegDef_t*) I2C2_BASEADDR )
#define I2C3 					((I2C_RegDef_t*) I2C3_BASEADDR )

/*
 * clock enable macro GPIOx peripheral
 */

#define GPIOA_PCLK_EN()  (RCC-> AHB1ENR|= (1 << 0))
#define GPIOB_PCLK_EN()  (RCC-> AHB1ENR|= (1 << 1))
#define GPIOC_PCLK_EN()  (RCC-> AHB1ENR|= (1 << 2))
#define GPIOD_PCLK_EN()  (RCC-> AHB1ENR|= (1 << 3))
#define GPIOE_PCLK_EN()  (RCC-> AHB1ENR|= (1 << 4))
#define GPIOF_PCLK_EN()  (RCC-> AHB1ENR|= (1 << 5))
#define GPIOG_PCLK_EN()  (RCC-> AHB1ENR|= (1 << 6))
#define GPIOH_PCLK_EN()  (RCC-> AHB1ENR|= (1 << 7))

/*
 * clock enable macro I2Cx peripheral
 */

#define I2C1_PCLK_EN()	 (RCC-> APB1ENR|= (1 << 21))
#define I2C2_PCLK_EN()	 (RCC-> APB1ENR|= (1 << 22))
#define I2C3_PCLK_EN()	 (RCC-> APB1ENR|= (1 << 23))

/*
 * clock enable macro SPIx peripheral
 */

#define SPI1_PCLK_EN()	 (RCC-> APB2ENR|= (1 << 12))
#define SPI2_PCLK_EN()	 (RCC-> APB1ENR|= (1 << 14))
#define SPI3_PCLK_EN()	 (RCC-> APB1ENR|= (1 << 15))
#define SPI4_PCLK_EN()	 (RCC-> APB2ENR|= (1 << 13))

/*
 * clock enable macro UARTx peripheral
 */

#define USART1_PCLK_EN()	 (RCC-> APB2ENR|= (1 << 4))
#define USART2_PCLK_EN()	 (RCC-> APB1ENR|= (1 << 17))
#define USART3_PCLK_EN()	 (RCC-> APB1ENR|= (1 << 18))
#define UART4_PCLK_EN()	     (RCC-> APB1ENR|= (1 << 19))
#define UART5_PCLK_EN()	     (RCC-> APB1ENR|= (1 << 20))
#define USART6_PCLK_EN()	 (RCC-> APB2ENR|= (1 << 5))

/*
 * clock enable macro SYSCGF peripheral
 */
#define SYSCGF_PCLK_EN()	 (RCC-> APB2ENR|= (1 << 14))

/*
 * clock disable macro GPIOx peripheral
 */
#define GPIOA_PCLK_DI()  (RCC-> AHB1ENR&= ~(1 << 0))
#define GPIOB_PCLK_DI()  (RCC-> AHB1ENR&= ~(1 << 1))
#define GPIOC_PCLK_DI()  (RCC-> AHB1ENR&= ~(1 << 2))
#define GPIOD_PCLK_DI()  (RCC-> AHB1ENR&= ~(1 << 3))
#define GPIOE_PCLK_DI()  (RCC-> AHB1ENR&= ~(1 << 4))
#define GPIOF_PCLK_DI()  (RCC-> AHB1ENR&= ~(1 << 5))
#define GPIOG_PCLK_DI()  (RCC-> AHB1ENR&= ~(1 << 6))
#define GPIOH_PCLK_DI()  (RCC-> AHB1ENR&= ~(1 << 7))

/*
 * clock disable macro I2Cx peripheral
 */

#define I2C1_PCLK_DI()	 (RCC-> APB1ENR&= ~(1 << 21))
#define I2C2_PCLK_DI()	 (RCC-> APB1ENR&= ~(1 << 22))
#define I2C3_PCLK_DI()	 (RCC-> APB1ENR&= ~(1 << 23))

/*
 * clock disable macro SPIx peripheral
 */

#define SPI1_PCLK_DI()	 (RCC-> APB2ENR&= ~(1 << 12))
#define SPI2_PCLK_DI()	 (RCC-> APB1ENR&= ~(1 << 14))
#define SPI3_PCLK_DI()	 (RCC-> APB1ENR&= ~(1 << 15))
#define SPI4_PCLK_DI()	 (RCC-> APB2ENR&= ~(1 << 13))

/*
 * clock disable macro UARTx peripheral
 */

#define USART1_PCLK_DI()	 (RCC-> APB2ENR&= ~(1 << 4))
#define USART2_PCLK_DI()	 (RCC-> APB1ENR&= ~(1 << 17))
#define USART3_PCLK_DI()	 (RCC-> APB1ENR&= ~(1 << 18))
#define UART4_PCLK_DI()	     (RCC-> APB1ENR&= ~(1 << 19))
#define UART5_PCLK_DI()	     (RCC-> APB1ENR&= ~(1 << 20))
#define USART6_PCLK_DI()	 (RCC-> APB2ENR&= ~(1 << 5))

/*
 * clock disable macro SYSCGF peripheral
 */
#define SYSCGF_PCLK_DN()	 (RCC-> APB2ENR&= ~(1 << 14))

/*
 * Macro for Reset GPIOx Peripheral
 */
#define GPIOA_REG_RESET()	  do{(RCC-> APB1RSTR |= (1 << 0));		(RCC-> APB1RSTR &= ~(1 << 0)); } while(0)
#define GPIOB_REG_RESET()	  do{(RCC-> APB1RSTR |= (1 << 1));		(RCC-> APB1RSTR &= ~(1 << 1)); } while(0)
#define GPIOC_REG_RESET()	  do{(RCC-> APB1RSTR |= (1 << 2));		(RCC-> APB1RSTR &= ~(1 << 2)); } while(0)
#define GPIOD_REG_RESET()	  do{(RCC-> APB1RSTR |= (1 << 3));		(RCC-> APB1RSTR &= ~(1 << 3)); } while(0)
#define GPIOE_REG_RESET()	  do{(RCC-> APB1RSTR |= (1 << 4));		(RCC-> APB1RSTR &= ~(1 << 4)); } while(0)
#define GPIOF_REG_RESET()	  do{(RCC-> APB1RSTR |= (1 << 5));		(RCC-> APB1RSTR &= ~(1 << 5)); } while(0)
#define GPIOG_REG_RESET()	  do{(RCC-> APB1RSTR |= (1 << 6));		(RCC-> APB1RSTR &= ~(1 << 6)); } while(0)
#define GPIOH_REG_RESET()	  do{(RCC-> APB1RSTR |= (1 << 7));		(RCC-> APB1RSTR &= ~(1 << 7)); } while(0)
#define GPIOI_REG_RESET()	  do{(RCC-> APB1RSTR |= (1 << 8));		(RCC-> APB1RSTR &= ~(1 << 8)); } while(0)

/*
 * Macro for Reset SPIx Peripheral
 */
#define SPI1_REG_RESET()	  do{(RCC-> APB2RSTR |= (1 << 12));		(RCC-> APB2RSTR &= ~(1 << 12)); } while(0)
#define SPI2_REG_RESET()	  do{(RCC-> APB1RSTR |= (1 << 14));		(RCC-> APB1RSTR &= ~(1 << 14)); } while(0)
#define SPI3_REG_RESET()	  do{(RCC-> APB1RSTR |= (1 << 15));		(RCC-> APB1RSTR &= ~(1 << 15)); } while(0)
#define SPI4_REG_RESET()	  do{(RCC-> APB2RSTR |= (1 << 13));		(RCC-> APB2RSTR &= ~(1 << 13)); } while(0)

/*
 * Macro for Reset I2Cx Peripheral
 */
#define I2C1_REG_RESET()	  do{(RCC-> APB1RSTR |= (1 << 21));		(RCC-> APB1RSTR &= ~(1 << 21)); } while(0)
#define I2C2_REG_RESET()	  do{(RCC-> APB1RSTR |= (1 << 22));		(RCC-> APB1RSTR &= ~(1 << 22)); } while(0)
#define I2C3_REG_RESET()	  do{(RCC-> APB1RSTR |= (1 << 23));		(RCC-> APB1RSTR &= ~(1 << 23)); } while(0)



#define GPIO_BASEADDR_TO_CODE(x)					((x == GPIOA)?0:\
														(x == GPIOB)?1:\
															(x == GPIOC)?2:\
																(x == GPIOD)?3:\
																	(x == GPIOE)?4:\
																		(x == GPIOF)?5:\
																			(x == GPIOG)?6:\
																				(x == GPIOH)?7:0)




/*
 * IRQ Number
 */
#define IRQ_NO_EXTI0			6
#define IRQ_NO_EXTI1			7
#define IRQ_NO_EXTI2			8
#define IRQ_NO_EXTI3			9
#define IRQ_NO_EXTI4			10
#define IRQ_NO_EXTI9_5			23
#define IRQ_NO_EXTI15_10		40

/*
 * IRQ Priorety
 */
#define NVIC_IRQ_PRIO_0			0
#define NVIC_IRQ_PRIO_1			1
#define NVIC_IRQ_PRIO_2			2
#define NVIC_IRQ_PRIO_3			3
#define NVIC_IRQ_PRIO_4			4
#define NVIC_IRQ_PRIO_5			5
#define NVIC_IRQ_PRIO_6			6
#define NVIC_IRQ_PRIO_7			7
#define NVIC_IRQ_PRIO_8			8
#define NVIC_IRQ_PRIO_9			9
#define NVIC_IRQ_PRIO_10		10
#define NVIC_IRQ_PRIO_11		11
#define NVIC_IRQ_PRIO_12		12
#define NVIC_IRQ_PRIO_13		13
#define NVIC_IRQ_PRIO_14		14
#define NVIC_IRQ_PRIO_15		15




/**********************************************
 * Bit Position definitions of SPI Peripheral
 **********************************************/
#define SPI_CR1_CPHA		0
#define SPI_CR1_CPOL		1
#define SPI_CR1_MSTR		2
#define SPI_CR1_BR			3
#define SPI_CR1_SPE			6
#define SPI_CR1_LSBFIRST	7
#define SPI_CR1_SSI			8
#define SPI_CR1_SSM			9
#define SPI_CR1_RXONLY		10
#define SPI_CR1_DFF			11
#define SPI_CR1_CRCNEXT		12
#define SPI_CR1_CRCEN		13
#define SPI_CR1_BIDIOE		14
#define SPI_CR1_BIDIMODE	15

#define SPI_CR2_RXDMAEN			0
#define SPI_CR2_TXDMAEN			1
#define SPI_CR2_SSOE			2
#define SPI_CR2_FRF				4
#define SPI_CR2_ERRIE			5
#define SPI_CR2_RXNEIE			6
#define SPI_CR2_TXEIE			7

#define SPI_SR_RXNE			0
#define SPI_SR_TXE			1
#define SPI_SR_CHSIDE		2
#define SPI_SR_UDR			3
#define SPI_SR_CRCERR		4
#define SPI_SR_MODF			5
#define SPI_SR_OVR			6
#define SPI_SR_BSY			7
#define SPI_SR_FRE			8


/**********************************************
 * Bit Position definitions of I2C Peripheral
 **********************************************/
#define I2C_CR1_PE			0
#define I2C_CR1_SMBUS		1
#define I2C_CR1_RESERVD1	2
#define I2C_CR1_SMBTYPE		3
#define I2C_CR1_ENARP		4
#define I2C_CR1_ENPEC		5
#define I2C_CR1_ENGC		6
#define I2C_CR1_NOSTRETCH	7
#define I2C_CR1_START		8
#define I2C_CR1_STOP		9
#define I2C_CR1_ACK			10
#define I2C_CR1_POS			11
#define I2C_CR1_PEC			12
#define I2C_CR1_ALERT		13
#define I2C_CR1_RESERVD2	14
#define I2C_CR1_SWRST		15

#define I2C_CR2_FREQ			0
#define I2C_CR2_ITERREN			8
#define I2C_CR2_ITEVTEN			9
#define I2C_CR2_ITBUFEN			10
#define I2C_CR2_DMAEN			11
#define I2C_CR2_LAST			12

#define I2C_SR1_SB				0
#define I2C_SR1_ADDR			1
#define I2C_SR1_BTF				2
#define I2C_SR1_ADD10			3
#define I2C_SR1_STOPF			4
#define I2C_SR1_RxNE			6
#define I2C_SR1_TxE				7
#define I2C_SR1_BERR			8
#define I2C_SR1_ARLO			9
#define I2C_SR1_AF				10
#define I2C_SR1_OVR				11
#define I2C_SR1_PECERR			12
#define I2C_SR1_TIMEOUT			14
#define I2C_SR1_SMBALERT		15

#define I2C_SR2_MSL				0
#define I2C_SR2_BUSY			1
#define I2C_SR2_TRA				2
#define I2C_SR2_GENCALL			4
#define I2C_SR2_DUALF			7

#define I2C_CCR_CCR				0
#define I2C_CCR_DUTY			14
#define I2C_CCR_FS				15


/*
 * some generic macro
 */
#define ENABLE 			1
#define DISABLE 		0
#define SET 			ENABLE
#define RESET 			DISABLE
#define GPIO_PIN_SET 	SET
#define GPIO_PIN_RESET	RESET
#define FLAG_RESET		RESET
#define FLAG_SET		SET

#include "STM32F446xx_GPIO_driver.h"
#include "STM32F446xx_SPI_Drivers.h"
#include "STM32F446xx_I2C_Drivers.h"

#endif /* INC_STM32F446XX_H_ */
