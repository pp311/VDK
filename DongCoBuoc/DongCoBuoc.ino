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
  // step one revolution  in one direction:
  for(int i=7;i<13;i++)
  {digitalWrite(i,HIGH);
  delay(300);}
  // Serial.println("clockwise");
  // myStepper.step(stepsPerRevolution/8);
  // delay(500);

  // // step one revolution in the other direction:
  // Serial.println("counterclockwise");
  //  myStepper.step(-stepsPerRevolution/8);
  //delay(500);
}