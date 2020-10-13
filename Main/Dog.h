#ifndef DOG_CLASS_H
#define DOG_CLASS_H

#include "Leg.h"
#include <Arduino.h>

class Dog{
private:
    String name;
    Leg legArray[4];
    
public:
    //Public Vars
    Leg *a;
    Leg *b;
    Leg *c;
    Leg *d;
    //Constructors
    Dog(String);
    //Methods
    void standBy();
    void testY();
    void setLegPinsAndOrigin(int[][3], int[][3]);
};

#endif //DOG_CLASS_H