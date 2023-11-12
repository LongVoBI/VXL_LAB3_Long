/*
 * fsm_manual.c
 *
 *  Created on: Nov 4, 2023
 *      Author: Asus
 */

#include "fsm_manual.h"

void switchMode3() {
	status = YELLOW_MAN;
	counter1 = 3;
	setTimer1(300);
	setTimer2(100);
	setTimer3(300);
	setTimer4(25);
	updateLedBufferVal(0, 3, counter1, 3);
}

void switchMode4() {
	status = GREEN_MAN;
	counter1 = 3;
	setTimer1(300);
	setTimer2(100);
	setTimer3(300);
	setTimer4(25);
	updateLedBufferVal(0, 4, counter1, 4);
}

void fsm_manual_run() {
	switch(status) {

	case RED_MAN:
		displayLed(RED_MAN);

		updateLedBuffer();

		if(timer1_flag == 1) {
			status = INIT;
			setTimer1(500);
		}

		if(timer2_flag == 1) {
			setTimer2(100);
			counter1--;
			updateLedBufferVal(counter1/10, 2, counter1%10, 2);
		}

		if(isButtonPressed(0)) {
			switchMode3();
		}
		if(isButtonPressed(1)) {
			status = RED_MAN_MODIFY;
			setTimer1(300);
			timerMan = 1;
			updateLedBufferVal(timerMan/10, 2, timerMan%10, 2);
		}
		break;
	case RED_MAN_MODIFY:
		if(timer1_flag == 1) {
			setTimer1(counter1*100);
			status = RED_MAN;
		}
		updateLedBuffer();

		if(isButtonPressed(1)) {
			setTimer1(300);
			timerMan++;
			if(timerMan > 99) timerMan = 1;
			updateLedBufferVal(timerMan/10, 2, timerMan%10, 2);
		}
		if(isButtonPressed(2)) {
			status = RED_MAN;
			counter1 = timerMan;
			setTimer1(counter1*100);
			updateLedBufferVal(counter1/10, 2, counter1%10, 2);
		}

		break;
	case YELLOW_MAN:
		displayLed(YELLOW_MAN);

		updateLedBuffer();

		if(timer1_flag == 1) {
			status = INIT;
			setTimer1(500);
		}

		if(timer2_flag == 1) {
			setTimer2(100);
			counter1--;
			updateLedBufferVal(counter1/10, 3, counter1%10, 3);
		}

		if(isButtonPressed(0)) {
			switchMode4();
		}
		if(isButtonPressed(1)) {
			status = YELLOW_MAN_MODIFY;
			setTimer1(300);
			timerMan = 1;
			updateLedBufferVal(timerMan/10, 3, timerMan%10, 3);
		}
		break;
	case YELLOW_MAN_MODIFY:
		if(timer1_flag == 1) {
			setTimer1(counter1*100);
			status = YELLOW_MAN;
		}
		updateLedBuffer();

		if(isButtonPressed(1)) {
			setTimer1(300);
			timerMan++;
			if(timerMan > 99) timerMan = 1;
			updateLedBufferVal(timerMan/10, 3, timerMan%10, 3);
		}
		if(isButtonPressed(2)) {
			status = YELLOW_MAN;
			counter1 = timerMan;
			setTimer1(counter1*100);
			updateLedBufferVal(counter1/10, 3, counter1%10, 3);
		}
		break;
	case GREEN_MAN:
		displayLed(GREEN_MAN);

		updateLedBuffer();

		if(timer1_flag == 1) {
			status = INIT;
			setTimer1(500);
		}

		if(timer2_flag == 1) {
			setTimer2(100);
			counter1--;
			updateLedBufferVal(counter1/10, 4, counter1%10, 4);
		}

		if(isButtonPressed(0)) {
			status = INIT;
			setTimer1(500);
		}
		if(isButtonPressed(1)) {
			status = GREEN_MAN_MODIFY;
			setTimer1(300);
			timerMan = 1;
			updateLedBufferVal(timerMan/10, 4, timerMan%10, 4);
		}
		break;
	case GREEN_MAN_MODIFY:
		if(timer1_flag == 1) {
			setTimer1(counter1*100);
			status = GREEN_MAN;
		}
		updateLedBuffer();

		if(isButtonPressed(1)) {
			setTimer1(300);
			timerMan++;
			if(timerMan > 99) timerMan = 1;
			updateLedBufferVal(timerMan/10, 4, timerMan%10, 4);
		}
		if(isButtonPressed(2)) {
			status = GREEN_MAN;
			counter1 = timerMan;
			setTimer1(counter1*100);
			updateLedBufferVal(counter1/10, 4, counter1%10, 4);
		}
		break;
	default:
		break;
	}
};
