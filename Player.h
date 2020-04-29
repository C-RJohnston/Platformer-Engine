#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Structs.h"
using namespace sf;
using namespace std;
class Player
{
private:
	//graphics
	Sprite sprite;
	Texture texture;
	//motion
	bool spawned = false;
	Vector2f position;
	Vector2f velocity;
	Vector2f acceleration = Vector2f(1200.f,0.f);
	Vector2f deceleration = Vector2f(800.f, 0.f);
	Vector2f gravity;
	Vector2f topRunSpeed = Vector2f(350.f, 0.f);
	Vector2f topWalkSpeed = Vector2f(200, 0);
	bool walkLeft;
	bool walkRight;
	bool jumpUp;
	bool shift;
	//collisions
	FloatRect boundBox;
	FloatRect top;
	FloatRect bottom;
	FloatRect left;
	FloatRect right;
	bool onGround;
	bool onCeil;
	bool justJumped ;
	float timeJumping;
	float maxJumpTime;
	Vector2f blockPos;
public:
	//constructor and destructor
	Player();

	//spawning function
	bool spawn(spawnData data);

	//handles walking
	void walk(float direction, float dt);

	void jump(float dt);
	//change the gravity for the player
	void setGravity(Vector2f gravity);

	//return the player's center
	Vector2f getCenter();

	//stop the player (for collisions)
	void stopUp(Vector2f blockPos);
	void stopDown(Vector2f blockPos);
	void stopLeft(Vector2f blockPos);
	void stopRight(Vector2f blockPos);
	void setBools(bool up, bool down);

	//update the binding boxes
	void updateBoxes();

	//returns the binding boxes
	FloatRect getBindingBox();
	FloatRect getTopBox();
	FloatRect getBottomBox();
	FloatRect getLeftBox();
	FloatRect getRightBox();


	//update function
	void update(float dt);

	//return the sprite
	Sprite getSprite();

	//handle input
	void handleInput();

};

