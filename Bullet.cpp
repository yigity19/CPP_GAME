#include "Bullet.h"

void Bullet::move(void){
    if(angle == 0){
        pos.x_inc(speed);
    }

    if(angle == 90){
        pos.y_inc(-speed);
    }

    if(angle == 180){
        pos.x_inc(-speed);
    }
    
    if(angle == 270){
        pos.y_inc(speed);
    }

    sprite.setPosition(pos.getx(), pos.gety());
}

void Bullet::setRotaion(){
    if(angle == 0 || angle == 180)
        sprite.setRotation(90);
    
    else
        sprite.setRotation(0);
}