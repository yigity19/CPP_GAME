#include "Barrel.h"

#pragma once // to prevent multiple includes

Barrel::Barrel(sf::RenderWindow *window, string texturePath, Coord pos){

    this->window = window;
    this->pos = pos;
    texture.loadFromFile(texturePath);
    sprite.setPosition(pos.getx(), pos.gety());
    
}

Coord Barrel::getPosition(){
    return pos;
}

//In order to draw the sprite
void Barrel::paint(){
    sprite.setTexture(texture);
    window->draw(sprite);
}