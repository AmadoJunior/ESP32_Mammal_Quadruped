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
    updateAllGradual(false, false, false, false);
}

void Dog::trot(bool state){
        Coordinates aC1(a->curCoordinates.x, a->curCoordinates.y-50, a->curCoordinates.z);
        a->setDesiredCoordinates(aC1);
        Coordinates bC1(b->curCoordinates.x, b->curCoordinates.y+50, b->curCoordinates.z);
        b->setDesiredCoordinates(bC1);
        Coordinates cC1(c->curCoordinates.x, c->curCoordinates.y+50, c->curCoordinates.z);
        c->setDesiredCoordinates(cC1);
        Coordinates dC1(d->curCoordinates.x, d->curCoordinates.y-50, d->curCoordinates.z);
        d->setDesiredCoordinates(dC1);
        updateAllGradual(false, true, true, false);
        Coordinates aC2(a->curCoordinates.x, a->curCoordinates.y+50, a->curCoordinates.z);
        a->setDesiredCoordinates(aC2);
        Coordinates bC2(b->curCoordinates.x, b->curCoordinates.y-50, b->curCoordinates.z);
        b->setDesiredCoordinates(bC2);
        Coordinates cC2(c->curCoordinates.x, c->curCoordinates.y-50, c->curCoordinates.z);
        c->setDesiredCoordinates(cC2);
        Coordinates dC2(d->curCoordinates.x, d->curCoordinates.y+50, d->curCoordinates.z);
        d->setDesiredCoordinates(dC2);
        updateAllGradual(true, false, false, true);
}

void Dog::updateAllGradual(bool liftA, bool liftB, bool liftC, bool liftD){
   if(liftA){
     a->curCoordinates.z += 30;
     a->setAngles(a->curCoordinates.x, a->curCoordinates.y, a->curCoordinates.z);
   }
   if(liftB){
     b->curCoordinates.z += 30;
     b->setAngles(b->curCoordinates.x, b->curCoordinates.y, b->curCoordinates.z);
   }
   if(liftC){
     c->curCoordinates.z += 30;
     c->setAngles(c->curCoordinates.x, c->curCoordinates.y, c->curCoordinates.z);
   }
   if(liftD){
     d->curCoordinates.z += 30;
     d->setAngles(d->curCoordinates.x, d->curCoordinates.y, d->curCoordinates.z);
   }
  a->updatePos();
  b->updatePos();
  c->updatePos();
  d->updatePos();
  delay(15); 

   while(a->curCoordinates.x != a->desiredCoordinates.x ||
        a->curCoordinates.y != a->desiredCoordinates.y ||
        b->curCoordinates.x != b->desiredCoordinates.x ||
        b->curCoordinates.y != b->desiredCoordinates.y ||
        c->curCoordinates.x != c->desiredCoordinates.x ||
        c->curCoordinates.y != c->desiredCoordinates.y || 
        d->curCoordinates.x != d->desiredCoordinates.x ||
        d->curCoordinates.y != d->desiredCoordinates.y 
        ){
          //X
          (a->curCoordinates.x != a->desiredCoordinates.x) ? 
            a->setCurCoordinateX(a->curCoordinates.x > a->desiredCoordinates.x ? a->curCoordinates.x-1: a->curCoordinates.x+1) : true;
          (b->curCoordinates.x != b->desiredCoordinates.x) ?  
            b->setCurCoordinateX(b->curCoordinates.x > b->desiredCoordinates.x ? b->curCoordinates.x-1: b->curCoordinates.x+1) : true;
          (c->curCoordinates.x != c->desiredCoordinates.x) ? 
            c->setCurCoordinateX(c->curCoordinates.x > c->desiredCoordinates.x ? c->curCoordinates.x-1: c->curCoordinates.x+1) : true;
          (d->curCoordinates.x != d->desiredCoordinates.x) ? 
            d->setCurCoordinateX(d->curCoordinates.x > d->desiredCoordinates.x ? d->curCoordinates.x-1: d->curCoordinates.x+1) : true;
          //Y
          (a->curCoordinates.y != a->desiredCoordinates.y) ? 
            a->setCurCoordinateY(a->curCoordinates.y > a->desiredCoordinates.y ? a->curCoordinates.y-1: a->curCoordinates.y+1) : true;
          (b->curCoordinates.y != b->desiredCoordinates.y) ?  
            b->setCurCoordinateY(b->curCoordinates.y > b->desiredCoordinates.y ? b->curCoordinates.y-1: b->curCoordinates.y+1) : true;
          (c->curCoordinates.y != c->desiredCoordinates.y) ? 
            c->setCurCoordinateY(c->curCoordinates.y > c->desiredCoordinates.y ? c->curCoordinates.y-1: c->curCoordinates.y+1) : true;
          (d->curCoordinates.y != d->desiredCoordinates.y) ? 
            d->setCurCoordinateY(d->curCoordinates.y > d->desiredCoordinates.y ? d->curCoordinates.y-1: d->curCoordinates.y+1) : true;
          //Z
          /*
           (a->curCoordinates.z != a->desiredCoordinates.z) ? 
             a->setCurCoordinateZ(a->curCoordinates.z > a->desiredCoordinates.z ? a->curCoordinates.z-1: a->curCoordinates.z+1) : true;
           (b->curCoordinates.z != b->desiredCoordinates.z) ?  
             b->setCurCoordinateZ(b->curCoordinates.z > b->desiredCoordinates.z ? b->curCoordinates.z-1: b->curCoordinates.z+1) : true;
           (c->curCoordinates.z != c->desiredCoordinates.z) ? 
             c->setCurCoordinateZ(c->curCoordinates.z > c->desiredCoordinates.z ? c->curCoordinates.z-1: c->curCoordinates.z+1) : true;
           (d->curCoordinates.z != d->desiredCoordinates.z) ? 
             d->setCurCoordinateZ(d->curCoordinates.z > d->desiredCoordinates.z ? d->curCoordinates.z-1: d->curCoordinates.z+1) : true;
          */
          //Setting Angles and Updating
          a->setAngles(a->curCoordinates.x, a->curCoordinates.y, a->curCoordinates.z);
          b->setAngles(b->curCoordinates.x, b->curCoordinates.y, b->curCoordinates.z);
          c->setAngles(c->curCoordinates.x, c->curCoordinates.y, c->curCoordinates.z);
          d->setAngles(d->curCoordinates.x, d->curCoordinates.y, d->curCoordinates.z);
          c->updatePos();
          b->updatePos();
          a->updatePos();
          d->updatePos();
          delay(5);
        }
       if(liftA){
        a->curCoordinates.z -= 30;
        a->setAngles(a->curCoordinates.x, a->curCoordinates.y, a->curCoordinates.z);
      }
      if(liftB){
        b->curCoordinates.z -= 30;
        b->setAngles(b->curCoordinates.x, b->curCoordinates.y, b->curCoordinates.z);
      }
      if(liftC){
        c->curCoordinates.z -= 30;
        c->setAngles(c->curCoordinates.x, c->curCoordinates.y, c->curCoordinates.z);
      }
      if(liftD){
        d->curCoordinates.z -= 30;
        d->setAngles(d->curCoordinates.x, d->curCoordinates.y, d->curCoordinates.z);
      }
      a->updatePos();
      b->updatePos();
      c->updatePos();
      d->updatePos();
      delay(15); 
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

