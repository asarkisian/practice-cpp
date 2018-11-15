//-------------------------------------------------
// ShotgunGuy.cpp

#include "Globals.h"
#include "myAssert.h"
#include "Room.h"
#include "SpaceMarine.h"
#include "ShotgunGuy.h"
#include <cstdlib>
#include <iostream>

ShotgunGuy::ShotgunGuy(length_t inX, 
			           length_t inY, 
			           direction_t inD, 
			           health_t inH)
:Monster(inX, inY, inD, inH, 50, -30)
{}

ShotgunGuy::~ShotgunGuy()
{}
//-------------------------------------------------