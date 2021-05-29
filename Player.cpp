#include "Player.h"
#include <cmath>
#pragma once //TO PREVENT MULTIPLE INCLUDES OF THIS FILE

//CONTRUCTER OF PLAYER CLASS
Player::Player(sf::RenderWindow *window, string textBasePath, int numTextures, Coord pos){
    string path = "";
    this->window = window;
    for(int i = 0; i < numTextures; i++){
        string num = to_string(i); // FUNCTION TO CONVERT INTEGER TO STRING TYPE
        path = textBasePath + "/soldier" + num + ".png";
        textures[i].loadFromFile(path); 
    }

    this->pos = pos; // INITIALIZATON OF POS MEMBER USING THIS POINTER
    //textures[0].loadFromFile(textBasePath + "/soldier0.png" );
    state = 0; s = 0; // INIT OF STATE AND S VARIABLES
    sprite.setPosition(this->pos.getx(), this->pos.gety());
}

//CHECKING IF PLAYER IS TO ENTER RADIUS OF THE NONPLAYER OBJECTS
bool is_inside(Coord& pos, Coord obj_pos){

    //FORMING A CIRCLE AROUND THE BARREL AND SANDBAGS 
    float left = pow(((pos.getx() +  40) - (obj_pos.getx() + 30)), 2);  //THE ORIGIN OF PLAYER IS [40,62]
    float right = pow(((pos.gety() + 62) - (obj_pos.gety() + 30)), 2);  //ORIGIN OF THE NONPLAYER OBJECTS IS [30,30]
    float sum = sqrt(left + right);
    
    //I GET THE RADIUS OF THE NONPLAYER OBJECTS AS 45
    if(sum <= 45){
        return true;
    }
    return false;
}

//CHECKING POSSIBLE COLLISIONS BASED ON THE NEXT PLACE WHERE USER WANT TO GO 
bool Player::checkCollision(float speed, Barrel *barrels, Sandbag *sandbags, int nb, int ns, int direction){
    bool check = false;
    float next_x = pos.getx(); float next_y = pos.gety();
    //GET WHERE PLAYER WANTS TO GO BY ADDING SPEDD TO CURRENT LOCATION 
    if(direction == 3)     //RIGTH
        next_x +=speed;

    if(direction == 4)     //LEFT
        next_x -= speed;

    if(direction == 1)     //UP
        next_y -=  speed;

    if(direction == 2)     //DOWN
        next_y += speed;
    

    Coord next(next_x,next_y);

    for(int i = 0; i < ns; i++){
        if(is_inside(next, sandbags[i].getPosition())){
            check = true;
            break;
        }
    }

    for(int i = 0; i < nb; i++){
        if(is_inside(next, barrels[i].getPosition())){
            check = true;
            break;
        }
    }

    return check;
}

//FUNCTION TO MOVE THE PLAYER ACCORDING TO INPUT FROM KEYBOARD
void Player::walk(float speed, sf::Keyboard dir, Barrel *barrels, Sandbag *sandbags, int nb, int ns, int who){
    if(who == 0){
        int direction = 0; 
        if(dir.isKeyPressed(dir.Up)){
            direction = 1;
            if(!checkCollision(speed, barrels, sandbags, nb, ns,direction))
                pos.y_inc(-speed);
            else
                cout<<"Collision up"<<endl;
            if(state != 0 && state != 7 && state != 8)
                state = 0;
            else   
                if(s == 0){ 
                    state = 7;  //RIGHT FOOT 
                    s = 1;
                }
                else{
                    state = 8;  //LEF FOOT 
                    s = 0;
                }

        }

        else if(dir.isKeyPressed(dir.Down)){
            direction = 2;
            if(!checkCollision(speed, barrels, sandbags, nb, ns,direction))
                pos.y_inc(speed);
            else
                cout<<"Collision down"<<endl;
            if(state != 4 && state != 5 && state != 11)
                state = 4; 
            else
                if(s == 0){ 
                    state = 5;  //RIGHT FOOT 
                    s = 1;
                }
                else{
                    state = 11; //LEFT FOOT
                    s = 0;
                }
        }

        else if(dir.isKeyPressed(dir.Right)){
            direction = 3;
            if(!checkCollision(speed, barrels, sandbags, nb, ns,direction))
                pos.x_inc(speed);

                else
                    cout<<"Collision right"<<endl;
            if(state != 2 && state != 9 && state !=10)
                state = 2;
            else
                if(s == 0){
                    state = 9;  //RIGHT FOOT 
                    s = 1;
                }
                else{
                    state = 10; //LEFT FOOT
                    s = 0;
                }
        }

        else if(dir.isKeyPressed(dir.Left)){
            direction = 4;
            if(!checkCollision(speed, barrels, sandbags, nb, ns,direction))
                pos.x_inc(-speed);

            else
                cout<<"Collision left"<<endl;

            if(state != 6 && state != 12 && state !=13)
                state = 6;

            else
                if(s == 0){
                    state = 12; //RIGHT FOOT 
                    s = 1;
                }
                else{
                    state = 13; //LEFT FOOT
                    s = 0;
                }

        }

    }

    else{
        int direction = 0; 
        if(dir.isKeyPressed(dir.W)){
            direction = 1;
            if(!checkCollision(speed, barrels, sandbags, nb, ns,direction))
                pos.y_inc(-speed);
            else
                cout<<"Collision up"<<endl;
            if(state != 0 && state != 7 && state != 8)
                state = 0;
            else   
                if(s == 0){ 
                    state = 7;  //RIGHT FOOT 
                    s = 1;
                }
                else{
                    state = 8;  //LEF FOOT 
                    s = 0;
                }

        }

        else if(dir.isKeyPressed(dir.S)){
            direction = 2;
            if(!checkCollision(speed, barrels, sandbags, nb, ns,direction))
                pos.y_inc(speed);
            else
                cout<<"Collision down"<<endl;
            if(state != 4 && state != 5 && state != 11)
                state = 4; 
            else
                if(s == 0){ 
                    state = 5;  //RIGHT FOOT 
                    s = 1;
                }
                else{
                    state = 11; //LEFT FOOT
                    s = 0;
                }
        }

        else if(dir.isKeyPressed(dir.D)){
            direction = 3;
            if(!checkCollision(speed, barrels, sandbags, nb, ns,direction))
                pos.x_inc(speed);

                else
                    cout<<"Collision right"<<endl;
            if(state != 2 && state != 9 && state !=10)
                state = 2;
            else
                if(s == 0){
                    state = 9;  //RIGHT FOOT 
                    s = 1;
                }
                else{
                    state = 10; //LEFT FOOT
                    s = 0;
                }
        }

        else if(dir.isKeyPressed(dir.A)){
            direction = 4;
            if(!checkCollision(speed, barrels, sandbags, nb, ns,direction))
                pos.x_inc(-speed);

            else
                cout<<"Collision left"<<endl;

            if(state != 6 && state != 12 && state !=13)
                state = 6;

            else
                if(s == 0){
                    state = 12; //RIGHT FOOT 
                    s = 1;
                }
                else{
                    state = 13; //LEFT FOOT
                    s = 0;
                }

        }
    }
    //CHANGE THE POSITION OF THE SPRITE 
    sprite.setPosition(pos.getx(), pos.gety());
}

//PAINT THE SPRITE
void Player::paint(){
    sprite.setTexture(textures[state]);
    window->draw(sprite);
}

