#include <Arduino.h> //Arduino functions and definitions
#include "pins.h" // Pins file
class a4988 {
    private:
        /* data */
    public:
        void begin();
        void motor1(int steps);
        void motor2(int steps);
        void motor3(int steps);
        void motor4(int steps);
};

void a4988::begin() {
    pinMode(M1_DIR, OUTPUT);
    pinMode(M1_STEP, OUTPUT);
    pinMode(M2_DIR, OUTPUT);
    pinMode(M2_STEP, OUTPUT);
    pinMode(M3_DIR, OUTPUT);
    pinMode(M3_STEP, OUTPUT);
    pinMode(M4_DIR, OUTPUT);
    pinMode(M4_STEP, OUTPUT);
}

void a4988::motor1(int steps) {
    if (steps > 0) {
        digitalWrite(M1_DIR, LOW);
    } else {
        digitalWrite(M1_DIR, HIGH);
    }
}

void a4988::motor2(int steps) {
    if (steps > 0) {
        digitalWrite(M2_DIR, HIGH);
    } else {
        digitalWrite(M2_DIR, LOW);
    }
}

void a4988::motor3(int steps) {
    if (steps > 0) {
        digitalWrite(M3_DIR, HIGH);
    } else {
        digitalWrite(M3_DIR, LOW);
    }
}

void a4988::motor4(int steps) {
    if (steps > 0) {
        digitalWrite(M4_DIR, HIGH);
    } else {
        digitalWrite(M4_DIR, LOW);
    }
}