#include "Leg.h"
#include "Coordinates.h"
#include <math.h>
#include <Arduino.h>

//Constructors
Leg::Leg(){
    this->ulnaLenMm = sqrt(sq(110) + sq(15));
    this->carpusLenMm = 120;
}
Leg::Leg(int humerusPin, int ulnaPin, int carpusPin, int humerusOrigin_, int ulnaOrigin_, int carpusOrigin_) : 
humerusPin(humerusPin), ulnaPin(ulnaPin), carpusPin(carpusPin), humerusOrigin(humerusOrigin_), ulnaOrigin(ulnaOrigin_), carpusOrigin(carpusOrigin_){
    //Length of Limbs
    this->ulnaLenMm = sqrt(sq(110) + sq(15));
    this->carpusLenMm = 120;
}

//Methods
void Leg::attachServos(){
    humerusServo.attach(humerusPin);
    ulnaServo.attach(ulnaPin);
    carpusServo.attach(carpusPin);
}
void Leg::initServos(){
    //Setting Origin Angle
    humerusServo.write(getHumerusOrigin());
    ulnaServo.write(getUlnaOrigin());
    carpusServo.write(getCarpusOrigin());
    //Initial Angles
    humerusAngle = humerusServo.read();
    ulnaAngle = ulnaServo.read();
    carpusAngle = carpusServo.read();
    //Testing
    // Serial.print("Leg Code: ");
    // Serial.println(getLegCode());
    // Serial.println("Humerus");
    // Serial.println(humerusPin);
    // Serial.println(humerusServo.read());
    // Serial.println();
    // Serial.println("Ulna");
    // Serial.println(ulnaPin);
    // Serial.println(ulnaServo.read());
    // Serial.println();
    // Serial.println("Carpus");
    // Serial.println(carpusPin);
    // Serial.println(carpusServo.read());
    // Serial.println();
}

void Leg::setAngles(double x, double y, double z){
    //Temp Init
    double w, alpha, beta, gamma, q1, q2, hyp, humerusAngleR, temp;
    
    //Updating Current Coordinates
    curCoordinates.setX(x);
    curCoordinates.setY(y);
    curCoordinates.setZ(z);

    //Finding Hypothenus && Humerus Angle - Use x && z ===================
    w = sqrt(pow(z, 2) + pow(x, 2));
    // Serial.println("Hypothenus");
    // Serial.println(w);
    // Serial.println();
    humerusAngleR = atan2(z,x);
    //Converting to Degrees
    humerusAngle = humerusAngleR * 57296 / 1000;
    // Serial.println();
    // Serial.println("humerusAngle");
    // Serial.println(humerusAngle);
    
    //Setting humerusAngle - (-180) => (-1) 
    temp = (90 + humerusAngle) * -1;
    if(x < 0){ //Go Left from Origin
        humerusAngle = humerusOrigin + temp;
    } else { //Go Right from Origin
        humerusAngle = humerusOrigin + temp;
    }

    //Finding Angle of Ulna & Carpus =====================================
    double newY = w * -1;
    double newX = y;

    //Hypothenus
    hyp = sqrt(pow(newX, 2) + pow(newY, 2));
    //Checking Limits
    if(hyp > getCarpusLenMm() + getUlnaLenMm()){
        return;
    }
    //Alpha
    alpha = pow(ulnaLenMm, 2) + pow(carpusLenMm, 2) - pow(newX, 2) - pow(newY, 2);
    alpha = alpha / (2 * ulnaLenMm * carpusLenMm);
    alpha = acos(alpha);
    alpha = alpha * 57296 / 1000;
    // Serial.println();
    // Serial.println("Alpha");
    // Serial.println(alpha);

    //Q2
    q2 = 180 - alpha;
     if(legCode == 'A'){
        Serial.println();
        Serial.println("q2");
        Serial.println(q2);

    }

    //Q2 to Rad
    q2 = q2 * 1000 / 57296;

    //Beta
    beta = carpusLenMm * sin(q2);
    beta = beta / (ulnaLenMm + carpusLenMm * cos(q2));
    beta = atan(beta);
    beta = beta * 57296 / 1000;
    // Serial.println();
    // Serial.println("Beta");
    // Serial.println(beta);

    //Gamma
    gamma = atan(newY/newX);
    gamma = gamma * 57296 / 1000;
    // Serial.println();
    // Serial.println("Gamma");
    // Serial.println(gamma);

    //Q1
    q1 = gamma - beta;

    //Converting Q2 Back to Degrees
    q2 = q2 * 57296 / 1000;
    if(legCode == 'A'){
        Serial.println();
        Serial.println("q1");
        Serial.println(q1);
    }
    

    //Setting Ulna & Carpus ===========================================
    if(legCode == 'A'){
        //A
        if(q1 > 0){ //Forward from Origin
            ulnaAngle = (double)ulnaOrigin + (90 - q1);
        } else { //Backward from Origin
            ulnaAngle = (double)ulnaOrigin - (90 + q1);
        }
        carpusAngle = (double)carpusOrigin - q2;
    } else if(legCode == 'B'){
        if(q1 > 0){ //Forward from Origin
            ulnaAngle = (double)ulnaOrigin - (90 - q1);
        } else { //Backward from Origin
            ulnaAngle = (double)ulnaOrigin + (90 + q1);
        }
        carpusAngle = (double)carpusOrigin + q2;
    } else if(legCode == 'C'){
        if(q1 > 0){ //Forward from Origin
            ulnaAngle = (double)ulnaOrigin + (90 - q1);
        } else { //Backward from Origin
            ulnaAngle = (double)ulnaOrigin - (90 + q1);
        }
        carpusAngle = (double)carpusOrigin - q2;
    } else if(legCode == 'D'){
        if(q1 > 0){ //Forward from Origin
            ulnaAngle = (double)ulnaOrigin - (90 - q1);
        } else { //Backward from Origin
            ulnaAngle = (double)ulnaOrigin + (90 + q1);
        }
        carpusAngle = (double)carpusOrigin + q2;
    }
    // Serial.println();
    // Serial.println("ulnaAngle");
    // Serial.println(ulnaAngle);
    // Serial.println();
    // Serial.println("carpusAngle");
    // Serial.println(carpusAngle);
}

