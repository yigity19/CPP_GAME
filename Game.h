#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp> 

#ifndef GAME_H
#define GAME_H

#include "Barrel.cpp"
#include "Sandbag.cpp"
#include "Player.cpp" 
#include "BulletList.cpp"

//GAME CLASS
class Game{
    float speed;
    int numBarrels;
    int numSandbags;
    int width;
    int height;
    sf::RenderWindow* window;
    sf::Texture texture;
    sf::Sprite sprite;
    Barrel *barrels;
    Sandbag *sandbags;
    Player* players;

    BulletList* bullets;
    sf::Text text;
    sf::Font font;
    
    public:
        Game(float speed, int w, int h, int nb, int ns); //CONSTRUCTER
        ~Game(); //DESTRUCTOR
        void drawBackground();
        void update();

};

#endif 