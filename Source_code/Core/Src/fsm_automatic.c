/*
 * fsm_automatic.c
 *
 *  Created on: Nov 4, 2023
 *      Author: Asus
 */

#include "fsm_automatic.h"

void fsm_automatic_run() {
	switch(status) {
	case INIT:
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);

		status = RED_AUTO;
		setTimer1(500);
		break;
	case RED_AUTO:
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);

		if(timer1_flag == 1) {
			status = GREEN_AUTO;
			setTimer1(300);
		}

		if(isButton1Pressed()) {
			status = RED_MAN;
			setTimer1(500);
		}
		break;
	case YELLOW_AUTO:
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);

		if(timer1_flag == 1) {
			status = RED_AUTO;
			setTimer1(500);
		}
		break;
	case GREEN_AUTO:
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);

		if(timer1_flag == 1) {
			status = YELLOW_AUTO;
			setTimer1(200);
		}
		break;
	default:
		break;
	}
};
