//-------------------------------------------------
// Game.cpp

#include "BonusFactory.h"
#include "DataFile.h"
#include "Game.h"
#include "HelperFunctors.h"
#include "MonsterFactory.h"
#include "myAssert.h"
#include "Screen.h"
#include "SpaceMarine.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <numeric>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
using std::accumulate;
using std::back_inserter;
using std::cin;
using std::cout;
using std::domain_error;
using std::for_each;
using std::ifstream;
using std::istream;
using std::istringstream;
using std::string;
using std::transform;
using std::vector;

// Helper Function to be used with the constructor
string demoData(const DataFile& dataFile)
{
	string theDemoData("");
	theDemoData = accumulate(dataFile.begin("[DemoData]"), dataFile.end("[DemoData]"),
		                     theDemoData);
	return(theDemoData);
}

// Helper Function to be used with the destructor
void deleteBonus(Bonus* bon)
{
	delete bon;
}

// Helper Function to be used with the destructor
void deleteMonster(Monster* mon)
{
	delete mon;
}

Game::Game()
:theScreen(cout),
 dataFile("MiniDoomData.txt"),
 demoStream(demoData(dataFile)),
 startX(0), 
 startY(0),
 startD(""),
 startH(0),
 startA(0)
{
	string type("");
	length_t inX(0), inY(0);
	direction_t inD("");
	health_t inH(0);
	armor_t inA(0);

	// Determining whether or not we are going to be in demo mode or not
	string demo(stringToken(*dataFile.begin("[Demo]"), 0));
	istream& inIS(demo == "demo" ? static_cast<istream&>(demoStream) : cin);

	istringstream smData(*dataFile.begin("[SpaceMarine]"));
	smData >> type >> inX >> inY >> inD >> inH >> inA;
	startX = inX;
	startY = inY;
	startD = inD;
	startH = inH;
	startA = inA;
	sm = new SpaceMarine(inIS, inX, inY, inD, inH, inA);

	transform(dataFile.begin("[Monster]"), dataFile.end("[Monster]"),
		back_inserter(mon),
		monsterFactory);

	transform(dataFile.begin("[Bonus]"), dataFile.end("[Bonus]"),
		      back_inserter(bon),
			  bonusFactory);
}

Game::~Game()
{
	// Release the memory back to the heap
	for_each(mon.begin(), mon.end(), deleteMonster);
	for_each(bon.begin(), bon.end(), deleteBonus);
}

void Game::play()
{
	PlaceBonus placeBonus(theScreen);
	PlaceMonster placeMonster(theScreen);
	ProcessBonus processBonus(*sm);
	ProcessMonster processMonster(*sm);

	do
	{
		theScreen.reset();    
		
		for_each(bon.begin(), bon.end(), placeBonus);	
		for_each(mon.begin(), mon.end(), placeMonster);

		theScreen.place(sm->xPosition(), sm->yPosition(), sm->image());

		theScreen.setStatusBar(sm->createStatusBar());
		theScreen.display();

		sm->setMove();
		sm->processMove(mon);

		for_each(bon.begin(), bon.end(), processBonus);
		for_each(mon.begin(), mon.end(), processMonster);

		if(sm->isAlive() == false)
		{
			sm->respawn(startX, startY, startD, startH, startA);
		}
	}while(sm->quitGame() == false);
}
//-------------------------------------------------