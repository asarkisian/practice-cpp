//--------------------------------------------
// main.cpp

// By Armond Sarkisian
// Blackjack Version 1.3
// From 3 July, 2003 to 5 July, 2003
// Blackjack Game (Player-mode and Demo-mode)

/*
Note: You can use the DataFile.txt to specify
      if you want the game to be run in demo
	  -mode or player-mode. In the DataFile.txt,
	  you will see two lines: nodemo and nofile.
	  If you erase the "no" portion of the nodemo
	  then the game will be run in the demo-mode.
	  To bring it back, simply put a no in front
	  of the demo. The nofile means to not output
	  to the output.txt file. If you erase the no
	  then the game will be outputted to the disk
	  file Output.txt. In the DataFile.txt, you
	  will notice a bunch of S's and H's in sequence.
	  Those are instructions to the input stream 
	  while in demo-mode. Feel free to change
	  the sequence of the demo.
*/

#include <iostream>

void doMain();

int main()
{
	try
	{
		doMain();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(...)
	{
		std::cerr << "Unknown internal error!\n";
	}

	std::cout << std::endl;
	return(EXIT_SUCCESS);
}
//--------------------------------------------