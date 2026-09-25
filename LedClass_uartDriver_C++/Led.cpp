#include 	"Led.h"
#include <stdio.h>

//function constructor
Led::Led(LedColor_Type _color, LedState_Type _state)
{
	this->color=_color;
	this->state=_state;
	
	/*Hardware Init*/
	RCC->AHB1ENR|= LED_PORT_CLOCK;
	
	switch (_color){
		case RED:
			LED_PORT->MODER |= LED_RED_MODE_BIT;
			if (this->state==ON) {
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
			if (this->state==ON) {
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
			if (this->state==ON) {
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
			if (this->state==ON) {
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
void Led::setState(LedState_Type _state){
	this->state=_state;
	
	switch (this->color){
		case RED:
			LED_PORT->MODER |= LED_RED_MODE_BIT;
			if (this->state==ON) {
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
			if (this->state==ON) {
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
			if (this->state==ON) {
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
			if (this->state==ON) {
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
LedState_Type Led::getState(void) const {
	return this->state;
}
