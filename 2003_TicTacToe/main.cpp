//----------------------------------------------------
// main.cpp

#include "Game.h"
#include <iostream>
#include <stdexcept>

int main()
{
	try
	{
		Game theGame;
		theGame.playGame();
	}
	catch(const std::exception& e)
	{
		std::cerr << '\n' << e.what() << std::endl;
	}
	catch(...)
	{
		std::cerr << "\nUnknown internal error" << std::endl;
	}

	return(EXIT_SUCCESS);
}
//----------------------------------------------------