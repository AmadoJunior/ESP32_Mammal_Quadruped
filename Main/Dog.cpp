#include "Dog.h"
#include "easingFunctions.h"

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
    a->setAngles(0, 0, -200);
    a->updatePos();
    delay(50);
    b->setAngles(0, 0, -200);
    b->updatePos();
    delay(50);
    c->setAngles(0, 0, -200);
    c->updatePos();
    delay(50);
    d->setAngles(0,  0, -200);
    d->updatePos();
    delay(50);
}

void Dog::stand(){
    Coordinates aC(-15, -20, -182);
    a->setDesiredCoordinates(aC);
    Coordinates bC(15, -20, -182);
    b->setDesiredCoordinates(bC);
    Coordinates cC(15, -70, -182);
    c->setDesiredCoordinates(cC);
    Coordinates dC(-15, -70, -180);
    d->setDesiredCoordinates(dC);
    updateAllGradual(false, false);
}

void Dog::trot(bool state){
  if(state){
    Coordinates aC1(a->curCoordinates.x, a->curCoordinates.y-25, a->curCoordinates.z+25);
    a->setDesiredCoordinates(aC1);
    Coordinates bC1(b->curCoordinates.x, b->curCoordinates.y+25, b->curCoordinates.z+25);
    b->setDesiredCoordinates(bC1);
    Coordinates cC1(c->curCoordinates.x, c->curCoordinates.y+25, c->curCoordinates.z+25);
    c->setDesiredCoordinates(cC1);
    Coordinates dC1(d->curCoordinates.x, d->curCoordinates.y-25, d->curCoordinates.z+25);
    d->setDesiredCoordinates(dC1);
    updateAllGradual(false, true);
    Coordinates aC2(a->curCoordinates.x, a->curCoordinates.y-25, a->curCoordinates.z-25);
    a->setDesiredCoordinates(aC2);
    Coordinates bC2(b->curCoordinates.x, b->curCoordinates.y+25, b->curCoordinates.z-25);
    b->setDesiredCoordinates(bC2);
    Coordinates cC2(c->curCoordinates.x, c->curCoordinates.y+25, c->curCoordinates.z-25);
    c->setDesiredCoordinates(cC2);
    Coordinates dC2(d->curCoordinates.x, d->curCoordinates.y-25, d->curCoordinates.z-25);
    d->setDesiredCoordinates(dC2);
    updateAllGradual(true, false);
  } else {
    Coordinates aC1(a->curCoordinates.x, a->curCoordinates.y+25, a->curCoordinates.z+25);
    a->setDesiredCoordinates(aC1);
    Coordinates bC1(b->curCoordinates.x, b->curCoordinates.y-25, b->curCoordinates.z+25);
    b->setDesiredCoordinates(bC1);
    Coordinates cC1(c->curCoordinates.x, c->curCoordinates.y-25, c->curCoordinates.z+25);
    c->setDesiredCoordinates(cC1);
    Coordinates dC1(d->curCoordinates.x, d->curCoordinates.y+25, d->curCoordinates.z+25);
    d->setDesiredCoordinates(dC1);
    updateAllGradual(false, true);
    Coordinates aC1(a->curCoordinates.x, a->curCoordinates.y+25, a->curCoordinates.z-25);
    a->setDesiredCoordinates(aC1);
    Coordinates bC1(b->curCoordinates.x, b->curCoordinates.y-25, b->curCoordinates.z-25);
    b->setDesiredCoordinates(bC1);
    Coordinates cC1(c->curCoordinates.x, c->curCoordinates.y-25, c->curCoordinates.z-25);
    c->setDesiredCoordinates(cC1);
    Coordinates dC1(d->curCoordinates.x, d->curCoordinates.y+25, d->curCoordinates.z-25);
    d->setDesiredCoordinates(dC1);
    updateAllGradual(true, false);
  }
}

void Dog::updateAllGradual(bool easeIn, bool easeOut){
  float increments = 0.01;
  float curStep = 0.01;
  float (*transition)(float);

  if(easeIn){
    transition = &easeInQuad;
  } else if(easeOut) {
    transtion = &easeOutQuad;
  }

  while(a->curCoordinates.x != a->desiredCoordinates.x ||
        a->curCoordinates.y != a->desiredCoordinates.y ||
        a->curCoordinates.z != a->desiredCoordinates.z ||
        b->curCoordinates.x != b->desiredCoordinates.x ||
        b->curCoordinates.y != b->desiredCoordinates.y ||
        b->curCoordinates.z != b->desiredCoordinates.z ||
        c->curCoordinates.x != c->desiredCoordinates.x ||
        c->curCoordinates.y != c->desiredCoordinates.y ||
        c->curCoordinates.z != c->desiredCoordinates.z || 
        d->curCoordinates.x != d->desiredCoordinates.x ||
        d->curCoordinates.y != d->desiredCoordinates.y ||
        d->curCoordinates.z != d->desiredCoordinates.z
  ){
    //X
      a->curCoordinates.x = lerp(a->curCoordinates.x, a->desiredCoordinates.x, curStep);
      b->curCoordinates.x = lerp(b->curCoordinates.x, b->desiredCoordinates.x, curStep);
      c->curCoordinates.x = lerp(c->curCoordinates.x, c->desiredCoordinates.x, curStep);
      d->curCoordinates.x = lerp(d->curCoordinates.x, d->desiredCoordinates.x, curStep);
    //Y
      a->curCoordinates.y = lerp(a->curCoordinates.y, a->desiredCoordinates.y, curStep);
      b->curCoordinates.y = lerp(b->curCoordinates.y, b->desiredCoordinates.y, curStep);
      c->curCoordinates.y = lerp(c->curCoordinates.y, c->desiredCoordinates.y, curStep);
      d->curCoordinates.y = lerp(d->curCoordinates.y, d->desiredCoordinates.y, curStep);
    //Z
      a->curCoordinates.z = lerp(a->curCoordinates.z, a->desiredCoordinates.z, transition(curStep));
      b->curCoordinates.z = lerp(b->curCoordinates.z, b->desiredCoordinates.z, transition(curStep));
      c->curCoordinates.z = lerp(c->curCoordinates.z, c->desiredCoordinates.z, transition(curStep));
      d->curCoordinates.z = lerp(d->curCoordinates.z, d->desiredCoordinates.z, transition(curStep));
    //Setting Angles and Updating
      a->setAngles(a->curCoordinates.x, a->curCoordinates.y, a->curCoordinates.z);
      b->setAngles(b->curCoordinates.x, b->curCoordinates.y, b->curCoordinates.z);
      c->setAngles(c->curCoordinates.x, c->curCoordinates.y, c->curCoordinates.z);
      d->setAngles(d->curCoordinates.x, d->curCoordinates.y, d->curCoordinates.z);
      c->updatePos();
      b->updatePos();
      a->updatePos();
      d->updatePos();
    //Advancing
      curStep += increments;
      delay(50);
  }
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
        delay(200);
    }
}

