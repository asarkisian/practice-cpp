//-------------------------------------------------
// Zombie.h

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Monster.h"

class Zombie : public Monster
{
public:

	// Constructor
	Zombie(length_t inX, 
		   length_t inY, 
		   direction_t inD, 
		   health_t inH);

	virtual	~Zombie();
};

#endif
//-------------------------------------------------