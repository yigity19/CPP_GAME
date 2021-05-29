#include "Game.h"
#pragma once
Game::Game(float speed, int w, int h, int nb, int ns){

	//Initialization of members 
    this->speed = speed;
    width = w;
    height = h;
    numBarrels = nb;
    numSandbags = ns;
    window = new sf::RenderWindow(sf::VideoMode(width, height), "My Game");
    barrels  = new Barrel[nb];
    sandbags = new Sandbag[ns];
	players = new Player[2];
	
	bullets = new BulletList(window);

	float sx = 300; float sy = 300; //Player's first location on the window
	Coord s_pos(sx,sy);
	Coord sol2(sx+100,sy+100);
	
	players[0] = Player(window, "textures",14, s_pos); //Creation of the player
	players[1] = Player(window, "textures",14, sol2);

	float x = 100; float y = 100; //First barrel's location on the window
    for(int i = 0; i < nb; i++){
		Coord pos(x,y);
		y += 100;
        barrels[i] = Barrel(window, "textures/barrel.png" , pos); //Creation of the barrels
    }
	x = 600; y = 100;	//First sandbag's location on the window
    for(int i = 0; i < ns; i++){
		Coord pos(x,y);
		y += 100;
        sandbags[i] = Sandbag(window, "textures/bags.png", pos); //Creation of the sandbags
    }

	
}

//DRAW THE BACKGROUND OF THE GAME
void Game::drawBackground(){

	texture.loadFromFile("textures/grass.png"); //Loading background image to the program as texture

	sprite.setTexture(texture); //Forming sprite

    sprite.setOrigin(sf::Vector2f(width / 2, height / 2)); //set the local origin of the object
	sprite.setScale(sf::Vector2f(0.1f, 0.1f)); //set the scale factors of the object
}

//MAIN LOOP FOR THE GAME
void Game::update(){
	sf::Keyboard dir;
	sf::Event event;
	
	int num = 0;
	bool space_pressed = false;
	bool enter_pressed = false;
	//Trial
	
	//window->setKeyRepeatEnabled(false); 

    while(window->isOpen()){
        window->clear(sf::Color::Black); //Clear the entire target with a single color (To give the window an initial color to show something)

		//draw the whole background with grass
		int i = 0.5*texture.getSize().y / 2;
		while(i<1.1*width){
			int j = 0.5*texture.getSize().x / 2; 
			while(j<1.1*height){					
				sprite.setScale(sf::Vector2f(0.5f, 0.5f));
				sprite.setPosition(i, j);
				window->draw(sprite);
				j+=0.5*texture.getSize().x/2;
			}
		i+=0.5*texture.getSize().y/2;
		}

		//draw sandbags
		for(int i=0;i<numSandbags;i++){
			sandbags[i].paint();
		}
		//draw barrels
		for(int i = 0; i < numBarrels; i++){
			barrels[i].paint();
        }
		//draw the player
		players[0].paint();
		players[1].paint();

		bullets->update();


		//Getting keyboard actions
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				players[0].walk(speed, dir, barrels, sandbags, numBarrels, numSandbags, 0);
				players[1].walk(speed, dir, barrels, sandbags, numBarrels, numSandbags, 1);
			}

			if (event.type == sf::Event::Closed) //If window is closed terminate the program
				window->close();

			if(dir.isKeyPressed(dir.Space)){
				space_pressed = true;
			}

    		if (space_pressed){
				bullets->add(players[1].getPosition(), players[1].getState());
				bullets->checkCollision(&players[0], barrels, sandbags, numBarrels, numSandbags);
				num++;
				space_pressed = false;
			}
			
			if(dir.isKeyPressed(dir.Return)){
				enter_pressed = true;
			}

    		if (enter_pressed){		
				bullets->add(players[0].getPosition(), players[0].getState());
				bullets->checkCollision(&players[1], barrels, sandbags, numBarrels, numSandbags);
				num++;
				enter_pressed = false;
			}

		}     
		window->display(); 
    }
	cout<<"NO OF BULLETS "<<num<<endl;
}

// DESTRUCTER FUNCTION TO DELETE ALL ALLOCATED MEMORY
Game::~Game(){
	delete window;
	delete [] players;
	delete [] barrels;
	delete [] sandbags;
	delete bullets;
}