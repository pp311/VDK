//in1, in2 thuoc enA
//tu code them
int enA = 9;
int in1 = 8;
int in2 = 7;
//in3, in4 thuoc enB
int enB = 3;
int in3 = 5;
int in4 = 4;

int LIGHT = 0;
int val = 0;
int LED = 13;
void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
  
void loop() { 
    Serial.println("quay");
    delay(2000);
    forward(255);
    delay(2000);
    backward(255);
}

void forward(int speed){
  analogWrite(enA, speed);
  digitalWrite(in1,HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enB, speed);
  digitalWrite(in3,HIGH);
  digitalWrite(in4, LOW);
}
void backward(int speed){
  analogWrite(enA, speed);
  digitalWrite(in1,LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enB, speed);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}


// void stop(int speed){
//   digitalWrite(in3,LOW);
//   digitalWrite(in4,LOW);
// }
// void turnR(int speed){
//   analogWrite(enA, speed);
//   analogWrite(enA, speed);
//   digitalWrite(in3,LOW);
//   digitalWrite(in4,LOW);
// }
// void turnL(int speed){
//   analogWrite(enA, speed);
//   analogWrite(enA, speed);
//   digitalWrite(in3,HIGH);
//   digitalWrite(in4,LOW);
// }