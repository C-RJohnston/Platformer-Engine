#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Structs.h"
#include "Maths.h"
#include <sstream>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
using namespace sf;
using namespace std;
class LevelManager
{
private:
	const int NUM_LEVELS = 1;
	int currentLevel;
	std::map<int, std::string> levelPaths;
	Texture woodTexture;


	
public:
	//temporary usage
	LevelManager();
	//creates the individual tiles
	vector<tile> generatePlatform(vector<vector<int>> points);
	//finds the level file based on the level number
	string getLevelPath(int level);
	//interprets the data from the file
	vector<vector<int>> readFile(string path);

};

