//-------------------------------------------------
// Globals.cpp

#include "Globals.h"
#include "Room.h"

Moves::Moves()
:stepForward('w'),
 stepBackward('s'),
 stepLeft('z'),
 stepRight('c'),
 turnLeft('a'),
 turnRight('d'),
 quit('q'),
 attack('f')
{}

Directions::Directions()
:north("North"),
 east("East"),
 south("South"),
 west("West")
{}

const int the_width  = 40;
const int the_height = 20;

// Original  width is 40, height is 20
// Temporary width is 37, height is 19
Room theRoom(the_width, the_height);

Moves theMoves;
Directions theDirections;

//------------------------------------------------