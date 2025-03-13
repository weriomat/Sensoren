#include "Adafruit_SGP40.h"
#include "Adafruit_SHT4x.h"
#include <Arduino.h>
// #include <SensirionI2CScd4x.h>
#include <Wire.h>
#include <ArduinoJson.h>

// own libs
#include <lib.h>
#include <sht.h>
#include <sgp.h>

// Global declaration 


void setup() {
  Wire.begin();
  Serial.begin(115200);

  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  init_sht45();
  // init_scd41();
  init_sgp40();
}

void loop() {
  sht s = read_sht45();
  Serial.print("Temperature: ");
  Serial.print(s.temp);
  Serial.println(" degrees C");
  Serial.print("Humidity: ");
  Serial.print(s.rel_hum);
  Serial.println("% rH");

  sgp sg = read_sgp40(s);

  Serial.print("Measurement: ");
  Serial.println(sg.raw);
  Serial.print("Voc Index: ");
  Serial.println(sg.voc);

  // read_scd41();
  delay(1000);
}
