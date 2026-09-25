#ifndef POWERLED_H
#define POWERLED_H

#include "Led.h"

typedef uint8_t led_elec_type;
typedef uint8_t led_dim_type;

typedef enum{
	CURR_LOW        = 10, 	/*10mA*/
	CURR_NORMAL     = 20,
	CURR_HIGH       = 35,
	CURR_VERY_HIGH  = 60
}LedCurrent_Type;

typedef enum{
	DIAM_2MM = 2, /*2nm*/
	DIAM_5MM = 5,
	DIAM_7MM = 7
}LedDiamter_Type;
	
typedef enum{
	VOL_LOW 			= 3, /*2nm*/
	VOL_NORMAL  	= 5,
	VOL_HIGH 			= 9
}LedVoltage_Type;	

class PowerLed:public Led {
	private :
		LedDiamter_Type 	diameter;
		LedCurrent_Type 	current;
		LedVoltage_Type 	voltage;


	public:
		PowerLed(LedColor_Type _color,
						LedState_Type _state,
	  				LedDiamter_Type _diameter,
						LedCurrent_Type _current,
						LedVoltage_Type _voltage);

		void PowerLed_setCurrent( LedCurrent_Type _current);
		void PowerLed_setDiameter(LedDiamter_Type _diameter);
		void PowerLed_setVoltage(LedVoltage_Type _voltage);

		led_elec_type Power_Led_getCurrent();
		led_elec_type Power_Led_getDiameter();
		led_elec_type Power_Led_getVoltage();

		led_elec_type Power_Led_computePower();

};


#endif