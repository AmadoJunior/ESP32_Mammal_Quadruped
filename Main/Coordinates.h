#ifndef COORDINATES_CLASS_H
#define COORDINATES_CLASS_H

class Coordinates{
    private:
        double x;
        double y;
        double z;
    public:
        //Constructors
        Coordinates();
        Coordinates(double x, double y, double z);

        //Setters
        void setX(double x);
        void setY(double y);
        void setZ(double z);

};

#endif //COORDINATES_CLASS_H