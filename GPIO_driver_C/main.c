#include "gpio_lib_stm32f7.h"

GPIO_InitTypeDef myGPIO_InitStruct;

int main(void){
	
	myGPIO_InitStruct.Mode	=	GPIO_MODE_OUTPUT_PP;
	myGPIO_InitStruct.Pin		=	GPIO_PIN_1;
	myGPIO_InitStruct.Pull	=	GPIO_NOPULL;
	__LIB_RCC_GPIOI_CLK_ENABLE();
	LIB_GPIO_Init(GPIOI,&myGPIO_InitStruct);
	while(1){
		for(volatile int i=0;i<900000;i++){}
		LIB_GPIO_TogglePin(GPIOI,GPIO_PIN_1);
	}
}





