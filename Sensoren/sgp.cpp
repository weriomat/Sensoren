#include <Wire.h>
#include <cstdint>
#include <sgp.h>

Adafruit_SGP40 sgp40;

void init_sgp40(void) {
  if (!sgp40.begin()) {
    Serial.println("// SGP40 sensor not found :(");
    while (1)
      ;
  }

  Serial.print("// SGP40 serial #");
  Serial.print(sgp40.serialnumber[0], HEX);
  Serial.print(sgp40.serialnumber[1], HEX);
  Serial.println(sgp40.serialnumber[2], HEX);
}

sgp read_sgp40(sht s) {
  uint16_t raw;

  raw = sgp40.measureRaw();
  int32_t voc_index = sgp40.measureVocIndex(s.temp, s.rel_hum);

  return {raw, voc_index};
}
