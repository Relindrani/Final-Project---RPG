#include <iostream>
#include <time.h>

#include "Header Files/Engine.h"

int main(){
    srand(time(NULL));
    Engine eng;
    eng.Go();
    return 0;
}
/*
FINAL PROJECT REQUIREMENTS
USED:
*   Opening screen with description of the application and instructions
*   Menu for the user to choose options
    Class Selection
*   4 Classes
    Engine
    Level
    Player
    PlayerClasses
        -Warrior
        -Rogue
        -Mage
        -Priest
    Enemy
*   Inheritence (minimum 2 derived classes)
    All PlayerClasses are derived from Player
*   Polymorphism
    Virtual functions in Player
*   Encapsulation
    Each class does this
*   File input and output processing OR network communication (remote data storage)
    File input to load levels
*   Templates
    Template class used to count remaining enemies in each levvel
*   Vectors
    Used for the level map
*   Exception handling
    threw exception for file reading

DIDN'T USE:
*   Minimum of one search and one sort not form the STL (Note: you can sort the input file to meet this criteria)
*   Iterators
*   Design Pattern(s) (must be described and documented)
*   Boost Library
*/