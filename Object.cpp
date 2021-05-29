#include "Object.h"

#pragma once

void Object::init(sf::RenderWindow* window, string texturePath, Coord pos){
    this->window = window;
    this->texturePath = texturePath;
    texture.loadFromFile(texturePath);
    this->pos = pos;
    sprite.setPosition(pos.getx(), pos.gety());
}

void Object::paint(){
    sprite.setTexture(texture);
    window->draw(sprite);
}