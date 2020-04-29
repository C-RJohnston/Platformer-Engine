#include "Game.h"


//private functions
void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->vM.width = 1600;
	this->vM.height = 900;
	this->window = new RenderWindow(this->vM , "Platformer", Style::Titlebar | Style::Close);
	this->mainView.setSize(vM.width, vM.height);
}

//constructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
	//temporary test textures
	Texture wood;
	wood.loadFromFile("Graphics/wood.png");
	typeData woodType = { wood,true };
	typeMap[1] = woodType;
}
//destructors
Game::~Game()
{
	delete this->window;
}
//gives game open status
const bool Game::getWindowIsOpen() const
{
	return this->window->isOpen();
}
//temp position, tomove to a texture holder when it exists
vector<Sprite> Game::drawLevel(vector<tile> tileSet)
{
	vector<Sprite> sprites;

	for (tile& t : tileSet)
	{
		if (t.type == -1)
		{
			//sets the player spawn
			this->sData.startPosition = t.Position;
			this->player.spawn(sData);
		}
		else if (t.type == 0)
		{
			//for empty positions
		}
		else
		{
		Sprite sprite;
		sprite.setTexture(typeMap[t.type].tex);
		sprite.setTextureRect(IntRect(0, 0, 32, 32));
		sprite.setPosition(t.Position);
		sprites.push_back(sprite);
		}

	}
	return sprites;
}
//temp position
void Game::environmentCollision(Player& player, vector<tile> tileSet)
{
	Vector2f qPos = Vector2f(floor(player.getCenter().x / 32.f),floor(player.getCenter().y / 32.f));
	vector<tile> localTiles;
	//position of the tiles around the player in the grid
	vector<Vector2f> localPos{
		Vector2f(qPos.x - 1,qPos.y - 1),Vector2f(qPos.x,qPos.y - 1),Vector2f(qPos.x + 1,qPos.y - 1),
		Vector2f(qPos.x - 1,qPos.y),Vector2f(qPos.x,qPos.y),Vector2f(qPos.x + 1,qPos.y),
		Vector2f(qPos.x - 1,qPos.y + 1),Vector2f(qPos.x,qPos.y + 1),Vector2f(qPos.x + 1,qPos.y + 1),
	};
	//adds the tiles around the player to the vector of localTiles
	for (tile t : tileSet)
	{
		if (std::find(localPos.begin(), localPos.end(), t.Position/32.f) != localPos.end()) 
		{
			localTiles.push_back(t);
		}
	}
	//to keep track if any environment collisions have occured, add truth every time one is
	bool onTop = false;
	bool onBottom = false;
	for (tile t : localTiles)
	{
		if (typeMap[t.type].tangibility)
		{
			if (player.getBindingBox().intersects(t.bindingBox))
			{
				if (player.getTopBox().intersects(t.bindingBox))
				{
					onTop++;
					player.stopUp(t.Position);
				}
				else if (player.getLeftBox().intersects(t.bindingBox))
				{
					player.stopLeft(t.Position);
				}
				else if (player.getBottomBox().intersects(t.bindingBox))
				{
					onBottom++;
					player.stopDown(t.Position);
				}
				else if (player.getRightBox().intersects(t.bindingBox))
				{
					player.stopRight(t.Position);
				}
			}
		}
	}
	player.setBools(onTop, onBottom);
}

//functions
	//updates the game for the new frame
void Game::update(float dt)
{
	player.update(dt);
	environmentCollision(player, level);
	mainView.setCenter(player.getCenter());
	//mainView.setCenter(Vector2f(Mouse::getPosition().x,Mouse::getPosition().y));
	
}

