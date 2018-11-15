//-------------------------------------------------
// Monster.cpp

#pragma warning(disable : 4715)

#include "Globals.h"
#include "Monster.h"
#include "myAssert.h"
#include "Room.h"
#include "SpaceMarine.h"
#include "Monster.h"
#include <cstdlib>
#include <iostream>
using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::abs;

Monster::Monster(length_t inX, 
		         length_t inY, 
		         direction_t inD, 
		         health_t inH,
		         health_t inMH,
				 int inDM)
:my_xPosition(inX), 
my_yPosition(inY),
my_directionFacing(inD), 
my_health(inH),
my_stepForward('w'), 
my_stepBackward('s'), 
my_stepLeft('z'), 
my_stepRight('c'), 
my_turnLeft('a'), 
my_turnRight('d'), 
my_move(' '), 
my_minHealth(0), 
my_maxHealth(inMH),
my_north("North"),
my_south("South"),
my_east("East"),
my_west("West"),
my_stepSize(1), 
my_imageNorth('^'),
my_imageEast('>'),
my_imageSouth('v'),
my_imageWest('<'),
my_attack('f'),
my_imageDead('D'),
my_damage(inDM)
{
	releaseAssert(isValidPosition());
	releaseAssert(isValidDirection());
	releaseAssert(isValidHealth());	
}

Monster::~Monster()
{}

// Public Modifier Member Functions
void Monster::setMove(SpaceMarine& sm)
{
    if(isReadyToAttack(sm))
	    my_move = my_attack;
	else if(isReadyToTurn(sm))
		my_move = turnMove(sm);    
	else
		my_move = stepMove(sm);
}

void Monster::stepForward()
{
	debugStatement(const direction_t oldDirection(my_directionFacing));

	if(my_directionFacing == my_north)
	    my_yPosition += 1;
	else if(my_directionFacing == my_south)
		my_yPosition -= 1;
	else if(my_directionFacing == my_east)
		my_xPosition += 1;
	else
	    my_xPosition -= 1;
	
	limitPosition();
	debugAssert(oldDirection == my_directionFacing);
	debugAssert(isValidPosition());
}

void Monster::stepBackward()
{
	debugStatement(const direction_t oldDirection(my_directionFacing));

	if(my_directionFacing == my_north)
	    my_yPosition -= 1;
	else if(my_directionFacing == my_south)
		my_yPosition += 1;
	else if(my_directionFacing == my_east)
		my_xPosition -= 1;
	else
	    my_xPosition += 1;

	limitPosition();
	debugAssert(oldDirection == my_directionFacing);
	debugAssert(isValidPosition());
}

void Monster::stepLeft()
{
	debugStatement(const direction_t oldDirection(my_directionFacing));

	if(my_directionFacing == my_north)
	    my_xPosition -= 1;
	else if(my_directionFacing == my_south)
		my_xPosition += 1;
	else if(my_directionFacing == my_east)
		my_yPosition += 1;
	else
	    my_yPosition -= 1;

	limitPosition();
	debugAssert(oldDirection == my_directionFacing);
	debugAssert(isValidPosition());
}

void Monster::stepRight()
{
	debugStatement(const direction_t oldDirection(my_directionFacing));

	if(my_directionFacing == my_north)
	    my_xPosition += 1;
	else if(my_directionFacing == my_south)
		my_xPosition -= 1;
	else if(my_directionFacing == my_east)
		my_yPosition -= 1;
	else
	    my_yPosition += 1;

	limitPosition();
	debugAssert(oldDirection == my_directionFacing);
	debugAssert(isValidPosition());
}

void Monster::turnLeft()
{
    if(my_directionFacing == my_north)
	    my_directionFacing = my_west;
	else if(my_directionFacing == my_south)
		my_directionFacing = my_east;
	else if(my_directionFacing == my_east)
		my_directionFacing = my_north;
	else
	    my_directionFacing = my_south;
}

