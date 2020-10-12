#include "Leg.h"
#include "Coordinates.h"
#include "libraries/ESP32Servo-master/src/ESP32_Servo.h"

//Constructors
Leg::Leg(){}
Leg::Leg(int humerusPin, int ulnaPin, int carpusPin, int humerusOrigin, int ulnaOrigin, int carpusOrigin) {
    //Set Pins
    this->humerusPin = humerusPin;
    this->ulnaPin = ulnaPin;
    this->carpusPin = carpusPin;
    //SetOriginPoint
    this->humerusOrigin = humerusOrigin;
    this->ulnaOrigin = ulnaOrigin;
    this->carpusOrigin = carpusOrigin;
    //Initiating Servos
    initServos();
}

//Methods
void Leg::initServos(){
    //Creating Servo Objects
    humerusServo.attach(humerusPin);
    ulnaServo.attach(ulnaPin);
    carpusServo.attach(carpusPin);
    //Setting Origin Angle
    humerusServo.write(humerusOrigin);
    ulnaServo.write(ulnaOrigin);
    carpusServo.write(carpusOrigin);
}

void Leg::setAngles(double x, double y, double z){

}
