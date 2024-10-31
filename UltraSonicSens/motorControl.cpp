#include "motorControl.h"
#include <Arduino.h>

//right motor pins
const int rightDirectionPin = 12;
const int rightMotorPin = 3;

//left motor pins
const int leftDirectionPin = 13;
const int leftMotorPin = 11;
unsigned int currentDirection = 0;



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

void motorControl(unsigned int control)
{
  // Use a switch-case structure to handle different motor controls
  switch(control){
    case 0:
      // Stop the motor
      turnOffMotor();
      currentDirection = 0;
      break;

    case 1:
      // Move forward
      goForward();
      currentDirection = 1;
      break;

    case 2:
      // Move in reverse
      goBackwards();
      currentDirection = 2;
      break;

    case 3:
      // Turn left
      turnLeft();
      currentDirection = 3;
      break;

    case 4:
      // Turn right
      turnRight();
      currentDirection = 4;
      break;

    case 5:
      // Slight left
      // Slight left  needed
      slightLeft();
      currentDirection = 5;
      break;

    case 6:
      // Slight right
      slightRight();
      currentDirection = 6;
      break;

    default:
      // If an invalid control is passed, stop the motor as a safe action
      turnOffMotor();
      currentDirection = 0;
      break;
    }
}



