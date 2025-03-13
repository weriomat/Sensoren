// #include <SensirionI2CScd4x.h>
// #include <Wire.h>
// #include <scd.h>

// // SensirionI2CScd4x scd4x;

// void init_scd41(void) {
//   uint16_t error;
//   char errorMessage[256];

//   scd4x.begin(Wire);

//   // stop potentially previously started measurement
//   error = scd4x.stopPeriodicMeasurement();
//   if (error) {
//     Serial.print("Error trying to execute stopPeriodicMeasurement(): ");
//     errorToString(error, errorMessage, 256);
//     Serial.println(errorMessage);
//   }

//   uint16_t serial0;
//   uint16_t serial1;
//   uint16_t serial2;
//   error = scd4x.getSerialNumber(serial0, serial1, serial2);
//   if (error) {
//     Serial.print("Error trying to execute getSerialNumber(): ");
//     errorToString(error, errorMessage, 256);
//     Serial.println(errorMessage);
//   } else {
//     printSerialNumber(serial0, serial1, serial2);
//   }

//   // Start Measurement
//   error = scd4x.startPeriodicMeasurement();
//   if (error) {
//     Serial.print("Error trying to execute startPeriodicMeasurement(): ");
//     errorToString(error, errorMessage, 256);
//     Serial.println(errorMessage);
//   }

//   Serial.println("Waiting for first measurement... (5 sec)");
// }
// void read_scd41(void) {
//   uint16_t error;
//   char errorMessage[256];

//   delay(100);

//   // Read Measurement
//   uint16_t co2 = 0;
//   float temperature = 0.0f;
//   float humidity1 = 0.0f;
//   bool isDataReady = false;
//   error = scd4x.getDataReadyFlag(isDataReady);
//   if (error) {
//     Serial.print("Error trying to execute getDataReadyFlag(): ");
//     errorToString(error, errorMessage, 256);
//     Serial.println(errorMessage);
//     return;
//   }
//   if (!isDataReady) {
//     return;
//   }
//   error = scd4x.readMeasurement(co2, temperature, humidity1);
//   if (error) {
//     Serial.print("Error trying to execute readMeasurement(): ");
//     errorToString(error, errorMessage, 256);
//     Serial.println(errorMessage);
//   } else if (co2 == 0) {
//     Serial.println("Invalid sample detected, skipping.");
//   } else {
//     Serial.print("Co2:");
//     Serial.print(co2);
//     Serial.print("\t");
//     Serial.print("Temperature:");
//     Serial.print(temperature);
//     Serial.print("\t");
//     Serial.print("Humidity:");
//     Serial.println(humidity1);
//   }
// }
