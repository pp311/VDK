#include "dht.h"
#define DHT11_PIN 4
dht DHT;
int enA = 9;
int enB = 3;
int in3 = 5;
int in4 = 4;
int LIGHT = 0;
int val = 0;
void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  Serial.println("DHT TEST PROGRAM ");
  Serial.print("LIBRARY VERSION : ");
  Serial.println(DHT_LIB_VERSION);
  Serial.println();
  Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");
  pinMode(LED,OUTPUT);
}
  
void loop() { 
  for(int i = 0 ;i <255;i++){
      int chk;
  Serial.print("DHT11, \t");
  chk = DHT.read11(DHT11_PIN);
  switch(chk)
  {
    case DHTLIB_OK: 
      Serial.print("OK,\t");
      break;
    case DHTLIB_ERROR_CHECKSUM: 
      Serial.print("Checksum error,\t");
      break;
    case DHTLIB_ERROR_TIMEOUT: 
      Serial.print("Time out error,\t");
      break;
    default:
      Serial.print("Unknown error,\t");
      break;
  }
  Serial.print(DHT.humidity, 1);
  Serial.print(",\t\t");
  Serial.println(DHT.temperature, 1);
    if (DHT.humidity > 60 && DHT.temperature > 30)
      backward(i);
    else  
      forward(i);
    delay(100);
  }
}
void forward(int speed){
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  digitalWrite(in3,HIGH);
  digitalWrite(in4, LOW);
}
void backward(int speed){
  analogWrite(enA, speed);
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