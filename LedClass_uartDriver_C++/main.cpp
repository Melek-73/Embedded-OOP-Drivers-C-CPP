#include "Led.h"
#include "PowerLed.h"

PowerLed pLed1(RED,ON,DIAM_5MM,CURR_NORMAL,VOL_NORMAL);


LedState_Type power_led1_state;
led_elec_type power_led2;
led_elec_type current_led3;

led_elec_type led1_power;
led_elec_type led2_power;

int main(void){
	USART1_Init();
	
	PowerLed pLed2(BLUE,ON,DIAM_7MM,CURR_HIGH,VOL_NORMAL);
	PowerLed *pLed3=new PowerLed(YELLOW,ON,DIAM_7MM,CURR_VERY_HIGH,VOL_HIGH);
	
	power_led1_state=pLed1.getState();
	power_led2=pLed2.Power_Led_computePower();
	current_led3=pLed3->Power_Led_getCurrent();
	
	pLed1.setState(OFF);
	pLed2.setState(OFF);
	pLed3->setState(OFF);
	
	delete pLed3;
	
	while(1){}
 }