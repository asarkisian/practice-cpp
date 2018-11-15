//-------------------------------------------------
// SpaceMarine.cpp

#pragma warning(disable : 4512)

#include "Globals.h"
#include "HelperFunctors.h"
#include "Monster.h"
#include "myAssert.h"
#include "Room.h"
#include "SpaceMarine.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::for_each;
using std::istream;
using std::ostream;
using std::ostringstream;
using std::string;
using std::vector;

/*
East Arrow       10
West Arrow       11
North Arrow      1e
South Arrow      1f
*/

SpaceMarine::SpaceMarine(istream& inIS,
						 length_t inX, 
						 length_t inY, 
						 direction_t inD, 
						 health_t inH, 
						 armor_t inA)
:my_xPosition(inX), 
 my_yPosition(inY),
 my_directionFacing(inD), 
 my_armor(inA), 
 my_health(inH),
 my_move(theMoves.quit), 
 my_minHealth(0), 
 my_maxHealth(200),
 my_minArmor(0), 
 my_maxArmor(200), 
 my_stepSize(1), 
 my_imageNorth('\x1e'),
 my_imageEast('\x10'),
 my_imageSouth('\x1f'),
 my_imageWest('\x11'),
 my_imageDead('D'),
 my_damage(-10),
 my_input(inIS),
 my_deathCount(0)
{
	releaseAssert(isValidPosition());
	releaseAssert(isValidDirection());
	releaseAssert(isValidHealth());
	releaseAssert(isValidArmor());
}

// Public Modifier Member Functions
void SpaceMarine::setMove()
{
	my_input >> my_move;
}

void SpaceMarine::stepForward()
{
	debugStatement(const direction_t oldDirection(directionFacing()));
    
	if(directionFacing() == theDirections.north)
	    my_yPosition += 1;
	else if(directionFacing() == theDirections.south)
		my_yPosition -= 1;
	else if(directionFacing() == theDirections.east)
		my_xPosition += 1;
	else
	    my_xPosition -= 1;

	limitPosition();
	debugAssert(oldDirection == directionFacing());
	debugAssert(isValidPosition());
}

void SpaceMarine::stepBackward()
{
	debugStatement(const direction_t oldDirection(directionFacing()));
    
	if(directionFacing() == theDirections.north)
	    my_yPosition -= 1;
	else if(directionFacing() == theDirections.south)
		my_yPosition += 1;
	else if(directionFacing() == theDirections.east)
		my_xPosition -= 1;
	else
	    my_xPosition += 1;

	limitPosition();
	debugAssert(oldDirection == directionFacing());
	debugAssert(isValidPosition());
}

void SpaceMarine::stepLeft()
{
	debugStatement(const direction_t oldDirection(directionFacing()));
    
	if(directionFacing() == theDirections.north)
	    my_xPosition -= 1;
	else if(directionFacing() == theDirections.south)
		my_xPosition += 1;
	else if(directionFacing() == theDirections.east)
		my_yPosition += 1;
	else
	    my_yPosition -= 1;

	limitPosition();
	debugAssert(oldDirection == directionFacing());
	debugAssert(isValidPosition());
}

void SpaceMarine::stepRight()
{
	debugStatement(const direction_t oldDirection(directionFacing()));
    
	if(directionFacing() == theDirections.north)
	    my_xPosition += 1;
	else if(directionFacing() == theDirections.south)
		my_xPosition -= 1;
	else if(directionFacing() == theDirections.east)
		my_yPosition -= 1;
	else
	    my_yPosition += 1;

	limitPosition();
	debugAssert(oldDirection == directionFacing());
	debugAssert(isValidPosition());
}

void SpaceMarine::turnLeft()
{
    if(directionFacing() == theDirections.north)
	    my_directionFacing = theDirections.west;
	else if(directionFacing() == theDirections.south)
		my_directionFacing = theDirections.east;
	else if(directionFacing() == theDirections.east)
		my_directionFacing = theDirections.north;
	else
	    my_directionFacing = theDirections.south;
}

void SpaceMarine::turnRight()
{
    if(directionFacing() == theDirections.north)
	    my_directionFacing = theDirections.east;
	else if(directionFacing() == theDirections.south)
		my_directionFacing = theDirections.west;
	else if(directionFacing() == theDirections.east)
		my_directionFacing = theDirections.south;
	else
	    my_directionFacing = theDirections.north;
}

