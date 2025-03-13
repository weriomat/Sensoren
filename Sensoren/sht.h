#ifndef _SHT_H
#define _SHT_H

#include "Adafruit_SHT4x.h"
#include "Arduino.h"
#include <Adafruit_Sensor.h>
#include <Wire.h>

typedef struct _sht {
  sensors_event_t temp;
  sensors_event_t rel_hum;
} sht;

void init_sht45(void);
sht read_sht45(void);

#endif // _SHT_H