void Monster::turnRight()
{
    if(my_directionFacing == my_north)
	    my_directionFacing = my_east;
	else if(my_directionFacing == my_south)
		my_directionFacing = my_west;
	else if(my_directionFacing == my_east)
		my_directionFacing = my_south;
	else
	    my_directionFacing = my_north;
}

void Monster::processMove(SpaceMarine& sm)
{
	if(isAlive())
		if(my_move == my_stepForward)
			stepForward();
		else if(my_move == my_stepBackward)
			stepBackward();
		else if(my_move == my_stepLeft)
			stepLeft();
		else if(my_move == my_stepRight)
			stepRight();
		else if(my_move == my_turnLeft)
			turnLeft();
		else if(my_move == my_turnRight)
			turnRight();
		else if(my_move == my_attack)
            if(isReadyToAttack(sm))
				attack(sm);
}

// Public Accessor Member Functions
length_t Monster::xPosition() const
{
    return(my_xPosition);
}

length_t Monster::yPosition() const
{
    return(my_yPosition);
}

direction_t Monster::directionFacing() const
{
    return(my_directionFacing);
}

health_t Monster::health() const
{
    return(my_health);
}

void Monster::adjustHealth(const health_t inH)
{
	my_health += inH;
	limitHealth();
}

void Monster::setHealth(const health_t inH)
{
	my_health = inH;
	limitHealth();
}

bool Monster::isAlive() const
{
    if(my_health > my_minHealth)
		return true;
	return false;
}

image_t Monster::image() const
{
    if(!isAlive())
	    return my_imageDead;
	else if(my_directionFacing == my_north)
	    return my_imageNorth; 
	else if(my_directionFacing == my_south)
	    return my_imageSouth;
	else if(my_directionFacing == my_east)
        return my_imageEast;
	else
	    return my_imageWest;
}

void Monster::attack(SpaceMarine& sm) const
{
	if(!sm.armor())
	    sm.adjustHealth(my_damage);
	else
	{
	    sm.adjustArmor(my_damage * 2/3);
		sm.adjustHealth(my_damage * 1/3);
	}
}

bool Monster::isReadyToAttack(const SpaceMarine& csm) const
{
	if(my_directionFacing == my_north)
	{
	    if(my_xPosition == csm.xPosition() && csm.isAlive() && my_yPosition < csm.yPosition())
		    return true;
		else
			return false;
	}
	else if(my_directionFacing == my_south)
	{
		if(my_xPosition == csm.xPosition() && csm.isAlive() && my_yPosition > csm.yPosition())
			return true;
		else
			return false;
	}
	else if(my_directionFacing == my_east)
	{
	    if(my_yPosition == csm.yPosition() && csm.isAlive() && my_xPosition < csm.xPosition())
			return true;
		else
			return false;
	}
	else
	{
		if(my_yPosition == csm.yPosition() && csm.isAlive() && my_xPosition > csm.xPosition())
			return true;
		else
			return false;
	}
}

bool Monster::isReadyToTurn(const SpaceMarine& csm) const
{
	if(my_xPosition == csm.xPosition() && csm.isAlive() && my_yPosition < csm.yPosition())
		return true;
	else if(my_xPosition == csm.xPosition() && csm.isAlive() && my_yPosition > csm.yPosition())
		return true;
	else if(my_yPosition == csm.yPosition() && csm.isAlive() && my_xPosition < csm.xPosition())
		return true;
	else if(my_yPosition == csm.yPosition() && csm.isAlive() && my_xPosition > csm.xPosition())
		return true;
	return false;
}

