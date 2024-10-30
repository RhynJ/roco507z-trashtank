#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

//libs needed
#include <Arduino.h>



void motorSetUp(void);
void rightForward(void);
void leftForward(void);
void rightBackwards(void);
void leftBackwards(void);
void goForward (void);
void goBackwards(void);
void turnLeft(void); 
void turnRight(void);
void turnOffMotor(void);
void slightLeft(void);
void slightRight(void);
void motorControl(unsigned int);


#endif