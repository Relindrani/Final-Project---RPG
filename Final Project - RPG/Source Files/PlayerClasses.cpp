#include <iostream>

#include "../Header Files/PlayerClasses.h"

using namespace std;

//**************************************************************//
//                         Warrior Class                        //
//**************************************************************//
Warrior::Warrior() {//initialize stats
	stats.health = 40;
	stats.maxHealth = 40;
	stats.mana = 10;
	stats.maxMana = 10;
	stats.strength = 20;
	stats.agility = 10;
	stats.intellect = 10;
	stats.spirit = 10;
}
Warrior::~Warrior() {

}

int Warrior::MeleeAttack() {//melee damage
	return (int)(.75*stats.strength) + (.25*stats.agility);
}
int Warrior::SpellAttack() {//spell damage
	return (int)(stats.intellect) + (.5*stats.spirit);
}
void Warrior::Regen() {//regen each turn
	stats.health += (int)stats.spirit / 10;
	if (stats.health > stats.maxHealth)stats.health = stats.maxHealth;
}

void Warrior::LevelUp() {//levelup stat increases
	Player::LevelUp();
	stats.maxHealth += 5;
	stats.health = stats.maxHealth;
	stats.strength += 5;
	stats.agility += 2;
	stats.spirit += 2;
}

void Warrior::DisplayStats() {
	cout << "Warrior" << endl;
	Player::DisplayStats();
}


//**************************************************************//
//                         Rogue Class                          //
//**************************************************************//
Rogue::Rogue() {//initialize stats
	stats.health = 35;
	stats.maxHealth = 35;
	stats.mana = 10;
	stats.maxMana = 10;
	stats.strength = 10;
	stats.agility = 20;
	stats.intellect = 10;
	stats.spirit = 10;
}
Rogue::~Rogue() {

}

int Rogue::MeleeAttack() {//melee damage
	return (int)(.25*stats.strength) + (.75*stats.agility);
}
int Rogue::SpellAttack() {//spell damage
	return (int)(stats.intellect) + (.5*stats.spirit);
}
void Rogue::Regen() {//regen each turn
	stats.health += (int)stats.spirit / 10;
	if (stats.health > stats.maxHealth)stats.health = stats.maxHealth;
}

void Rogue::LevelUp() {//levelup stat increases
	Player::LevelUp();
	stats.maxHealth += 5;
	stats.health = stats.maxHealth;
	stats.strength += 2;
	stats.agility += 5;
	stats.spirit += 2;
}

void Rogue::DisplayStats() {
	cout << "Rogue" << endl;
	Player::DisplayStats();
}

//**************************************************************//
//                         Mage Class                           //
//**************************************************************//
Mage::Mage() {//initialize stats
	stats.health = 15;
	stats.maxHealth = 15;
	stats.mana = 35;
	stats.maxMana = 35;
	stats.strength = 10;
	stats.agility = 10;
	stats.intellect = 20;
	stats.spirit = 10;
}
Mage::~Mage() {

}

int Mage::MeleeAttack() {//melee damage
	return (int)(.5*stats.strength) + (.5*stats.agility);
}
int Mage::SpellAttack() {//spell damage
	return (int)(stats.intellect) + (.5*stats.spirit);
}
void Mage::Regen() {//regen each turn
	stats.health += (int)stats.spirit / 10 * stats.intellect / 10;
	if (stats.health > stats.maxHealth)stats.health = stats.maxHealth;
}

void Mage::LevelUp() {//levelup stat increases
	Player::LevelUp();
	stats.maxHealth += 5;
	stats.health = stats.maxHealth;
	stats.maxMana += 5;
	stats.mana = stats.maxMana;
	stats.intellect += 5;
	stats.spirit += 2;
}

void Mage::DisplayStats() {
	cout << "Mage" << endl;
	Player::DisplayStats();
}


//**************************************************************//
//                         Priest Class                         //
//**************************************************************//
Priest::Priest() {//initialize stats
	stats.health = 20;
	stats.maxHealth = 20;
	stats.mana = 30;
	stats.maxMana = 30;
	stats.strength = 10;
	stats.agility = 10;
	stats.intellect = 15;
	stats.spirit = 15;
}
Priest::~Priest() {

}

int Priest::MeleeAttack() {//melee damage
	return (int)(.5*stats.strength) + (.5*stats.agility);
}
int Priest::SpellAttack() {//spell damage
	return (int)(stats.intellect) + (.5*stats.spirit);
}
void Priest::Regen() {//regen each turn
	stats.health += (int)stats.spirit / 10 + stats.intellect / 10;
	if (stats.health > stats.maxHealth)stats.health = stats.maxHealth;
}

void Priest::LevelUp() {//levelup stat increases
	Player::LevelUp();
	stats.maxHealth += 5;
	stats.health = stats.maxHealth;
	stats.maxMana += 5;
	stats.mana = stats.maxMana;
	stats.intellect += 5;
	stats.spirit += 5;
}

void Priest::DisplayStats() {
	cout << "Priest" << endl;
	Player::DisplayStats();
}