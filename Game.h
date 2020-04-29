#pragma once
#include <sfml/Graphics.hpp>
#include <sfml/Audio.hpp>
#include <sfml/Window.hpp>
#include <sfml/System.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Structs.h"
#include "Maths.h"
#include "LevelManager.h"
//engine class, contains update and render functions
using namespace sf;
using namespace std;
class Game
{
private:
	//variables
	RenderWindow* window;
	VideoMode vM;
	Event event;
	View BGView;
	View mainView;
	//private functions
	void initVariables();
	void initWindow();
	Player player;
	spawnData sData{ Vector2f(0,0), Vector2f(0, 0), Vector2f(0,600)};
	LevelManager lM;
	Texture texture;
	vector<tile> level = lM.generatePlatform(lM.readFile("levels/level0.dat"));
	map<int, typeData> typeMap;
public:
	//constructors & destructors
	Game();
	virtual ~Game();
	//accessors
	const bool getWindowIsOpen() const;

	//functions
	//tomove to a texture holder function
	vector<Sprite> drawLevel(vector<tile> tileSet);
	//tomove to a detect collisions file
	//for checking to see if the player has collided with an environment object
	void environmentCollision(Player& player, vector<tile> tileSet);
	//to get input
	void pollEvents();
	//update function
	void update(float dt);
	//drawing function
	void render();
};

