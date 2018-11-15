//-------------------------------------------------
// Globals.h

#pragma warning(disable : 4512)

#ifndef GLOBALS_H
#define GLOBALS_H

#include "Typedefs.h"

class Room;
extern Room theRoom;

struct Moves
{
	Moves();
	const move_t stepForward;
	const move_t stepBackward;
	const move_t stepLeft;
	const move_t stepRight;
	const move_t turnLeft;
	const move_t turnRight;
	const move_t quit;
	const move_t attack;
};

extern Moves theMoves;

struct Directions
{
	Directions();
	const direction_t north;
	const direction_t east;
	const direction_t south;
	const direction_t west;
};

extern Directions theDirections;

#endif
//-------------------------------------------------