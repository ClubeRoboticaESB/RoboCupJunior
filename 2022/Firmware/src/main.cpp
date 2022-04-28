#include <Arduino.h>
#include <tcs3200.h>
#include <MDriver.h>
#include <DistSense.h>
#include <LineSense.h>
#include "pins.h"

tcs3200 rgbSensor1(CS1_S0,CS1_S1,CS1_S2,CS1_S3,CS1_OUTPUT);
tcs3200 rgbSensor2(CS2_S0,CS2_S1,CS2_S2,CS2_S3,CS2_OUTPUT);

MDriver driverFront(IN3B,IN4B,IN3A,IN4A, M4_PWM, M2_PWM);
MDriver driverBack(IN1B,IN2B,IN1A,IN2A, M3_PWM, M1_PWM);

DistSense distSensor1(DIST_TRIG1, DIST_ECHO1); //Front sensor
DistSense distSensor2(DIST_TRIG2, DIST_ECHO2);

LineSense line(IR1, IR2, IR3, IR4, IR5);

int line_calib = 500, green1_calib, green2_calib;
int state = 0;
int speed = 100;
void setup() {
    //while (digitalRead(PIN_BUTTON) != HIGH) {
    //    Serial.println("Click to start");
    //}
    Serial.begin(9600);
    rgbSensor1.scale(20);
    delay(1000);
}

void loop() {
   /*
   * 0 - Line Follow (Green Squares not detected)
   * 1 - Turn (RGB Sensors)
   * 2 - Go Around Obstacle
   * 3 - Victims
   */
    int lsensor1 = line.readIR1();
    int lsensor2 = line.readIR2();
    int lsensor3 = line.readIR3();
    int lsensor4 = line.readIR4();
    int lsensor5 = line.readIR5();
    distSensor1.reset();
    Serial.println(distSensor1.distance());
    Serial.println(lsensor2);
    Serial.println(lsensor3);
    Serial.println(lsensor4);
    Serial.println(lsensor5);
    Serial.println();
    Serial.println();
    distSensor1.reset();
    distSensor2.reset();
    
    /*if ((rgbSensor1.read_green() > green1_calib || rgbSensor2.read_green() > green2_calib ) && ((line.readIR1() > line_calib && line.readIR2() > line_calib && line.readIR3() > line_calib) || (line.readIR3() > line_calib && line.readIR4() > line_calib && line.readIR5() > line_calib))) {
        state = 1;
    }
    if (distSensor1.distance() < 12) {
        state = 2;
    }*/

   switch (state) {
       case 0:
            // First we detect if all of the sensor is on a white space
            // this is so the robot go foward on gaps
            if (line.readIR1() < line_calib && line.readIR2() < line_calib && line.readIR3() < line_calib && line.readIR4() < line_calib &&line.readIR5() < line_calib) {
                /*driverFront.move(speed, speed);
                driverBack.move(speed, speed);*/
            }

            //// Maintain robot between 1500 - 2500
            //if (line.weighted_average() > 1800 ) {
            //   /* driverFront.move(speed, speed-20);
            //    driverBack.move(speed, speed-20);*/
            //} else if (line.weighted_average() < 2200 ) {
            //    /*driverFront.move(speed-20, speed);
            //    driverBack.move(speed-20, speed);   */             
            //}
            if (line.readIR3() < line_calib) {
                Serial.println("Moving Foward");
                driverFront.move(speed, speed);
                driverBack.move(speed, speed);
            } else if (line.readIR1() < line_calib) {
                Serial.println("Moving to the right sensor 1");
                driverFront.move(speed-70, speed);
                driverBack.move(speed-70, speed);
            } else if (line.readIR2() < line_calib) {
                Serial.println("Moving to the right sensor 2");
                driverFront.move(speed-50, speed);
                driverBack.move(speed-50, speed);
            } else if (line.readIR4() < line_calib) {
                Serial.println("Moving to the left sensor 4");
                driverFront.move(speed, speed-50);
                driverBack.move(speed, speed-50);
            } else if (line.readIR5() < line_calib) {
                Serial.println("Moving to the left sensor 5");
                driverFront.move(speed, speed-70);
                driverBack.move(speed, speed-70);
            }
            break;
        case 2:
            if (rgbSensor1.read_green() > green1_calib && rgbSensor2.read_green() > green2_calib) {
                driverFront.move(speed, speed-20);
                driverBack.move(speed, speed-20);
                delay(100);
                state = 0;
            } else if (rgbSensor2.read_green() > green1_calib && rgbSensor2.read_green() < green2_calib) {
                driverFront.move(speed-20, speed);
                driverBack.move(speed-20, speed);
                delay(100);
                state = 0;
            }
        //case 3:
            
    }
}