//----------------------------------------------------
// Game.cpp

#include "Game.h"

//------------------------------------------
// Constructors
Game::Game()
{
	ttt = new(TicTacToe);
}

//------------------------------------------
// Destructors
Game::~Game()
{
	delete ttt;
}

//------------------------------------------
// Modifiers
void Game::playGame()
{
	bool result(false);
	
	while(!ttt->isQuit())
	{
		ttt->resetValues();
		ttt->selectionMenu();

		while(!ttt->arePlayersWon())
		{
			ttt->displayGrid();
			ttt->playerOneTurn();
			ttt->displayGrid();				
			result = (ttt->checkPattern());
			if(result == true)
			{
				ttt->setWhoWon(true, 1);
				break;
			}
			result = (ttt->isTie());
			if(result == true)
			{
				break;
			}
			ttt->playerTwoTurn();
			ttt->displayGrid();
			result = (ttt->checkPattern());		
			if(result == true)
			{
				ttt->setWhoWon(true, 2);
				break;
			}
		}
		ttt->displayWinner();
		ttt->playAgain();
	}
}
//----------------------------------------------------