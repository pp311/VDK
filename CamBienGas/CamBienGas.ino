int loa = 11;
int sinval;
int toneval;
int gas = 0; 
void setup() {
  pinMode(13, OUTPUT);
  Serial.begin (9600);
}

void loop() {
  gas = analogRead(A0);
  Serial.println(gas);
  if (gas> 250)
    stereo();
  else 
    noTone(loa);

}
void stereo()
{
  for (int x=0;x<180;x++)
    {
      sinval =(sin(x*(3.1412/180)));
      toneval = 2000+(int(sinval*1000));
      tone(loa,toneval);
      delay(1);
    }
}