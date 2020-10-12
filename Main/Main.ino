#include <ESP32_Servo.h>
#include "Dog.h"

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
//Dog Object
Dog myDog(legPinArray, legOriginArray);

void setup() {

}

void loop() {

}
