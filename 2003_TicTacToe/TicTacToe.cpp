//----------------------------------------------------
// TicTacToe.cpp

#include "TicTacToe.h"
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::for_each;

// Helper Class
void clearSpaces(char& m)
{
	m = (' ');
}

void clearScreen()
{
	system("cls");
}

//------------------------------------------
// Constructors
TicTacToe::TicTacToe()
:my_x('X'),
 my_o('O'),
 my_playerSymbol(' '),
 my_isPlayerOneWin(false),
 my_isPlayerTwoWin(false),
 my_isPlayerTie(false),
 my_maxSpaces(9),
 my_spaces(my_maxSpaces, ' '),
 my_isQuit(false),
 my_isOnePlayer(false)
{
}

//------------------------------------------
// Destructors
TicTacToe::~TicTacToe()
{
}

//------------------------------------------
// Modifiers
void TicTacToe::resetValues()
{
	my_playerSymbol = (' ');
	my_isPlayerOneWin = my_isPlayerTwoWin = my_isPlayerTie = my_isQuit = my_isOnePlayer = (false);
	for_each(my_spaces.begin(), my_spaces.end(), clearSpaces);
}

void TicTacToe::playerOneTurn()
{
	symbol_t row(' '), col(' ');
	
	my_playerSymbol = my_x;

	do
	{
		cout << "\n\nPlayer One: Enter row and column: ";
		cin >> row >> col;
		
		row = toupper(row);
		col = toupper(col);

	}while(placeSymbol(row, col) == false);
}

