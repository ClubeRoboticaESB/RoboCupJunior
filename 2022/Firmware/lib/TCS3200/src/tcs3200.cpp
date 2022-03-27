#include <Arduino.h>
#include <tcs3200.h>

tcs3200::tcs3200(int s0, int s1, int s2, int s3, int output) {
    PIN_S0 = s0;
    PIN_S1 = s1;
    PIN_S2 = s2;
    PIN_S3 = s3;
    PIN_OUTPUT = output;
    pinMode(PIN_S0, OUTPUT);
    pinMode(PIN_S1, OUTPUT);
    pinMode(PIN_S2, OUTPUT);
    pinMode(PIN_S3, OUTPUT);
    pinMode(PIN_OUTPUT, INPUT);

    // Default scale is 20%
    digitalWrite(PIN_S0, HIGH);
	digitalWrite(PIN_S1, LOW);
}

void tcs3200::scale(int scale) {
    switch (scale)
    {
    case 0: //Off
        digitalWrite(PIN_S0, LOW);
        digitalWrite(PIN_S1, LOW);
        break;

    case 2: // 2%
        digitalWrite(PIN_S0, LOW);
        digitalWrite(PIN_S1, HIGH);
        break;

    case 20: // 20%
        digitalWrite(PIN_S0, HIGH);
        digitalWrite(PIN_S1, LOW);
        break;

    case 100: // 100%
        digitalWrite(PIN_S0, HIGH);
        digitalWrite(PIN_S1, HIGH);
        break;

    default: // Default is 20%
        digitalWrite(PIN_S0, HIGH);
        digitalWrite(PIN_S1, LOW);
        break;
    }
}

int tcs3200::read_red() {
    digitalWrite(PIN_S2, LOW);
	digitalWrite(PIN_S3, LOW);
	unsigned long duration;

	duration = pulseIn(PIN_OUTPUT, LOW);
	//Serial.print("Red: ");
  	//Serial.println(1000 / duration);
	if (duration != 0) {
		return 1000 / duration; // Reads and returns the frequency of selected color
	} else {
		return 0;
	}
}

int tcs3200::read_green() {
    digitalWrite(PIN_S2, HIGH);
	digitalWrite(PIN_S3, HIGH);
	unsigned long duration;

	duration = pulseIn(PIN_OUTPUT, LOW);
	//Serial.print("Red: ");
  	//Serial.println(1000 / duration);
	if (duration != 0) {
		return 1000 / duration; // Reads and returns the frequency of selected color
	} else {
		return 0;
	}
}

int tcs3200::read_blue() {
    digitalWrite(PIN_S2, LOW);
	digitalWrite(PIN_S3, HIGH);
	unsigned long duration;

	duration = pulseIn(PIN_OUTPUT, LOW);
	//Serial.print("Red: ");
  	//Serial.println(1000 / duration);
	if (duration != 0) {
		return 1000 / duration; // Reads and returns the frequency of selected color
	} else {
		return 0;
	}
}

int tcs3200::read_white() {
    digitalWrite(PIN_S2, HIGH);
	digitalWrite(PIN_S3, LOW);
	unsigned long duration;

	duration = pulseIn(PIN_OUTPUT, LOW);
	//Serial.print("Red: ");
  	//Serial.println(1000 / duration);
	if (duration != 0) {
		return 1000 / duration; // Reads and returns the frequency of selected color
	} else {
		return 0;
	}
}