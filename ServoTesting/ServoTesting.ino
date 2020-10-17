#include <ESP32Servo.h>

Servo myServo;
Servo myServo1;

void setup() {
  myServo.attach(4);
  myServo1.attach(16);
}

void loop() {
  myServo.write(0);
  myServo1.write(0);
}