void TicTacToe::playerTwoTurn()
{
	symbol_t row(' '), col(' ');
	
	my_playerSymbol = my_o;

	do
	{
		if(my_isOnePlayer == true)
		{
			// Offensive

			// Horizontal Row A
			if(my_spaces[0] == my_o && my_spaces[1] == my_o && my_spaces[2] == ' ')
			{
				row = 'A';
				col = '3';
			}
			else if(my_spaces[0] == my_o && my_spaces[1] == ' ' && my_spaces[2] == my_o)
			{
				row = 'A';
				col = '2';
			}
			else if(my_spaces[0] == ' ' && my_spaces[1] == my_o && my_spaces[2] == my_o)
			{
				row = 'A';
				col = '1';
			}

			// Horizontal Row B
			else if(my_spaces[3] == my_o && my_spaces[4] == my_o && my_spaces[5] == ' ')
			{
				row = 'B';
				col = '3';
			}
			else if(my_spaces[3] == my_o && my_spaces[4] == ' ' && my_spaces[5] == my_o)
			{
				row = 'B';
				col = '2';
			}
			else if(my_spaces[3] == ' ' && my_spaces[4] == my_o && my_spaces[5] == my_o)
			{
				row = 'B';
				col = '1';
			}

			// Horizontal Row C
			else if(my_spaces[6] == my_o && my_spaces[7] == my_o && my_spaces[8] == ' ')
			{
				row = 'C';
				col = '3';
			}
			else if(my_spaces[6] == my_o && my_spaces[7] == ' ' && my_spaces[8] == my_o)
			{
				row = 'C';
				col = '2';
			}
			else if(my_spaces[6] == ' ' && my_spaces[7] == my_o && my_spaces[8] == my_o)
			{
				row = 'C';
				col = '1';
			}

			// Vertical Column 1
			else if(my_spaces[0] == my_o && my_spaces[3] == my_o && my_spaces[6] == ' ')
			{
				row = 'C';
				col = '1';
			}
			else if(my_spaces[0] == my_o && my_spaces[3] == ' ' && my_spaces[6] == my_o)
			{
				row = 'B';
				col = '1';
			}
			else if(my_spaces[0] == ' ' && my_spaces[3] == my_o && my_spaces[6] == my_o)
			{
				row = 'A';
				col = '1';
			}

			// Vertical Column 2
			else if(my_spaces[1] == my_o && my_spaces[4] == my_o && my_spaces[7] == ' ')
			{
				row = 'C';
				col = '2';
			}
			else if(my_spaces[1] == my_o && my_spaces[4] == ' ' && my_spaces[7] == my_o)
			{
				row = 'B';
				col = '2';
			}
			else if(my_spaces[1] == ' ' && my_spaces[4] == my_o && my_spaces[7] == my_o)
			{
				row = 'A';
				col = '2';
			}

			// Vertical Column 3
			else if(my_spaces[2] == my_o && my_spaces[5] == my_o && my_spaces[8] == ' ')
			{
				row = 'C';
				col = '3';
			}
			else if(my_spaces[2] == my_o && my_spaces[5] == ' ' && my_spaces[8] == my_o)
			{
				row = 'B';
				col = '3';
			}
			else if(my_spaces[2] == ' ' && my_spaces[5] == my_o && my_spaces[8] == my_o)
			{
				row = 'A';
				col = '3';
			}

			// Diagnol Left to Right
			else if(my_spaces[0] == my_o && my_spaces[4] == my_o && my_spaces[8] == ' ')
			{
				row = 'C';
				col = '3';
			}
			else if(my_spaces[0] == my_o && my_spaces[4] == ' ' && my_spaces[8] == my_o)
			{
				row = 'B';
				col = '2';
			}
			else if(my_spaces[0] == ' ' && my_spaces[4] == my_o && my_spaces[8] == my_o)
			{
				row = 'A';
				col = '1';
			}

			// Diagnol Left to Right
			else if(my_spaces[2] == my_o && my_spaces[4] == my_o && my_spaces[6] == ' ')
			{
				row = 'C';
				col = '1';
			}
			else if(my_spaces[2] == my_o && my_spaces[4] == ' ' && my_spaces[6] == my_o)
			{
				row = 'B';
				col = '2';
			}
			else if(my_spaces[2] == ' ' && my_spaces[4] == my_o && my_spaces[6] == my_o)
			{
				row = 'A';
				col = '3';
			}

			// Defensive

			// Horizontal Row A
			else if(my_spaces[0] == my_x && my_spaces[1] == my_x && my_spaces[2] == ' ')
			{
				row = 'A';
				col = '3';
			}
			else if(my_spaces[0] == my_x && my_spaces[1] == ' ' && my_spaces[2] == my_x)
			{
				row = 'A';
				col = '2';
			}
			else if(my_spaces[0] == ' ' && my_spaces[1] == my_x && my_spaces[2] == my_x)
			{
				row = 'A';
				col = '1';
			}

			// Horizontal Row B
			else if(my_spaces[3] == my_x && my_spaces[4] == my_x && my_spaces[5] == ' ')
			{
				row = 'B';
				col = '3';
			}
			else if(my_spaces[3] == my_x && my_spaces[4] == ' ' && my_spaces[5] == my_x)
			{
				row = 'B';
				col = '2';
			}
			else if(my_spaces[3] == ' ' && my_spaces[4] == my_x && my_spaces[5] == my_x)
			{
				row = 'B';
				col = '1';
			}

			// Horizontal Row C
			else if(my_spaces[6] == my_x && my_spaces[7] == my_x && my_spaces[8] == ' ')
			{
				row = 'C';
				col = '3';
			}
			else if(my_spaces[6] == my_x && my_spaces[7] == ' ' && my_spaces[8] == my_x)
			{
				row = 'C';
				col = '2';
			}
			else if(my_spaces[6] == ' ' && my_spaces[7] == my_x && my_spaces[8] == my_x)
			{
				row = 'C';
				col = '1';
			}

			// Vertical Column 1
			else if(my_spaces[0] == my_x && my_spaces[3] == my_x && my_spaces[6] == ' ')
			{
				row = 'C';
				col = '1';
			}
			else if(my_spaces[0] == my_x && my_spaces[3] == ' ' && my_spaces[6] == my_x)
			{
				row = 'B';
				col = '1';
			}
			else if(my_spaces[0] == ' ' && my_spaces[3] == my_x && my_spaces[6] == my_x)
			{
				row = 'A';
				col = '1';
			}

			// Vertical Column 2
			else if(my_spaces[1] == my_x && my_spaces[4] == my_x && my_spaces[7] == ' ')
			{
				row = 'C';
				col = '2';
			}
			else if(my_spaces[1] == my_x && my_spaces[4] == ' ' && my_spaces[7] == my_x)
			{
				row = 'B';
				col = '2';
			}
			else if(my_spaces[1] == ' ' && my_spaces[4] == my_x && my_spaces[7] == my_x)
			{
				row = 'A';
				col = '2';
			}

			// Vertical Column 3
			else if(my_spaces[2] == my_x && my_spaces[5] == my_x && my_spaces[8] == ' ')
			{
				row = 'C';
				col = '3';
			}
			else if(my_spaces[2] == my_x && my_spaces[5] == ' ' && my_spaces[8] == my_x)
			{
				row = 'B';
				col = '3';
			}
			else if(my_spaces[2] == ' ' && my_spaces[5] == my_x && my_spaces[8] == my_x)
			{
				row = 'A';
				col = '3';
			}

			// Diagnol Left to Right
			else if(my_spaces[0] == my_x && my_spaces[4] == my_x && my_spaces[8] == ' ')
			{
				row = 'C';
				col = '3';
			}
			else if(my_spaces[0] == my_x && my_spaces[4] == ' ' && my_spaces[8] == my_x)
			{
				row = 'B';
				col = '2';
			}
			else if(my_spaces[0] == ' ' && my_spaces[4] == my_x && my_spaces[8] == my_x)
			{
				row = 'A';
				col = '1';
			}

			// Diagnol Left to Right
			else if(my_spaces[2] == my_x && my_spaces[4] == my_x && my_spaces[6] == ' ')
			{
				row = 'C';
				col = '1';
			}
			else if(my_spaces[2] == my_x && my_spaces[4] == ' ' && my_spaces[6] == my_x)
			{
				row = 'B';
				col = '2';
			}
			else if(my_spaces[2] == ' ' && my_spaces[4] == my_x && my_spaces[6] == my_x)
			{
				row = 'A';
				col = '3';
			}
			else
			{
				if((my_spaces[0] != ' ' && my_spaces[8] != ' ') || (my_spaces[2] != ' ' && my_spaces[6] != ' '))
				{
					if(my_spaces[1] == ' ')
					{
						row = 'A';
						col = '2';
					}
					else if(my_spaces[3] == ' ')
					{
						row = 'B';
						col = '1';
					}
					else if(my_spaces[4] == ' ')
					{
						row = 'B';
						col = '2';
					}
					else if(my_spaces[7] == ' ')
					{
						row = 'C';
						col = '2';
					}
					else if(my_spaces[4] == ' ')
					{
						row = 'B';
						col = '2';
					}
					else if(my_spaces[0] == ' ')
					{
						row = 'A';
						col = '1';
					}
					else if(my_spaces[2] == ' ')
					{
						row = 'A';
						col = '3';
					}
					else if(my_spaces[5] == ' ')
					{
						row = 'B';
						col = '3';
					}
					else if(my_spaces[6] == ' ')
					{
						row = 'C';
						col = '1';
					}
					else if(my_spaces[8] == ' ')
					{
						row = 'C';
						col = '3';
					}
				}
				else if(my_spaces[4] == ' ')
				{
					row = 'B';
					col = '2';
				}
				else if(my_spaces[0] == ' ')
				{
					row = 'A';
					col = '1';
				}
				else if(my_spaces[2] == ' ')
				{
					row = 'A';
					col = '3';
				}
				else if(my_spaces[5] == ' ')
				{
					row = 'B';
					col = '3';
				}
				else if(my_spaces[6] == ' ')
				{
					row = 'C';
					col = '1';
				}
				else if(my_spaces[8] == ' ')
				{
					row = 'C';
					col = '3';
				}
			}// end of else
		}
		else
		{
			cout << "\n\nPlayer Two: Enter row and column: ";
			cin >> row >> col;
		}

		row = toupper(row);
		col = toupper(col);

	}while(placeSymbol(row, col) == false);
}

