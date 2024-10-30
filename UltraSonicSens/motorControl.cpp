#include "motorControl.h"
#include <Arduino.h>

//right motor pins
const int rightDirectionPin = 12;
const int rightMotorPin = 3; 
//left motor pins
const int leftDirectionPin = 13;
const int leftMotorPin = 11;





void motorSetUp(void)
{
  pinMode(rightDirectionPin, OUTPUT);
  pinMode(rightMotorPin, OUTPUT);
  pinMode(leftDirectionPin, OUTPUT);
  pinMode(leftMotorPin, OUTPUT);
}




void rightForwards(void)
{
  digitalWrite(rightDirectionPin, HIGH);
  digitalWrite(rightMotorPin, HIGH);
}
 
void leftForwards(void)
{
  digitalWrite(leftDirectionPin, LOW);
  digitalWrite(leftMotorPin, HIGH);
}
 
void rightBackwards()
{
  digitalWrite(rightDirectionPin, LOW);
  digitalWrite(rightMotorPin, HIGH);
}
 
void leftBackwards()
{
  digitalWrite(leftDirectionPin, HIGH);
  digitalWrite(leftMotorPin, HIGH);
}
 
 
void goForward(void)
{
  rightForwards();
  leftForwards();
}
 
void goBackwards(void)
{
  rightBackwards();
  leftBackwards();
}
 
void turnLeft(void)
{
  leftForwards();
  rightBackwards();
}
 
void turnRight(void)
{
  rightForwards();
  leftBackwards();
}
 
void turnOffMotor(void)
{
  digitalWrite(rightMotorPin, LOW);
  digitalWrite(leftMotorPin, LOW);
}


void slightRight(void)
{
    rightForwards();
    digitalWrite(leftMotorPin, LOW);
}

void slightLeft(void)
{
    leftForwards();
    digitalWrite(rightMotorPin, LOW);
}

