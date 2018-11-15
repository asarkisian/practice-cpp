//-------------------------------------------------
// MonsterFactory.cpp

#include "MonsterFactory.h"
#include "ShotgunGuy.h"
#include "PinkDemon.h"
#include "Zombie.h"
#include <sstream>
#include <stdexcept>
#include <string>
using std::domain_error;
using std::istringstream;
using std::string;

Monster* monsterFactory(const string& row)
{
	istringstream data(row);
	string type;
	length_t inX, inY;
	direction_t inD;
	health_t inH;
	data >> type >> inX >> inY >> inD >> inH;
	if(type == "ShotgunGuy")
	{
		return new ShotgunGuy(inX, inY, inD, inH);
	}
	else if(type == "PinkDemon")
	{
		return new PinkDemon(inX, inY, inD, inH);
	}
	else if(type == "Zombie")
	{
		return new Zombie(inX, inY, inD, inH);
	}
	else
	{
		throw domain_error("Bad type in monsterFactory");
	}
}
//-------------------------------------------------