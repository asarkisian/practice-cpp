//--------------------------------------------
// doMain.cpp

#pragma warning(disable : 4244)
#pragma warning(disable : 4800)

#include "Blackjack.h"
#include "Deck.h"
#include "Globals.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::ifstream;
using std::istream;
using std::ofstream;
using std::ostream;
using std::string;

void doMain()
{
	string inputMode(""), outputMode("");
	ifstream inputFile("DataFile.txt");
	ofstream outputFile("Output.txt");

	inputFile >> inputMode >> outputMode;
	
	istream& my_input(inputMode == "demo"   ? static_cast<istream&>(inputFile) : cin);
	ostream& my_output(outputMode == "file" ? static_cast<ostream&>(outputFile) : cout);

	Blackjack bj(my_input, my_output);

	if(inputMode == "demo")
	{
		bj.setDemoMode(true);
		bj.getPlayerName("Demo-mode");
	}
	else
	{
		bj.getPlayerName();
	}

	do
	{
		bj.resetValues();
		theDeck.resetValues();

		bj.displayScreen();

		if(bj.isDemoMode() == false)
		{	
			if(bj.isOutOfMoney() == true)
			{
				bj.outOfMoney();
				break;
			}
			bj.placeBet();
		}
		theDeck.dealCards("Both");

		bj.increase_gameNumber();
		bj.displayScreen();

		bj.countDealerCards();
		bj.countPlayerCards();
		bj.checkBlackjack();

		while(bj.isDealerBlackjack() == false 
		   && bj.isPlayerBlackjack() == false
		   && bj.isDealerWon() == false 
		   && bj.isPlayerWon() == false)
		{
			bj.displayScreen();
			
			do
			{
				bj.playersTurn();
				bj.displayScreen();
			}while(bj.move() == bj.hit());
			
			do
			{
				bj.dealersTurn();
			}while(bj.move() == bj.hit());

			bj.displayScreen();
			bj.setWinner();
		}
		bj.playAgain();
	}while(bj.isQuit() == false);
}
//--------------------------------------------