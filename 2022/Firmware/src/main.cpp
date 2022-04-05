#include <Arduino.h>
#include <tcs3200.h>
#include <MDriver.h>
#include <DistSense.h>
#include <LineSense.h>
#include "pins.h"

tcs3200 rgbSensor1(CS1_S0,CS1_S1,CS1_S2,CS1_S3,CS1_OUTPUT);
tcs3200 rgbSensor2(CS2_S0,CS2_S1,CS2_S2,CS2_S3,CS2_OUTPUT);

MDriver driver(IN1A,IN2A,IN3A,IN4A);
MDriver driver(IN1B,IN2B,IN3B,IN4B);

DistSense distSensor1(DIST_TRIG1, DIST_ECHO1);
DistSense distSensor2(DIST_TRIG2, DIST_ECHO2);

LineSense line(IR1, IR2, IR3, IR4, IR5);

int line_calib, green1_calib, green2_calib;

void setup() {
    while (digitalRead(PIN_BUTTON) != HIGH) {
        Serial.println("Click to start calibration");
    }
    do {
        Serial.println("Click to calibrate the line");
        line_calib = line.readIR3();
        Serial.println("Line Calibration: " + line_calib);
    } while (!line_calib);
    do {
        Serial.println("Click to calibrate the RGB Sensors");
        green1_calib = rgbSensor1.read_green();
        green2_calib = rgbSensor2.read_green();
        Serial.println("Green 1 Calibration: " + green1_calib);
        Serial.println("Green 2 Calibration: " + green1_calib);
    } while (!green1_calib && !green2_calib);

    
}

void loop() {

}