#ifndef DOG_CLASS_H
#define DOG_CLASS_H

#include "Leg.h"
#include "Coordinates.h"
#include <Arduino.h>
//Enums
enum ZDirection {up, down};
enum YDirection {forward, backward};
enum XDirection {left, right};

//Class
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
    void stand();
    void trot(bool state);
    void updateAllGradual(bool, bool);
    void initTrot();
    //Setters
    void setLegPinsAndOrigin(int[][3], int[][3]);
    //Test Methods
    void moveInZ(ZDirection);
    void moveInY(YDirection);
    void moveInX(XDirection);
};

#endif //DOG_CLASS_H