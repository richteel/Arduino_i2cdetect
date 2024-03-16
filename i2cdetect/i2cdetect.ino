/*
  This I2C Scan project was created to work with Earle F. Philhower, III's
  Raspberry Pi Pico core and is similar to the Raspberry Pi command, i2cdetect.
  pi@raspberrypi ~ $ sudo i2cdetect -y 0

  The Raspberry Pi Pico supports I2C on the following pins
  ===================================
  | IC2 Bus | SDA GPIOs | SCL GPIOs |
  ===================================
  |  I2C0   |   GPIO0   |   GPIO1   |
  |  Wire   |   GPIO4 * |   GPIO5 * |
  |         |   GPIO8   |   GPIO9   |
  |         |   GPI12   |   GPI13   |
  |         |   GPI16   |   GPI17   |
  |         |   GPI20   |   GPI21   |
  -----------------------------------
  |  I2C1   |   GPIO2   |   GPIO3   |
  |  Wire1  |   GPIO6   |   GPIO7   |
  |         |   GPI10   |   GPI11   |
  |         |   GPI14   |   GPI15   |
  |         |   GPI18   |   GPI19   |
  |         |   GPI26   |   GPI27   |
  -----------------------------------

  ---- SAMPLE OUTPUT ----
    I2C Bus Scan
      0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
  00:                         -- -- -- -- -- -- -- --
  10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
  20: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
  30: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
  40: -- -- -- -- -- -- -- -- -- -- -- -- -- 4d -- --
  50: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
  60: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
  70: -- -- -- -- -- -- -- --                      
  Done.

  The above example shows that the slave address 0x4d was found.

  NOTE: Change #define statements for SDA, SCL, and WIRE for your setup.

  SOURCE: https://github.com/richteel/Arduino_i2cdetect
  https://teelsys.com
*/

#include <Wire.h>

// GPIO Numbers for the I2C Pins
// I2C0 Example on Raspberry Pi Pico
// #define SDA 16
// #define SCL 17
// #define WIRE Wire

// I2C1 Example on Raspberry Pi Pico
#define SDA 2
#define SCL 3
#define WIRE Wire1

void setup() {
  Serial.begin(115200);

  while (!Serial) {
    delay(1000);
  }

  Serial.println("\nStarting");
  Serial.println("");

  WIRE.setSDA(SDA);
  WIRE.setSCL(SCL);
  WIRE.begin();
}

void loop() {
  byte error, addr;
  int nDevices;

  Serial.printf("\nI2C Bus Scan\n");
  Serial.printf("     0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F\n");
  nDevices = 0;
  for (addr = 0; addr < 127; addr++) {
    if (addr % 16 == 0) {
      Serial.printf("%02x: ", addr);
    }

    if (addr < 0x08 or addr > 0x77) {
      Serial.print("  ");
    } else {

      WIRE.beginTransmission(addr);
      error = WIRE.endTransmission();

      if (error == 0) {
        Serial.printf("%02x", addr);
        nDevices++;
      } else {
        Serial.print("--");
      }
    }

    Serial.printf(addr % 16 == 15 ? "\n" : " ");
  }

  if (nDevices == 0) {
    Serial.println("\nNo I2C Devices Found.\n");
  } else {
    Serial.println("\nDone.\n");
  }
  delay(5000);
}