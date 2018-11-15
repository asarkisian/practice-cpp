//-------------------------------------------------
// PinkDemon.h

#ifndef PINKDEMON_H
#define PINKDEMON_H

#include "Monster.h"

class SpaceMarine;

class PinkDemon : public Monster
{
public:

	// Constructor
	PinkDemon(length_t inX, 
		      length_t inY, 
		      direction_t inD, 
		      health_t inH);

	virtual	~PinkDemon();
	
	// Modifiers
	virtual bool isReadyToAttack(const SpaceMarine& csm) const;
    virtual bool isReadyToTurn(const SpaceMarine& csm) const;
	virtual move_t turnMove(const SpaceMarine& csm) const;
    virtual move_t stepMove(const SpaceMarine& csm) const;
};

#endif
//-------------------------------------------------