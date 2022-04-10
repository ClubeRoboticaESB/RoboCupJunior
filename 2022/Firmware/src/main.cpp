#include <Arduino.h>
#include <tcs3200.h>
#include <MDriver.h>
#include <DistSense.h>
#include <LineSense.h>
#include "pins.h"

tcs3200 rgbSensor1(CS1_S0,CS1_S1,CS1_S2,CS1_S3,CS1_OUTPUT);
tcs3200 rgbSensor2(CS2_S0,CS2_S1,CS2_S2,CS2_S3,CS2_OUTPUT);

MDriver driverFront(IN1A,IN2A,IN3A,IN4A);
MDriver driverBack(IN1B,IN2B,IN3B,IN4B);

DistSense distSensor1(DIST_TRIG1, DIST_ECHO1);
DistSense distSensor2(DIST_TRIG2, DIST_ECHO2);

LineSense line(IR1, IR2, IR3, IR4, IR5);

int line_calib, green1_calib, green2_calib;

int state = 0;
int speed = 100;
void setup() {
    while (digitalRead(PIN_BUTTON) != HIGH) {
        Serial.println("Click to start");
    }

}

void loop() {
   /*
   * 0 - Line Follow (Green Squares not detected)
   * 1 - Turn (RGB Sensors)
   * 2 - Go Around Obstacle
   * 3 - Victims
   */
   switch (state) {
       case 0:
            // First we detect if all of the sensor is on a white space
            // this is so the robot go foward on gaps
            if (line.readIR1() < line_calib && line.readIR2() < line_calib && line.readIR3() < line_calib && line.readIR4() < line_calib &&line.readIR5() < line_calib) {
                driverFront.move(speed, speed);
                driverBack.move(speed, speed);
            }

            // Skip this cycle if a green square was detected
            if (rgbSensor1.read_green() > green1_calib || rgbSensor2.read_green() > green2_calib) {
                state = 1;
                break; // Dont continue the cycle
            } 

            // Maintain robot between 1500 - 2500
            if (line.weighted_average() > 1500 ) {
                driverFront.move(speed, speed-20);
                driverBack.move(speed, speed-20);
            } else if (line.weighted_average() < 2500 ) {
                driverFront.move(speed-20, speed);
                driverBack.move(speed-20, speed);                
            }
            break;
        case 2:
            if (rgbSensor1.read_green() > green1_calib && rgbSensor2.read_green() > green2_calib) {
                driverFront.move(speed, speed-20);
                driverBack.move(speed, speed-20);
                delay(100);
            
            }
            

   }
}