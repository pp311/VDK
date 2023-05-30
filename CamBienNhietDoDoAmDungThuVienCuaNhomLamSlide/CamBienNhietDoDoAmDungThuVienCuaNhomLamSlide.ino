#include "dht.h"
#define DHT11_PIN 4
dht DHT;
int LED = 6;
void setup()
{
  Serial.begin(9600);
  Serial.println("DHT TEST PROGRAM ");
  Serial.print("LIBRARY VERSION : ");
  Serial.println(DHT_LIB_VERSION);
  Serial.println();
  Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");
  pinMode(LED,OUTPUT);
}
void loop()
{
  if (DHT.humidity > 60 && DHT.temperature > 30){
        digitalWrite(LED , HIGH);
      }
      else  
          digitalWrite(LED , LOW);
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
  
  delay(1000);
}