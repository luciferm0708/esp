#include <esp_now.h>
#include <WiFi.h>

#define MINUTE 60000
#define SECOND 1000

int ledPin = 14;       
int pirPin = 32;

int lastPirVal = LOW;
int pirVal;

unsigned long myTime;
char printBuffer[128];

uint8_t broadcastAddress[] = {0xC8, 0xF0, 0x9E, 0x7B, 0xD1, 0xC8};

typedef struct struct_message {
  int motion;
} struct_message;

struct_message msg;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
}

void loop() {
  pirVal = digitalRead(pirPin);

  if (pirVal == HIGH) {
    digitalWrite(ledPin, HIGH);

    if (lastPirVal == LOW) {
      myTime = millis();
      sprintf(printBuffer, "%lu min %lu sec: Motion detected!", myTime / MINUTE, (myTime % MINUTE) / SECOND);
      Serial.println(printBuffer);

      msg.motion = 1;
      esp_now_send(broadcastAddress, (uint8_t *)&msg, sizeof(msg));
      lastPirVal = HIGH;
    }

  } else {
    digitalWrite(ledPin, LOW);

    if (lastPirVal == HIGH) {
      myTime = millis();
      sprintf(printBuffer, "%lu min %lu sec: Motion ended!", myTime / MINUTE, (myTime % MINUTE) / SECOND);
      Serial.println(printBuffer);

      msg.motion = 0;
      esp_now_send(broadcastAddress, (uint8_t *)&msg, sizeof(msg));
      lastPirVal = LOW;
    }
  }

  delay(100);
}
