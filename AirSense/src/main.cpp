#include <Arduino.h>

#define LED_BUILTIN 2

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  
  Serial.println("AirSense is running...");
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}