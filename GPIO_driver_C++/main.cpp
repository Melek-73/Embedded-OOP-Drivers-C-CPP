#include "gpio_lib_stm32f7.h"

GPIO_InitTypeDef myGPIO_InitStruct;

uint8_t btnState;

int main(void){
	
	
	
	GPIO_InitTypeDef myGPIO_InitStruct;
	/*Test 1 
	myGPIO_InitStruct.Mode	=	GPIO_MODE_OUTPUT_PP;
	myGPIO_InitStruct.Pin		=	GPIO_PIN_1;
	myGPIO_InitStruct.Pull	=	GPIO_NOPULL;
	Gpio myOutput0(PORTI,GPIOI,&myGPIO_InitStruct);
	*/
	
	myGPIO_InitStruct = __gpio_pin_params(GPIO_PIN_1,GPIO_MODE_OUTPUT_PP,GPIO_NOPULL);
	Gpio myOutput1(PORTI,GPIOI,&myGPIO_InitStruct);
	
	/*Test2 - Add another port, same pin*/
	Gpio myOutput2(PORTC,GPIOC,&myGPIO_InitStruct);

	/*Test 3 - another Port, different Pin*/
	myGPIO_InitStruct = __gpio_pin_params(GPIO_PIN_13,GPIO_MODE_OUTPUT_PP,GPIO_NOPULL);
	Gpio myOutput3(PORTD,GPIOD,&myGPIO_InitStruct);
	
	/*Test 4 - another Port, different Mode*/
	myGPIO_InitStruct = __gpio_pin_params(GPIO_PIN_11,GPIO_MODE_INPUT,GPIO_NOPULL);
	Gpio myInput1(PORTI,GPIOI,&myGPIO_InitStruct);
	while(1){
		for(volatile int i=0;i<900000;i++){}
		myOutput1.LIB_GPIO_TogglePin(GPIOI,GPIO_PIN_1);
		myOutput2.LIB_GPIO_TogglePin(GPIOC,GPIO_PIN_5);
		myOutput3.LIB_GPIO_TogglePin(GPIOD,GPIO_PIN_13);
			/*Button is Active Low*/
		btnState = myInput1.LIB_GPIO_ReadPin(GPIOI,GPIO_PIN_11);
	}
}





