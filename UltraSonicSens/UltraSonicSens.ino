#include <string.h>
#include "motorControl.h"


volatile long echoDuration = 0;
const long distanceThreshold = 10;  // Set your distance threshold in cm
unsigned long startTime = 0;
const int triggerPin = 10;
const int frontUltraTrigger = 10;
const int backUltraTrigger = 14;
const int echoPin = 2; // Echo pin must be connected to an interrupt-capable pin (like 2 or 3 on an Uno)
unsigned int activeSensor;

volatile long duration = 0;
volatile long distance = 0;

void measureDistance(int trigPin);
void echoISR();
void backAvoidance();
void forwardAvoidance();

void setup() {
  //pin set up for motor
  motorSetUp();

  //set up for the ultra sonic sense
  pinMode(frontUltraTrigger, OUTPUT);
  pinMode(backUltraTrigger, OUTPUT);
  pinMode(echoPin, INPUT);

  // Attach an interrupt to the echoPin to detect both RISING and FALLING edges
  attachInterrupt(digitalPinToInterrupt(echoPin), echoISR, CHANGE); // CHANGE triggers both edges

  Serial.begin(9600);
}

void loop() {

  // Measure distance from Sensor 1
  activeSensor = 0; // Set active sensor to 1
  measureDistance(frontUltraTrigger);
  delay(100);

  activeSensor = 1;
  measureDistance(backUltraTrigger);
  delay(100);  //this is needed to get a reading
}


// Function to send trigger pulse and wait for echo
void measureDistance(int trigPin) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
}




void echoISR() {
    // Capture the duration of the echo pulse
    duration = pulseIn(echoPin, HIGH); // Measure the duration of the high pulse
    distance = duration * 0.034 / 2; // Calculate distance in cm


    //THIS MUST LATER BE REMOVED ONLY HERE FOR DEBUGGING
    // Print distance based on which sensor is active
    Serial.print("Distance from Sensor ");
    Serial.print(activeSensor + 1); // Add 1 to match sensor number
    Serial.print(": ");
    Serial.print(distance);
    Serial.println(" cm");

  if (distance < distanceThreshold)
  {
    motorControl(0);
      if (activeSensor == 0)
        {
          forwardAvoidance();
        } else if (activeSensor == 1){
          backAvoidance();
        }
  }
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




 