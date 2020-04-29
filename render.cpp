#include "Game.h"

//renders game objects
void Game::render()
{
	this->window->clear();

	this->window->setView(mainView);

	this->window->draw(player.getSprite());
	//for debugging collisions
	//RectangleShape head;
	//head.setSize(Vector2f(player.getTopBox().width, player.getTopBox().height));
	//head.setPosition(Vector2f(player.getTopBox().left, player.getTopBox().top));
	//head.setFillColor(Color::White);
	//this->window->draw(head);
	//RectangleShape feet;
	//feet.setSize(Vector2f(player.getBottomBox().width, player.getBottomBox().height));
	//feet.setPosition(Vector2f(player.getBottomBox().left, player.getBottomBox().top));
	//feet.setFillColor(Color::Green);
	//this->window->draw(feet);
	//RectangleShape left;
	//left.setSize(Vector2f(player.getLeftBox().width, player.getLeftBox().height));
	//left.setPosition(Vector2f(player.getLeftBox().left, player.getLeftBox().top));
	//left.setFillColor(Color::Blue);
	//this->window->draw(left);
	//RectangleShape right;
	//right.setSize(Vector2f(player.getRightBox().width, player.getRightBox().height));
	//right.setPosition(Vector2f(player.getRightBox().left, player.getRightBox().top));
	//right.setFillColor(Color::Cyan);
	//this->window->draw(right);

	FloatRect camera = FloatRect(this->player.getCenter().x-vM.width/2, this->player.getCenter().y-vM.height/2, vM.width, vM.height);
	for (Sprite s : drawLevel(level))
	{
		if (camera.intersects(s.getGlobalBounds()))
		{
			this->window->draw(s);
		}
	}
	this->window->display();
}
