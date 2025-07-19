#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  delay(2000);
  WiFi.begin();
  WiFi.mode(WIFI_STA);
  Serial.print("MAC Address: ");
  
  Serial.println(WiFi.macAddress());
}

void loop() {
  // do nothing
}