//SFML-2.5.1
#include "Game.h"
#include <iostream>

using namespace sf;

int main()
{
	//init engine
	Game game;

	Clock clock;

	//game loop

	while (game.getWindowIsOpen())
	{
		Time dt = clock.restart();
		// Make a decimal fraction from the delta time
		float dtAsSeconds = dt.asSeconds();

		//handle input
		game.pollEvents();

		//update
		game.update(dtAsSeconds);

		//render
		game.render();


	}
	
	return 0;
}