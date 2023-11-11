/*
 * button.c
 *
 *  Created on: Nov 3, 2023
 *      Author: Asus
 */

#include "button.h"

#define NUMBER_BUTTONS		3

int KeyReg0[NUMBER_BUTTONS];
int KeyReg1[NUMBER_BUTTONS];
int KeyReg2[NUMBER_BUTTONS];
int KeyReg3[NUMBER_BUTTONS];

int timerForKeyPress[NUMBER_BUTTONS];
int button_flag[NUMBER_BUTTONS];

uint16_t gpio_pin[NUMBER_BUTTONS] = {button1_Pin, button2_Pin, button3_Pin};
GPIO_TypeDef* gpio_port[NUMBER_BUTTONS] = {button1_GPIO_Port, button2_GPIO_Port, button3_GPIO_Port};

void initStateForButton() {
	for (int i = 0; i < NUMBER_BUTTONS; ++i) {
	    KeyReg0[i] = NORMAL_STATE;
	    KeyReg1[i] = NORMAL_STATE;
	    KeyReg2[i] = NORMAL_STATE;
	    KeyReg3[i] = NORMAL_STATE;
	    timerForKeyPress[i] = 200;
	    button_flag[i] = 0;
	 }
}

int isButtonPressed(int key_index) {
	if(button_flag[key_index] == 1) {
		button_flag[key_index] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int key_index) {
	button_flag[key_index] = 1;
}

void getKeyInput() {
	for(int i = 0; i<NUMBER_BUTTONS; i++) {
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		KeyReg2[i] = HAL_GPIO_ReadPin(gpio_port[i], gpio_pin[i]);
		if((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])) {
			if(KeyReg3[i] != KeyReg2[i]) {	// Press and release
				KeyReg3[i] = KeyReg2[i];
				if(KeyReg2[i] == PRESSED_STATE) {
					//TO DO
					subKeyProcess(i);
					timerForKeyPress[i] = 200;
				}
			}
			else {		// Press and hold
				timerForKeyPress[i]--;
				if(timerForKeyPress[i] <= 0) {
					//TO DO
					if(KeyReg2[i] == PRESSED_STATE) {
						subKeyProcess(i);
					}
					timerForKeyPress[i] = 200;
				}
			}
		}
	}
}
