#ifndef LEG_CLASS_H
#define LEG_CLASS_H

#include "libraries/ESP32Servo-master/src/ESP32_Servo.h"
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
        double humerusLenMm;
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
            Coordinates curCordinates;
            Coordinates desiredCoordinates;

        //Constructor
        Leg();
        Leg(int humerusPin, int ulnaPin, int carpusPin, int humerusOrigin, int ulnaOrigin, int carpusOrigin);

        //Methods
        void initServos();
        void setAngles(double x, double y, double z);
        void updatePos();

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

        //Getters
        double getHumerusLenMm();
        double getUlnaLenMm();
        double setCarpusLenMm();
};

#endif //LEG_CLASS_H