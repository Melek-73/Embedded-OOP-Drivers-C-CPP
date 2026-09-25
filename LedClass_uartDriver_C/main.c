#include "Led.h"
#include "PowerLed.h"

Led_Type led1;
Led_Type led2;

PowerLed_Type pled1,pled2;
led_elec_type led1_power;
led_elec_type led2_power;

int main(void){
	USART1_Init();
	
	//Led_ctor(&led1,RED,OFF);
	//Led_getState(&led1);
	
	//Led_ctor(&led2,BLUE,ON);
	//Led_getState(&led2);
	
	//Led_setState(&led1,ON);
	
	PowerLed_ctor(&pled1,RED,ON,DIAM_5MM,CURR_NORMAL,VOL_NORMAL);
	PowerLed_ctor(&pled2,YELLOW,ON,DIAM_7MM,CURR_HIGH,VOL_NORMAL);
	
	led1_power=Power_Led_computePower(&pled1);
	led2_power=Power_Led_computePower(&pled2);
	
	while(1){}
 }