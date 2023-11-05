/*
 * displayLed.c
 *
 *  Created on: 5 thg 11, 2023
 *      Author: Asus
 */

#include "displayLed.h"

void update7SEG(int index) {
	switch(index) {
	case 0:
		display7SEG_road1(0);
		display7SEG_road2(0);
	case 1:

	}
}

void display7SEG_road1(int counter) {
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
		HAL_GPIO_WritePin(a_GPIO_Port, a1_Pin, RESET);
		HAL_GPIO_WritePin(b_GPIO_Port, b1_Pin, RESET);
		HAL_GPIO_WritePin(c_GPIO_Port, c1_Pin, SET);
		HAL_GPIO_WritePin(d_GPIO_Port, d1_Pin, RESET);
		HAL_GPIO_WritePin(e_GPIO_Port, e1_Pin, RESET);
		HAL_GPIO_WritePin(f_GPIO_Port, f1_Pin, SET);
		HAL_GPIO_WritePin(g_GPIO_Port, g1_Pin, RESET);
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

void display7SEG_road2(int counter) {
	if(counter == 0) {
		HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, RESET);
		HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, RESET);
		HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, RESET);
		HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, RESET);
		HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, RESET);
		HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, RESET);
		HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, SET);
	}
	else if(counter == 1) {
		HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, SET);
		HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, RESET);
		HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, RESET);
		HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, SET);
		HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, SET);
		HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, SET);
		HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, SET);
	}
	else if(counter == 2) {
		HAL_GPIO_WritePin(a_GPIO_Port, a2_Pin, RESET);
		HAL_GPIO_WritePin(b_GPIO_Port, b2_Pin, RESET);
		HAL_GPIO_WritePin(c_GPIO_Port, c2_Pin, SET);
		HAL_GPIO_WritePin(d_GPIO_Port, d2_Pin, RESET);
		HAL_GPIO_WritePin(e_GPIO_Port, e2_Pin, RESET);
		HAL_GPIO_WritePin(f_GPIO_Port, f2_Pin, SET);
		HAL_GPIO_WritePin(g_GPIO_Port, g2_Pin, RESET);
	}

	else if(counter == 3) {
		HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, RESET);
		HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, RESET);
		HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, RESET);
		HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, RESET);
		HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, SET);
		HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, SET);
		HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, RESET);
	}
	else if(counter == 4) {
		HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, SET);
		HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, RESET);
		HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, RESET);
		HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, SET);
		HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, SET);
		HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, RESET);
		HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, RESET);
	}
	else if(counter == 5) {
		HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, RESET);
		HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, SET);
		HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, RESET);
		HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, RESET);
		HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, SET);
		HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, RESET);
		HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, RESET);
	}
	else if(counter == 6) {
		HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, RESET);
		HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, SET);
		HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, RESET);
		HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, RESET);
		HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, RESET);
		HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, RESET);
		HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, RESET);
	}
	else if(counter == 7) {
		HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, RESET);
		HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, RESET);
		HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, RESET);
		HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, SET);
		HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, SET);
		HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, SET);
		HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, SET);
	}
	else if(counter == 8) {
		HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, RESET);
		HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, RESET);
		HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, RESET);
		HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, RESET);
		HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, RESET);
		HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, RESET);
		HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, RESET);
	}
	else if(counter == 9) {
		HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, RESET);
		HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, RESET);
		HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, RESET);
		HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, RESET);
		HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, SET);
		HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, RESET);
		HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, RESET);
	}

}

