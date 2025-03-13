#include <cstdint>
#include <sht.h>

Adafruit_SHT4x sht4 = Adafruit_SHT4x();

void init_sht45(void) {
  Serial.println("// Adafruit SHT4x test");
  if (!sht4.begin()) {
    Serial.println("// Couldn't find SHT4x");
    while (1)
      delay(1);
  }
  Serial.println("// Found SHT4x sensor");
  Serial.print("// Serial number 0x");
  Serial.println(sht4.readSerial(), HEX);

  // You can have 3 different precisions, higher precision takes longer
  sht4.setPrecision(SHT4X_HIGH_PRECISION);
  switch (sht4.getPrecision()) {
  case SHT4X_HIGH_PRECISION:
    Serial.println("// High precision");
    break;
  case SHT4X_MED_PRECISION:
    Serial.println("// Med precision");
    break;
  case SHT4X_LOW_PRECISION:
    Serial.println("// Low precision");
    break;
  }

  // You can have 6 different heater settings
  // higher heat and longer times uses more power
  // and reads will take longer too!
  sht4.setHeater(SHT4X_MED_HEATER_1S);
  // sht4.setHeater(SHT4X_NO_HEATER);
  switch (sht4.getHeater()) {
  case SHT4X_NO_HEATER:
    Serial.println("// No heater");
    break;
  case SHT4X_HIGH_HEATER_1S:
    Serial.println("// High heat for 1 second");
    break;
  case SHT4X_HIGH_HEATER_100MS:
    Serial.println("// High heat for 0.1 second");
    break;
  case SHT4X_MED_HEATER_1S:
    Serial.println("// Medium heat for 1 second");
    break;
  case SHT4X_MED_HEATER_100MS:
    Serial.println("// Medium heat for 0.1 second");
    break;
  case SHT4X_LOW_HEATER_1S:
    Serial.println("// Low heat for 1 second");
    break;
  case SHT4X_LOW_HEATER_100MS:
    Serial.println("// Low heat for 0.1 second");
    break;
  }
}

sht read_sht45(void) {
  Serial.print("// Reading SHT45");
  sensors_event_t humidity, temp;

  uint32_t start = millis();
  sht4.getEvent(&humidity,
                &temp); // populate temp and humidity objects with fresh

  uint32_t end = millis();

  Serial.print("// Reading took: ");
  Serial.print(end - start);
  Serial.print("ms");

  sht ret = {
      .temp = temp.temperature,
      .rel_hum = humidity.relative_humidity,
  };
  return ret;
}
