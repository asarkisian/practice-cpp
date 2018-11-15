//----------------------------------------------------
// TicTacToe.h

#pragma once

#include "Typedefs.h"
#include <vector>

class TicTacToe
{
public:

	//------------------------------------------
	// Constructors
	TicTacToe();

	//------------------------------------------
	// Destructors
	~TicTacToe();

	//------------------------------------------
	// Modifiers
	void resetValues();
	void playerOneTurn();
	void playerTwoTurn();
	void playAgain();
	void selectionMenu();
	void setWhoWon(bool choice, int playerNumber);

	//------------------------------------------
	// Accessors
	void displayGrid() const;
	void displayWinner() const;
	bool checkPattern() const;
	bool isQuit() const;
	bool arePlayersWon() const;
	bool isTie() const;

private:

	//------------------------------------------
	// Data
	symbol_t my_x;
	symbol_t my_o;
	symbol_t my_playerSymbol;

	bool my_isPlayerOneWin;
	bool my_isPlayerTwoWin;
	bool my_isPlayerTie;

	counter_t my_maxSpaces;
	std::vector<char> my_spaces;

	bool my_isQuit;
	bool my_isOnePlayer;

	//------------------------------------------
	// Modifiers
	void quitGame();
	bool placeSymbol(symbol_t r, symbol_t c);
};
//----------------------------------------------------