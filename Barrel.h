#ifndef BARREL_H
#define BARREL_H    //TO PREVENT MULTIPLE INCLUDES

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp> 
#include <string>


#include "Object.cpp"

using namespace std;

class Barrel:public Object{
    public:
        Barrel(){}  //DEFAULT CONSTRUCTER
        Barrel(sf::RenderWindow *window, string texturePath, Coord pos);
        Coord getPosition();
        void paint();

        int isVisible();
        bool getVisible(void);
        void setVisible(bool visible);
};

#endif