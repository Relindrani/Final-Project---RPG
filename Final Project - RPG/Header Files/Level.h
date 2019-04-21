#pragma once


#include <vector>
#include <string>

class Level {
public:
	Level();
	~Level();

	void LoadNextLevel();//Loads the next level

	int GetWidth();//returns width of level
	int GetHeight();//returns height of level

	int GetCurLevel();//returns the current level

	std::vector<std::vector<char>> GetMap();//returns the level map
private:
	std::vector<std::vector<char>> map;//map loaded from text file

	int w, h;//width and height of the level
	int curLvl;//the current level

	void SetDimensions(int w, int h);//sets the width and height of the level
};