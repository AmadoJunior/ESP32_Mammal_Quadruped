#ifndef DOG_CLASS_H
#define DOG_CLASS_H

#include "Leg.h"

class Dog{
private:
    Leg legArray[4];
    Leg *a;
    Leg *b;
    Leg *c;
    Leg *d;
public:
    Dog();
    Dog(int legPinArray[][3], int originPointArray[][3]);
};

#endif //DOG_CLASS_H