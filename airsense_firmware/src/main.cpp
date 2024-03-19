#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME680.h>

#define LED_PIN 2
#define BME688_I2C_ADDR 0x77

Adafruit_BME680 bme;
// Adafruit_BME680 bme(BME688_I2C_ADDR, Wire);

void blink_led();
float calculate_aqi(Adafruit_BME680 bme);

void blink_led()
{
  digitalWrite(LED_PIN, LOW);
  delay(1000);
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
}

void setup()
{
  Serial.begin(115200);
  Wire.begin();

  Serial.println("[+] AirSense is running...");

  if (!bme.begin(BME688_I2C_ADDR))
  {
    Serial.println("[-] Could not find a valid BME688 sensor, check wiring!");
    while (1)
      ;
  }
  blink_led();
}

void loop()
{

  // Calculate Air Quality Index (AQI) using a formula
  float aqi = calculate_aqi(bme);
  blink_led();
  Serial.print("[+] Air Quality Index (AQI): ");
  Serial.println(aqi);

  delay(2000);
}

float calculate_aqi(Adafruit_BME680 bme)
{

  float temperature = bme.readTemperature();
  float humidity = bme.readHumidity();
  float pressure = bme.readPressure() / 100.0;
  float gas = bme.readGas() / 1000.0;
  // TODO: Get Gas Resistance value from the sensor
  // float gas_resistance = bme.readGasResistance() / 1000.0;

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" hPa");

  Serial.print("Gas: ");
  Serial.print(gas);
  Serial.println(" KOhms");

  // TODO: Implement AQI calculation based on sensor readings
  // You can use the provided sensor data to calculate the AQI
  // and return the calculated value

  // Example calculation:
  float aqi = temperature + humidity + pressure + gas;
  // float aqi = temperature * humidity * pressure / gas;

  return aqi;
}