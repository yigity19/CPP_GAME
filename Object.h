#include <iostream>
#include <string>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp> 

#include "Coord.cpp"

using namespace std;

#pragma once

class Object{
    protected:
        sf::RenderWindow* window;
        sf::Texture texture;
        sf::Sprite sprite;
        string texturePath;
        Coord pos;
    
    public:
        void init(sf::RenderWindow *window, string texturePath, Coord pos);
        void paint();
};