#include "Dog.h"

//Constructors
Dog::Dog(String name){
    this->name = name;
    a = &Dog::legArray[0];
    b = &Dog::legArray[1];
    c = &Dog::legArray[2];
    d = &Dog::legArray[3];
}

//Methods
void Dog::standBy(){
    Serial.print("Leg A ==============================================");
    a->setAngles(0, 0, -200);
    a->updatePos();
    delay(50);
    Serial.print("Leg B ==============================================");
    b->setAngles(0, 0, -200);
    b->updatePos();
    delay(50);
    Serial.print("Leg C ==============================================");
    c->setAngles(0, 0, -200);
    c->updatePos();
    delay(50);
    Serial.print("Leg D ==============================================");
    d->setAngles(0,  0, -200);
    d->updatePos();
    delay(50);
}

//Setters
void Dog::setLegPinsAndOrigin(int legPinArray[][3], int legOriginArray[][3]){
    a->setLegCode('A');
    b->setLegCode('B');
    c->setLegCode('C');
    d->setLegCode('D');
    for(int i = 0; i < 4; i++){
        legArray[i].setHumerusPin(legPinArray[i][0]);
        legArray[i].setUlnaPin(legPinArray[i][1]);
        legArray[i].setCarpusPin(legPinArray[i][2]);
        legArray[i].setHumerusOrigin(legOriginArray[i][0]);
        legArray[i].setUlnaOrigin(legOriginArray[i][1]);
        legArray[i].setCarpusOrigin(legOriginArray[i][2]);
        legArray[i].attachServos();
        legArray[i].initServos();
        delay(1000);
    }
}

