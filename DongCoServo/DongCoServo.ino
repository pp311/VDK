#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int val = 200;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  if (val == 200)
    val = 1000;
  else
    val = 200;
  val = map(val, 0, 1023, 0, 180);     // scale it for use with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(2000);                           // waits for the servo to get there
}
