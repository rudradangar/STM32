

#ifndef INC_STM32F446XX_GPIO_DRIVER_H_
#define INC_STM32F446XX_GPIO_DRIVER_H_

#include "stm32f446xx.h"

typedef struct
{
	uint8_t GPIO_PinNumber;			//Possible Value From @GPIO_PINNUM
	uint8_t GPIO_PinMode;   		//Possible Value From @GPIO_PIN_MODES
	uint8_t GPIO_PinSpeed;			//Possible Value From @GPIO_PIN_SPEED
	uint8_t GPIO_PinPuPdControl;	//Possible Value From @GPIO_PIN_PUPD
	uint8_t GPIO_PinOPType;			//Possible Value From @GPIO_PIN_OPTYPE
	uint8_t GPIO_PinAltFunMode;		//Possible Value From @GPIO_PIN_ALTFUNCTION
}GPIO_PinCofing_t;

/*
 * this is handale structure for gpio pins
 */

typedef struct
{
	// pointer to the hold the base address of the GPIO peripheral
	GPIO_RegDef_t *pGPIOx;  //this is hold the base address of the GPIO port to which pin belong
	GPIO_PinCofing_t GPIO_PinConfig; //this hold GPIO pin configration setting


}GPIO_Handle_t;


//@GPIO_PINNUM
/*
 * GPIO Pin Number
 */
#define GPIO_PIN_NO_0 		0
#define GPIO_PIN_NO_1 		1
#define GPIO_PIN_NO_2 		2
#define GPIO_PIN_NO_3 		3
#define GPIO_PIN_NO_4 		4
#define GPIO_PIN_NO_5 		5
#define GPIO_PIN_NO_6 		6
#define GPIO_PIN_NO_7 		7
#define GPIO_PIN_NO_8 		8
#define GPIO_PIN_NO_9 		9
#define GPIO_PIN_NO_10 		10
#define GPIO_PIN_NO_11 		11
#define GPIO_PIN_NO_12 		12
#define GPIO_PIN_NO_13 		13
#define GPIO_PIN_NO_14 		14
#define GPIO_PIN_NO_15 		15

//@GPIO_PIN_MODES
/*
 * GPIO Pin Possible Mode
 */
#define GPIO_MODE_IN 		0
#define GPIO_MODE_OUT 		1
#define GPIO_MODE_ALTFN 	2
#define GPIO_MODE_ANALOG 	3
#define GPIO_MODE_IT_FT     4     //GPIO MODE INPUT FALLING EDGE DERIVE FOR US WE GIVE IT 4 THERE IN NOT EXIST IN MODE & INTRUPT ONLY GENRST WHEN ITS INPUT
#define GPIO_MODE_IT_RT     5     //GPIO MODE INPUT RISING EDGE DERIVE FOR US WE GIVE IT 4 THERE IN NOT EXIST IN MODE & INTRUPT ONLY GENRST WHEN ITS INPUT
#define GPIO_MODE_IT_RFT    6     //RISING AND FALLING EDGE


//@GPIO_PIN_OPTYPE
/*
 * GPIO Pin Possible Output Type
 */
#define GPIO_OP_TYPE_PP 	0     // push pull
#define GPIO_OP_TYPE_OD  	1	  // open drain


//@GPIO_PIN_SPEED
/*
 * GPIO Pin Possible Output Speed
 */

#define GPIO_SPEED_LOW 		0
#define GPIO_SPEED_MEDIUM	1
#define GPIO_SPEED_FAST		2
#define GPIO_SPEED_HIGH		3


//@GPIO_PIN_PUPD
/*
 * GPIO Pin Pull up Pull Down Macros
 */
#define GPIO_NO_PUPD 		0
#define GPIO_PIN_PU 		1
#define GPIO_PIN_PD 		2






/* ************************************
 * api support by this driver
 ***************************************/


void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDI);
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx , uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteFromOutputPin(GPIO_RegDef_t *pGPIOx , uint8_t PinNumber , uint8_t Value);
void GPIO_WriteFromOutputPort(GPIO_RegDef_t *pGPIOx , uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx , uint8_t PinNumber);
void GPIO_IRQInterruptConfig(uint8_t IRQNumber , uint8_t EnorDi );
void GPIO_IRQPriorityConfig (uint8_t IRQNumber ,uint32_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);




#endif /* INC_STM32F446XX_GPIO_DRIVER_H_ */
