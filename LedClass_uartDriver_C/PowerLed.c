#include "PowerLed.h"

void PowerLed_ctor(PowerLed_Type * const me,
									 LedColor_Type _color,
									 LedState_Type _state, 
									 LedDiamter_Type _diameter,
									 LedCurrent_Type _current,
									 LedVoltage_Type _voltage){
	Led_ctor(&me->super,_color,_state);
	me->diameter	=_diameter;
	me->current = _current;
	me->voltage = _voltage;										 
}
									 
void PowerLed_setCurrent(PowerLed_Type * const me, LedCurrent_Type _current){
	me->current= _current;
}

void PowerLed_setDiameter(PowerLed_Type * const me, LedDiamter_Type _diameter){
	me->diameter= _diameter;
}

void PowerLed_setVoltage(PowerLed_Type * const me, LedVoltage_Type _voltage){
	me->voltage= _voltage;
}

led_elec_type Power_Led_computePower(PowerLed_Type *const me){
	return (me->current)*(me->voltage);
}
/*


led_elec_type Power_Led_getCurrent(PowerLed_Type *const me);
led_elec_type Power_Led_getDiameter(PowerLed_Type *const me);
led_elec_type Power_Led_getVoltage(PowerLed_Type *const me);
*/