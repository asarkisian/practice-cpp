//-------------------------------------------------
// ShotgunGuy.h

#ifndef SHOTGUNGUY_H
#define SHOTGUNGUY_H

#include "Monster.h"

class SpaceMarine;

class ShotgunGuy : public Monster
{
public:

	// Constructor
	ShotgunGuy(length_t inX, 
		       length_t inY, 
		       direction_t inD, 
		       health_t inH);

	virtual ~ShotgunGuy();
};
#endif
//-------------------------------------------------