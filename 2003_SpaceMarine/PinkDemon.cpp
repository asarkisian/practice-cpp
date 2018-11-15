//-------------------------------------------------
// PinkDemon.cpp

#pragma warning(disable : 4512)
#pragma warning(disable : 4715)

#include "Globals.h"
#include "myAssert.h"
#include "Room.h"
#include "SpaceMarine.h"
#include "PinkDemon.h"
#include <cstdlib>
#include <iostream>
using std::abs;

PinkDemon::PinkDemon(length_t inX, 
			         length_t inY, 
			         direction_t inD, 
			         health_t inH)
:Monster(inX, inY, inD, inH, 70, -20)
{}

PinkDemon::~PinkDemon()
{}

// Virtual Member Functions
bool PinkDemon::isReadyToAttack(const SpaceMarine& csm) const
{
	if(directionFacing() == theDirections.north)
	{
		if((yPosition() == csm.yPosition()-1) 
		&& (xPosition() == csm.xPosition() || xPosition() == csm.xPosition() + 1 
		 || xPosition() == csm.xPosition()-1) && csm.isAlive())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if(directionFacing() == theDirections.south)
	{
		if((yPosition() == csm.yPosition()+1) 
		&& (xPosition() == csm.xPosition() || xPosition() == csm.xPosition() + 1 
		 || xPosition() == csm.xPosition()-1) && csm.isAlive())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if(directionFacing() == theDirections.east)
	{
		if((xPosition() == csm.xPosition()-1) 
		&& (yPosition() == csm.yPosition() || yPosition() == csm.yPosition() + 1 
		 || yPosition() == csm.yPosition()-1) && csm.isAlive())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if((xPosition() == csm.xPosition()+1) 
		&& (yPosition() == csm.yPosition() || yPosition() == csm.yPosition() + 1 
		 || yPosition() == csm.yPosition()-1) && csm.isAlive())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool PinkDemon::isReadyToTurn(const SpaceMarine& csm) const
{
	if((yPosition() == csm.yPosition()-1) 
	&& (xPosition() == csm.xPosition() || xPosition() == csm.xPosition() + 1 
		|| xPosition() == csm.xPosition()-1) && csm.isAlive())
	{
		return true;
	}

	if((yPosition() == csm.yPosition()+1) 
	&& (xPosition() == csm.xPosition() || xPosition() == csm.xPosition() + 1 
		|| xPosition() == csm.xPosition()-1) && csm.isAlive())
	{
		return true;
	}

	if((xPosition() == csm.xPosition()-1) 
	&& (yPosition() == csm.yPosition() || yPosition() == csm.yPosition() + 1 
		|| yPosition() == csm.yPosition()-1) && csm.isAlive())
	{
		return true;
	}

	if((xPosition() == csm.xPosition()+1) 
	&& (yPosition() == csm.yPosition() || yPosition() == csm.yPosition() + 1 
		|| yPosition() == csm.yPosition()-1) && csm.isAlive())
	{
		return true;
	}
	return false;
}

move_t PinkDemon::turnMove(const SpaceMarine& csm) const
{
	if((xPosition() == csm.xPosition()) && (yPosition() == csm.yPosition() - 1))
	{
		if(directionFacing() == theDirections.east)
		{
			return theMoves.turnLeft;
		}
		else if(directionFacing() == theDirections.west)
		{
			return theMoves.turnRight;
		}
		else
		{
			return theMoves.turnLeft;
		}
	}
	else if((xPosition() == csm.xPosition() - 1)  && (yPosition() == csm.yPosition() - 1))
	{
		if(directionFacing() == theDirections.west)
		{
			return theMoves.turnRight;
		}
		else
		{
			return theMoves.turnLeft;
		}
	}
	else if((xPosition() == csm.xPosition() + 1) && (yPosition() == csm.yPosition() - 1))
	{
		if(directionFacing() == theDirections.east)
		{
			return theMoves.turnLeft;
		}
		else
		{
			return theMoves.turnRight;
		}
	}
	else if((xPosition() == csm.xPosition() - 1) && (yPosition() == csm.yPosition()))
	{
		if(directionFacing() == theDirections.west)
		{
			return theMoves.turnRight;
		}
		else if(directionFacing() == theDirections.south)
		{
			return theMoves.turnLeft;
		}
		else
		{
			return theMoves.turnRight;
		}
	}
	else if((xPosition() == csm.xPosition() + 1) && (yPosition() == csm.yPosition()))
	{
		if(directionFacing() == theDirections.east)
		{
			return theMoves.turnLeft;
		}
		else if(directionFacing() == theDirections.north)
		{
			return theMoves.turnLeft;
		}
		else
		{
			return theMoves.turnRight;
		}
	}
	else if((xPosition() == csm.xPosition() - 1) && (yPosition() == csm.yPosition() + 1))
	{
		if(directionFacing() == theDirections.north)
		{
			return theMoves.turnRight;
		}
		else
		{
			return theMoves.turnLeft;
		}
	}
	else if((xPosition() == csm.xPosition()) && (yPosition() == csm.yPosition() + 1))
	{
		if(directionFacing() == theDirections.north)
		{
			return theMoves.turnLeft;
		}
		else if(directionFacing() == theDirections.east)
		{
			return theMoves.turnRight;
		}
		else
		{
			return theMoves.turnLeft;
		}
	}
	else if((xPosition() == csm.xPosition() + 1) && (yPosition() == csm.yPosition() + 1))
	{	
		if(directionFacing() == theDirections.north)
		{
			return theMoves.turnLeft;
		}
		else
		{
			return theMoves.turnRight;
		}
	}
}

move_t PinkDemon::stepMove(const SpaceMarine& csm) const
{
	if(xPosition() == csm.xPosition() && yPosition() == csm.yPosition())
	{
		return theMoves.stepBackward;
	}
	else if(abs(csm.xPosition() - xPosition()) > abs(csm.yPosition() - yPosition()))
	{
		if(xPosition() < csm.xPosition())
		{
            if(directionFacing() == theDirections.north)
			{
				return theMoves.stepRight;
			}
			else if(directionFacing() == theDirections.east)
			{
				return theMoves.stepForward;
			}
			else if(directionFacing() == theDirections.west)
			{
				return theMoves.stepBackward;
			}
			else
			{
				return theMoves.stepLeft;
			}
		}
		else
		{
            if(directionFacing() == theDirections.north)
				return theMoves.stepLeft;
			else if(directionFacing() == theDirections.east)
				return theMoves.stepBackward;
			else if(directionFacing() == theDirections.west)
				return theMoves.stepForward;
			else
				return theMoves.stepRight;
		}
	}
	else
	{
		if(yPosition() < csm.yPosition())
		{
			if(directionFacing() == theDirections.north)
			{
				return theMoves.stepForward;
			}
			else if(directionFacing() == theDirections.south)
			{
				return theMoves.stepBackward;
			}
			else if(directionFacing() == theDirections.east)
			{
				return theMoves.stepLeft;
			}
			else
			{
				return theMoves.stepRight;
			}
		}
		else
		{
			if(directionFacing() == theDirections.north)
			{
				return theMoves.stepBackward;
			}
			else if(directionFacing() == theDirections.south)
			{
				return theMoves.stepForward;
			}
			else if(directionFacing() == theDirections.east)
			{
				return theMoves.stepRight;
			}
			else
			{
				return theMoves.stepLeft;
			}
		}
	}
}
//-------------------------------------------------