/*
 * fsm_manual.c
 *
 *  Created on: Nov 4, 2023
 *      Author: Asus
 */

#include "fsm_manual.h"

void switchMode3() {
	status = YELLOW_MAN;
	counter1 = yellowTimer;
	setTimer2(100);
	setTimer4(25);
	updateLedBufferVal(counter1/10, 3, counter1%10, 3);
}

void switchMode4() {
	status = GREEN_MAN;
	counter1 = greenTimer;
	setTimer2(100);
	setTimer4(25);
	updateLedBufferVal(counter1/10, 4, counter1%10, 4);
}

void fsm_manual_run() {
	switch(status) {

	case RED_MAN:
		displayLed(RED_MAN);

		if(timer2_flag == 1) {
			setTimer2(100);
			updateLedBufferVal(counter1/10, 2, counter1%10, 2);
		}

		if(isButtonPressed(0)) {
			switchMode3();
		}

		if(isButtonPressed(1)) {
			status = RED_MAN_MODIFY;
			timerMan = redTimer;
			updateLedBufferVal(timerMan/10, 2, timerMan%10, 2);
		}
		break;
	case RED_MAN_MODIFY:
		displayLed(RED_MAN);

		if(isButtonPressed(0)) {
			status = RED_MAN;
		}

		if(isButtonPressed(1)) {
			timerMan++;
			if(timerMan > 99) timerMan = 1;
			updateLedBufferVal(timerMan/10, 2, timerMan%10, 2);
		}

		if(isButtonPressed(2)) {
			status = INIT;
			redTimer = timerMan;
			greenTimer = redTimer - yellowTimer;
		}

		break;
	case YELLOW_MAN:
		displayLed(YELLOW_MAN);

		if(timer2_flag == 1) {
			setTimer2(100);
			updateLedBufferVal(counter1/10, 3, counter1%10, 3);
		}

		if(isButtonPressed(0)) {
			switchMode4();
		}

		if(isButtonPressed(1)) {
			status = YELLOW_MAN_MODIFY;
			timerMan = yellowTimer;
			updateLedBufferVal(timerMan/10, 3, timerMan%10, 3);
		}
		break;
	case YELLOW_MAN_MODIFY:
		displayLed(YELLOW_MAN);

		if(isButtonPressed(0)) {
			status = YELLOW_MAN;
		}

		if(isButtonPressed(1)) {
			timerMan++;
			if(timerMan >= redTimer) timerMan = 1;
			updateLedBufferVal(timerMan/10, 3, timerMan%10, 3);
		}

		if(isButtonPressed(2)) {
			status = INIT;
			yellowTimer = timerMan;
			greenTimer = redTimer-yellowTimer;
		}
		break;
	case GREEN_MAN:
		displayLed(GREEN_MAN);

		if(timer2_flag == 1) {
			setTimer2(100);
			updateLedBufferVal(counter1/10, 4, counter1%10, 4);
		}

		if(isButtonPressed(0)) {
			status = INIT;
		}

		if(isButtonPressed(1)) {
			status = GREEN_MAN_MODIFY;
			timerMan = greenTimer;
			updateLedBufferVal(timerMan/10, 4, timerMan%10, 4);
		}
		break;
	case GREEN_MAN_MODIFY:
		displayLed(GREEN_MAN);

		if(isButtonPressed(0)) {
			status = GREEN_MAN;
		}

		if(isButtonPressed(1)) {
			timerMan++;
			if(timerMan >= redTimer) timerMan = 1;
			updateLedBufferVal(timerMan/10, 4, timerMan%10, 4);
		}

		if(isButtonPressed(2)) {
			status = INIT;
			greenTimer = timerMan;
			yellowTimer = redTimer - greenTimer;
		}
		break;
	default:
		break;
	}
};
