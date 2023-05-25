#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Servo.h>
Servo myservo;
#include <Stepper.h>

ESP8266WebServer webServer(80);
const char* ssid = "Wifi Chua";
const char* pass = "38383838@";
//=========Biến chứa mã HTLM Website==//
const char MainPage[] PROGMEM = R"=====(
  <!DOCTYPE html> 
  <html>
   <head> 
       <title>HOME PAGE</title> 
       <style> 
          body {text-align:center;}
          h1 {color:#003399;}
          a {text-decoration: none;color:#FFFFFF;}
          .bt_on {height:50px; width:100px; margin:10px 0;background-color:#FF6600;border-radius:5px;}
          .bt_off {height:50px; width:100px; margin:10px 0;background-color:#00FF00;border-radius:5px;}
       </style>
       <meta charset="UTF-8">
   </head>
   <body> 
      <h1>ESP8266 Web Server</h1> 
      <div>Trạng thái trên chân D1: </div>
      <div>
        <button class="bt_on"><a href="/onD1">ON</a></button>
        <button class="bt_off"><a href="/offD1">OFF</a></button>
      </div>
      <div>Trạng thái trên chân D2: </div>
      <div>
        <button class="bt_on"><a href="/onD2">ON</a></button>
        <button class="bt_off"><a href="/offD2">OFF</a></button>
      </div>

      <div>Trạng thái động cơ Servo: </div>
      <div>
        <button class="bt_on"><a href="/servo1">Xoay ngược chiều</a></button>
        <button class="bt_off"><a href="/servo2">Xoay cùng chiều</a></button>
      </div>
   </body> 
  </html>
)=====";
//=========================================//
void setup() {
  Serial.begin(9600);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  // pinMode(5,OUTPUT);
  digitalWrite(D1,HIGH);
  digitalWrite(D2,HIGH);
  myservo.attach(D5);
  WiFi.begin(ssid,pass);
  Serial.println("Connecting");
  Serial.println(ssid);
  Serial.println(pass);
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println(WiFi.localIP());

  webServer.on("/",mainpage);
  webServer.on("/onD1",on_D1);
  webServer.on("/offD1",off_D1);
  webServer.on("/onD2",on_D2);
  webServer.on("/offD2",off_D2);

  webServer.on("/servo1",servo1);
  webServer.on("/servo2",servo2);

  webServer.begin();


  WiFi.mode(WIFI_AP_STA);
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("connect");
  Serial.print("ip thu duoc: ");
  Serial.print(WiFi.localIP());
  WiFi.softAP("hahahaha", "22222222");
  Serial.print("\nip phat ra: ");
  Serial.print(WiFi.softAPIP()); 
}
void loop() {
  int val = analogRead(A0);
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s + "Cảm biến ánh sáng: " + val);
  webServer.handleClient();
}
//==========Chương trình con=================//
void mainpage(){
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}
void on_D1(){
  Serial.println("Da bat den 1");
  digitalWrite(D1,LOW);
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}
void off_D1(){
  Serial.println("Da tat den 1");
  digitalWrite(D1,HIGH);
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}
void on_D2(){
  Serial.println("Da bat den 2");
  digitalWrite(D2,LOW);
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}
void off_D2(){
  Serial.println("Da tat den 2");
  digitalWrite(D2,HIGH);
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}

void servo1(){
  Serial.println("Xoay cung chieu");
  myservo.write(180);
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}
void servo2(){
  Serial.println("Xoay nguoc chieu");
  myservo.write(0);
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}