void SpaceMarine::processMove(const vector<Monster*>& mon)
{
	AttackIfReady attackIfReady(*this);

	if(isAlive() == true)
		if(my_move == theMoves.stepForward)
			stepForward();
		else if(my_move == theMoves.stepBackward)
			stepBackward();
		else if(my_move == theMoves.stepLeft)
			stepLeft();
		else if(my_move == theMoves.stepRight)
			stepRight();
		else if(my_move == theMoves.turnLeft)
			turnLeft();
		else if(my_move == theMoves.turnRight)
			turnRight();
		else if(my_move == theMoves.attack)
		{
			for_each(mon.begin(), mon.end(), attackIfReady);
		}
		else if(my_move == theMoves.quit)
			quitGame();
}

void SpaceMarine::respawn(length_t inX, length_t inY, direction_t inD, health_t inH, armor_t inA)
{
    ++my_deathCount;
	my_xPosition = inX;
	my_yPosition = inY;
	my_directionFacing = inD;
	my_health = inH;
	my_armor = inA;
}

// Public Accessor Member Functions
length_t SpaceMarine::xPosition() const
{
    return my_xPosition;
}

length_t SpaceMarine::yPosition() const
{
    return my_yPosition;
}

direction_t SpaceMarine::directionFacing() const
{
    return my_directionFacing;
}

health_t SpaceMarine::health() const
{
    return my_health;
}

armor_t SpaceMarine::armor() const
{
    return my_armor;
}

string SpaceMarine::createStatusBar() const
{
    ostringstream statusBar;
	statusBar << "Death Count: " << my_deathCount << '\n'
		      << "Health: " << my_health 
		      << ", Armor: " << my_armor 
			  << '\n' << "Enter your move: ";
	return statusBar.str();
}

void SpaceMarine::adjustArmor(const armor_t inA)
{
    my_armor += inA;
	limitArmor();
}

void SpaceMarine::setArmor(const armor_t inA)
{
	my_armor = inA;
	limitArmor();
}

void SpaceMarine::adjustHealth(const health_t inH)
{
	my_health += inH;
	limitHealth();
}

void SpaceMarine::setHealth(const health_t inH)
{
	my_health = inH;
	limitHealth();
}

bool SpaceMarine::quitGame() const
{
    if(my_move == theMoves.quit)
		return true;

	return false;
}

bool SpaceMarine::isAlive() const
{
    if(my_health > my_minHealth)
		return true;

	return false;
}

image_t SpaceMarine::image() const
{
	if(isAlive() == false)
		return my_imageDead;
    else if(directionFacing() == theDirections.north)
	    return my_imageNorth; 
	else if(directionFacing() == theDirections.south)
	    return my_imageSouth;
	else if(directionFacing() == theDirections.east)
        return my_imageEast;
	else
	    return my_imageWest;
}

