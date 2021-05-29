#ifndef PLAYER_H
#define PLAYER_H    //PREVENT MULTIPLE INCLUDES

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp> 

#include <string>
using namespace std;

#include "Barrel.cpp"
#include "Sandbag.cpp"
#include "Object.h"



class Player:public Object{
    sf::Texture textures[14];
    int state;
    int s;
    int score;
    public:
        Player(){}  //DEFAULT CONTRUCTER
        Player(sf::RenderWindow *window, string textBasePath, int numTextures, Coord pos);
        void setPosition(Coord pos);    
        bool checkCollision(float speed, Barrel *barrels, Sandbag *sandbags, int nb, int ns, int direction);
        void walk(float speed, sf::Keyboard dir, Barrel *barrels, Sandbag *sandbags, int nb, int ns, int who);
        void paint();

        void incrementScore(void);
        int getScore(void){return score;}
        Coord getPosition(){return pos;}
        int getState(){return state;}
};

#endif