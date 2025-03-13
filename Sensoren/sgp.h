#ifndef _SGP_H
#define _SGP_H

#include "Adafruit_SGP40.h"
#include "Arduino.h"
#include <cstdint>
#include <sht.h>

typedef struct _sgp {
  uint16_t raw;
  int32_t voc;
} sgp;

void init_sgp40(void);
sgp read_sgp40(sht);

#endif // _SGP_H
