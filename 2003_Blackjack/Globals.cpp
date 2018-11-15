//-----------------------------------------------
// Globals.cpp

#include "Globals.h"
#include "typedefs.h"
#include <cstdlib>

void clearScreen()
{
	system("cls");
}

void pauseScreen()
{
	for(counter_t i(0); i < 59999999; ++i);
}
//-----------------------------------------------