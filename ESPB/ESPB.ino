#include <esp_now.h>
#include <WiFi.h>

#define BUZZER_PIN 12

typedef struct struct_message {
  int motion;
} struct_message;

struct_message msg;

void OnDataRecv(const esp_now_recv_info_t *recvInfo, const uint8_t *incomingData, int len) {
  memcpy(&msg, incomingData, sizeof(msg));
  Serial.print("Motion: ");
  Serial.println(msg.motion);

  if (msg.motion == 1) {
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }
}


void setup() {
  Serial.begin(115200);
  WiFi.begin();
  pinMode(BUZZER_PIN, OUTPUT);

  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {

}