move_t Monster::turnMove(const SpaceMarine& csm) const
{
	if(my_directionFacing == my_north)
	{
		if(my_xPosition < csm.xPosition() && my_yPosition == csm.yPosition())
			return my_turnRight;
		else if(my_xPosition > csm.xPosition() && my_yPosition == csm.yPosition())
			return my_turnLeft;
		else
			return my_turnLeft;
	}
	else if(my_directionFacing == my_west)
	{
		if(my_xPosition < csm.xPosition() && my_yPosition == csm.yPosition())
			return my_turnLeft;
		else if(my_xPosition  == csm.xPosition() && my_yPosition < csm.yPosition())
			return my_turnRight;
		else
			return my_turnLeft;
	}
	else if(my_directionFacing == my_south)
	{
		if(my_xPosition < csm.xPosition() && my_yPosition == csm.yPosition())
			return my_turnLeft;
		else if(my_xPosition > csm.xPosition() && my_yPosition == csm.yPosition())
			return my_turnRight;
		else
			return my_turnLeft;
	}
	else
	{
        if(my_xPosition > csm.xPosition() && my_yPosition == csm.yPosition())
			return my_turnLeft;
		else if(my_xPosition == csm.xPosition() && my_yPosition < csm.yPosition())
			return my_turnLeft;
		else
			return my_turnRight;
	}
}

move_t Monster::stepMove(const SpaceMarine& csm) const
{
	if(my_xPosition == csm.xPosition() && my_yPosition == csm.yPosition())
		return my_stepBackward;
	else if(abs(csm.xPosition() - my_xPosition) < abs(csm.yPosition() - my_yPosition))
	{
		if(my_xPosition < csm.xPosition())
		{
            if(my_directionFacing == my_north)
				return my_stepRight;
			else if(my_directionFacing == my_east)
				return my_stepForward;
			else if(my_directionFacing == my_west)
				return my_stepBackward;
			else
				return my_stepLeft;
		}
		else
		{
            if(my_directionFacing == my_north)
				return my_stepLeft;
			else if(my_directionFacing == my_east)
				return my_stepBackward;
			else if(my_directionFacing == my_west)
				return my_stepForward;
			else
				return my_stepRight;
		}
	}
	else
	{
		if(my_yPosition < csm.yPosition())
		{
			if(my_directionFacing == my_north)
				return my_stepForward;
			else if(my_directionFacing == my_south)
				return my_stepBackward;
			else if(my_directionFacing == my_east)
				return my_stepLeft;
			else
				return my_stepRight;
		}
		else
		{
			if(my_directionFacing == my_north)
				return my_stepBackward;
			else if(my_directionFacing == my_south)
				return my_stepForward;
			else if(my_directionFacing == my_east)
				return my_stepRight;
			else
				return my_stepLeft;
		}
	}
}

// Private Accessor Member Functions
bool Monster::isValidHealth() const
{
    if(my_health >= my_minHealth && my_health <= my_maxHealth)
		return true;
	return false;
}

bool Monster::isValidPosition() const
{
    if((my_xPosition > theRoom.xPosWestWall() && my_xPosition < theRoom.xPosEastWall()) 
	&& (my_yPosition > theRoom.yPosSouthWall() && my_yPosition < theRoom.yPosNorthWall()))
	    return true;
	return false;
}

bool Monster::isValidDirection() const
{
    if(my_directionFacing == my_north
	|| my_directionFacing == my_south
	|| my_directionFacing == my_east
	|| my_directionFacing == my_west)
	    return true;
	return false;
}

void Monster::limitPosition()
{
	if(my_xPosition <= theRoom.xPosWestWall())
		my_xPosition = theRoom.xPosWestWall() + 1;
	else if(my_xPosition >= theRoom.xPosEastWall())
		my_xPosition = theRoom.xPosEastWall() - 1;
	
	if(my_yPosition <= theRoom.yPosSouthWall())
		my_yPosition = theRoom.yPosSouthWall() + 1;
	else if(my_yPosition >= theRoom.yPosNorthWall())
		my_yPosition = theRoom.yPosNorthWall() - 1;
}

void Monster::limitHealth()
{
    if(my_health < my_minHealth)
	    my_health = my_minHealth;
	else if(my_health > my_maxHealth)
	    my_health = my_maxHealth;
}
//-------------------------------------------------