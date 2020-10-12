#include <ESP32Servo.h>

Servo myServo1;
Servo myServo2;
Servo myServo3;
Servo myServo4;
Servo myServo5;
Servo myServo6;
Servo myServo7;
Servo myServo8;
Servo myServo9;
Servo myServo10;
Servo myServo11;
Servo myServo12;


void setup() {
  myServo1.attach(15);
  myServo2.attach(2);
  myServo3.attach(4);
  myServo4.attach(16);
  myServo5.attach(17);
  myServo6.attach(5);
  myServo7.attach(18);
  myServo8.attach(19);
  myServo9.attach(21);
  myServo10.attach(22);
  myServo11.attach(23);
  myServo12.attach(26);

  
}

void loop() {
//A
  myServo1.write(100);
  delay(500);
  myServo2.write(75);
  delay(500);
  myServo3.write(100);
  delay(500);
//B
  myServo4.write(60);
  delay(500);
  myServo5.write(105);
  delay(500);
  myServo6.write(65);
  delay(500);
//C
  myServo7.write(55);
  delay(500);
  myServo8.write(80);
  delay(500);
  myServo9.write(110);
  delay(500);
//D
  myServo10.write(110);
  delay(500);
  myServo11.write(95);
  delay(500);
  myServo12.write(60);
  delay(500);
  
}
