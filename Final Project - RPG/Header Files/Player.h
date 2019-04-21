#pragma once

#include <vector>
#include <queue>

#include "Enemy.h"

enum Direction {//directions the player is trying to move in
	UP, DOWN, LEFT, RIGHT
};
struct Stats {//player stats
	int health;
	int maxHealth;
	int mana;
	int maxMana;
	int strength;
	int agility;
	int intellect;
	int spirit;
};

class Player {
public:
	Player();
	~Player();

	void SetPos(int x, int y);//set the player position

	int GetPosX();//returns player x position
	int GetPosY();//returns player y position

	void MovePlayer(Direction dir);//Moves the player

	virtual int MeleeAttack() { return 0; }//Virtual function for melee attack, different for each derived character class
	virtual int SpellAttack() { return 0; }//virtual function for spell attack, different for each derived character class
	virtual void Regen() {}//virtual function for regenerating player health each turn, different for each derived character class
	void RegenMana();

	bool InitCombat(Enemy *mob);//Starts combat, then proceeds to combatloop
	bool CombatLoop(Enemy *mob);//combat loop
	void DisplayCombatInfo(Enemy *mob);

	void GrantExp(Enemy *mob);//grant experience to player after combat
	bool DidLevelUp();//checks if player leveled up
	virtual void LevelUp();//level up player, virtual to extend to derived classes

	virtual void DisplayStats();//displays stats, virtual to extend to derived classes
private:
	int posX, posY;//position of player0
protected:
	Stats stats;//player stats
	int level;//player level
	int exp, expToLevel;//player experience and how much to next level
};