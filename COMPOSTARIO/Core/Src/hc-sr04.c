#include "stm32f1xx_hal.h"
#include <HC-SR04.h>

#define TRIG_PIN GPIO_PIN_10
#define TRIG_PORT GPIOB
#define ECHO_PIN GPIO_PIN_11
#define ECHO_PORT GPIOB

#define timer htim1
extern TIM_HandleTypeDef timer;

//uint32_t pMillis;					//ORIGINAL
//uint32_t Value1 = 0;				//ORIGINAL
//uint32_t Value2 = 0;				//ORIGINAL
//uint16_t Distance  = 0;			//ORIGINAL


uint16_t measure_distance() {
	uint32_t pMillis = 0;
	uint32_t Value1 = 0;
	uint32_t Value2 = 0;
	uint16_t Distance = 0;

	HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_RESET); // pull the TRIG pin low
	HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_SET); // pull the TRIG pin HIGH
	__HAL_TIM_SET_COUNTER(&timer, 0);
	while (__HAL_TIM_GET_COUNTER (&timer) < 10);  // wait for 10 us
		HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_RESET); // pull the TRIG pin low

	pMillis = HAL_GetTick(); // used this to avoid infinite while loop  (for timeout)
	// wait for the echo pin to go high
	while (!(HAL_GPIO_ReadPin(ECHO_PORT, ECHO_PIN))&& pMillis + 10 > HAL_GetTick());
		Value1 = __HAL_TIM_GET_COUNTER(&timer);

	pMillis = HAL_GetTick(); // used this to avoid infinite while loop (for timeout)
	// wait for the echo pin to go low
	while ((HAL_GPIO_ReadPin(ECHO_PORT, ECHO_PIN))&& pMillis + 50 > HAL_GetTick());
		Value2 = __HAL_TIM_GET_COUNTER(&timer);

	Distance = (Value2 - Value1) * 0.034 / 2;
	HAL_Delay(50);

	return Distance;

}
