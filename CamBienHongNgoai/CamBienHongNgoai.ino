//Cai thu vien DHT11 cua adafruit

int loa = 11;
const int cambien = 2;
const int led = 13;
int sinval;
int toneval;
void setup() {
  pinMode(led,OUTPUT);
  pinMode(cambien,INPUT);
  Serial.begin(9600);
 }

void loop() {
  if(digitalRead(cambien) == HIGH){  
    digitalWrite(led,HIGH);
    stereo();
    Serial.println("anything move in ");
    
  }
  else{
    digitalWrite(led,LOW);
    noTone(loa);
    Serial.println("nothing !");
    } ;
    delay(500);
}
void stereo()
{
  for (int x=0;x<180;x++)
    {
      sinval =(sin(x*(3.1412/180)));
      toneval = 2000+(int(sinval*1000));
      tone(loa,toneval);
      delay(20);
    }
}