void Leg::updatePos(){
    if(humerusAngle )
    humerusServo.write(humerusAngle);
    ulnaServo.write((int)ulnaAngle);
    carpusServo.write((int) carpusAngle);
}

//Setters
void Leg::setLegCode(char c){
    this->legCode = c;
}

void Leg::setHumerusPin(int pin){
    this->humerusPin = pin;
}

void Leg::setUlnaPin(int pin){
    this->ulnaPin = pin;
}

void Leg::setCarpusPin(int pin){
    this->carpusPin = pin;
}

void Leg::setHumerusOrigin(int origin){
    this->humerusOrigin = origin;
}

void Leg::setUlnaOrigin(int origin){
    this->ulnaOrigin = origin;
}

void Leg::setCarpusOrigin(int origin){
    this->carpusOrigin = origin;
}

void Leg::setDesiredCoordinates(Coordinates desired){
    desiredCoordinates.setX(desired.getX());
    desiredCoordinates.setY(desired.getY());
    desiredCoordinates.setZ(desired.getZ());
}

bool Leg::setCurCoordinateX(double x){
    curCoordinates.setX(x);
    return false;
}
bool Leg::setCurCoordinateY(double y){
    curCoordinates.setY(y);
    return false;
}
bool Leg::setCurCoordinateZ(double z){
    curCoordinates.setZ(z);
    return false;
}

//Getters
int Leg::getHumerusPin(){
    return humerusPin;
}
int Leg::getUlnaPin(){
    return ulnaPin;
}
int Leg::getCarpusPin(){
    return carpusPin;
}
int Leg::getHumerusOrigin(){
    return humerusOrigin;
}
int Leg::getUlnaOrigin(){
    return ulnaOrigin;
}
int Leg::getCarpusOrigin(){
    return carpusOrigin;
}
char Leg::getLegCode(){
    return legCode;
}

double Leg::getHumerusAngle(){
    return humerusAngle;
}

double Leg::getUlnaAngle(){
    return ulnaAngle;
}

double Leg::getCarpusAngle(){
    return carpusAngle;
}

double Leg::getUlnaLenMm(){
    return ulnaLenMm;
}
double Leg::getCarpusLenMm(){
    return carpusLenMm;
}

