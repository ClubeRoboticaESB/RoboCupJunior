#include <Arduino.h>
#include <Wire.h>

void requestEvent()
{
  Wire.write("220");
  Wire.write("100");
}

void setup()
{
  Wire.begin(2);                // join i2c bus with address #2
  Wire.onRequest(requestEvent); // register event
}

void loop()
{
  delay(100);
}