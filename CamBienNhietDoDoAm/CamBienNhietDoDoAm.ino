//DHT11: 
// DAT -> D4
// VCC -> 5V
// GND -> GND

#include <DHT.h>
#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
int LED = 13;
void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  Serial.println(F("DHT11 test!"));
  dht.begin();
}
float humidity = 0;
float temperature = 0;
void loop()
{
   delay(3000);
  humidity = dht.readHumidity();
  delay(30); // xoa cai ni la loi @@
  temperature = dht.readTemperature();

  if (humidity > 77 && temperature > 33){
    digitalWrite(LED , HIGH);
  }
  else  
    digitalWrite(LED , LOW);
  
  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.print(F("%  Temperature: "));
  Serial.print(temperature);
  Serial.print(F("°C "));
  Serial.println();
}