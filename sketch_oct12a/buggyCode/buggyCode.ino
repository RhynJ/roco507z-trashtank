//#include "string"

//right motor pins 
//int rightDirectionPin = 12;
int rightMotorPin = 3;

//left motor pins 
//int leftDirectionPin = 13;
int leftMotorPin = 11;

//boolean to switch direction



void goForward (void);
void goBackwards(void);
void turnLeft(void);
void turnRight(void);
void turnOffMotor(void);


void setup() {
  
//define pins
// pinMode(rightDirectionPin, OUTPUT);
pinMode(rightMotorPin, OUTPUT);

// pinMode(leftDirectionPin, OUTPUT);
pinMode(leftMotorPin, OUTPUT);

}

void loop() {

  goBackwards();

  delay(2000);

  goForward();

  delay(2000);




}




void goForward(void)
{
  digitalWrite(rightMotorPin, HIGH);
  digitalWrite(leftMotorPin, HIGH);
}

void goBackwards(void)
{
  digitalWrite(rightMotorPin, LOW);
  digitalWrite(leftMotorPin, LOW);
}

void turnLeft(void)
{
  digitalWrite(rightMotorPin, HIGH);
  digitalWrite(leftMotorPin, LOW);
}

void turnRight(void)
{
  digitalWrite(rightMotorPin, LOW);
  digitalWrite(leftMotorPin, HIGH);
}

void turnOffMotor(void)
{
  digitalWrite(rightMotorPin, LOW);
  digitalWrite(leftMotorPin, LOW);
}