#include <iostream>
#include <cmath>
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

int main(){
    float p = 0.1;
    float a = 1;
    float b = 11;
    float temp;
    while(a != b){
        std::cout << temp << std::endl;
        temp =  lerp(a, b, easeInQuad(p)) - a;
        a = lerp(a, b, easeInQuad(p));
        p += 0.1;
    }
    return 0;
}