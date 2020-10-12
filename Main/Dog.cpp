#include "Dog.h"
#include <Arduino.h>

//Constructors
Dog::Dog(){}
Dog::Dog(int legPinArray[][3], int originPointArray[][3]){
    for(int i = 0; i < 4; i++){
        legArray[i] = Leg(legPinArray[i][0], legPinArray[i][1], legPinArray[i][2], originPointArray[i][0], originPointArray[i][1], originPointArray[i][2]);
        delay(500);
    }
    a = &Dog::legArray[0];
    b = &Dog::legArray[1];
    c = &Dog::legArray[2];
    d = &Dog::legArray[3];
}