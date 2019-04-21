#pragma once

#include "Player.h"

class Warrior : public Player {
public:
	Warrior();
	~Warrior();

	int MeleeAttack();//Warrior melee attack
	int SpellAttack();//Warrior spell attack
	void Regen();//Warrior regen

	void LevelUp();//Warrior level up

	void DisplayStats();//Warrior display
};

class Rogue : public Player {
public:
	Rogue();
	~Rogue();

	int MeleeAttack();//rogue melee attack
	int SpellAttack();//rogue spell attack
	void Regen();//rogue regen

	void LevelUp();//rogue level up

	void DisplayStats();//rogue display
};

class Mage : public Player {
public:
	Mage();
	~Mage();

	int MeleeAttack();//mage melee attack
	int SpellAttack();//mage spell attack
	void Regen();//mage regen

	void LevelUp();//mage level up

	void DisplayStats();//mage display
};

class Priest : public Player {
public:
	Priest();
	~Priest();

	int MeleeAttack();//priest melee attack
	int SpellAttack();//priest spell attack
	void Regen();//priest regen

	void LevelUp();//priest level up

	void DisplayStats();//priest display
};