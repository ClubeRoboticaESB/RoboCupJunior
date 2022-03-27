#include <Arduino.h>
#include <MDriver.h>

MDriver::MDriver(int in1, int in2, int in3, int in4) {
    PIN_IN1 = in1;
    PIN_IN2 = in2;
    PIN_IN3 = in3;
    PIN_IN4 = in4;
    pinMode(PIN_IN1, OUTPUT);
    pinMode(PIN_IN2, OUTPUT);
    pinMode(PIN_IN3, OUTPUT);
    pinMode(PIN_IN4, OUTPUT);
}

void MDriver::foward_a(int speed) {
    // speed is a pwm value (0-255)
    if (speed > 255) speed = 255;
    if (speed < 0) speed = 0;
    analogWrite(PIN_IN1, speed);
    digitalWrite(PIN_IN2, LOW);
}

void MDriver::reverse_a(int speed) {
    // speed is a pwm value (0-255)
    if (speed > 255) speed = 255;
    if (speed < 0) speed = 0;
    digitalWrite(PIN_IN1, LOW);
    analogWrite(PIN_IN2, speed);
}

void MDriver::foward_b(int speed) {
    // speed is a pwm value (0-255)
    if (speed > 255) speed = 255;
    if (speed < 0) speed = 0;
    analogWrite(PIN_IN3, speed);
    digitalWrite(PIN_IN4, LOW);
}

void MDriver::foward_a(int speed) {
    // speed is a pwm value (0-255)
    if (speed > 255) speed = 255;
    if (speed < 0) speed = 0;
    digitalWrite(PIN_IN3, LOW);
    analogWrite(PIN_IN4, speed);
}

void MDriver::stop_a() {
    digitalWrite(PIN_IN1, LOW);
    digitalWrite(PIN_IN2, LOW);
}

void MDriver::stop_b() {
    digitalWrite(PIN_IN3, LOW);
    digitalWrite(PIN_IN4, LOW);
}

void MDriver::stop() {
    digitalWrite(PIN_IN1, LOW);
    digitalWrite(PIN_IN2, LOW);
    digitalWrite(PIN_IN3, LOW);
    digitalWrite(PIN_IN4, LOW);
}