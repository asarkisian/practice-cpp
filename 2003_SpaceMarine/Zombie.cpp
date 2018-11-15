//-------------------------------------------------
// Zombie.cpp

#include "Globals.h"
#include "myAssert.h"
#include "Room.h"
#include "SpaceMarine.h"
#include "Zombie.h"
#include <cstdlib>
#include <iostream>

Zombie::Zombie(length_t inX, 
			   length_t inY, 
			   direction_t inD, 
			   health_t inH)
:Monster(inX, inY, inD, inH, 30, -10)
{}

Zombie::~Zombie()
{}
//-------------------------------------------------