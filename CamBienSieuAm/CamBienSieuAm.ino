const int trigPin = 10;
const int echoPin = 9;
int val = 0;
unsigned long duration;
int distance;
int LED = 13;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);s
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  if (distance < 20) digitalWrite(LED, HIGH);
  else digitalWrite(LED, LOW);
  Serial.print("Distance Measured= ");
  Serial.print(distance);
  Serial.println("cm");
  delay(100);  
}