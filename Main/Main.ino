
#include <ESP32Servo.h>
#include "Dog.h"

double y = -60;

//Leg Pins
int legPinArray[4][3] = {
  {15, 2, 4},
  {16, 17, 5},
  {18, 19, 21},
  {22, 23, 26}
};
//Leg Origins
int legOriginArray[4][3] = {
  {100, 75, 100},
  {60, 105, 65},
  {55, 80, 110},
  {110, 95, 60}
};
//Dog Object+
Dog myDog("Spot");

void setup() {
  Serial.begin(9600);
  myDog.setLegPinsAndOrigin(legPinArray, legOriginArray);
  myDog.standBy();
}

void loop() {
  if(y > 60){
    y = -60;
  }
  myDog.a->setAngles(0, y, -160);
  myDog.b->setAngles(0, y, -160);
  myDog.c->setAngles(0, y, -160);
  myDog.d->setAngles(0, y, -160);
  myDog.a->updatePos();
  myDog.b->updatePos();
  myDog.c->updatePos();
  myDog.d->updatePos();
  y+=2.5;
  delay(50);
}