bool TicTacToe::placeSymbol(symbol_t r, symbol_t c)
{
	bool result(false);

	if(my_spaces[0] == ' ' && result == false)
	{
		if(r == 'A' && c == '1')
		{
			my_spaces[0] = my_playerSymbol;
			result = (true);
		}
	}
	if(my_spaces[1] == ' ' && result == false)
	{
		if(r == 'A' && c == '2')
		{
			my_spaces[1] = my_playerSymbol;
			result = (true);
		}
	}
	if(my_spaces[2] == ' ' && result == false)
	{
		if(r == 'A' && c == '3')
		{
			my_spaces[2] = my_playerSymbol;
			result = (true);
		}
	}
	if(my_spaces[3] == ' ' && result == false)
	{
		if(r == 'B' && c == '1')
		{
			my_spaces[3] = my_playerSymbol;
			result = (true);
		}
	}
	if(my_spaces[4] == ' ' && result == false)
	{
		if(r == 'B' && c == '2')
		{
			my_spaces[4] = my_playerSymbol;
			result = (true);
		}
	}
	if(my_spaces[5] == ' ' && result == false)
	{
		if(r == 'B' && c == '3')
		{
			my_spaces[5] = my_playerSymbol;
			result = (true);
		}
	}
	if(my_spaces[6] == ' ' && result == false)
	{
		if(r == 'C' && c == '1')
		{
			my_spaces[6] = my_playerSymbol;
			result = (true);
		}
	}
	if(my_spaces[7] == ' ' && result == false)
	{
		if(r == 'C' && c == '2')
		{
			my_spaces[7] = my_playerSymbol;
			result = (true);
		}
	}
	if(my_spaces[8] == ' ' && result == false)
	{
		if(r == 'C' && c == '3')
		{
			my_spaces[8] = my_playerSymbol;
			result = (true);
		}
	}
	return(result);
}

