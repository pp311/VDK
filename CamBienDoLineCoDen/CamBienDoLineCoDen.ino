#define LINE 2
int indexInput = 2;
int val = 0;
int ledD = 7;
int ledT = 6;
void setup()
{
  pinMode(ledD,OUTPUT);
  pinMode(ledT,OUTPUT);
  pinMode(indexInput,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
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