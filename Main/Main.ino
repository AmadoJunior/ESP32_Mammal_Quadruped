#include <ESP32Servo.h>
#include "Dog.h"
#include "BluetoothSerial.h"

//Check if BT Enabled
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

//Global Vars
bool state = true;
ZDirection zDir;
YDirection yDir;
XDirection xDir;
BluetoothSerial SerialBT;

//Leg Pins
int legPinArray[4][3] = {
  {15, 2, 4},
  {16, 17, 5},
  {18, 19, 21},
  {22, 23, 26}
};
//Leg Origins
int legOriginArray[4][3] = {
  {100, 80+15, 105-(15)},
  {65, 105-15, 65+(15)},
  {58, 85+15, 113-(15)},
  {110, 95-15, 65+(15)}

};
//Dog Object
Dog myDog("Spot");

void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP32Test"); //Device Name
  myDog.setLegPinsAndOrigin(legPinArray, legOriginArray);
  myDog.standBy();
  delay(500);
}

void loop() {
//  if (Serial.available()) {
//    SerialBT.write(Serial.read());
//  }
  if (SerialBT.available()) {
    //Serial.write(SerialBT.read());
    switch(SerialBT.read()){
      case 'w':
        zDir = up;
        myDog.moveInZ(zDir);
        Serial.print("humerusAngle: ");
        Serial.println(myDog.a->getHumerusAngle());
        Serial.println(myDog.c->getHumerusAngle());
        Serial.print("ulnaAngle: ");
        Serial.println(myDog.a->getUlnaAngle());
        Serial.println(myDog.c->getUlnaAngle());
        Serial.print("carpusAngle: ");
        Serial.println(myDog.a->getCarpusAngle());
        Serial.println(myDog.c->getCarpusAngle());
        break;
      case 's':
        zDir = down;
        myDog.moveInZ(zDir);
        Serial.print("humerusAngle: ");
        Serial.println(myDog.a->getHumerusAngle());
        Serial.println(myDog.c->getHumerusAngle());
        Serial.print("ulnaAngle: ");
        Serial.println(myDog.a->getUlnaAngle());
        Serial.println(myDog.c->getUlnaAngle());
        Serial.print("carpusAngle: ");
        Serial.println(myDog.a->getCarpusAngle());
        Serial.println(myDog.c->getCarpusAngle());
        break;
      case 'q':
        yDir = forward;
        myDog.moveInY(yDir);
        Serial.print("humerusAngle: ");
        Serial.println(myDog.a->getHumerusAngle());
        Serial.println(myDog.c->getHumerusAngle());
        Serial.print("ulnaAngle: ");
        Serial.println(myDog.a->getUlnaAngle());
        Serial.println(myDog.c->getUlnaAngle());
        Serial.print("carpusAngle: ");
        Serial.println(myDog.a->getCarpusAngle());
        Serial.println(myDog.c->getCarpusAngle());
        break;
      case 'e':
        yDir = backward;
        myDog.moveInY(yDir);
        Serial.print("humerusAngle: ");
        Serial.println(myDog.a->getHumerusAngle());
        Serial.println(myDog.c->getHumerusAngle());
        Serial.print("ulnaAngle: ");
        Serial.println(myDog.a->getUlnaAngle());
        Serial.println(myDog.c->getUlnaAngle());
        Serial.print("carpusAngle: ");
        Serial.println(myDog.a->getCarpusAngle());
        Serial.println(myDog.c->getCarpusAngle());
    }
  }
}
