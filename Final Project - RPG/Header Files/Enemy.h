#pragma once

template <typename T>//counter template class to count number of enemies
struct counter {
	counter() {
		count++;
	}
	virtual ~counter() {
		count--;
	}
	static int count;
};

template<typename T>int counter<T>::count(0);

class Enemy : counter<Enemy>{
public:
	Enemy();
	Enemy(int lvl, int x, int y);//creates new enemy with a level and position
	~Enemy();

	int GetPosX();//returns x pos of enemy
	int GetPosY();//returns y pos of enemy

	int GetExpGranted();

	void MoveEnemy(std::vector<std::vector<char>> *map);//Moves the enemy, chooses a random direction and moves if it can

	int health;//health of enemy
	int level;//level of the enemy

	int Attack();//returns attack number to deal damage to player
private:
	int posX, posY;//position of the enemy
	int expGranted;//how much experience is granted by killing enemy
};