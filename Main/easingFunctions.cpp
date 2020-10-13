#include "easingFunctions.h"
#include <math.h>

float easeOutQuad(float x){
    return 1 - (1 - x) * (1 - x);
}

float easeInQuad(float x){
    return x * x;
}

float easeOutSine(float x){
return sin((x * M_PI) / 2);
}

float easeInSine(float x){
return 1 - cos((x * M_PI) / 2);
}

float lerp(float a, float b, float f){
    return (a * (1.0 - f)) + (b * f);
}