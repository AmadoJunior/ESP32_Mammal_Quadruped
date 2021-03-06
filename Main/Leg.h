#ifndef LEG_CLASS_H
#define LEG_CLASS_H

#include "libraries/ESP32Servo/src/ESP32Servo.h"
#include "Coordinates.h"

class Leg{
    private:
        char legCode;
        int humerusPin;
        int ulnaPin;
        int carpusPin;
        int humerusOrigin;
        int ulnaOrigin;
        int carpusOrigin;
        double ulnaLenMm;
        double carpusLenMm;
        double humerusAngle;
        double ulnaAngle;
        double carpusAngle;

    public:
        //Public Properties
            //Servos
            Servo humerusServo;
            Servo ulnaServo;
            Servo carpusServo;
            //Coordinates
            Coordinates curCoordinates;
            Coordinates desiredCoordinates;

        //Constructor
        Leg();
        Leg(int humerusPin, int ulnaPin, int carpusPin, int humerusOrigin, int ulnaOrigin, int carpusOrigin);

        //Methods
        void attachServos();
        void initServos();
        void setAngles(double x, double y, double z);
        void updatePos();
        void standBy();

        //Setters
        void setHumerusPin(int);
        void setUlnaPin(int);
        void setCarpusPin(int);
        void setHumerusOrigin(int);
        void setUlnaOrigin(int);
        void setCarpusOrigin(int);
        void setHumerusLenMm(double);
        void setUlnaLenMm(double);
        void setCarpusLenMm(double);
        void setLegCode(char);
        void setDesiredCoordinates(Coordinates);
        bool setCurCoordinateX(double);
        bool setCurCoordinateY(double);
        bool setCurCoordinateZ(double);

        //Getters
        double getHumerusLenMm();
        double getUlnaLenMm();
        double getCarpusLenMm();
        int getHumerusPin();
        int getUlnaPin();
        int getCarpusPin();
        int getHumerusOrigin();
        int getUlnaOrigin();
        int getCarpusOrigin();
        char getLegCode();
        double getHumerusAngle();
        double getUlnaAngle();
        double getCarpusAngle();
};

#endif //LEG_CLASS_H