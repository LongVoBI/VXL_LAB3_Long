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
		turnOffLed();

		status = RED1_GREEN2_AUTO;
		counter1 = 5;
		counter2 = 3;
		setTimer1(300);
		setTimer2(100);
		break;
	case RED1_GREEN2_AUTO:
		displayLed(RED1_GREEN2);

		display7SEG_road1(counter1);
		display7SEG_road2(counter2);
		if(timer2_flag == 1) {
			setTimer2(100);
			counter1--;
			counter2--;
		}

		if(timer1_flag == 1) {
			status = RED1_YELLOW2_AUTO;
			setTimer1(200);
			counter1 = 2;
			counter2 = 2;
		}

		if(isButtonPressed(0)) {
			status = RED_MAN;
			timerMan = 100;
			setTimer3(200);
		}
		break;
	case RED1_YELLOW2_AUTO:
		displayLed(RED1_YELLOW2);

		display7SEG_road1(counter1);
		display7SEG_road2(counter2);
		if(timer2_flag == 1) {
			setTimer2(100);
			counter1--;
			counter2--;
		}

		if(timer1_flag == 1) {
			status = GREEN1_RED2_AUTO;
			setTimer1(300);
			counter1 = 3;
			counter2 = 5;
		}

		if(isButtonPressed(0)) {
			status = RED_MAN;
			timerMan = 100;
			setTimer3(200);
		}
		break;
	case GREEN1_RED2_AUTO:
		displayLed(GREEN1_RED2);

		display7SEG_road1(counter1);
		display7SEG_road2(counter2);
		if(timer2_flag == 1) {
			setTimer2(100);
			counter1--;
			counter2--;
		}

		if(timer1_flag == 1) {
			status = YELLOW1_RED2_AUTO;
			setTimer1(200);
			counter1 = 2;
			counter2 = 2;
		}

		if(isButtonPressed(0)) {
			status = RED_MAN;
			timerMan = 100;
			setTimer3(200);
		}
		break;
	case YELLOW1_RED2_AUTO:
		displayLed(YELLOW1_RED2);

		display7SEG_road1(counter1);
		display7SEG_road2(counter2);
		if(timer2_flag == 1) {
			setTimer2(100);
			counter1--;
			counter2--;
		}

		if(timer1_flag == 1) {
			status = RED1_GREEN2_AUTO;
			setTimer1(300);
			counter1 = 5;
			counter2 = 3;
		}

		if(isButtonPressed(0)) {
			status = RED_MAN;
			timerMan = 100;
			setTimer3(200);
		}
		break;
	default:
		break;
	}
};
