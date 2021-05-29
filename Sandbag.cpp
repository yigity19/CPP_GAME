#include "Sandbag.h"
#pragma once 

//SANDBAG CONSTRUCTER
Sandbag::Sandbag(sf::RenderWindow *window, string texturePath, Coord pos){
    this->window = window;
    texture.loadFromFile(texturePath);
    this->pos = pos;
    sprite.setPosition(pos.getx(), pos.gety());
}

//GETTER FUNC FOR GETTING THE LOCATION
Coord Sandbag::getPosition(){   
    return pos;
}

//PAINT THE SANDBAG
void Sandbag::paint(){
    sprite.setTexture(texture);
    window->draw(sprite);
}

