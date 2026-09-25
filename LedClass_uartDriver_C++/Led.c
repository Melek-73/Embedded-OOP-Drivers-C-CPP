#include 	"Led.h"
#include <stdio.h>

//function constructor
void Led_ctor(Led_Type * const me,LedColor_Type _color, LedState_Type _state){
	me->color=_color;
	me->state=_state;
	
	/*Hardware Init*/
	RCC->AHB1ENR|= LED_PORT_CLOCK;
	
	switch (_color){
		case RED:
			LED_PORT->MODER |= LED_RED_MODE_BIT;
			if (me->state==ON) {
				LED_PORT->ODR |= LED_RED_PIN;
				printf("The RED Led is set ON \n\r");
			}
			else {
				LED_PORT->ODR &= ~LED_RED_PIN;
				printf("The RED Led is set OFF \n\r");
			}
		break;
			case GREEN:
			LED_PORT->MODER |= LED_GREEN_MODE_BIT;
			if (me->state==ON) {
				LED_PORT->ODR |= LED_GREEN_PIN;
				printf("The GREEN Led is set ON \n\r");
			}
			else {
				LED_PORT->ODR &= ~LED_GREEN_PIN;
				printf("The GREEN Led is set OFF \n\r");
			}
		break;
			case YELLOW:
			LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
			if (me->state==ON) {
				LED_PORT->ODR |= LED_YELLOW_PIN;
				printf("The YELLOW Led is set ON \n\r");
			}
			else {
				LED_PORT->ODR &= ~LED_YELLOW_PIN;
				printf("The YELLOW Led is set OFF \n\r");
			}
		break;
			case BLUE:
			LED_PORT->MODER |= LED_BLUE_MODE_BIT;
			if (me->state==ON) {
				LED_PORT->ODR |= LED_BLUE_PIN;
				printf("The BLUE Led is set ON \n\r");
			}
			else {
				LED_PORT->ODR &= ~LED_BLUE_PIN;
				printf("The BLUE Led is set OFF \n\r");
			}
		break;
		}
	
}


//function set state
void Led_setState(Led_Type * const me,LedState_Type _state){
	me->state=_state;
	
	switch (me->color){
		case RED:
			LED_PORT->MODER |= LED_RED_MODE_BIT;
			if (me->state==ON) {
				LED_PORT->ODR |= LED_RED_PIN;
				printf("The RED Led is set ON \n\r");
			}
			else {
				LED_PORT->ODR &= ~LED_RED_PIN;
				printf("The RED Led is set OFF \n\r");
			}
		break;
			case GREEN:
			LED_PORT->MODER |= LED_GREEN_MODE_BIT;
			if (me->state==ON) {
				LED_PORT->ODR |= LED_GREEN_PIN;
				printf("The GREEN Led is set ON \n\r");
			}
			else {
				LED_PORT->ODR &= ~LED_GREEN_PIN;
				printf("The GREEN Led is set OFF \n\r");
			}
		break;
			case YELLOW:
			LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
			if (me->state==ON) {
				LED_PORT->ODR |= LED_YELLOW_PIN;
				printf("The YELLOW Led is set ON \n\r");
			}
			else {
				LED_PORT->ODR &= ~LED_YELLOW_PIN;
				printf("The YELLOW Led is set OFF \n\r");
			}
		break;
			case BLUE:
			LED_PORT->MODER |= LED_BLUE_MODE_BIT;
			if (me->state==ON) {
				LED_PORT->ODR |= LED_BLUE_PIN;
				printf("The BLUE Led is set ON \n\r");
			}
			else {
				LED_PORT->ODR &= ~LED_BLUE_PIN;
				printf("The BLUE Led is set OFF \n\r");
			}
		break;
		}
}

//function get state
LedState_Type Led_getState(Led_Type * const me){
	return me->state;
}
