/*
 * displayLed.h
 *
 *  Created on: 5 thg 11, 2023
 *      Author: Asus
 */

#ifndef INC_DISPLAYLED_H_
#define INC_DISPLAYLED_H_

#include "global.h"

void update7SEG(int index);
void display7SEG_road2(int counter);
void display7SEG_road2(int counter);

void displayLed(int index);
void turnOffLed();

extern int counter1;
extern int counter2;

#endif /* INC_DISPLAYLED_H_ */
