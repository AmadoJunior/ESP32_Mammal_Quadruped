#include "Coordinates.h"

//Constructors
Coordinates::Coordinates(){}
Coordinates::Coordinates(double x, double y, double z) : x(x), y(y), z(z) {}

//Setters
void Coordinates::setX(double x){
    this->x = x;
}

void Coordinates::setY(double y){
    this->y = y;
}

void Coordinates::setZ(double z){
    this->z = z;
}

//Getters
double Coordinates::getX(){
    return x;
}

double Coordinates::getY(){
    return y;
}

double Coordinates::getZ(){
    return z;
}
