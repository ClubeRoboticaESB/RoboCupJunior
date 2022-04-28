#include <Arduino.h>
#include <MDriver.h>

MDriver::MDriver(int in1, int in2, int in3, int in4, int pwm1, int pwm2) {
    PIN_IN1 = in1;
    PIN_IN2 = in2;
    PIN_IN3 = in3;
    PIN_IN4 = in4;
    PWM1 = pwm1;
    PWM2 = pwm2;
    pinMode(PIN_IN1, OUTPUT);
    pinMode(PIN_IN2, OUTPUT);
    pinMode(PIN_IN3, OUTPUT);
    pinMode(PIN_IN4, OUTPUT);
}

void MDriver::move(int rightSpeed, int leftSpeed) {
    if (rightSpeed > 100)  rightSpeed = 100;
    if (rightSpeed < -100) rightSpeed = -100;
    if (leftSpeed > 100)  leftSpeed = 100;
    if (leftSpeed < -100) leftSpeed = -100;
    // set speed correctly
    if (rightSpeed > 0) {
        rightSpeed = map(rightSpeed, 0, 100, 0, 255);
        digitalWrite(PIN_IN1, HIGH);
        digitalWrite(PIN_IN2, LOW);
        analogWrite(PWM1, rightSpeed);
    } else if (rightSpeed < 0) {
        rightSpeed = map(rightSpeed, -100, 0, 0, 255);
        digitalWrite(PIN_IN1, LOW);
        digitalWrite(PIN_IN2, HIGH);
        analogWrite(PWM1, rightSpeed);
    }

    if (leftSpeed > 0) {
        leftSpeed = map(leftSpeed, 0, 100, 0, 255);
        digitalWrite(PIN_IN3, HIGH);
        digitalWrite(PIN_IN4, LOW);
        analogWrite(PWM2, leftSpeed);
    } else if (leftSpeed < 0) {
        leftSpeed = map(leftSpeed, -100, 0, 0, 255);
        digitalWrite(PIN_IN3, LOW);
        digitalWrite(PIN_IN4, HIGH);
        analogWrite(PWM2, leftSpeed);
    }
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