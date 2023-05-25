const int trigPin = 5; // PWM trigger
const int echoPin = 3; // PWM Output 0-25000US, Every 50US represent 1cm
long duration; // defines variables
int distance;
void setup() {
  pinMode (trigPin, OUTPUT); //Sets the trigPin as an Output
  pinMode (echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); //configure baud rate to 9600 bps
}
void loop() {
  digitalWrite(trigPin, LOW); //Clears the trigPin
  delayMicroseconds(2) ;
  // Sets the trigPin on HIGH state for 10 micro seconds  
  digitalWrite (trigPin, HIGH);
  delayMicroseconds(10) ;
  digitalWrite(trigPin, LOW);

  duration = pulseIn (echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration * 0.034 / 2; // Calculating the distance

  Serial.print("Distance Measure = "); // Prints the distance on the Serial Monitor
  Serial.print(distance);
  Serial.println("cm");
  delay(10);
}