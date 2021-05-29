#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp> 

#include "Bullet.cpp"
#include "Barrel.cpp"
#include "Player.cpp"
#include "Sandbag.cpp"

#pragma once

class BulletList{
    //I added this window pointer access from everywhere and start the bullet from add function
    sf::RenderWindow* window;
    Bullet* head;

    public:
        BulletList(sf::RenderWindow* window);
        void add(Coord pos, int state);
        void update(void);




        //can be reconsidered
        int checkCollision(Player* players, Barrel* barrels, Sandbag* sandbags, int nb, int ns);
        void deleteBullet();
        
        ~BulletList();

};

