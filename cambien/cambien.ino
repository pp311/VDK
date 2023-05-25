
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

// Khai báo một ESP8266WebServer đối tượng để chạy server trên thiết bị của bạn
ESP8266WebServer server(80);

// Khai báo chân cảm biến của bạn
const int sensorPin = A0;

const char* ssid = "Wf";
const char* pass = "pass";

void setup() {
  // Khởi tạo Serial Monitor để kiểm tra
  Serial.begin(9600);
  
  // Kết nối với WiFi
  WiFi.begin(ssid, pass);

  // Đợi cho kết nối được thiết lập
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  // In địa chỉ IP của ESP8266 trên Serial Monitor
  Serial.println(WiFi.localIP());

  // Đăng ký các xử lý GET và POST cho server
  server.on("/", handleRoot);
  server.on("/read", handleRead);

  // Bắt đầu server
  server.begin();
  Serial.println("Server started");
}

void loop() {
  // Quản lý kết nối với client
  server.handleClient();

  // Lấy thông số từ cảm biến và đưa lên server sau mỗi 5 giây
  delay(5000);
  String json = "{\"temperature\": " + String(analogRead(sensorPin)) + "}";
  server.send(200, "application/json", json);
}

// Xử lý GET request đến trang root ("/")
void handleRoot() {
  // Trả về mã HTML hiển thị thông số từ cảm biến
  String html = "<html><body><h1>ESP8266 Webserver</h1><p>Temperature: " + String(analogRead(sensorPin)) + "</p><script>setTimeout(function() {location.reload();}, 5000);</script></body></html>";
  server.send(200, "text/html", html);
}

// Xử lý GET request đến trang "/read"
void handleRead() {
  // Trả về thông số từ cảm biến dưới dạng JSON
  String json = "{\"temperature\": " + String(analogRead(sensorPin)) + "}";
  server.send(200, "application/json", json);
}
