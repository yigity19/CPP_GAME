#include <iostream>
#include "Game.cpp"


int main()
{	
	float speed = 10; //Num of pixels moved by player at 1 step
	int width = 800; int height = 600; //Window dimensions
	int nb = 5; //num of barrels
	int ns = 5; //num of sandbags

	Game game(speed,width, height, nb, ns); //Game constructer
	game.drawBackground(); //Function to draw background
	game.update();	//Main loop for the game

	return 0;
}
