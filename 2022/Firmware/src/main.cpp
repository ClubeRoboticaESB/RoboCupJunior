#include <Arduino.h>
#include <tcs3200.h>
#include <MDriver.h>
#include "pins.h"

tcs3200 rgbSensor1(CS1_S0,CS1_S1,CS1_S2,CS1_S3,CS1_OUTPUT);
MDriver driver();

void setup() {
  rgbSensor1.scale(20);

}

void loop() {

}