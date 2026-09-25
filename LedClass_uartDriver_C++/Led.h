#ifndef LED_H
#define LED_H

#include "uart.h"
#include <stdint.h>
#include "stm32f7xx.h"                  // Device header
#

#define LED_PORT GPIOB
#define LED_PORT_CLOCK (1U<<1)

#define LED_RED_PIN (1U<<14)
#define LED_GREEN_PIN (1U<<12)
#define LED_BLUE_PIN (1U<<15)
#define LED_YELLOW_PIN (1U<<13)

#define LED_RED_MODE_BIT (1U<<28)
#define LED_GREEN_MODE_BIT (1U<<24)
#define LED_BLUE_MODE_BIT (1U<<30)
#define LED_YELLOW_MODE_BIT (1U<<26)

// An enum is a special type that represents a group of constants (unchangeable values).
// You can also use typedef with enum. This makes it easier to declare variables of the enum type, without having to write enum every time:
// The typedef keyword lets you create a new name (an alias) for an existing type.

 typedef enum{
	 RED = 0,
	 GREEN,
	 YELLOW,
	 BLUE
} LedColor_Type;

typedef enum{
	OFF = 0,
	ON =  1
}LedState_Type;

/*Led's attributes*/
class Led{
	private :
		LedColor_Type color; //Color of Led
	  LedState_Type state; //State of Led
	public :
		// Now we will develop 3 functions , one for creating an Led (like constructor) , the seconf one is for setting the state of the Led and third one for get the state of the Led
		Led(LedColor_Type _color, LedState_Type _state);
		void setState(LedState_Type _state);
		LedState_Type getState() const;
};


#endif 