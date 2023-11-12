/*
 * fsm_manual.c
 *
 *  Created on: Nov 4, 2023
 *      Author: Asus
 */

#include "fsm_manual.h"

//void fsm_manual_run() {
//	switch(status) {
//	case RED_MAN:
//		if(timer3_flag == 1) {
//			displayLed(RED_MAN);
//
//			display7SEG_road1(counter1);
//
//			if(timer1_flag == 1) {
//				status = INIT;
//				setTimer1(500);
//			}
//
//			if(timer2_flag == 1) {
//				setTimer2(100);
//				counter1--;
//			}
//
//			if(isButtonPressed(0)) {
//				status = GREEN_MAN;
//				timerMan = 500;
//				setTimer1(timerMan);
//			}
//		}
//		else {
//			if(isButtonPressed(1)) {
//				setTimer3(200);
//				timerMan += 100;
//			}
//			if(isButtonPressed(2)) {
//				counter1 = timerMan/100;
//				setTimer3(0);
//			}
//			else {
//				counter1 = 1;
//			}
//		}
//
//		break;
//	case YELLOW_MAN:
//		break;
//	case GREEN_MAN:
//		break;
//	default:
//		break;
//	}
//};
