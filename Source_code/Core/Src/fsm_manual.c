/*
 * fsm_manual.c
 *
 *  Created on: Nov 4, 2023
 *      Author: Asus
 */

#include "fsm_manual.h"
void fsm_manual_run() {
	switch(status) {
	case RED_MAN:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);

		if(timer1_flag == 1) {
			status = RED_AUTO;
			setTimer1(500);
		}

		if(isButton1Pressed()) {
			status = GREEN_MAN;
			setTimer1(500);
		}
		break;
	case YELLOW_MAN:
		break;
	case GREEN_MAN:
		break;
	default:
		break;
	}
};
