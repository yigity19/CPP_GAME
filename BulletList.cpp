#include "BulletList.h"

BulletList::BulletList(sf::RenderWindow* window){
    head = NULL;
    this->window = window;
}


void BulletList::add(Coord pos, int state){
    Bullet* new_bullet = new Bullet;
    new_bullet->next = NULL;
    string path = "./images/bullet.png";

    if(state == 4 || state == 5 || state == 11){    //down
        pos.x_inc(30);
        pos.y_inc(100);
        new_bullet->setAngle(270);
    }

    if(state == 0 || state == 7 || state == 8){     //up
        pos.x_inc(60);
        new_bullet->setAngle(90);
    }

    if(state == 2 || state == 9 || state == 10){    //right
        pos.x_inc(90);
        pos.y_inc(80);
        new_bullet->setAngle(0);
    }

    if(state == 6 || state == 12 || state == 13){   //left
        pos.y_inc(40);
        new_bullet->setAngle(180);
    }


    new_bullet->setSpeed(2);

    new_bullet->setRotaion();
    new_bullet->init(window, path , pos);

    if(head == NULL)
        head = new_bullet;

    else{
        Bullet* ptr = head;

        while(ptr->next != NULL)
            ptr = ptr->next;
        
        ptr->next = new_bullet;
    }
}

void BulletList::update(){
    Bullet* ptr = head;

    while (ptr != NULL){
        ptr->paint();
        ptr->move();
        ptr = ptr->next;
    }
}


//CHECKING IF PLAYER IS TO ENTER RADIUS OF THE NONPLAYER OBJECTS
bool is_inside(Coord pos, Coord obj_pos){

    //FORMING A CIRCLE AROUND THE BARREL AND SANDBAGS 
    float left = pow(((pos.getx() /*+  40*/) - (obj_pos.getx() + 30)), 2);  //THE ORIGIN OF PLAYER IS [40,62]
    float right = pow(((pos.gety() /*+ 62*/) - (obj_pos.gety() + 30)), 2);  //ORIGIN OF THE NONPLAYER OBJECTS IS [30,30]
    float sum = sqrt(left + right);
    
    //I GET THE RADIUS OF THE NONPLAYER OBJECTS AS 45
    if(sum <= 45){
        return true;
    }
    return false;
}

//CHECKING POSSIBLE COLLISIONS BASED ON THE NEXT PLACE WHERE USER WANT TO GO 
int BulletList::checkCollision(Player* players, Barrel* barrels, Sandbag* sandbags, int nb, int ns){
    bool check = false;
    Bullet* ptr = head;
    
    while(ptr != NULL){
        for(int i = 0; i < ns; i++){
            if(is_inside(ptr->getPosition(), sandbags[i].getPosition())){
                check = true;
                cout<<"bullet hit sandbag"<<endl;
                break;
            }
        }

        for(int i = 0; i < nb; i++){
            if(is_inside(ptr->getPosition(), barrels[i].getPosition())){
                check = true;
                cout<<"bullet hit barrel"<<endl;
                break;
            }
        }

       
        if(is_inside(ptr->getPosition(), players->getPosition())){
            cout<<"soldier 1 is hit"<<endl;
            check = true;
        }
        
        if(check == true)
            deleteBullet();

        ptr = ptr->next;

    }
    return check;
}

BulletList::~BulletList(){
    Bullet* ptr = head;
    int i = 0;
    while(head != NULL){
        ptr = head;
        head = head->next;
        delete ptr;
        i++;
        cout<<i<<"bullets deleted"<<endl;
    }
}

void BulletList::deleteBullet(){
    Bullet* ptr = head;
    head = head->next;
    cout<<"****Bullet deleted****"<<endl;
    delete ptr;
}