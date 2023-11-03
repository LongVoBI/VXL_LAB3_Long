/*
 * button.c
 *
 *  Created on: Nov 3, 2023
 *      Author: Asus
 */

#include "button.h"

int button1_flag = 0;

int keyReg0 = NORMAL_STATE;
int keyReg1 = NORMAL_STATE;
int keyReg2 = NORMAL_STATE;

int keyReg3 = NORMAL_STATE;
int timerForKeyPress = 200;

void subKeyProcess() {
	button1_flag = 1;
}

void getKeyInput() {
	keyReg0 = keyReg1;
	keyReg1 = keyReg2;
	keyReg2 = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
	if((keyReg0 == keyReg1) && (keyReg1 == keyReg2)) {
		if(keyReg3 != keyReg2) {	// Press and release
			keyReg3 = keyReg2;
			if(keyReg2 == PRESSED_STATE) {
				//TO DO
				subKeyProcess();
				timerForKeyPress = 200;

			}
		}
		else {		// Press and hold
			timerForKeyPress--;
			if(timerForKeyPress <= 0) {
				//TO DO
				if(keyReg2 == PRESSED_STATE) {
					subKeyProcess();
				}
				timerForKeyPress = 200;
			}
		}
	}
}
