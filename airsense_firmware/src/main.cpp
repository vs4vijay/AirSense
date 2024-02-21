#include <Arduino.h>

#define LED_PIN 2

void blink_led();

void setup()
{
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);

  Serial.println("[+] AirSense is running...");
}

void loop()
{
  blink_led();
}

void blink_led()
{
  digitalWrite(LED_PIN, LOW);
  delay(1000);
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
}