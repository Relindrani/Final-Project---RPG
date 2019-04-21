#pragma once

#include "Level.h"
#include "Player.h"

char* getAction();

class Engine {
public:
	Engine();
	~Engine();

	void Go();//Runs init then starts main game loop
private:
	Level* currentLevel;//The current level
	Player* player;//The player
	std::vector<Enemy*> enemies;//The enemies on the level

	std::vector<std::vector<char>> displayMap;//The map to display based on the level and player/enemy positions

	Player* ChoosePlayerClass();//Has user choose which class they would like to make at beginning

	void Init();//Initializes values, loads first level and creates player and first enemies
	void MainLoop();//Main game loop, gets user input, displays, updates values not based on input, then displays again
	void Display();//Displays all information required, instructions, player stats, level, enemy count, and all the map information
	void GetInput();//Gets user input for movement and either moves, starts combat, or loads next level or victory screen
	void Update();//player regeneration and enemy movement each turn

	bool canMovePlayer(Direction dir);//checks if the player can move in the specified direction

	void levelBeat();//Runs when the player reaches the end of the level, shows victory screen or loads next level, resetting player position and loading new enemies
	void showVictoryScreen();//shows victory screen and exits
	void showGameOverScreen();//shows game over screen and exits

	bool playing;//value that checks if the game is still playing
};