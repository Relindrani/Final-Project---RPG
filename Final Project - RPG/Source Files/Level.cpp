#include <vector>
#include <string>
#include <fstream>

#include "../Header Files/Level.h"

using namespace std;

Level::Level() {
	curLvl = 0;
}
Level::~Level() {

}

void Level::LoadNextLevel() {
	curLvl++;//increment current level
	string loadLevel = "Assets/Levels/level";//directory
	loadLevel += to_string(curLvl);//add level number
	loadLevel += ".txt";//add extension
	ifstream inFile(loadLevel);//load file

	if (!inFile)throw "Could not load level from file at: " + loadLevel;

	SetDimensions(25, 25);//set the dimensions to 25,25

	vector<vector<char>*>level;//create 2-d vector to read into
	string line;//line

	int iter = 0;
	while (getline(inFile, line)) {//while there are lines
		level.push_back(new vector<char>);//add new 'row' to vector
		for (int i = 0; i < line.length(); i++) {//for length of line
			level.at(iter)->push_back(line[i]);//push back each character
		}
		iter++;//increment iterator
	}

	for (int i = 0; i < level.size(); i++) {//for height
		for (int j = 0; j < level.at(i)->size(); j++) {//for width
			map[j][i] = level.at(i)->at(j);//load level vector into map vector
		}
	}
}
int Level::GetWidth() { return w; }//return wdith
int Level::GetHeight() { return h; }//return height

int Level::GetCurLevel() { return curLvl; }//return currentLevel

vector<vector<char>> Level::GetMap() { return map; }//return map

void Level::SetDimensions(int w, int h) {//set the size of the map vector and width/height
	map.resize(w);
	for (int i = 0; i < w; i++)map.at(i).resize(h, 0);
	this->w = w;
	this->h = h;
}