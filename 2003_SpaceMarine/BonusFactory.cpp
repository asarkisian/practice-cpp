//-------------------------------------------------
// BonusFactory.cpp

#include "BonusFactory.h"
#include "ArmorBonus.h"
#include "BlueArmor.h"
#include "GreenArmor.h"
#include "HealthBonus.h"
#include <sstream>
#include <stdexcept>
#include <string>
using std::domain_error;
using std::istringstream;
using std::string;

Bonus* bonusFactory(const string& row)
{
	istringstream data(row);
	string type;
	length_t inX, inY;
	data >> type >> inX >> inY;
	if(type == "ArmorBonus")
	{
		return new ArmorBonus(inX, inY);
	}
	else if(type == "BlueArmor")
	{
		return new BlueArmor(inX, inY);
	}
	else if(type == "GreenArmor")
	{
		return new GreenArmor(inX, inY);
	}
	else if(type == "HealthBonus")
	{
		return new HealthBonus(inX, inY);
	}
	else
	{
		throw domain_error("Bad type in bonusFactory");
	}
}
//-------------------------------------------------