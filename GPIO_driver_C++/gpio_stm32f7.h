#ifndef  __GPIO_STM32F7__H__
#define  __GPIO_STM32F7__H__

////this file defines hardware addresses, registers, and bit masks.
//look at the data sheet block diagram to see GPIOs to each Bus are connected , than search for boundry address of all peripherals + AHB1

//A. Defining peripheral addresses
#include <stdint.h>
#define PERIPH_BASE 					0x40000000U									//starting address of the peripheral address region.
#define AHB1PERIPH_BASE 			(PERIPH_BASE+0x20000U)			//starting address of the AHB1 peripheral region.
#define RCC_AHB1_BASE 				(AHB1PERIPH_BASE+0x3800U)		//intended base address of the RCC registers.


#define GPIOA_AHB1_BASE (AHB1PERIPH_BASE+0x0U)
#define GPIOB_AHB1_BASE (AHB1PERIPH_BASE+0x400U)
#define GPIOC_AHB1_BASE (AHB1PERIPH_BASE+0x800U)
#define GPIOD_AHB1_BASE (AHB1PERIPH_BASE+0x0C00U)
#define GPIOE_AHB1_BASE (AHB1PERIPH_BASE+0x1000U)
#define GPIOF_AHB1_BASE (AHB1PERIPH_BASE+0x1400U)
#define GPIOG_AHB1_BASE (AHB1PERIPH_BASE+0x1800U)
#define GPIOH_AHB1_BASE (AHB1PERIPH_BASE+0x1C00U)
#define GPIOI_AHB1_BASE (AHB1PERIPH_BASE+0x2000U)
#define GPIOJ_AHB1_BASE (AHB1PERIPH_BASE+0x2400U)
#define GPIOK_AHB1_BASE (AHB1PERIPH_BASE+0x2800U)

//0x4002 0400
#define __IO volatile
	
//B. Defining the GPIO register structure
typedef struct{
	__IO uint32_t MODER;		 //mode register
	__IO uint32_t OTYPER;		 //output type register
	__IO uint32_t OSPEEDR;	 //output speed register
	__IO uint32_t PUPDR;		 //pull-up/pull-down register
	__IO uint32_t IDR;			 // Input data register				
	__IO uint32_t ODR;       //outout data register
	__IO uint32_t BSRR;      //bit set reset register
	__IO uint32_t LCKR;  		 //configuration lock register
	__IO uint32_t AFR[2];    //alternate function
}GPIO_TypeDef;  //This structure describes the layout of a GPIO peripheral's registers in memory.

typedef struct{
	
	__IO uint32_t CR;			//clock control register 
	__IO uint32_t PLLCFGR;
	__IO uint32_t CFGR;
	__IO uint32_t CIR; 
	__IO uint32_t AHB1RSTR;
	__IO uint32_t	AHB2RSTR;
	__IO uint32_t	AHB3RSTR;
			 uint32_t DUMMY1;
	__IO uint32_t	APB1RSTR;
	__IO uint32_t	APB2RSTR;
			 uint32_t DUMMY2[2];
	__IO uint32_t	AHB1ENR;
	__IO uint32_t	AHB2ENR;
  __IO uint32_t	AHB3ENR;
			 uint32_t DUMMY3;
	__IO uint32_t	APB1ENR;
	__IO uint32_t	APB2ENR;
	     uint32_t DUMMY4[2];
	__IO uint32_t AHB1LPENR;
	__IO uint32_t AHB2LPENR;
	__IO uint32_t AHB3LPENR;
			 uint32_t DUMMY5;
	__IO uint32_t APB1LPENR;
	__IO uint32_t APB2LPENR;
			 uint32_t DUMMY6[2];
	__IO uint32_t BDCR;
	__IO uint32_t CSR;
	uint32_t DUMMY7[2];
	__IO uint32_t	SSCGR;
	__IO uint32_t	PLLI2SCFGR;
	__IO uint32_t	PLLSAICFGR;
	__IO uint32_t	DCKCFGR1;
	
}RCC_TypeDef;

#define RCC ((RCC_TypeDef*) RCC_AHB1_BASE)
//C. Defining the GPIOs pointers
#define GPIOA ((GPIO_TypeDef*) GPIOA_AHB1_BASE)		//It converts the GPIOA base address into a pointer to your register structure.
#define GPIOB ((GPIO_TypeDef*) GPIOB_AHB1_BASE)
#define GPIOC ((GPIO_TypeDef*) GPIOC_AHB1_BASE)
#define GPIOD ((GPIO_TypeDef*) GPIOD_AHB1_BASE)
#define GPIOE ((GPIO_TypeDef*) GPIOE_AHB1_BASE)
#define GPIOF ((GPIO_TypeDef*) GPIOF_AHB1_BASE)
#define GPIOG ((GPIO_TypeDef*) GPIOG_AHB1_BASE)
#define GPIOH ((GPIO_TypeDef*) GPIOH_AHB1_BASE)
#define GPIOI ((GPIO_TypeDef*) GPIOI_AHB1_BASE)
#define GPIOJ ((GPIO_TypeDef*) GPIOJ_AHB1_BASE)
#define GPIOK ((GPIO_TypeDef*) GPIOK_AHB1_BASE)

#define MODER_1_OUT 	1U<<2
#define LED_PIN 			1U<<1
//D. Defining bit masks
#define GPIOA_EN 1<<0
#define GPIOB_EN 1<<1
#define GPIOC_EN 1<<2
#define GPIOD_EN 1<<3
#define GPIOE_EN 1<<4
#define GPIOF_EN 1<<5
#define GPIOG_EN 1<<6
#define GPIOH_EN 1<<7
#define GPIOI_EN 1<<8
#define GPIOJ_EN 1<<9
#define GPIOK_EN 1<<10



#endif