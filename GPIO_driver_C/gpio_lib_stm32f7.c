#include  "gpio_lib_stm32f7.h"

//this file implements GPIO initialization, reading, writing, toggling, and clock enabling.
//define masks :
#define GPIO_NUMBER							16U
#define GPIO_MODER_MODE0   			0x3U<<0     ///Each GPIO pin uses 2 bits in MODER register.
#define GPIO_MODE								0x03U
#define GPIO_PUPDR_MODE 				0x03U
#define GPIO_PUPDR_PUPDR0				0x3U<<0
#define GPIO_OSPEEDR_OSPEEDR0		0x3U<<0
#define GPIO_OTYPER_OT0					0x1U<<0
#define GPIO_OUTPUT_TYPE				0x00010U
//This function it will configure all 16 pins of GPIOx to the mode you pass,and to pull up/down you pass
void LIB_GPIO_Init(GPIO_TypeDef *GPIOx,GPIO_InitTypeDef *GPIO_Init){
	uint32_t position;
	uint32_t temp=				0x0U;

	for(position=0;position<GPIO_NUMBER;position++){
			
		if((GPIO_Init->Pin & (1U << position)) != 0U){
			/*Alternate function selection*/
			if ((GPIO_Init->Mode == GPIO_MODE_AF_PP) || (GPIO_Init->Mode == GPIO_MODE_AF_OD)){
				temp = GPIOx->AFR[position>>3U];												//position >> 3U is equivalent to integer division by 8.3U to know if positoin is <8 or >=8 , if <8 >>3U give 0 so AFR[1] else give 1 
				temp &= ~(0xFU<<(uint32_t)(position & 0x07U) * 4U); 		//Clear the old AF value , Multiplying by 4 finds the starting bit of that pin's four-bit field.
				temp |= ((uint32_t)(GPIO_Init->Alternate)<< (((uint32_t)position & 0x07U)*4U));
				GPIOx->AFR[position>>3U]=temp;
			}
			/*Direction mode*/
			//Configure MODER
			temp = GPIOx->MODER;
			temp &=~(GPIO_MODER_MODE0<<(position*2U));					//Clear the two MODER bits belonging to the current pin.This removes the old mode without changing the other pins' mode bits.
			temp |=(GPIO_Init->Mode & GPIO_MODE)<<(position*2U);//GPIO_Init->Mode is the value we want to put into the MODER field of the associated pin,& GPIO_MODE mean only the lowest 2 bits of GPIO_Init->Mode are supposed to represent the GPIO mode
			GPIOx->MODER=temp;																	//4. Write the register back	 
			/*Alternate Function Selection*/
			if ((GPIO_Init->Mode == GPIO_MODE_OUTPUT_PP)||(GPIO_Init->Mode == GPIO_MODE_OUTPUT_OD)||
				(GPIO_Init->Mode == GPIO_MODE_AF_PP)||(GPIO_Init->Mode == GPIO_MODE_AF_OD)){
					temp = GPIOx->OSPEEDR;
					temp &= ~(GPIO_OSPEEDR_OSPEEDR0 << (position * 2U));
					temp |= (GPIO_Init->Speed <<(position * 2U));
					GPIOx->OSPEEDR = temp;
					
					//Configure output type
					temp = GPIOx->OTYPER;
					temp &= ~(GPIO_OTYPER_OT0 << (position * 2U));
					temp |= (((GPIO_Init->Mode & GPIO_OUTPUT_TYPE)>>4U) <<(position * 2U));
					GPIOx->OTYPER = temp;
				}
			
			temp=GPIOx->PUPDR;
			temp &=~(GPIO_PUPDR_PUPDR0<<(position*2U));
			temp |=((GPIO_Init->Pull & GPIO_PUPDR_MODE)<<(position*2U));
			GPIOx->PUPDR=temp;
		}
	}
}

//This function is for read one GPIO pin and tell us whether it is 0 or 1.
GPIO_PinState LIB_GPIO_ReadPin(GPIO_TypeDef *GPIOx,uint32_t GPIO_Pin){
	GPIO_PinState bitstatus;
	//Notes that IDR tells us the current logic level being detected on each GPIO pin.IDE : Input Data Register
	if ((GPIOx->IDR & GPIO_Pin) !=(uint32_t)GPIO_PIN_RESET){
		bitstatus=GPIO_PIN_SET;
	}else{
		bitstatus=GPIO_PIN_RESET;
	}
	return bitstatus;
}
//The BSRR register is 32-bit register and it is divided into 16-bit for Set(BS) and 16-bit for Reset(BR) , setting or resetting a pin
void LIB_GPIO_WritePin(GPIO_TypeDef *GPIOx,uint32_t GPIO_Pin,GPIO_PinState PinState){
	if(PinState != GPIO_PIN_RESET){
		GPIOx->BSRR=GPIO_Pin;
	}else{
		GPIOx->BSRR=(uint32_t)GPIO_Pin<<16;
	}
}

//For a GPIO port, each bit of ODR corresponds to one GPIO pin.
void LIB_GPIO_TogglePin(GPIO_TypeDef *GPIOx,uint32_t GPIO_Pin){
	GPIOx->ODR ^=GPIO_Pin;
}

void __LIB_RCC_GPIOA_CLK_ENABLE(void){RCC->AHB1ENR |= GPIOA_EN;}
void __LIB_RCC_GPIOB_CLK_ENABLE(void){RCC->AHB1ENR |= GPIOB_EN;}
void __LIB_RCC_GPIOC_CLK_ENABLE(void){RCC->AHB1ENR |= GPIOC_EN;}
void __LIB_RCC_GPIOD_CLK_ENABLE(void){RCC->AHB1ENR |= GPIOD_EN;}
void __LIB_RCC_GPIOE_CLK_ENABLE(void){RCC->AHB1ENR |= GPIOE_EN;}
void __LIB_RCC_GPIOF_CLK_ENABLE(void){RCC->AHB1ENR |= GPIOF_EN;}
void __LIB_RCC_GPIOG_CLK_ENABLE(void){RCC->AHB1ENR |= GPIOG_EN;}
void __LIB_RCC_GPIOH_CLK_ENABLE(void){RCC->AHB1ENR |= GPIOH_EN;}
void __LIB_RCC_GPIOI_CLK_ENABLE(void){RCC->AHB1ENR |= GPIOI_EN;}
void __LIB_RCC_GPIOJ_CLK_ENABLE(void){RCC->AHB1ENR |= GPIOJ_EN;}
void __LIB_RCC_GPIOK_CLK_ENABLE(void){RCC->AHB1ENR |= GPIOK_EN;}














