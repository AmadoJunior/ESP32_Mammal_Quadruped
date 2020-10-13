#include <ESP32Servo.h>
#include "Dog.h"

bool state = false;

//Leg Pins
int legPinArray[4][3] = {
  {15, 2, 4},
  {16, 17, 5},
  {18, 19, 21},
  {22, 23, 26}
};
//Leg Origins
int legOriginArray[4][3] = {
  {95, 80, 105},
  {70, 95, 65},
  {62, 95, 120},
  {110, 85, 70}
};
//Dog Object
Dog myDog("Spot");

void setup() {
  Serial.begin(9600);
  myDog.setLegPinsAndOrigin(legPinArray, legOriginArray);
  myDog.standBy();
  myDog.stand();
}

void loop() {
  myDog.trot(state);
  state = !state;
  delay(40);
}
