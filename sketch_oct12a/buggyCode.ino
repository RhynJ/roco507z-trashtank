#include "string"

//rifght motor pins 
int rightDirectionPin = 12;
int rightPwmPin = 3;
int rightBrakePin = 9;

//left motor pins 
int leftDirectionPin = 13;
int leftPwmPin = 11;
int leftBrakePin = 8;

//boolean to switch direction
bool leftDirectionState, rightDirectionState;



void goForward (void);
void goBackwards(void);
void turnLeft(void);
void turnRight(void);



void setup() {
  
//define pins
pinMode(rightDirection, OUTPUT);
pinMode(rightPwmPin, OUTPUT);
pinMode(rightBrakePin, OUTPUT);

pinMode(leftDirectionPin, OUTPUT);
pinMode(leftPwmPin, OUTPUT);
pinMode(leftBrakePin, OUTPUT);

}

void loop() {

//change direction every loop()
rightDirectionState = !rightDirectionState;
leftDirectionState =! leftDirectionState;

//write a low state to the direction pin (13)
if(directionState == false){
  digitalWrite(directionPin, LOW);
}

//write a high state to the direction pin (13)
else{
  digitalWrite(directionPin, HIGH);
}

//release breaks
digitalWrite(brakePin, LOW);

//set work duty for the motor
analogWrite(pwmPin, 30);

delay(2000);

//activate breaks
digitalWrite(brakePin, HIGH);

//set work duty for the motor to 0 (off)
analogWrite(pwmPin, 0);

delay(2000);
}