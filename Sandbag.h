#ifndef SANDBAG_H
#define SANDBAG_H   //TO PREVENT MULTIPLE INCLUDES

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp> 
#include <string>

#include "Object.cpp"

using namespace std;


class Sandbag:public Object{
    public:
        Sandbag(){}
        Sandbag(sf::RenderWindow *window, string texturePath, Coord pos);
        void paint();
        Coord getPosition();
};

#endif