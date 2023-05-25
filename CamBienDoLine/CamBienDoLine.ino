#define LINE 2
int indexInput = 2;
int val = 0;
void setup()
{
  pinMode(indexInput,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  val = digitalRead(LINE);
  Serial.println(val);
  delay(100);
}