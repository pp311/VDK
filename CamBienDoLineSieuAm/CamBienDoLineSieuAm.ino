const int trigPin = 5; // PWM trigger
const int echoPin = 3; // PWM Output 0-25000US, Every 50US represent 1cm
long duration; // defines variables
int distance;
int led5 = 13;
int led10 = 12;
int led20 = 11;
int led40 = 10;

#define LINE 2
int indexInput = 2;
int val = 0;
int ledD = 7;
int ledT = 6;


void setup() {
  pinMode (trigPin, OUTPUT); //Sets the trigPin as an Output
  pinMode (echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); //configure baud rate to 9600 bps
  pinMode (led5, OUTPUT);
  pinMode (led10, OUTPUT);
  pinMode (led20, OUTPUT);
  pinMode (led40, OUTPUT);

  pinMode(ledD,OUTPUT);
  pinMode(ledT,OUTPUT);
  pinMode(indexInput,INPUT_PULLUP);
}
void loop() {
  digitalWrite(trigPin, LOW); //Clears the trigPin
  //delayMicroseconds(2) ;
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite (trigPin, HIGH);
  //delayMicroseconds(10) ;
  digitalWrite(trigPin, LOW);
  duration = pulseIn (echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration * 0.034 / 2; // Calculating the distance

  Serial.print("Distance Measure = "); // Prints the distance on the Serial Monitor
  Serial.print(distance);
  Serial.println("cm");

  if(distance <= 5) digitalWrite(led5, HIGH);
  else digitalWrite(led5, LOW);

  if(distance <= 10 && distance > 5) digitalWrite(led10, HIGH);
  else digitalWrite(led10, LOW);
  
  if(distance <= 20 && distance > 10) digitalWrite(led20, HIGH);
  else digitalWrite(led20, LOW);

  if(distance <= 40 && distance > 20) digitalWrite(led40, HIGH);
  else digitalWrite(led40, LOW);


  val = digitalRead(LINE);
  Serial.println(val);
  if(val == 0) {
    digitalWrite(ledT,HIGH);
    digitalWrite(ledD,LOW);
  }
  else{
    digitalWrite(ledT,LOW);
    digitalWrite(ledD,HIGH);
  }
}