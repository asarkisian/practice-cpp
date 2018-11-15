//-------------------------------------------------
// Game.h

// Warning - Copy constructor could not be generated
#pragma warning(disable : 4511)

#ifndef GAME_H
#define GAME_H

#include "DataFile.h"
#include "Screen.h"
#include "Typedefs.h"
#include <sstream>
#include <vector>

class Bonus;
class Monster;
class SpaceMarine;

class Game
{
public:

	Game();
	~Game();

	void play();

private:
	Screen theScreen;
	DataFile dataFile;
	std::istringstream demoStream;
	
	SpaceMarine* sm; 

	std::vector<Monster*> mon;
	std::vector<Bonus*> bon;

	length_t startX;
	length_t startY;
	direction_t startD;
	health_t startH;
	armor_t startA;
};

#endif
//-------------------------------------------------