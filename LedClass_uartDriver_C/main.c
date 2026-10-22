#include "Led.h"
#include "PowerLed.h"
#include "MedicalLed.h"

//In this project , there is Led as base class and there is PowerLed and MedicalLed as two classes inherit from the base class Led(note that we mean by class here the structure)

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
	
	/*
	PowerLed_ctor(&pled1,RED,ON,DIAM_5MM,CURR_NORMAL,VOL_NORMAL);
	PowerLed_ctor(&pled2,YELLOW,ON,DIAM_7MM,CURR_HIGH,VOL_NORMAL);
	
	led1_power=Power_Led_computePower(&pled1);
	led2_power=Power_Led_computePower(&pled2);
	*/
	
	/*
	MedicalLed_Type mled1;
	MedicalLed_ctor(&mled1,INFRARED,RED,ON);
	*/
	
	MedicalLed_Type mled1;
	PowerLed_Type pled1;
	Led_Type led1;
	
	Led_Type const * sys_leds[]={&led1,(Led_Type *)&pled1,(Led_Type *)&mled1,(Led_Type *)0};
	Led_ctor(&led1,RED,ON);
	MedicalLed_ctor(&mled1,INFRARED,(LedColor_Type)INFRARED,ON);
	PowerLed_ctor(&pled1,RED,ON,DIAM_5MM,CURR_NORMAL,VOL_NORMAL);
	
	while(1){
		runSystemDiagnostics(sys_leds);
	}
 }

 
 
 
 
 
 