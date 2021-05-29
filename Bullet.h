#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp> 

#include "Object.cpp"

#pragma once

class Bullet:public Object{

    //friend class BulletList;
    float speed;
    int angle;

    public:
        //void init(sf::RenderWindow *window, string texturePath, Coord pos);
        void move(void);
        void setSpeed(float speed){this->speed = speed;}
        Bullet* next;

        Coord getPosition(){return pos;}
        void setAngle(int angle){this->angle = angle;};
        void setRotaion();
};