void TicTacToe::playAgain()
{
	char choice(' ');

	cout << "Would you like to play again: ";
	cin >> choice;
	choice = toupper(choice);

	if(choice == 'N')
	{
		quitGame();
	}
}

void TicTacToe::quitGame()
{
	my_isQuit = (true);
}

void TicTacToe::selectionMenu()
{
	char choice(' ');
	do
	{
		clearScreen();

		cout << "\n\n       TicTacToe by Armond\n\n"
			<< "A) Player VS. Computer\n"
			<< "B) Player VS. Player\n\n" << flush;
		
		cout << "Choice: ";
		cin >> choice;
		choice = toupper(choice);

		switch(choice)
		{
		case 'A':
			{
				my_isOnePlayer = (true);
				break;
			}
		case 'B':
			{
				my_isOnePlayer = (false);
				break;
			}
		}
	}while(choice != 'A' && choice != 'B');
}

void TicTacToe::setWhoWon(bool choice, int playerNumber)
{
	if(playerNumber == 1)
	{
		my_isPlayerOneWin = (choice);
	}
	else
	{
		my_isPlayerTwoWin = (choice);
	}
}

//------------------------------------------
// Accessors
void TicTacToe::displayGrid() const
{
	clearScreen();
    
	cout << "\n\n       TicTacToe by Armond\n";
	cout << "\n\n\n      " << "  1      2      3\n\n"
	     << "      " << "     |       |\n"
		 << "  A   " << "  " << my_spaces[0] << "  |   " << my_spaces[1] << "   |  " << my_spaces[2] << '\n'
		 << "      " << "     |       |\n"
		 << "      " << "-------------------\n"
		 << "      " << "     |       |\n"
		 << "  B   " << "  " << my_spaces[3] << "  |   " << my_spaces[4] << "   |  " << my_spaces[5] << '\n'
		 << "      " << "     |       |\n"
		 << "      " << "-------------------\n"
		 << "      " << "     |       |\n"
		 << "  C   " << "  " << my_spaces[6] << "  |   " << my_spaces[7] << "   |  " << my_spaces[8] << '\n'
		 << "      " << "     |       |\n" << flush;
}

