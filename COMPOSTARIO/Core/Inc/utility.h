/*
 * utility.h
 *
 *  Created on: 2 jul. 2022
 *      Author: Ezequiel
 */

#ifndef INC_UTILITY_H_
#define INC_UTILITY_H_

typedef enum
{
  TEMP_OK       = 0x00U,
  OVERTEMPERATURE    = 0x01U,
  UNDERTEMPERATURE     = 0x02U
} TempTypeDef;

typedef enum
{
  HUM_OK       = 0x00U,
  OVERHUMIDITY    = 0x01U,
  UNDERHUMIDITY     = 0x02U
} HUMTypeDef;

typedef enum
{
  SUN_OK       = 0x00U,
  SUN_NOK    = 0x01U,
} SUNTypeDef;



uint8_t map(uint16_t au16_IN, uint16_t au16_INmin, uint16_t au16_INmax, uint16_t au16_OUTmin, uint16_t au16_OUTmax);
uint8_t adc_to_temp(uint16_t au16_IN);
TempTypeDef check_temperature(uint8_t temp);
HUMTypeDef check_humidity(uint8_t hum);
uint8_t adc_to_hum(uint16_t hum);
void print_error_msg(TempTypeDef temp, HUMTypeDef hum);
uint8_t calculate_volume(uint16_t h, float r);

#endif /* INC_UTILITY_H_ */
