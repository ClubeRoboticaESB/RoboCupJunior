#include <Arduino.h>
#include <Wire.h>
#include <Constants.h>

// Line Follower variables
int LINE_1, LINE_2, LINE_3, LINE_4, LINE_5, LINE_6, LINE_7, LINE_8;

void setup() {
  // put your setup code here, to run once:

  // Start I2C on the STM32 Bluepill
  Wire.begin(8); // Start I2C on address 8
  Wire.onRequest(requestEvent); // Set the onRequest callback
  // no need for onReceive callback because we're not using it


}

void loop() {
  // put your main code here, to run repeatedly:
  LINE_1 = analogRead(LINE_1_PIN);
  LINE_2 = analogRead(LINE_2_PIN);
  LINE_3 = analogRead(LINE_3_PIN);
  LINE_4 = analogRead(LINE_4_PIN);
  LINE_5 = analogRead(LINE_5_PIN);
  LINE_6 = analogRead(LINE_6_PIN);
  LINE_7 = analogRead(LINE_7_PIN);
  LINE_8 = analogRead(LINE_8_PIN);
}

void requestEvent() {
  // Send all the sensor on the Line follower
  Wire.write(LINE_1);
  Wire.write(LINE_2);
  Wire.write(LINE_3);
  Wire.write(LINE_4);
  Wire.write(LINE_5);
  Wire.write(LINE_6);
  Wire.write(LINE_7);
  Wire.write(LINE_8);
}