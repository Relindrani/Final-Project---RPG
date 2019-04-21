#include <iostream>

#include "../Header Files/Player.h"
#include "../Header Files/Engine.h"

using namespace std;

Player::Player() {//player start position, level, exp and exp to level
	posX = 1;
	posY = 23;
	level = 1;
	exp = 0;
	expToLevel = level * 5;
}
Player::~Player() {

}

void Player::SetPos(int x, int y) {//sets player position
	this->posX = x;
	this->posY = y;
}

int Player::GetPosX() { return posX; }//returns posx
int Player::GetPosY() { return posY; }//returns posy

void Player::MovePlayer(Direction dir) {//move player 1 space in direction
	switch (dir) {
	case UP:
		posY -= 1;
		break;
	case DOWN:
		posY += 1;
		break;
	case LEFT:
		posX -= 1;
		break;
	case RIGHT:
		posX += 1;
		break;
	}
}

void Player::RegenMana() {//regen mana each turn
	stats.mana++;
	if (stats.mana > stats.maxMana)stats.mana = stats.maxMana;
}

bool Player::InitCombat(Enemy *mob) {//start combat
	//entering combat message
	cout << "\n*****************\n*Entering combat*\n*****************" << endl;
	return CombatLoop(mob); 
}
bool Player::CombatLoop(Enemy *mob) {//combat loop, stops when player or enemy dies
	char action = NULL;//action
	int damage;//amount of damage
	while (stats.health > 0 && mob->health > 0) {//while both still alive
		DisplayCombatInfo(mob);//display combat information
		cout << "\nYou're turn. Choose an action.\n" <<//menu display
			"1 to do a melee attack\n" <<
			"2 to do a magic attack (Requires 5 mana)" << endl;
		action = *getAction();//get input
		switch (action) {
		case '1'://melee attack
			damage = MeleeAttack();
			mob->health -= damage;//do damage to enemy
			cout << "\nYou did " << damage << " damage to the enemy." << endl;//damage message
			if (mob->health > 0) {//if mob is still alive
				damage = mob->Attack();
				stats.health -= damage;//deal damage to player
				cout << "The enemy did " << damage << " damage to you." << endl;//damage message
			}
			break;
		case '2':
			if (stats.mana >= 5) {//if you have enough mana
				damage = SpellAttack();
				mob->health -= damage;//deal damage to enemy
				cout << "\nYou did " << damage << " damage to the enemy." << endl;//damage message
				stats.mana -= 5;//use mana
				if (mob->health > 0) {//if mob is still alive
					damage = mob->Attack();
					stats.health -= damage;//deal damage to player
					cout << "The enemy did " << damage << " damage to you." << endl;//damage message
				}
			} else {
				cout << "Not enough mana, try a different action" << endl;//not enough mana message
			}
			break;
		default:
			cout << "Invalid action, try again" << endl;//invalid input
		}
	}
	if (stats.health <= 0)return false;//if you die, return false, leads to game over
	else if (mob->health <= 0)return true;//if enemy dies, return true, grant xp and continue
}

//displays level, health and mana of player and enemy (except enemy mana... since there is none...)
void Player::DisplayCombatInfo(Enemy *mob) {
	cout << endl << endl;
	cout << "Player Level: " << level << "\tPlayer Health: " << stats.health << "\tPlayer Mana: " << stats.mana << endl;
	cout << "Enemy  Level: " << mob->level << "\tEnemy  Health: " << mob->health << endl;
}
//grant xp to player based on enemy killed
void Player::GrantExp(Enemy *mob) {
	exp += mob->GetExpGranted();
}
//checks if player leveled up
bool Player::DidLevelUp() {
	return exp >= expToLevel;
}
//level up player
void Player::LevelUp() {
	exp -= expToLevel;
	if (exp < 0)exp = 0;
	level++;
	expToLevel = level * 5;
}

//display all player stats
void Player::DisplayStats() {
	cout << "Level: " << level << endl;
	cout << "Experience: " << exp << endl;
	cout << "Experience to Level: " << expToLevel << endl;
	cout << "Health: " << stats.health << "\tMana: " << stats.mana << endl;
	cout << "Strength: " << stats.strength << endl;
	cout << "Agility: " << stats.agility << endl;
	cout << "Intellect: " << stats.intellect << endl;
	cout << "Spirit: " << stats.spirit << endl << endl;
}