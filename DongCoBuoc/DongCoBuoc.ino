#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 2, 4, 3, 5);

void setup() {
  // set the speed at 60 rpm:
  // initialize the serial port:
  myStepper.setSpeed(15);
  Serial.begin(9600);
}

void loop() { 
    Serial.println("clockwise");
  myStepper.step(stepsPerRevolution/8);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
   myStepper.step(-stepsPerRevolution/8);
  delay(500);
}