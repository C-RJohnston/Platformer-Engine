#include "LevelManager.h"


LevelManager::LevelManager()
{
	levelPaths[0] = "levels/level0.dat";
}

vector<tile> LevelManager::generatePlatform(vector<vector<int>> points)
{
	//to give each tile a unique identifier
	int co = 0;
	vector<tile> platforms;
	//iterates over the y
	for (int i = 0; i < points.size(); i++)
	{
		//iterates over the x
		for (int j = 0; j < points[i].size(); j++)
		{
			co++;
			tile t{ currentLevel + co,points[i][j],Vector2f(j*32,i*32),FloatRect(j*32,i*32,32,32)};
			platforms.push_back(t); 
		}
	}
	return platforms;
}



std::string LevelManager::getLevelPath(int level)
{
	auto keyValuePair = levelPaths.find(level);
	// Did we find a match?
	if (keyValuePair != levelPaths.end())
	{
		//found the level number matches a level file
		return keyValuePair->second;
	}
	else
	{
		//put error handling in here
	}
}

vector<vector<int>> LevelManager::readFile(string path)
{
	string line;
	ifstream levelFile (path);
	vector<vector<int>> points;
	if (levelFile.is_open())
	{
		while (getline(levelFile, line))
		{
		//converting the strings into intergers to store in a 2nd rank tensor
			std::stringstream iss(line);
			int number;
			std::vector<int> myNumbers;
			while (iss >> number)
			{
				myNumbers.push_back(number);
			}
			points.push_back(myNumbers);
		}

	}

	return points;
}
