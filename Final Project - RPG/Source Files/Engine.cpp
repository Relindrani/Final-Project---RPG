#include <string>
#include <iostream>

#include <conio.h>//C library to read console without buffer allowing for input without hitting enter

#include "../Header Files/Engine.h"
#include "../Header Files/Player.h"
#include "../Header Files/PlayerClasses.h"

using namespace std;

//key codes for conio.h _getch
const int SPECIAL_ARROW_KEY_CODE = 224;
const int UP_ARROW_KEY = 72;
const int LEFT_ARROW_KEY = 75;
const int RIGHT_ARROW_KEY = 77;
const int DOWN_ARROW_KEY = 80;

//number of final levels
const int LAST_LEVEL = 5;

//gets action from user
char* getAction() {
	char action;
	cin >> action;
	return &action;
}

Engine::Engine() {

}
Engine::~Engine() {

}
//Asks user which class they would like to play, creates new class then returns that to the primary player object
Player* Engine::ChoosePlayerClass() {
	Player *chosenPlayerClass;
	char action;
	cout << "Please select which class you would like to be: \n" <<
		"1 for Warrior\n" <<
		"2 for Rogue\n" <<
		"3 for Mage\n" <<
		"4 for Priest\n";
	action = *getAction();
	switch (action) {
	case '1': {
		Warrior *warrior = new Warrior;
		chosenPlayerClass = warrior;
	}break;
	case '2': {
		Rogue *rogue = new Rogue;
		chosenPlayerClass = rogue;
	}break;
	case '3': {
		Mage *mage = new Mage;
		chosenPlayerClass = mage;
	}break;
	case '4':{
		Priest *priest = new Priest;
		chosenPlayerClass = priest;
	}break;
	default:
		cout << "Invalid action, please try again" << endl;
		return ChoosePlayerClass();
	}
	return chosenPlayerClass;
}
//initialize values
void Engine::Init() {
	playing = true;//whether we are playing or not

	currentLevel = new Level();//create new level
	currentLevel->LoadNextLevel();//load next level

	for (int i = 0; i < 5; i++) {//creates 5 enemies
		int x = rand() % 25;//random x
		int y = rand() % 25;//random y
		while(currentLevel->GetMap().at(x).at(y) != ' ') {//keep getting new random values if the coordinates are not an empty space
			x = rand() % 25;
			y = rand() % 25;
		}
		enemies.push_back(new Enemy(currentLevel->GetCurLevel(), x, y));//add the enemy to the vector
	}

	cout << "Welcome to PLACEHOLDER_RPG_NAME. \nThe goal in this game is to get the end of all the levels. \nYou are the 'P', the 'E' are the enemies, the end of each level is the 'F', and the '*' are walls. \nEnjoy.\n(NOTE: This game is a much more pleasant experience if you make your console larger; For windows, a window height of 55 is a good number;)\n\n" << endl;

	player = ChoosePlayerClass();
	system("pause");//pause
	system("cls");//clear screen
	Display();//display info
}
//gets input from user, clears screen, displays new information, updates non input information, clears screen, then displays new information one last time
void Engine::MainLoop() {
	while (playing) {
		GetInput();
		system("cls");
		Display();
		Update();
		system("cls");
		Display();
	}
}
//displays all information each turn
void Engine::Display() {
	//show instructions
	cout << "Welcome to PLACEHOLDER_RPG_NAME. \nThe goal in this game is to get the end of all the levels. \nYou are the 'P', the 'E' are the enemies, the end of each level is the 'F', and the '*' are walls. \nEnjoy.\n(NOTE: This game is a much more pleasant experience if you make your console larger; For windows, a window height of 55 is a good number;)\n\n" << endl;

	//Show player stats
	cout << endl;
	player->DisplayStats();
	cout << endl << endl;

	//Show what level you are on and number of enemies left on the level
	cout << "Level: " << currentLevel->GetCurLevel() << endl;
	cout << "Enemies Remaining: " << counter<Enemy>::count << endl << endl;

	//load current level map into new map
	displayMap = currentLevel->GetMap();
	//place player
	displayMap.at(player->GetPosX()).at(player->GetPosY()) = 'P';
	//place enemies
	for (int i = 0; i < enemies.size(); i++) {
		displayMap.at(enemies[i]->GetPosX()).at(enemies[i]->GetPosY()) = 'E';
	}
	//display all
	for (int h = 0; h < currentLevel->GetHeight(); h++) {
		for (int w = 0; w < currentLevel->GetWidth(); w++) {
			cout << displayMap.at(w).at(h);
		}
		cout << endl;
	}
}
//gets user input for movement without using a buffer
void Engine::GetInput() {
	cout << "Use the arrow keys to move \n(Note: holding down arrow key will work but will cause the map to refresh very quickly causing a flashing effect)" << endl;
	int key;
	key = _getch();
	if (key == SPECIAL_ARROW_KEY_CODE) {//_getch returns 2 key codes for arrow keys, first is 224 then whatever the code for the key is (72,75,77,80)
		key = _getch();
		//checks if the player can be moved in a direction, then moves if they can
		if (key == UP_ARROW_KEY) if (canMovePlayer(UP))player->MovePlayer(UP);
		if (key == LEFT_ARROW_KEY) if (canMovePlayer(LEFT))player->MovePlayer(LEFT);
		if (key == RIGHT_ARROW_KEY) if (canMovePlayer(RIGHT))player->MovePlayer(RIGHT);
		if (key == DOWN_ARROW_KEY) if (canMovePlayer(DOWN))player->MovePlayer(DOWN);
	}
}
//update for regeneration of player health/mana and movement of enemies
void Engine::Update() {
	player->Regen();
	player->RegenMana();
	for (int i = 0; i < enemies.size(); i++)enemies[i]->MoveEnemy(&displayMap);
}
//checks if the player can move in specified direction
bool Engine::canMovePlayer(Direction dir) {
	char c;
	switch (dir) {
	case UP:
		c = displayMap.at(player->GetPosX()).at(player->GetPosY() - 1);
		break;
	case DOWN:
		c = displayMap.at(player->GetPosX()).at(player->GetPosY() + 1);
		break;
	case LEFT:
		c = displayMap.at(player->GetPosX() - 1).at(player->GetPosY());
		break;
	case RIGHT:
		c = displayMap.at(player->GetPosX() + 1).at(player->GetPosY());
		break;
	}
	if (c == ' ')return true;//return true if the next space is empty
	else if (c == 'F') {//level is finished, run levelbeat to start next one
		levelBeat();
		return false;//return false since there is no need to move once next level is loaded
	} else if (c == 'E') {//checks if you walked into an enemy
		Enemy *mob = new Enemy;//creates new enemy
		counter<Enemy>::count--;//reduce count since this is a temp enemy
		switch (dir) {//checks which enemy is at the adjacent position based on the direction
		case UP:
			for (int i = 0; i < enemies.size(); i++)if (enemies[i]->GetPosX() == player->GetPosX() && enemies[i]->GetPosY() == player->GetPosY() - 1)mob = enemies[i];
			break;
		case DOWN:
			for (int i = 0; i < enemies.size(); i++)if (enemies[i]->GetPosX() == player->GetPosX() && enemies[i]->GetPosY() == player->GetPosY() + 1)mob = enemies[i];
			break;
		case LEFT:
			for (int i = 0; i < enemies.size(); i++)if (enemies[i]->GetPosX() == player->GetPosX() - 1 && enemies[i]->GetPosY() == player->GetPosY())mob = enemies[i];
			break;
		case RIGHT:
			for (int i = 0; i < enemies.size(); i++)if (enemies[i]->GetPosX() == player->GetPosX() + 1 && enemies[i]->GetPosY() == player->GetPosY())mob = enemies[i];
			break;
		}
		if (player->InitCombat(mob)) {//start combat with that enemy; true is returned if we win
			cout << "You defeated the enemy.\nYou earned " << mob->GetExpGranted() << " experience.\n";//display experience message
			player->GrantExp(mob);//grant exp to player
			if (player->DidLevelUp()) {//checks if player leveled up
				player->LevelUp();//level up if so
			}
			enemies.erase(remove(enemies.begin(), enemies.end(), mob), enemies.end());//remove the enemy using mob pointer
			counter<Enemy>::count--;//reduce enemy count
			system("pause");//pause
		} else {//if you lost in combat
			cout << "You have been defeated." << endl;//defeat message
			system("pause");//pause
			system("cls");//clear screen
			showGameOverScreen();//game over and exit
		}
		return true;//return true to walk into position where defeated enemy was
	}
	return false;
}

