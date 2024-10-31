#include <string.h>
#include "motorControl.h"


volatile long echoDuration = 0;
const long distanceThreshold = 10;  // Set your distance threshold in cm
unsigned long startTime = 0;
//const int triggerPin = 10;
const int frontUltraTrigger = 10;
const int backUltraTrigger = 9; 
const int echoPinFront = 2; // Echo pin must be connected to an interrupt-capable pin (like 2 or 3 on an Uno)
const int echoPinBack = 4;
unsigned int activeSensor;

volatile long duration = 0;
volatile long distanceFront, distanceBack = 0;

long measureDistance(unsigned int trigPin, unsigned int echo);
void backAvoidance();
void forwardAvoidance();

void setup() {
  //pin set up for motor
  motorSetUp();

  //set up for the ultra sonic sense
  pinMode(frontUltraTrigger, OUTPUT);
  pinMode(backUltraTrigger, OUTPUT);
  pinMode(echoPinFront, INPUT);
  pinMode(echoPinBack, INPUT);

  Serial.begin(9600);
}

void loop() {

  distanceFront = measureDistance(frontUltraTrigger, echoPinFront);

  if (distanceFront < distanceThreshold)
  {
    motorControl(0);
    //add some avoidance code
  }

  distanceBack = measureDistance(backUltraTrigger, echoPinBack);

  if (distanceBack < distanceThreshold)
  {
    motorControl(0);
    //add some avoidance code
  }



}


// Function to send trigger pulse and wait for echo
long measureDistance(unsigned int trigPin, unsigned int echo) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);  
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echo, HIGH);
  long distance = (duration * 0.034 / 2);  

  return distance;
}






void backAvoidance(void)
{
  //add code here to avoid an object 
  Serial.print("now going forward");
}

void forwardAvoidance(void)
{
  //add code here to avoid objects infront of the buggy
  Serial.print("now going backwards");
}




 