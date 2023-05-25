int LED =13;
int LIGHT = 0;
int val = 0;
void setup() {
  // put your setup code here, to run once:  
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:  
  val = analogRead(LIGHT);
  Serial.println(val);
  if(val < 900)
  digitalWrite(LED ,LOW );
  else digitalWrite(LED, HIGH); 
  delay(100);
}