void TicTacToe::displayWinner() const
{
	cout << "Player ";

	if(my_isPlayerOneWin == true)
	{
		cout << "One is the winner!!!" << endl;
	}
	else if(my_isPlayerTwoWin == true)
	{
		cout << "Two is the winner!!!" << endl;
	}
	else
	{
		cout << "has a tie game!!!" << endl;
	}
}

bool TicTacToe::checkPattern() const
{
	bool result(false);
	if(my_spaces[0] == my_x && my_spaces[1] == my_x && my_spaces[2] == my_x)
	{
		result = (true);
	}
	else if(my_spaces[3] == my_x && my_spaces[4] == my_x && my_spaces[5] == my_x)
	{
		result = (true);
	}
	else if(my_spaces[6] == my_x && my_spaces[7] == my_x && my_spaces[8] == my_x)
	{
		result = (true);
	}
	else if(my_spaces[0] == my_x && my_spaces[3] == my_x && my_spaces[6] == my_x)
	{
		result = (true);
	}
	else if(my_spaces[1] == my_x && my_spaces[4] == my_x && my_spaces[7] == my_x)
	{
		result = (true);
	}
	else if(my_spaces[2] == my_x && my_spaces[5] == my_x && my_spaces[8] == my_x)
	{
		result = (true);
	}
	else if(my_spaces[0] == my_x && my_spaces[4] == my_x && my_spaces[8] == my_x)
	{
		result = (true);
	}
	else if(my_spaces[2] == my_x && my_spaces[4] == my_x && my_spaces[6] == my_x)
	{
		result = (true);
	}

	if(result == true)
	{
		return(result);
	}

	if(my_spaces[0] == my_o && my_spaces[1] == my_o && my_spaces[2] == my_o)
	{
		result = (true);
	}
	else if(my_spaces[3] == my_o && my_spaces[4] == my_o && my_spaces[5] == my_o)
	{
		result = (true);
	}
	else if(my_spaces[6] == my_o && my_spaces[7] == my_o && my_spaces[8] == my_o)
	{
		result = (true);
	}
	else if(my_spaces[0] == my_o && my_spaces[3] == my_o && my_spaces[6] == my_o)
	{
		result = (true);
	}
	else if(my_spaces[1] == my_o && my_spaces[4] == my_o && my_spaces[7] == my_o)
	{
		result = (true);
	}
	else if(my_spaces[2] == my_o && my_spaces[5] == my_o && my_spaces[8] == my_o)
	{
		result = (true);
	}
	else if(my_spaces[0] == my_o && my_spaces[4] == my_o && my_spaces[8] == my_o)
	{
		result = (true);
	}
	else if(my_spaces[2] == my_o && my_spaces[4] == my_o && my_spaces[6] == my_o)
	{
		result = (true);
	}
	return(result);
}

bool TicTacToe::isQuit() const
{
	return(my_isQuit);
}

bool TicTacToe::arePlayersWon() const
{
	return(my_isPlayerOneWin == true || my_isPlayerTwoWin == true);
}

bool TicTacToe::isTie() const
{
	bool result(true);
	for(counter_t i(0); i < my_spaces.size(); ++i)
	{
		if(my_spaces[i] == ' ')
		{
			result = (false);
		}
	}
	return(result);
}
//----------------------------------------------------