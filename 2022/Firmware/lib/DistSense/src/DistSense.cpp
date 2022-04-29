#include <Arduino.h>
#include <DistSense.h>

DistSense::DistSense(int trigPin, int echoPin) {
    ECHO = echoPin;
    TRIG = trigPin;
    pinMode(ECHO, INPUT);
    pinMode(TRIG, OUTPUT);
}

void DistSense::reset() {
    // Must be called everytime something we need a new measurement
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);
}

int DistSense::distance() {
    long duration = pulseIn(ECHO, HIGH);
    delay(20);
    // Calculating the distance in cm
    int distance = duration * 0.034 / 2;
    return distance;
}