#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "***";
const char* password = "***";
const char* pc_ip = "192.168.1.3";  // Bilgisayarının yerel IP'si

const int trigPin = 9;
const int echoPin = 10;
bool tetiklendi = false;

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Baglandi!");
}

void loop() {
  Serial.println("--- Yeni Olcum Basliyor ---");
  
  digitalWrite(trigPin, LOW); delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH, 30000);
  float distance = duration * 0.034 / 2;

  Serial.print("Mesafe: ");
  Serial.println(distance);

  if (distance > 50 && !tetiklendi) {
    Serial.println("Kapi acildi! PC'ye haber veriliyor...");

    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      String serverPath = "http://" + String(pc_ip) + ":5001/alert";
      http.begin(serverPath.c_str());
      int httpResponseCode = http.GET();

      if (httpResponseCode > 0) {
        Serial.print("PC Yaniti: ");
        Serial.println(httpResponseCode);
        tetiklendi = true;  
      }
      http.end();
    }
  } else if (distance <= 50) {
    tetiklendi = false;  
  }
  delay(500);
}
