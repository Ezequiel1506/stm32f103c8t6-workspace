/*
 * utility.c
 *
 *  Created on: 2 jul. 2022
 *      Author: Ezequiel
 */
#include "stm32f1xx_hal.h"
#include <utility.h>
#include <LCD1602.h>

const char* OVER_TEMP="Temperatura alta";
const char* UNDER_TEMP="Temperatura baja";
const char* OVER_HUM="Humedad alta";
const char* UNDER_HUM="Humedad baja";



const uint8_t TEMP_MAX	=	70;
const uint8_t TEMP_MIN	=	20;

const uint8_t HUM_MAX	=	80;
const uint8_t HUM_MIN	=	40;


uint8_t map(uint16_t au16_IN, uint16_t au16_INmin, uint16_t au16_INmax, uint16_t au16_OUTmin, uint16_t au16_OUTmax){
    return ((((au16_IN - au16_INmin)*(au16_OUTmax - au16_OUTmin))/(au16_INmax - au16_INmin)) + au16_OUTmin);
}

uint8_t adc_to_hum(uint16_t hum){
	uint8_t var;
	var=-0.026*hum+105;
	if(var>100){
		var=100.00;
	}
	return var;
}
uint8_t adc_to_temp(uint16_t au16_IN){
	uint8_t temp;
	temp=(((au16_IN*3.3/4096.0)*100)-27);
    return temp;
}
uint8_t calculate_volume(uint16_t h, float r){
	float var;
	uint8_t vol;
	var=h*r*r*2.14;
	vol=var*100/288;
	return (vol);
}

TempTypeDef check_temperature(uint8_t temp){

	if(temp>TEMP_MAX){
		return OVERTEMPERATURE;
	}
	else if(temp<TEMP_MIN){
		return UNDERTEMPERATURE;
	}
	else
		return TEMP_OK;

}

HUMTypeDef check_humidity(uint8_t hum){

	if(hum>HUM_MAX){
		return OVERHUMIDITY;
	}
	else if(hum<HUM_MIN){
		return UNDERHUMIDITY;
	}
	else
		return HUM_OK;

}

void print_error_msg(TempTypeDef temp, HUMTypeDef hum){
	switch(temp){
		case OVERTEMPERATURE:
			  lcd_clear();
			  lcd_put_cur(0, 0);
			  lcd_send_string(OVER_TEMP);
			  HAL_Delay(3000);
			break;

		case UNDERTEMPERATURE:
			  lcd_clear();
			  lcd_put_cur(0, 0);
			  lcd_send_string(UNDER_TEMP);
			  HAL_Delay(3000);
			break;

		case TEMP_OK:
			break;
	}

	switch(hum){
		case OVERHUMIDITY:
			  lcd_clear();
			  lcd_put_cur(0, 0);
			  lcd_send_string(OVER_HUM);
			  HAL_Delay(3000);
			break;

		case UNDERHUMIDITY:
			  lcd_clear();
			  lcd_put_cur(0, 0);
			  lcd_send_string(UNDER_HUM);
			  HAL_Delay(3000);
			break;

		case HUM_OK:
			break;
	}
}