//handles loading the next level once this one is finished
void Engine::levelBeat(){
	if (currentLevel->GetCurLevel() == LAST_LEVEL) {//if it was the last level
		cout << "You have beat the game!!!" << endl;//game won message
		system("pause");//pause
		system("cls");//clear screen
		showVictoryScreen();//show victory and exit
	} else {//if it wasn't the last level
		cout << "Loading level: " << (currentLevel->GetCurLevel() + 1) << endl;//loading level message
		currentLevel->LoadNextLevel();//load next level
		player->SetPos(1, 23);//reset player position
		enemies.clear();//clear out enemies vector
		counter<Enemy>::count = 0;//reset enemies count
		for (int i = 0; i < 5; i++) {//create new enemies
			int x = rand() % 25;
			int y = rand() % 25;
			while (currentLevel->GetMap().at(x).at(y) != ' ') {
				x = rand() % 25;
				y = rand() % 25;
			}
			enemies.push_back(new Enemy(currentLevel->GetCurLevel(), x, y));
		}
		system("pause");//pause
		system("cls");//clear screen
		Display();//display information
	}
}
void Engine::showVictoryScreen() {
	cout << "Victory" << endl;//print victory
	system("pause");//pause
	exit(0);//exit
}
void Engine::showGameOverScreen() {
	cout << "Game Over" << endl;//print game over
	system("pause");//pause
	exit(0);//exit
}

void Engine::Go() {
	Init();//intialize
	MainLoop();//start main loop
}