/*
bool SpaceMarine::isReadyToAttack(const Zombie& czo) const
{
	if(directionFacing() == theDirections.north)
	{
	    if(xPosition() == czo.xPosition() && czo.isAlive() && yPosition() < czo.yPosition())
		    return true;
	}
	else if(directionFacing() == theDirections.south)
	{
		if(xPosition() == czo.xPosition() && czo.isAlive() && yPosition() > czo.yPosition())
			return true;
	}
	else if(directionFacing() == theDirections.east)
	{
	    if(yPosition() == czo.yPosition() && czo.isAlive() && xPosition() < czo.xPosition())
			return true;
	}
	else
	{
		if(yPosition() == czo.yPosition() && czo.isAlive() && xPosition() > czo.xPosition())
			return true;
	}
	return false;
}

void SpaceMarine::attack(Zombie& zo) const
{
    zo.adjustHealth(my_damage);
}

bool SpaceMarine::isReadyToAttack(const ShotgunGuy& csg) const
{
	if(directionFacing() == theDirections.north)
	{
	    if(xPosition() == csg.xPosition() && csg.isAlive() && yPosition() < csg.yPosition())
		    return true;
	}
	else if(directionFacing() == theDirections.south)
	{
		if(xPosition() == csg.xPosition() && csg.isAlive() && yPosition() > csg.yPosition())
			return true;
	}
	else if(directionFacing() == theDirections.east)
	{
	    if(yPosition() == csg.yPosition() && csg.isAlive() && xPosition() < csg.xPosition())
			return true;
	}
	else
	{
		if(yPosition() == csg.yPosition() && csg.isAlive() && xPosition() > csg.xPosition())
			return true;
	}
	return false;
}

void SpaceMarine::attack(ShotgunGuy& sg) const
{
    sg.adjustHealth(my_damage);
}

bool SpaceMarine::isReadyToAttack(const PinkDemon& cpd) const
{
	if(directionFacing() == theDirections.north)
	{
	    if(xPosition() == cpd.xPosition() && cpd.isAlive() && yPosition() < cpd.yPosition())
		    return true;
	}
	else if(directionFacing() == theDirections.south)
	{
		if(xPosition() == cpd.xPosition() && cpd.isAlive() && yPosition() > cpd.yPosition())
			return true;
	}
	else if(directionFacing() == theDirections.east)
	{
	    if(yPosition() == cpd.yPosition() && cpd.isAlive() && xPosition() < cpd.xPosition())
			return true;
	}
	else
	{
		if(yPosition() == cpd.yPosition() && cpd.isAlive() && xPosition() > cpd.xPosition())
			return true;
	}
	return false;
}

void SpaceMarine::attack(PinkDemon& pd) const
{
    pd.adjustHealth(my_damage);
}
*/

bool SpaceMarine::isReadyToAttack(const Monster& cm) const
{
	if(directionFacing() == theDirections.north)
	{
	    if(xPosition() == cm.xPosition() && cm.isAlive() && yPosition() < cm.yPosition())
		    return true;
	}
	else if(directionFacing() == theDirections.south)
	{
		if(xPosition() == cm.xPosition() && cm.isAlive() && yPosition() > cm.yPosition())
			return true;
	}
	else if(directionFacing() == theDirections.east)
	{
	    if(yPosition() == cm.yPosition() && cm.isAlive() && xPosition() < cm.xPosition())
			return true;
	}
	else
	{
		if(yPosition() == cm.yPosition() && cm.isAlive() && xPosition() > cm.xPosition())
			return true;
	}
	return false;
}

void SpaceMarine::attack(Monster& pd) const
{
    pd.adjustHealth(my_damage);
}

// Private Accessor Member Functions
bool SpaceMarine::isValidHealth() const
{
    if(my_health >= my_minHealth && my_health <= my_maxHealth)
		return true;

	return false;
}

bool SpaceMarine::isValidArmor() const
{
    if(my_armor >= my_minArmor && my_armor <= my_maxArmor)
		return true;

	return false;
}

bool SpaceMarine::isValidPosition() const
{
    if((xPosition() > theRoom.xPosWestWall() && xPosition() < theRoom.xPosEastWall()) 
	&& (yPosition() > theRoom.yPosSouthWall() && yPosition() < theRoom.yPosNorthWall()))
	    return true;

	return false;
}

bool SpaceMarine::isValidDirection()
{
    if(directionFacing() == theDirections.north
	|| directionFacing() == theDirections.south
	|| directionFacing() == theDirections.east
	|| directionFacing() == theDirections.west)
	    return true;

	return false;
}

void SpaceMarine::limitPosition()
{
	if(xPosition() <= theRoom.xPosWestWall())
		my_xPosition = theRoom.xPosWestWall() + 1;
	else if(xPosition() >= theRoom.xPosEastWall())
		my_xPosition = theRoom.xPosEastWall() - 1;

	if(yPosition() <= theRoom.yPosSouthWall())
		my_yPosition = theRoom.yPosSouthWall() + 1;
	else if(yPosition() >= theRoom.yPosNorthWall())
		my_yPosition = theRoom.yPosNorthWall() - 1;
}

void SpaceMarine::limitHealth()
{
    if(my_health < my_minHealth)
	    my_health = my_minHealth;
	else if(my_health > my_maxHealth)
	    my_health = my_maxHealth;
}

void SpaceMarine::limitArmor()
{
    if(my_armor < my_minArmor)
        my_armor = my_minArmor;
	else if(my_armor > my_maxArmor)
        my_armor = my_maxArmor;
}
//-------------------------------------------------