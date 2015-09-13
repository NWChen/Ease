#include <Ultrasonic.h>

Ultrasonic pingA(6);
Ultrasonic pingB(7);

void setup() {
  Serial.begin(9600);
}

void loop() {
  long rangeA = pingA.MeasureInCentimeters();
  long rangeB = pingB.MeasureInCentimeters();
  Serial.println(String(rangeA) + ", " + String(rangeB));
  delay(150);
}
