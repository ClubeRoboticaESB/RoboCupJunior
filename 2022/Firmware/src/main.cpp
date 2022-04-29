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

int line_vtrans = 600, green_square = 20;
int state = 0;
int speed = 55;
void setup() {
    //while (digitalRead(PIN_BUTTON) != HIGH) {
    //    Serial.println("Click to start");
    //}
    Serial.begin(9600);
    rgbSensor2.scale(20);
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
    Serial.println(rgbSensor2.read_green()); //20-40
    Serial.println(lsensor1);
    Serial.println(lsensor2);
    Serial.println(lsensor3);
    Serial.println(lsensor4);
    Serial.println(lsensor5);
    Serial.println();
    Serial.println();
    distSensor1.reset();
    distSensor2.reset();

    if ((rgbSensor1.read_green() > green_square || rgbSensor2.read_green() > green_square ) && ((line.readIR1() > line_vtrans && line.readIR2() > line_vtrans && line.readIR3() > line_vtrans) || (line.readIR3() > line_vtrans && line.readIR4() > line_vtrans && line.readIR5() > line_vtrans))) {
        state = 1;
    }
    if (distSensor1.distance() < 8 && distSensor1.distance() > 2) {
        state = 2;
    }

   switch (state) {
       case 0:
            // First we detect if all of the sensor is on a white space
            // this is so the robot go foward on gaps
            //if (line.readIR1() < line_vtrans && line.readIR2() < line_vtrans && line.readIR3() < line_vtrans && line.readIR4() < line_vtrans &&line.readIR5() < line_vtrans) {
            //    /*driverFront.move(speed, speed);
            //    driverBack.move(speed, speed);*/
            //}

            //// Maintain robot between 1500 - 2500
            //if (line.weighted_average() > 1800 ) {
            //   /* driverFront.move(speed, speed-20);
            //    driverBack.move(speed, speed-20);*/
            //} else if (line.weighted_average() < 2200 ) {
            //    /*driverFront.move(speed-20, speed);
            //    driverBack.move(speed-20, speed);   */             
            //}
            if (line.readIR3() < line_vtrans) {
                Serial.println("Moving Foward");
                driverFront.move(speed, speed);
                driverBack.move(speed, speed);
            } else if (line.readIR1() < line_vtrans) {
                Serial.println("Moving to the right sensor 1");
                driverFront.move(speed-150, speed);
                driverBack.move(speed-150, speed);
            } else if (line.readIR2() < line_vtrans) {
                Serial.println("Moving to the right sensor 2");
                driverFront.move(speed-120, speed);
                driverBack.move(speed-120, speed);
            } else if (line.readIR4() < line_vtrans) {
                Serial.println("Moving to the left sensor 4");
                driverFront.move(speed, speed-120);
                driverBack.move(speed, speed-120);
            } else if (line.readIR5() < line_vtrans) {
                Serial.println("Moving to the left sensor 5");
                driverFront.move(speed, speed-150);
                driverBack.move(speed, speed-150);
            }
            break;
        case 1:
            if (rgbSensor1.read_green() > green_square && rgbSensor2.read_green() > green_square) {
                driverFront.move(speed, speed-120);
                driverBack.move(speed, speed-120);
                delay(100);
                state = 0;
            } else if (rgbSensor2.read_green() > green_square && rgbSensor2.read_green() < green_square) {
                driverFront.move(speed-130, speed);
                driverBack.move(speed-130, speed);
                delay(100);
                state = 0;
            }
        case 2:
            driverFront.move(speed, speed-130);
            driverBack.move(speed, speed-130);
            delay(50);
            state = 0;
            break;
            
    }
}