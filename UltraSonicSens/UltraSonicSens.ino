#include <string.h>
#include "motorControl.h"


volatile long echoDuration = 0;
const long distanceThreshold = 10;  // Set your distance threshold in cm
unsigned long startTime = 0;
const int triggerPin = 10;
const int frontUltra = 10;
const int backUltra = 14;
const int echoPin = 2; // Echo pin must be connected to an interrupt-capable pin (like 2 or 3 on an Uno)



void setup() {
  //pin set up for motor
  motorSetUp();

  //set up for the ultra sonic sense
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // Attach an interrupt to the echoPin to detect both RISING and FALLING edges
  attachInterrupt(digitalPinToInterrupt(echoPin), echoISR, CHANGE); // CHANGE triggers both edges

  Serial.begin(9600);
}

void loop() {

  // Send a 10us pulse to the trigger pin to initiate the measurement
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  // Wait for the measurement to complete (the interrupt will update echoDuration)
  delay(100);

  // Calculate the distance in cm (duration in microseconds, speed of sound ~343m/s)
  float distance = (echoDuration * 0.0343) / 2;

  if (distance < distanceThreshold)
  {
    distanceThresholdBroken();
  }
  

}

// This function simulates an "interrupt" for when the threshold is broken
void distanceThresholdBroken() {
  // Actions to take when the distance threshold is crossed
  Serial.println("Threshold crossed! Taking action...");
  // You can add other actions here, like turning on a buzzer or LED
  motorControl(0);

  //add decision code here to decide what to do this can be done using the currect direction to back away from a wall

}

void echoISR() {
  // Check if the pin state is HIGH or LOW
  if (digitalRead(echoPin) == HIGH) {
    // The echo pin just went HIGH, start timing
    startTime = micros();
  }
  else {
    // The echo pin just went LOW, calculate the duration
    echoDuration = micros() - startTime;
  }
}





 