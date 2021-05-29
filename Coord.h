#ifndef COORD_H
#define COORD_H
#include <iostream>

class Coord{
    float x;
    float y;
    public:
        Coord();
        Coord(float,float);
        float getx(){return x;} //GETTER FUNCTIONS
        float gety(){return y;}
        void x_inc(float num){x+=num;}  //SETTER FUNCTIONS 
        void y_inc(float num){y+=num;}
};

#endif
