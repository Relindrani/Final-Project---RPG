
#include <iostream>
#include <vector>

#include "../Header Files/Enemy.h"

Enemy::Enemy() {

}
Enemy::Enemy(int lvl, int x, int y) {//create enemy using level and position; calculate exp granted and health based on level
	this->level = lvl;
	this->posX = x;
	this->posY = y;
	this->expGranted = lvl;
	this->health = lvl * 20;
}
Enemy::~Enemy() {

}

int Enemy::GetPosX() { return posX; }//return posx
int Enemy::GetPosY() { return posY; }//return posy

int Enemy::GetExpGranted() { return expGranted; }//return experience granted

void Enemy::MoveEnemy(std::vector<std::vector<char>> *map) {//move enemy
	int dir = rand() % 4;//random number between 0 and 3; each represent a direction
	char c;//adjacent character based on direction
	switch (dir) {//checks if can move; then does if possible
	case 0: {//up
		c = map->at(GetPosX()).at(GetPosY() - 1);
		if (c == ' ')posY -= 1;
	}break;
	case 1: {//down
		c = map->at(GetPosX()).at(GetPosY() + 1);
		if (c == ' ')posY += 1;
	}break;
	case 2: {//left
		c = map->at(GetPosX() - 1).at(GetPosY());
		if (c == ' ')posX -= 1;
	}break;
	case 3: {//right
		c = map->at(GetPosX() + 1).at(GetPosY());
		if (c == ' ')posX += 1;
	}break;
	}
}

//enemy attack damage
int Enemy::Attack() {
	return level * 2;
}