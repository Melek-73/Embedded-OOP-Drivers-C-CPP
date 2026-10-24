#ifndef __GPIO_LIB_STM32F7_H__
#define __GPIO_LIB_STM32F7_H__

//this file defines the API and configuration structures you will use in your application.

#include "gpio_stm32f7.h"
//A. Pin masks
#define GPIO_PIN_0						((uint32_t)0x0001)
#define GPIO_PIN_1						((uint32_t)0x0002)
#define GPIO_PIN_2						((uint32_t)0x0004)
#define GPIO_PIN_3						((uint32_t)0x0008)
#define GPIO_PIN_4						((uint32_t)0x0010)
#define GPIO_PIN_5						((uint32_t)0x0020)
#define GPIO_PIN_6						((uint32_t)0x0040)
#define GPIO_PIN_7						((uint32_t)0x0080)
#define GPIO_PIN_8						((uint32_t)0x0100)
#define GPIO_PIN_9						((uint32_t)0x0200)
#define GPIO_PIN_10						((uint32_t)0x0400)
#define GPIO_PIN_11						((uint32_t)0x0800)
#define GPIO_PIN_12						((uint32_t)0x1000)
#define GPIO_PIN_13						((uint32_t)0x2000)
#define GPIO_PIN_14						((uint32_t)0x4000)
#define GPIO_PIN_15						((uint32_t)0x8000)
#define GPIO_PIN_ALL					((uint32_t)0xFFFF)


//These correspond to the MODER register:
#define GPIO_MODE_INPUT     	0x00U
//these configure the mode register and the output type mode register OTYPER
#define GPIO_MODE_OUTPUT_PP  	0x11U 	//mode : output , output type : PP push pull and so on
#define GPIO_MODE_OUTPUT_OD  	0x01U
#define GPIO_MODE_AF_PP  			0x02U   //AF mode, push-pull output type
#define GPIO_MODE_AF_OD  			0x12U		//AF mode , output drain output type

////These correspond to the PUPDR register:
#define GPIO_NOPULL 					0x00U
#define GPIO_PULLUP 					0x01U
#define GPIO_PULLDOWN 				0x02U


typedef struct
{
    uint32_t Pin;        // WHICH pin?
    uint32_t Mode;       // WHAT general mode?
    uint32_t Pull;       // pull-up/down?
    uint32_t Speed;      // output speed?
    uint32_t Alternate;  // WHICH peripheral function?
} GPIO_InitTypeDef;

typedef enum{
	GPIO_PIN_RESET=0,
	GPIO_PIN_SET,
}GPIO_PinState;

void LIB_GPIO_Init(GPIO_TypeDef *GPIOx,GPIO_InitTypeDef *GPIO_Init);
GPIO_PinState LIB_GPIO_ReadPin(GPIO_TypeDef *GPIOx,uint32_t GPIO_Pin);
void LIB_GPIO_WritePin(GPIO_TypeDef *GPIOx,uint32_t GPIO_Pin,GPIO_PinState PinState);
void LIB_GPIO_TogglePin(GPIO_TypeDef *GPIOx,uint32_t GPIO_Pin);

void __LIB_RCC_GPIOA_CLK_ENABLE(void);
void __LIB_RCC_GPIOB_CLK_ENABLE(void);
void __LIB_RCC_GPIOC_CLK_ENABLE(void);
void __LIB_RCC_GPIOD_CLK_ENABLE(void);
void __LIB_RCC_GPIOE_CLK_ENABLE(void);
void __LIB_RCC_GPIOF_CLK_ENABLE(void);
void __LIB_RCC_GPIOG_CLK_ENABLE(void);
void __LIB_RCC_GPIOH_CLK_ENABLE(void);
void __LIB_RCC_GPIOI_CLK_ENABLE(void);
void __LIB_RCC_GPIOJ_CLK_ENABLE(void);
void __LIB_RCC_GPIOK_CLK_ENABLE(void);


#endif