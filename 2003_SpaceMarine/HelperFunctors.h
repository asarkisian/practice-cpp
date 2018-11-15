//-------------------------------------------------
// HelperFunctors.cpp

#ifndef HELPERFUNCTORS_H
#define HELPERFUNCTORS_H

#include "ArmorBonus.h"
#include "BlueArmor.h"
#include "DataFile.h"
#include "GreenArmor.h"
#include "HealthBonus.h"
#include "Monster.h"
#include "myAssert.h"
#include "Screen.h"
#include "SpaceMarine.h"
#include "Typedefs.h"
#include <sstream>
#include <string>

#include <iostream>

//------- Helper Class -------
class PlaceBonus
{
public:
	PlaceBonus(Screen& inS)
	:my_screen(inS)
	{
	}

	void operator()(const Bonus* bonus)
	{
		my_screen.place(bonus->xPosition(), bonus->yPosition(), bonus->image());
	}
private:
	Screen& my_screen;
};

class ProcessBonus
{
public:
	ProcessBonus(SpaceMarine& inS)
	:sm(&inS)
	{}
	
	void operator()(Bonus* bonus)
	{
		if(bonus->isStoodOnBy(*sm)) 
			bonus->pickedUpBy(*sm);
	}

private:
	SpaceMarine* sm;
};

/*
class AppendBonus
{
public:
	AppendBonus(std::vector<Bonus*>& inB) 
	:my_b(inB)
	{}

	void operator()(const std::string& line)
	{
		std::istringstream bonusData(line);
		length_t inX, inY;
		std::string inT;
		bonusData >> inT >> inX >> inY;

		if(inT == "ArmorBonus")
		{
			my_b.push_back(new ArmorBonus(inX, inY));
		}
		else if(inT == "BlueArmor")
		{
			my_b.push_back(new BlueArmor(inX, inY));
		}
		else if(inT == "HealthBonus")
		{
			my_b.push_back(new GreenArmor(inX, inY));
		}
		else if(inT == "GreenArmor")
		{
			my_b.push_back(new HealthBonus(inX, inY));
		}
		else
		{
			throw std::domain_error("Bad Type in AppendBonus");
		}
	}
private:
	std::vector<Bonus*>& my_b;
};
*/

class AttackIfReady
{
public:
	AttackIfReady(const SpaceMarine& inSM)
	:my_sm(inSM)
	{
	}

	void operator()(Monster* target) const
	{
		if(my_sm.isReadyToAttack(*target)) my_sm.attack(*target);
	}
private:
	const SpaceMarine& my_sm;
};

class PlaceMonster
{
public:
	PlaceMonster(Screen& my_s)
	:theScreen(my_s)
	{
	}

	void operator()(const Monster* inM)
	{
		theScreen.place(inM->xPosition(), inM->yPosition(), inM->image());	
	}

private:
	Screen& theScreen;
};

class ProcessMonster
{
public:
	ProcessMonster(SpaceMarine& inSM)
	:sm(&inSM)
	{
	}

	void operator()(Monster* inM)
	{
		inM->setMove(*sm);
		inM->processMove(*sm);
	}

private:
	SpaceMarine* sm;
};

#endif
//-------------------------------------------------