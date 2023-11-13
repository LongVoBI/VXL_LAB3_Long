/*
 * displayLed.c
 *
 *  Created on: 5 thg 11, 2023
 *      Author: Asus
 */

#include "displayLed.h"
#include "main.h"

int counter1 = 0;
int counter2 = 0;

const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1, 2, 3, 4};


void turnOffLed() {
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
}

void displayLed(int led_index) {
	switch(led_index) {
	case RED_MAN:
		if(timer4_flag == 1) {
			setTimer4(25);
			HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
			HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
		}
		break;
	case YELLOW_MAN:
		if(timer4_flag == 1) {
			setTimer4(25);
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
			HAL_GPIO_TogglePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
			HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
		}
		break;
	case GREEN_MAN:
		if(timer4_flag == 1) {
			setTimer4(25);
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
			HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
			HAL_GPIO_TogglePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
		}
		break;
	case RED1_GREEN2:
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
		HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, RESET);
		break;
	case RED1_YELLOW2:
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
		HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
		break;
	case GREEN1_RED2:
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);
		HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
		break;
	case YELLOW1_RED2:
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
		HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
		break;
	default:
		break;
	}
}

void scanLedBuffer() {
	if(timer5_flag == 1) {
		setTimer5(25);
		update7SEG(index_led);
		index_led++;
		if(index_led >= MAX_LED) index_led = 0;
	}
}

void updateLedBufferVal(int val0, int val1, int val2, int val3) {
	led_buffer[0] = val0;
	led_buffer[1] = val1;
	led_buffer[2] = val2;
	led_buffer[3] = val3;
}

void update7SEG(int index) {
	switch(index) {
	case 0:
		HAL_GPIO_WritePin (EN0_GPIO_Port, EN0_Pin, RESET);
		HAL_GPIO_WritePin (EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin (EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin (EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG(led_buffer[index]);
		break;
	case 1:
		HAL_GPIO_WritePin (EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin (EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin (EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin (EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG(led_buffer[index]);
		break;
	case 2:
		HAL_GPIO_WritePin (EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin (EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin (EN2_GPIO_Port, EN2_Pin, RESET);
		HAL_GPIO_WritePin (EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG(led_buffer[index]);
		break;
	case 3:
		HAL_GPIO_WritePin (EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin (EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin (EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin (EN3_GPIO_Port, EN3_Pin, RESET);
		display7SEG(led_buffer[index]);
		break;
	}
}

void display7SEG(int counter) {
	if(counter == 0) {
		HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, RESET);
		HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, RESET);
		HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
		HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, RESET);
		HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, RESET);
		HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, RESET);
		HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, SET);
	}
	else if(counter == 1) {
		HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, SET);
		HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, RESET);
		HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
		HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, SET);
		HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, SET);
		HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, SET);
		HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, SET);
	}
	else if(counter == 2) {
		HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, RESET);
		HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, RESET);
		HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, SET);
		HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, RESET);
		HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, RESET);
		HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, SET);
		HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, RESET);
	}

	else if(counter == 3) {
		HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, RESET);
		HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, RESET);
		HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
		HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, RESET);
		HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, SET);
		HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, SET);
		HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, RESET);
	}
	else if(counter == 4) {
		HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, SET);
		HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, RESET);
		HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
		HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, SET);
		HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, SET);
		HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, RESET);
		HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, RESET);
	}
	else if(counter == 5) {
		HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, RESET);
		HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, SET);
		HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
		HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, RESET);
		HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, SET);
		HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, RESET);
		HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, RESET);
	}
	else if(counter == 6) {
		HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, RESET);
		HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, SET);
		HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
		HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, RESET);
		HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, RESET);
		HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, RESET);
		HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, RESET);
	}
	else if(counter == 7) {
		HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, RESET);
		HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, RESET);
		HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
		HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, SET);
		HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, SET);
		HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, SET);
		HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, SET);
	}
	else if(counter == 8) {
		HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, RESET);
		HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, RESET);
		HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
		HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, RESET);
		HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, RESET);
		HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, RESET);
		HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, RESET);
	}
	else if(counter == 9) {
		HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, RESET);
		HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, RESET);
		HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, RESET);
		HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, RESET);
		HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, SET);
		HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, RESET);
		HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, RESET);
	}

}
