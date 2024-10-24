//#include "string"
 
//right motor pins
int rightDirectionPin = 12;
int rightMotorPin = 3;
 
//left motor pins
int leftDirectionPin = 13;
int leftMotorPin = 11;
 
//boolean to switch direction
 
 
void rightForward(void);
void leftForward(void);
void rightBackwards();
void leftBackwards();
void goForward (void);
void goBackwards(void);
void turnLeft(void);
void turnRight(void);
void turnOffMotor(void);
 
 
void setup() {
 
//define pins
pinMode(rightDirectionPin, OUTPUT);
pinMode(rightMotorPin, OUTPUT);
pinMode(leftDirectionPin, OUTPUT);
pinMode(leftMotorPin, OUTPUT);
 
}
 
void loop() {
 
  goBackwards();
 
  delay(2000);
 
  goForward();
 
  delay(2000);
 
  turnLeft();
 
 
  delay(2000);
 
  turnRight();
 
  delay(2000);
 
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
 