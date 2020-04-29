#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

//structure for an individual tile in the level
struct tile
{
	int ID;
	int type;
	Vector2f Position;
	FloatRect bindingBox;
};

//contains the data for different types of tile
struct typeData
{
	Texture tex;
	bool tangibility;
	/*
	friction
	restitution
	interactable
	contents
	function
	collectable
	*/
};
//contain the data the player needs to spawn each level
struct spawnData
{
	Vector2f startPosition;
	Vector2f startVelocity;
	Vector2f gravity;
	/*
	base stats
	*/
};