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
typedef struct {
	struct LedVtable const *vptr; //the virtual pointer is a pointer to the virtual table (vptr point to vtable) and it is const because it is immutable object
	LedColor_Type color; //Color of Led
	LedState_Type state; //State of Led
	uint32_t last_update; 
}Led_Type;

//we will create a virtual table (vtable)(it named virtual because it will hold table of virtual pointers that point to virtual functions introduced by the class which are related to polymorphism)
/*Led virtual table*/
struct LedVtable{
	void (*run_diagnostics)(Led_Type const * const me);//this function is for run diagnostics on all Leds, run_diagnostics stores the address of a function that receives a pointer to an LED object and returns nothing.
	uint32_t (*compute_efficiency)(Led_Type const * const me);//this function is for compute the effeciency of the Led
};//This is basically a structure containing function pointers.


// Now we will develop 3 functions , one for creating an Led (like constructor) , the second one is for setting the state of the Led and third one for get the state of the Led

void Led_ctor(Led_Type * const me,LedColor_Type _color, LedState_Type _state);
void Led_setState(Led_Type * const me,LedState_Type _state);
LedState_Type Led_getState(Led_Type * const me);

/*Method 1*/
static inline void Led_runDiagnostics_vcall(Led_Type const * const me){ //me is a constant pointer pointing to a constant Led_Type.
	me->vptr->run_diagnostics(me);
}
static inline uint32_t Led_computeEffi_vcall(Led_Type const * const me){
	return me->vptr->compute_efficiency(me);
}

//inline: suggests that the compiler may replace the function call with its body to reduce call overhead.

/*Method 2*/

#define LED_RUN_DIAG_VCALL(me)  (*(me)->vptr->run_diagnostics)(me)
#define LED_GET_EFFI_VCALL(me)  (*(me)->vptr->compute_efficiency)(me)


/*Run System diagnostics*/
void runSystemDiagnostics(Led_Type const *led_modules[]);
void computeLedEffs(Led_Type const *led_modules[]);


/*
2. What are we trying to add when introduce vtable and vptr ? :
A normal LED might have:

Led_runDiagnostics()
Led_computeEfficiency()

But a PowerLed may need its own implementation of these functions.

And a MedicalLed may need a different implementation.

This is the idea of polymorphism:

Led pointer
    ¦
    +-- ordinary Led ? ordinary diagnostic()
    ¦
    +-- PowerLed     ? PowerLed diagnostic()
    ¦
    +-- MedicalLed   ? MedicalLed diagnostic()
	
C doesn't have C++'s virtual keyword.

So we build something similar manually using function pointers.

void (*function)(int); This means : function is a pointer to a function that takes an int and returns void.
A function pointer lets us store the address of a function inside a variable.

*/


#endif 