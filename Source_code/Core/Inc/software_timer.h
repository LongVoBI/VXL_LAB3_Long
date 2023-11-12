/*
 * software_timer.h
 *
 *  Created on: Nov 3, 2023
 *      Author: Asus
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;			//Count down the total value
extern int timer2_flag;			//Update counter value
extern int timer3_flag;			//Wait for button2 and button3
extern int timer4_flag;			//Set blinky time for led in 0.5s
extern int timer5_flag;			//Set time for each 7SEG led display in 1s (each 0.25s)
extern int timerMan;

void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimer4(int duration);
void setTimer5(int duration);
void timerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */
