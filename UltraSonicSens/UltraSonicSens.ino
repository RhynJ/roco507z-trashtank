const int triggerPin = 10;
const int echoPin = 2; // Echo pin must be connected to an interrupt-capable pin (like 2 or 3 on an Uno)

//right motor pins
const int rightDirectionPin = 12;
const int rightMotorPin = 3; 
//left motor pins
const int leftDirectionPin = 13;
const int leftMotorPin = 11;

volatile long startTime = 0;
volatile long echoDuration = 0;
const long distanceThreshold = 10;  // Set your distance threshold in cm

//motor functions this can be moved to a header file to clear up the main
void rightForward(void);
void leftForward(void);
void rightBackwards();
void leftBackwards();
void goForward (void);
void goBackwards(void);
void turnLeft(void);
void turnRight(void);
void turnOffMotor(void);
void slightLeft(void);
void slightRight(void);

void motorControl(unsigned int);


void setup() {
  //pin set up for motor
  pinMode(rightDirectionPin, OUTPUT);
  pinMode(rightMotorPin, OUTPUT);
  pinMode(leftDirectionPin, OUTPUT);
  pinMode(leftMotorPin, OUTPUT);

  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Attach an interrupt to the echoPin to detect both RISING and FALLING edges
  attachInterrupt(digitalPinToInterrupt(echoPin), echoISR, CHANGE); // CHANGE triggers both edges
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
  long distance = (echoDuration * 0.0343) / 2;
  
  // Check if the measured distance exceeds or falls below the threshold
  if (distance < distanceThreshold) {
    // Trigger an interrupt-like function when threshold is crossed
    distanceThresholdBroken();
  }
  
  Serial.print("Distance: ");
  Serial.println(distance);
  
  delay(500); // Small delay between measurements
}

// This function simulates an "interrupt" for when the threshold is broken
void distanceThresholdBroken() {
  // Actions to take when the distance threshold is crossed
  Serial.println("Threshold crossed! Taking action...");
  // You can add other actions here, like turning on a buzzer or LED
}

void echoISR() {
  // Check if the pin state is HIGH or LOW
  if (digitalRead(echoPin) == HIGH) {
    // The echo pin just went HIGH, start timing
    startTime = micros();
  } else {
    // The echo pin just went LOW, calculate the duration
    echoDuration = micros() - startTime;
  }
}

//0 = stop, 1 = forward, 2 = reverse, 3 = left, 4 = right, 5 = slight left, 6 = slight right 
void motorControl(int control)
{
  // Use a switch-case structure to handle different motor controls
  switch(control)
  {
    case 0:
      // Stop the motor
      turnOffMotor();
      break;

    case 1:
      // Move forward
      goForward();
      break;

    case 2:
      // Move in reverse
      goBackwards();
      break;

    case 3:
      // Turn left
      turnLeft();
      break;

    case 4:
      // Turn right
      turnRight();
      break;

    case 5:
      // Slight left
      slightLeft();
      break;

    case 6:
      // Slight right
      slightRight();
      break;

    default:
      // If an invalid control is passed, stop the motor as a safe action
      turnOffMotor();
      break;
  }
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


void slightRight()
{
    rightForwards();
    digitalWrite(leftMotorPin, LOW);
}

void slightLeft()
{
    leftForward();
    DigitalWrite(rightMotorPin, LOW);
}

 