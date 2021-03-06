#include <Arduino.h>
#include <LineSense.h>

LineSense::LineSense(int ir1, int ir2, int ir3, int ir4, int ir5) {
    PIN_IR1 = ir1;
    PIN_IR2 = ir2;
    PIN_IR3 = ir3;
    PIN_IR4 = ir4;
    PIN_IR5 = ir5;
}

int LineSense::readIR1() {
    int value = analogRead(PIN_IR1);
    return value;
}

int LineSense::readIR2() {
    int value = analogRead(PIN_IR2);
    return value;
}

int LineSense::readIR3() {
    int value = analogRead(PIN_IR3);
    return value;
}

int LineSense::readIR4() {
    int value = analogRead(PIN_IR4);
    return value;
}

int LineSense::readIR5() {
    int value = analogRead(PIN_IR5);
    return value;
}

int LineSense::weighted_average() {
    int ir1 = readIR1();
    int ir2 = readIR2();
    int ir3 = readIR3();
    int ir4 = readIR4();
    int ir5 = readIR5();
    int weighted_average = (0 * ir1 + 1000 * ir2 + 2000 * ir3 + 3000 * ir4 +4000 * ir5) / (ir1 + ir2 + ir3 + ir4 + ir5);
    return weighted_average;
}