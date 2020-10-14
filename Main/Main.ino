#include <ESP32Servo.h>
#include "Dog.h"

bool state = true;

//Leg Pins
int legPinArray[4][3] = {
  {15, 2, 4},
  {16, 17, 5},
  {18, 19, 21},
  {22, 23, 26}
};
//Leg Origins
int legOriginArray[4][3] = {
  {100, 75, 108},
  {65, 105, 65},
  {58, 80, 113},
  {110, 95, 60}

};
//Dog Object
Dog myDog("Spot");

void setup() {
  Serial.begin(9600);
  myDog.setLegPinsAndOrigin(legPinArray, legOriginArray);
  myDog.standBy();
  myDog.stand();
  myDog.initTrot();
  delay(500);
}

void loop() {
  myDog.trot(state);
  state = !state;
}
