#include "Game.h"


//checking for input
void Game::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		//checks for if the close button is pressed and closes the game
		case sf::Event::Closed:
			this->window->close();
			break;
		//checks if esc is pressed and closes the game
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}

	player.handleInput();
}